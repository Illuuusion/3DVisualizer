#ifndef SCENE_H
#define SCENE_H

#include "figure.h"

class Scene
{
private:
    std::vector<Figure> figures;
public:
    Scene() = default;
    Scene(Figure figure);
    Scene(std::vector<Figure> figures);
    std::vector<Figure> getFigures();
    void addFigure(Figure figure);
    void transformFigures(TransformMatrix matrix);
};

#endif // SCENE_H
