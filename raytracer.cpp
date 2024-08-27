#include <iostream>
#include "vec3.h"

int main(){
    vec3 v1(3,3,5);
    vec3 v2(0, 1, 0);

    std::cout << v1*v2;


    /*int width = 256;
    int height = 256;

    std::cout << "P3\n" << width << ' ' << height << "\n255 \n";

    for (int i = 0; i < height; i++) {
        std::clog << (100 * i / height) << "% \n" << std::flush;
        for (int j = 0; j < width; j++) {
            double wt = double(i) / double(width - 1);
            double ht = double(j) / double(height - 1);

            int ir = int(wt * 255.999);
            int ig = int(ht * 255.999);
            int ib = int(std::fmax(wt/2,ht) * 255.999);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    std::clog << "done! \n";*/
}