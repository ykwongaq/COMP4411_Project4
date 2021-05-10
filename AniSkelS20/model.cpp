#include <FL/gl.h>
#include <cmath>

#include "model.h"
#include "modelerview.h"
#include "modelerdraw.h"
#include "modelerglobals.h"
#include "modelerapp.h"
#include "modelerapp.h"
#include "camera.h"
#include "bitmap.h"
#include "particleSystem.h"
#include <random>
#include <time.h>

int Model::LEFT_SHOULDER_MOVEMENT = 1;
int Model::RIGHT_SHOULDER_MOVEMENT = 1;
int Model::LEFT_LEG_MOVEMENT = 1;
int Model::RIGHT_LEG_MOVEMENT = -1;
int Model::HEAD_MOVEMENT = 1;

// Draw uppper body of the robot
void Model::drawUpperBody() {
	drawTriangle(4, 0, -6, 2, 0, -2, 0, 3, -4.3);
	drawTriangle(-4, 0, -6, -2, 0, -2, 0, 3, -4.3);
	drawTriangle(-4, 0, -6, 0, -3, -7, 0, 3, -4.3);
	drawTriangle(4, 0, -6, 0, -3, -7, 0, 3, -4.3);
	drawTriangle(0, -2, -1.5, 2, 0, -2, 0, 3, -4.3);
	drawTriangle(0, -2, -1.5, -2, 0, -2, 0, 3, -4.3);
	drawTriangle(4, 0, -6, 2, 0, -2, 0, -3.5, -5);
	drawTriangle(-4, 0, -6, -2, 0, -2, 0, -3.5, -5);
	drawTriangle(-4, 0, -6, 0, -3, -7, 0, -3.5, -5);
	drawTriangle(4, 0, -6, 0, -3, -7, 0, -3.5, -5);
	drawTriangle(0, -1.75, -2, 2, 0, -2, 0, -3.5, -5);
	drawTriangle(0, -1.75, -2, -2, 0, -2, 0, -3.5, -5);
	drawTriangle(0, -1.75, -2, 0, -2, -1.5, 2, 0, -2);
	drawTriangle(0, -1.75, -2, 0, -2, -1.5, -2, 0, -2);
}

// Draw the head of the robot
void Model::drawHead() {
	drawSphere(0.3);
	drawTriangle(0, 0, -2.6, 0.8, 0, 0, 0, 3.5, 0);
	drawTriangle(0, 0, -2.6, 0, 3.5, 0, -0.8, 0, 0);
	drawTriangle(0.8, 0, -2, 0, 0, -1.5, 0, 3.5, 0);
	drawTriangle(-0.8, 0, -2, 0, 0, -1.5, 0, 3.5, 0);
	drawTriangle(0.8, 0, -2, 1.6, -1, -0.1, 0, 3.5, 0);
	drawTriangle(-0.8, 0, -2, -1.6, -1, -0.1, 0, 3.5, 0);
	drawTriangle(-0.8, 0, -2, -1.6, -1, -0.1, 0, -1.5, 0);
	drawTriangle(0.8, 0, -2, 1.6, -1, -0.1, 0, -1.5, 0);
	drawTriangle(-0.8, 0, -2, 0.8, 0, -2, 0, -1.5, 0);
	drawTriangle(0, 0, 0.45, 1.6, -1, -0.1, 0, 3.5, 0);
	drawTriangle(-1.6, -1, -0.1, 0, 0, 0.45, 0, 3.5, 0);
}

// Draw the horn of the robot
void Model::drawHorn() {
	drawTriangle(-0.25, -1.5, -0.75, 0.25, -1.5, -0.75, 0, -1.5, -3);
	drawTriangle(-0.25, -1.5, -0.75, -1.4, -1.4, -1.5, 0, -1.5, -1.5);
	drawTriangle(0.25, -1.5, -0.75, 1.4, -1.4, -1.5, 0, -1.5, -1.5);
	drawTriangle(1.6, -1.25, -3.5, 1.4, -1.4, -1.5, 0.25, -1.5, -0.75);
	drawTriangle(-1.6, -1.25, -3.5, -1.4, -1.4, -1.5, -0.25, -1.5, -0.75);
}

// Draw the left arm of the robot
void Model::drawLeftUpperArm() {
	drawTriangle(-0.15, 0, -1.5, 0.2, 0.25, 0.5, 0.6, 0, 0.5);
	drawTriangle(-0.15, 0, -1.5, 0.2, -0.25, 0.5, 0.6, 0, 0.5);
	drawTriangle(0.4, 0, 1.25, 0.2, -0.25, 0.5, 0.6, 0, 0.5);
	drawTriangle(0.4, 0, 1.25, 0.2, 0.25, 0.5, 0.6, 0, 0.5);
	drawTriangle(0, 0, -0.5, 0.2, 0.25, 0.5, 0, 1.5, 0.6);
	drawTriangle(0, 0, -0.5, 0.2, -0.25, 0.5, 0, -1.5, 0.6);
	drawTriangle(0.4, 1.2, 0.85, 0.2, 0.25, 0.5, 0, 1.5, 0.6);
	drawTriangle(0.4, -1.2, 1, 0.2, -0.25, 0.5, 0, -1.5, 0.6);
	drawTriangle(0.4, 1.2, 0.85, 0.2, 0.25, 0.5, 0.4, 0, 1.25);
	drawTriangle(0.4, -1.2, 1, 0.2, -0.25, 0.5, 0.4, 0, 1.25);
	drawTriangle(0.4, -1.2, 1, 0.2, 0, 3.25, 0.4, 0, 1.25);
	drawTriangle(0.4, 1.2, 0.85, 0.2, 0, 3.25, 0.4, 0, 1.25);
	drawTriangle(0.4, 1.2, 0.85, 0.2, 0, 3.25, 0.6, 0.9, 3.4);
	drawTriangle(0.4, 1.2, 0.85, 0.8, 1.4, 2.4, 0.6, 0.9, 3.4);
	drawTriangle(0.4, -1.2, 1, 0.2, 0, 3.25, 0.4, -1, 3);
	drawTriangle(0.75, -0.8, 3.3, 0.2, 0, 3.25, 0.4, -1, 3);
	drawTriangle(0.75, -0.8, 3.3, 0.2, 0, 3.25, 0.65, -0.4, 3.6);
	drawTriangle(1.2, 0, 4, 0.2, 0, 3.25, 0.65, -0.4, 3.6);
	drawTriangle(1.2, 0, 4, 0.6, 0.9, 3.4, 0.2, 0, 3.25);
	drawTriangle(1.2, 0, 4, 0.6, 0.9, 3.4, 1.4, 0, 3.4);
	drawTriangle(1.2, 0, 4, 0.65, 0.4, 3.6, 1.4, 0, 3.4);
	drawTriangle(1.2, 0, 4, 0.65, 0.4, 3.6, 1.4, 0, 3.4);
	drawTriangle(0.75, -0.8, 3.3, 0.65, -0.4, 3.6, 1.4, 0, 3.4);
	drawTriangle(1.2, 0, 4, 0.65, -0.4, 3.6, 1.4, 0, 3.4);
	drawTriangle(0.75, -0.8, 3.3, 0.4, -1.2, 1, 1.4, 0, 3.4);
	drawTriangle(0.9, 1, 2.7, 0.6, 0.9, 3.4, 1.4, 0, 3.4);
	drawTriangle(0.9, 1, 2.7, 0.4, 1.2, 0.75, 1.4, 0, 3.4);
	drawTriangle(0.75, -0.8, 3.3, 0.4, -1.2, 1, 0.4, -1, 3);
	drawTriangle(0.8, 1.4, 2.4, 0.9, 1, 2.7, 0.6, 0.9, 3.4);
	drawTriangle(0.8, 1.4, 2.4, 0.9, 1, 2.7, 0.4, 1.2, 0.85);
	drawTriangle(0.4, 1.2, 0.85, 0.9, 1, 2.7, 0.3, 0, 1);
	drawTriangle(1.5, 0, 1, 1.4, 0, 3.4, 0.4, 1.2, 0.85);
	drawTriangle(1.5, 0, 1, 1.4, 0, 3.4, 0.4, -1.2, 1);
	drawTriangle(1.5, 0, 1, 2, 0, 0.2, 0.4, -1.2, 1);
	drawTriangle(1.5, 0, 1, 2, 0, 0.2, 0.4, 1.2, 0.85);
	drawTriangle(0, 1.5, 0.6, 2, 0, 0.2, 0.4, 1.2, 0.85);
	drawTriangle(0, 1.5, 0.6, 2, 0, 0.2, 0, 0, -0.5);
	drawTriangle(0, -1.5, 0.6, 2, 0, 0.2, 0, 0, -0.5);
	drawTriangle(0, -1.5, 0.6, 2, 0, 0.2, 0.4, -1.2, 1);
}

void Model::drawLeftLowerArm() {
	drawTriangle(0.2, 0, -0.2, 0.8, 0, 1, 0, 0.6, 0.65);
	drawTriangle(0.2, 0, -0.2, 0.8, 0, 1, 0, -0.6, 0.65);
	drawTriangle(0.2, 0, -0.2, -0.3, 0, 0.5, 0, 0.6, 0.65);
	drawTriangle(0.2, 0, -0.2, -0.3, 0, 0.5, 0, -0.6, 0.65);
	drawTriangle(-0.5, 0, 3.25, 0.8, 0, 1, 0, 0.6, 0.65);
	drawTriangle(-0.5, 0, 3.25, 0.8, 0, 1, 0, -0.6, 0.65);
	drawTriangle(-0.5, 0, 3.25, -0.3, 0, 0.5, 0, 0.6, 0.65);
	drawTriangle(-0.5, 0, 3.25, -0.3, 0, 0.5, 0, -0.6, 0.65);
}

void Model::drawRightUpperArm() {
	drawTriangle(0.15, 0, -1.5, -0.2, 0.25, 0.5, -0.6, 0, 0.5);
	drawTriangle(0.15, 0, -1.5, -0.2, -0.25, 0.5, -0.6, 0, 0.5);
	drawTriangle(-0.4, 0, 1.25, -0.2, -0.25, 0.5, -0.6, 0, 0.5);
	drawTriangle(-0.4, 0, 1.25, -0.2, 0.25, 0.5, -0.6, 0, 0.5);
	drawTriangle(-0, 0, -0.5, -0.2, 0.25, 0.5, -0, 1.5, 0.6);
	drawTriangle(-0, 0, -0.5, -0.2, -0.25, 0.5, -0, -1.5, 0.6);
	drawTriangle(-0.4, 1.2, 0.85, -0.2, 0.25, 0.5, -0, 1.5, 0.6);
	drawTriangle(-0.4, -1.2, 1, -0.2, -0.25, 0.5, -0, -1.5, 0.6);
	drawTriangle(-0.4, 1.2, 0.85, -0.2, 0.25, 0.5, -0.4, 0, 1.25);
	drawTriangle(-0.4, -1.2, 1, -0.2, -0.25, 0.5, -0.4, 0, 1.25);
	drawTriangle(-0.4, -1.2, 1, -0.2, 0, 3.25, -0.4, 0, 1.25);
	drawTriangle(-0.4, 1.2, 0.85, -0.2, 0, 3.25, -0.4, 0, 1.25);
	drawTriangle(-0.4, 1.2, 0.85, -0.2, 0, 3.25, -0.6, 0.9, 3.4);
	drawTriangle(-0.4, 1.2, 0.85, -0.8, 1.4, 2.4, -0.6, 0.9, 3.4);
	drawTriangle(-0.4, -1.2, 1, -0.2, 0, 3.25, -0.4, -1, 3);
	drawTriangle(-0.75, -0.8, 3.3, -0.2, 0, 3.25, -0.4, -1, 3);
	drawTriangle(-0.75, -0.8, 3.3, -0.2, 0, 3.25, -0.65, -0.4, 3.6);
	drawTriangle(-1.2, 0, 4, -0.2, 0, 3.25, -0.65, -0.4, 3.6);
	drawTriangle(-1.2, 0, 4, -0.6, 0.9, 3.4, -0.2, 0, 3.25);
	drawTriangle(-1.2, 0, 4, -0.6, 0.9, 3.4, -1.4, 0, 3.4);
	drawTriangle(-1.2, 0, 4, -0.65, 0.4, 3.6, -1.4, 0, 3.4);
	drawTriangle(-1.2, 0, 4, -0.65, 0.4, 3.6, -1.4, 0, 3.4);
	drawTriangle(-0.75, -0.8, 3.3, -0.65, -0.4, 3.6, -1.4, 0, 3.4);
	drawTriangle(-1.2, 0, 4, -0.65, -0.4, 3.6, -1.4, 0, 3.4);
	drawTriangle(-0.75, -0.8, 3.3, -0.4, -1.2, 1, -1.4, 0, 3.4);
	drawTriangle(-0.9, 1, 2.7, -0.6, 0.9, 3.4, -1.4, 0, 3.4);
	drawTriangle(-0.9, 1, 2.7, -0.4, 1.2, 0.75, -1.4, 0, 3.4);
	drawTriangle(-0.75, -0.8, 3.3, -0.4, -1.2, 1, -0.4, -1, 3);
	drawTriangle(-0.8, 1.4, 2.4, -0.9, 1, 2.7, -0.6, 0.9, 3.4);
	drawTriangle(-0.8, 1.4, 2.4, -0.9, 1, 2.7, -0.4, 1.2, 0.85);
	drawTriangle(-0.4, 1.2, 0.85, -0.9, 1, 2.7, -0.3, 0, 1);
	drawTriangle(-1.5, 0, 1, -1.4, 0, 3.4, -0.4, 1.2, 0.85);
	drawTriangle(-1.5, 0, 1, -1.4, 0, 3.4, -0.4, -1.2, 1);
	drawTriangle(-1.5, 0, 1, -2, 0, 0.2, -0.4, -1.2, 1);
	drawTriangle(-1.5, 0, 1, -2, 0, 0.2, -0.4, 1.2, 0.85);
	drawTriangle(-0, 1.5, 0.6, -2, 0, 0.2, -0.4, 1.2, 0.85);
	drawTriangle(-0, 1.5, 0.6, -2, 0, 0.2, -0, 0, -0.5);
	drawTriangle(-0, -1.5, 0.6, -2, 0, 0.2, -0, 0, -0.5);
	drawTriangle(-0, -1.5, 0.6, -2, 0, 0.2, -0.4, -1.2, 1);
}

void Model::drawRightLowerArm() {
	drawTriangle(-0.2, 0, -0.2, -0.8, 0, 1, -0, 0.6, 0.65);
	drawTriangle(-0.2, 0, -0.2, -0.8, 0, 1, -0, -0.6, 0.65);
	drawTriangle(-0.2, 0, -0.2, +0.3, 0, 0.5, -0, 0.6, 0.65);
	drawTriangle(-0.2, 0, -0.2, +0.3, 0, 0.5, -0, -0.6, 0.65);
	drawTriangle(+0.5, 0, 3.25, -0.8, 0, 1, -0, 0.6, 0.65);
	drawTriangle(+0.5, 0, 3.25, -0.8, 0, 1, -0, -0.6, 0.65);
	drawTriangle(+0.5, 0, 3.25, +0.3, 0, 0.5, -0, 0.6, 0.65);
	drawTriangle(+0.5, 0, 3.25, +0.3, 0, 0.5, -0, -0.6, 0.65);
}

void Model::drawLowerBody() {
	glRotated(90, 1.0, 0.0, 0.0);
	glTranslated(0.0, 0.0, -3.5f);
	drawCylinder(3.25, 1.05, 0.85);
	drawCylinder(2.65, 1.75, 0.85);
	glTranslated(-0.55, -0.55, 2.0);
	glScaled(1.1, 1.1, 2.5);
	drawBox(1, 1, 1);
}

void Model::drawRightUpperLeg() {
	drawTriangle(0.56, 0, 0.75, 0.8, 0, 1.6, 0.57, 1.5, 1.3);
	drawTriangle(0.56, 0, 2.5, 0.8, 0, 1.6, 0.57, 1.5, 1.3);
	drawTriangle(0.56, 0, 0.75, 0.8, 0, 1.6, 0.52, -1.5, 1.2);
	drawTriangle(0.4, -1.2, 1.9, 0.8, 0, 1.6, 0.52, -1.5, 1.2);
	drawTriangle(0.4, -1.2, 1.9, 0.8, 0, 1.6, 0.57, 0, 2.5);
	drawTriangle(0.57, 1.5, 1.3, 0.3, 1.8, 3.5, 0.57, 0, 2.5);
	drawTriangle(0.7, 1.6, 4.5, 0.3, 1.8, 3.5, 0.57, 0, 2.5);
	drawTriangle(0.7, 1.6, 4.5, 0.5, 1.4, 4.3, 0.57, 0, 2.5);
	drawTriangle(0.5, 1.4, 4.3, 0.9, -0.3, 3, 0.57, 0, 2.5);
	drawTriangle(0.5, -0.7, 2.6, 0.9, -0.3, 3, 0.57, 0, 2.5);
	drawTriangle(0.5, -0.7, 2.6, 0.4, -1.2, 1.9, 0.57, 0, 2.5);
	drawTriangle(0.56, 0, 0.75, 2.5, 0, 1.25, 0.57, 1.5, 1.3);
	drawTriangle(0.56, 0, 0.75, 2.5, 0, 1.25, 0.52, -1.5, 1.2);
	drawTriangle(0.4, -1.2, 1.9, 2.5, 0, 1.25, 0.52, -1.5, 1.2);
	drawTriangle(0.3, 1.8, 3.5, 0.7, 1.6, 4.5, 0.57, 1.5, 1.3);
	drawTriangle(0.7, 1.6, 4.5, 2.5, 0, 1.25, 1.5, 1, 4);
	drawTriangle(0.5, -0.7, 2.6, 0.4, -1.2, 1.9, 0.9, -0.3, 3);
	drawTriangle(2.5, 0, 1.25, 0.4, -1.2, 1.9, 0.9, -0.3, 3);
	drawTriangle(2.5, 0, 1.25, 1.5, 1, 4, 0.9, -0.3, 3);
	drawTriangle(0.57, 1.5, 1.3, 2.5, 0, 1.25, 0.7, 1.6, 4.5);
	drawTriangle(0.5, 1.4, 4.3, 1.5, 1, 4, 0.7, 1.6, 4.5);
	drawTriangle(0.5, 1.4, 4.3, 1.5, 1, 4, 0.9, -0.3, 3);
}

void Model::drawRightLowerLeg() {
	drawTriangle(0, 1, -0.5, -0.5, 0.1, 0.2, 0, -1, 3.75);
	drawTriangle(0, 1, -0.5, 0.5, 0.1, 0.2, 0, -1, 3.75);
	drawTriangle(0, -1, 0.8, -0.5, 0.1, 0.2, 0, -1, 3.75);
	drawTriangle(0, -1, 0.8, 0.5, 0.1, 0.2, 0, -1, 3.75);
	drawTriangle(0, 1, -0.5, -0.5, 0.1, 0.2, 0, -1, 0.8);
	drawTriangle(0, 1, -0.5, 0.5, 0.1, 0.2, 0, -1, 0.8);
}

void Model::drawRightFoot() {
	drawTriangle(-0.5, 0, 0, 0, 0, -0.75, 0, 3, 0);
	drawTriangle(0.5, 0, 0, 0, 0, -0.75, 0, 3, 0);
	drawTriangle(0.5, 0, 0, 0, -0.5, 0, 0, 0, -0.75);
	drawTriangle(-0.5, 0, 0, 0, -0.5, 0, 0, 0, -0.75);
}

void Model::drawLeftUpperLeg() {
	drawTriangle(-0.56, 0, 0.75, -0.8, 0, 1.6, -0.57, 1.5, 1.3);
	drawTriangle(-0.56, 0, 2.5, -0.8, 0, 1.6, -0.57, 1.5, 1.3);
	drawTriangle(-0.56, 0, 0.75, -0.8, 0, 1.6, -0.52, -1.5, 1.2);
	drawTriangle(-0.4, -1.2, 1.9, -0.8, 0, 1.6, -0.52, -1.5, 1.2);
	drawTriangle(-0.4, -1.2, 1.9, -0.8, 0, 1.6, -0.57, 0, 2.5);
	drawTriangle(-0.57, 1.5, 1.3, -0.3, 1.8, 3.5, -0.57, 0, 2.5);
	drawTriangle(-0.7, 1.6, 4.5, -0.3, 1.8, 3.5, -0.57, 0, 2.5);
	drawTriangle(-0.7, 1.6, 4.5, -0.5, 1.4, 4.3, -0.57, 0, 2.5);
	drawTriangle(-0.5, 1.4, 4.3, -0.9, -0.3, 3, -0.57, 0, 2.5);
	drawTriangle(-0.5, -0.7, 2.6, -0.9, -0.3, 3, -0.57, 0, 2.5);
	drawTriangle(-0.5, -0.7, 2.6, -0.4, -1.2, 1.9, -0.57, 0, 2.5);
	drawTriangle(-0.56, 0, 0.75, -2.5, 0, 1.25, -0.57, 1.5, 1.3);
	drawTriangle(-0.56, 0, 0.75, -2.5, 0, 1.25, -0.52, -1.5, 1.2);
	drawTriangle(-0.4, -1.2, 1.9, -2.5, 0, 1.25, -0.52, -1.5, 1.2);
	drawTriangle(-0.3, 1.8, 3.5, -0.7, 1.6, 4.5, -0.57, 1.5, 1.3);
	drawTriangle(-0.7, 1.6, 4.5, -2.5, 0, 1.25, -1.5, 1, 4);
	drawTriangle(-0.5, -0.7, 2.6, -0.4, -1.2, 1.9, -0.9, -0.3, 3);
	drawTriangle(-2.5, 0, 1.25, -0.4, -1.2, 1.9, -0.9, -0.3, 3);
	drawTriangle(-2.5, 0, 1.25, -1.5, 1, 4, -0.9, -0.3, 3);
	drawTriangle(-0.57, 1.5, 1.3, -2.5, 0, 1.25, -0.7, 1.6, 4.5);
	drawTriangle(-0.5, 1.4, 4.3, -1.5, 1, 4, -0.7, 1.6, 4.5);
	drawTriangle(-0.5, 1.4, 4.3, -1.5, 1, 4, -0.9, -0.3, 3);
}

void Model::drawLeftLowerLeg() {
	drawTriangle(0, 1, -0.5, -0.5, 0.1, 0.2, 0, -1, 3.75);
	drawTriangle(0, 1, -0.5, 0.5, 0.1, 0.2, 0, -1, 3.75);
	drawTriangle(0, -1, 0.8, -0.5, 0.1, 0.2, 0, -1, 3.75);
	drawTriangle(0, -1, 0.8, 0.5, 0.1, 0.2, 0, -1, 3.75);
	drawTriangle(0, 1, -0.5, -0.5, 0.1, 0.2, 0, -1, 0.8);
	drawTriangle(0, 1, -0.5, 0.5, 0.1, 0.2, 0, -1, 0.8);
}

void Model::drawLeftFoot() {
	drawTriangle(-0.5, 0, 0, 0, 0, -0.75, 0, 3, 0);
	drawTriangle(0.5, 0, 0, 0, 0, -0.75, 0, 3, 0);
	drawTriangle(0.5, 0, 0, 0, -0.5, 0, 0, 0, -0.75);
	drawTriangle(-0.5, 0, 0, 0, -0.5, 0, 0, 0, -0.75);
}

void Model::rotate(const double& x, const double& y, const double& z) {
	glRotated(x, 1.0, 0.0, 0.0);
	glRotated(y, 0.0, 1.0, 0.0);
	glRotated(z, 0.0, 0.0, 1.0);
}

void Model::back_rotate(const double& x, const double& y, const double& z) {
	glRotated(z, 0.0, 0.0, 1.0);
	glRotated(y, 0.0, 1.0, 0.0);
	glRotated(x, 1.0, 0.0, 0.0);
}

void Model::prepare_texture() {
	this->textureImg = readBMP("Images/water.bmp", this->textImgWidth, this->textImgHeight);
	if (this->textureImg == nullptr) { printf("Texture image not found.\n"); }

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->textImgWidth, this->textImgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, this->textureImg);
}

float Model::rad(float degree) {
	return degree * M_PI / 180;
}

float Model::deg(float rad) {
	return rad * 180 / M_PI;
}
float Model::calAngle(Vec3f v1, Vec3f v2) {
	float angle = deg(acos((v1 * v2) / (v1.length() * v2.length())));
	Vec3f corss = v1 ^ v2;

	return v1 * corss >= 0 ? angle : -angle;
}

void Model::drawAxis() {
	// draw axis
	glPushMatrix();
	glBegin(GL_LINES);

	// actual axis
	setDiffuseColor(1.0f, 0.0f, 0.0f); // red x
	glVertex3f(-5, 0, 0);
	glVertex3f(50, 0, 0);


	setDiffuseColor(0.0f, 1.0f, 0.0f); // green y
	glVertex3f(0, -5, 0);
	glVertex3f(0, 50, 0);

	setDiffuseColor(0.0f, 0.0f, 1.0f); // blue z
	glVertex3f(0, 0, -5);
	glVertex3f(0, 0, 50);

	glEnd();
	glPopMatrix();
	setDiffuseColor(1.0f, 1.0f, 1.0f);
}

void Model::drawArmVector() {
	glPushMatrix();
	setDiffuseColor(COLOR_BLUE);
	glBegin(GL_LINES);
	glVertex3f(this->segment1Start[0], this->segment1Start[1], this->segment1Start[2]);
	glVertex3f(this->segment1End[0], this->segment1End[1], this->segment1End[2]);
	setDiffuseColor(COLOR_RED);
	glVertex3f(this->segment2Start[0], this->segment2Start[1], this->segment2Start[2]);
	glVertex3f(this->segment2End[0], this->segment2End[1], this->segment2End[2]);
	glEnd();
	glPopMatrix();
	setDiffuseColor(COLOR_GREEN);
}

void Model::printArmVector() {
	//printf("s1 start = [%f, %f, %f]\n", this->segment1Start[0], this->segment1Start[1], this->segment1Start[2]);
	//printf("s1 end = [%f, %f, %f]\n", this->segment1End[0], this->segment1End[1], this->segment1End[2]);
	//printf("s2 start = [%f, %f, %f]\n", this->segment2Start[0], this->segment2Start[1], this->segment2Start[2]);
	//printf("s2 end = [%f, %f, %f]\n", this->segment2End[0], this->segment2End[1], this->segment2End[2]);
}

void Model::drawVector(Vec3f v) {
	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	v = v * 10;
	glVertex3f(v[0], v[1], v[2]);

	glEnd();
	glPopMatrix();
}

void Model::drawLine(Vec3f v1, Vec3f v2) {
	glPushMatrix();
	//setDiffuseColor(COLOR_WHITE);
	glBegin(GL_LINES);
	glVertex3f(v1[0], v1[1], v1[2]);
	glVertex3f(v2[0], v2[1], v2[2]);
	//cout << "drawing" << endl;
	glEnd();
	glPopMatrix();
	setDiffuseColor(COLOR_GREEN);
}

float Model::calAngleWithDir(Vec3f v1, Vec3f v2) {
	return deg(atan2(v1[2] * v2[1] - v1[1] * v2[2], v1[2] * v2[2] + v1[1] * v2[1]));;
}

Vec3f Model::rotateVectorX(Vec3f v, float angle) {
	Mat4f M;
	MakeHRotX(M, angle);
	Vec3f res = M * v;
	res.normalize();
	res *= v.length();
	return res;
}

Vec3f Model::rotateVectorX(Vec3f v, Vec3f offset, float angle) {
	Vec3f res = v - offset;
	Mat4f M;
	MakeHRotX(M, rad(angle));
	res = M * res;
	res = res + offset;

	return res;
}


Model::Model(int x, int y, int w, int h, char* label) : ModelerView(x, y, w, h, label) {
	this->textureImg = nullptr;
	this->textImgHeight = this->textImgWidth = 0;
	this->tex = 0;
	this->firstTime = true;
	this->segment1Start = Vec3f(3.8, 6.5, 0);
	this->segment2Start = Vec3f(4.45, 2.15, -0.5);
	this->segment2End = Vec3f(4.2, -1.3, -0.5);
	this->segment1End = Vec3f(4.45, 2.15, -0.5);

	this->l1 = (this->segment2Start - this->segment1Start).length();
	this->l2 = (this->segment2End - this->segment2Start).length();

	this->alpha = 0;
	this->beta = 0;
}


std::vector<char> Model::gsentence1(const int stage) {
	std::vector<char> current, next;
	current.push_back('F');
	for (int i = 0; i < stage; ++i) {
		next.clear();
		for (int l = 0; l < current.size(); ++l) {
			// F -> FFF+[+F-F-F]-[-F+F+F]
			if (current[l] == 'F') {
				next.push_back('F');
				next.push_back('F');
				next.push_back('+');
				next.push_back('[');
				next.push_back('+');
				next.push_back('F');
				next.push_back('-');
				next.push_back('F');
				next.push_back('-');
				next.push_back('F');
				next.push_back(']');
				next.push_back('-');
				next.push_back('[');
				next.push_back('-');
				next.push_back('F');
				next.push_back('+');
				next.push_back('F');
				next.push_back('+');
				next.push_back('F');
				next.push_back(']');
			}
			else next.push_back(current[l]);
		}
		current = next;
	}
	return current;
}

std::vector<char> Model::gsentence2(const int stage) {
	std::vector<char> current, next;
	current.push_back('F');
	for (int i = 0; i < stage; ++i) {
		next.clear();
		for (int l = 0; l < current.size(); ++l) {
			// F -> FF-[-F+F+F]+[+F-F-F]
			if (current[l] == 'F') {
				next.push_back('F');
				next.push_back('F');
				next.push_back('-');
				next.push_back('[');
				next.push_back('-');
				next.push_back('F');
				next.push_back('+');
				next.push_back('F');
				next.push_back('+');
				next.push_back('F');
				next.push_back(']');
				next.push_back('+');
				next.push_back('[');
				next.push_back('+');
				next.push_back('F');
				next.push_back('-');
				next.push_back('F');
				next.push_back('-');
				next.push_back('F');
				next.push_back(']');
			}
			else next.push_back(current[l]);
		}
		current = next;
	}
	return current;
}

void Model::drawLsystem(const std::vector<char>& sentence, int option) {

	float len = 0.15;
	glTranslated(1, 2.5, 0);
	for (int i = 0; i < sentence.size(); ++i) {
		char c = sentence[i];
		switch (c) {
		case 'F':
			glLineWidth(2.0f);
			glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, len, 0.0f);
			glEnd();
			glTranslatef(0.0f, len, 0.0f);
			break;
		case '+':
			if (option == 0) {
				glRotatef(-25, 0, 0, 1);
			}
			else {
				glRotatef(-25.3, 0, 0, 1);
			}
			break;
		case '-':
			if (option == 1) {
				glRotatef(25, 0, 0, 1);
			}
			else {
				glRotatef(25.3, 0, 0, 1);
			}
			break;
		case '[':
			glPushMatrix();
			break;
		case ']':
			glPopMatrix();
			break;
		default: break;
		}
	}

}


// We are going to override (is that the right word?) the draw()
// method of ModelerView to draw out SampleModel
void Model::draw() {

	srand(time(NULL));

	// Determine adjust body component or not
	bool isAdjust = VAL(ADJUST_BODY) == 1;
	bool isTexture = VAL(TEXTURE_MAPPING) == 1;
	int level = VAL(LEVEL_CONTROL);
	if (firstTime) {
		this->prepare_texture();
		this->firstTime = false;
	}

	if (VAL(FRAME_ALL) == 1) {
		this->m_camera->frameAll(VAL(XPOS), VAL(YPOS), VAL(ZPOS));
		ModelerApplication::Instance()->SetControlValue(FRAME_ALL, 0);
	}

	// This call takes care of a lot of the nasty projection 
	// matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
	ModelerView::draw();
	Mat4f CameraM = getModelViewMatrix();



	if (VAL(IK_ENABLE))
		this->drawArmVector();
	setDiffuseColor(COLOR_WHITE);
	//glTranslatef(this->armPos[0], this->armPos[1], this->armPos[2]);
	//drawSphere(0.25f);
	//glTranslatef(- this->armPos[0], -this->armPos[1], -this->armPos[2]);

	if (VAL(IK_ENABLE)) {
		glTranslatef(4.5, VAL(IK_POS), 5);
		drawSphere(0.25f);
		glTranslatef(-4.5, -VAL(IK_POS), -5);
	}

	setDiffuseColor(COLOR_GREEN);

	/*
	Vec3f a = Vec3f(0, 1, 0);
	Vec3f b = Vec3f(0, 0, 1);
	float c = this->calAngleWithDir(a, b);
	cout << "angle = " << c << endl;
	float d = this->calAngleWithDir(b, a);
	cout << "angle = " << d << endl;
	*/
	// Handle animation
	if (VAL(ANIMATION) == 1) {
		ModelerApplication* app = ModelerApplication::Instance();

		// Handle left shoulder movement
		double left_shoulder_rotate = app->GetControlValue(LEFT_SHOULDER_X_ROTATE);
		if (left_shoulder_rotate >= Model::LEFT_SHOULDER_X_ROTATE_MAX) Model::LEFT_SHOULDER_MOVEMENT = -1;
		if (left_shoulder_rotate <= Model::LEFT_SHOULDER_X_ROTATE_MIN) Model::LEFT_SHOULDER_MOVEMENT = 1;
		app->SetControlValue(LEFT_SHOULDER_X_ROTATE, left_shoulder_rotate + Model::LEFT_SHOULDER_MOVEMENT);

		// Handle right shoulder movement
		double right_shoulder_rotate = app->GetControlValue(RIGHT_SHOULDER_X_ROTATE);
		if (right_shoulder_rotate >= Model::RIGHT_SHOULDER_X_ROTATE_MAX) Model::RIGHT_SHOULDER_MOVEMENT = -1;
		if (right_shoulder_rotate <= Model::RIGHT_SHOULDER_X_ROTATE_MIN) Model::RIGHT_SHOULDER_MOVEMENT = 1;
		app->SetControlValue(RIGHT_SHOULDER_X_ROTATE, right_shoulder_rotate + Model::RIGHT_SHOULDER_MOVEMENT);

		// Handle left leg movement
		double left_leg_rotate = app->GetControlValue(LEFT_LEG_X_ROTATE);
		if (left_leg_rotate >= Model::LEFT_LEG_X_ROTATE_MAX) Model::LEFT_LEG_MOVEMENT = -1;
		if (left_leg_rotate <= Model::LEFT_LEG_X_ROTATE_MIN) Model::LEFT_LEG_MOVEMENT = 1;
		//printf("left leg rotation %f -> %f \n", left_leg_rotate, left_leg_rotate + Model::LEFT_LEG_MOVEMENT);

		app->SetControlValue(LEFT_LEG_X_ROTATE, left_leg_rotate + Model::LEFT_LEG_MOVEMENT);

		// Handle right leg movement
		double right_leg_rotate = app->GetControlValue(RIGHT_LEG_X_ROTATE);
		if (right_leg_rotate >= Model::RIGHT_LEG_X_ROTATE_MAX) Model::RIGHT_LEG_MOVEMENT = -1;
		if (right_leg_rotate <= Model::RIGHT_LEG_X_ROTATE_MIN) Model::RIGHT_LEG_MOVEMENT = 1;
		//printf("right leg rotation %f -> %f \n", right_leg_rotate, right_leg_rotate + Model::RIGHT_LEG_MOVEMENT);

		app->SetControlValue(RIGHT_LEG_X_ROTATE, right_leg_rotate + Model::RIGHT_LEG_MOVEMENT);
	}

	// draw the floor and center
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_RED);
	glPushMatrix();
	//drawSphere(0.2f);
	//downward by 10
	glTranslated(-5, -10.01f, -5);
	//drawBox(10,0.01f,10);
	glPopMatrix();

	// draw the sample model
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_GREEN);
	glPushMatrix();
	glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));	// Get the value from slider

		//draw the upper body
		// need the whole body rotation
	glPushMatrix();
	glRotated(90, 1.0, 0.0, 0.0);

	glTranslated(0.0, 0.0, -VAL(HEIGHT));

	/***this 0 can be changed as "upper body rotation"***/
	glRotated(VAL(WHOLE_UPPER_BODY_ROTATE), 0.0, 0.0, 1.0);

	if (level >= 1) {
		if (isAdjust) {
			// Draw sphere body
			glTranslated(0.0, 0.0, -3.0);
			drawSphere(2);
			glTranslated(0.0, 0.0, 3.0);
		}
		else {
			// Draw triangular body
			Model::drawUpperBody();
		}

	}
	if (level >= 2) {
		// draw the L system wings
		if (VAL(LSYSTEM_SWITCH)) {
			std::vector<char> sen_1 = gsentence1(VAL(LSYSTEM_STAGE));
			std::vector<char> sen_2 = gsentence2(VAL(LSYSTEM_STAGE));
			int option_right = 0;
			int option_left = 1;

			// left wing
			glPushMatrix();
			glRotated(-90, 1.0, 0.0, 0.0);
			glTranslated(-2.0, 4.0, -3.2);
			glRotated(-65, 0.0, 0.0, 1.0);

			glRotated(VAL(WING_FIRST_ROTATION), 5, 18, 0);


			drawLsystem(sen_1, option_left);

			glPopMatrix();

			//right wings
			glPushMatrix();
			glRotated(-90, 1.0, 0.0, 0.0);
			glTranslated(1.1, 2.2, -3.2);
			glRotated(65, 0.0, 0.0, 1.0);
			glRotated(-VAL(WING_FIRST_ROTATION), 0.4, 1.0, 0.0);
			drawLsystem(sen_2, option_right);
			glPopMatrix();
		}
	}

	//draw the head
	glTranslated(0, 0, -6);

	// If the model is in sad mood, he will shake his head 
	if (VAL(SAD_MOOD) == 1) {
		ModelerApplication* app = ModelerApplication::Instance();

		double head_rotate = app->GetControlValue(HEAD_Z_ROTATE);
		if (head_rotate >= Model::HEAD_Z_ROTATE_MAX) Model::HEAD_MOVEMENT = -1;
		if (head_rotate <= Model::HEAD_Z_ROTATE_MIN) Model::HEAD_MOVEMENT = 1;
		app->SetControlValue(HEAD_Z_ROTATE, head_rotate + Model::HEAD_MOVEMENT);
	}

	this->rotate(VAL(HEAD_X_ROTATE), VAL(HEAD_Y_ROTATE), VAL(HEAD_Z_ROTATE));

	if (level >= 2) {
		Model::drawHead();
		Model::drawHorn();
	}

	glTranslated(0, 0, -5);
	if (isTexture) setDiffuseColor(COLOR_WHITE);

	if (level >= 3) {
		drawTorus(1.5, 0.2, isTexture);
		
	}

	

	setDiffuseColor(COLOR_GREEN);
	glTranslated(0, 0, 5);

	//translate back
	this->back_rotate(-VAL(HEAD_X_ROTATE), -VAL(HEAD_Y_ROTATE), -VAL(HEAD_Z_ROTATE));
	//glRotated(0, 0.0, 0.0, 1.0);
	glTranslated(0, 0, 6.3);


	//draw the left arm
	glTranslated(3.8, 0.0, -6.5);
	/*** here can add XYZ " left showder rotation"***/

	//for picking
	glRotated(VAL(PICKING), 0.0, 0.0, 1.0);
	if (VAL(IK_ENABLE)) {
		//cout << " ===================== " << endl;
		Vec3f target = Vec3f(4.5, VAL(IK_POS), 5);
		Vec3f dir = target - this->segment2Start;
		//dir.normalize();

		Vec3f armVector = this->segment2End - this->segment2Start;
		//armVector.normalize();

		float angle = this->calAngle(dir, armVector);
		//printf("angle = %f\n", angle);

		if (angle >= 10 || angle <= -10) {
			this->segment2End = this->rotateVectorX(this->segment2End, this->segment2Start, -angle);
		}


		Vec3f offset = target - this->segment2End;
		this->segment2End += offset;
		this->segment2Start += offset;

		target = this->segment2Start;
		dir = target - this->segment1Start;

		armVector = this->segment1End - this->segment1Start;
		float angle2 = this->calAngle(dir, armVector);

		//cout << "before angle2 = " << angle2 << endl;
		Vec3f segment = this->segment1End - this->segment1Start;
		float tempAngle = this->calAngle(segment, Vec3f(0, -1, 0));
		//cout << "tempAngle : " << tempAngle << endl;
		float max = VAL(ARM_CONSTRAIN);
		if (tempAngle > max) {
			Vec3f a = Vec3f(0, -1, 0);
			a = this->rotateVectorX(a, Vec3f(0, 0, 0), -30);
			float b = tempAngle - max;
			//cout << "b = " << -b << endl;
			angle2 = -b;
			//cout << "some angle = " << angle2 << endl;
			this->segment1End = this->rotateVectorX(this->segment1End, this->segment1Start, -angle2);
			this->alpha += -angle2;
		}
		else if (angle2 >= 10 || angle2 <= -10) {
			this->segment1End = this->rotateVectorX(this->segment1End, this->segment1Start, -angle2);
			this->alpha += -angle2;
		}
		//printf("angle2 = %f\n", angle2);
		offset = this->segment1End - this->segment2Start;
		this->segment2Start += offset;
		this->segment2End += offset;

		target = Vec3f(4.5, VAL(IK_POS), 5);
		dir = target - this->segment2Start;

		armVector = this->segment2End - this->segment2Start;
		float angle3 = this->calAngle(dir, armVector);
		//printf("angle3 = %f\n", angle3);
		if (angle3 >= 10 || angle3 <= -10) {
			this->segment2End = this->rotateVectorX(this->segment2End, this->segment2Start, -angle3);
		}

		Vec3f segment1 = this->segment1End - this->segment1Start;
		Vec3f segment2 = this->segment2End - this->segment2Start;
		float angle4 = this->calAngleWithDir(segment2, segment1);
		//printf("angle4 = %f\n", angle4);
		this->beta = angle4;

		if (this->alpha >= 360) this->alpha -= 360;
		if (this->alpha <= -360) this->alpha += 360;
		if (this->beta >= 360) this->beta -= 360;
		if (this->beta <= -360) this->beta += 360;

		//this->printArmVector();
		//printf("alpha = %f, this->beta = %f\n", this->alpha, this->beta);
	}


	if (VAL(IK_ENABLE)) {
		this->rotate(this->alpha, 0, 0);
	}
	else {
		this->rotate(VAL(LEFT_SHOULDER_X_ROTATE), VAL(LEFT_SHOULDER_Y_ROTATE), VAL(LEFT_SHOULDER_Z_ROTATE));
	}

	if (level >= 2) {
		if (isAdjust) {
			// Draw cylinder arm
			glTranslated(0.9, 0.0, 0.0);
			drawCylinder(3, 0.4, 0.4);
			glTranslated(-0.9, 0.0, 0.0);
		}
		else {
			// Draw triangular arm
			Model::drawLeftUpperArm();
		}
	}


	// albow
	glTranslated(0.8, 0.0, 4);
	/*** here can add XYZ "left albow rotation"***/
	if (VAL(IK_ENABLE)) {
		this->rotate(this->beta, 0, 0);
	}
	else {
		this->rotate(VAL(LEFT_ELBOW_X_ROTATE), VAL(LEFT_ELBOW_Y_ROTATE), VAL(LEFT_ELBOW_Z_ROTATE));
	}

	//for picking
	glRotated(VAL(PICKING), 0.0, 1.0, 0.0);

	setDiffuseColor(COLOR_RED);

	if (level >= 3) {
		drawSphere(0.25f);
	}

	setDiffuseColor(COLOR_GREEN);

	// left fore arm

	if (level >= 3) {
		if (isAdjust) {
			// Draw cylinder arm
			glTranslated(0.0, 0.0, 0.6);
			glRotated(-9, 0.0, 1.0, 0.0);
			drawCylinder(2, 0.3, 0.3);
			glRotated(9, 0.0, 1.0, 0.0);
			glTranslated(0.0, 0.0, -0.6);
		}
		else {
			// Draw triangular arm
			Model::drawLeftLowerArm();
		}
	}

	//left wrist
	glTranslated(-0.5, 0.0, 3.25);
	/*** here can add XYZ "left wrist rotation"***/
	this->rotate(VAL(LEFT_WRIST_X_ROTATE), VAL(LEFT_WRIST_Y_ROTATE), VAL(LEFT_WRIST_Z_ROTATE));

	//for picking
	glRotated(VAL(PICKING), 0.0, 1.0, 0.0);

	setDiffuseColor(COLOR_RED);

	if (level >= 4) {
		drawSphere(0.15f);
	}

	setDiffuseColor(COLOR_GREEN);

	//left paw
	if (level >= 4) {
		glRotated(7, 0.0, 1.0, 0.0);
		glTranslated(0, -0.35, 0);
		drawBox(0.1f, 0.7, 0.7);
		glTranslated(0, +0.35, 0);
		glTranslated(0, -0.35, 0.7);
		glRotated(-25, 0.0, 1.0, 0.0);
		drawBox(0.1f, 0.7, 0.7);
		glTranslated(0, +0.35, -0.7);
		glRotated(+25, 0.0, 1.0, 0.0);
		glRotated(-15, 0.0, 1.0, 0.0);

		glTranslated(-0.4, -0.2, 0);
		drawBox(0.1f, 0.4, 0.6);
		//glRotated(+90, 0.0, 0.0, 1.0);
		/*  particle system */
		//glPushMatrix();
		//glTranslated(0, 0, -0.3);
		Mat4f CurrModelM1 = getModelViewMatrix();
		ParticleSystem* ps1 = ModelerApplication::Instance()->GetParticleSystem();
		float currt1 = ModelerApplication::Instance()->GetTime();
		int currfps1 = ModelerApplication::Instance()->GetFps();
		cout << "#frame:" << (currt1 * currfps1) << " " << ((int)currt1 * currfps1 % currfps1 == 0) << endl;
		if ((int)(currt1 * currfps1) % currfps1 == 0) ps1->spawnParticles(CameraM, CurrModelM1, currt1);
		glTranslated(0, 0, -0.1);
		double ran = (double)rand() / (RAND_MAX + 1.0);
		Mat4f CurrModelM2 = getModelViewMatrix();
		ParticleSystem* ps2 = ModelerApplication::Instance()->GetParticleSystem();
		float currt2 = (ModelerApplication::Instance()->GetTime()) + ran;
		int currfps2 = ModelerApplication::Instance()->GetFps();
		cout << "#frame:" << (currt2 * currfps2) << " " << ((int)currt2 * currfps2 % currfps2 == 0) << endl;
		if ((int)(currt2 * currfps2) % currfps2 == 0) ps2->spawnParticles(CameraM, CurrModelM2, currt2);
		glTranslated(0, 0, 0.1);
		//glTranslated(0, 0, 0.3);
		//glPopMatrix();
		//glRotated(-90, 0.0, 0.0, 1.0);


		//translate back
		glTranslated(+0.4, +0.2, 0);
		glRotated(15, 0.0, 1.0, 0.0);
		glRotated(-25, 0.0, 1.0, 0.0);
		glTranslated(0, -0.35, +0.7);
		glRotated(+25, 0.0, 1.0, 0.0);
		glTranslated(0, +0.35, -0.7);
		glTranslated(0, -0.35, 0);
		glTranslated(0, +0.35, 0);
		glRotated(-7, 0.0, 1.0, 0.0);

	}

	/*** here can add XYZ "left wrist rotation"***/
	glRotated(-VAL(PICKING), 0.0, 1.0, 0.0);
	this->back_rotate(-VAL(LEFT_WRIST_X_ROTATE), -VAL(LEFT_WRIST_Y_ROTATE), -VAL(LEFT_WRIST_Z_ROTATE));
	glTranslated(0.5, 0.0, -3.25);
	/*** here can add XYZ "left albow rotation"***/
	glRotated(-VAL(PICKING), 0.0, 1.0, 0.0);
	if (VAL(IK_ENABLE))
		this->back_rotate(-this->beta, 0, 0);
	else
		this->back_rotate(-VAL(LEFT_ELBOW_X_ROTATE), -VAL(LEFT_ELBOW_Y_ROTATE), -VAL(LEFT_ELBOW_Z_ROTATE));
	glTranslated(-0.8, 0.0, -4);
	/***translate back the left shoulder rotation***/

	if (VAL(IK_ENABLE)) {
		this->back_rotate(-this->alpha, 0, 0);
	}
	else {
		this->back_rotate(-VAL(LEFT_SHOULDER_X_ROTATE), -VAL(LEFT_SHOULDER_Y_ROTATE), -VAL(LEFT_SHOULDER_Z_ROTATE));
	}
	glRotated(-VAL(PICKING), 0.0, 0.0, 1.0);
	glTranslated(-3.8, 0.0, 6.5);

	//this->drawArmVector();

	//draw the right arm
	glTranslated(-3.8, 0.0, -6.5);
	/*** here can add XYZ " right showder rotation"***/
	this->rotate(-VAL(RIGHT_SHOULDER_X_ROTATE), -VAL(RIGHT_SHOULDER_Y_ROTATE), -VAL(RIGHT_SHOULDER_Z_ROTATE));

	//for picking
	glRotated(-VAL(PICKING), 0.0, 0.0, 1.0);

	if (level >= 2) {
		if (isAdjust) {
			// Draw cylinder arm
			glTranslated(-0.9, 0.0, 0.0);
			drawCylinder(3, 0.4, 0.4);
			glTranslated(0.9, 0.0, 0.0);
		}
		else {
			// Draw triangular arm
			Model::drawRightUpperArm();
		}
	}

	// albow
	glTranslated(-0.8, 0.0, 4);
	/*** here can add XYZ "right albow rotation"***/
	this->rotate(VAL(RIGHT_ELBOW_X_ROTATE), -VAL(RIGHT_ELBOW_Y_ROTATE), -VAL(RIGHT_ELBOW_Z_ROTATE));

	//for picking
	glRotated(-VAL(PICKING), 0.0, 1.0, 0.0);

	setDiffuseColor(COLOR_RED);

	if (level >= 3) {
		drawSphere(0.25f);
	}
	setDiffuseColor(COLOR_GREEN);

	if (level >= 3) {
		//right fore arm
		if (isAdjust) {
			// Draw cylinder arm
			glTranslated(0.0, 0.0, 0.6);
			glRotated(9, 0.0, 1.0, 0.0);
			drawCylinder(2, 0.3, 0.3);
			glRotated(-9, 0.0, 1.0, 0.0);
			glTranslated(0.0, 0.0, -0.6);
		}
		else {
			// Draw triangular arm
			Model::drawRightLowerArm();
		}
	}

	//right wrist
	glTranslated(0.5, 0.0, 3.25);
	/*** here can add XYZ "left wrist rotation"***/
	this->rotate(-VAL(RIGHT_WRIST_X_ROTATE), -VAL(RIGHT_WRIST_Y_ROTATE), -VAL(RIGHT_WRIST_Z_ROTATE));

	//for picking
	glRotated(-VAL(PICKING), 0.0, 1.0, 0.0);

	setDiffuseColor(COLOR_RED);

	if (level >= 4) {
		drawSphere(0.15f);
	}

	setDiffuseColor(COLOR_GREEN);

	if (level >= 4) {
		//right paw
		glRotated(-7, 0.0, 1.0, 0.0);
		glTranslated(0, -0.35, 0);
		drawBox(-0.1f, 0.7, 0.7);
		glTranslated(0, +0.35, 0);
		glTranslated(0, -0.35, 0.7);
		glRotated(25, 0.0, 1.0, 0.0);
		drawBox(-0.1f, 0.7, 0.7);
		glTranslated(0, +0.35, -0.7);
		glRotated(-25, 0.0, 1.0, 0.0);
		glRotated(+15, 0.0, 1.0, 0.0);

		glTranslated(0.4, -0.2, 0);
		drawBox(-0.1f, 0.4, 0.6);

		//translate back
		glTranslated(-0.4, +0.2, 0);
		glRotated(-15, 0.0, 1.0, 0.0);
		glRotated(25, 0.0, 1.0, 0.0);
		glTranslated(0, -0.35, +0.7);
		glRotated(-25, 0.0, 1.0, 0.0);
		glTranslated(0, +0.35, -0.7);
		glTranslated(0, -0.35, 0);
		glTranslated(0, +0.35, 0);
		glRotated(7, 0.0, 1.0, 0.0);

		if (VAL(METABALL)) {
			glRotated(-10, 0.0, 1.0, 0.0);
			glRotated(7, 0.0, 1.0, 0.0);
			glTranslated(0.6, 0, 0.7);
			glRotated(-90, 0, 0, 1);
			glRotated(VAL(METABALL_SECOND_ROTATION), 0, 1, 0);
			glRotated(VAL(METABALL_FIRST_ROTATION), 1, 0, 0);
			glScaled(VAL(METABALL_LENGTH), 0.5, 0.8);

			auto m_func = [](double x, double y, double z)
				-> double {return	metaballFunc(-VAL(METABALL_MERGE), 0, 0, x, y, z) +
				metaballFunc(VAL(METABALL_MERGE), 0, 0, x, y, z); };

			drawMetaball(m_func(1.12, 0, 0), 0.8, m_func);

	

			//translate back
			//glScaled(1 / VAL(METABALL_LENGTH), 1 / 0.5, 1 / 0.8);
			//glRotated(-VAL(METABALL_FIRST_ROTATION), 1, 0, 0);
			//glRotated(-VAL(METABALL_SECOND_ROTATION), 0, 1, 0);
			//glRotated(90, 0, 0, 1);
			//glTranslated(-0.8, 0, -0.7);
			//glRotated(-7, 0.0, 1.0, 0.0);
		}
	}

	glPopMatrix();

	//draw the down body 
	glPushMatrix();
	if (!isAdjust)
		Model::drawLowerBody();
	glPopMatrix();

	// draw the left leg
	glPushMatrix();
	glRotated(90, 1.0, 0.0, 0.0);

	//glRotated(20, 0.0, 1.0, 0.0);
	//glRotated(25, 1.0, 0.0, 0.0);
	/***here can add X Y Z rotation and counted as " right leg roation"***/
	this->rotate(VAL(LEFT_LEG_X_ROTATE), -VAL(LEFT_LEG_Y_ROTATE), -VAL(LEFT_LEG_Z_ROTATE));

	if (level >= 2) {
		if (isAdjust) {
			// Draw cylinder leg
			glRotated(-20, 0.0, 1.0, 0.0);
			glRotated(-25, 1.0, 0.0, 0.0);
			glTranslated(1.9, -0.5, 0.0);
			drawCylinder(2.5, 0.4, 0.4);
			glTranslated(-1.9, 0.5, -0.0);
			glRotated(20, 0.0, 1.0, 0.0);
			glRotated(25, 1.0, 0.0, 0.0);
		}
		else {
			// Draw triangular leg
			Model::drawRightUpperLeg();
		}

	}
	// knee 
	//go to the place it rotate
	// the knee's center
	glTranslated(0.5, 1.3, 4.4);
	setDiffuseColor(COLOR_RED);

	if (level >= 3) {
		drawSphere(0.3f);
	}
	setDiffuseColor(COLOR_GREEN);
	glRotated(-20, 0.0, 1.0, 0.0);
	glRotated(-25, 1.0, 0.0, 0.0);
	/***here can add X Y Z rotation and counted as "left ankle roation"***/
	this->rotate(VAL(LEFT_CALF_X_ROTATE), -VAL(LEFT_CALF_Y_ROTATE), -VAL(LEFT_CALF_Z_ROTATE));
	if (level >= 3) {
		if (isAdjust) {
			// Draw cylinder leg
			glRotated(13, 1.0, 0.0, 0.0);
			glTranslated(0.0, 0.0, 1.0);
			drawCylinder(2, 0.3, 0.3);
			glTranslated(0.0, 0.0, -1.0);
			glRotated(-13, 1.0, 0.0, 0.0);
		}
		else {
			// Draw triangular leg
			Model::drawRightLowerLeg();
		}
	}


	//ankle
	glRotated(-2, 1.0, 0.0, 0.0);
	glTranslated(0, -0.9, 3.65);
	setDiffuseColor(COLOR_RED);
	if (level >= 4) {
		drawSphere(0.3f);
	}
	glTranslated(0, 0, 0.75);
	setDiffuseColor(COLOR_GREEN);
	/***here can add X Y Z rotation and counted as "right ankle roation"***/
	glTranslated(0, 0, -0.75);
	this->rotate(VAL(LEFT_FOOT_X_ROTATE), -VAL(LEFT_FOOT_Y_ROTATE), -VAL(LEFT_FOOT_Z_ROTATE));
	glTranslated(0, 0, 0.75);
	if (level >= 4) {
		Model::drawRightFoot();
	}
	glPopMatrix();

	// draw the right leg
	glPushMatrix();
	glRotated(90, 1.0, 0.0, 0.0);

	//glRotated(-20, 0.0, 1.0, 0.0);
	//glRotated(25, 1.0, 0.0, 0.0);
	/***here can add X Y Z rotation and counted as " right leg roation"***/
	this->rotate(VAL(RIGHT_LEG_X_ROTATE), -VAL(RIGHT_LEG_Y_ROTATE), -VAL(RIGHT_LEG_Z_ROTATE));

	if (level >= 2) {
		if (isAdjust) {
			// Draw cylinder leg
			glRotated(20, 0.0, 1.0, 0.0);
			glRotated(-25, 1.0, 0.0, 0.0);
			glTranslated(-1.9, -0.5, 0.0);
			drawCylinder(2.5, 0.4, 0.4);
			glTranslated(1.9, 0.5, -0.0);
			glRotated(-20, 0.0, 1.0, 0.0);
			glRotated(25, 1.0, 0.0, 0.0);
		}
		else {
			// Draw triangular leg
			Model::drawLeftUpperLeg();
		}
	}

	// knee 
	//go to the place it rotate
	// the knee's center
	glTranslated(-0.5, 1.3, 4.4);
	setDiffuseColor(COLOR_RED);
	if (level >= 3) {
		drawSphere(0.3f);
	}
	setDiffuseColor(COLOR_GREEN);
	glRotated(20, 0.0, 1.0, 0.0);
	glRotated(-25, 1.0, 0.0, 0.0);
	/***here can add X Y Z rotation and counted as "right ankle roation"***/
	this->rotate(VAL(RIGHT_CALF_X_ROTATE), -VAL(RIGHT_CALF_Y_ROTATE), -VAL(RIGHT_CALF_Z_ROTATE));
	if (level >= 3) {
		if (isAdjust) {
			// Draw cylinder leg
			glRotated(13, 1.0, 0.0, 0.0);
			glTranslated(0.0, 0.0, 1.0);
			drawCylinder(2, 0.3, 0.3);
			glTranslated(0.0, 0.0, -1.0);
			glRotated(-13, 1.0, 0.0, 0.0);
		}
		else {
			// Draw triangular leg
			Model::drawLeftLowerLeg();
		}
	}

	glRotated(-2, 1.0, 0.0, 0.0);
	glTranslated(0, -0.9, 3.65);
	setDiffuseColor(COLOR_RED);
	if (level >= 4) {
		drawSphere(0.3f);
	}
	glTranslated(0, 0, 0.75);
	setDiffuseColor(COLOR_GREEN);
	/***here can add X Y Z rotation and counted as "right ankle roation"***/
	glTranslated(0, 0, -0.75);
	this->rotate(VAL(RIGHT_FOOT_X_ROTATE), -VAL(RIGHT_FOOT_Y_ROTATE), -VAL(RIGHT_FOOT_Z_ROTATE));
	glTranslated(0, 0, 0.75);
	if (level >= 4) {
		Model::drawLeftFoot();
	}
	glPopMatrix();

	glPopMatrix();

	endDraw();
}