#pragma once

#include "Common.h"
#include "Time.h"

namespace Graphics
{
	typedef int ControlId;
	typedef int WindowId;

	#define GraphicsErrorIdBase 1000

	enum GraphicsErrorId
	{
		FailedToCreateUIThread = GraphicsErrorIdBase,
		FailedToRegisterWindowClass,
		NotHInstanceSetForGraphics,
		InvalidHInstance,
		FailedToCreateWindow,
		FailedToAllocateUserMessage,
		FailedToCreateEvent,
		FailedToCreateMessageLoop,
		FailedToCreateMessageWindow,
		FailedToSetEvent,
		InvalidWindowId,
		InvalidControlId,
		FailedToDestroyWindow,
		FailedToCreateBrush,
	};

	extern "C"
	{
		EXPORT_API WindowId EXPORT_CALL CreateGraphicsWindow(Common::ErrorId *lpError);
		EXPORT_API WindowId EXPORT_CALL CreateGraphicsWindowEx(int width, int height, Common::ErrorId *lpError);
		EXPORT_API Common::ErrorId EXPORT_CALL DestroyGraphicsWindow(WindowId graphicsWindow);

		EXPORT_API ControlId EXPORT_CALL GetGraphicsWindowRootControl(WindowId graphicsWindow);

		EXPORT_API Common::ErrorId EXPORT_CALL InvalidateControl(ControlId control);

		EXPORT_API Common::ErrorId EXPORT_CALL InvalidateControlRect(ControlId control, int x, int y, int width, int height);

		EXPORT_API Common::ErrorId EXPORT_CALL InvalidateControlCentral(ControlId control, int x, int y, int width, int height);

		EXPORT_API Common::ErrorId EXPORT_CALL SetControlOrigin(ControlId control, int x, int y);
	}
}

namespace Input
{
	enum InputType
	{
		InputNone = 0x0,
		KeyDown = 0x1,
		KeyUp = 0x2,
		MouseButtonDown = 0x4,
		MouseButtonUp = 0x8,
		MouseWheelMove = 0x10,
		MouseMove = 0x20,
	};

	inline InputType operator|(InputType a, InputType b)
	{
		return static_cast<InputType>(static_cast<int>(a) | static_cast<int>(b));
	}

	enum MouseButton
	{
		MouseNone = 0,
		MouseLeft = 1,
		MouseRight = 2,
		MouseMiddle = 3,
		MouseMax = 4,
	};

	enum KeyCode
	{
		KeyNone = 0,
		KeyMax = 256,
	};

	extern "C"
	{
		EXPORT_API bool EXPORT_CALL IsKeyDownEx(Graphics::ControlId control, KeyCode code);

		EXPORT_API bool EXPORT_CALL IsMouseButtonDownEx(Graphics::ControlId control, MouseButton button);

		EXPORT_API int EXPORT_CALL GetMouseXEx(Graphics::ControlId control);
		EXPORT_API int EXPORT_CALL GetMouseYEx(Graphics::ControlId control);

		EXPORT_API KeyCode EXPORT_CALL ConsumeKeyDownEx(Graphics::ControlId control);
		EXPORT_API KeyCode EXPORT_CALL ConsumeKeyUpEx(Graphics::ControlId control);
		EXPORT_API MouseButton EXPORT_CALL ConsumeMouseButtonDownEx(Graphics::ControlId control);
		EXPORT_API MouseButton EXPORT_CALL ConsumeMouseButtonUpEx(Graphics::ControlId control);
		EXPORT_API bool EXPORT_CALL ConsumeMouseMoveEx(Graphics::ControlId control);
		EXPORT_API int EXPORT_CALL ConsumeMouseWheelMoveEx(Graphics::ControlId control);
		EXPORT_API int EXPORT_CALL GetMouseXAtLastConsumeExd();
		EXPORT_API int EXPORT_CALL GetMouseYAtLastConsumedEx();

		EXPORT_API InputType EXPORT_CALL WaitForInputEx(Graphics::ControlId control, Time::Timestamp maximumWaitTime, InputType filter);



		EXPORT_API bool EXPORT_CALL IsKeyDown(KeyCode code);

		EXPORT_API bool EXPORT_CALL IsMouseButtonDown(MouseButton button);

		EXPORT_API int EXPORT_CALL GetMouseX();
		EXPORT_API int EXPORT_CALL GetMouseY();

		EXPORT_API KeyCode EXPORT_CALL ConsumeKeyDown();
		EXPORT_API KeyCode EXPORT_CALL ConsumeKeyUp();
		EXPORT_API MouseButton EXPORT_CALL ConsumeMouseButtonDown();
		EXPORT_API MouseButton EXPORT_CALL ConsumeMouseButtonUp();
		EXPORT_API bool EXPORT_CALL ConsumeMouseMove();
		EXPORT_API int EXPORT_CALL ConsumeMouseWheelMove();

		EXPORT_API InputType EXPORT_CALL WaitForInput(Time::Timestamp maximumWaitTime, InputType filter);

		EXPORT_API void EXPORT_CALL SetDefaultInputControl(Graphics::ControlId controlId);
	}
}
