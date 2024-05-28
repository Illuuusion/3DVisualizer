#ifndef FACADE_H
#define FACADE_H

#include "filereader.h"
#include "qtscenedrawer.h"

class Facade
{
public:
    Facade() = default;
    bool show(AppContext* context);
};

#endif // FACADE_H
