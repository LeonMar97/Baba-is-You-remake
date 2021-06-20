#include <SFML/Graphics.hpp>
#include <fstream>
#include "Animation.h"
#include "Resources.h"
#include "Controller.h"
#include "Menu.h"

int main()
{
    auto file = std::fstream("log.txt", std::fstream::out);
    try {
        Menu m;
        m.activate();
    }
    catch(std::exception& e){
        file << e.what();
        file.flush();
    }
}
