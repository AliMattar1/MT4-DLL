#pragma once
#include "stdafx.h"
#include "ManagedObject.h"
#include "../MT4/Core.h"

using namespace System;

namespace MT4Wrapper {
	public ref class MTRequestInfo : public ManagedObject<Core::MTRequestInfo>
	{
	public:
		MTRequestInfo();

		RequestInfo* prev, * next;

		TradeTransInfo*  trade;				      // Trading transaction type

		//--- General information
		int               id;                         // Request ID
		int               status;                     // Request status
		time_t             time;                       // Request time
		int               manager;                    // The manager the request is sent to

		//--- Client data
		int               login;                      // Client's login
		String^	          group;                      // Client group
		double            balance;                    // Client's balance
		double            credit;                     // Client's credit

		//--- Data of an executed request
		double            prices;                     // Execution price
		int               gw_volume;                  // The volume processed through a gateway
		int               gw_order;                   // The ticket of the order processed through the gateway
		short             gw_price;                   // Difference between the price of the order processed through the gateway and the requested price
		short             reserved;                   // A reserved field
	};
}
