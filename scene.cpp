#include "scene.h"

Scene::Scene(Figure figure)
{
    figures.push_back(figure);
}

Scene::Scene(std::vector<Figure> figures): figures(figures){}

std::vector<Figure> Scene::getFigures(){
    return figures;
}

void Scene::addFigure(Figure figure){
    figures.push_back(figure);
}

void Scene::transformFigures(TransformMatrix matrix){
    for (auto& el: figures) el.transformMatrix(matrix);
}
