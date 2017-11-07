#pragma once
using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;

public ref class ReversibleForm : public System::Windows::Forms::Form
{
public:
	ReversibleForm();
	~ReversibleForm();
protected:
	virtual void OnMouseDown(MouseEventArgs^ e) override;
	virtual void OnMouseMove(MouseEventArgs^ e) override;
	virtual void OnMouseUp(MouseEventArgs^ e) override;
	virtual void OnPaint(PaintEventArgs^ e) override;
private:

private:
	void DrawRectangle(const Drawing::Rectangle% rc);
	bool m_isPressed = false;
	Drawing::Point m_startPoint;
	Drawing::Point m_endPoint;
	Drawing::Rectangle m_preRect;
	Drawing::Rectangle m_curRect;
};
