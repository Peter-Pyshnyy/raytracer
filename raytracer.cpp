#include <iostream>
#include "vec3.h"
#include "color.h"

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
    vec3 vp_delta_u = vp_u / img_width;
    vec3 vp_delta_v = vp_v / img_height;
    point3 camera_center(0, 0, 0);
    auto left_upper_corner = camera_center - vec3(0, 0, focal_length) - (vp_u / 2) - (vp_v / 2);
    point3 vp_pos00 = left_upper_corner + (vp_delta_u / 2) + (vp_delta_v / 2);

    std::cout << "P3\n" << img_width << ' ' << img_height << "\n255 \n";

    for (int i = 0; i < img_height; i++) {
        std::clog << (100 * i / img_height) << "% \n" << std::flush;
        for (int j = 0; j < img_width; j++) {
            float wt = float(i) / float(img_width - 1);
            float ht = float(j) / float(img_height - 1);
            color col(0.5, 0.5, 1);
            set_pixel(std::cout, col);
        }
    }

    std::clog << "done! \n";
}