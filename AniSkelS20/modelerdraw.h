// modelerdraw.h

// Contains object and routines related to rendering things

#ifndef MODELERDRAW_H
#define MODELERDRAW_H

#include <FL/gl.h>
#include <cstdio>
#include "mat.h"
#include <vector>

// ADDED
// for the XYZ useage
class XYZ {

public:
    XYZ() {}
    XYZ(double a, double b, double c) {
        x = a;
        y = b;
        z = c;
    }
    double x = 0;
    double y = 0;
    double z = 0;
};

// for using the metaball 
class Cell {
public:
    Cell(XYZ* p_in, double* val_in) {
        // both have length 8
        p[0] = p_in[0];
        p[1] = p_in[1];
        p[2] = p_in[2];
        p[3] = p_in[3];
        p[4] = p_in[4];
        p[5] = p_in[5];
        p[6] = p_in[6];
        p[7] = p_in[7];

        val[0] = val_in[0];
        val[1] = val_in[1];
        val[2] = val_in[2];
        val[3] = val_in[3];
        val[4] = val_in[4];
        val[5] = val_in[5];
        val[6] = val_in[6];
        val[7] = val_in[7];
    }
    XYZ p[8];
    double val[8];

};
// END

enum DrawModeSetting_t
{
    NONE = 0, NORMAL, WIREFRAME, FLATSHADE,
};

enum QualitySetting_t
{
    HIGH, MEDIUM, LOW, POOR,
};

// Ignore this; the ModelerDrawState just keeps 
// information about the current color, etc, etc.
class ModelerDrawState
{
public:

    static ModelerDrawState* Instance();

    FILE* m_rayFile;

    DrawModeSetting_t m_drawMode;
    QualitySetting_t  m_quality;

    GLfloat m_ambientColor[4];
    GLfloat m_diffuseColor[4];
    GLfloat m_specularColor[4];
    GLfloat m_shininess;

private:
    ModelerDrawState();
    ModelerDrawState(const ModelerDrawState&) {}
    ModelerDrawState& operator=(const ModelerDrawState&) {}

    static ModelerDrawState* m_instance;
};

// ****************************************************************************
// DRAWING FUNCTIONS
//
// The following functions are for your use in Modeler.  You don't *need* to
// use these functions; however, if you desire to output your model for
// the raytracer project (in .ray file format), you must either call these
// functions or implement the appropriate functionality so that the raytracer
// can handle it.
//
// Note:  Depending on whether a ray file is open or closed, these functions
//        will either output to a ray file or make OpenGL calls.
// ****************************************************************************

// Set the current material properties
void setAmbientColor(float r, float g, float b);
void setDiffuseColor(float r, float g, float b);
void setSpecularColor(float r, float g, float b);
void setShininess(float s);

// Set the current draw mode (see DrawModeSetting_t for valid values
void setDrawMode(DrawModeSetting_t drawMode);

// Set the current quality mode (See QualityModeSetting_t for valid values
void setQuality(QualitySetting_t quality);

// Opens a .ray file for writing, returns false on error
bool openRayFile(const char rayFileName[]);
// Closes the current .ray file if one exists
void closeRayFile();

/////////////////////////////
// Raytraceable Primitives //
/////////////////////////////

// Draw a sphere of radius r
void drawSphere(double r);

// Draw an axis-aligned box from origin to (x,y,z)
void drawBox(double x, double y, double z);

// Draw an axis-aligned texture box from origin to (x,y,z)
void drawTextureBox(double x, double y, double z);

// Draw a cylinder from z=0 to z=h with radius r1 at origin and r2 at z=h
void drawCylinder(double h, double r1, double r2);

// Driangle with three given vertices.  Specify in counterclockwise direction
void drawTriangle(double x1, double y1, double z1,
    double x2, double y2, double z2,
    double x3, double y3, double z3);

void drawTorus(const double& outer_r, const double& inner_r, bool isTexture);

double metaballFunc(double x0, double y0, double z0, double x, double y, double z);

void triangulize(double threshold, Cell grid);

void drawMetaball(double threshold, const double r, double(*metaballFunc)(double x, double y, double z));
Mat4f getModelViewMatrix();

void drawTorus(const double &outer_r, const double &inner_r, bool isTexture);

double metaballFunc(double x0, double y0, double z0, double x, double y, double z);

void triangulize(double threshold, Cell grid);

void drawMetaball(double threshold, const double r, double(*metaballFunc)(double x, double y, double z));

#endif