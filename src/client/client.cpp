#include "client.hpp" 
 
void client::run(std::mutex *mutex, common::Map *map, common::Config *config)
{
    std::cout << "Jestem klientem!\n" << std::endl;
    
    for(int i = 0;; ++i) // nieskonczona petla
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(820));
        
        mutex->lock();
            std::cout <<"klient czyta plansze, liczba obiektow: " << map->countObjects() << std::endl;
        mutex->unlock();
    }
}