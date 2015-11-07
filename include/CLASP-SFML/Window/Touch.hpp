#ifndef CLASP_SFML_TOUCH_HPP
#define CLASP_SFML_TOUCH_HPP

#include <SFML/Window/Touch.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::Touch> registerTouch()
{
  return    
    class_<sf::Touch>("touch", no_default_constructor);
}

inline scope registerTouchIsDown()
{
  return
    def("touch/is-down", (bool (*)(unsigned int))&sf::Touch::isDown,
	policies<>(), "", "",
	R"**(\brief Check if a touch event is currently down

     \param finger Finger index

     \return True if \a finger is currently touching the screen, false otherwise)**");
}

inline scope registerTouchGetPosition()
{
  return
    def("touch/get-position", (sf::Vector2i (*)(unsigned int))&sf::Touch::getPosition,
	policies<>(), "", "",
	R"**(\brief Get the current position of a touch in desktop coordinates

     This function returns the current touch position
     in global (desktop) coordinates.

     \param finger Finger index

     \return Current position of \a finger, or undefined if it's not down)**");
}

inline scope registerTouchGetPositionRelative()
{
  return
    def("touch/get-position-relative", (sf::Vector2i (*)(unsigned int, const sf::Window&))&sf::Touch::getPosition,
	policies<>(), "", "",
	R"**(\brief Get the current position of a touch in window coordinates

     This function returns the current touch position
     relative to the given window.

     \param finger Finger index
     \param relativeTo Reference window

     \return Current position of \a finger, or undefined if it's not down)**");
}



#endif //CLASP_SFML_TOUCH_HPP
