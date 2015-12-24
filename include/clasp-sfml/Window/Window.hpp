#ifndef CLASP_SFML_WINDOW_HPP
#define CLASP_SFML_WINDOW_HPP

#include <SFML/Window/Window.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::Window> registerWindow()
{
  return

    class_<sf::Window>("window", no_default_constructor)

    .def_constructor("make-window", constructor<>())
	   
    .def_constructor("make-window-vsuc", constructor<sf::VideoMode, sf::String, sf::Uint32, const sf::ContextSettings &>())

    .def_constructor("make-window-wc", constructor<sf::WindowHandle, const sf::ContextSettings &>())

    .def("create-vsuc", (void (sf::Window::*)(sf::VideoMode, const sf::String &, sf::Uint32, const sf::ContextSettings &))&sf::Window::create,
	 policies<>(), "", "",
	 R"**(Create (or recreate) the window
* Description
If the window was already created, it closes it first.
If \a style contains Style::Fullscreen, then \a mode
must be a valid video mode.

The fourth parameter is an optional structure specifying
advanced OpenGL context settings such as antialiasing,
depth-buffer bits, etc.
* Arguments
- MODE :: Video mode to use (defines the width, height and depth of the rendering area of the window)
- TITLE :: Title of the window
- STYLE ::%Window style, a bitwise OR combination of sf::Style enumerators
- SETTINGS :: settings for the underlying OpenGL context)**")

    .def("create-wc", (void (sf::Window::*)(sf::WindowHandle, const sf::ContextSettings &))&sf::Window::create,
	 policies<>(), "", "",
	 R"**(Create (or recreate) the window from an existing control
* Description
Use this function if you want to create an OpenGL
rendering area into an already existing control.
If the window was already created, it closes it first.

The second parameter is an optional structure specifying
advanced OpenGL context settings such as antialiasing,
depth-buffer bits, etc.
* Arguments
- HANDLE :: Platform-specific handle of the control (\a HWND on
Windows, \a %Window on Linux/FreeBSD, \a NSWindow on OS X)
- SETTINGS :: settings for the underlying OpenGL context)**")

    .def("close", &sf::Window::close,
	 policies<>(), "", "",
	 R"**(Close the window and destroy all the attached resources
* Description
After calling this function, the sf::Window instance remains
valid and you can call create() to recreate the window.
All other functions such as pollEvent() or display() will
still work (i.e. you don't have to test isOpen() every time),
and will have no effect on closed windows.)**")

    .def("is-open", &sf::Window::isOpen,
	 policies<>(), "", "",
	 R"**(Tell whether or not the window is open
* Description
This function returns whether or not the window exists.
Note that a hidden window (setVisible(false)) is open
(therefore this function would return true).
* Returns
True if the window is open, false if it has been closed)**")

    .def("get-settings", &sf::Window::getSettings,
	 policies<>(), "", "",
	 R"**(Get the settings of the OpenGL context of the window
* Description
Note that these settings may be different from what was
passed to the constructor or the create() function,
if one or more settings were not supported. In this case,
SFML chose the closest match.
* Returns
Structure containing the OpenGL context settings)**")

    .def("poll-event", &sf::Window::pollEvent,
	 policies<>(), "", "",
	 R"**(Pop the event on top of the event queue, if any, and return it
* Description
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
* Arguments
- EVENT :: to be returned
* Returns
True if an event was returned, or false if the event queue was empty
* See
[[wait-event]])**")

    .def("wait-event", &sf::Window::waitEvent,
	 policies<>(), "", "",
	 R"**(Wait for an event and return it
* Description
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
* Arguments
- EVENT :: to be returned
* Returns
False if any error occurred
* See
[[poll-Event]])**")

    .def("get-position", &sf::Window::getPosition,
	 policies<>(), "", "",
	 R"**(Get the position of the window
* Arguments
Position of the window, in pixels
* See
[[setPosition]])**")

    .def("set-position", &sf::Window::setPosition,
	 policies<>(), "", "",
	 R"**(Change the position of the window on screen
* Description
This function only works for top-level windows
(i.e. it will be ignored for windows created from
the handle of a child window/control).
* Arguments
- POSITION :: position, in pixels
* See
[[get-position]])**")

    .def("get-size", &sf::Window::getSize,
	 policies<>(), "", "",
	 R"**(Get the size of the rendering region of the window
* Description
The size doesn't include the titlebar and borders
of the window.
* Returns
Size in pixels
* See
[[set-size]])**")

    .def("set-size", &sf::Window::setSize,
	 policies<>(), "", "",
	 R"**(\brief Change the size of the rendering region of the window

		\param size New size, in pixels

		\see getSize)**")

    .def("set-title", &sf::Window::setTitle,
	 policies<>(), "", "",
	 R"**(Change the title of the window
* Arguments
- TITLE :: title
* See
[[set-icon]])**")

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
	 R"**(Show or hide the window
* Description
The window is shown by default.
* Arguments
- VISIBLE :: to show the window, false to hide it)**")

    .def("set-vertical-sync-enabled", &sf::Window::setVerticalSyncEnabled,
	 policies<>(), "", "",
	 R"**(Enable or disable vertical synchronization
* Description
Activating vertical synchronization will limit the number
of frames displayed to the refresh rate of the monitor.
This can avoid some visual artifacts, and limit the framerate
to a good value (but not constant across different computers).

Vertical synchronization is disabled by default.
* Arguments
- ENABLED :: to enable v-sync, false to deactivate it)**")

    .def("set-mouse-cursor-visible", &sf::Window::setMouseCursorVisible,
	 policies<>(), "", "",
	 R"**(Show or hide the mouse cursor
* Description
The mouse cursor is visible by default.
* Arguments
- VISIBLE :: to show the mouse cursor, false to hide it)**")

    .def("set-key-repeat-enabled", &sf::Window::setKeyRepeatEnabled,
	 policies<>(), "", "",
	 R"**(Enable or disable automatic key-repeat
* Description
If key repeat is enabled, you will receive repeated
KeyPressed events while keeping a key pressed. If it is disabled,
you will only get a single event when the key is pressed.

Key repeat is enabled by default.
* Arguments
- ENABLED :: to enable, false to disable)**")

    .def("set-framerate-limit", &sf::Window::setFramerateLimit,
	 policies<>(), "", "",
	 R"**(Limit the framerate to a maximum fixed frequency
* Description
If a limit is set, the window will use a small delay after
each call to display() to ensure that the current frame
lasted long enough to match the framerate limit.
SFML will try to match the given limit as much as it can,
but since it internally uses sf::sleep, whose precision
depends on the underlying OS, the results may be a little
unprecise as well (for example, you can get 65 FPS when
requesting 60).
* Arguments
- LIMIT :: limit, in frames per seconds (use 0 to disable limit))**")

    .def("set-joystick-threshold", &sf::Window::setJoystickThreshold,
	 policies<>(), "", "",
	 R"**(Change the joystick threshold
* Description
The joystick threshold is the value below which
no JoystickMoved event will be generated.

The threshold value is 0.1 by default.
* Arguments
- THRESHOLD :: threshold, in the range [0, 100])**")

    .def("set-active", &sf::Window::setActive,
	 policies<>(), "", "",
	 R"**(Activate or deactivate the window as the current target
for OpenGL rendering
* Description
A window is active only on the current thread, if you want to
make it active on another thread you have to deactivate it
on the previous thread first if it was active.
Only one window can be active on a thread at a time, thus
the window previously active (if any) automatically gets deactivated.
This is not to be confused with requestFocus().
* Arguments
- ACTIVE :: to activate, false to deactivate
* Returns
True if operation was successful, false otherwise)**")

    .def("request-focus", &sf::Window::requestFocus,
	 policies<>(), "", "",
	 R"**(Request the current window to be made the active
foreground window
* Description
At any given time, only one window may have the input focus
to receive input events such as keystrokes or mouse events.
If a window requests focus, it only hints to the operating
system, that it would like to be focused. The operating system
is free to deny the request.
This is not to be confused with setActive().
* See
[[has-focus]])**")

    .def("has-focus", &sf::Window::hasFocus,
	 policies<>(), "", "",
	 R"**(Check whether the window has the input focus
* Description
At any given time, only one window may have the input focus
to receive input events such as keystrokes or most mouse
events.
* Returns
True if window has focus, false otherwise
* See
[[request-focus]])**")

    .def("display", &sf::Window::display,
	 policies<>(), "", "",
	 R"**(Display on screen what has been rendered to the window so far
* Description
This function is typically called after all OpenGL rendering
has been done for the current frame, in order to show
it on screen.)**")

    .def("get-system-handle", &sf::Window::getSystemHandle,
	 policies<>(), "", "",
	 R"**(Get the OS-specific handle of the window
* Description
The type of the returned handle is sf::WindowHandle,
which is a typedef to the handle type defined by the OS.
You shouldn't need to use this function, unless you have
very specific stuff to implement that SFML doesn't support,
or implement a temporary workaround until a bug is fixed.
The type is \a HWND on Windows, \a %Window on Linux/FreeBSD
and \a NSWindow on OS X.
* Returns
System handle of the window)**")
    ;
  //FIXME: WindowStyle.hpp enum - how to deal with or-able enums?

}

#endif //CLASP_SFML_WINDOW_HPP
