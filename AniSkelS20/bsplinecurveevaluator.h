#pragma once

#include "curveevaluator.h"

class BSplineCurveEvaluator : public CurveEvaluator {
public:
	// Only need to implement the evaluateCurve function
	void evaluateCurve(const std::vector<Point> &control_points, std::vector<Point> &evaluated_curve_points, const float &animation_length, const bool &wrap_control_points) const override;
};
