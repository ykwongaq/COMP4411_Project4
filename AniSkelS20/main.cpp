#include "modelerapp.h"
#include "modelerglobals.h"
#include "model.h"

// We need to make a creator function, mostly because of
// nasty API stuff that we'd rather stay away from.
ModelerView *createSampleModel(int x, int y, int w, int h, char *label) {
	return new Model(x, y, w, h, label);
}

int main() {
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
	ModelerControl controls[NUMCONTROLS];

	// --------------------------------- Whole Body Controls ---------------------------------
	controls[XPOS] = ModelerControl("X Position", -5, 5, 0.1f, 0);
	controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
	controls[ZPOS] = ModelerControl("Z Position", -5, 5, 0.1f, 0);
	controls[HEIGHT] = ModelerControl("Height", -0.4, 0.4, 0.01f, 0);
	controls[WHOLE_UPPER_BODY_ROTATE] = ModelerControl("Whole Upper Body Rotate", -180, 180, 1, 0);
	// --------------------------------- Upper Body Controls ---------------------------------
	// Head controls
	controls[HEAD_X_ROTATE] = ModelerControl("Head X Rotate", -70, 30, 1, 0);
	controls[HEAD_Y_ROTATE] = ModelerControl("Head Y Rotate", -60, 60, 1, 0);
	controls[HEAD_Z_ROTATE] = ModelerControl("Head Z Rotate", -80, 80, 1, 0);
	// Left shoulder controls
	controls[LEFT_SHOULDER_X_ROTATE] = ModelerControl("Left Shoulder X Rotate", -180, 180, 1, 8);
	controls[LEFT_SHOULDER_Y_ROTATE] = ModelerControl("Left Shoulder Y Rotate", -30, 170, 1, 0);
	controls[LEFT_SHOULDER_Z_ROTATE] = ModelerControl("Left Shoulder Z Rotate", -100, 100, 1, 0);
	// Left elbow controls
	controls[LEFT_ELBOW_X_ROTATE] = ModelerControl("Left Albow X Rotate", -135, 10, 1, -10);
	controls[LEFT_ELBOW_Y_ROTATE] = ModelerControl("Left Albow Y Rotate", -135, 20, 1, 0);
	controls[LEFT_ELBOW_Z_ROTATE] = ModelerControl("Left Albow Z Rotate", -130, 130, 1, 0);
	// Left wrist controls
	controls[LEFT_WRIST_X_ROTATE] = ModelerControl("Left Wrist X Rotate", -50, 50, 1, -5);
	controls[LEFT_WRIST_Y_ROTATE] = ModelerControl("Left Wrist Y Rotate", -120, 90, 1, 0);
	controls[LEFT_WRIST_Z_ROTATE] = ModelerControl("Left Wrist Z Rotate", -130, 130, 1, 0);
	// Right shoulder controls
	controls[RIGHT_SHOULDER_X_ROTATE] = ModelerControl("Right Shoulder X Rotate", -180, 180, 1, -8);
	controls[RIGHT_SHOULDER_Y_ROTATE] = ModelerControl("Right Shoulder Y Rotate", -30, 170, 1, 0);
	controls[RIGHT_SHOULDER_Z_ROTATE] = ModelerControl("Right Shoulder Z Rotate", -100, 100, 1, 0);
	// Right elbow controls
	controls[RIGHT_ELBOW_X_ROTATE] = ModelerControl("Right Albow X Rotate", -135, 10, 1, -10);
	controls[RIGHT_ELBOW_Y_ROTATE] = ModelerControl("Right Albow Y Rotate", -135, 20, 1, 0);
	controls[RIGHT_ELBOW_Z_ROTATE] = ModelerControl("Right Albow Z Rotate", -130, 130, 1, 0);
	// Right wrist controls
	controls[RIGHT_WRIST_X_ROTATE] = ModelerControl("Right Wrist X Rotate", -50, 50, 1, 5);
	controls[RIGHT_WRIST_Y_ROTATE] = ModelerControl("Right Wrist Y Rotate", -120, 90, 1, 0);
	controls[RIGHT_WRIST_Z_ROTATE] = ModelerControl("Right Wrist Z Rotate", -130, 130, 1, 0);
	// Picking control
	controls[PICKING] = ModelerControl("Picking", -100, 0, 1, 0);
	// --------------------------------- Lower Body Controls ---------------------------------
	// Left leg controls 
	controls[LEFT_LEG_X_ROTATE] = ModelerControl("Left Leg X Rotate", -100, 85, 1, 25);
	controls[LEFT_LEG_Y_ROTATE] = ModelerControl("Left Leg Y Rotate", -40, 10, 1, -20);
	controls[LEFT_LEG_Z_ROTATE] = ModelerControl("Left Leg Z Rotate", -20, 20, 1, 0);
	// Left calf controls
	controls[LEFT_CALF_X_ROTATE] = ModelerControl("Left Calf X Rotate", -20, 100, 1, 2);
	controls[LEFT_CALF_Y_ROTATE] = ModelerControl("Left Calf Y Rotate", -10, 10, 1, 0);
	controls[LEFT_CALF_Z_ROTATE] = ModelerControl("Left Calf Z Rotate", -20, 20, 1, 0);
	// Left foot controls
	controls[LEFT_FOOT_X_ROTATE] = ModelerControl("Left Foot X Rotate", -5, 60, 1, 0);
	controls[LEFT_FOOT_Y_ROTATE] = ModelerControl("Left Foot Y Rotate", -20, 20, 1, 0);
	controls[LEFT_FOOT_Z_ROTATE] = ModelerControl("Left Foot Z Rotate", -20, 20, 1, 18);
	// Right leg controls
	controls[RIGHT_LEG_X_ROTATE] = ModelerControl("Right Leg X Rotate", -100, 85, 1, 25);
	controls[RIGHT_LEG_Y_ROTATE] = ModelerControl("Right Leg Y Rotate", -10, 40, 1, 20);
	controls[RIGHT_LEG_Z_ROTATE] = ModelerControl("Right Leg Z Rotate", -20, 20, 1, 0);
	// Right calf controls
	controls[RIGHT_CALF_X_ROTATE] = ModelerControl("Right Calf X Rotate", -20, 100, 1, 2);
	controls[RIGHT_CALF_Y_ROTATE] = ModelerControl("Right Calf Y Rotate", -10, 10, 1, 0);
	controls[RIGHT_CALF_Z_ROTATE] = ModelerControl("Right Calf Z Rotate", -20, 20, 1, 0);
	// Right foot controls
	controls[RIGHT_FOOT_X_ROTATE] = ModelerControl("Right Foot X Rotate", -5, 60, 1, 0);
	controls[RIGHT_FOOT_Y_ROTATE] = ModelerControl("Right Foot Y Rotate", -20, 20, 1, 0);
	controls[RIGHT_FOOT_Z_ROTATE] = ModelerControl("Right Foot Z Rotate", -20, 20, 1, -18);
	// --------------------------------- Bonus Controls ---------------------------------
	// Light position controls
	controls[LIGHT_X_POS] = ModelerControl("Light X Position", -70, 70, 1, 4);
	controls[LIGHT_Y_POS] = ModelerControl("Light Y Position", -70, 70, 1, 2);
	controls[LIGHT_Z_POS] = ModelerControl("Light Z Position", -70, 70, 1, -4);
	// Light intensity control
	controls[LIGHT_INTENSITY] = ModelerControl("Light Intensity", 0, 5, 0.01, 0.5);
	// Animation
	controls[ANIMATION] = ModelerControl("Animation", 0, 1, 1, 0);
	// Adjustment on body
	controls[ADJUST_BODY] = ModelerControl("Adjust Body?", 0, 1, 1, 0);
	// Frame all
	controls[FRAME_ALL] = ModelerControl("Frame All", 0, 1, 1, 0);
	// Texture mapping
	controls[TEXTURE_MAPPING] = ModelerControl("Texture Mapping", 0, 1, 1, 0);
	// Level Control	
	controls[LEVEL_CONTROL] = ModelerControl("Level Control", 0, 4, 1, 4);
	// L system control
	controls[LSYSTEM_SWITCH] = ModelerControl("Display Tree", 0, 1, 1, 0);
	controls[LSYSTEM_STAGE] = ModelerControl("LSystem Stage", 1, 6, 1, 3);
	controls[WING_FIRST_ROTATION] = ModelerControl("Wings Rotation", -10, 20, 1, 0);
	// For meta ball
	controls[METABALL] = ModelerControl("Enable metaball", 0, 1, 1, 0);
	controls[METABALL_RESOLUTION] = ModelerControl("Metaball Resolution", 0.05, 0.3, 0.01, 0.15);
	controls[METABALL_FIRST_ROTATION] = ModelerControl("Metaball First Rotation", -180, 180, 1, 0);
	controls[METABALL_SECOND_ROTATION] = ModelerControl("Metaball Second Rotation", -180, 180, 1, 0);
	controls[METABALL_LENGTH] = ModelerControl("Metaball length", 1, 4.5, 0.5, 3.5);
	controls[METABALL_MERGE] = ModelerControl("Metaball Merge", 0.25, 1, 0.01, 0.54);
	// Mood Control
	controls[SAD_MOOD] = ModelerControl("Sad Mood", 0, 1, 1, 0);
	// IK System
	controls[IK_ENABLE] = ModelerControl("Enable IK System", 0, 1, 1, 0);
	controls[IK_POS] = ModelerControl("IK X POS", -5, 5, 0.01, 4.5);
	controls[ARM_CONSTRAIN] = ModelerControl("ARM Constrain", 10, 180, 1, 180);

	ModelerApplication::Instance()->Init(&createSampleModel, controls, NUMCONTROLS); // Use the controls array to create the appropriate sliders.
	return ModelerApplication::Instance()->Run();	// Run the application.
}