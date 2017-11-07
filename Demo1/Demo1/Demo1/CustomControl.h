#pragma once
using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;

ref class CustomControl : public Control
{
public:
	CustomControl();
	virtual ~CustomControl();
protected:
	virtual void OnPaint(System::Windows::Forms::PaintEventArgs^ e) override;
};

