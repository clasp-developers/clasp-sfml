#ifndef CLASP_SFML_RECTANGLESHAPE_HPP
#define CLASP_SFML_RECTANGLESHAPE_HPP

#include <SFML/Graphics/RectangleShape.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::RectangleShape, sf::Shape> registerRectangleShape()
{
  return
    class_<sf::RectangleShape, sf::Shape>("rectangle-shape", no_default_constructor)
    .def_constructor("make-rectangle-shape", constructor<const sf::Vector2f &>())

    .def("set-size/rectangle-shape", &sf::RectangleShape::setSize,
	 policies<>(), "", "",
	 R"**(\brief Set the size of the rectangle

		\param size New size of the rectangle

		\see getSize)**")

    .def("get-size/rectangle-shape", &sf::RectangleShape::getSize,
	 policies<>(), "", "",
	 R"**(\brief Get the size of the rectangle

		\return Size of the rectangle

		\see setSize)**");
}

#endif //CLASP_SFML_RECTANGLESHAPE_HPP
