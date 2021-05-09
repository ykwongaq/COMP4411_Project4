#pragma once

#include "curveevaluator.h"

class CatmullRomCurveEvaluator : public CurveEvaluator {
public:
	void evaluateCurve(const std::vector<Point> &control_points,
						std::vector<Point> &evaluated_curve_points,
						const float &animation_length,
						const bool &wrap_control_points) const override;
};