#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include "scene.h"

class FileReader
{
private:
    Point parsePoint(std::string strPoint);
    Edge parseEdge(std::string strEdge, std::vector<Vertex> vertices);
    bool checkNumber(std::string line);
public:
    FileReader() = default;
    std::vector<Figure> readScene(std::string& path);
};

#endif // FILEREADER_H
