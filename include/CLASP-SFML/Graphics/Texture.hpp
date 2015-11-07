#ifndef CLASP_SFML_TEXTURE_HPP
#define CLASP_SFML_TEXTURE_HPP

#include <SFML/Graphics/Texture.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::Texture> registerTexture()
{
  //FIXME:
  return
    class_<sf::Texture>("texture")
    . def_constructor("make-texture", constructor<>())
    //. def_constructor("make-texture", constructor<const sf::Texture &>())
    . def("texture/create", &sf::Texture::create)
    . def("load-from-file", &sf::Texture::loadFromFile, policies<>(), "(self filename &optional (area nil))");
    // . def("load-from-memory", &sf::Texture::loadFromMemory)
    // . def("load-from-stream", &sf::Texture::loadFromStream)
    // . def("load-from-image", &sf::Texture::loadFromImage)
    // . def("get-size", &sf::Texture::getSize)
    // . def("copy-to-image", &sf::Texture::copyToImage)
    //missing definitions here
	   
}

#endif //CLASP_SFML_TEXTURE_HPP
