#include "GraphicForm.h"
using namespace System::Drawing;
GraphicForm::GraphicForm()
{
	CenterToScreen();
	SetStyle(ControlStyles::OptimizedDoubleBuffer | ControlStyles::ResizeRedraw | ControlStyles::AllPaintingInWmPaint, true);

	m_control = gcnew CustomControl();

	m_control->BringToFront();
	m_control->Size = this->Size;
	Controls->Add(m_control);
	m_control->Hide();
}

GraphicForm::~GraphicForm()
{
	
}

void GraphicForm::OnMouseDown(MouseEventArgs ^ e)
{
	Console::WriteLine("OnMouseDown");
	m_isPressed = true;
	m_startX = e->X;
	m_startY = e->Y;

	//m_control->Show();
}

void GraphicForm::OnMouseMove(MouseEventArgs ^ e)
{
	m_curX = e->X;
	m_curY = e->Y;
	Invalidate();
}

void GraphicForm::OnMouseUp(MouseEventArgs ^ e)
{
	Console::WriteLine("OnMouseUp");
	m_isPressed = false;
}

void GraphicForm::OnPaint(PaintEventArgs ^ e)
{
	Form::OnPaint(e);
	Drawing::Graphics^ g = e->Graphics;
	g->DrawString("Hello world", gcnew Drawing::Font("Arial", 20), Brushes::Black, 100, 100);

	if (m_isPressed) {
		Console::WriteLine("OnPaint");
		Pen^ pen = gcnew Drawing::Pen(Brushes::Black);
		pen->DashStyle = Drawing2D::DashStyle::Dash;
		Rectangle rc = Rectangle(m_startX, m_startY, m_curX - m_startX, m_curY - m_startY);
		g->DrawRectangle(pen, rc);
	}
}