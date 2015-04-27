#include "stdafx.h"
#include "simon.h"
bool shape::containspt(int x, int y)
{
	int ulx = ul.getX();
	int uly = ul.getY();
	int lrx = lr.getX();
	int lry = lr.getY();

	if((x>ulx && x<lrx)&&
		(y>uly && y<lry))
		return true;
	else
		return false;
}
void shape::draw(Graphics ^ pg)
{
}
void ellipse::draw(Graphics ^ pg)
{
	Brush ^ b = gcnew SolidBrush (colr);
	//pg->FillEllipse(b,230,80,100,100);
	pg->FillEllipse(b,ul.getX(),ul.getY(),150,100);
	lr.setX(ul.getX()+100);
	lr.setY(ul.getY()+100);
}
void circle::draw(Graphics ^ pg)
{
	Brush ^ b = gcnew SolidBrush (colr);
	//pg->FillEllipse(b,210,260,150,100);
	pg->FillEllipse(b,ul.getX(),ul.getY(),100,100);
	lr.setX(ul.getX()+150);
	lr.setY(ul.getY()+100);
}
void rectangle::draw(Graphics ^ pg)
{
	Brush ^ b = gcnew SolidBrush (colr);
	//pg->FillRectangle(b,380,160,150,100);
	pg->FillRectangle(b,ul.getX(),ul.getY(),150,100);
	lr.setX(ul.getX()+100);
	lr.setY(ul.getY()+100);
}
void square::draw(Graphics ^ pg)
{
	Brush ^ b = gcnew SolidBrush (colr);
	//pg->FillRectangle(b,80,160,100,100);
	pg->FillRectangle(b,ul.getX(),ul.getY(),100,100);
	lr.setX(ul.getX()+100);
	lr.setY(ul.getY()+100);
}
