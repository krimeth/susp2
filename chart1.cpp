//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "chart1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int i=0;
int t=20;
double dt=t/2000.0;
int window=10;
int mini=0,maxi=window;
double u=0,newu=0;
double u1=0,u0=0,d2u=0,du=0;
double x1=0,x=0,y=0;
double w1=0;
double k11,k12,k13,k14,l11,l12,l13,l14;
double k21,k22,k23,k24,l21,l22,l23,l24;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
Timer1->Interval=t;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
Timer1->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	  //rk4
	  k11 = x1;
	  k21= w1;

	  l11 = dx1(x,x1,y,w1,u);
	  l21 = dy1(x,x1,y,w1);

	  k12= x1+l11*dt/2;
	  k22= w1+l21*dt/2;

	  l12= dx1(x + k11*dt / 2, x1 + l11*dt / 2,y + k21*dt / 2, w1 + l21*dt / 2,u);
	  l22= dy1(x + k11*dt / 2, x1 + l11*dt / 2,y + k21*dt / 2, w1 + l21*dt / 2);


	  k13= x1+l12*dt/2;
	  k23= w1+l22*dt/2;

	  l13= dx1(x + k12*dt / 2, x1 + l12*dt / 2,y + k22*dt / 2, w1 + l22*dt / 2,u);
	  l23= dy1(x + k12*dt / 2, x1 + l12*dt / 2,y + k22*dt / 2, w1 + l22*dt / 2);

	  k14= x1+l13*dt;
	  k24= w1+l23*dt;

	  l14= dx1(x + k13*dt , x1 + l13*dt ,y + k23*dt , w1 + l23*dt ,u);
	  l24= dy1(x + k13*dt , x1 + l13*dt ,y + k23*dt , w1 + l23*dt );

// x value
	x = x + dt / 6.0 * (k11 + 2 * k12 + 2 * k13 + k14);
	x1 = x1 + dt / 6.0 * (l11 + 2 * l12 + 2 * l13 + l14);
// y value
	 y = y + dt / 6.0 * (k21 + 2 * k22 + 2 * k23 + k24);
	w1 = w1 + dt / 6.0 * (l21 + 2 * l22 + 2 * l23 + l24);

	Series1->AddXY(i*dt,u);
   Series2->AddXY(i*dt,y-x);
	Series3->AddXY(i*dt,y);


// Grafikon kitöltése
//Series1->AddXY(i*dt,sin(i*dt*2*3.1416*0.25));
//Series2->AddXY(i*dt,du);

// Grafikon "window" secenként
/*maxi=floor(i*dt/window)*window+window;
mini=maxi-window;
Chart1->BottomAxis->Maximum=maxi+(mini>0)*i*dt;
Chart1->BottomAxis->Minimum=mini+(mini>0)*i*dt;*/

// Grafikon "window" seces csúszó ablakban
Chart1->BottomAxis->Maximum=(floor(i*dt/window)>0)*(i*dt-window)+window;
Chart1->BottomAxis->Minimum=(floor(i*dt/window)>0)*(i*dt-window);
 i++;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBar1Change(TObject *Sender)
{
u=(ScrollBar1->Position-100)/200.0;
}
double __fastcall TForm1::dx1(double x, double x1, double y, double w1, double u)
{
double dx1;
dx1=(cc*(w1-x1)+ks*(y-x)+kk*(u-x))/m1;
return dx1;
}
double __fastcall TForm1::dy1(double x, double x1, double y, double w1)
{
double dy1;
dy1=(cc*(x1-w1)+ks*(x-y))/m2;
return dy1;
}
//---------------------------------------------------------------------------
