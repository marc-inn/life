#include <iostream>
#include <mutex>
#include <thread> // c++11
#include <chrono> // c++11

#include "../include.hpp"
#include "client_ui.hpp"
#include "../common/Map.hpp"

namespace client
{
    int run(std::mutex *mutex, common::Map *map, Client_UI *client_UI);
    // tutaj deklaracje jakichs klas uzytych w kliencie, np.
    // class GameWindow;
}
