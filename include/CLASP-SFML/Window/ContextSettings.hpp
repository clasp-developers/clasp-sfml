#ifndef CLASP_SFML_CONTEXTSETTINGS_HPP
#define CLASP_SFML_CONTEXTSETTINGS_HPP

#include <SFML/Window/ContextSettings.hpp>

#include <clasp/clbind/clbind.h>

namespace translate
{
 
  template <>
  struct to_object<sf::ContextSettings::Attribute>
  {
    static core::T_sp convert(sf::ContextSettings::Attribute v)
    {
      core::Symbol_sp converterSym = core::lisp_intern("*CONTEXT-SETTINGS-ATTRIBUTE-ENUM-MAPPER*", "SFML");
      core::SymbolToEnumConverter_sp converter = converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
      return converter->symbolForEnum<sf::ContextSettings::Attribute>(v);
    }
  };

 
  template <>
  struct to_object<sf::ContextSettings::Attribute, adopt_pointer>
  {
    static core::T_sp convert(sf::ContextSettings::Attribute v)
    {
      core::Symbol_sp converterSym = core::lisp_intern("*CONTEXT-SETTINGS-ATTRIBUTE-ENUM-MAPPER*", "SFML");
      core::SymbolToEnumConverter_sp converter = converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
      return converter->symbolForEnum<sf::ContextSettings::Attribute>(v);
    }
  };
  
  template <>
  struct from_object<sf::ContextSettings::Attribute>
  {
    typedef sf::ContextSettings::Attribute DeclareType;
    DeclareType _v;
    from_object(core::T_sp object)
    {
      if ( core::Symbol_sp sym = object.asOrNull<core::Symbol_O>() ) {
	if ( sym.notnilp() ) {
	  core::Symbol_sp converterSym = core::lisp_intern("*CONTEXT-SETTINGS-ATTRIBUTE-ENUM-MAPPER*", "SFML");
	  core::SymbolToEnumConverter_sp converter = converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
	  this->_v = converter->enumForSymbol<sf::ContextSettings::Attribute>(sym);
	  return;
	}
      }
      SIMPLE_ERROR(BF("Cannot convert object %s to sf::ContextSettings::Attribute") % _rep_(object) );
    }
  };

  
}; //end namespace translate

using namespace clbind;

inline class_<sf::ContextSettings> registerContextSettings()
{
  return
    class_<sf::ContextSettings>("context-settings")
    .def_constructor("context-settings", constructor<unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int>(),
	 policies<>(), "", "",
	 R"**(\brief Default constructor

	 \param depth        Depth buffer bits
	 \param stencil      Stencil buffer bits
	 \param antialiasing Antialiasing level
	 \param major        Major number of the context version
	 \param minor        Minor number of the context version
	 \param attributes   Attribute flags of the context)**")
    .enum_<sf::ContextSettings::Attribute>(core::lisp_intern("*CONTEXT-SETTINGS-ATTRIBUTE-ENUM-MAPPER*", "SFML"))
    [ value("Default", sf::ContextSettings::Attribute::Default),
      value("Core", sf::ContextSettings::Attribute::Core),
      value("Debug", sf::ContextSettings::Attribute::Debug)]
    .def_readonly("depth-bits", &sf::ContextSettings::depthBits)
    .def_readonly("stencil-bits", &sf::ContextSettings::stencilBits)
    .def_readonly("antialiasing-level", &sf::ContextSettings::antialiasingLevel)
    .def_readonly("major-version", &sf::ContextSettings::majorVersion)
    .def_readonly("minor-version", &sf::ContextSettings::minorVersion)
    .def_readonly("attribute-flags", &sf::ContextSettings::attributeFlags);

}

#endif //CLASP_SFML_CONTEXTSETTINGS_HPP
