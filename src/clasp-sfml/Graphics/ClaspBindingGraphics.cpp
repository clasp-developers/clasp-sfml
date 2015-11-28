#include <clasp-sfml/translators.hpp>

#include <clasp-sfml/System/String.hpp>
#include <clasp-sfml/System/Vector2.hpp>
#include <clasp-sfml/Window/Event.hpp>
#include <clasp-sfml/Window/VideoMode.hpp>

#include <clasp-sfml/Graphics/Color.hpp>
#include <clasp-sfml/Graphics/Rect.hpp>

#include <clasp-sfml/Graphics/BlendMode.hpp>

#include <clasp-sfml/Graphics/CircleShape.hpp>
#include <clasp-sfml/Graphics/ConvexShape.hpp>
#include <clasp-sfml/Graphics/Font.hpp>
#include <clasp-sfml/Graphics/Glyph.hpp>
#include <clasp-sfml/Graphics/Image.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <clasp-sfml/Graphics/RectangleShape.hpp>
#include <clasp-sfml/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include <clasp-sfml/Graphics/RenderWindow.hpp>
#include <clasp-sfml/Graphics/Texture.hpp>
#include <clasp-sfml/Graphics/Drawable.hpp>
#include <clasp-sfml/Graphics/Transformable.hpp>
#include <clasp-sfml/Graphics/Sprite.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <clasp-sfml/Graphics/Shape.hpp>
#include <clasp-sfml/Graphics/Transformable.hpp>


#include <clasp/core/foundation.h>
#include <clasp/clbind/clbind.h>
#include <clasp/core/lispVector.h>
#include <clasp/core/vectorObjects.h>
#include <clasp/core/cons.h>
#include <clasp/core/translators.h>
#include <clasp/core/str.h>

#define EXPORT __attribute__((visibility("default")))


namespace translate {
    // template <> struct to_object<const vector<double>&>
    // {
    //     static core::T_sp convert(const vector<double>& v)
    //     {
    //         core::VectorObjects_sp vec;
    //         vec->adjust(_Nil<core::T_O>(),_Nil<core::Cons_O>(),v.size());
    //         printf("%s:%d fill the vec here\n", __FILE__, __LINE__ );
    //         return vec;
    //     }
    // };

  // template <> struct from_object<sf::VideoMode>
  // {
  //   typedef sf::VideoMode DeclareType;
  //   DeclareType _v;
  //   from_object(core::T_sp obj)
  //   {
  //     if ( obj.nilp() ) {
  // 	this->_v.width = 800;
  // 	this->_v.height = 600;
  // 	this->_v.bitsPerPixel = 32;
  //     } else if ( core::Cons_sp list = obj.asOrNull<core::Cons_O>() ) {
  // 	// Translate a CONS list into the a VideoMode
  // 	this->_v.width = oCar(list).as<core::Number_O>()->as_int();
  // 	list = cCdr(list);
  // 	this->_v.height = oCar(list).as<core::Number_O>()->as_int();
  // 	list = cCdr(list);
  // 	this->_v.bitsPerPixel = (list.nilp())?
  // 	  32 : oCar(list).as<core::Number_O>()->as_int();
  //     } else {
  // 	SIMPLE_ERROR(BF("Could not convert %s to sf::VideoMode") % core::_rep_(obj));
  //     }
  //   }
  // };

  
  // template <>
  // struct from_object<const sf::String&, std::true_type>
  // {
  //   typedef sf::String DeclareType;
  //   DeclareType _v;
  //   from_object(T_P o) : _v(str_get(o)) {};
  // };

  
  // template <>
  // struct	from_object<sf::String,std::true_type>
  // {
  //   typedef	sf::String		DeclareType;
  //   DeclareType _v;
  //   from_object(T_P o) : _v(str_get(o)) {};
  // };
  
  
  // template <>
  // struct	from_object<sf::String&,std::true_type>
  // {
  //   typedef	sf::String		DeclareType;
  //   DeclareType _v;
  //   from_object(T_P o) : _v(str_get(o)) {};
  // };
  
  // template <>
  // struct	from_object<sf::String&,std::false_type>
  // {
  //   typedef	sf::String		DeclareType;
  //   DeclareType _v;
  //   from_object(T_P o) : _v("") {};
  // };
  

  
  // template <>
  // struct to_object<sf::Event::EventType>
  // {
  //   static core::T_sp convert(sf::Event::EventType v)
  //   {
  //     core::Symbol_sp converterSym = core::lisp_intern("SFML","*ENUM-TO-SYMBOL-MAPPER*");
  //     core::SymbolToEnumConverter_sp converter = converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
  //     return converter->symbolForEnum<sf::Event::EventType>(v);
  //   }
  // };

  // template <>
  // struct from_object<sf::Event::EventType,std::true_type>
  // {
  //   typedef sf::Event::EventType DeclareType;
  //   DeclareType _v;
  //   from_object(core::T_sp object)
  //   {
  //     if ( core::Symbol_sp sym = object.asOrNull<core::Symbol_O>() ) {
  // 	if ( sym.notnilp() ) {
  // 	  core::Symbol_sp converterSym = core::lisp_intern("SFML","*ENUM-TO-SYMBOL-MAPPER*");
  // 	  core::SymbolToEnumConverter_sp converter = converterSym->symbolValue().as<core::SymbolToEnumConverter_O>();
  // 	  this->_v = converter->enumForSymbol<sf::Event::EventType>(sym);
  // 	  return;
  // 	}
  //     }
  //     SIMPLE_ERROR(BF("Cannot convert object %s to sf::Event::EventType") % _rep_(object) );
  //   }
  // };


  
  template <> struct from_object<const sf::RenderStates&>
  {
    typedef sf::RenderStates DeclareType;
    DeclareType _v;
    from_object(core::T_sp obj)
    {
      if ( obj.nilp() ) {
  	_v = sf::RenderStates::Default;
      } else {
      	SIMPLE_ERROR(BF("Could not convert %s to sf::IntRect") % core::_rep_(obj));
      }
    }
  };

  // template <> struct from_object<sf::String>
  // {
  //   typedef sf::String DeclareType;
  //   DeclareType _v;
  //   from_object(core::T_sp obj)
  //   {
  //     if ( obj.nilp() ) {
  // 	this->_v = "Initiated with nil";
  //     } else if ( core::Cons_sp list = obj.asOrNull<core::Cons_O>() ) {
  // 	// Translate a CONS list into a String, which doesn't make sense.
  // 	this->_v = "Initiated with cons";
  //     } else {
  // 	this->_v = "Initiated with unkown object type";
  //     }
  //   }
  // };
};

//DECLARE_ENUM_SYMBOL_TRANSLATOR(sf::Event::EventType,core::lisp_intern("event-type"))


extern "C" {
    EXPORT
    void CLASP_MAIN()
    {
        using namespace clbind;
        package("SF")
	  [
	   registerBlendMode(),
	   registerDrawable(),
	   registerGlyph(),
	   registerTransformable(),
	   registerShape(),
	   
	   registerCircleShape(),
	   
	   //FIXME: Add Color translator
	   registerFont(),
	   //FIXME: Missing class Glyph
	   registerImage(),
	   //FIXME missing PrimitiveType enum

	   // //FIXME missing Rect templated class
	   registerRectangleShape(),
	   // //FIXME missing class RenderStates
	   registerRenderTarget(),
	   registerRenderWindow(),
	   registerTexture(),
	   registerTextureBind(),
	   registerTextureGetMaximumSize(),
	   // // ,
	   // // class_<sf::Drawable> ("drawable",no_default_constructor)
	   // // ,
	   // // class_<sf::Transformable> ("transformable")
	   registerRect<float>("float"),
	   registerRect<int>("int"),
	   registerVector2<float>("float"),
	   registerSprite()
	  ];
    }
}
