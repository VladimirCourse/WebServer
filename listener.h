#ifndef LISTENER_H
#define LISTENER_H

#include "reader.h"

class Listener: public QTcpServer{

public:
    Listener(const QHostAddress & address, const quint16 port, QObject *parent = 0);
    void incomingConnection(int socket);
};

#endif // LISTENER_H
