#ifndef CLASP_SFML_MOUSE_HPP
#define CLASP_SFML_MOUSE_HPP


#include <SFML/Window/Mouse.hpp>

#include <clasp/clbind/clbind.h>

namespace translate
{

  template <>
  struct to_object<sf::Mouse::Button>
  {
    static core::T_sp convert(sf::Mouse::Button v)
    {
      core::Symbol_sp converterSym = 
        core::lisp_intern("*MOUSE-BUTTON-ENUM-MAPPER*", "SFML");
      core::SymbolToEnumConverter_sp converter = 
        converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
      return converter->symbolForEnum<sf::Mouse::Button>(v);
    }
  };

  template <>
  struct from_object<sf::Mouse::Button>
  {
    typedef sf::Mouse::Button DeclareType;
    DeclareType _v;
    from_object(core::T_sp object)
    {
      if (core::Symbol_sp sym = object.asOrNull<core::Symbol_O>()) 
      {
	if (sym.notnilp()) 
        {
	  core::Symbol_sp converterSym = core::lisp_intern("*MOUSE-BUTTON-ENUM-MAPPER*", "SFML");
	  core::SymbolToEnumConverter_sp converter = 
            converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
	  this->_v = converter->enumForSymbol<sf::Mouse::Button>(sym);
	  return;
	}
      }
      SIMPLE_ERROR(BF("Cannot convert object %s to sf::Mouse::Button") % _rep_(object) );
    }
  };

  

};

#endif //CLASP_SFML_MOUSE_HPP
