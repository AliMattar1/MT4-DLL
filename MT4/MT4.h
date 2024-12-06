#pragma once
#include "CManager.h"

namespace Core {

	class MT4User
	{
	public:
		MT4User() {
			return;
		}
	};

	class MTMarginLevel
	{
	public:
		MTMarginLevel() {
			return;
		}
	};

	class MTTradeRecord
	{
	public:
		MTTradeRecord() {
			return;
		}
	};

	class MTTradeTransInfo
	{
	public:
		MTTradeTransInfo() {
			return;
		}
	};

	class MTRequestInfo
	{
	public:
		MTRequestInfo() {
			return;
		}
	};

	class MTConSymbol
	{
	public:
		MTConSymbol() {
			return;
		}
	};

	class MTGroup
	{
	public:
		MTGroup() {
			return;
		}
	};

	class MT4 {
		private:
			CManager manager;
		public:
			MT4(const char* server, int loginId, const char* password);
			void MemFree(void* ptr);
			double getBalance(int userID);
			double getCredit(int userID);
			double getEquity(int userID);
			double getMargin(int userID);
			double getMarginLevel(int userID);
			int depositOrWithdraw(int loginID, double amount, bool withdraw, const char* message);
			int creditInOrOut(int loginID, double amount, bool withdraw, const char* message);
			int internalTransfer(int fromID, int toID, double amount, const char* messageFrom, const char* messageTo);
			int internalTransferAll(int fromID, int toID);
			int changePassword(int userID, const char* new_password, int changeInvestr);
			UserRecord* getUser(int userID);
			UserRecord* getUsers(const int* userIDs, int* total);
			UserRecord* getUsers(LPCSTR group, int* total);
			TradeRecord* getTrade(int orderID);
			UserRecord addUser(UserRecord user);
			int createUser(UserRecord user);
			int updateUser(UserRecord user);
			int updateTrade(TradeRecord trade);
			int getMarginLevel(const int login, MarginLevel *marginLevel);
			int tradeRecordGet(const int order, TradeRecord *trade);
			int refreshSymbols();
			ConSymbol* getAllSymbols(int* total);
			ConGroup* getAllGroups(int* total);
			TradeRecord* getTrades(const int login, int *total);
			TradeRecord* getOpenTradesByGroup(LPCSTR group, int *total);
			TradeRecord* getAllTradesByGroup(LPCSTR group, int *total);
			TradeRecord* getLiveTrades(int *total);
			int balanceFix(int* logins, const int total);
			TradeRecord* tradesGet(int* total);
			TradeRecord* GetTradesUserHistory(const int login, const time_t from, const time_t to, int* total);
			int dealerSend(RequestInfo* info, const int requote, const int mode);
			int IsConnected();
			int Disconnect();
			int Connect(const char* server);
			int Login(int loginId, const char* password);
			int Ping();
	};

	
}