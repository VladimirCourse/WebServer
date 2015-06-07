#include "listener.h"

Listener::Listener(const QHostAddress &address, const quint16 port, QObject *parent): QTcpServer(parent){
    listen(address, port);
}

void Listener::incomingConnection(int socket){
    QSslSocket* s = new QSslSocket(this);
    Reader *reader = new Reader(s);
    //abc
    connect(s, SIGNAL(encrypted()), reader, SLOT(read()));
    s->startServerEncryption();
    connect(s, SIGNAL(disconnected()), reader, SLOT(disconnect()));
    s->setSocketDescriptor(socket);
}


