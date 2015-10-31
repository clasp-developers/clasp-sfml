#ifndef CLASP_SFML_DRAWABLE_HPP
#define CLASP_SFML_DRAWABLE_HPP

#include <SFML/Drawable.hpp>

#include <clasp/clbind/clbind.h>

namespace sf
{

  class DerivableDrawable : public clbind::Derivable<sf::Drawable>
  {
    typedef sf:Drawable AlieinBase;
  public:
    virtual void draw(RenderTarget &target, RenderStates states) const
    {
      //FIXME
      //core::eval::funcall(
    }

    void default_draw(RenderTarget &target, RenderStates states) const
    {
      SIMPLE_ERROR(BF("Method \"draw\" must be implemented by subclasses of Drawable"));
    }
		      
  }



}; //namespace sf

#endif //CLASP_SFML_DRAWABLE_HPP
