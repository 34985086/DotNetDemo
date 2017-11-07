#include "CustomControl.h"

CustomControl::CustomControl()
{
	//SetStyle(ControlStyles::Opaque, false);
	SetStyle(ControlStyles::SupportsTransparentBackColor, true);
	BackColor = Drawing::Color::FromArgb(100, 200, 0, 0);
}


CustomControl::~CustomControl()
{
}

void CustomControl::OnPaint(System::Windows::Forms::PaintEventArgs ^ e)
{
	Control::OnPaint(e);
	Drawing::Graphics^g = e->Graphics;
	g->DrawString("1234567890", gcnew System::Drawing::Font("Arial", 20), System::Drawing::Brushes::Red, 0, 0);
}
