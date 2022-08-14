#include "glm/vec2.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& stream, glm::vec2 vec)
{
    return stream << "x: " << vec.x << " x: " << vec.y;
}

int main()
{
    glm::vec2 vec = {2.0f, 5.0f};
    std::cout << vec;
    std::cin.get();
}
