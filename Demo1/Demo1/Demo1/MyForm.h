#pragma once
using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;

public ref class MyForm : public System::Windows::Forms::Form
{
public:
	MyForm();
	~MyForm();
protected:
	virtual void OnMouseDown(MouseEventArgs^ e) override;
	virtual void OnMouseMove(MouseEventArgs^ e) override;
	virtual void OnMouseUp(MouseEventArgs^ e) override;
	virtual void OnPaint(PaintEventArgs^ e) override;
private:
	void OnTick(System::Object ^sender, System::EventArgs ^e);
private:
	void DrawRectangle(int x1, int y1, int x2, int y2);
	int m_startX;
	int m_startY;
	int m_curX;
	int m_curY;
	bool m_isPressed = false;
	Timer^ m_timer;

	Drawing::Rectangle m_rectangle;
};