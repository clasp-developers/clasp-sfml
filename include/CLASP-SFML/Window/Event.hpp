#ifndef CLASP_BINDING_EVENT_HPP
#define CLASP_BINDING_EVENT_HPP

#include <SFML/Window/Event.hpp>

#include <clasp/clbind/clbind.h>

namespace translate
{
  
  template <>
  struct to_object<sf::Event::EventType>
  {
    static core::T_sp convert(sf::Event::EventType v)
    {
      core::Symbol_sp converterSym = core::lisp_intern("*EVENT-EVENTTYPE-ENUM-MAPPER*", "SFML");
      core::SymbolToEnumConverter_sp converter = converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
      return converter->symbolForEnum<sf::Event::EventType>(v);
    }
  };

 
  template <>
  struct to_object<sf::Event::EventType, adopt_pointer>
  {
    static core::T_sp convert(sf::Event::EventType v)
    {
      core::Symbol_sp converterSym = core::lisp_intern("*EVENT-EVENTTYPE-ENUM-MAPPER*", "SFML");
      core::SymbolToEnumConverter_sp converter = converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
      return converter->symbolForEnum<sf::Event::EventType>(v);
    }
  };
  
  template <>
  struct from_object<sf::Event::EventType>
  {
    typedef sf::Event::EventType DeclareType;
    DeclareType _v;
    from_object(core::T_sp object)
    {
      if ( core::Symbol_sp sym = object.asOrNull<core::Symbol_O>() ) {
	if ( sym.notnilp() ) {
	  core::Symbol_sp converterSym = core::lisp_intern("*EVENT-EVENTTYPE-ENUM-MAPPER*", "SFML");
	  core::SymbolToEnumConverter_sp converter = converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
	  this->_v = converter->enumForSymbol<sf::Event::EventType>(sym);
	  return;
	}
      }
      SIMPLE_ERROR(BF("Cannot convert object %s to sf::Event::EventType") % _rep_(object) );
    }
  };

}; //end namespace translate

#endif //CLASP_BINDING_EVENT_HPP
