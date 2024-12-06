#pragma once
#pragma once
#include "stdafx.h"
#include "ManagedObject.h"
#include "../MT4/Core.h"
using namespace System;
namespace MT4Wrapper {
	public ref class MTConSymbol : public ManagedObject<Core::MTConSymbol>
	{
	public:
		MTConSymbol();
		MTConSymbol(ConSymbol* sRec, int total);
		MTConSymbol^ getSymbolIndex(int index);

		ConSymbol *conSymbol;
		int total;

		//--- common settings
		String^ symbol;                  // name
		String^ description;             // description
		String^ source;                  // synonym
		String^ currency;                // currency
		int               type;                        // security group (see ConSymbolGroup)
		int               digits;                      // security precision
		int               trade;                       // trade mode
		//--- margin calculation
		int               margin_mode;                 // margin calculation mode
		double            margin_initial;              // initial margin
		double            margin_maintenance;          // margin maintenance
		double            margin_hedged;               // hedged margin
		double            margin_divider;              // margin divider
		double            contract_size;               // contract size
	};
}