 
#include <thread> // c++11
#include <mutex>  // c++11
 
#include "client/client.hpp"
#include "init/init.hpp"
#include "server/server.hpp"

int main()
{
  Config *config = new Config();
  
  init::main(config); // nie musimy wolac tego jako osobnego watku
  
  Map *map = new Map(config->map_width, config->map_height); // ta struktura zawiera wszystkie dane gry
  
  std::mutex *mutex = new std::mutex; // mutex do synchronizacji
    
  std::thread client_thread(bind(client::main, mutex, map, config));
  std::thread server_thread(bind(server::main, mutex, map, config));
  
  client_thread.join();
  server_thread.join();
  
  delete map;
  delete mutex;
  delete config;
  
  return 0;
}