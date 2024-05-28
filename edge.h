#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"


class Edge
{
private:
    Vertex begin;
    Vertex end;
public:
    explicit Edge(Vertex begin, Vertex end);
    Vertex& getBegin();
    Vertex& getEnd();
    void transformEdge(TransformMatrix matrix);
};

#endif // EDGE_HFigure
