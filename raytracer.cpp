#include <iostream>
#include "vec3.h"
#include "color.h"

int main(){
    int width = 256;
    int height = 256;

    std::cout << "P3\n" << width << ' ' << height << "\n255 \n";

    for (int i = 0; i < height; i++) {
        std::clog << (100 * i / height) << "% \n" << std::flush;
        for (int j = 0; j < width; j++) {
            float wt = float(i) / float(width - 1);
            float ht = float(j) / float(height - 1);
            color col(wt, ht, 1-ht);
            set_pixel(std::cout, col);
        }
    }

    std::clog << "done! \n";
}