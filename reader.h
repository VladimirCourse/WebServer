#ifndef READER_H
#define READER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include "requestprocessor.h"
#include "htmlparser.h"

//класс-читатель сокета
class Reader: public QObject{
    Q_OBJECT

private:
    RequestProcessor m_processor;
    HtmlParser m_htmlParser;
    QString tryRequest(QString req);

public:
    Reader(QObject *parent = 0);
    ~Reader(){}

public slots:
    void read();
    void disconnect();
};



#endif // READER_H
