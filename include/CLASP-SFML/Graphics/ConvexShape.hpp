#ifndef CLASP_SFML_CONVEXSHAPE_HPP
#define CLASP_SFML_CONVEXSHAPE_HPP

#include <SFML/Graphics/ConvexShape.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::ConvexShape, sf::Shape> registerConvexShape()
{
  return
    class_<sf::ConvexShape, sf::Shape>("convex-shape", no_default_constructor)
    .def_constructor("make-convex-shape", constructor<unsigned int>())

    .def("set-point-count", &sf::ConvexShape::setPointCount,
	 policies<>(), "", "",
	 R"**(\brief Set the number of points of the polygon

		\a count must be greater than 2 to define a valid shape.

		\param count New number of points of the polygon

		\see getPointCount)**")

    .def("get-point-count", &sf::ConvexShape::getPointCount,
	 policies<>(), "", "",
	 R"**(\brief Get the number of points of the polygon

		\return Number of points of the polygon

		\see setPointCount)**")

    .def("set-point", &sf::ConvexShape::setPoint,
	 policies<>(), "", "",
	 R"**(\brief Set the position of a point

		Don't forget that the polygon must remain convex, and
		the points need to stay ordered!
		setPointCount must be called first in order to set the total
		number of points. The result is undefined if \a index is out
		of the valid range.

		\param index Index of the point to change, in range [0 .. getPointCount() - 1]
		\param point New position of the point

		\see getPoint)**")

    .def("get-point", &sf::ConvexShape::getPoint,
	 policies<>(), "", "",
	 R"**(\brief Get the position of a point

		The returned point is in local coordinates, that is,
		the shape's transforms (position, rotation, scale) are
		not taken into account.
		The result is undefined if \a index is out of the valid range.

		\param index Index of the point to get, in range [0 .. getPointCount() - 1]

		\return Position of the index-th point of the polygon

		\see setPoint)**");
}

#endif //CLASP_SFML_CONVEXSHAPE_HPP
