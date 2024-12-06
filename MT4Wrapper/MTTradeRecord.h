#pragma once
#pragma once
#include "stdafx.h"
#include "ManagedObject.h"
#include "../MT4/Core.h"
using namespace System;
namespace MT4Wrapper {
	public ref class MTTradeRecord : public ManagedObject<Core::MTTradeRecord>
	{
	public:
		MTTradeRecord();
		MTTradeRecord(const TradeRecord traderecord);
		MTTradeRecord(TradeRecord *tRec, int total, char *tempSymb);
		MTTradeRecord(TradeRecord* tRec, int total);
		MTTradeRecord^ getTradeIndex(int index);
		TradeRecord getTradeRecord();

		TradeRecord		 *tradeRecord;
		int				  total;
		String^           tempSymb;

		int               order;            // order ticket
		int               login;            // owner's login
		String^           symbol;       // security
		int               digits;           // security precision
		int               cmd;              // trade command
		int               volume;           // volume
		//---
		__time32_t        open_time;        // open time
		int               state;            // reserved
		double            open_price;       // open price
		double            sl, tp;            // stop loss & take profit
		__time32_t        close_time;       // close time
		int               gw_volume;        // gateway order volume
		__time32_t        expiration;       // pending order's expiration time
		String^              reason;           // trade reason
		String^              conv_reserv;   // reserved fields
		double            conv_rates;    // convertation rates from profit currency to group deposit currency
											// (first element-for open time, second element-for close time)
		double            commission;       // commission
		double            commission_agent; // agent commission
		double            storage;          // order swaps
		double            close_price;      // close price
		double            profit;           // profit
		double            taxes;            // taxes
		int               magic;            // special value used by client experts
		String^               comment;      // comment
		int               gw_order;         // gateway order ticket
		int               activation;       // used by MT Manager
		short             gw_open_price;    // gateway order price deviation (pips) from order open price
		short             gw_close_price;   // gateway order price deviation (pips) from order close price
		double            margin_rate;      // margin convertation rate (rate of convertation from margin currency to deposit one)
		__time32_t        timestamp;        // timestamp
	};


}
