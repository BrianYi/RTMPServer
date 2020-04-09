#include "EventHandler.h"
#include "Dispatcher.h"

EventHandler::EventHandler( int32_t inSocketType, int32_t inProtocol, IOType inIOType ):
	Socket(inSocketType, inProtocol, inIOType )
{
	fEvents = 0;
}

EventHandler::EventHandler( int32_t fd, bool binded, int32_t inSocketType, int32_t inProtocol, IOType inIOType ):
	Socket(fd, binded, inSocketType, inProtocol, inIOType )
{
	fEvents = 0;
}

EventHandler::~EventHandler( )
{
}

void EventHandler::request_event( uint32_t events )
{
// 	if ( fEvents & events )
// 		return;
	fEvents = events | EPOLLET;
	//fEvents |= events;
	//fEvents |= EPOLLET;	// all task is one shot and edge-trigger
	Dispatcher::register_handler( fSocket, this );
}

void EventHandler::kill_event( )
{
	// mark dead
	this->set_dead( );

	// remove from dispatcher
	Dispatcher::remove_handler( this->fSocket );
}

std::string events_str( uint32_t events )
{
#ifdef _DEBUG
	std::string evstr = "";
	if ( events & EPOLLIN )
		evstr += "EPOLLIN ";
	if ( events & EPOLLOUT )
		evstr += "EPOLLOUT ";
	if ( events & EPOLLHUP )
		evstr += "EPOLLHUB ";
	if ( events & EPOLLRDHUP )
		evstr += "EPOLLRDHUB ";
	if ( events & EPOLLWAKEUP )
		evstr += "EPOLLWAKEUP ";
	if ( events & EPOLLONESHOT )
		evstr += "EPOLLONESHOT ";
	if ( events & EPOLLET )
		evstr += "EPOLLET ";
#endif // _DEBUG
	return evstr;
}


// 
// void EventHandler::set_event( struct epoll_event event )
// {
// 	fEvent = event;
// }

// Task * EventHandler::get_handler( )
// {
// 	return fTask;
// }
