#include "beziercurveevaluator.h"
#include "mat.h"
#include "vec.h"

#define SEGMENT 20

void BezierCurveEvaluator::evaluateCurve(const std::vector<Point> &control_points, std::vector<Point> &evaluated_curve_points, const float &animation_length, const bool &wrap_control_points) const {
	evaluated_curve_points.clear();

	const Mat4d M(
		-1, 3, -3, 1,
		3, -6, 3, 0,
		-3, 3, 0, 0,
		1, 0, 0, 0);

	std::vector<Point> control_points_copy(control_points);
	if (wrap_control_points) 	{
		control_points_copy.push_back(Point(control_points.front().x + animation_length, control_points.front().y));
		control_points_copy.insert(control_points_copy.begin(), Point(control_points.back().x - animation_length, control_points.back().y));
	}

	int i;

	bool is_wrapped = false;

	for (i = 0; i < ((int) control_points_copy.size() - 3); i += 3) 	{
		Vec4d XVec(control_points_copy[i].x, control_points_copy[i + 1].x, control_points_copy[i + 2].x, control_points_copy[i + 3].x);
		Vec4d YVec(control_points_copy[i].y, control_points_copy[i + 1].y,
			control_points_copy[i + 2].y, control_points_copy[i + 3].y);
		for (int j = 0; j < SEGMENT; ++j) 		{
			double t = j / (double) SEGMENT;
			Vec4d TVec(t * t * t, t * t, t, 1);
			Point eval_pt((float) (TVec * M * XVec), (float) (TVec * M * YVec));
			if (eval_pt.x > animation_length && wrap_control_points) 			{
				float x_mod = eval_pt.x - animation_length;
				if (!is_wrapped) 				{
					Point prev_pt(evaluated_curve_points.back());
					float mid_pt_y = (eval_pt.y * (animation_length - prev_pt.x) + prev_pt.y * (eval_pt.x - animation_length))
						/ (eval_pt.x - prev_pt.x);
					evaluated_curve_points.push_back(Point(0, mid_pt_y));
					evaluated_curve_points.push_back(Point(animation_length, mid_pt_y));
					is_wrapped = true;
				}
				eval_pt.x = x_mod;
			}
			evaluated_curve_points.push_back(eval_pt);
		}
		evaluated_curve_points.push_back(control_points_copy[i + 3]);
	}

	for (; i < (int) control_points.size(); i++) evaluated_curve_points.push_back(control_points[i]);
	if (!wrap_control_points) 	{
		evaluated_curve_points.push_back(Point(0, control_points.front().y));
		evaluated_curve_points.push_back(Point(animation_length, control_points.back().y));
	} 	else if (!is_wrapped) 	{
		float mid_y = (control_points.back().y * control_points.front().x
			+ control_points.front().y * (animation_length - control_points.back().x))
			/ (control_points.front().x + animation_length - control_points.back().x);
		evaluated_curve_points.push_back(Point(0, mid_y));
		evaluated_curve_points.push_back(Point(animation_length, mid_y));
	}
}
