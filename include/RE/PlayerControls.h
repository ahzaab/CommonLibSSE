#pragma once

#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTEvent.h"  // BSTEventSink
#include "RE/BSTSingleton.h"  // BSTSingletonSDM


namespace RE
{
	class InputEvent;
	class MenuOpenCloseEvent;
	class PlayerInputHandler;
	struct ActivateHandler;
	struct AttackBlockHandler;
	struct AutoMoveHandler;
	struct JumpHandler;
	struct LookHandler;
	struct MenuModeChangeEvent;
	struct MovementHandler;
	struct ReadyWeaponHandler;
	struct RunHandler;
	struct ShoutHandler;
	struct SneakHandler;
	struct SprintHandler;
	struct TESFurnitureEvent;
	struct TogglePOVHandler;
	struct ToggleRunHandler;


	class PlayerControls :
		public BSTEventSink<InputEvent*>,
		public BSTEventSink<MenuOpenCloseEvent>,
		public BSTEventSink<MenuModeChangeEvent>,
		public BSTEventSink<TESFurnitureEvent>
	{
	public:
		struct Data024
		{
			float		movementX;	// 00 - Strafe Left=-1, Strafe Right=1
			float		movementY;	// 04 - Forward=1, Back=-1
			float		unk08;		// 08
			float		unk0C;		// 0C
			float		unk10;		// 10
			float		unk14;		// 14
			float		unk18;		// 18
			float		unk1C;		// 1C
			UInt32		unk20;		// 20
			UInt8		autoRun;	// 24
			UInt8		runMode;	// 25
			UInt8		unk26;		// 26
			UInt8		unk27;		// 27
			UInt16		unk28;		// 28
			UInt8		unk2A;		// 2A
			UInt8		unk2B;		// 2B
			bool		remapMod;	// 2C
			UInt8		pad2D[7];	// 2D
		};


		PlayerControls();
		virtual	~PlayerControls();

		virtual UInt32			Unk_01();

		static PlayerControls*	GetSingleton();
		PlayerControls*			ctor_Hook();


		// members
		UInt32							pad020;				// 020
		Data024							data024;			// 024
		BSTArray<PlayerInputHandler*>	handlers;			// 058
		BSTArray<void*>					unk070;				// 070
		BSTArray<void*>					unk088;				// 088
		UInt8							unk0A0[8];			// 0A0
		UInt64							unk0A8;				// 0A8
		float							unk0B0[8];			// 0B0
		UInt32							unk0D0[10];			// 0D0
		UInt8							unk0F8[8];			// 0F8
		float							unk100[20];			// 100
		BSTArray<void*>					unk150;				// 150
		UInt64							unk168;				// 168
		MovementHandler*				movementHandler;	// 170
		LookHandler*					lookHandler;		// 178
		SprintHandler*					sprintHandler;		// 180
		ReadyWeaponHandler*				readyWeaponHandler; // 188
		AutoMoveHandler*				autoMoveHandler;	// 190
		ToggleRunHandler*				toggleRunHandler;	// 198
		ActivateHandler*				activateHandler;	// 1A0
		JumpHandler*					jumpHandler;		// 1A8
		ShoutHandler*					shoutHandler;		// 1B0
		AttackBlockHandler*				attackBlockHandler; // 1B8
		RunHandler*						runHandler;			// 1C0
		SneakHandler*					sneakHandler;		// 1C8
		TogglePOVHandler*				togglePOVHandler;	// 1D0

	private:
		PlayerControls* ctor_internal();
	};
	STATIC_ASSERT(offsetof(PlayerControls, data024) == 0x024);
}
