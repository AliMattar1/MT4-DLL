#include "MTGroup.h"
namespace MT4Wrapper {

	MTGroup::MTGroup() : ManagedObject(new Core::MTGroup) {

	}

	MTGroup::MTGroup(ConGroup* gRecord, int total) : ManagedObject(new Core::MTGroup) {
		this->conGroup = gRecord;
		this->total = total;
	}

	MTGroup^ MTGroup::getGroupIndex(int index) {
		this->groupName = catos(this->conGroup[index].group);

		return this;
	}
}