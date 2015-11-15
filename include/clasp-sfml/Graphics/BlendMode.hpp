#ifndef CLASP_SFML_BLEND_MODE_HPP
#define CLASP_SFML_BLEND_MODE_HPP

#include <SFML/Graphics/BlendMode.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

namespace translate
{

  template <>
  struct to_object<sf::BlendMode::Factor>
  {
    static core::T_sp convert(sf::BlendMode::Factor v)
    {
      core::Symbol_sp converterSym = 
        core::lisp_intern("*BLENDMODE-FACTOR-ENUM-MAPPER*", "SFML");
      core::SymbolToEnumConverter_sp converter = 
        converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
      return converter->symbolForEnum<sf::BlendMode::Factor>(v);
    }
  };

  template <>
  struct from_object<sf::BlendMode::Factor>
  {
    typedef sf::BlendMode::Factor DeclareType;
    DeclareType _v;
    from_object(core::T_sp object)
    {
      if (core::Symbol_sp sym = object.asOrNull<core::Symbol_O>()) 
      {
	if (sym.notnilp()) 
        {
	  core::Symbol_sp converterSym = core::lisp_intern("*BLENDMODE-FACTOR-ENUM-MAPPER*", "SFML");
	  core::SymbolToEnumConverter_sp converter = 
            converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
	  this->_v = converter->enumForSymbol<sf::BlendMode::Factor>(sym);
	  return;
	}
      }
      SIMPLE_ERROR(BF("Cannot convert object %s to sf::BlendMode::Factor") % _rep_(object) );
    }
  };

  template <>
  struct to_object<sf::BlendMode::Equation>
  {
    static core::T_sp convert(sf::BlendMode::Equation v)
    {
      core::Symbol_sp converterSym = 
        core::lisp_intern("SFML","*BLENDMODE-EQUATION-ENUM-MAPPER*");
      core::SymbolToEnumConverter_sp converter = 
        converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
      return converter->symbolForEnum<sf::BlendMode::Equation>(v);
    }
  };

  template <>
  struct from_object<sf::BlendMode::Equation>
  {
    typedef sf::BlendMode::Equation DeclareType;
    DeclareType _v;
    from_object(core::T_sp object)
    {
      if (core::Symbol_sp sym = object.asOrNull<core::Symbol_O>()) 
      {
	if (sym.notnilp()) 
        {
	  core::Symbol_sp converterSym = core::lisp_intern("*BLENDMODE-EQUATION-ENUM-MAPPER*", "SFML");
	  core::SymbolToEnumConverter_sp converter = 
            converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
	  this->_v = converter->enumForSymbol<sf::BlendMode::Equation>(sym);
	  return;
	}
      }
      SIMPLE_ERROR(BF("Cannot convert object %s to sf::BlendMode::Equation") % _rep_(object) );
    }
  };

  
  
};


inline class_<sf::BlendMode> registerBlendMode()
{
  return
    class_<sf::BlendMode>("blend-mode")

    .enum_<sf::BlendMode::Factor>(core::lisp_intern("*BLENDMODE-FACTOR-ENUM-MAPPER*", "SFML"))
    [
     value("blend-mode/factor/zero", sf::BlendMode::Factor::Zero),
     value("blend-mode/factor/one", sf::BlendMode::Factor::One),
     value("blend-mode/factor/src-color", sf::BlendMode::Factor::SrcColor),
     value("blend-mode/factor/one-minus-src-color", sf::BlendMode::Factor::OneMinusSrcColor),
     value("blend-mode/factor/dst-color", sf::BlendMode::Factor::DstColor),
     value("blend-mode/factor/one-minus-dst-color", sf::BlendMode::Factor::OneMinusDstColor),
     value("blend-mode/factor/src-alpha", sf::BlendMode::Factor::SrcAlpha),
     value("blend-mode/factor/one-minus-src-alpha", sf::BlendMode::Factor::OneMinusSrcAlpha),
     value("blend-mode/factor/dst-alpha", sf::BlendMode::Factor::DstAlpha),
     value("blend-mode/factor/one-minus-dst-alpha", sf::BlendMode::Factor::OneMinusDstAlpha)
     ]

    .enum_<sf::BlendMode::Equation>(core::lisp_intern("*BLENDMODE-EQUATION-ENUM-MAPPER*", "SFML"))
    [
     value("blend-mode/equation/add", sf::BlendMode::Equation::Add),
     value("blend-mode/equation/subtract", sf::BlendMode::Equation::Subtract)
     ]

    .def_constructor("make-blend-mode", constructor<sf::BlendMode::Factor, sf::BlendMode::Factor, sf::BlendMode::Equation>());

}


#endif // CLASP_SFML_BLEND_MODE_HPP
