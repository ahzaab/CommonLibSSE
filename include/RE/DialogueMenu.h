#pragma once

#include <string_view>

#include "RE/BSTArray.h"
#include "RE/BSTEvent.h"
#include "RE/IMenu.h"


namespace RE
{
	class MenuOpenCloseEvent;


	class DialogueMenu :
		public IMenu,							// 00
		public BSTEventSink<MenuOpenCloseEvent>	// 30
	{
	public:
		inline static const void* RTTI = RTTI_DialogueMenu;
		constexpr static std::string_view MENU_NAME = "Dialogue Menu";


		struct Data
		{
			void*	unk00;	// 00
			UInt64	unk08;	// 08
		};
		STATIC_ASSERT(sizeof(Data) == 0x10);


		virtual ~DialogueMenu();																									// 00

		// override (IMenu)
		virtual void		Accept(CallbackProcessor* a_processor) override;														// 01
		virtual Result		ProcessMessage(UIMessage* a_message) override;															// 04

		// override (BSTEventSink<MenuOpenCloseEvent>)
		virtual	EventResult	ReceiveEvent(MenuOpenCloseEvent* a_event, BSTEventSource<MenuOpenCloseEvent>* a_eventSource) override;	// 01


		// members
		BSTArray<Data> unk38;	// 38
	};
	STATIC_ASSERT(sizeof(DialogueMenu) == 0x50);
}
