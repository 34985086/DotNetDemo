#include "MyForm.h"

MyForm::MyForm()
{
	SetStyle(ControlStyles::OptimizedDoubleBuffer | ControlStyles::ResizeRedraw | ControlStyles::AllPaintingInWmPaint, true);

	m_timer = gcnew Timer();
	m_timer->Interval = 2;
	m_timer->Tick += gcnew System::EventHandler(this, &MyForm::OnTick);
}

MyForm::~MyForm()
{
	
}

void MyForm::OnMouseDown(MouseEventArgs ^ e)
{
	Console::WriteLine("OnMouseDown");
	m_isPressed = true;
	m_startX = e->X;
	m_startY = e->Y;
	//Invalidate();
	m_timer->Start();

	//m_rectangle. = PointToScreen()
}

void MyForm::OnMouseMove(MouseEventArgs ^ e)
{
	//Console::WriteLine("OnMouseMove");
	m_curX = e->X;
	m_curY = e->Y;
	//Refresh();
	//Refresh();
	if (m_isPressed) {
		DrawRectangle(m_startX, m_startY, m_curX, m_curY);
	}
	//
	//DrawRectangle(m_startX, m_startY, m_curX, m_curY);
}

void MyForm::OnMouseUp(MouseEventArgs ^ e)
{
	Console::WriteLine("OnMouseUp");
	//Update();
	//Invalidate();
	m_isPressed = false;
	m_timer->Stop();
}

void MyForm::OnPaint(PaintEventArgs ^ e)
{
	Form::OnPaint(e);
	Console::WriteLine("OnPaint");
	/*if (m_isPressed) {
		Drawing::Graphics^ g = e->Graphics;
		g->DrawString("1111111", gcnew Drawing::Font("Arial", 10), Drawing::Brushes::Black, 100, 100);
		g->DrawRectangle(gcnew Drawing::Pen(Drawing::Brushes::Black), Drawing::Rectangle(m_startX, m_startY, m_curX - m_startX, m_curY - m_startY));
	}*/
	/*if (m_isPressed) {
		DrawRectangle(m_startX, m_startY, m_curX, m_curY);
	}*/
}

void MyForm::DrawRectangle(int x1, int y1, int x2, int y2)
{
#if 0
	Drawing::Point p1 = PointToScreen(Drawing::Point(x1, y1));

	Drawing::Rectangle rc(p1.X, p1.Y, x2 - x1, y2 - y1);
	// Draw the reversible frame.
	Forms::ControlPaint::DrawReversibleFrame(rc, Drawing::Color::White, Forms::FrameStyle::Thick);
#endif
	Drawing::Rectangle rc(x1, y1, x2 - x1, y2 - y1);
	ControlPaint::DrawReversibleFrame(RectangleToScreen(rc), Drawing::Color::Black, Forms::FrameStyle::Dashed);
}


void MyForm::OnTick(System::Object ^sender, System::EventArgs ^e)
{
	//Invalidate(true);
	Console::WriteLine("OnTick");
}


