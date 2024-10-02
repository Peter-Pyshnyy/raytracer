#include <iostream>
#include "vec3.h"
#include "ray.h"
#include "color.h"

bool hit_sphere(ray& r, point3& p) {
    vec3 a = r.direction() * r.direction();
    //vec3 b = -2*r.direction()*
}

color ray_color(ray& r) {
    vec3 norm = normalized(r.direction());
    float t = (norm.y() + 1) / 2; // interpolates -1 -> 1 to 0 -> 2 and then to 0 -> 1
    //std::clog << norm.y() << '\n' << std::flush;
    return (1 - t)* color(1., 1., 1.) + t * color(.2, .4, .85); //lerp
}

int main(){
    int img_width = 400;
    double aspect_ratio = 16. / 9.;
    int img_height = int(img_width / aspect_ratio);
    img_height = (img_height < 1) ? 1 : img_height;

    auto vp_height = 2.0; //viewport
    auto vp_width = vp_height * double(img_width) / img_height;
    auto focal_length = 1.;
    vec3 vp_u(vp_width, 0, 0);
    vec3 vp_v(0, -vp_height, 0);
    vec3 vp_delta_u = vp_u / float(img_width); //PROBLEM WITH VECTOR DIVISION
    vec3 vp_delta_v = vp_v / float(img_height);
    point3 camera_center(0, 0, 0);
    auto left_upper_corner = camera_center - vec3(0, 0, focal_length) - (vp_u / 2) - (vp_v / 2);
    point3 vp_pos00 = left_upper_corner + (vp_delta_u / 2) + (vp_delta_v / 2);

    std::cout << "P3\n" << img_width << ' ' << img_height << "\n255 \n";

    for (int i = 0; i < img_height; i++) {
        std::clog << (100 * i / img_height) << "% \n" << std::flush;
        for (int j = 0; j < img_width; j++) {
            vec3 pixel_center = vp_pos00 + float(i) * vp_delta_v + float(j) * vp_delta_u;
            ray ray_direction = ray(camera_center, pixel_center);
            color col = ray_color(ray_direction);
            set_pixel(std::cout, col);
        }
    }

    std::clog << "done! \n";
}

