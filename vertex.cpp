#include "vertex.h"

Vertex::Vertex(Point point): position(point){}

Point Vertex::getVertex(){
    return position;
}

void Vertex::transformPoint(TransformMatrix matrix){
    TransformMatrix pointMatrix = TransformMatrix(position);
    pointMatrix = pointMatrix * matrix;
    position = {pointMatrix.getElem(0, 0), pointMatrix.getElem(1, 0), pointMatrix.getElem(2, 0)};
}
