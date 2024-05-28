#ifndef FIGURE_H
#define FIGURE_H

#include "edge.h"
#include "vertex.h"

class Figure
{
private:
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
public:
    Figure(std::vector<Vertex> vertices, std::vector<Edge> edges);
    std::vector<Vertex> getVertices();
    std::vector<Edge> getEdges();
    void transformMatrix(TransformMatrix matrix);
};

#endif // FIGURE_H
