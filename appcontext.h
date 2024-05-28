#ifndef APPCONTEXT_H
#define APPCONTEXT_H

#include <string>
#include "scene.h"


struct AppContext{
    std::string file;
    std::vector<Figure> scene;
};


#endif // APPCONTEXT_H
