#include "OpenGL/Demo.h"
#include <iostream>

int main()
{
    try
    {
        OpenGL::Demo demo;
        demo.run();
    }
    catch (const std::exception& exception)
    {
        std::cerr << "Exception: " << exception.what();
        std::cin.get();
    }
}
