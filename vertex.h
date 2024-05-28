#ifndef VERTEX_H
#define VERTEX_H

#include "transformmatrix.h"

class Vertex
{
private:
    Point position;
public:
    Vertex(Point point);
    Point getVertex();
    void transformPoint(TransformMatrix matrix);
};

#endif // VERTEX_H
