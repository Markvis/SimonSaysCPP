#include "stdafx.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

public ref class point
{
protected:
	int x;
	int y;
public:
	point() 
	{x = 0; y = 0;}
	point(int form1x, int form1y)
	{x = form1x; y = form1y;}
	int getX(){return x;}
	int getY(){return y;}
	void setX(int f1x){x = f1x;}
	void setY(int f1y){y = f1y;}
};
public ref class shape
{
protected:
	point ul;
	point lr;
	Color colr;
public:
	shape():ul(),lr()
	{colr = Color::Blue;}
	shape(int ulx, int uly, Color col)
		:ul(ulx, uly){colr = col;}
	bool containspt(int,int);
	virtual void draw(Graphics ^ pg);
};
public ref class ellipse:public shape
{
public:
	ellipse():shape(){}
	ellipse(int xxx,int yyy, Color col)
		:shape(xxx,yyy,col){}
	virtual void draw(Graphics ^ pg) override;
};
public ref class circle:public ellipse
{
public:
	circle():ellipse(){}
	circle(int xxx,int yyy, Color col)
		:ellipse(xxx,yyy,col){}
	virtual void draw(Graphics ^ pg) override;
};
public ref class rectangle:public shape
{
public:
	rectangle():shape(){}
	rectangle(int xxx,int yyy, Color col)
		:shape(xxx,yyy,col){}
	virtual void draw(Graphics ^ pg) override;
};
public ref class square:public rectangle
{
public:
	square():rectangle(){}
	square(int xxx,int yyy, Color col)
		:rectangle(xxx,yyy,col){}
	virtual void draw(Graphics ^ pg) override;
};