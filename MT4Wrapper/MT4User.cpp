#pragma once
#include "stdafx.h"
#include "MT4User.h"
namespace MT4Wrapper {
	MT4User::MT4User(UserRecord userrecord)
		: ManagedObject(new Core::MT4User() ){

		this->userID = userrecord.login;
		this->balance = userrecord.balance;
		//Strings
		this->group = catos(userrecord.group);
		this->country = catos(userrecord.country);
		this->name = catos(userrecord.name);
		this->city = catos(userrecord.city);
		this->state = catos(userrecord.state);
		this->zipcode = catos(userrecord.zipcode);
		this->address = catos(userrecord.address);
		this->lead_source = catos(userrecord.lead_source);
		this->phone = catos(userrecord.phone);
		this->email = catos(userrecord.email);
		this->comment = catos(userrecord.comment);
		this->id = catos(userrecord.id);
		this->status = catos(userrecord.status);
		this->password = catos(userrecord.password);


		// Ints
		this->leverage = userrecord.leverage;
		this->agent_account = userrecord.agent_account;
		this->send_reports = userrecord.send_reports;
		this->enable = userrecord.enable;
		this->enable_change_password = userrecord.enable_change_password;
		this->enable_read_only = userrecord.enable_read_only;
		this->enable_otp = userrecord.enable_otp;

		//Doubles
		this->prevmonthbalance = userrecord.prevmonthbalance;
		this->prevbalance = userrecord.prevbalance;
		this->balance = userrecord.balance;
		this->credit = userrecord.credit;
		this->interestrate = userrecord.interestrate;
		this->taxes = userrecord.taxes;
		this->prevmonthequity = userrecord.prevmonthequity;
		this->prevequity = userrecord.prevequity;
		this->mqid = userrecord.mqid;


	}

	MT4User::MT4User(UserRecord* users, int total): ManagedObject(new Core::MT4User()) {
		this->users = users;
		this->total = total;
	}

	MT4User::MT4User() : ManagedObject(new Core::MT4User()) {

	}

	MT4User^ MT4User::getUserIndex(int index) {
		this->userID = this->users[index].login;
		this->balance = this->users[index].balance;
		//Strings
		this->group = catos(this->users[index].group);
		this->country = catos(this->users[index].country);
		this->name = catos(this->users[index].name);
		this->city = catos(this->users[index].city);
		this->state = catos(this->users[index].state);
		this->zipcode = catos(this->users[index].zipcode);
		this->address = catos(this->users[index].address);
		this->lead_source = catos(this->users[index].lead_source);
		this->phone = catos(this->users[index].phone);
		this->email = catos(this->users[index].email);
		this->comment = catos(this->users[index].comment);
		this->id = catos(this->users[index].id);
		this->status = catos(this->users[index].status);
		this->password = catos(this->users[index].password);


		// Ints
		this->leverage = this->users[index].leverage;
		this->agent_account = this->users[index].agent_account;
		this->send_reports = this->users[index].send_reports;
		this->enable = this->users[index].enable;
		this->enable_change_password = this->users[index].enable_change_password;
		this->enable_read_only = this->users[index].enable_read_only;
		this->enable_otp = this->users[index].enable_otp;

		//Doubles
		this->prevmonthbalance = this->users[index].prevmonthbalance;
		this->prevbalance = this->users[index].prevbalance;
		this->balance = this->users[index].balance;
		this->credit = this->users[index].credit;
		this->interestrate = this->users[index].interestrate;
		this->taxes = this->users[index].taxes;
		this->prevmonthequity = this->users[index].prevmonthequity;
		this->prevequity = this->users[index].prevequity;
		this->mqid = this->users[index].mqid;

		return this;
	}

	UserRecord MT4User::getUserRecord() {
		UserRecord user = { 0 };
		user.login = this->userID;
		user.balance = this->balance;
		strcpy_s(user.group, stoca(this->group));
		strcpy_s(user.name, stoca(this->name));
		strcpy_s(user.country, stoca(this->country));
		strcpy_s(user.city, stoca(this->city));
		strcpy_s(user.state, stoca(this->state));
		strcpy_s(user.zipcode, stoca(this->zipcode));
		strcpy_s(user.address, stoca(this->address));
		strcpy_s(user.lead_source, stoca(this->lead_source));
		strcpy_s(user.phone, stoca(this->phone));
		strcpy_s(user.email, stoca(this->email));
		strcpy_s(user.comment, stoca(this->comment));
		strcpy_s(user.id, stoca(this->id));
		strcpy_s(user.status, stoca(this->status));
		strcpy_s(user.password, stoca(this->password));
		strcpy_s(user.password_investor, stoca(this->password));

		user.leverage = this->leverage;
		user.agent_account = this->agent_account;
		user.send_reports = this->send_reports;
		user.enable = this->enable;
		user.enable_change_password = this->enable_change_password;
		user.enable_read_only = this->enable_read_only;
		user.enable_otp = this->enable_otp;

		user.prevmonthbalance = this->prevmonthbalance;
		user.prevbalance = this->prevbalance;
		user.balance = this->balance;
		user.credit = this->credit;
		user.interestrate = this->interestrate;
		user.taxes = this->taxes;
		user.prevmonthequity = this->prevmonthequity;
		user.prevequity = this->prevequity;
		user.mqid = this->mqid;
		return user;
	}


	UserRecord MT4User::getUserRecordForPassword() {
		UserRecord user = { 0 };
		user.login = this->userID;
		user.balance = this->balance;
		strcpy_s(user.group, stoca(this->group));
		strcpy_s(user.name, stoca(this->name));
		strcpy_s(user.country, stoca(this->country));
		strcpy_s(user.city, stoca(this->city));
		strcpy_s(user.state, stoca(this->state));
		strcpy_s(user.zipcode, stoca(this->zipcode));
		strcpy_s(user.address, stoca(this->address));
		strcpy_s(user.lead_source, stoca(this->lead_source));
		strcpy_s(user.phone, stoca(this->phone));
		strcpy_s(user.email, stoca(this->email));
		strcpy_s(user.comment, stoca(this->comment));
		strcpy_s(user.id, stoca(this->id));
		strcpy_s(user.status, stoca(this->status));

		user.leverage = this->leverage;
		user.agent_account = this->agent_account;
		user.send_reports = this->send_reports;
		user.enable = this->enable;
		user.enable_change_password = this->enable_change_password;
		user.enable_read_only = this->enable_read_only;
		user.enable_otp = this->enable_otp;

		user.prevmonthbalance = this->prevmonthbalance;
		user.prevbalance = this->prevbalance;
		user.balance = this->balance;
		user.credit = this->credit;
		user.interestrate = this->interestrate;
		user.taxes = this->taxes;
		user.prevmonthequity = this->prevmonthequity;
		user.prevequity = this->prevequity;
		user.mqid = this->mqid;
		return user;
	}
}
