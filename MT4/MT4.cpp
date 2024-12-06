#include "MT4.h"
#include <iostream>
namespace Core {
	MT4::MT4(const char* server, int loginId, const char* password) {
		if (manager.IsValid()) {
			if (manager->Connect(server) != 0 || manager->Login(loginId, password) != 0)
			{
				return;
			}
		}
	}
	double MT4::getBalance(int userID) {
		const int loginUser = userID;
		int               m_users_total;
		UserRecord* m_user = NULL;
		m_users_total = 1;
		m_user = manager->UserRecordsRequest(&loginUser, &m_users_total);
		//printf("%f", m_user[0].balance);
		double balance = 0;
		if (m_user != NULL) {
			balance = m_user[0].balance;
		}
		return balance;
	}

	double MT4::getCredit(int userID) {
		const int loginUser = userID;
		int               m_users_total;
		UserRecord* m_user = NULL;
		m_users_total = 1;
		m_user = manager->UserRecordsRequest(&loginUser, &m_users_total);
		//printf("%f", m_user[0].balance);
		return m_user[0].credit;
	}

	double MT4::getEquity(int userID) {
		const int loginUser = userID;
		int               m_users_total;
		UserRecord* m_user = NULL;
		m_users_total = 1;
		m_user = manager->UserRecordsRequest(&loginUser, &m_users_total);
		//printf("%f", m_user[0].balance);
		return m_user[0].prevequity;
	}


	int MT4::depositOrWithdraw(int loginID, double amount, bool withdraw, const char* message) {
		TradeTransInfo info = { 0 };
		//char           tmp[32];
		//--- данные
		info.type = TT_BR_BALANCE;
		info.cmd = OP_BALANCE; // OP_CREDIT
		info.orderby = loginID;
		info.price = amount;

		//strcpy_s(info.comment, "Deposit");
		strcpy_s(info.comment, message);

		if (withdraw)
		{
			info.price = -amount;
			//strcpy_s(info.comment, "Withdraw");
		}

		//---
		if (info.orderby <= 0) { exit(0); }
		//---
		int ok = RET_INVALID_DATA;
		if (manager->TradeTransaction(&info) == 0) {
			return 1;
		}
	}

	int MT4::creditInOrOut(int loginID, double amount, bool creditOut, const char* message) {
		TradeTransInfo info = { 0 };
		//char           tmp[32];
		//--- данные
		info.type = TT_BR_BALANCE;

		info.cmd = OP_CREDIT;
		info.orderby = loginID;
		info.price = amount;

		time_t exp;
		time(&exp);
		//info.expiration = exp + 7776000; // adding 90 days for expiry
		info.expiration = exp + 86400;

		//strcpy_s(info.comment, "Deposit");
		strcpy_s(info.comment, message);

		if (creditOut)
		{
			info.price = -amount;
			//strcpy_s(info.comment, "Withdraw");
		}

		//---
		if (info.orderby <= 0) { exit(0); }
		//---
		int ok = RET_INVALID_DATA;
		if (manager->TradeTransaction(&info) == 0) {
			return 1;
		}
		//return manager->ErrorDescription(manager->TradeTransaction(&info));
	}


	int MT4::internalTransfer(int fromID, int toID, double amount, const char* messageFrom, const char* messageTo) {
		double current_bal = getBalance(fromID);
		if (amount <= current_bal) {
			if (depositOrWithdraw(fromID, amount, true, messageFrom) == 1 && depositOrWithdraw(toID, amount, false, messageTo) == 1) {
				return 1;
			}

		}
		else {
			return 2;
		}
	}

	int MT4::internalTransferAll(int fromID, int toID) {
		double current_bal = getBalance(fromID);

		if (depositOrWithdraw(fromID, current_bal, true, "Internal Transfer All") == 1 && depositOrWithdraw(toID, current_bal, false, "Internal Transfer All") == 1) {
			return 1;
		}

	}

	int MT4::changePassword(int userID, const char* new_password, int changeInvestr) {
		return manager->UserPasswordSet(userID, new_password, changeInvestr, 0);
	}

	UserRecord* MT4::getUser(int userID) {
		const int loginUser = userID;
		int               m_users_total;
		UserRecord* m_user = NULL;
		m_users_total = 1;
		m_user = manager->UserRecordsRequest(&loginUser, &m_users_total);
		//printf("%f", m_user[0].balance);
		return m_user;
	}
	TradeRecord* MT4::getTrade(int orderID) {
		const int order = orderID;
		int               m_users_total;
		TradeRecord* trade = NULL;
		m_users_total = 1;
		trade = manager->TradeRecordsRequest(&order, &m_users_total);
		//printf("%f", m_user[0].balance);
		return trade;
	}
	UserRecord MT4::addUser(UserRecord user) {
		manager->UserRecordNew(&user);
		return user;
	}
	int MT4::createUser(UserRecord user) {
		return manager->UserRecordNew(&user);
	}

	int MT4::updateUser(UserRecord user) {
		return manager->UserRecordUpdate(&user);
	}
	int MT4::IsConnected() {
		return manager->IsConnected();
	}
	int MT4::Disconnect() {
		return manager->Disconnect();
	}
	int MT4::Connect(const char* server) {
		return manager->Connect(server);
	}
	int MT4::Login(int loginId, const char* password) {
		return manager->Login(loginId, password);
	}
	int MT4::Ping() {
		return manager->Ping();
	}
	int MT4::updateTrade(TradeRecord trade) {
		return manager->AdmTradeRecordModify(&trade);
	}
	int MT4::balanceFix(int* logins, const int total) {
		return manager->AdmBalanceFix(logins, total);
	}
	int MT4::tradeRecordGet(const int order , TradeRecord* trade) {
		return manager->TradeRecordGet(order, trade);
	}
	
	int  MT4::getMarginLevel(const int login, MarginLevel* marginLevel) {
		return manager->MarginLevelRequest(login, marginLevel);
	}
	TradeRecord* MT4::getTrades(const int login, int* total) {
		time_t ltime;
		time(&ltime);
		return manager->TradesUserHistory(login,1, ltime, total);

	}
	TradeRecord* MT4::getOpenTradesByGroup(LPCSTR group, int* total) {
		return manager->AdmTradesRequest(group, 1, total);
	}
	TradeRecord* MT4::getAllTradesByGroup(LPCSTR group, int* total) {
		return manager->AdmTradesRequest(group, 0, total);
	}
	TradeRecord* MT4::GetTradesUserHistory(const int login, const time_t from, const time_t to, int* total) {
		return manager->TradesUserHistory(login, from, to, total);
	}
	int MT4::refreshSymbols() {
		return manager->SymbolsRefresh();
	}
	ConSymbol* MT4::getAllSymbols(int* total) {
		return manager->SymbolsGetAll(total);
	}
	ConGroup* MT4::getAllGroups(int* total) {
		return manager->CfgRequestGroup(total);
	}
	TradeRecord* MT4::getLiveTrades(int* total) {
		return manager->TradesRequest(total);
	}
	TradeRecord* MT4::tradesGet(int* total) {
		return manager->TradesGet(total);
	}
	int MT4::dealerSend(RequestInfo* info, const int requote, const int mode) {
		return manager->DealerSend(info, requote, mode);
	}

	UserRecord* MT4::getUsers(const int* logins, int* total) {
		return manager->UserRecordsRequest(logins, total);
	}
	UserRecord* MT4::getUsers(LPCSTR group, int* total) {
		//LPCSTR group = "ECN";
		return manager->AdmUsersRequest(group, total);
	}

	void MT4::MemFree(void* ptr) {
		return manager->MemFree(ptr);
	}
}