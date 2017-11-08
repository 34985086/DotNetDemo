#include "SelectionTool.h"

SelectionTool::SelectionTool()
{
	CenterToParent();
	SetStyle(ControlStyles::OptimizedDoubleBuffer | ControlStyles::ResizeRedraw | ControlStyles::AllPaintingInWmPaint, true);
	FormBorderStyle = Forms::FormBorderStyle::None;
	BackColor = Color::DarkKhaki;
	TransparencyKey = BackColor;
}

SelectionTool::~SelectionTool()
{
}

void SelectionTool::OnMouseDown(MouseEventArgs ^ e)
{
	Console::WriteLine("SelectionTool::OnMouseDown");
	m_isPressed = true;
	m_startX = e->X;
	m_startY = e->Y;
}

void SelectionTool::OnMouseMove(MouseEventArgs ^ e)
{
	m_curX = e->X;
	m_curY = e->Y;
	Invalidate();
}

void SelectionTool::OnMouseUp(MouseEventArgs ^ e)
{
	Console::WriteLine("SelectionTool::OnMouseUp");
	m_isPressed = false;

	Hide();
}

void SelectionTool::OnPaint(PaintEventArgs ^ e)
{
	Form::OnPaint(e);
	RectangleF rectF = RectangleF(0, 0, Size.Width, Size.Height);
	StringFormat^format = gcnew StringFormat;
	format->Alignment = StringAlignment::Center;
	format->LineAlignment = StringAlignment::Center;
	e->Graphics->DrawString("Drawing Layer", gcnew Drawing::Font("Arial", 20), Brushes::Red, rectF, format);

	if (m_isPressed) {
		Console::WriteLine("SelectionTool::OnPaint");
		Pen^ pen = gcnew Drawing::Pen(Color::White, 2);
		pen->DashStyle = Drawing2D::DashStyle::Dash;
		Rectangle rc = Rectangle(m_startX, m_startY, m_curX - m_startX, m_curY - m_startY);
		e->Graphics->DrawRectangle(pen, rc);
	}
}
