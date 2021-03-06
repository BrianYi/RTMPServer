/*
 * Copyright (C) 2020 BrianYi, All rights reserved
 */
#pragma once
#include "TcpSocket.h"

class RtmpSession;

class RtmpListenerSocket :
	public TcpSocket
{ 
public:
	RtmpListenerSocket( );
	virtual ~RtmpListenerSocket( );
	virtual int32_t handle_event( uint32_t flags );
	RtmpSession* accept( IOType inIOType = Blocking );
};

