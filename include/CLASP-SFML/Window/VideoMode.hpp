#ifndef CLASP_BINDING_VIDEO_MODE_HPP
#define CLASP_BINDING_VIDEO_MODE_HPP

#include <SFML/Window/VideoMode.hpp>

#include <clasp/clbind/clbind.h>

namespace translate
{
  template <> struct from_object<sf::VideoMode>
  {
    typedef sf::VideoMode DeclareType;
    DeclareType _v;
    from_object(core::T_sp obj)
    {
      if ( obj.nilp() )	{
	this->_v.width = 800;
	this->_v.height = 600;
	this->_v.bitsPerPixel = 32;
      } else if ( core::List_sp list = obj.asOrNull<core::List_V>() ) {
	// Translate a CONS list into a VideoMode
	this->_v.width = clasp_to_fixnum(gc::As<core::Integer_sp>(oCar(list)));
	list = oCdr(list);
	this->_v.height = clasp_to_fixnum(gc::As<core::Integer_sp>(oCar(list)));
	list = oCdr(list);
	this->_v.bitsPerPixel = (list.nilp())?
	  32 : clasp_to_fixnum(gc::As<core::Integer_sp>(oCar(list)));
      } else {
	SIMPLE_ERROR(BF("Could not convert %s to sf::VideoMode") % core::_rep_(obj));
      }
    }
  };

}; //end namespace translate


#endif //CLASP_BINDING_VIDEO_MODE_HPP
