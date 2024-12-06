#pragma once
#include "stdafx.h"
#include "ManagedObject.h"
#include "../MT4/Core.h"
using namespace System;
namespace MT4Wrapper {
	public ref class MT4User : public ManagedObject<Core::MT4User>
	{
	public:
		MT4User(const UserRecord userrecord);
		MT4User(UserRecord* users, int total);
		MT4User();
		MT4User^ getUserIndex(int index);
		UserRecord getUserRecord();
		UserRecord getUserRecordForPassword();

		UserRecord* users;
		int total;
		
		int userID, leverage, agent_account, send_reports, last_ip, enable, enable_change_password, enable_read_only, enable_otp;
		unsigned int mqid;
		double balance, prevmonthbalance, prevbalance, credit, interestrate, taxes, prevmonthequity, prevequity;
		String^ group = "";
		String^  name = "";
		String^  country = "";
		String^  city = "";
		String^  state = "";
		String^  zipcode = "";
		String^  address = "";
		String^  lead_source = "";
		String^  phone = "";
		String^  email = "";
		String^  comment = "";
		String^  id = "";
		String^  status = "";
		String^ password = "";
	};


}
