#ifndef CLASP_BINDING_RECT_HPP
#define CLASP_BINDING_RECT_HPP

#include <SFML/Graphics/Rect.hpp>

#include <clasp/clbind/clbind.h>

namespace translate
{

  template <> struct from_object<const sf::IntRect&>
  {
    typedef sf::IntRect DeclareType;
    DeclareType _v;
    from_object(core::T_sp obj)
    {
      if ( obj.nilp() ) {
      } else {
      	SIMPLE_ERROR(BF("Could not convert %s to sf::IntRect") % core::_rep_(obj));
      }
    }
  };

}; //end namespace translate

#endif //CLASP_BINDING_RECT_HPP
