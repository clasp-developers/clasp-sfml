#ifndef CLASP_SFML_SPRITE_HPP
#define CLASP_SFML_SPRITE_HPP

#include <SFML/Graphics/Sprite.hpp>

#include <clasp/clbind/clbind.h>

// using namespace clbind;

// inline class_<sf::Sprite, bases<sf::Drawable,sf::Transformable>> registerSprite()
// {
//   //FIXME:
//   return
//     class_<sf::Sprite, bases<sf::Drawable,sf::Transformable>> ("sprite")
//     //. def_constructor("make-sprite", constructor<>())
//     . def_constructor("make-sprite", constructor<const sf::Texture &>())
//     //. def_constructor("make-sprite", constructor<const sf::Texture &, const sf::IntRect &>())
//     ;
// }

using namespace clbind;

inline class_<sf::Sprite, bases<sf::Drawable,sf::Transformable>> registerSprite()
{
  return
    class_<sf::Sprite, bases<sf::Drawable,sf::Transformable>>("sprite")

    .def_constructor("make-sprite", constructor<>(),
		     policies<>(), "", "",
		     R"**(\brief Default constructor

	 Creates an empty sprite with no source texture.)**")

    .def_constructor("make-sprite-from-texture", constructor<const sf::Texture&>(),
		     policies<>(), "", "",
		     R"**(\brief Construct the sprite from a source texture

	 \param texture Source texture

	 \see setTexture)**")

    .def_constructor("make-sprite-from-texture-rect", constructor<const sf::Texture&, const sf::IntRect&>(),
	 policies<>(), "", "",
	 R"**(\brief Construct the sprite from a sub-rectangle of a source texture

	 \param texture   Source texture
	 \param rectangle Sub-rectangle of the texture to assign to the sprite

	 \see setTexture, setTextureRect)**")

    .def("set-texture", &sf::Sprite::setTexture,
	 policies<>(), "", "",
	 R"**(\brief Change the source texture of the sprite

       The \a texture argument refers to a texture that must
       exist as long as the sprite uses it. Indeed, the sprite
       doesn't store its own copy of the texture, but rather keeps
       a pointer to the one that you passed to this function.
       If the source texture is destroyed and the sprite tries to
       use it, the behavior is undefined.
       If \a resetRect is true, the TextureRect property of
       the sprite is automatically adjusted to the size of the new
       texture. If it is false, the texture rect is left unchanged.

       \param texture   New texture
       \param resetRect Should the texture rect be reset to the size of the new texture?

       \see getTexture, setTextureRect)**")

    .def("set-texture-rect", &sf::Sprite::setTextureRect,
	 policies<>(), "", "",
	 R"**(\brief Set the sub-rectangle of the texture that the sprite will display

	  The texture rect is useful when you don't want to display
	  the whole texture, but rather a part of it.
	  By default, the texture rect covers the entire texture.

	  \param rectangle Rectangle defining the region of the texture to display

	  \see getTextureRect, setTexture)**")

    .def("set-color", &sf::Sprite::setColor,
	 policies<>(), "", "",
	 R"**(\brief Set the global color of the sprite

	  This color is modulated (multiplied) with the sprite's
	  texture. It can be used to colorize the sprite, or change
	  its global opacity.
	  By default, the sprite's color is opaque white.

	  \param color New color of the sprite

	  \see getColor)**")

    .def("get-texture", &sf::Sprite::getTexture,
	 policies<>(), "", "",
	 R"**(\brief Get the source texture of the sprite

	  If the sprite has no source texture, a NULL pointer is returned.
	  The returned pointer is const, which means that you can't
	  modify the texture when you retrieve it with this function.

	  \return Pointer to the sprite's texture

	  \see setTexture)**")

    .def("get-texture-rect", &sf::Sprite::getTextureRect,
	 policies<>(), "", "",
	 R"**(\brief Get the sub-rectangle of the texture displayed by the sprite

	  \return Texture rectangle of the sprite

	  \see setTextureRect)**")

    .def("get-color", &sf::Sprite::getColor,
	 policies<>(), "", "",
	 R"**(\brief Get the global color of the sprite

	  \return Global color of the sprite

	  \see setColor)**")

    .def("get-local-bounds", &sf::Sprite::getLocalBounds,
	 policies<>(), "", "",
	 R"**(\brief Get the local bounding rectangle of the entity

     The returned rectangle is in local coordinates, which means
     that it ignores the transformations (translation, rotation,
     scale, ...) that are applied to the entity.
     In other words, this function returns the bounds of the
     entity in the entity's coordinate system.

     \return Local bounding rectangle of the entity)**")

    .def("get-global-bounds", &sf::Sprite::getGlobalBounds,
	 policies<>(), "", "",
	 R"**(\brief Get the global bounding rectangle of the entity

     The returned rectangle is in global coordinates, which means
     that it takes into account the transformations (translation,
     rotation, scale, ...) that are applied to the entity.
     In other words, this function returns the bounds of the
     sprite in the global 2D world's coordinate system.

     \return Global bounding rectangle of the entity)**");
    
}


#endif //CLASP_SFML_SPRITE_HPP
