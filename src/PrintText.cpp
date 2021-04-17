
#include "PrintText.h"

PrintText::PrintText(){}
PrintText::~PrintText(){}

void PrintText::printxy(const char* text, int x, int y, int z){
    int len;
    len = strlen(text);
    
    glColor3f(PrintText::textColor[0], PrintText::textColor[1], PrintText::textColor[2]);

    glMatrixMode( GL_PROJECTION );
    glPushMatrix();
    glLoadIdentity();

    gluOrtho2D( 0, 600, 0, 600 );

    glMatrixMode( GL_MODELVIEW );
    glPushMatrix();

    glLoadIdentity();

    glRasterPos2i(190, 300);

    for ( int i = 0; i < len; i++ )
    {
        glutBitmapCharacter(PrintText::textFont, text[i]);
    }

    glPopMatrix();

    glMatrixMode( GL_PROJECTION );
    glPopMatrix();
    glMatrixMode( GL_MODELVIEW );
}

void PrintText::setFont(const char* font, int size){
    strcpy(PrintText::textFont, font);
    PrintText::textSize = size;
}

void PrintText::setTextColor(float r, float g, float b){
    PrintText::textColor[0] = r;
    PrintText::textColor[1] = g;
    PrintText::textColor[2] = b;
}