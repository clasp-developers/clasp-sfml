#ifndef CLASP_SFML_GLYPH_HPP
#define CLASP_SFML_GLYPH_HPP

#include <SFML/Graphics/Glyph.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::Glyph> registerGlyph()
{
  return
    class_<sf::Glyph>("glyph")
    .def_constructor("make-glyph", constructor<>(),
		     policies<>(), "", "",
		     R"**(\brief Default constructor)**")
    .def_readwrite("advance", &sf::Glyph::advance)
    .def_readwrite("bounds", &sf::Glyph::bounds)
    .def_readwrite("texture-rect", &sf::Glyph::textureRect);    
}

#endif //CLASP_SFML_GLYPH_HPP
