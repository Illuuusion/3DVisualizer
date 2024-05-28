#include "facade.h"

bool Facade::show(AppContext* context)
{
    bool check = false;
    FileReader reader;
    context->scene = reader.readScene(context->file);
    if (context->scene.size())
        check = true;
    return check;
}
