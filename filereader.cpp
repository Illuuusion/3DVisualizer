#include "filereader.h"
#include "QDebug"

Point FileReader::parsePoint(std::string strPoint){
    std::vector<float> result ;
    size_t pos = 0 ;
    size_t size = strPoint.size() ;
    size_t prevPos = 0 ;
    while (pos < size){
        prevPos = pos ;
        if ((pos=strPoint.find_first_of(',',pos)) == std::string::npos ){
            result.push_back(std::stof(strPoint.substr(prevPos)));
            break ;
        }
        else result.push_back(std::stof(strPoint.substr(prevPos,pos-prevPos)));
        ++pos;
    }
    if (result.size() < 3)
        while (result.size() != 3)
            result.push_back(0);
    return Point(result);
}

Edge FileReader::parseEdge(std::string strEdge, std::vector<Vertex> vertices){
    std::vector<int> result ;
    size_t pos = 0 ;
    size_t size = strEdge.size() ;
    size_t prevPos = 0 ;
    while (pos < size){
        prevPos = pos ;
        if ((pos=strEdge.find_first_of(',',pos)) == std::string::npos ){
            result.push_back(std::stoi(strEdge.substr(prevPos)));
            break ;
        }
        else result.push_back(std::stoi(strEdge.substr(prevPos,pos-prevPos)));
        ++pos;
    }
    return Edge(vertices[result[0] - 1], vertices[result[1] - 1]);
}

std::vector<Figure> FileReader::readScene(std::string &path){
    std::ifstream inStream(path);
    int countPoints = 0;
    int countEdges = 0;
    if (!inStream.is_open()) throw std::exception();
    std::string line;
    std::getline(inStream, line);
    if (checkNumber(line))
        countPoints = std::stoi(line);
    std::getline(inStream, line);
    if (checkNumber(line))
        countEdges = std::stoi(line);
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    std::vector<Figure> figures;
    for (int j = 0; j < countPoints; ++j){
        std::getline(inStream, line);
        if (!line.empty()){
            Vertex vertex(parsePoint(line));
            vertices.push_back(vertex);
        }
    }
    for (int j = 0; j < countEdges; ++j){
        std::getline(inStream, line);
        if (!line.empty()){
            Edge edge = parseEdge(line, vertices);
            edges.push_back(edge);
        }
    }
    Figure figure(vertices, edges);
    figures.push_back(figure);
    return figures;
}

bool FileReader::checkNumber(std::string line){
    return !line.empty() && (line.find_first_not_of("0123456789") == line.npos);
}
