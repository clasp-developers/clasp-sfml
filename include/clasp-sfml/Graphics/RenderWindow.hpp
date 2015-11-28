#ifndef CLASP_SFML_RENDERWINDOW_HPP
#define CLASP_SFML_RENDERWINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::RenderWindow, bases<sf::Window,sf::RenderTarget>> registerRenderWindow()
{
  //FIXME: Redo this with comments.
  return
    class_<sf::RenderWindow,bases<sf::Window,sf::RenderTarget>>("render-window", no_default_constructor)
    .def_constructor("make-render-window", constructor<>(),
		     policies<>(), "", "",
		     R"**(\brief Default constructor

	 This constructor doesn't actually create the window,
	 use the other constructors or call create() to do so.)**")

    .def_constructor("make-render-window-video-mode", constructor<sf::VideoMode, const sf::String& , sf::Uint32, const sf::ContextSettings&>(),
		     policies<>(), "(mode title &optional (style 7) (settings (sf:make-context-settings)))", "",
		     R"**(\brief Construct a new window

	 This constructor creates the window with the size and pixel
	 depth defined in \a mode. An optional style can be passed to
	 customize the look and behavior of the window (borders,
	 title bar, resizable, closable, ...).

	 The fourth parameter is an optional structure specifying
	 advanced OpenGL context settings such as antialiasing,
	 depth-buffer bits, etc. You shouldn't care about these
	 parameters for a regular usage of the graphics module.

	 \param mode     Video mode to use (defines the width, height and depth of the rendering area of the window)
	 \param title    Title of the window
	 \param style    %Window style, a bitwise OR combination of sf::Style enumerators
	 \param settings Additional settings for the underlying OpenGL context)**")

    .def_constructor("make-render-window-window-handle", constructor<sf::WindowHandle, const sf::ContextSettings&>(),
		     policies<>(), "", "",
		     R"**(\brief Construct the window from an existing control

     Use this constructor if you want to create an SFML
     rendering area into an already existing control.

     The second parameter is an optional structure specifying
     advanced OpenGL context settings such as antialiasing,
     depth-buffer bits, etc. You shouldn't care about these
     parameters for a regular usage of the graphics module.

     \param handle   Platform-specific handle of the control (\a HWND on
     Windows, \a %Window on Linux/FreeBSD, \a NSWindow on OS X)
     \param settings Additional settings for the underlying OpenGL context)**")

    .def("get-size/render-window", &sf::RenderWindow::getSize,
	 policies<>(), "", "",
	 R"**(\brief Get the size of the rendering region of the window

	 The size doesn't include the titlebar and borders
	 of the window.

	 \return Size in pixels)**")

    .def("capture", &sf::RenderWindow::capture,
	 policies<>(), "", "",
	 R"**(\brief Copy the current contents of the window to an image

	 This is a slow operation, whose main purpose is to make
	 screenshots of the application. If you want to update an
	 image with the contents of the window and then use it for
	 drawing, you should rather use a sf::Texture and its
	 update(Window&) function.
	 You can also draw things directly to a texture with the
	 sf::RenderTexture class.

	 \return Image containing the captured contents)**");

    
}

#endif //CLASP_SFML_RENDERWINDOW_HPP
