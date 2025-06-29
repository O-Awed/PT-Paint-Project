#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	//color GetUColor(Input* pInput) const;
	void GetUserColor(Input* pInput, color& c,color& f) const;
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle

	void DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected = false) const;  //Draw a triangle

	void DrawCirc(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected = false) const;  //Draw a circle

	void DrawHexa(const int Xcoord[6], const int Ycoord[6], GfxInfo HexaGfxInfo, bool selected) const;

	

	void DrawSquare(Point P1, GfxInfo SquareGfxInfo, bool selected = false) const;  //Draw a square

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	    //get current drwawing color
	color getCrntFillColor() const;	    //get current filling color
	int getCrntPenWidth() const;		//get current pen width

	bool getSave() const;	//Does the user want to save
	
	~Output();
};

#endif