/*
 * Copyright (C) 2020 BrianYi, All rights reserved
 */
#include "RtmpSessionTable.h"

std::mutex RtmpSessionTable::mx;
/*
 * static variable declaration
 */
//RtmpSessionTable::RtmpSessionArryType RtmpSessionTable::sRtmpSessionArry;	// store all session
RtmpSessionTable::RtmpSessionUnorderedMapType RtmpSessionTable::sRtmpSessionTable;		// store pusher app-session
RtmpSessionTable::RtmpSessionUnorderedMultimapType RtmpSessionTable::sRtmpPairSessionTable;	// store puller app-session

RtmpSessionTable::RtmpSessionTable( )
{

}

RtmpSessionTable::~RtmpSessionTable( )
{

}
