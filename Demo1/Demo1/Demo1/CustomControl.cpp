#include "CustomControl.h"
using namespace System::Drawing;


CustomControl::CustomControl()
{
	SetStyle(ControlStyles::SupportsTransparentBackColor, true);
	//SetStyle(ControlStyles::OptimizedDoubleBuffer, true);
	SetStyle(ControlStyles::Opaque, true);
	SetStyle(ControlStyles::UserPaint, true);
	SetStyle(ControlStyles::AllPaintingInWmPaint, true);
	//SetStyle(ControlStyles::ResizeRedraw, true);
	BackColor = Color::Transparent;
}


CustomControl::~CustomControl()
{

}

void CustomControl::OnMouseDown(MouseEventArgs ^ e)
{
	Console::WriteLine("OnMouseDown");
	m_isPressed = true;
	m_startX = e->X;
	m_startY = e->Y;
}

void CustomControl::OnMouseMove(MouseEventArgs ^ e)
{
	m_curX = e->X;
	m_curY = e->Y;
	Invalidate();
}

void CustomControl::OnMouseUp(MouseEventArgs ^ e)
{
	Console::WriteLine("OnMouseDown");
	m_isPressed = false;
}

void CustomControl::OnPaint(System::Windows::Forms::PaintEventArgs ^ e)
{
	Control::OnPaint(e);
	
	Drawing::Graphics^g = e->Graphics;
	g->Clear(Color::FromArgb(0, 200, 0, 0));
	ButtonRenderer::DrawParentBackground(g, this->ClientRectangle, this);
	//
	drawRectangle(g);

	RectangleF rectF = RectangleF(0, 0, Size.Width, Size.Height);
	StringFormat^format = gcnew StringFormat;
	format->Alignment = StringAlignment::Center;
	format->LineAlignment = StringAlignment::Center;
	g->DrawString("1234567890", gcnew Drawing::Font("Arial", 20), Brushes::White, rectF, format);
#if 0
	g->DrawString("1234567890", gcnew System::Drawing::Font("Arial", 20), System::Drawing::Brushes::Red, 0, 0);
#endif
}

void CustomControl::drawRectangle(Drawing::Graphics^ g)
{
	if (m_isPressed) {
		Pen^ pen = gcnew Drawing::Pen(Brushes::White);
		pen->DashStyle = Drawing2D::DashStyle::Dash;
		Rectangle rc = Rectangle(m_startX, m_startY, m_curX - m_startX, m_curY - m_startY);
		g->DrawRectangle(pen, rc);
	}
}
