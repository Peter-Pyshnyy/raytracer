#pragma once
#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
	point3 orig;
	vec3 dir;
public:
	ray(){}
	ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

	const point3& origin() {
		return orig;
	}

	const vec3& direction() {
		return dir;
	}

	point3 at(float t) {
		return orig + dir * t;
	}
};

#endif // !RAY_H
