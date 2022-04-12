//---------------------------------------------------------------------------

#ifndef chart1H
#define chart1H
#define kk 2000
#define m1 10
#define ks 50
#define m2 29
#define cc 400

//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <VCLTee.Series.hpp>
#include <math.h>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TChart *Chart1;
	TButton *Button1;
	TButton *Button2;
	TTimer *Timer1;
	TScrollBar *ScrollBar1;
	TFastLineSeries *Series1;
	TFastLineSeries *Series2;
	TFastLineSeries *Series3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall ScrollBar1Change(TObject *Sender);
private:	// User declarations
public:		double __fastcall dx1(double x, double x1, double y, double w1, double u);
			double __fastcall dy1(double x, double x1, double y, double w1);
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
