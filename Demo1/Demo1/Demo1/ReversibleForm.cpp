#include "ReversibleForm.h"

#define ON_PAINT

ReversibleForm::ReversibleForm()
{

}

ReversibleForm::~ReversibleForm()
{
	
}

void ReversibleForm::OnMouseDown(MouseEventArgs ^ e)
{
	m_isPressed = true;
	m_startPoint = PointToScreen(Drawing::Point(e->X, e->Y));
	m_preRect = Drawing::Rectangle(m_startPoint.X, m_startPoint.Y, 0, 0);
}

void ReversibleForm::OnMouseMove(MouseEventArgs ^ e)
{
	if (!m_isPressed) {
		return;
	}

	/*if (!ClientRectangle.Contains(Drawing::Point(e->X, e->Y))) {
		return;
	}*/
#ifdef ON_PAINT
	m_endPoint = Drawing::Point(PointToScreen(Drawing::Point(e->X, e->Y)));
	int w = m_endPoint.X - m_startPoint.X;
	int h = m_endPoint.Y - m_startPoint.Y;
	m_curRect = Drawing::Rectangle(m_startPoint.X, m_startPoint.Y, w, h);
	Refresh();
#else
	m_endPoint = Drawing::Point(PointToScreen(Drawing::Point(e->X, e->Y)));
	int w = m_endPoint.X - m_startPoint.X;
	int h = m_endPoint.Y - m_startPoint.Y;
	m_curRect = Drawing::Rectangle(m_startPoint.X, m_startPoint.Y, w, h);
	DrawRectangle(m_curRect);
#endif
}

void ReversibleForm::OnMouseUp(MouseEventArgs ^ e)
{
	m_isPressed = false;
	Refresh();
}

void ReversibleForm::OnPaint(PaintEventArgs ^ e)
{
	Form::OnPaint(e);
	if (m_isPressed) {
		DrawRectangle(m_curRect);
	}
}

void ReversibleForm::DrawRectangle(const Drawing::Rectangle % rc)
{
#ifndef ON_PAINT
	ControlPaint::DrawReversibleFrame(m_preRect, Drawing::Color::Black, FrameStyle::Thick);
	m_preRect = rc;
#endif // !ON_PAINT
	ControlPaint::DrawReversibleFrame(rc, Drawing::Color::Black, FrameStyle::Thick);
}
