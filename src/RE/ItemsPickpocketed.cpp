#include "RE/ItemsPickpocketed.h"

#include "RE/Offsets.h"


namespace RE
{
	BSTEventSource<ItemsPickpocketed::Event>* ItemsPickpocketed::GetEventSource()
	{
		using func_t = function_type_t<decltype(&ItemsPickpocketed::GetEventSource)>;
		RelocUnrestricted<func_t*> func(Offset::ItemsPickpocketed::GetEventSource);
		return func();
	}


	void ItemsPickpocketed::SendEvent(UInt32 a_numItems)
	{
		Event e = { a_numItems, 0 };
		auto source = GetEventSource();
		source->SendEvent(&e);
	}
}
