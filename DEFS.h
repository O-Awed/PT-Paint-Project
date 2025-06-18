#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_SQR,		//Draw Square
	DRAW_TRIG,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle
	DRAW_HEX,		//Draw Hexagon
	UNDO,          
	REDO,
	SELECT,
	SWAP,
	RCCW,
	RCW,
	DEL,
	COPY,
	CUT,
	PASTE,
	CLRALL,
	SAVE,
	LOAD,

	MATCHING,
	MISSING,

				//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS		,	//A click on the status bar
	EXIT
	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif