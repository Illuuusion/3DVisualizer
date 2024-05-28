#ifndef POINT_H
#define POINT_H

#include <vector>

struct Point{
    float x, y, z;
    Point(float x, float y, float z): x(x), y(y), z(z){}
    Point(std::vector<float> vector){
        x = vector[0];
        y = vector[1];
        z = vector[2];
    }
};

#endif // 3DPOINT_H
