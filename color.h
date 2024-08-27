#pragma once
#ifndef COLOR_H
#define COLOR_H
#include "vec3.h"
#include <iostream>

using color = vec3;

void set_pixel(std::ostream& COUT, color& col) {
    int ir = int(col.x() * 255.999);
    int ig = int(col.y() * 255.999);
    int ib = int(col.z() * 255.999);

    COUT << ir << ' ' << ig << ' ' << ib << '\n';
}

#endif