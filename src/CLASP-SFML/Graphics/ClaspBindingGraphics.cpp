#include <CLASP-SFML/translators.hpp>

#include <CLASP-SFML/System/String.hpp>
#include <CLASP-SFML/System/Vector2.hpp>
#include <CLASP-SFML/Window/Event.hpp>
#include <CLASP-SFML/Window/VideoMode.hpp>

#include <CLASP-SFML/Graphics/Color.hpp>
#include <CLASP-SFML/Graphics/Rect.hpp>

#include <CLASP-SFML/Graphics/BlendMode.hpp>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Transformable.hpp>


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

	   .def_constructor("make-blend-mode", constructor<sf::BlendMode::Factor, sf::BlendMode::Factor, sf::BlendMode::Equation>())
	   
	   
	   ,class_<sf::Drawable>("drawable", no_default_constructor)

	   ,class_<sf::Transformable>("transformable", no_default_constructor)
	   .def_constructor("make-transformable", constructor<>())

	   .def("set-position", (void (sf::Transformable::*)(const sf::Vector2f&))&sf::Transformable::setPosition,
		policies<>(), "", "",
		R"**(\brief set the position of the object

		This function completely overwrites the previous position.
		See the move function to apply an offset based on the previous position instead.
		The default position of a transformable object is (0, 0).

		\param position New position

		\see move, getPosition)**")

	   .def("set-rotation", &sf::Transformable::setRotation,
		policies<>(), "", "",
		R"**(\brief set the orientation of the object

		This function completely overwrites the previous rotation.
		See the rotate function to add an angle based on the previous rotation instead.
		The default rotation of a transformable object is 0.

		\param angle New rotation, in degrees

		\see rotate, getRotation)**")

	   .def("set-scale", (void (sf::Transformable::*)(const sf::Vector2f&))&sf::Transformable::setScale,
		policies<>(), "", "",
		R"**(\brief set the scale factors of the object

		This function completely overwrites the previous scale.
		See the scale function to add a factor based on the previous scale instead.
		The default scale of a transformable object is (1, 1).

		\param factors New scale factors

		\see scale, getScale)**")

	   .def("set-origin", (void (sf::Transformable::*)(const sf::Vector2f&))&sf::Transformable::setOrigin,
		policies<>(), "", "",
		R"**(\brief set the local origin of the object

		The origin of an object defines the center point for
		all transformations (position, scale, rotation).
		The coordinates of this point must be relative to the
		top-left corner of the object, and ignore all
		transformations (position, scale, rotation).
		The default origin of a transformable object is (0, 0).

		\param origin New origin

		\see getOrigin)**")

	   .def("get-position", &sf::Transformable::getPosition,
		policies<>(), "", "",
		R"**(\brief get the position of the object

		\return Current position

		\see setPosition)**")

	   .def("get-rotation", &sf::Transformable::getRotation,
		policies<>(), "", "",
		R"**(\brief get the orientation of the object

		The rotation is always in the range [0, 360].

		\return Current rotation, in degrees

		\see setRotation)**")

	   .def("get-scale", &sf::Transformable::getScale,
		policies<>(), "", "",
		R"**(\brief get the current scale of the object

		\return Current scale factors

		\see setScale)**")

	   .def("get-origin", &sf::Transformable::getOrigin,
		policies<>(), "", "",
		R"**(\brief get the local origin of the object

		\return Current origin

		\see setOrigin)**")

	   .def("move", (void (sf::Transformable::*)(const sf::Vector2f&))&sf::Transformable::move,
		policies<>(), "", "",
		R"**(\brief Move the object by a given offset

		This function adds to the current position of the object,
		unlike setPosition which overwrites it.
		Thus, it is equivalent to the following code:
		\code
		object.setPosition(object.getPosition() + offset);
		\endcode

		\param offset Offset

		\see setPosition)**")

	   .def("rotate", &sf::Transformable::rotate,
		policies<>(), "", "",
		R"**(\brief Rotate the object

		This function adds to the current rotation of the object,
		unlike setRotation which overwrites it.
		Thus, it is equivalent to the following code:
		\code
		object.setRotation(object.getRotation() + angle);
		\endcode

		\param angle Angle of rotation, in degrees)**")

	   .def("scale", (void (sf::Transformable::*)(const sf::Vector2f&))&sf::Transformable::scale,
		policies<>(), "", "",
		R"**(\brief Scale the object

		This function multiplies the current scale of the object,
		unlike setScale which overwrites it.
		Thus, it is equivalent to the following code:
		\code
		sf::Vector2f scale = object.getScale();
		object.setScale(scale.x * factor.x, scale.y * factor.y);
		\endcode

		\param factor Scale factors

		\see setScale)**")

	   .def("get-transform", &sf::Transformable::getTransform,
		policies<>(), "", "",
		R"**(\brief get the combined transform of the object

		\return Transform combining the position/rotation/scale/origin of the object

		\see getInverseTransform)**")

	   .def("get-inverse-transform", &sf::Transformable::getInverseTransform,
		policies<>(), "", "",
		R"**(\brief get the inverse of the combined transform of the object

		\return Inverse of the combined transformations applied to the object

		\see getTransform)**")

	   ,class_<sf::Shape, bases<sf::Drawable, sf::Transformable>>("shape", no_default_constructor)

	   .def("set-texture", &sf::Shape::setTexture,
		policies<>(), "", "",
		R"**(\brief Change the source texture of the shape

		The \a texture argument refers to a texture that must
		exist as long as the shape uses it. Indeed, the shape
		doesn't store its own copy of the texture, but rather keeps
		a pointer to the one that you passed to this function.
		If the source texture is destroyed and the shape tries to
		use it, the behavior is undefined.
		\a texture can be NULL to disable texturing.
		If \a resetRect is true, the TextureRect property of
		the shape is automatically adjusted to the size of the new
		texture. If it is false, the texture rect is left unchanged.

		\param texture   New texture
		\param resetRect Should the texture rect be reset to the size of the new texture?

		\see getTexture, setTextureRect)**")

	   .def("set-texture-rect", &sf::Shape::setTextureRect,
		policies<>(), "", "",
		R"**(\brief Set the sub-rectangle of the texture that the shape will display

		The texture rect is useful when you don't want to display
		the whole texture, but rather a part of it.
		By default, the texture rect covers the entire texture.

		\param rect Rectangle defining the region of the texture to display

		\see getTextureRect, setTexture)**")

	   .def("set-fill-color", &sf::Shape::setFillColor,
		policies<>(), "", "",
		R"**(\brief Set the fill color of the shape

		This color is modulated (multiplied) with the shape's
		texture if any. It can be used to colorize the shape,
		or change its global opacity.
		You can use sf::Color::Transparent to make the inside of
		the shape transparent, and have the outline alone.
		By default, the shape's fill color is opaque white.

		\param color New color of the shape

		\see getFillColor, setOutlineColor)**")

	   .def("set-outline-color", &sf::Shape::setOutlineColor,
		policies<>(), "", "",
		R"**(\brief Set the outline color of the shape

		By default, the shape's outline color is opaque white.

		\param color New outline color of the shape

		\see getOutlineColor, setFillColor)**")

	   .def("set-outline-thickness", &sf::Shape::setOutlineThickness,
		policies<>(), "", "",
		R"**(\brief Set the thickness of the shape's outline

		Note that negative values are allowed (so that the outline
		expands towards the center of the shape), and using zero
		disables the outline.
		By default, the outline thickness is 0.

		\param thickness New outline thickness

		\see getOutlineThickness)**")

	   .def("shape/get-texture", &sf::Shape::getTexture,
		policies<>(), "", "",
		R"**(\brief Get the source texture of the shape

		If the shape has no source texture, a NULL pointer is returned.
		The returned pointer is const, which means that you can't
		modify the texture when you retrieve it with this function.

		\return Pointer to the shape's texture

		\see setTexture)**")

	   .def("get-texture-rect", &sf::Shape::getTextureRect,
		policies<>(), "", "",
		R"**(\brief Get the sub-rectangle of the texture displayed by the shape

		\return Texture rectangle of the shape

		\see setTextureRect)**")

	   .def("get-fill-color", &sf::Shape::getFillColor,
		policies<>(), "", "",
		R"**(\brief Get the fill color of the shape

		\return Fill color of the shape

		\see setFillColor)**")

	   .def("get-outline-color", &sf::Shape::getOutlineColor,
		policies<>(), "", "",
		R"**(\brief Get the outline color of the shape

		\return Outline color of the shape

		\see setOutlineColor)**")

	   .def("get-outline-thickness", &sf::Shape::getOutlineThickness,
		policies<>(), "", "",
		R"**(\brief Get the outline thickness of the shape

		\return Outline thickness of the shape

		\see setOutlineThickness)**")

	   .def("get-point-count", &sf::Shape::getPointCount,
		policies<>(), "", "",
		R"**(\brief Get the total number of points of the shape

		\return Number of points of the shape

		\see getPoint)**")

	   .def("get-point", &sf::Shape::getPoint,
		policies<>(), "", "",
		R"**(\brief Get a point of the shape

		The returned point is in local coordinates, that is,
		the shape's transforms (position, rotation, scale) are
		not taken into account.
		The result is undefined if \a index is out of the valid range.

		\param index Index of the point to get, in range [0 .. getPointCount() - 1]

		\return index-th point of the shape

		\see getPointCount)**")

	   .def("get-local-bounds", &sf::Shape::getLocalBounds,
		policies<>(), "", "",
		R"**(\brief Get the local bounding rectangle of the entity

		The returned rectangle is in local coordinates, which means
		that it ignores the transformations (translation, rotation,
		scale, ...) that are applied to the entity.
		In other words, this function returns the bounds of the
		entity in the entity's coordinate system.

		\return Local bounding rectangle of the entity)**")

	   .def("get-global-bounds", &sf::Shape::getGlobalBounds,
		policies<>(), "", "",
		R"**(\brief Get the global bounding rectangle of the entity

		The returned rectangle is in global coordinates, which means
		that it takes in account the transformations (translation,
		rotation, scale, ...) that are applied to the entity.
		In other words, this function returns the bounds of the
		sprite in the global 2D world's coordinate system.

		\return Global bounding rectangle of the entity)**")

	   ,class_<sf::CircleShape, sf::Shape>("circle-shape", no_default_constructor)
	   .def_constructor("make-circle-shape", constructor<float, unsigned int>())

	   .def("set-radius", &sf::CircleShape::setRadius,
		policies<>(), "", "",
		R"**(\brief Set the radius of the circle

		\param radius New radius of the circle

		\see getRadius)**")

	   .def("get-radius", &sf::CircleShape::getRadius,
		policies<>(), "", "",
		R"**(\brief Get the radius of the circle

		\return Radius of the circle

		\see setRadius)**")

	   .def("set-point-count", &sf::CircleShape::setPointCount,
		policies<>(), "", "",
		R"**(\brief Set the number of points of the circle

		\param count New number of points of the circle

		\see getPointCount)**")

	   .def("get-point-count", &sf::CircleShape::getPointCount,
		policies<>(), "", "",
		R"**(\brief Get the number of points of the circle

		\return Number of points of the circle

		\see setPointCount)**")

	   .def("get-point", &sf::CircleShape::getPoint,
		policies<>(), "", "",
		R"**(\brief Get a point of the circle

		The returned point is in local coordinates, that is,
		the shape's transforms (position, rotation, scale) are
		not taken into account.
		The result is undefined if \a index is out of the valid range.

		\param index Index of the point to get, in range [0 .. getPointCount() - 1]

		\return index-th point of the shape)**")

	   //FIXME: Add Color translator

	   ,class_<sf::ConvexShape, sf::Shape>("convex-shape", no_default_constructor)
	   .def_constructor("make-convex-shape", constructor<unsigned int>())

	   .def("set-point-count", &sf::ConvexShape::setPointCount,
		policies<>(), "", "",
		R"**(\brief Set the number of points of the polygon

		\a count must be greater than 2 to define a valid shape.

		\param count New number of points of the polygon

		\see getPointCount)**")

	   .def("get-point-count", &sf::ConvexShape::getPointCount,
		policies<>(), "", "",
		R"**(\brief Get the number of points of the polygon

		\return Number of points of the polygon

		\see setPointCount)**")

	   .def("set-point", &sf::ConvexShape::setPoint,
		policies<>(), "", "",
		R"**(\brief Set the position of a point

		Don't forget that the polygon must remain convex, and
		the points need to stay ordered!
		setPointCount must be called first in order to set the total
		number of points. The result is undefined if \a index is out
		of the valid range.

		\param index Index of the point to change, in range [0 .. getPointCount() - 1]
		\param point New position of the point

		\see getPoint)**")

	   .def("get-point", &sf::ConvexShape::getPoint,
		policies<>(), "", "",
		R"**(\brief Get the position of a point

		The returned point is in local coordinates, that is,
		the shape's transforms (position, rotation, scale) are
		not taken into account.
		The result is undefined if \a index is out of the valid range.

		\param index Index of the point to get, in range [0 .. getPointCount() - 1]

		\return Position of the index-th point of the polygon

		\see setPoint)**")

	   ,class_<sf::Font>("font", no_default_constructor)
	   //FIXME: struct info family missing
	   .def_constructor("make-font", constructor<>())
	   .def_constructor("copy-font", constructor<const sf::Font &>())

	   .def("load-from-file", &sf::Font::loadFromFile,
		policies<>(), "", "",
		R"**(\brief Load the font from a file

		The supported font formats are: TrueType, Type 1, CFF,
		OpenType, SFNT, X11 PCF, Windows FNT, BDF, PFR and Type 42.
		Note that this function know nothing about the standard
		fonts installed on the user's system, thus you can't
		load them directly.

		\param filename Path of the font file to load

		\return True if loading succeeded, false if it failed

		\see loadFromMemory, loadFromStream)**")

	   .def("load-from-memory", &sf::Font::loadFromMemory,
		policies<>(), "", "",
		R"**(\brief Load the font from a file in memory

		The supported font formats are: TrueType, Type 1, CFF,
		OpenType, SFNT, X11 PCF, Windows FNT, BDF, PFR and Type 42.
		Warning: SFML cannot preload all the font data in this
		function, so the buffer pointed by \a data has to remain
		valid as long as the font is used.

		\param data        Pointer to the file data in memory
		\param sizeInBytes Size of the data to load, in bytes

		\return True if loading succeeded, false if it failed

		\see loadFromFile, loadFromStream)**")

	   // .def("load-from-stream", &sf::Font::loadFromStream,
	   // 	policies<>(), "", "",
	   // 	R"**(\brief Load the font from a custom stream

	   // 	The supported font formats are: TrueType, Type 1, CFF,
	   // 	OpenType, SFNT, X11 PCF, Windows FNT, BDF, PFR and Type 42.
	   // 	Warning: SFML cannot preload all the font data in this
	   // 	function, so the contents of \a stream have to remain
	   // 	valid as long as the font is used.

	   // 	\param stream Source stream to read from

	   // 	\return True if loading succeeded, false if it failed

	   // 	\see loadFromFile, loadFromMemory)**")

	   // .def("get-info", &sf::Font::getInfo,
	   // 	policies<>(), "", "",
	   // 	R"**(\brief Get the font information

	   // 	\return A structure that holds the font information)**")

	   // .def("get-glyph", &sf::Font::getGlyph,
	   // 	policies<>(), "", "",
	   // 	R"**(\brief Retrieve a glyph of the font

	   // 	If the font is a bitmap font, not all character sizes
	   // 	might be available. If the glyph is not available at the
	   // 	requested size, an empty glyph is returned.

	   // 	\param codePoint     Unicode code point of the character to get
	   // 	\param characterSize Reference character size
	   // 	\param bold          Retrieve the bold version or the regular one?

	   // 	\return The glyph corresponding to \a codePoint and \a characterSize)**")

	   .def("get-kerning", &sf::Font::getKerning,
		policies<>(), "", "",
		R"**(\brief Get the kerning offset of two glyphs

		The kerning is an extra offset (negative) to apply between two
		glyphs when rendering them, to make the pair look more "natural".
		For example, the pair "AV" have a special kerning to make them
		closer than other characters. Most of the glyphs pairs have a
		kerning offset of zero, though.

		\param first         Unicode code point of the first character
		\param second        Unicode code point of the second character
		\param characterSize Reference character size

		\return Kerning value for \a first and \a second, in pixels)**")

	   .def("get-line-spacing", &sf::Font::getLineSpacing,
		policies<>(), "", "",
		R"**(\brief Get the line spacing

		Line spacing is the vertical offset to apply between two
		consecutive lines of text.

		\param characterSize Reference character size

		\return Line spacing, in pixels)**")

	   .def("get-underline-position", &sf::Font::getUnderlinePosition,
		policies<>(), "", "",
		R"**(\brief Get the position of the underline

		Underline position is the vertical offset to apply between the
		baseline and the underline.

		\param characterSize Reference character size

		\return Underline position, in pixels

		\see getUnderlineThickness)**")

	   .def("get-underline-thickness", &sf::Font::getUnderlineThickness,
		policies<>(), "", "",
		R"**(\brief Get the thickness of the underline

		Underline thickness is the vertical size of the underline.

		\param characterSize Reference character size

		\return Underline thickness, in pixels

		\see getUnderlinePosition)**")

	   .def("font/get-texture", &sf::Font::getTexture,
		policies<>(), "", "",
		R"**(\brief Retrieve the texture containing the loaded glyphs of a certain size

		The contents of the returned texture changes as more glyphs
		are requested, thus it is not very relevant. It is mainly
		used internally by sf::Text.

		\param characterSize Reference character size

		\return Texture containing the glyphs of the requested size)**")

	   //FIXME: Missing class Glyph

	   ,class_<sf::Image>("image", no_default_constructor)
	   .def_constructor("make-image", constructor<>())

	   .def("image/create", (void (sf::Image::*)(unsigned int, unsigned int, const sf::Color&))&sf::Image::create,
		policies<>(), "", "",
		R"**(\brief Create the image and fill it with a unique color

		\param width  Width of the image
		\param height Height of the image
		\param color  Fill color)**")

	   // .def("create-from-array", (void (sf::Image::*)(unsigned int, unsigned int, const sf::Uint8*))&sf::Image::create,
	   // 	policies<>(), "", "",
	   // 	R"**(\brief Create the image from an array of pixels

	   // 	The \a pixel array is assumed to contain 32-bits RGBA pixels,
	   // 	and have the given \a width and \a height. If not, this is
	   // 	an undefined behavior.
	   // 	If \a pixels is null, an empty image is created.

	   // 	\param width  Width of the image
	   // 	\param height Height of the image
	   // 	\param pixels Array of pixels to copy to the image)**")

	   .def("load-from-memory", &sf::Image::loadFromMemory,
		policies<>(), "", "",
		R"**(\brief Load the image from a file in memory

		The supported image formats are bmp, png, tga, jpg, gif,
		psd, hdr and pic. Some format options are not supported,
		like progressive jpeg.
		If this function fails, the image is left unchanged.

		\param data Pointer to the file data in memory
		\param size Size of the data to load, in bytes

		\return True if loading was successful

		\see loadFromFile, loadFromStream)**")

	   // .def("load-from-stream", &sf::Image::loadFromStream,
	   // 	policies<>(), "", "",
	   // 	R"**(\brief Load the image from a custom stream

	   // 	The supported image formats are bmp, png, tga, jpg, gif,
	   // 	psd, hdr and pic. Some format options are not supported,
	   // 	like progressive jpeg.
	   // 	If this function fails, the image is left unchanged.

	   // 	\param stream Source stream to read from

	   // 	\return True if loading was successful

	   // 	\see loadFromFile, loadFromMemory)**")

	   .def("save-to-file", &sf::Image::saveToFile,
		policies<>(), "", "",
		R"**(\brief Save the image to a file on disk

		The format of the image is automatically deduced from
		the extension. The supported image formats are bmp, png,
		tga and jpg. The destination file is overwritten
		if it already exists. This function fails if the image is empty.

		\param filename Path of the file to save

		\return True if saving was successful

		\see create, loadFromFile, loadFromMemory)**")

	   .def("get-size", &sf::Image::getSize,
		policies<>(), "", "",
		R"**(\brief Return the size (width and height) of the image

		\return Size of the image, in pixels)**")

	   .def("create-mask-from-color", &sf::Image::createMaskFromColor,
		policies<>(), "", "",
		R"**(\brief Create a transparency mask from a specified color-key

		This function sets the alpha value of every pixel matching
		the given color to \a alpha (0 by default), so that they
		become transparent.

		\param color Color to make transparent
		\param alpha Alpha value to assign to transparent pixels)**")

	   .def("copy", &sf::Image::copy,
		policies<>(), "", "",
		R"**(\brief Copy pixels from another image onto this one

		This function does a slow pixel copy and should not be
		used intensively. It can be used to prepare a complex
		static image from several others, but if you need this
		kind of feature in real-time you'd better use sf::RenderTexture.

		If \a sourceRect is empty, the whole image is copied.
		If \a applyAlpha is set to true, the transparency of
		source pixels is applied. If it is false, the pixels are
		copied unchanged with their alpha value.

		\param source     Source image to copy
		\param destX      X coordinate of the destination position
		\param destY      Y coordinate of the destination position
		\param sourceRect Sub-rectangle of the source image to copy
		\param applyAlpha Should the copy take in account the source transparency?)**")

	   .def("set-pixel", &sf::Image::setPixel,
		policies<>(), "", "",
		R"**(\brief Change the color of a pixel

		This function doesn't check the validity of the pixel
		coordinates, using out-of-range values will result in
		an undefined behavior.

		\param x     X coordinate of pixel to change
		\param y     Y coordinate of pixel to change
		\param color New color of the pixel

		\see getPixel)**")

	   .def("get-pixel", &sf::Image::getPixel,
		policies<>(), "", "",
		R"**(\brief Get the color of a pixel

		This function doesn't check the validity of the pixel
		coordinates, using out-of-range values will result in
		an undefined behavior.

		\param x X coordinate of pixel to get
		\param y Y coordinate of pixel to get

		\return Color of the pixel at coordinates (x, y)

		\see setPixel)**")

	   .def("get-pixels-ptr", &sf::Image::getPixelsPtr,
		policies<>(), "", "",
		R"**(\brief Get a read-only pointer to the array of pixels

		The returned value points to an array of RGBA pixels made of
		8 bits integers components. The size of the array is
		width * height * 4 (getSize().x * getSize().y * 4).
		Warning: the returned pointer may become invalid if you
		modify the image, so you should never store it for too long.
		If the image is empty, a null pointer is returned.

		\return Read-only pointer to the array of pixels)**")

	   .def("flip-horizontally", &sf::Image::flipHorizontally,
		policies<>(), "", "",
		R"**(\brief Flip the image horizontally (left <-> right))**")

	   .def("flip-vertically", &sf::Image::flipVertically,
		policies<>(), "", "",
		R"**(\brief Flip the image vertically (top <-> bottom))**")


	   //FIXME missing PrimitiveType enum

	   //FIXME missing Rect templated class

	   ,class_<sf::RectangleShape, sf::Shape>("rectangle-shape", no_default_constructor)
	   .def_constructor("make-rectangle-shape", constructor<const sf::Vector2f &>())

	   .def("rectangle-shape/set-size", &sf::RectangleShape::setSize,
		policies<>(), "", "",
		R"**(\brief Set the size of the rectangle

		\param size New size of the rectangle

		\see getSize)**")

	   .def("get-size", &sf::RectangleShape::getSize,
		policies<>(), "", "",
		R"**(\brief Get the size of the rectangle

		\return Size of the rectangle

		\see setSize)**")

	   //FIXME missing class RenderStates

	   ,class_<sf::RenderTarget>("render-target", no_default_constructor)

	   .def("clear", &sf::RenderTarget::clear,
		policies<>(), "", "",
		R"**(\brief Clear the entire target with a single color

		This function is usually called once every frame,
		to clear the previous contents of the target.

		\param color Fill color to use to clear the render target)**")

	   .def("set-view", &sf::RenderTarget::setView,
		policies<>(), "", "",
		R"**(\brief Change the current active view

		The view is like a 2D camera, it controls which part of
		the 2D scene is visible, and how it is viewed in the
		render target.
		The new view will affect everything that is drawn, until
		another view is set.
		The render target keeps its own copy of the view object,
		so it is not necessary to keep the original one alive
		after calling this function.
		To restore the original view of the target, you can pass
		the result of getDefaultView() to this function.

		\param view New view to use

		\see getView, getDefaultView)**")

	   .def("get-view", &sf::RenderTarget::getView,
		policies<>(), "", "",
		R"**(\brief Get the view currently in use in the render target

		\return The view object that is currently used

		\see setView, getDefaultView)**")

	   .def("get-default-view", &sf::RenderTarget::getDefaultView,
		policies<>(), "", "",
		R"**(\brief Get the default view of the render target

		The default view has the initial size of the render target,
		and never changes after the target has been created.

		\return The default view of the render target

		\see setView, getView)**")

	   .def("get-viewport", &sf::RenderTarget::getViewport,
		policies<>(), "", "",
		R"**(\brief Get the viewport of a view, applied to this render target

		The viewport is defined in the view as a ratio, this function
		simply applies this ratio to the current dimensions of the
		render target to calculate the pixels rectangle that the viewport
		actually covers in the target.

		\param view The view for which we want to compute the viewport

		\return Viewport rectangle, expressed in pixels)**")

	   // .def("map-pixel-to-coords", (Vector2f (sf::RenderTarget::*)(const Vector2i&))&sf::RenderTarget::mapPixelToCoords,
	   // 	policies<>(), "", "",
	   // 	R"**(\brief Convert a point from target coordinates to world
	   // 	coordinates, using the current view

	   // 	This function is an overload of the mapPixelToCoords
	   // 	function that implicitly uses the current view.
	   // 	It is equivalent to:
	   // 	\code
	   // 	target.mapPixelToCoords(point, target.getView());
	   // 	\endcode

	   // 	\param point Pixel to convert

	   // 	\return The converted point, in "world" coordinates

	   // 	\see mapCoordsToPixel)**")

	   
	   .def("map-pixel-to-coords", (sf::Vector2f (sf::RenderTarget::*)(const sf::Vector2i&, const sf::View&) const)&sf::RenderTarget::mapPixelToCoords,
		policies<>(), "(self point &optional (view (get-view self)))", "", //FIXME works?
		R"**(\brief Convert a point from target coordinates to world coordinates

		This function finds the 2D position that matches the
		given pixel of the render target. In other words, it does
		the inverse of what the graphics card does, to find the
		initial position of a rendered pixel.

		Initially, both coordinate systems (world units and target pixels)
		match perfectly. But if you define a custom view or resize your
		render target, this assertion is not true anymore, i.e. a point
		located at (10, 50) in your render target may map to the point
		(150, 75) in your 2D world -- if the view is translated by (140, 25).

		For render-windows, this function is typically used to find
		which point (or object) is located below the mouse cursor.

		This version uses a custom view for calculations, see the other
		overload of the function if you want to use the current view of the
		render target.

		\param point Pixel to convert
		\param view The view to use for converting the point

		\return The converted point, in "world" units

		\see mapCoordsToPixel)**")

	   // .def("map-coords-to-pixel", (Vector2i (sf::RenderTarget::*)(const Vector2f&))&sf::RenderTarget::mapCoordsToPixel,
	   // 	policies<>(), "", "",
	   // 	R"**(\brief Convert a point from world coordinates to target
	   // 	coordinates, using the current view

	   // 	This function is an overload of the mapCoordsToPixel
	   // 	function that implicitly uses the current view.
	   // 	It is equivalent to:
	   // 	\code
	   // 	target.mapCoordsToPixel(point, target.getView());
	   // 	\endcode

	   // 	\param point Point to convert

	   // 	\return The converted point, in target coordinates (pixels)

	   // 	\see mapPixelToCoords)**")

	   .def("map-coords-to-pixel", (sf::Vector2i (sf::RenderTarget::*)(const sf::Vector2f&, const sf::View&) const)&sf::RenderTarget::mapCoordsToPixel,
		policies<>(), "(self point &optional (view (get-view self)))", "", //FIXME: I don't think this will work...
		R"**(\brief Convert a point from world coordinates to target coordinates

		This function finds the pixel of the render target that matches
		the given 2D point. In other words, it goes through the same process
		as the graphics card, to compute the final position of a rendered point.

		Initially, both coordinate systems (world units and target pixels)
		match perfectly. But if you define a custom view or resize your
		render target, this assertion is not true anymore, i.e. a point
		located at (150, 75) in your 2D world may map to the pixel
		(10, 50) of your render target -- if the view is translated by (140, 25).

		This version uses a custom view for calculations, see the other
		overload of the function if you want to use the current view of the
		render target.

		\param point Point to convert
		\param view The view to use for converting the point

		\return The converted point, in target coordinates (pixels)

		\see mapPixelToCoords)**")

	   .def("draw", (void (sf::RenderTarget::*)(const sf::Drawable&, const sf::RenderStates&))&sf::RenderTarget::draw,
		policies<>(), "(self drawable &optional (states nil))", "",
		R"**(\brief Draw a drawable object to the render target

		\param drawable Object to draw
		\param states   Render states to use for drawing)**")

	   // .def("draw-vertices", (void (sf::RenderTarget::*)(const sf::Vertex*, unsigned int, sf::PrimitiveType, const sf::RenderStates&))&sf::RenderTarget::draw,
	   // 	policies<>(), "", "",
	   // 	R"**(\brief Draw primitives defined by an array of vertices

	   // 	\param vertices    Pointer to the vertices
	   // 	\param vertexCount Number of vertices in the array
	   // 	\param type        Type of primitives to draw
	   // 	\param states      Render states to use for drawing)**")

	   .def("get-size", &sf::RenderTarget::getSize,
		policies<>(), "", "",
		R"**(\brief Return the size of the rendering region of the target

		\return Size in pixels)**")

	   .def("push-gl-states", &sf::RenderTarget::pushGLStates,
		policies<>(), "", "",
		R"**(\brief Save the current OpenGL render states and matrices

		This function can be used when you mix SFML drawing
		and direct OpenGL rendering. Combined with popGLStates,
		it ensures that:
		\li SFML's internal states are not messed up by your OpenGL code
		\li your OpenGL states are not modified by a call to a SFML function

		More specifically, it must be used around code that
		calls Draw functions. Example:
		\code
		OpenGL code here...
		window.pushGLStates();
		window.draw(...);
		window.draw(...);
		window.popGLStates();
		OpenGL code here...
		\endcode

		Note that this function is quite expensive: it saves all the
		possible OpenGL states and matrices, even the ones you
		don't care about. Therefore it should be used wisely.
		It is provided for convenience, but the best results will
		be achieved if you handle OpenGL states yourself (because
		you know which states have really changed, and need to be
		saved and restored). Take a look at the resetGLStates
		function if you do so.

		\see popGLStates)**")

	   .def("pop-gl-states", &sf::RenderTarget::popGLStates,
		policies<>(), "", "",
		R"**(\brief Restore the previously saved OpenGL render states and matrices

		See the description of pushGLStates to get a detailed
		description of these functions.

		\see pushGLStates)**")

	   .def("reset-gl-states", &sf::RenderTarget::resetGLStates,
		policies<>(), "", "",
		R"**(\brief Reset the internal OpenGL states so that the target is ready for drawing

		This function can be used when you mix SFML drawing
		and direct OpenGL rendering, if you choose not to use
		pushGLStates/popGLStates. It makes sure that all OpenGL
		states needed by SFML are set, so that subsequent draw()
		calls will work as expected.

		Example:
		\code
		OpenGL code here...
		glPushAttrib(...);
		window.resetGLStates();
		window.draw(...);
		window.draw(...);
		glPopAttrib(...);
		OpenGL code here...
		\endcode)**")

	   

	   

	   
	   

	   
	   
	   

	   

	   

	   

	   
	   // ,class_<sf::RenderTarget>("render-target", no_default_constructor)
	   // . def("clear",&sf::RenderTarget::clear)
	   // . def("get-view", &sf::RenderTarget::getView)
	   // . def("draw", (void (sf::RenderTarget::*)(const sf::Drawable&, const sf::RenderStates&))&sf::RenderTarget::draw, policies<>(),  "(self drawable &optional (states nil))", "", "Draws the given Drawable onto the RenderTarget")
	   ,
	   class_<sf::RenderWindow,bases<sf::Window,sf::RenderTarget>>("render-window", no_default_constructor)
	   . def_constructor("make-render-window", constructor<>())
	   . def_constructor("make-render-window-vs", constructor<sf::VideoMode, sf::String>())
	   . def("get-size",&sf::RenderWindow::getSize)
	   . def("capture",&sf::RenderWindow::capture)
	   ,
	   class_<sf::Texture>("texture")
	   . def_constructor("make-texture", constructor<>())
	   //. def_constructor("make-texture", constructor<const sf::Texture &>())
	   . def("texture/create", &sf::Texture::create)
	   . def("load-from-file", &sf::Texture::loadFromFile, policies<>(), "(self filename &optional (area nil))")
	   // . def("load-from-memory", &sf::Texture::loadFromMemory)
	   // . def("load-from-stream", &sf::Texture::loadFromStream)
	   // . def("load-from-image", &sf::Texture::loadFromImage)
	   // . def("get-size", &sf::Texture::getSize)
	   // . def("copy-to-image", &sf::Texture::copyToImage)
	   //missing definitions here
	   // ,
	   // class_<sf::Drawable> ("drawable",no_default_constructor)
	   // ,
	   // class_<sf::Transformable> ("transformable")
	   ,
	   class_<sf::Sprite, bases<sf::Drawable,sf::Transformable>> ("sprite")
	   //. def_constructor("make-sprite", constructor<>())
	   . def_constructor("make-sprite", constructor<const sf::Texture &>())
	   //. def_constructor("make-sprite", constructor<const sf::Texture &, const sf::IntRect &>())
	  ];
    }
}

//example for enum exposing:

//  . enum_<clang::TemplateArgument::ArgKind>(asttooling::_sym_STARclangTemplateArgumentArgKindSTAR)[
// value("Type",clang::TemplateArgument::ArgKind::Type)
// , value("Null",clang::TemplateArgument::ArgKind::Null)
// , value("Declaration",clang::TemplateArgument::ArgKind::Declaration)
// , value("NullPtr",clang::TemplateArgument::ArgKind::NullPtr)
// , value("Integral",clang::TemplateArgument::ArgKind::Integral)
// , value("Template",clang::TemplateArgument::ArgKind::Template)
// , value("TemplateExpansion",clang::TemplateArgument::ArgKind::TemplateExpansion)
// , value("Expression",clang::TemplateArgument::ArgKind::Expression)
// , value("Pack",clang::TemplateArgument::ArgKind::Pack) 
