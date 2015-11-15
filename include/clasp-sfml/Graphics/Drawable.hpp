#ifndef CLASP_SFML_DRAWABLE_HPP
#define CLASP_SFML_DRAWABLE_HPP

#include <SFML/Graphics/Drawable.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;


namespace translate
{

  class DerivableDrawable : public clbind::Derivable<sf::Drawable>
  {
    typedef sf::Drawable AlienBase;
  public:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
      //FIXME
      //core::eval::funcall(
    }

    void default_draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
      SIMPLE_ERROR(BF("Method \"draw\" must be implemented by subclasses of Drawable"));
    }
  };

}; //namespace sf


inline class_<sf::Drawable> registerDrawable()
{
  return
    class_<sf::Drawable>("drawable", no_default_constructor);
}


#endif //CLASP_SFML_DRAWABLE_HPP
