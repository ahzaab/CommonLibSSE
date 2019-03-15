#include "RE/NiControllerManager.h"

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/Offsets.h"


namespace RE
{
	NiControllerSequence* NiControllerManager::GetSequenceByName(const BSFixedString& a_name)
	{
		using func_t = function_type_t<decltype(&NiControllerManager::GetSequenceByName)>;
		RelocUnrestricted<func_t*> func(Offset::NiControllerManager::GetSequenceByName);
		return func(this, a_name);
	}
}
