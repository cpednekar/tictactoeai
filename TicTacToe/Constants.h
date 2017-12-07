#pragma once

#ifndef CONSTANTS_H
#define CONSTANTS_H


enum FlipTypes
{
	FlipType_Vertical,
	FlipType_Horizontal,
	FlipType_None
};



enum EventTypes
{
	EventType_Key_UpArrow,
	EventType_Key_DownArrow,
	EventType_Key_Return,
	EventType_KeyPad_1,
	EventType_KeyPad_2,
	EventType_KeyPad_3,
	EventType_KeyPad_4,
	EventType_KeyPad_5,
	EventType_KeyPad_6,
	EventType_KeyPad_7,
	EventType_KeyPad_8,
	EventType_KeyPad_9,
	EventType_MouseButton_Left,
	EventType_None
};


enum Symbols
{
	Symbol_EmptySpace,
	Symbol_X,
	Symbol_O
};


enum GameTypes
{
	GameType_PlayerVsPlayer,
	GameType_PlayerVsComputer
};



#endif