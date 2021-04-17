
#ifndef __print_text_h__
#define __print_text_h__

#include "string.h"
#include "glut.h"

#define RGB_SIZE (3)
#define FONT_SIZE (256)

class PrintText  
{
private: //atributos
    static float        textColor[RGB_SIZE];
    static char         textFont[FONT_SIZE];
    static int          textSize;

	PrintText();
	virtual ~PrintText();

public: //metodos
    static void printxy(const char* text, int x, int y, int z = 0);
    static void setFont(const char* font, int size=12);
    static void setTextColor(float r, float g, float b);
};


#endif