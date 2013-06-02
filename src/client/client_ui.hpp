#ifndef CLIENT_UI_H
#define CLIENT_UI_H

#include <QMainWindow>
#include <QPixmap>
#include "client.hpp"
#include "../common/Config.hpp"

#include <QPainter>
#include <cmath>
#include <QScrollArea>
#include <QAction>
#include <QLabel>
#include <QScrollBar>
#include <QMessageBox>
#include <QImage>
#include <QMenu>

namespace Ui
{
    class Client_UI;
}


class Client_UI : public QMainWindow
{
    Q_OBJECT

    public:

        Client_UI(common::Config *config, QMainWindow *parent = 0);
        ~Client_UI();

    private slots:

        void updatePixmap(const QImage &image);
        void updatePopCre(int update);
        void updatePopHer(int update);
        void updatePopPre(int update);
        void zoomIn();
        void zoomOut();
        void normalSize();
        void about();

    private:

        void createActions();
        void createMenus();
        void scaleImage(double factor);
        void adjustScrollBar(QScrollBar *scrollBar, double factor);

        common::Config  *config;
        Ui::Client_UI   *ui;
        client::Client  *client_thread;
        QPixmap         *pixmap;
        QLabel          *imageLabel;
        QImage          *image;

        QAction         *exitAct;
        QAction         *zoomInAct;
        QAction         *zoomOutAct;
        QAction         *normalSizeAct;
        QAction         *aboutAct;
        QAction         *aboutQtAct;
        double          scaleFactor;

        QMenu           *viewMenu;
        QMenu           *helpMenu;
        QMenu           *fileMenu;
};

#endif // CLIENT_UI_H
