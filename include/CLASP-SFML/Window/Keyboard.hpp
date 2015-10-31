#ifndef CLASP_SFML_KEYBOARD_HPP
#define CLASP_SFML_KEYBOARD_HPP

#include <SFML/Window/Keyboard.hpp>

#include <clasp/clbind/clbind.h>

namespace translate
{

  template <>
  struct to_object<sf::Keyboard::Key>
  {
    static core::T_sp convert(sf::Keyboard::Key v)
    {
      core::Symbol_sp converterSym = 
        core::lisp_intern("*KEYBOARD-KEY-ENUM-MAPPER*", "SFML");
      core::SymbolToEnumConverter_sp converter = 
        converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
      return converter->symbolForEnum<sf::Keyboard::Key>(v);
    }
  };

  
  template <>
  struct to_object<sf::Keyboard::Key, adopt_pointer>
  {
    static core::T_sp convert(sf::Keyboard::Key v)
    {
      core::Symbol_sp converterSym = 
        core::lisp_intern("*KEYBOARD-KEY-ENUM-MAPPER*", "SFML");
      core::SymbolToEnumConverter_sp converter = 
        converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
      return converter->symbolForEnum<sf::Keyboard::Key>(v);
    }
  };

  
  template <>
  struct from_object<sf::Keyboard::Key>
  {
    typedef sf::Keyboard::Key DeclareType;
    DeclareType _v;
    from_object(core::T_sp object)
    {
      if (core::Symbol_sp sym = object.asOrNull<core::Symbol_O>()) 
      {
	if (sym.notnilp()) 
        {
	  core::Symbol_sp converterSym = core::lisp_intern("*KEYBOARD-KEY-ENUM-MAPPER*", "SFML");
	  core::SymbolToEnumConverter_sp converter = 
            converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
	  this->_v = converter->enumForSymbol<sf::Keyboard::Key>(sym);
	  return;
	}
      }
      SIMPLE_ERROR(BF("Cannot convert object %s to sf::Keyboard::Key") % _rep_(object) );
    }
  };

  
  
};

#endif //CLASP_SFML_KEYBOARD_HPP
