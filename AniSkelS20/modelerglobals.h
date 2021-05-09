#ifndef _MODELER_GLOBALS_H
#define _MODELER_GLOBALS_H

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502
#endif

// This is a list of the controls for the SampleModel
// We'll use these constants to access the values 
// of the controls from the user interface.
enum SampleModelControls {
	// Whole body controls
	XPOS, YPOS, ZPOS, HEIGHT,
	// Head controls
	HEAD_X_ROTATE, HEAD_Y_ROTATE, HEAD_Z_ROTATE,
	// ------------------------------------- Upper Body Controls -------------------------------------
	// Left shoulder controls
	LEFT_SHOULDER_X_ROTATE, LEFT_SHOULDER_Y_ROTATE, LEFT_SHOULDER_Z_ROTATE,
	// Left elbow controls
	LEFT_ELBOW_X_ROTATE, LEFT_ELBOW_Y_ROTATE, LEFT_ELBOW_Z_ROTATE,
	// Left wrist controls
	LEFT_WRIST_X_ROTATE, LEFT_WRIST_Y_ROTATE, LEFT_WRIST_Z_ROTATE,
	// Right shoulder controls
	RIGHT_SHOULDER_X_ROTATE, RIGHT_SHOULDER_Y_ROTATE, RIGHT_SHOULDER_Z_ROTATE,
	// Right elbow controls
	RIGHT_ELBOW_X_ROTATE, RIGHT_ELBOW_Y_ROTATE, RIGHT_ELBOW_Z_ROTATE,
	// Right wrist controls
	RIGHT_WRIST_X_ROTATE, RIGHT_WRIST_Y_ROTATE, RIGHT_WRIST_Z_ROTATE,
	// Upper body controls 
	WHOLE_UPPER_BODY_ROTATE, PICKING,
	// ------------------------------------- Lower Body Controls -------------------------------------
	// Left leg controls
	LEFT_LEG_X_ROTATE, LEFT_LEG_Y_ROTATE, LEFT_LEG_Z_ROTATE,
	// Left calf controls
	LEFT_CALF_X_ROTATE, LEFT_CALF_Y_ROTATE, LEFT_CALF_Z_ROTATE,
	// Left foot controls
	LEFT_FOOT_X_ROTATE, LEFT_FOOT_Y_ROTATE, LEFT_FOOT_Z_ROTATE,
	// Right leg controls
	RIGHT_LEG_X_ROTATE, RIGHT_LEG_Y_ROTATE, RIGHT_LEG_Z_ROTATE,
	// Right calf controls
	RIGHT_CALF_X_ROTATE, RIGHT_CALF_Y_ROTATE, RIGHT_CALF_Z_ROTATE,
	// Right foot controls
	RIGHT_FOOT_X_ROTATE, RIGHT_FOOT_Y_ROTATE, RIGHT_FOOT_Z_ROTATE,
	// ------------------------------------- Bonus Controls -------------------------------------
	// Light position controls
	LIGHT_X_POS, LIGHT_Y_POS, LIGHT_Z_POS,
	// Light intensity controls
	LIGHT_INTENSITY,
	// Animation
	ANIMATION,
	// Adjustment on body,
	ADJUST_BODY,
	// Frame all
	FRAME_ALL,
	// Enable texture mapping
	TEXTURE_MAPPING,
	// Level Control
	LEVEL_CONTROL,
	// L System Control
	LSYSTEM_SWITCH,
	LSYSTEM_STAGE,
	WING_FIRST_ROTATION,
	// Met ball Control
	METABALL,
	METABALL_RESOLUTION,
	METABALL_FIRST_ROTATION,
	METABALL_SECOND_ROTATION,
	METABALL_LENGTH,
	METABALL_MERGE,
	// Mood Control
	SAD_MOOD,
	// IK System
	IK_ENABLE, IK_POS, ARM_CONSTRAIN,
	// Number of controls
	NUMCONTROLS
};

// Colors
#define COLOR_RED		1.0f, 0.0f, 0.0f
#define COLOR_GREEN		0.0f, 1.0f, 0.0f
#define COLOR_BLUE		0.0f, 0.0f, 1.0f
#define COLOR_WHITE		1.0f, 1.0f, 1.0f

// We'll be getting the instance of the application a lot; 
// might as well have it as a macro.
#define VAL(x) (ModelerApplication::Instance()->GetControlValue(x))
//#define double rad(double deg) {return deg * 180 / M_PI;}
#endif