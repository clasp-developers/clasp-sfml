#include <CLASP-SFML/translators.hpp>
#include <CLASP-SFML/Window/Joystick.hpp>
#include <CLASP-SFML/Window/Keyboard.hpp>
#include <CLASP-SFML/Window/Mouse.hpp>
#include <CLASP-SFML/Window/Sensor.hpp>

#include <CLASP-SFML/Window/Event.hpp>
#include <CLASP-SFML/Window/VideoMode.hpp>

#include <CLASP-SFML/System/String.hpp>
#include <CLASP-SFML/System/Vector2.hpp>

#include <CLASP-SFML/Window/Window.hpp>
#include <CLASP-SFML/Window/Touch.hpp>
#include <CLASP-SFML/Window/Context.hpp>
#include <CLASP-SFML/Window/ContextSettings.hpp>

#include <clasp/core/foundation.h>
#include <clasp/clbind/clbind.h>
#include <clasp/core/lispVector.h>
#include <clasp/core/vectorObjects.h>
#include <clasp/core/cons.h>
#include <clasp/core/translators.h>
#include <clasp/core/str.h>

#define EXPORT __attribute__((visibility("default")))


extern "C" {
    EXPORT
    void CLASP_MAIN()
    {
        using namespace clbind;
	list<string> lnicknames = {"SF"};
	list<string> luse;
	//FIXME: here we have package SFML with nickname SF,
	//Graphics has package SF. Why does this work?
	_lisp->makePackage("SFML",lnicknames,luse);
        package("SFML")
	  [
	   registerContext(),
	   registerContextSettings(),
	   
	   registerJoystick(),
	   registerJoystickIsConnected(),
	   registerJoystickGetButtonCount(),
	   registerJoystickHasAxis(),
	   registerJoystickIsButtonPressed(),
	   registerJoystickGetAxisPosition(),
	   registerJoystickGetIdentification(),
	   registerJoystickUpdate(),
	   
	   registerKeyboard(),
	   registerKeyboardIsKeyPressed(),
	   registerKeyboardSetVirtualKeyboardVisible(),

	   registerMouse(),
	   registerMouseIsButtonPressed(),
	   registerMouseGetPosition(),
	   registerMouseGetPositionRelativeTo(),
	   registerMouseSetPosition(),
	   registerMouseSetPositionRelativeTo(),

	   registerSensor(),
	   registerSensorIsAvailable(),
	   registerSensorSetEnabled(),
	   registerSensorGetValue(),


	   registerTouch(),
	   registerTouchIsDown(),
	   registerTouchGetPosition(),
	   registerTouchGetPositionRelative(),

	   registerVideoMode(),
	   registerVideoModeGetDesktopMode(),
	   registerVideoModeGetFullscreenModes(),
	   //FIXME: missing operators

	   registerWindow(),	   

	   registerEvent(),
	   registerSizeEvent(),
	   registerKeyEvent(),
	   registerTextEvent(),
	   registerMouseMoveEvent(),
	   registerMouseButtonEvent(),
	   registerMouseWheelEvent(),
	   registerJoystickConnectEvent(),
	   registerJoystickMoveEvent(),
	   registerJoystickButtonEvent(),
	   registerTouchEvent(),
	   registerSensorEvent()	    
	   //FIXME: All the other event types.
	 ];
    }
}
