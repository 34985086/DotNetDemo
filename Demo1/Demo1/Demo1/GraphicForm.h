#pragma once
#include "CustomControl.h"
using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;

public ref class GraphicForm : public System::Windows::Forms::Form
{
public:
	GraphicForm();
	~GraphicForm();
protected:
	virtual void OnMouseDown(MouseEventArgs^ e) override;
	virtual void OnMouseMove(MouseEventArgs^ e) override;
	virtual void OnMouseUp(MouseEventArgs^ e) override;
	virtual void OnPaint(PaintEventArgs^ e) override;
private:
	bool m_isPressed = false;
	int m_startX;
	int m_startY;
	int m_curX;
	int m_curY;
private:	
	Drawing::Point m_startPoint;
	Drawing::Point m_endPoint;
	Drawing::Rectangle m_preRect;
	Drawing::Rectangle m_curRect;

	CustomControl^ m_control;
	void OnSelectionBtnClick(System::Object ^sender, System::EventArgs ^e);
};

