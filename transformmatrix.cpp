#include "transformmatrix.h"

TransformMatrix::TransformMatrix(QMatrix4x4 matrix): matrix(matrix){}

TransformMatrix::TransformMatrix(Point point){
    matrix = QMatrix4x4(point.x, 0, 0, 0,
                        point.y, 0, 0, 0,
                        point.z, 0, 0, 0,
                        1, 0, 0, 0);
}

TransformMatrix TransformMatrix::operator*(TransformMatrix matr){
    return matr.matrix*matrix;
}

float TransformMatrix::getElem(int row, int column){
    return matrix(row, column);
}
