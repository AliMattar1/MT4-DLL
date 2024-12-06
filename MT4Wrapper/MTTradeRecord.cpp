#pragma once
#include "stdafx.h"
#include "MTTradeRecord.h"
namespace MT4Wrapper {

	MTTradeRecord::MTTradeRecord(TradeRecord *tRec, int total, char *tempSym) : ManagedObject(new Core::MTTradeRecord()) {
		this->tradeRecord = tRec;
		this->total = total;
		this->tempSymb = catos(tempSym);
	}

	MTTradeRecord::MTTradeRecord(TradeRecord *tRec, int total) : ManagedObject(new Core::MTTradeRecord()) {
		this->tradeRecord = tRec;
		this->total = total;
	}
	MTTradeRecord::MTTradeRecord() : ManagedObject(new Core::MTTradeRecord()) {

	}

	  MTTradeRecord^ MTTradeRecord::getTradeIndex(int index) {
			this->order = this->tradeRecord[index].order;
			this->symbol = catos(this->tradeRecord[index].symbol);
			this->cmd = this->tradeRecord[index].cmd;
			this->close_price = this->tradeRecord[index].close_price;
			this->open_price = this->tradeRecord[index].open_price;
			this->volume = this->tradeRecord[index].volume;
			this->profit = this->tradeRecord[index].profit;
			this->close_time = this->tradeRecord[index].close_time;
			this->open_time = this->tradeRecord[index].open_time;
			this->login = this->tradeRecord[index].login;
			this->sl = this->tradeRecord[index].sl;
			this->tp = this->tradeRecord[index].tp;
			this->storage = this->tradeRecord[index].storage;
			this->commission = this->tradeRecord[index].commission;
			this->timestamp = this->tradeRecord[index].timestamp;
			this->state = this->tradeRecord[index].state;

		return this;
	}
	MTTradeRecord::MTTradeRecord(TradeRecord traderecord)
		: ManagedObject(new Core::MTTradeRecord()) {
		this->login = traderecord.login;
		this->order = traderecord.order;
		this->cmd = traderecord.cmd;
		this->close_price = traderecord.close_price;
		this->symbol = catos(traderecord.symbol);
		//System::String clistr = gcnew System::String(traderecord.reason);
		//this->reason = catos(traderecord.reason);
		this->reason = charToSingleString(traderecord.reason);
		this->open_price = traderecord.open_price;
		this->volume = traderecord.volume;
		this->profit = traderecord.profit;
		this->close_time = traderecord.close_time;
		this->open_time = traderecord.open_time;
		this->commission = traderecord.commission;
		this->sl = traderecord.sl;
		this->tp = traderecord.tp;
		this->storage = traderecord.storage;
		this->timestamp = traderecord.timestamp;
		this->state = traderecord.state;
		this->digits = traderecord.digits;
		this->gw_volume = traderecord.gw_volume;
		this->expiration = traderecord.expiration;
		this->conv_reserv = catos(traderecord.conv_reserv);
		this->commission_agent = traderecord.commission_agent;
		this->taxes = traderecord.taxes;
		this->magic = traderecord.magic;
		this->comment = catos(traderecord.comment);
		this->gw_order = traderecord.gw_order;
		this->activation = traderecord.activation;
		this->gw_open_price = traderecord.gw_open_price;
		this->gw_close_price = traderecord.gw_close_price;
		this->margin_rate = traderecord.margin_rate;
	}

	TradeRecord MTTradeRecord::getTradeRecord() {
		TradeRecord trade = { 0 };
		trade.order = this->order;
		trade.commission = this->commission;
		//trade.symbol = stoca(this->symbol);
		strcpy_s(trade.symbol, stoca(this->symbol));
		trade.cmd = this->cmd;
		trade.close_price = this->close_price;
		trade.open_price = this->open_price;
		trade.volume = this->volume;
		trade.profit = this->profit;
		trade.close_time = this->close_time;
		trade.open_time = this->open_time;
		trade.login = this->login;
		trade.sl = this->sl;
		trade.tp = this->tp;
		trade.storage = this->storage;
		trade.timestamp = this->timestamp;
		trade.state = this->state;
		trade.digits = this->digits;
		trade.gw_volume = this->gw_volume;
		trade.expiration = this->expiration;
		strcpy_s(trade.conv_reserv, stoca(this->conv_reserv));
		trade.conv_rates[0] = this->conv_rates;
		trade.conv_rates[1] = this->conv_rates;
		trade.commission_agent = this->commission_agent;
		trade.storage = this->storage;
		trade.taxes = this->taxes;
		trade.magic = this->magic;
		strcpy_s(trade.comment, stoca(this->comment));
		trade.gw_order = this->gw_order;
		trade.activation = this->activation;
		trade.gw_open_price = this->gw_open_price;
		trade.gw_close_price = this->gw_close_price;
		trade.margin_rate = this->margin_rate;
		//trade.reason, stoca(this->reason);
		trade.reason, 0;
		//trade.reason = stringToSingleChar(this ->reason);
		return trade;
	}
}
