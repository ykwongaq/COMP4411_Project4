#include "catmullromcurveevaluator.h"
#include "mat.h"
#include "vec.h"

#define SEGMENT 30

void CatmullRomCurveEvaluator::evaluateCurve(const std::vector<Point> &control_points, std::vector<Point> &evaluated_curve_points, const float &animation_length, const bool &wrap_control_points) const {
	
	evaluated_curve_points.clear();

	const Mat4d M = Mat4d(
		-1, 3, -3, 1,
		2, -5, 4, -1,
		-1, 0, 1, 0,
		0, 2, 0, 0) / 2.0;

	std::vector<Point> control_points_copy;

	if (wrap_control_points) 	{
		control_points_copy.push_back(Point((control_points.end() - 2)->x - animation_length, (control_points.end() - 2)->y));
		control_points_copy.push_back(Point((control_points.end() - 1)->x - animation_length, (control_points.end() - 1)->y));
		control_points_copy.insert(control_points_copy.end(), control_points.begin(), control_points.end());
		control_points_copy.push_back(Point((control_points.begin())->x + animation_length, (control_points.begin())->y));
		control_points_copy.push_back(Point((control_points.begin() + 1)->x + animation_length, (control_points.begin() + 1)->y));
	} 	else 	{
		control_points_copy.assign(control_points.begin(), control_points.end());
		control_points_copy.push_back(Point(control_points.front().x + animation_length, control_points.front().y));
		control_points_copy.insert(control_points_copy.begin(), Point(control_points.back().x - animation_length, control_points.back().y));
	}

	for (int i = 0; i < ((int) control_points_copy.size() - 3); ++i) 	{
		Vec4d XVec = Vec4d(control_points_copy[i].x, control_points_copy[i + 1].x,
			control_points_copy[i + 2].x, control_points_copy[i + 3].x);
		Vec4d YVec = Vec4d(control_points_copy[i].y, control_points_copy[i + 1].y,
			control_points_copy[i + 2].y, control_points_copy[i + 3].y);
		std::vector<Point> evalPts;
		for (int j = 1; j < SEGMENT; ++j) 		{
			double t = j / (double) SEGMENT;
			Vec4d TVec = Vec4d(t * t * t, t * t, t, 1);
			Point eval_pt = Point((float) (TVec * M * XVec), (float) (TVec * M * YVec));
			if (eval_pt.x > control_points_copy[i + 1].x && eval_pt.x < control_points_copy[i + 2].x
				&& (evalPts.empty() || eval_pt.x > evalPts.back().x))
				evalPts.push_back(eval_pt);
		}
		evaluated_curve_points.push_back(control_points_copy[i + 1]);
		evaluated_curve_points.insert(evaluated_curve_points.end(), evalPts.begin(), evalPts.end());
		evaluated_curve_points.push_back(control_points_copy[i + 2]);
	}

	if (!wrap_control_points) 	{
		evaluated_curve_points.push_back(Point(0, control_points.front().y));
		evaluated_curve_points.push_back(Point(animation_length, control_points.back().y));
	}
}
