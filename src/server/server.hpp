

#include <mutex> // c++11
#include <iostream>
#include <thread> // c++11
#include <chrono> // c++11


#include <QThread>
#include "../common/Config.hpp"
#include "../common/Map.hpp"
#include "MapGenerator.hpp"
#include "SimulationVisitor.hpp"

namespace server
{
    class Server : public QThread
    {
        Q_OBJECT

    public:
        Server(common::Config *config, QObject *parent = 0);

    protected:
        void run();

    private:
        common::Config *config;

    };
}
