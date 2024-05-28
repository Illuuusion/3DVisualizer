#ifndef TRANSFORMMATRIX_H
#define TRANSFORMMATRIX_H

#include <cmath>
#include "QMatrix4x4"
#include "point.h"


class TransformMatrix{
private:
    QMatrix4x4 matrix;
public:
    TransformMatrix(Point point);
    TransformMatrix(QMatrix4x4 matrix);
    TransformMatrix operator*(TransformMatrix matr);
    float getElem(int row, int column);
};

#endif // TRANSFORMMATRIX_H
