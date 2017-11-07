#include "GraphicForm.h"

GraphicForm::GraphicForm()
{
	SetStyle(ControlStyles::OptimizedDoubleBuffer | ControlStyles::ResizeRedraw | ControlStyles::AllPaintingInWmPaint, true);
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
	if (m_isPressed) {
		Console::WriteLine("OnPaint");
		System::Drawing::Graphics^ g = e->Graphics;
		g->DrawRectangle(gcnew Drawing::Pen(Drawing::Brushes::Black), Drawing::Rectangle(m_startX, m_startY, m_curX - m_startX, m_curY - m_startY));
	}
}