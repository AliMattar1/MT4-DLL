#pragma once
#include "MTConSymbol.h"
namespace MT4Wrapper {

	MTConSymbol::MTConSymbol() : ManagedObject(new Core::MTConSymbol()) {

	}

	MTConSymbol::MTConSymbol(ConSymbol *sRec, int total) : ManagedObject(new Core::MTConSymbol()) {
		this->conSymbol = sRec;
		this->total = total;
	}

	MTConSymbol^ MTConSymbol::getSymbolIndex(int index) {
		this->symbol = catos(this->conSymbol[index].symbol);
		this->description = catos(this->conSymbol[index].description);
		this->source = catos(this->conSymbol[index].source);
		this->currency = catos(this->conSymbol[index].currency);
		this->contract_size = this->conSymbol[index].contract_size;
		/*this->type = this->conSymbol[index].type;
		this->digits = this->conSymbol[index].digits;
		this->trade = this->conSymbol[index].trade;
		this->margin_mode = this->conSymbol[index].margin_mode;
		this->margin_initial = this->conSymbol[index].margin_initial;
		this->margin_maintenance = this->conSymbol[index].margin_maintenance;
		this->margin_hedged = this->conSymbol[index].margin_hedged;
		this->margin_divider = this->conSymbol[index].margin_divider;*/

		return this;
	}
}