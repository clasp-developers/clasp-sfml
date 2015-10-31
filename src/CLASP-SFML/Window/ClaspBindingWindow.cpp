#include <CLASP-SFML/translators.hpp>
#include <CLASP-SFML/Window/Joystick.hpp>
#include <CLASP-SFML/Window/Keyboard.hpp>
#include <CLASP-SFML/Window/Mouse.hpp>
#include <CLASP-SFML/Window/Sensor.hpp>

#include <CLASP-SFML/Window/Event.hpp>
#include <CLASP-SFML/Window/VideoMode.hpp>

#include <CLASP-SFML/System/String.hpp>
#include <CLASP-SFML/System/Vector2.hpp>

#include <SFML/Window/Window.hpp>
#include <SFML/Window/Touch.hpp>
#include <SFML/Window/Context.hpp>


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
	_lisp->makePackage("SFML",lnicknames,luse);
        package("SFML")
	  [
	   class_<sf::Context>("context")
	   .def("set-active", &sf::Context::setActive,
		policies<>(), "", "",
		R"**(\brief Activate or deactivate explicitly the context

		\param active True to activate, false to deactivate

		\return True on success, false on failure)**")

	   //FIXME: missing ContextSettings

	   ,
	   class_<sf::Joystick>("joystick")
	   .enum_<sf::Joystick::Axis>(core::lisp_intern("*JOYSTICK-AXIS-ENUM-MAPPER*", "SFML"))
	   [
	   value("joystick-axis/x", sf::Joystick::Axis::X),
	   value("joystick-axis/y", sf::Joystick::Axis::Y),
	   value("joystick-axis/z", sf::Joystick::Axis::Z),
	   value("joystick-axis/r", sf::Joystick::Axis::R),
	   value("joystick-axis/u", sf::Joystick::Axis::U),
	   value("joystick-axis/v", sf::Joystick::Axis::V),
	   value("joystick-axis/pov-x", sf::Joystick::Axis::PovX),
	   value("joystick-axis/pov-y", sf::Joystick::Axis::PovY)
	   ]

	   //FIXME: Missing struct identification

	   ,def("joystick/is-connected", &sf::Joystick::isConnected,
		policies<>(), "", "",
		R"**(\brief Check if a joystick is connected

		\param joystick Index of the joystick to check

		\return True if the joystick is connected, false otherwise)**")

	   ,def("joystick/get-button-count", &sf::Joystick::getButtonCount,
		policies<>(), "", "",
		R"**(\brief Return the number of buttons supported by a joystick

		If the joystick is not connected, this function returns 0.

		\param joystick Index of the joystick

		\return Number of buttons supported by the joystick)**")

	   ,def("joystick/has-axis", &sf::Joystick::hasAxis,
		policies<>(), "", "",
		R"**(\brief Check if a joystick supports a given axis

		If the joystick is not connected, this function returns false.

		\param joystick Index of the joystick
		\param axis     Axis to check

		\return True if the joystick supports the axis, false otherwise)**")

	   ,def("joystick/is-button-pressed", &sf::Joystick::isButtonPressed,
		policies<>(), "", "",
		R"**(\brief Check if a joystick button is pressed

		If the joystick is not connected, this function returns false.

		\param joystick Index of the joystick
		\param button   Button to check

		\return True if the button is pressed, false otherwise)**")

	   ,def("joystick/get-axis-position", &sf::Joystick::getAxisPosition,
		policies<>(), "", "",
		R"**(\brief Get the current position of a joystick axis

		If the joystick is not connected, this function returns 0.

		\param joystick Index of the joystick
		\param axis     Axis to check

		\return Current position of the axis, in range [-100 .. 100])**")

	   ,def("joystick/get-identification", &sf::Joystick::getIdentification,
		policies<>(), "", "",
		R"**(\brief Get the joystick information

		\param joystick Index of the joystick

		\return Structure containing joystick information.)**")

	   ,def("joystick/update", &sf::Joystick::update,
		policies<>(), "", "",
		R"**(\brief Update the states of all joysticks

		This function is used internally by SFML, so you normally
		don't have to call it explicitly. However, you may need to
		call it if you have no window yet (or no window at all):
		in this case the joystick states are not updated automatically.)**")

	   ,class_<sf::Keyboard>("keyobard", no_default_constructor)

	   .enum_<sf::Keyboard::Key>(core::lisp_intern("*KEYBOARD-KEY-ENUM-MAPPER*", "SFML"))
	   [
	   value("keyboard-key/unknown", sf::Keyboard::Key::Unknown),
	   value("keyboard-key/a", sf::Keyboard::Key::A),
	   value("keyboard-key/b", sf::Keyboard::Key::B),
	   value("keyboard-key/c", sf::Keyboard::Key::C),
	   value("keyboard-key/d", sf::Keyboard::Key::D),
	   value("keyboard-key/e", sf::Keyboard::Key::E),
	   value("keyboard-key/f", sf::Keyboard::Key::F),
	   value("keyboard-key/g", sf::Keyboard::Key::G),
	   value("keyboard-key/h", sf::Keyboard::Key::H),
	   value("keyboard-key/i", sf::Keyboard::Key::I),
	   value("keyboard-key/j", sf::Keyboard::Key::J),
	   value("keyboard-key/k", sf::Keyboard::Key::K),
	   value("keyboard-key/l", sf::Keyboard::Key::L),
	   value("keyboard-key/m", sf::Keyboard::Key::M),
	   value("keyboard-key/n", sf::Keyboard::Key::N),
	   value("keyboard-key/o", sf::Keyboard::Key::O),
	   value("keyboard-key/p", sf::Keyboard::Key::P),
	   value("keyboard-key/q", sf::Keyboard::Key::Q),
	   value("keyboard-key/r", sf::Keyboard::Key::R),
	   value("keyboard-key/s", sf::Keyboard::Key::S),
	   value("keyboard-key/t", sf::Keyboard::Key::T),
	   value("keyboard-key/u", sf::Keyboard::Key::U),
	   value("keyboard-key/v", sf::Keyboard::Key::V),
	   value("keyboard-key/w", sf::Keyboard::Key::W),
	   value("keyboard-key/x", sf::Keyboard::Key::X),
	   value("keyboard-key/y", sf::Keyboard::Key::Y),
	   value("keyboard-key/z", sf::Keyboard::Key::Z),
	   value("keyboard-key/num0", sf::Keyboard::Key::Num0),
	   value("keyboard-key/num1", sf::Keyboard::Key::Num1),
	   value("keyboard-key/num2", sf::Keyboard::Key::Num2),
	   value("keyboard-key/num3", sf::Keyboard::Key::Num3),
	   value("keyboard-key/num4", sf::Keyboard::Key::Num4),
	   value("keyboard-key/num5", sf::Keyboard::Key::Num5),
	   value("keyboard-key/num6", sf::Keyboard::Key::Num6),
	   value("keyboard-key/num7", sf::Keyboard::Key::Num7),
	   value("keyboard-key/num8", sf::Keyboard::Key::Num8),
	   value("keyboard-key/num9", sf::Keyboard::Key::Num9),
	   value("keyboard-key/escape", sf::Keyboard::Key::Escape),
	   value("keyboard-key/l-control", sf::Keyboard::Key::LControl),
	   value("keyboard-key/l-shift", sf::Keyboard::Key::LShift),
	   value("keyboard-key/l-alt", sf::Keyboard::Key::LAlt),
	   value("keyboard-key/l-system", sf::Keyboard::Key::LSystem),
	   value("keyboard-key/r-control", sf::Keyboard::Key::RControl),
	   value("keyboard-key/r-shift", sf::Keyboard::Key::RShift),
	   value("keyboard-key/r-alt", sf::Keyboard::Key::RAlt),
	   value("keyboard-key/r-system", sf::Keyboard::Key::RSystem),
	   value("keyboard-key/menu", sf::Keyboard::Key::Menu),
	   value("keyboard-key/l-bracket", sf::Keyboard::Key::LBracket),
	   value("keyboard-key/r-bracket", sf::Keyboard::Key::RBracket),
	   value("keyboard-key/semi-colon", sf::Keyboard::Key::SemiColon),
	   value("keyboard-key/comma", sf::Keyboard::Key::Comma),
	   value("keyboard-key/period", sf::Keyboard::Key::Period),
	   value("keyboard-key/quote", sf::Keyboard::Key::Quote),
	   value("keyboard-key/slash", sf::Keyboard::Key::Slash),
	   value("keyboard-key/back-slash", sf::Keyboard::Key::BackSlash),
	   value("keyboard-key/tilde", sf::Keyboard::Key::Tilde),
	   value("keyboard-key/equal", sf::Keyboard::Key::Equal),
	   value("keyboard-key/dash", sf::Keyboard::Key::Dash),
	   value("keyboard-key/space", sf::Keyboard::Key::Space),
	   value("keyboard-key/return", sf::Keyboard::Key::Return),
	   value("keyboard-key/back-space", sf::Keyboard::Key::BackSpace),
	   value("keyboard-key/tab", sf::Keyboard::Key::Tab),
	   value("keyboard-key/page-up", sf::Keyboard::Key::PageUp),
	   value("keyboard-key/page-down", sf::Keyboard::Key::PageDown),
	   value("keyboard-key/end", sf::Keyboard::Key::End),
	   value("keyboard-key/home", sf::Keyboard::Key::Home),
	   value("keyboard-key/insert", sf::Keyboard::Key::Insert),
	   value("keyboard-key/delete", sf::Keyboard::Key::Delete),
	   value("keyboard-key/add", sf::Keyboard::Key::Add),
	   value("keyboard-key/subtract", sf::Keyboard::Key::Subtract),
	   value("keyboard-key/multiply", sf::Keyboard::Key::Multiply),
	   value("keyboard-key/divide", sf::Keyboard::Key::Divide),
	   value("keyboard-key/left", sf::Keyboard::Key::Left),
	   value("keyboard-key/right", sf::Keyboard::Key::Right),
	   value("keyboard-key/up", sf::Keyboard::Key::Up),
	   value("keyboard-key/down", sf::Keyboard::Key::Down),
	   value("keyboard-key/numpad0", sf::Keyboard::Key::Numpad0),
	   value("keyboard-key/numpad1", sf::Keyboard::Key::Numpad1),
	   value("keyboard-key/numpad2", sf::Keyboard::Key::Numpad2),
	   value("keyboard-key/numpad3", sf::Keyboard::Key::Numpad3),
	   value("keyboard-key/numpad4", sf::Keyboard::Key::Numpad4),
	   value("keyboard-key/numpad5", sf::Keyboard::Key::Numpad5),
	   value("keyboard-key/numpad6", sf::Keyboard::Key::Numpad6),
	   value("keyboard-key/numpad7", sf::Keyboard::Key::Numpad7),
	   value("keyboard-key/numpad8", sf::Keyboard::Key::Numpad8),
	   value("keyboard-key/numpad9", sf::Keyboard::Key::Numpad9),
	   value("keyboard-key/f1", sf::Keyboard::Key::F1),
	   value("keyboard-key/f2", sf::Keyboard::Key::F2),
	   value("keyboard-key/f3", sf::Keyboard::Key::F3),
	   value("keyboard-key/f4", sf::Keyboard::Key::F4),
	   value("keyboard-key/f5", sf::Keyboard::Key::F5),
	   value("keyboard-key/f6", sf::Keyboard::Key::F6),
	   value("keyboard-key/f7", sf::Keyboard::Key::F7),
	   value("keyboard-key/f8", sf::Keyboard::Key::F8),
	   value("keyboard-key/f9", sf::Keyboard::Key::F9),
	   value("keyboard-key/f10", sf::Keyboard::Key::F10),
	   value("keyboard-key/f11", sf::Keyboard::Key::F11),
	   value("keyboard-key/f12", sf::Keyboard::Key::F12),
	   value("keyboard-key/f13", sf::Keyboard::Key::F13),
	   value("keyboard-key/f14", sf::Keyboard::Key::F14),
	   value("keyboard-key/f15", sf::Keyboard::Key::F15),
	   value("keyboard-key/pause", sf::Keyboard::Key::Pause)
	   ]

	   ,def("keyboard/is-key-pressed", &sf::Keyboard::isKeyPressed,
		policies<>(), "", "",
		R"**(\brief Check if a key is pressed

		\param key Key to check

		\return True if the key is pressed, false otherwise)**")

	   ,def("keyboard/set-virtual-keyboard-visible", &sf::Keyboard::setVirtualKeyboardVisible,
		policies<>(), "", "",
		R"**(\brief Show or hide the virtual keyboard

		Warning: the virtual keyboard is not supported on all
		systems. It will typically be implemented on mobile OSes
		(Android, iOS) but not on desktop OSes (Windows, Linux, ...).

		If the virtual keyboard is not available, this function does
		nothing.

		\param visible True to show, false to hide)**")

	   ,class_<sf::Mouse>("mouse", no_default_constructor)

	   .enum_<sf::Mouse::Button>(core::lisp_intern("*MOUSE-BUTTON-ENUM-MAPPER*", "SFML"))
	   [
	   value("mouse-button/left", sf::Mouse::Button::Left),
	   value("mouse-button/right", sf::Mouse::Button::Right),
	   value("mouse-button/middle", sf::Mouse::Button::Middle),
	   value("mouse-button/x-button1", sf::Mouse::Button::XButton1),
	   value("mouse-button/x-button2", sf::Mouse::Button::XButton2),
	   value("mouse-button/button-count", sf::Mouse::Button::ButtonCount)
	   ]

	   ,def("mouse/is-button-pressed", &sf::Mouse::isButtonPressed,
		policies<>(), "", "",
		R"**(\brief Check if a mouse button is pressed

		\param button Button to check

		\return True if the button is pressed, false otherwise)**")

	   ,def("mouse/get-position", (sf::Vector2i (*)(void))&sf::Mouse::getPosition,
		policies<>(), "", "",
		R"**(\brief Get the current position of the mouse in window coordinates

		This function returns the current position of the mouse
		cursor, relative to the given window.

		\param relativeTo Reference window

		\return Current position of the mouse)**")

	   ,def("mouse/get-position", (sf::Vector2i (*)(const sf::Window &))&sf::Mouse::getPosition,
		policies<>(), "", "",
		R"**(\brief Get the current position of the mouse in window coordinates

		This function returns the current position of the mouse
		cursor, relative to the given window.

		\param relativeTo Reference window

		\return Current position of the mouse)**")

	   ,def("mouse/set-position-v", (void (*)(const sf::Vector2i &))&sf::Mouse::setPosition,
		policies<>(), "", "",
		R"**(\brief Set the current position of the mouse in desktop coordinates

		This function sets the global position of the mouse
		cursor on the desktop.

		\param position New position of the mouse)**")

	    ,def("mouse/set-position-vw", (void (*)(const sf::Vector2i &, const sf::Window &))&sf::Mouse::setPosition,
		policies<>(), "", "",
		R"**(\brief Set the current position of the mouse in window coordinates

		This function sets the current position of the mouse
		cursor, relative to the given window.

		\param position New position of the mouse
		\param relativeTo Reference window)**")

	   ,class_<sf::Sensor>("sensor", no_default_constructor)

	   .enum_<sf::Sensor::Type>(core::lisp_intern("*SENSOR-TYPE-ENUM-MAPPER*", "SFML"))
	   [
	   value("sensor-type/accelerometer", sf::Sensor::Type::Accelerometer),
	   value("sensor-type/gyroscope", sf::Sensor::Type::Gyroscope),
	   value("sensor-type/magnetometer", sf::Sensor::Type::Magnetometer),
	   value("sensor-type/gravity", sf::Sensor::Type::Gravity),
	   value("sensor-type/user-acceleration", sf::Sensor::Type::UserAcceleration),
	   value("sensor-type/orientation", sf::Sensor::Type::Orientation),
	   value("sensor-type/count", sf::Sensor::Type::Count)
	   ]

	   ,def("sensor/is-available", &sf::Sensor::isAvailable,
		policies<>(), "", "",
		R"**(\brief Check if a sensor is available on the underlying platform

		\param sensor Sensor to check

		\return True if the sensor is available, false otherwise)**")

	   ,def("sensor/set-enabled", &sf::Sensor::setEnabled,
		policies<>(), "", "",
		R"**(\brief Enable or disable a sensor

		All sensors are disabled by default, to avoid consuming too 
		much battery power. Once a sensor is enabled, it starts
		sending events of the corresponding type.

		This function does nothing if the sensor is unavailable.

		\param sensor  Sensor to enable
		\param enabled True to enable, false to disable)**")

	   ,def("sensor/get-value", &sf::Sensor::getValue,
		policies<>(), "", "",
		R"**(\brief Get the current sensor value

		\param sensor Sensor to read

		\return The current sensor value)**")

	   ,class_<sf::Touch>("touch", no_default_constructor)

	   ,def("touch/is-down", &sf::Touch::isDown,
		policies<>(), "", "",
		R"**(\brief Check if a touch event is currently down

		\param finger Finger index

		\return True if \a finger is currently touching the screen, false otherwise)**")

	   ,def("touch/get-position-u", (sf::Vector2i (*)(unsigned int))&sf::Touch::getPosition,
		policies<>(), "", "",
		R"**(\brief Get the current position of a touch in desktop coordinates

		This function returns the current touch position
		in global (desktop) coordinates.

		\param finger Finger index

		\return Current position of \a finger, or undefined if it's not down)**")

	   ,def("touch/get-position-uw", (sf::Vector2i (*)(unsigned int, const sf::Window &))&sf::Touch::getPosition,
		policies<>(), "", "",
		R"**(\brief Get the current position of a touch in window coordinates

		This function returns the current touch position
		in global (desktop) coordinates.

		\param finger Finger index
		\param relativeTo Reference window

		\return Current position of \a finger, or undefined if it's not down)**")

	   ,class_<sf::VideoMode>("video-mode")

	   .def_constructor("make-video-mode", constructor<unsigned int, unsigned int, unsigned int>())

	   .def("is-valid", &sf::VideoMode::isValid,
		policies<>(), "", "",
		R"**(\brief Tell whether or not the video mode is valid

		The validity of video modes is only relevant when using
		fullscreen windows; otherwise any video mode can be used
		with no restriction.

		\return True if the video mode is valid for fullscreen mode)**")

	   ,def("video-mode/get-fullscreen-modes", &sf::VideoMode::getFullscreenModes,
		policies<>(), "", "",
		R"**(\brief Retrieve all the video modes supported in fullscreen mode

		When creating a fullscreen window, the video mode is restricted
		to be compatible with what the graphics driver and monitor
		support. This function returns the complete list of all video
		modes that can be used in fullscreen mode.
		The returned array is sorted from best to worst, so that
		the first element will always give the best mode (higher
		width, height and bits-per-pixel).

		\return Array containing all the supported fullscreen modes)**")

	   ,def("video-mode/get-desktop-mode", &sf::VideoMode::getDesktopMode,
		policies<>(), "", "",
		R"**(\brief Get the current desktop video mode

		\return Current desktop video mode)**")

	   //FIXME: missing access to public member data

	   //FIXME: missing operators

	   ,class_<sf::Window>("window", no_default_constructor)

	   .def_constructor("make-window", constructor<>())
	   
	   .def_constructor("make-window-vsuc", constructor<sf::VideoMode, sf::String, sf::Uint32, const sf::ContextSettings &>())

	   .def_constructor("make-window-wc", constructor<sf::WindowHandle, const sf::ContextSettings &>())

	   .def("create-vsuc", (void (sf::Window::*)(sf::VideoMode, const sf::String &, sf::Uint32, const sf::ContextSettings &))&sf::Window::create,
		policies<>(), "", "",
		R"**(\brief Create (or recreate) the window

		If the window was already created, it closes it first.
		If \a style contains Style::Fullscreen, then \a mode
		must be a valid video mode.

		The fourth parameter is an optional structure specifying
		advanced OpenGL context settings such as antialiasing,
		depth-buffer bits, etc.

		\param mode     Video mode to use (defines the width, height and depth of the rendering area of the window)
		\param title    Title of the window
		\param style    %Window style, a bitwise OR combination of sf::Style enumerators
		\param settings Additional settings for the underlying OpenGL context)**")

	   .def("create-wc", (void (sf::Window::*)(sf::WindowHandle, const sf::ContextSettings &))&sf::Window::create,
		policies<>(), "", "",
		R"**(\brief Create (or recreate) the window from an existing control

		Use this function if you want to create an OpenGL
		rendering area into an already existing control.
		If the window was already created, it closes it first.

		The second parameter is an optional structure specifying
		advanced OpenGL context settings such as antialiasing,
		depth-buffer bits, etc.

		\param handle   Platform-specific handle of the control (\a HWND on
		Windows, \a %Window on Linux/FreeBSD, \a NSWindow on OS X)
		\param settings Additional settings for the underlying OpenGL context)**")

	   .def("close", &sf::Window::close,
		policies<>(), "", "",
		R"**(\brief Close the window and destroy all the attached resources

		After calling this function, the sf::Window instance remains
		valid and you can call create() to recreate the window.
		All other functions such as pollEvent() or display() will
		still work (i.e. you don't have to test isOpen() every time),
		and will have no effect on closed windows.)**")

	   .def("is-open", &sf::Window::isOpen,
		policies<>(), "", "",
		R"**(\brief Tell whether or not the window is open

		This function returns whether or not the window exists.
		Note that a hidden window (setVisible(false)) is open
		(therefore this function would return true).

		\return True if the window is open, false if it has been closed)**")

	   .def("get-settings", &sf::Window::getSettings,
		policies<>(), "", "",
		R"**(\brief Get the settings of the OpenGL context of the window

		Note that these settings may be different from what was
		passed to the constructor or the create() function,
		if one or more settings were not supported. In this case,
		SFML chose the closest match.

		\return Structure containing the OpenGL context settings)**")

	   .def("poll-event", &sf::Window::pollEvent,
		policies<>(), "", "",
		R"**(\brief Pop the event on top of the event queue, if any, and return it

		This function is not blocking: if there's no pending event then
		it will return false and leave \a event unmodified.
		Note that more than one event may be present in the event queue,
		thus you should always call this function in a loop
		to make sure that you process every pending event.
		\code
		sf::Event event;
		while (window.pollEvent(event))
		{
		process event...
		}
		\endcode

		\param event Event to be returned

		\return True if an event was returned, or false if the event queue was empty

		\see waitEvent)**")

	   .def("wait-event", &sf::Window::waitEvent,
		policies<>(), "", "",
		R"**(\brief Wait for an event and return it

		This function is blocking: if there's no pending event then
		it will wait until an event is received.
		After this function returns (and no error occurred),
		the \a event object is always valid and filled properly.
		This function is typically used when you have a thread that
		is dedicated to events handling: you want to make this thread
		sleep as long as no new event is received.
		\code
		sf::Event event;
		if (window.waitEvent(event))
		{
		process event...
		}
		\endcode

		\param event Event to be returned

		\return False if any error occurred

		\see pollEvent)**")

	   .def("get-position", &sf::Window::getPosition,
		policies<>(), "", "",
		R"**(\brief Get the position of the window

		\return Position of the window, in pixels

		\see setPosition)**")

	   .def("set-position", &sf::Window::setPosition,
		policies<>(), "", "",
		R"**(\brief Change the position of the window on screen

		This function only works for top-level windows
		(i.e. it will be ignored for windows created from
		the handle of a child window/control).

		\param position New position, in pixels

		\see getPosition)**")

	   .def("get-size", &sf::Window::getSize,
		policies<>(), "", "",
		R"**(\brief Get the size of the rendering region of the window

		The size doesn't include the titlebar and borders
		of the window.

		\return Size in pixels

		\see setSize)**")

	   .def("set-size", &sf::Window::setSize,
		policies<>(), "", "",
		R"**(\brief Change the size of the rendering region of the window

		\param size New size, in pixels

		\see getSize)**")

	   .def("set-title", &sf::Window::setTitle,
		policies<>(), "", "",
		R"**(\brief Change the title of the window

		\param title New title

		\see setIcon)**")

	   // .def("set-icon", &sf::Window::setIcon,
	   // 	policies<>(), "", "",
	   // 	R"**(\brief Change the window's icon

	   // 	\a pixels must be an array of \a width x \a height pixels
	   // 	in 32-bits RGBA format.

	   // 	The OS default icon is used by default.

	   // 	\param width  Icon's width, in pixels
	   // 	\param height Icon's height, in pixels
	   // 	\param pixels Pointer to the array of pixels in memory. The
	   // 	pixels are copied, so you need not keep the
	   // 	source alive after calling this function.

	   // 	\see setTitle)**")

	   .def("set-visible", &sf::Window::setVisible,
		policies<>(), "", "",
		R"**(\brief Show or hide the window

		The window is shown by default.

		\param visible True to show the window, false to hide it)**")

	   .def("set-vertical-sync-enabled", &sf::Window::setVerticalSyncEnabled,
		policies<>(), "", "",
		R"**(\brief Enable or disable vertical synchronization

		Activating vertical synchronization will limit the number
		of frames displayed to the refresh rate of the monitor.
		This can avoid some visual artifacts, and limit the framerate
		to a good value (but not constant across different computers).

		Vertical synchronization is disabled by default.

		\param enabled True to enable v-sync, false to deactivate it)**")

	   .def("set-mouse-cursor-visible", &sf::Window::setMouseCursorVisible,
		policies<>(), "", "",
		R"**(\brief Show or hide the mouse cursor

		The mouse cursor is visible by default.

		\param visible True to show the mouse cursor, false to hide it)**")

	   .def("set-key-repeat-enabled", &sf::Window::setKeyRepeatEnabled,
		policies<>(), "", "",
		R"**(\brief Enable or disable automatic key-repeat

		If key repeat is enabled, you will receive repeated
		KeyPressed events while keeping a key pressed. If it is disabled,
		you will only get a single event when the key is pressed.

		Key repeat is enabled by default.

		\param enabled True to enable, false to disable)**")

	   .def("set-framerate-limit", &sf::Window::setFramerateLimit,
		policies<>(), "", "",
		R"**(\brief Limit the framerate to a maximum fixed frequency

		If a limit is set, the window will use a small delay after
		each call to display() to ensure that the current frame
		lasted long enough to match the framerate limit.
		SFML will try to match the given limit as much as it can,
		but since it internally uses sf::sleep, whose precision
		depends on the underlying OS, the results may be a little
		unprecise as well (for example, you can get 65 FPS when
		requesting 60).

		\param limit Framerate limit, in frames per seconds (use 0 to disable limit))**")

	   .def("set-joystick-threshold", &sf::Window::setJoystickThreshold,
		policies<>(), "", "",
		R"**(\brief Change the joystick threshold

		The joystick threshold is the value below which
		no JoystickMoved event will be generated.

		The threshold value is 0.1 by default.

		\param threshold New threshold, in the range [0, 100])**")

	   .def("set-active", &sf::Window::setActive,
		policies<>(), "", "",
		R"**(\brief Activate or deactivate the window as the current target
		for OpenGL rendering

		A window is active only on the current thread, if you want to
		make it active on another thread you have to deactivate it
		on the previous thread first if it was active.
		Only one window can be active on a thread at a time, thus
		the window previously active (if any) automatically gets deactivated.
		This is not to be confused with requestFocus().

		\param active True to activate, false to deactivate

		\return True if operation was successful, false otherwise)**")

	   .def("request-focus", &sf::Window::requestFocus,
		policies<>(), "", "",
		R"**(\brief Request the current window to be made the active
		foreground window

		At any given time, only one window may have the input focus
		to receive input events such as keystrokes or mouse events.
		If a window requests focus, it only hints to the operating
		system, that it would like to be focused. The operating system
		is free to deny the request.
		This is not to be confused with setActive().

		\see hasFocus)**")

	   .def("has-focus", &sf::Window::hasFocus,
		policies<>(), "", "",
		R"**(\brief Check whether the window has the input focus

		At any given time, only one window may have the input focus
		to receive input events such as keystrokes or most mouse
		events.

		\return True if window has focus, false otherwise
		\see requestFocus)**")

	   .def("display", &sf::Window::display,
		policies<>(), "", "",
		R"**(\brief Display on screen what has been rendered to the window so far

		This function is typically called after all OpenGL rendering
		has been done for the current frame, in order to show
		it on screen.)**")

	   .def("get-system-handle", &sf::Window::getSystemHandle,
		policies<>(), "", "",
		R"**(\brief Get the OS-specific handle of the window

		The type of the returned handle is sf::WindowHandle,
		which is a typedef to the handle type defined by the OS.
		You shouldn't need to use this function, unless you have
		very specific stuff to implement that SFML doesn't support,
		or implement a temporary workaround until a bug is fixed.
		The type is \a HWND on Windows, \a %Window on Linux/FreeBSD
		and \a NSWindow on OS X.

		\return System handle of the window)**")

	   //FIXME: WindowStyle.hpp enum - how to deal with or-able enums?
	   



	   
	   
	   
	   
	   // ,class_<sf::Window>("window", no_default_constructor)
	   // . def_constructor("make-window",constructor<sf::VideoMode, sf::String>())
	   // //overloaded. Need to specify which is called.
	   // //. def("create",&sf::Window::create)
	   // . def("close",&sf::Window::close)
	   // . def("is-open",&sf::Window::isOpen)
	   // . def("get-settings",&sf::Window::getSettings)
	   // . def("poll-event",&sf::Window::pollEvent)
	   // . def("wait-event",&sf::Window::waitEvent)
	   // . def("get-position",&sf::Window::getPosition)
	   // . def("set-position",&sf::Window::setPosition)
	   // . def("get-size",&sf::Window::getSize)
	   // . def("set-size",&sf::Window::setSize)
	   // . def("set-title",&sf::Window::setTitle)
	   // //[unknown error] error: base specifier must name a class , public Alien
	   // //	   . def("set-icon",&sf::Window::setIcon)
   	   // . def("set-visible",&sf::Window::setVisible)
   	   // . def("set-vertical-sync-enabled",&sf::Window::setVerticalSyncEnabled)
	   // . def("set-mouse-cursor-visible",&sf::Window::setMouseCursorVisible)
	   // . def("set-key-repeat-enabled",&sf::Window::setKeyRepeatEnabled)
	   // . def("set-framerate-limit",&sf::Window::setFramerateLimit)
	   // //[unknown error] error: base specifier must name a class , public Alien
	   // //. def("set-joystick-threshold",&sf::Window::setJoystickThreshold)
	   // . def("set-active",&sf::Window::setActive)
	   // . def("request-focus",&sf::Window::requestFocus)
	   // . def("has-focus",&sf::Window::hasFocus)
	   // . def("display",&sf::Window::display)
	   // . def("get-system-handle",&sf::Window::getSystemHandle)
	   ,
	   class_<sf::Event>("event")
	   . def_constructor("make-event",constructor<>())
	   //. def_readonly("type", &sf::Event::type)
	   
	   . enum_<sf::Event::EventType>(core::lisp_intern("*EVENT-EVENTTYPE-ENUM-MAPPER*", "SFML"))
	   [ value("Closed",sf::Event::EventType::Closed) 
	     , value("Resized",sf::Event::EventType::Resized)                
	     , value("LostFocus",sf::Event::EventType::LostFocus)              
	     , value("GainedFocus",sf::Event::EventType::GainedFocus)            
	     , value("TextEntered",sf::Event::EventType::TextEntered)            
	     , value("KeyPressed",sf::Event::EventType::KeyPressed)             
	     , value("KeyReleased",sf::Event::EventType::KeyReleased)            
	     , value("MouseWheelMoved",sf::Event::EventType::MouseWheelMoved)        
	     , value("MouseButtonPressed",sf::Event::EventType::MouseButtonPressed)     
	     , value("MouseButtonReleased",sf::Event::EventType::MouseButtonReleased)    
	     , value("MouseMoved",sf::Event::EventType::MouseMoved)             
	     , value("MouseEntered",sf::Event::EventType::MouseEntered)           
	     , value("MouseLeft",sf::Event::EventType::MouseLeft)              
	     , value("JoystickButtonPressed",sf::Event::EventType::JoystickButtonPressed)  
	     , value("JoystickButtonReleased",sf::Event::EventType::JoystickButtonReleased) 
	     , value("JoystickMoved",sf::Event::EventType::JoystickMoved)          
	     , value("JoystickConnected",sf::Event::EventType::JoystickConnected)      
	     , value("JoystickDisconnected",sf::Event::EventType::JoystickDisconnected)   
	     , value("TouchBegan",sf::Event::EventType::TouchBegan)             
	     , value("TouchMoved",sf::Event::EventType::TouchMoved)             
	     , value("TouchEnded",sf::Event::EventType::TouchEnded)             
	     , value("SensorChanged",sf::Event::EventType::SensorChanged)          
	     , value("Count",sf::Event::EventType::Count)
	   ]
	   .def_readonly("type", &sf::Event::type)
	   .def_readonly("size", &sf::Event::size)
	   .def_readonly("key", &sf::Event::key)
	   .def_readonly("text", &sf::Event::text)
	   .def_readonly("mouse-move", &sf::Event::mouseMove)
	   .def_readonly("mouse-button", &sf::Event::mouseButton)
	   .def_readonly("mouse-wheel", &sf::Event::mouseWheel)
	   .def_readonly("joystick-move", &sf::Event::joystickMove)
	   .def_readonly("joystick-button", &sf::Event::joystickButton)
	   .def_readonly("joystick-connect", &sf::Event::joystickConnect)
	   .def_readonly("touch", &sf::Event::touch)
	   .def_readonly("sensor", &sf::Event::sensor)

	   ,class_<sf::Event::SizeEvent>("event-size-event")
	   .def_readonly("width", &sf::Event::SizeEvent::width)
	   .def_readonly("height", &sf::Event::SizeEvent::height)
	   
	   ,class_<sf::Event::KeyEvent>("event-key-event")
	   .def_readonly("code", &sf::Event::KeyEvent::code)
	   .def_readonly("alt", &sf::Event::KeyEvent::alt)
	   .def_readonly("control", &sf::Event::KeyEvent::control)
	   .def_readonly("shift", &sf::Event::KeyEvent::shift)
	   .def_readonly("system", &sf::Event::KeyEvent::system)
	   
	   ,class_<sf::Event::TextEvent>("event-text-event")
	   .def_readonly("unicode", &sf::Event::TextEvent::unicode)
	   
	   ,class_<sf::Event::MouseMoveEvent>("event-mouse-move-event")
	   .def_readonly("x-mouse-move-event", &sf::Event::MouseMoveEvent::x)
	   .def_readonly("y-mouse-move-event", &sf::Event::MouseMoveEvent::y)
	   
	   ,class_<sf::Event::MouseButtonEvent>("event-mouse-button-event")
	   .def_readonly("button", &sf::Event::MouseButtonEvent::button)
	   .def_readonly("x-mouse-button-event", &sf::Event::MouseButtonEvent::x)
	   .def_readonly("y-mouse-button-event", &sf::Event::MouseButtonEvent::y)
	   
	   ,class_<sf::Event::MouseWheelEvent>("event-mouse-wheel-event")
	   .def_readonly("delta", &sf::Event::MouseWheelEvent::delta)
	   .def_readonly("x-mouse-wheel-event", &sf::Event::MouseWheelEvent::x)
	   .def_readonly("y-mouse-wheel-event", &sf::Event::MouseWheelEvent::y)
	   
	   ,class_<sf::Event::JoystickConnectEvent>("event-joystick-connect-event")
	   .def_readonly("joystick-id", &sf::Event::JoystickConnectEvent::joystickId)
	   
	   ,class_<sf::Event::JoystickMoveEvent>("event-joystick-move-event")
	   .def_readonly("joystick-id", &sf::Event::JoystickMoveEvent::joystickId)
	   .def_readonly("axis", &sf::Event::JoystickMoveEvent::axis)
	   .def_readonly("position", &sf::Event::JoystickMoveEvent::position)
	   
	   ,class_<sf::Event::JoystickButtonEvent>("event-joystick-button-event")
	   .def_readonly("joystick-id", &sf::Event::JoystickButtonEvent::joystickId)
	   .def_readonly("button", &sf::Event::JoystickButtonEvent::button)
	   
	   ,class_<sf::Event::TouchEvent>("event-touch-event")
	   .def_readonly("x-touch-event", &sf::Event::TouchEvent::x)
	   .def_readonly("y-touch-event", &sf::Event::TouchEvent::y)
	   
	   ,class_<sf::Event::SensorEvent>("event-sensor-event")
	   .def_readonly("x-sensor-event", &sf::Event::SensorEvent::x)
	   .def_readonly("y-sensor-event", &sf::Event::SensorEvent::y)
	   .def_readonly("z-sensor-event", &sf::Event::SensorEvent::z)
	   
	   
	   
	   //FIXME: All the other event types.
	 ];
    }
}

//example for enum exposing:

//  . enum_<clang::TemplateArgument::ArgKind>(asttooling::_sym_STARclangTemplateArgumentArgKindSTAR)[
// value("Type",clang::TemplateArgument::ArgKind::Type)
// , value("Null",clang::TemplateArgument::ArgKind::Null)
// , value("Declaration",clang::TemplateArgument::ArgKind::Declaration)
// , value("NullPtr",clang::TemplateArgument::ArgKind::NullPtr)
// , value("Integral",clang::TemplateArgument::ArgKind::Integral)
// , value("Template",clang::TemplateArgument::ArgKind::Template)
// , value("TemplateExpansion",clang::TemplateArgument::ArgKind::TemplateExpansion)
// , value("Expression",clang::TemplateArgument::ArgKind::Expression)
// , value("Pack",clang::TemplateArgument::ArgKind::Pack) 
