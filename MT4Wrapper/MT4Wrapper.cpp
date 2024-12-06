#include "stdafx.h"
#include "MT4Wrapper.h"
#include <iostream>
#include <msclr/marshal_cppstd.h>
using namespace System;
using namespace msclr::interop;

namespace MT4Wrapper {


	MT4::MT4(String^ server, int loginId, String^ password) 
		: ManagedObject(new Core::MT4(stoca(server), loginId, stoca(password)))
	{
	}
	double MT4::getBalance(int userID) {
		return m_Instance->getBalance(userID);
	}

	double MT4::getEquity(int userID) {
		return m_Instance->getEquity(userID);
	}

	double MT4::getCredit(int userID) {
		return m_Instance->getCredit(userID);
	}

	int MT4::deposit(int loginID, double amount, String^ message) {
		return m_Instance->depositOrWithdraw(loginID,amount,false, stoca(message));
	}

	int MT4::withdraw(int loginID, double amount, String^ message) {
		return m_Instance->depositOrWithdraw(loginID, amount, true, stoca(message));
	}

	int MT4::creditIn(int loginID, double amount, String^ message) {
		return m_Instance->creditInOrOut(loginID, amount, false, stoca(message));
	}

	int MT4::creditOut(int loginID, double amount, String^ message) {
		return m_Instance->creditInOrOut(loginID, amount, true, stoca(message));
	}

	int MT4::internalTransfer(int fromID, int toID, double amount, String^ messageFrom, String^ messageTo) {
		return m_Instance->internalTransfer(fromID, toID, amount, stoca(messageFrom), stoca(messageTo));
	}

	int MT4::internalTransferAll(int fromID, int toID) {
		return m_Instance->internalTransferAll(fromID, toID);

	}
	int MT4::changePassword(int userID, String^ new_password, int changeInvestr) {
		return m_Instance->changePassword(userID, stoca(new_password), changeInvestr);
	}

	MT4User ^ MT4::addUser(MT4User^ user) {

		UserRecord user_record = user->getUserRecord();
		UserRecord user_record2 = m_Instance->addUser(user_record);
		//return user_record.login;
		MT4User^ mt4user = gcnew MT4User(user_record2);
		return mt4user;
	}
	int MT4::createUser(MT4User^ user) {

		UserRecord user_record = user->getUserRecord();
		return  m_Instance->createUser(user_record);
	}

	MT4User ^ MT4::getUser(int userID) {
		UserRecord* x = m_Instance->getUser(userID);
		if (x != NULL) {
			MT4User^ mt4user = gcnew MT4User(x[0]);
			return mt4user;
		}
		else {
			MT4User^ mt4user = gcnew MT4User();
			return mt4user;
		}
	}
	MTTradeRecord^ MT4::getTrade(int orderID) {
		TradeRecord* x = m_Instance->getTrade(orderID);
		if (x != NULL) {
			MTTradeRecord^ mt4trade = gcnew MTTradeRecord(x[0]);
			return mt4trade;
		}
		else {
			MTTradeRecord^ mt4trade = gcnew MTTradeRecord();
			return mt4trade;
		}


	}

	TradeRecord  MT4::tradeRecordGet(int order,TradeRecord% trade) {
		int total = 0;
		TradeRecord trs = { 0 };
		int res = m_Instance->tradeRecordGet(order, &trs);
		if (res != RET_OK) {

			return trade;
		}
		trade = TradeRecord(trs);
		return trade;
	}
	int  MT4::updateUser(MT4User^ user) {
		UserRecord user_record = user->getUserRecordForPassword();
		return m_Instance->updateUser(user_record);
	}
	int  MT4::updateTrade(MTTradeRecord^ trade) {
		int res = 0;
		TradeRecord trade_record = trade->getTradeRecord();
		res = m_Instance->updateTrade(trade_record);
		return res;
	}
	int  MT4::getMarginLevel(int login, MTMarginLevel^ marginLevel) {
		MarginLevel mLevel = { 0 };
		int res = m_Instance->getMarginLevel(login, &mLevel);
		if (res == RET_OK) {
			marginLevel->balance = mLevel.balance;
			marginLevel->equity = mLevel.equity;
			marginLevel->group = catos(mLevel.group);
			marginLevel->level_type = mLevel.level_type;
			marginLevel->leverage = mLevel.leverage;
			marginLevel->login = mLevel.login;
			marginLevel->margin = mLevel.margin;
			marginLevel->margin_free = mLevel.margin_free;
			marginLevel->margin_level = mLevel.margin_level;
			marginLevel->margin_type = mLevel.margin_type;
			marginLevel->updated = mLevel.updated;
			marginLevel->volume = mLevel.volume;
		}
		return res;
	}

	MTTradeRecord^ MT4::GetTradesUserHistory(const int login, const time_t from, const time_t to) {
		int total;
		TradeRecord* tRecord = m_Instance->GetTradesUserHistory(login, from, to, &total);
		MTTradeRecord^ mt4tradeRecord = gcnew MTTradeRecord(tRecord, total);
		return mt4tradeRecord;
	}
	MTTradeRecord^ MT4::getTrades(const int login) {
		int total;
		TradeRecord* tRecord = m_Instance->getTrades(login,&total);

		MTTradeRecord^ mt4tradeRecord = gcnew MTTradeRecord(tRecord, total);
		return mt4tradeRecord;
	}
	MTTradeRecord^ MT4::getOpenTradesByGroup(String ^ _group,int total) {
		marshal_context context;
		const char* group = context.marshal_as<const char*>(_group);
		TradeRecord* tRecord = m_Instance->getOpenTradesByGroup(group, &total);

		MTTradeRecord^ mt4tradeRecord = gcnew MTTradeRecord(tRecord, total);
		return mt4tradeRecord;
	}
	MTTradeRecord^ MT4::getAllTradesByGroup(String^ _group, int total) {
		marshal_context context;
		const char* group = context.marshal_as<const char*>(_group);
		TradeRecord* tRecord = m_Instance->getAllTradesByGroup(group, &total);

		MTTradeRecord^ mt4tradeRecord = gcnew MTTradeRecord(tRecord, total);
		return mt4tradeRecord;
	}
	MTConSymbol^ MT4::getSymbols() {
		int total;
		ConSymbol* conSymbol = m_Instance->getAllSymbols(&total);
		MTConSymbol^ mtConSymbol = gcnew MTConSymbol(conSymbol, total);
		return mtConSymbol;
	}
	int MT4::refreshSymbols() {
		return m_Instance->refreshSymbols();
	}
	MTGroup^ MT4::getAllGroups() {
		int total;
		ConGroup* conGroup = m_Instance->getAllGroups(&total);
		if (conGroup == NULL) return gcnew MTGroup();
		MTGroup^ mtGroup = gcnew MTGroup(conGroup, total);
		return mtGroup;
	}
	MTTradeRecord^ MT4::getLiveTrades() {
		int total;
		TradeRecord* tRecord = m_Instance->getLiveTrades(&total);
		MTTradeRecord^ mt4tradeRecord = gcnew MTTradeRecord(tRecord, total);
		return mt4tradeRecord;
	}
	int MT4::balanceFix(int logins) {
		int total = 1;
		return  m_Instance->balanceFix(&logins, total);
	};
	MTTradeRecord^ MT4::tradesGet() {
		int total = 1;
		TradeRecord* tRecord = m_Instance->tradesGet(&total);
		MTTradeRecord^ mt4tradeRecord = gcnew MTTradeRecord(tRecord, total);
		return mt4tradeRecord;
	}
	int MT4::getUserLiveTradesCount(const int login) {
		int total = 0;
		int userLiveCount = 0;
		TradeRecord* tRecord = m_Instance->getLiveTrades(&total);
		for (int i = 0; i < total; i++) {
			if (tRecord[i].login == login) {
				userLiveCount++;
			}
		}
		return userLiveCount;
	}
	MT4User^ MT4::getUsers(array<int>^ logins) {
		int total = logins->Length;
		if (total > 0) {
			pin_ptr<int> pin = &logins[0];
			UserRecord* records = m_Instance->getUsers(pin, &total);
			MT4User^ users = gcnew MT4User(records, total);
			return users;
			m_Instance->MemFree(records);
		}
		else {
			MT4User^ usrs = gcnew MT4User();
			return usrs;
		}
	}
	MT4User^ MT4::getUsersByGroup(String^ _group, int total) {
		UserRecord* records = m_Instance->getUsers(stoca(_group), &total);
		MT4User^ users = gcnew MT4User(records, total);
		return users;		
	}
	MT4User^ MT4::getUsersByGroup(const char* _group) {
		int total = 10;
		UserRecord* records = m_Instance->getUsers(_group, &total);
		MT4User^ users = gcnew MT4User(records, total);
		return users;		
	}


	int MT4::IsConnected() {
		return m_Instance->IsConnected();
	}

	int MT4::Disconnect() {
		return m_Instance->Disconnect();
	}

	int MT4::Connect(String^ server) {
		return m_Instance->Connect(stoca(server));
	}
	int MT4::Login(int loginId, String^ password) {
		return m_Instance->Login(loginId, stoca(password));
	}
	int MT4::Ping() {
		return m_Instance->Ping();
	}
}

