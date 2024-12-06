#pragma once
#include "ManagedObject.h"
#include "../MT4/Core.h"
using namespace System;
namespace MT4Wrapper {
	public ref class MTGroup : public ManagedObject<Core::MTGroup>
	{
	public:
		MTGroup();
		MTGroup(ConGroup* gRecord, int total);
		MTGroup^ getGroupIndex(int index);

		ConGroup* conGroup;
		int total;

		String^              groupName;                   // group name
	};
}

