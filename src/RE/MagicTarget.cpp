#include "RE/MagicTarget.h"

#include "RE/ActiveEffect.h"  // ActiveEffect
#include "RE/EffectSetting.h"  // EffectSetting
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/Offsets.h"


namespace RE
{
	bool MagicTarget::HasMagicEffect(EffectSetting* a_effect)
	{
		using func_t = function_type_t<decltype(&MagicTarget::HasMagicEffect)>;
		RelocUnrestricted<func_t*> func(Offset::MagicTarget::HasMagicEffect);
		return func(this, a_effect);
	}


	bool MagicTarget::HasEffectWithArchetype(Archetype a_type)
	{
		BSSimpleList<ActiveEffect*>* effects = GetActiveEffects();
		if (!effects) {
			return false;
		}

		EffectSetting* setting = 0;
		for (auto& effect : *effects) {
			setting = effect ? effect->GetBaseEffect() : 0;
			if (setting && setting->HasArchetype(a_type)) {
				return true;
			}
		}
		return false;
	}


	void MagicTarget::DispellEffectsWithArchetype(Archetype a_type, bool a_force)
	{
		BSSimpleList<ActiveEffect*>* effects = GetActiveEffects();
		if (!effects) {
			return;
		}

		EffectSetting* setting = 0;
		for (auto& effect : *effects) {
			setting = effect ? effect->GetBaseEffect() : 0;
			if (setting && setting->HasArchetype(a_type)) {
				effect->Dispell(a_force);
			}
		}
	}
}
