#include "mainwindow.h"
#include <QApplication>
#include "listener.h"
#include "datastorage.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    DataStorage storage;
    MainWindow w;
    w.show();
    Listener *listener = new Listener(QHostAddress::LocalHost, 80, &w);
    return a.exec();
}
