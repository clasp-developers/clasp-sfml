#ifndef CLASP_SFML_VIEW_HPP
#define CLASP_SFML_VIEW_HPP

#include <SFML/Graphics/View.hpp>

#include <clasp/clbind/clbind.h>

using namespace clbind;
using namespace sf;

inline class_<sf::View> registerView()
{
  return
    class_<sf::View>("view")
    
    .def_constructor("make-view", constructor<>(),
		     policies<>(), "(view)", "",
		     R"**(\brief Default constructor

     This constructor creates a default view of (0, 0, 1000, 1000))**")
    
    .def_constructor("make-view-from-rectangle", constructor<const FloatRect&>(),
		     policies<>(), "(view rectangle)", "",
		     R"**(\brief Construct the view from a rectangle

	 \param rectangle Rectangle defining the zone to display)**")

    .def_constructor("make-view-from-center-size", constructor<const Vector2f&, const Vector2f&>(),
		     policies<>(), "(view center size)", "",
		     R"**(\brief Construct the view from its center and size

	 \param center Center of the zone to display
	 \param size   Size of zone to display)**")

    .def("set-center-2f", (void (sf::View::*)(float, float))&sf::View::setCenter,
	 policies<>(), "(view x y)", "",
	 R"**(\brief Set the center of the view

	 \param x X coordinate of the new center
	 \param y Y coordinate of the new center

	 \see setSize, getCenter)**")

    .def("set-center-vector", (void (sf::View::*)(const Vector2f&))&sf::View::setCenter,
	 policies<>(), "(view center)", "",
	 R"**(\brief Set the center of the view

	 \param center New center

	 \see setSize, getCenter)**")
    
    .def("set-size-2f", (void (sf::View::*)(float, float))&sf::View::setSize,
	 policies<>(), "(view width height)", "",
	 R"**(\brief Set the size of the view
     \param width  New width of the view
     \param height New height of the view

     \see setCenter, getCenter)**")

    .def("set-size-vector", (void (sf::View::*)(const Vector2f&))&sf::View::setSize,
	 policies<>(), "(view size)", "",
	 R"**(\brief Set the size of the view

	 \param size New size

	 \see setCenter, getCenter)**")

    .def("set-rotation/view", (void (sf::View::*)(float))&sf::View::setRotation,
	 policies<>(), "(view angle)", "",
	 R"**(\brief Set the orientation of the view

	 The default rotation of a view is 0 degree.

	 \param angle New angle, in degrees

	 \see getRotation)**")

    .def("set-viewport", (void (sf::View::*)(const FloatRect&))&sf::View::setViewport,
	 policies<>(), "(view viewport)", "",
	 R"**(\brief Set the target viewport

	 The viewport is the rectangle into which the contents of the
	 view are displayed, expressed as a factor (between 0 and 1)
	 of the size of the RenderTarget to which the view is applied.
	 For example, a view which takes the left side of the target would
	 be defined with View.setViewport(sf::FloatRect(0, 0, 0.5, 1)).
	 By default, a view has a viewport which covers the entire target.

	 \param viewport New viewport rectangle

	 \see getViewport)**")

    .def("reset", (void (sf::View::*)(const FloatRect&))&sf::View::reset,
	 policies<>(), "(view rectangle)", "",
	 R"**(\brief Reset the view to the given rectangle

	 Note that this function resets the rotation angle to 0.

	 \param rectangle Rectangle defining the zone to display

	 \see setCenter, setSize, setRotation)**")

    .def("get-center/view", (const Vector2f& (sf::View::*)())&sf::View::getCenter,
	 policies<>(), "(view)", "",
	 R"**(\brief Get the center of the view

	 \return Center of the view

	 \see getSize, setCenter)**")

    .def("get-size/view", (const Vector2f& (sf::View::*)())&sf::View::getSize,
	 policies<>(), "(view)", "",
	 R"**(\brief Get the size of the view

	 \return Size of the view

	 \see getCenter, setSize)**")

    .def("get-rotation/view", (float (sf::View::*)())&sf::View::getRotation,
	 policies<>(), "(view)", "",
	 R"**(\brief Get the current orientation of the view

	 \return Rotation angle of the view, in degrees

	 \see setRotation)**")

    .def("get-viewport/view", (const FloatRect& (sf::View::*)())&sf::View::getViewport,
	 policies<>(), "(view)", "",
	 R"**(\brief Get the target viewport rectangle of the view

	 \return Viewport rectangle, expressed as a factor of the target size

	 \see setViewport)**")

    .def("move-2f/view", (void (sf::View::*)(float, float))&sf::View::move,
	 policies<>(), "(view offsetX offsetY)", "",
	 R"**(\brief Move the view relatively to its current position

	 \param offsetX X coordinate of the move offset
	 \param offsetY Y coordinate of the move offset

	 \see setCenter, rotate, zoom)**")

    .def("move-vector/view", (void (sf::View::*)(const Vector2f&))&sf::View::move,
	 policies<>(), "(view offset)", "",
	 R"**(\brief Move the view relatively to its current position

	 \param offset Move offset

	 \see setCenter, rotate, zoom)**")

    .def("rotate/view", (void (sf::View::*)(float))&sf::View::rotate,
	 policies<>(), "(view angle)", "",
	 R"**(\brief Rotate the view relatively to its current orientation

	 \param angle Angle to rotate, in degrees

	 \see setRotation, move, zoom)**")

    .def("zoom/view", (void (sf::View::*)(float))&sf::View::zoom,
	 policies<>(), "(view factor)", "",
	 R"**(\brief Resize the view rectangle relatively to its current size

	 Resizing the view simulates a zoom, as the zone displayed on
	 screen grows or shrinks.
	 \a factor is a multiplier:
	 \li 1 keeps the size unchanged
	 \li > 1 makes the view bigger (objects appear smaller)
	 \li < 1 makes the view smaller (objects appear bigger)

	 \param factor Zoom factor to apply

	 \see setSize, move, rotate)**")

    .def("get-transform/view", (const Transform& (sf::View::*)())&sf::View::getTransform,
	 policies<>(), "(view)", "",
	 R"**(\brief Get the projection transform of the view

	 This function is meant for internal use only.

	 \return Projection transform defining the view

	 \see getInverseTransform)**")

    .def("get-inverse-transform/view", (const Transform& (sf::View::*)())&sf::View::getInverseTransform,
	 policies<>(), "(view)", "",
	 R"**(\brief Get the inverse projection transform of the view

	 This function is meant for internal use only.

	 \return Inverse of the projection transform defining the view

	 \see getTransform)**")
    ;
}

#endif //CLASP_SFML_VIEW_HPP
