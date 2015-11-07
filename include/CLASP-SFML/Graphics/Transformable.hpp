#ifndef CLASP_SFML_TRANSFORMABLE_HPP
#define CLASP_SFML_TRANSFORMABLE_HPP

#include <SFML/Graphics/Transformable.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::Transformable> registerTransformable()
{
  return
    class_<sf::Transformable>("transformable", no_default_constructor)
    .def_constructor("make-transformable", constructor<>())

    .def("set-position", (void (sf::Transformable::*)(const sf::Vector2f&))&sf::Transformable::setPosition,
	 policies<>(), "", "",
	 R"**(\brief set the position of the object

		This function completely overwrites the previous position.
		See the move function to apply an offset based on the previous position instead.
		The default position of a transformable object is (0, 0).

		\param position New position

		\see move, getPosition)**")

    .def("set-rotation", &sf::Transformable::setRotation,
	 policies<>(), "", "",
	 R"**(\brief set the orientation of the object

		This function completely overwrites the previous rotation.
		See the rotate function to add an angle based on the previous rotation instead.
		The default rotation of a transformable object is 0.

		\param angle New rotation, in degrees

		\see rotate, getRotation)**")

    .def("set-scale", (void (sf::Transformable::*)(const sf::Vector2f&))&sf::Transformable::setScale,
	 policies<>(), "", "",
	 R"**(\brief set the scale factors of the object

		This function completely overwrites the previous scale.
		See the scale function to add a factor based on the previous scale instead.
		The default scale of a transformable object is (1, 1).

		\param factors New scale factors

		\see scale, getScale)**")

    .def("set-origin", (void (sf::Transformable::*)(const sf::Vector2f&))&sf::Transformable::setOrigin,
	 policies<>(), "", "",
	 R"**(\brief set the local origin of the object

		The origin of an object defines the center point for
		all transformations (position, scale, rotation).
		The coordinates of this point must be relative to the
		top-left corner of the object, and ignore all
		transformations (position, scale, rotation).
		The default origin of a transformable object is (0, 0).

		\param origin New origin

		\see getOrigin)**")

    .def("get-position", &sf::Transformable::getPosition,
	 policies<>(), "", "",
	 R"**(\brief get the position of the object

		\return Current position

		\see setPosition)**")

    .def("get-rotation", &sf::Transformable::getRotation,
	 policies<>(), "", "",
	 R"**(\brief get the orientation of the object

		The rotation is always in the range [0, 360].

		\return Current rotation, in degrees

		\see setRotation)**")

    .def("get-scale", &sf::Transformable::getScale,
	 policies<>(), "", "",
	 R"**(\brief get the current scale of the object

		\return Current scale factors

		\see setScale)**")

    .def("get-origin", &sf::Transformable::getOrigin,
	 policies<>(), "", "",
	 R"**(\brief get the local origin of the object

		\return Current origin

		\see setOrigin)**")

    .def("move", (void (sf::Transformable::*)(const sf::Vector2f&))&sf::Transformable::move,
	 policies<>(), "", "",
	 R"**(\brief Move the object by a given offset

		This function adds to the current position of the object,
		unlike setPosition which overwrites it.
		Thus, it is equivalent to the following code:
		\code
		object.setPosition(object.getPosition() + offset);
		\endcode

		\param offset Offset

		\see setPosition)**")

    .def("rotate", &sf::Transformable::rotate,
	 policies<>(), "", "",
	 R"**(\brief Rotate the object

		This function adds to the current rotation of the object,
		unlike setRotation which overwrites it.
		Thus, it is equivalent to the following code:
		\code
		object.setRotation(object.getRotation() + angle);
		\endcode

		\param angle Angle of rotation, in degrees)**")

    .def("scale", (void (sf::Transformable::*)(const sf::Vector2f&))&sf::Transformable::scale,
	 policies<>(), "", "",
	 R"**(\brief Scale the object

		This function multiplies the current scale of the object,
		unlike setScale which overwrites it.
		Thus, it is equivalent to the following code:
		\code
		sf::Vector2f scale = object.getScale();
		object.setScale(scale.x * factor.x, scale.y * factor.y);
		\endcode

		\param factor Scale factors

		\see setScale)**")

    .def("get-transform", &sf::Transformable::getTransform,
	 policies<>(), "", "",
	 R"**(\brief get the combined transform of the object

		\return Transform combining the position/rotation/scale/origin of the object

		\see getInverseTransform)**")

    .def("get-inverse-transform", &sf::Transformable::getInverseTransform,
	 policies<>(), "", "",
	 R"**(\brief get the inverse of the combined transform of the object

		\return Inverse of the combined transformations applied to the object

		\see getTransform)**");

}

#endif //CLASP_SFML_TRANSFORMABLE_HPP
