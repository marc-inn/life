#include "client.hpp" 
 
int client::main(std::mutex *mutex, Map *map, Config *config)
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