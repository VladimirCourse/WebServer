#include "mainwindow.h"
#include <QApplication>
#include "listener.h"
#include "datastorage.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    DataStorage storage;
    MainWindow w;
    w.show();
    //создания объекта листенера, который сразу начинает слушать локалхост
    Listener *listener = new Listener(QHostAddress::LocalHost, 80, &w);
    return a.exec();
}
