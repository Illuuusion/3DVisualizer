#ifndef TRANSFORMMATRIXBUILDER_H
#define TRANSFORMMATRIXBUILDER_H

#include "transformmatrix.h"

class TransformMatrixBuilder{
public:
    static TransformMatrix createRotationXMatrix(float angle);
    static TransformMatrix createRotationYMatrix(float angle);
    static TransformMatrix createRotationZMatrix(float angle);
    static TransformMatrix createMoveMatrix(float x, float y, float z);
    static TransformMatrix createScaleMatrix(float x, float y, float z);
};

#endif // TRANSFORMMATRIXBUILDER_H
