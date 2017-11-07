#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;

ref class CustomControl : public Control
{
public:
	CustomControl();
	virtual ~CustomControl();
protected:
protected:
	virtual void OnMouseDown(MouseEventArgs^ e) override;
	virtual void OnMouseMove(MouseEventArgs^ e) override;
	virtual void OnMouseUp(MouseEventArgs^ e) override;
	virtual void OnPaint(PaintEventArgs^ e) override;

	virtual void OnBackColorChanged(System::EventArgs^ e) override;
	virtual void OnParentBackColorChanged(EventArgs^ e) override;
private:
	void drawRectangle(Graphics^ g);

private:
	bool m_isPressed = false;
	int m_startX;
	int m_startY;
	int m_curX;
	int m_curY;
	int alpha;
	int m_opacity = 100;
	bool drag = false;
};

