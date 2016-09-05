#pragma once
#include <gtkmm/drawingarea.h>
class MyArea : public Gtk::DrawingArea
{
public:
	MyArea();
	virtual ~MyArea();
protected:
	bool on_expose_event( GdkEventExpose* event );
private:
	Glib::RefPtr< Gdk::Pixbuf > m_pixbufBmp;
	Glib::RefPtr< Gdk::Pixbuf > m_pixbufGif;
	Glib::RefPtr< Gdk::Pixbuf > m_pixbufPng;
	Glib::RefPtr< Gdk::Pixbuf > m_pixbufJpg;
	Glib::RefPtr< Gdk::Pixbuf > m_pixbufTif;
	Glib::RefPtr< Gdk::Pixbuf > m_pixbufIco;
	Glib::RefPtr< Gdk::Pixbuf > m_pixbuf_logo;
};
