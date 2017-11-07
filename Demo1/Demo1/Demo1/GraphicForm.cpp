#include "GraphicForm.h"
using namespace System::Drawing;
GraphicForm::GraphicForm()
{
	CenterToScreen();
	SetStyle(ControlStyles::OptimizedDoubleBuffer | ControlStyles::ResizeRedraw | ControlStyles::AllPaintingInWmPaint, true);
	BackColor = Color::RoyalBlue;

	m_control = gcnew CustomControl();

	//m_control->BringToFront();
	m_control->Size = this->Size;
	Controls->Add(m_control);
	m_control->Hide();


	Button ^btn1 = gcnew Button();
	btn1->Text = "Selection";
	btn1->Location = Point(0, 50);
	btn1->Click += gcnew System::EventHandler(this, &GraphicForm::OnSelectionBtnClick);
	Controls->Add(btn1);

	Button ^btn2 = gcnew Button();
	btn2->Text = "btn2";
	btn2->Location = Point(100, 50);
	Controls->Add(btn2);
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
	Drawing::Graphics^ g = e->Graphics;

	RectangleF rectF = RectangleF(0, 0, Size.Width, Size.Height);
	StringFormat^format = gcnew StringFormat;
	format->Alignment = StringAlignment::Center;
	format->LineAlignment = StringAlignment::Center;
	g->DrawString("Hello world", gcnew Drawing::Font("Arial", 20), Brushes::White, rectF, format);
#if 0
	if (m_isPressed) {
		Console::WriteLine("OnPaint");
		Pen^ pen = gcnew Drawing::Pen(Brushes::Black);
		pen->DashStyle = Drawing2D::DashStyle::Dash;
		Rectangle rc = Rectangle(m_startX, m_startY, m_curX - m_startX, m_curY - m_startY);
		g->DrawRectangle(pen, rc);
	}
#endif
}

void GraphicForm::OnSelectionBtnClick(System::Object ^sender, System::EventArgs ^e)
{
	m_control->Show();
}
