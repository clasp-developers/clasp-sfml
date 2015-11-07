#ifndef CLASP_SFML_FONT_HPP
#define CLASP_SFML_FONT_HPP

#include <SFML/Graphics/Font.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;

inline class_<sf::Font> registerFont()
{
  return
    class_<sf::Font>("font", no_default_constructor)
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

		\return Texture containing the glyphs of the requested size)**");
}

#endif //CLASP_SFML_FONT_HPP
