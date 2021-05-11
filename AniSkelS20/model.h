#pragma once
#ifndef MODEL_H
#define MODEL_H

#include <FL/gl.h>
#include <GL/glu.h>

#include "vec.h"
#include "modelerview.h"
#include "mat.h"
#include <vector>

// To make a Model, we inherit off of ModelerView
class Model : public ModelerView {

public:
	Model(int x, int y, int w, int h, char* label);

	virtual void draw();

	// Functions drawing different part of the model
	void drawUpperBody();
	void drawHead();
	void drawHorn();
	void drawLeftUpperArm();
	void drawLeftLowerArm();
	void drawRightUpperArm();
	void drawRightLowerArm();
	void drawLowerBody();
	void drawRightUpperLeg();
	void drawRightLowerLeg();
	void drawRightFoot();
	void drawLeftUpperLeg();
	void drawLeftLowerLeg();
	void drawLeftFoot();
	std::vector<char> gsentence1(const int stage);// left wings
	std::vector<char> gsentence2(const int stage); // right wings
	void drawLsystem(const std::vector<char>& sentence, int option);

	// Angle rotated in each flame in animation
	static int LEFT_SHOULDER_MOVEMENT;
	static int RIGHT_SHOULDER_MOVEMENT;
	static int LEFT_LEG_MOVEMENT;
	static int RIGHT_LEG_MOVEMENT;
	static int HEAD_MOVEMENT;

	// Max angle of rotate of different parts of body
	const static int LEFT_SHOULDER_X_ROTATE_MAX = 68;
	const static int LEFT_SHOULDER_X_ROTATE_MIN = -52;
	const static int RIGHT_SHOULDER_X_ROTATE_MAX = 68;
	const static int RIGHT_SHOULDER_X_ROTATE_MIN = -52;
	const static int LEFT_LEG_X_ROTATE_MAX = 85;
	const static int LEFT_LEG_X_ROTATE_MIN = -35;
	const static int RIGHT_LEG_X_ROTATE_MAX = 85;
	const static int RIGHT_LEG_X_ROTATE_MIN = -35;
	const static int HEAD_Z_ROTATE_MAX = 20;
	const static int HEAD_Z_ROTATE_MIN = -20;

private:

	unsigned char* textureImg;
	int textImgWidth;
	int textImgHeight;
	GLuint tex;
	bool firstTime;

	Vec3f segment1Start;
	Vec3f segment1End;
	Vec3f segment2Start;
	Vec3f segment2End;

	float alpha, beta;

	float l1, l2;

	void rotate(const double& x, const double& y, const double& z);	// Rotate the body
	void back_rotate(const double& x, const double& y, const double& z); // Back rotate the body
	void prepare_texture();
	float calAngle(Vec3f v1, Vec3f v2);
	float rad(float degree);
	float deg(float rad);
	//Mat4f getRMatrix(float angle);
	void drawAxis();
	void drawArmVector();
	void printArmVector();
	Vec3f rotateVectorX(Vec3f v, Vec3f offset, float angle);
	void drawVector(Vec3f v);
	void drawLine(Vec3f v1, Vec3f v2);
	Vec3f rotateVectorX(Vec3f v, float angle);
	float calAngleWithDir(Vec3f v1, Vec3f v2);
};

#endif