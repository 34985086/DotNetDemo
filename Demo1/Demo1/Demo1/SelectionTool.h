#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;

ref class SelectionTool : public Form
{
public:
	SelectionTool();
	virtual ~SelectionTool();
protected:
	virtual void OnMouseDown(MouseEventArgs^ e) override;
	virtual void OnMouseMove(MouseEventArgs^ e) override;
	virtual void OnMouseUp(MouseEventArgs^ e) override;
	virtual void OnPaint(PaintEventArgs^ e) override;
private:
	//void drawRectangle(int x1, int y1, int x2, int y2);
	bool m_isPressed = false;
	int m_startX;
	int m_startY;
	int m_curX;
	int m_curY;
};

