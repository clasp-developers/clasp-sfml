#ifndef CLASP_SFML_SPRITE_HPP
#define CLASP_SFML_SPRITE_HPP

#include <SFML/Graphics/Sprite.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::Sprite, bases<sf::Drawable,sf::Transformable>> registerSprite()
{
  //FIXME:
  return
    class_<sf::Sprite, bases<sf::Drawable,sf::Transformable>> ("sprite")
    //. def_constructor("make-sprite", constructor<>())
    . def_constructor("make-sprite", constructor<const sf::Texture &>())
    //. def_constructor("make-sprite", constructor<const sf::Texture &, const sf::IntRect &>())
    ;
}

#endif //CLASP_SFML_SPRITE_HPP
