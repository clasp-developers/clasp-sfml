#ifndef CLASP_SFML_CIRCLESHAPE_HPP
#define CLASP_SFML_CIRCLESHAPE_HPP

#include <SFML/Graphics/CircleShape.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::CircleShape, sf::Shape> registerCircleShape()
{
  return
    class_<sf::CircleShape, sf::Shape>("circle-shape", no_default_constructor)
    .def_constructor("make-circle-shape", constructor<float, unsigned int>())

    .def("set-radius", &sf::CircleShape::setRadius,
	 policies<>(), "", "",
	 R"**(\brief Set the radius of the circle

		\param radius New radius of the circle

		\see getRadius)**")

    .def("get-radius", &sf::CircleShape::getRadius,
	 policies<>(), "", "",
	 R"**(\brief Get the radius of the circle

		\return Radius of the circle

		\see setRadius)**")

    .def("set-point-count", &sf::CircleShape::setPointCount,
	 policies<>(), "", "",
	 R"**(\brief Set the number of points of the circle

		\param count New number of points of the circle

		\see getPointCount)**")

    .def("get-point-count", &sf::CircleShape::getPointCount,
	 policies<>(), "", "",
	 R"**(\brief Get the number of points of the circle

		\return Number of points of the circle

		\see setPointCount)**")

    .def("get-point", &sf::CircleShape::getPoint,
	 policies<>(), "", "",
	 R"**(\brief Get a point of the circle

		The returned point is in local coordinates, that is,
		the shape's transforms (position, rotation, scale) are
		not taken into account.
		The result is undefined if \a index is out of the valid range.

		\param index Index of the point to get, in range [0 .. getPointCount() - 1]

		\return index-th point of the shape)**");

}

#endif //CLASP_SFML_CIRCLESHAPE_HPP
