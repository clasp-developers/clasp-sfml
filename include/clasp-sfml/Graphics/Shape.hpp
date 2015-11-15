#ifndef CLASP_SFML_SHAPE_HPP
#define CLASP_SFML_SHAPE_HPP

#include <SFML/Graphics/Shape.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::Shape, bases<sf::Drawable, sf::Transformable>> registerShape()
{
  return
    class_<sf::Shape, bases<sf::Drawable, sf::Transformable>>("shape", no_default_constructor)

    .def("set-texture", &sf::Shape::setTexture,
	 policies<>(), "", "",
	 R"**(\brief Change the source texture of the shape

		The \a texture argument refers to a texture that must
		exist as long as the shape uses it. Indeed, the shape
		doesn't store its own copy of the texture, but rather keeps
		a pointer to the one that you passed to this function.
		If the source texture is destroyed and the shape tries to
		use it, the behavior is undefined.
		\a texture can be NULL to disable texturing.
		If \a resetRect is true, the TextureRect property of
		the shape is automatically adjusted to the size of the new
		texture. If it is false, the texture rect is left unchanged.

		\param texture   New texture
		\param resetRect Should the texture rect be reset to the size of the new texture?

		\see getTexture, setTextureRect)**")

    .def("set-texture-rect", &sf::Shape::setTextureRect,
	 policies<>(), "", "",
	 R"**(\brief Set the sub-rectangle of the texture that the shape will display

		The texture rect is useful when you don't want to display
		the whole texture, but rather a part of it.
		By default, the texture rect covers the entire texture.

		\param rect Rectangle defining the region of the texture to display

		\see getTextureRect, setTexture)**")

    .def("set-fill-color", &sf::Shape::setFillColor,
	 policies<>(), "", "",
	 R"**(\brief Set the fill color of the shape

		This color is modulated (multiplied) with the shape's
		texture if any. It can be used to colorize the shape,
		or change its global opacity.
		You can use sf::Color::Transparent to make the inside of
		the shape transparent, and have the outline alone.
		By default, the shape's fill color is opaque white.

		\param color New color of the shape

		\see getFillColor, setOutlineColor)**")

    .def("set-outline-color", &sf::Shape::setOutlineColor,
	 policies<>(), "", "",
	 R"**(\brief Set the outline color of the shape

		By default, the shape's outline color is opaque white.

		\param color New outline color of the shape

		\see getOutlineColor, setFillColor)**")

    .def("set-outline-thickness", &sf::Shape::setOutlineThickness,
	 policies<>(), "", "",
	 R"**(\brief Set the thickness of the shape's outline

		Note that negative values are allowed (so that the outline
		expands towards the center of the shape), and using zero
		disables the outline.
		By default, the outline thickness is 0.

		\param thickness New outline thickness

		\see getOutlineThickness)**")

    .def("shape/get-texture", &sf::Shape::getTexture,
	 policies<>(), "", "",
	 R"**(\brief Get the source texture of the shape

		If the shape has no source texture, a NULL pointer is returned.
		The returned pointer is const, which means that you can't
		modify the texture when you retrieve it with this function.

		\return Pointer to the shape's texture

		\see setTexture)**")

    .def("get-texture-rect", &sf::Shape::getTextureRect,
	 policies<>(), "", "",
	 R"**(\brief Get the sub-rectangle of the texture displayed by the shape

		\return Texture rectangle of the shape

		\see setTextureRect)**")

    .def("get-fill-color", &sf::Shape::getFillColor,
	 policies<>(), "", "",
	 R"**(\brief Get the fill color of the shape

		\return Fill color of the shape

		\see setFillColor)**")

    .def("get-outline-color", &sf::Shape::getOutlineColor,
	 policies<>(), "", "",
	 R"**(\brief Get the outline color of the shape

		\return Outline color of the shape

		\see setOutlineColor)**")

    .def("get-outline-thickness", &sf::Shape::getOutlineThickness,
	 policies<>(), "", "",
	 R"**(\brief Get the outline thickness of the shape

		\return Outline thickness of the shape

		\see setOutlineThickness)**")

    .def("get-point-count", &sf::Shape::getPointCount,
	 policies<>(), "", "",
	 R"**(\brief Get the total number of points of the shape

		\return Number of points of the shape

		\see getPoint)**")

    .def("get-point", &sf::Shape::getPoint,
	 policies<>(), "", "",
	 R"**(\brief Get a point of the shape

		The returned point is in local coordinates, that is,
		the shape's transforms (position, rotation, scale) are
		not taken into account.
		The result is undefined if \a index is out of the valid range.

		\param index Index of the point to get, in range [0 .. getPointCount() - 1]

		\return index-th point of the shape

		\see getPointCount)**")

    .def("get-local-bounds", &sf::Shape::getLocalBounds,
	 policies<>(), "", "",
	 R"**(\brief Get the local bounding rectangle of the entity

		The returned rectangle is in local coordinates, which means
		that it ignores the transformations (translation, rotation,
		scale, ...) that are applied to the entity.
		In other words, this function returns the bounds of the
		entity in the entity's coordinate system.

		\return Local bounding rectangle of the entity)**")

    .def("get-global-bounds", &sf::Shape::getGlobalBounds,
	 policies<>(), "", "",
	 R"**(\brief Get the global bounding rectangle of the entity

		The returned rectangle is in global coordinates, which means
		that it takes in account the transformations (translation,
		rotation, scale, ...) that are applied to the entity.
		In other words, this function returns the bounds of the
		sprite in the global 2D world's coordinate system.

		\return Global bounding rectangle of the entity)**");


}

#endif //CLASP_SFML_SHAPE_HPP
