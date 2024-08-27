#include "vec3.h"
#include <iostream>
#include <array>
#include <cmath>

vec3::vec3(float X, float Y, float Z) : e{ X, Y, Z } {}

float vec3::x() const {
	return e[0];
}

float vec3::y() const {
	return e[1];
}

float vec3::z() const {
	return e[2];
}

float vec3::length() const {
	return std::sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
}

vec3 vec3::operator+(const vec3& v) const {
	return vec3(e[0] + v.e[0], e[1] + v.e[1], e[2] + v.e[2]);
}

vec3 vec3::operator-(const vec3& v) const {
	return vec3(e[0] - v.e[0], e[1] - v.e[1], e[2] - v.e[2]);
}

vec3 vec3::operator*(const vec3& v) const {
	return vec3(e[0] * v.e[0], e[1] * v.e[1], e[2] * v.e[2]);
}

vec3 vec3::operator/(const vec3& v) const {
	return vec3(e[0] / v.e[0], e[1] / v.e[1], e[2] / v.e[2]);
}

vec3 vec3::operator*(float n) const {
	vec3 result;
	result.e[0] = e[0] * n;
	result.e[1] = e[1] * n;
	result.e[2] = e[2] * n;

	return result;
}

vec3 vec3::operator-() const{
	return vec3(-e[0], -e[1], -e[2]);
}

vec3& vec3::operator+=(const vec3& v) {
	e[0] += v.e[0];
	e[1] += v.e[1];
	e[2] += v.e[2];
	return *this;
}

vec3& vec3::operator-=(const vec3& v) {
	e[0] -= v.e[0];
	e[1] -= v.e[1];
	e[2] -= v.e[2];
	return *this;
}

vec3& vec3::operator*= (const vec3 & v){
	e[0] *= v.e[0];
	e[1] *= v.e[1];
	e[2] *= v.e[2];
	return *this;
}

vec3& vec3::operator*=(float n) {
	e[0] *= n;
	e[1] *= n;
	e[2] *= n;
	return *this;
}

vec3& vec3::operator/=(float n) {
	e[0] /= n;
	e[1] /= n;
	e[2] /= n;
	return *this;
}

std::ostream& operator<<(std::ostream& COUT, const vec3& v) {
	COUT << '(' << v.x() << ", " << v.y() << ", " << v.z() << ')';
	return COUT;
}  

vec3 operator*(float n, const vec3& v) {
	return v * n;
}