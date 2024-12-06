#pragma once
#pragma once
#include "stdafx.h"
#include "ManagedObject.h"
#include "../MT4/Core.h"
using namespace System;
namespace MT4Wrapper {
	public ref class MTMarginLevel : public ManagedObject<Core::MTMarginLevel>
	{
	public:
		MTMarginLevel();

		int               login;            // user login
		String^           group = "";        // user group
		int               leverage;         // user leverage
		int               updated;          // (internal)
		double            balance;          // balance+credit
		double            equity;           // equity
		int               volume;           // lots
		double            margin;           // margin requirements
		double            margin_free;      // free margin
		double            margin_level;     // margin level
		int               margin_type;      // margin controlling type (percent/currency)
		int               level_type;       // level type(ok/margincall/stopout)
	};


}
