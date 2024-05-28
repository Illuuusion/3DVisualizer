#include "figure.h"

Figure::Figure(std::vector<Vertex> vertices, std::vector<Edge> edges): vertices(vertices), edges(edges){}

std::vector<Vertex> Figure::getVertices(){
    return vertices;
}

std::vector<Edge> Figure::getEdges(){
    return edges;
}

void Figure::transformMatrix(TransformMatrix matrix){
    for (auto& el : vertices) el.transformPoint(matrix);
    for (auto& el : edges) el.transformEdge(matrix);
}
