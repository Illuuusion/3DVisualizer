#include "edge.h"

Edge::Edge(Vertex begin, Vertex end): begin(begin), end(end){}

Vertex& Edge::getBegin(){
    return begin;
}

Vertex& Edge::getEnd(){
    return end;
}

void Edge::transformEdge(TransformMatrix matrix){
    begin.transformPoint(matrix);
    end.transformPoint(matrix);
}
