#include "MyArea.h"
#include <gtkmm.h>
#include <glibmm.h>
#include <string>
#include <pangomm.h>
#include <pangomm/fontdescription.h>

MyArea::MyArea(void)
{
	try {
		m_pixbufBmp = Gdk::Pixbuf::create_from_file( "../res/yaru256x256_32bitColor.bmp" );
		m_pixbufPng = Gdk::Pixbuf::create_from_file( "../res/yaru256x256.png" );
		m_pixbufGif = Gdk::Pixbuf::create_from_file( "../res/yaru256x256_sikiiti216.gif" );
		m_pixbufJpg = Gdk::Pixbuf::create_from_file( "../res/yaru256x256.jpg" );
		m_pixbufTif = Gdk::Pixbuf::create_from_file( "../res/yaru256x256.tif" );
		m_pixbufIco = Gdk::Pixbuf::create_from_file( "../res/yaru128x128_4bitColor_from_256x256_sikiiti216.ico" );
		m_pixbuf_logo = Gdk::Pixbuf::create_from_file( "../res/yaru1024x242.png" );
	}
	catch(...)
	{
		Glib::exception_handlers_invoke();
		exit(1);
	}
}
MyArea::~MyArea(void)
{
}
bool MyArea::on_expose_event( GdkEventExpose* event )
{
	const int width = this->get_width();
	const int height = this->get_height();

	Cairo::RefPtr< Cairo::Context > cr = get_window()->create_cairo_context();
	
	Gdk::Cairo::set_source_color( cr, Gdk::Color( "green" ) ); 
	cr->paint();

	Gdk::Cairo::set_source_pixbuf( cr, m_pixbufBmp, 0, 0 );
	cr->paint();
	
	Gdk::Cairo::set_source_pixbuf( cr, m_pixbufGif, m_pixbufBmp->get_width(), 0 );
	cr->paint();
	
	Gdk::Cairo::set_source_pixbuf( cr, m_pixbufPng, m_pixbufGif->get_width() + m_pixbufGif->get_width(), 0 );
	cr->paint();
	
	Gdk::Cairo::set_source_pixbuf( cr, m_pixbufJpg, m_pixbufGif->get_width() + m_pixbufGif->get_width() + m_pixbufPng->get_width(), 0 );
	cr->paint();
	
	Gdk::Cairo::set_source_pixbuf( cr, m_pixbufTif, 0, m_pixbufBmp->get_height() );
	cr->paint();
	
	Gdk::Cairo::set_source_pixbuf( cr, m_pixbufIco, m_pixbufBmp->get_width(), m_pixbufBmp->get_height() );
	cr->paint();
	
	Gdk::Cairo::set_source_pixbuf( cr, m_pixbuf_logo, 0, m_pixbufBmp->get_height() + m_pixbufTif->get_height() );
	cr->paint();

	return true;
}
