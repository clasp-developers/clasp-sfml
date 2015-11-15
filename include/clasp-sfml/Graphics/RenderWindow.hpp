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
    . def_constructor("make-render-window", constructor<>())
    . def_constructor("make-render-window-vs", constructor<sf::VideoMode, sf::String>())
    . def("get-size",&sf::RenderWindow::getSize)
    . def("capture",&sf::RenderWindow::capture);
}

#endif //CLASP_SFML_RENDERWINDOW_HPP
