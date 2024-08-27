#pragma once
#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <array>
#include <cmath>

class vec3 {
	std::array<float, 3> e;
public:
	vec3(float X = 0, float Y = 0, float Z = 0);
	float x() const;
	float y() const;
	float z() const;
	float length() const;

	vec3 operator+(const vec3& v) const;
	vec3 operator-(const vec3& v) const;
	vec3 operator*(const vec3& v) const;
	vec3 operator/(const vec3& v) const;
	vec3 operator*(float n) const;
	vec3 operator-() const;
	vec3& operator+=(const vec3& v);
	vec3& operator-=(const vec3& v);
	vec3& operator*=(const vec3 & v);
	vec3& operator*=(float n);
	vec3& operator/=(float n);
	friend std::ostream& operator<<(std::ostream& out, const vec3& v);
	friend vec3 operator*(float n, const vec3& v);
};

inline float dot(const vec3& v1, const vec3& v2) {
	return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
}

inline vec3 cross(const vec3& v1, const vec3& v2) {
	float x = v1.y() * v2.z() - v2.y() * v1.z();
	float y = v1.z() * v2.x() - v2.z() * v1.x();
	float z = v1.x() * v2.y() - v2.x() * v1.y();
	
	return vec3(x,y,z);
}

inline float angle(const vec3& v1, const vec3& v2) {
	return std::acos(dot(v1, v2) / (v1.length() * v2.length()));
}

inline vec3 normalized(const vec3& v) {
	return v / v.length();
}

using point3 = vec3;

#endif