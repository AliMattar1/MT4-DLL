#pragma once
#include "ManagedObject.h"
#include "MT4User.h"
#include "MTMarginLevel.h"
#include "MTTradeRecord.h"
#include "MTConSymbol.h"
#include "MTGroup.h"
#include "../MT4/Core.h"
using namespace System;

namespace MT4Wrapper {
	public ref class MT4 : public ManagedObject<Core::MT4>
	{
		public:
			MT4(String^ server, int loginId, String^ password);
			double getBalance(int userID);
			double getEquity(int userID);
			double getCredit(int userID);
			int deposit(int loginID, double amount, String^ message);
			int withdraw(int loginID, double amount, String^ message);
			int creditIn(int loginID, double amount, String^ message);
			int creditOut(int loginID, double amount, String^ message);
			int internalTransfer(int fromID, int toID, double amount, String^ messageFrom, String^ messageTo);
			int internalTransferAll(int fromID, int toID);
			int changePassword(int userID, String^ new_password, int changeInvestr);
			MT4User ^ addUser(MT4User^ user);
			int createUser(MT4User^ user);
			int updateUser(MT4User^ user);
			int updateTrade(MTTradeRecord^ trade);
			MT4User^ getUser(int userID);
			MT4User^ getUsers(array<int>^ userIDs);
			MT4User^ getUsersByGroup(String ^ group, int total);
			MT4User^ getUsersByGroup(const char * group);
			MTTradeRecord^ getTrade(int orderID);
			int getMarginLevel(const int login, MTMarginLevel^ marginLevel);
			MTConSymbol^ getSymbols();
			int refreshSymbols();
			MTGroup^ getAllGroups();
			TradeRecord tradeRecordGet(int order,TradeRecord% trade);
			MTTradeRecord^ getTrades(const int login);
			MTTradeRecord^ getOpenTradesByGroup(String^ group, int total);
			MTTradeRecord^ getAllTradesByGroup(String^ group, int total);
			MTTradeRecord^ GetTradesUserHistory(const int login, const time_t from, const time_t to);
			MTTradeRecord^ getLiveTrades();
			int balanceFix(int logins);
			MTTradeRecord^ tradesGet();
			int getUserLiveTradesCount(const int login);
			int IsConnected();
			int Disconnect();
			int Connect(String^ server);
			int Login(int loginId, String^ password);
			int Ping();
	};


}
