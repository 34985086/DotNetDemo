#include "MyWidget.h"

MyWidget::MyWidget()
{
	//SetStyle(ControlStyles::OptimizedDoubleBuffer | ControlStyles::ResizeRedraw | ControlStyles::AllPaintingInWmPaint, true);
	/*SetStyle(ControlStyles::UserPaint, true);
	SetStyle(ControlStyles::AllPaintingInWmPaint, true);*/
	//SetStyle(ControlStyles::OptimizedDoubleBuffer, true);
}

MyWidget::~MyWidget()
{
	
}

void MyWidget::OnMouseDown(MouseEventArgs ^ e)
{
	m_isPressed = true;
	m_startPoint = PointToScreen(Drawing::Point(e->X, e->Y));
	m_preRect = Drawing::Rectangle(m_startPoint.X, m_startPoint.Y, 0, 0);
	/*Refresh();*/
}

void MyWidget::OnMouseMove(MouseEventArgs ^ e)
{
	if (!m_isPressed) {
		return;
	}

	if (!ClientRectangle.Contains(Drawing::Point(e->X, e->Y))) {
		return;
	}
#if 1
	m_endPoint = Drawing::Point(PointToScreen(Drawing::Point(e->X, e->Y)));
	int w = m_endPoint.X - m_startPoint.X;
	int h = m_endPoint.Y - m_startPoint.Y;
	m_curRect = Drawing::Rectangle(m_startPoint.X, m_startPoint.Y, w, h);
	Refresh();
#endif

#if 0
	m_endPoint = Drawing::Point(PointToScreen(Drawing::Point(e->X, e->Y)));
	int w = m_endPoint.X - m_startPoint.X;
	int h = m_endPoint.Y - m_startPoint.Y;
	m_curRect = Drawing::Rectangle(m_startPoint.X, m_startPoint.Y, w, h);
	DrawRectangle(m_curRect);
	//Refresh();
#endif
#if 0
	ControlPaint::DrawReversibleFrame(m_preRect, Drawing::Color::Black, FrameStyle::Dashed);
	m_endPoint = Drawing::Point(PointToScreen(Drawing::Point(e->X, e->Y)));
	int w = m_endPoint.X - m_startPoint.X;
	int h = m_endPoint.Y - m_startPoint.Y;
	m_preRect = Drawing::Rectangle(m_startPoint.X, m_startPoint.Y, w, h);

	ControlPaint::DrawReversibleFrame(m_preRect, Drawing::Color::Black, FrameStyle::Dashed);
#endif
}

void MyWidget::OnMouseUp(MouseEventArgs ^ e)
{
	m_isPressed = false;
	Refresh();
}

void MyWidget::OnPaint(PaintEventArgs ^ e)
{
	Form::OnPaint(e);
	if (m_isPressed) {
		DrawRectangle(m_curRect);
	}
}

void MyWidget::DrawRectangle(const Drawing::Rectangle % rc)
{
	/*ControlPaint::DrawReversibleFrame(m_preRect, Drawing::Color::Black, FrameStyle::Dashed);
	m_preRect = rc;*/
	ControlPaint::DrawReversibleFrame(rc, Drawing::Color::Black, FrameStyle::Dashed);
}
