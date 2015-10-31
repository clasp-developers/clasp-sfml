#ifndef CLASP_BINDING_COLOR_HPP
#define CLASP_BINDING_COLOR_HPP

#include <SFML/Graphics/Color.hpp>

#include <clasp/clbind/clbind.h>

namespace translate
{
  
  template <> struct from_object<const sf::Color &>
  {
    typedef sf::Color DeclareType;
    DeclareType _v;
    from_object(core::T_sp obj)
    {
      if ( obj.nilp() ) {
      	this->_v.r = 0;
      	this->_v.g = 0;
      	this->_v.b = 0;
      	this->_v.a = 255;
      } else if ( core::List_sp list = obj.asOrNull<core::List_V>() ) {
      	// Translate a CONS list into the a VideoMode
      	this->_v.r = clasp_to_fixnum(gc::As<core::Integer_sp>(oCar(list)));
      	list = oCdr(list);
      	this->_v.g = clasp_to_fixnum(gc::As<core::Integer_sp>(oCar(list)));
      	list = oCdr(list);
      	this->_v.b = clasp_to_fixnum(gc::As<core::Integer_sp>(oCar(list)));
      	list = oCdr(list);
      	this->_v.a = (oCar(list).nilp())?
      	  255 : clasp_to_fixnum(gc::As<core::Integer_sp>(oCar(list)));
      } else {
      	SIMPLE_ERROR(BF("Could not convert %s to sf::Color") % core::_rep_(obj));
      }
    }
  };

}; //end namespace translate

#endif //CLASP_BINDING_COLOR_HPP
