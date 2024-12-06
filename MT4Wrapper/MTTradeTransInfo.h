#pragma once
#include "stdafx.h"
#include "ManagedObject.h"
#include "../MT4/Core.h"

using namespace System;

namespace MT4Wrapper {
	public ref class MTTradeTransInfo : public ManagedObject<Core::MTTradeTransInfo>
	{
	public:
		MTTradeTransInfo();

		UCHAR             type;                       // Trading transaction type
		char              flags;                      // Flags
		short             cmd;                        // Trade command type
		int               order, orderby;             // Ticket of the order and ticket of the opposite order
		String^           symbol;                     // Financial instrument
		int               volume;                     // Volume
		double            price;                      // Price
		double            sl, tp;                     // Stop Loss and Take Profit
		int               ie_deviation;               // Deviation in the Instant Execution mode
		String^           comment;                    // Comment
		__time32_t        expiration;                 // Expiration
		int               crc;                        // Check sum
	};
}