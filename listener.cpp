#include "listener.h"

Listener::Listener(const QHostAddress &address, const quint16 port, QObject *parent): QTcpServer(parent){
    listen(address, port);
}
//создание сокета для каждого нового соединения
void Listener::incomingConnection(int socket){
    QTcpSocket* s = new QTcpSocket(this);
    Reader *r = new Reader(s);
    connect(s, SIGNAL(readyRead()), r, SLOT(read()));
    connect(s, SIGNAL(disconnected()), r, SLOT(disconnect()));
    s->setSocketDescriptor(socket);
}


