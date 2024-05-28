#include "transformmatrixbuilder.h"

TransformMatrix TransformMatrixBuilder::createRotationXMatrix(float angle){
    QMatrix4x4 matr = QMatrix4x4(1, 0, 0, 0,
                                 0, cos(angle), sin(angle), 0,
                                 0, -sin(angle), cos(angle), 0,
                                 0, 0, 0, 1);
    return TransformMatrix(matr);
}

TransformMatrix TransformMatrixBuilder::createRotationYMatrix(float angle){
    QMatrix4x4 matr = QMatrix4x4(cos(angle), 0, -sin(angle), 0,
                                 0, 1, 0, 0,
                                 sin(angle), 0, cos(angle), 0,
                                 0, 0, 0, 1);
    return TransformMatrix(matr);
}

TransformMatrix TransformMatrixBuilder::createRotationZMatrix(float angle){
    QMatrix4x4 matr = QMatrix4x4(cos(angle), sin(angle), 0, 0,
                                 -sin(angle), cos(angle), 0, 0,
                                 0, 0, 1, 0,
                                 0, 0, 0, 1);
    return TransformMatrix(matr);
}

TransformMatrix TransformMatrixBuilder::createMoveMatrix(float x, float y, float z){
    QMatrix4x4 matr = QMatrix4x4(1, 0, 0, x,
                                 0, 1, 0, y,
                                 0, 0, 1, z,
                                 0, 0, 0, 1);
    return TransformMatrix(matr);
}

TransformMatrix TransformMatrixBuilder::createScaleMatrix(float x, float y, float z){
    QMatrix4x4 matr = QMatrix4x4(x, 0, 0, 0,
                                 0, y, 0, 0,
                                 0, 0, z, 0,
                                 0, 0, 0, 1);
    return TransformMatrix(matr);
}
