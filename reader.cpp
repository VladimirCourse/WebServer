#include "reader.h"
#include "datastorage.h"

Reader::Reader(QObject *parent): QObject(parent){

}

void Reader::read(){
    QSslSocket * socket = (QSslSocket *)sender();
    QString data;
    if(socket->bytesAvailable()){
        data = QString(socket->readAll());
        QStringList socketContent = data.split("\n");
        QStringList headContent = socketContent[0].split(" ");
        QString answer = "HTTP/1.0 200 Ok\r\n"
                "Content-Type: text/html; charset=\"utf-8\"\r\n"
                "\r\n" ;
        if (headContent[0] == "GET"){
            if (DataStorage::pages.contains(headContent[1])){
                answer += m_htmlParser.parseHtml(DataStorage::pages[headContent[1]]);
            }else{
                answer += m_processor.processRequest(headContent[1]);
            }
        }else{
            answer += m_processor.processRequest(headContent[1] + "?" + socketContent.last());
        }
        QTextStream os(socket);
        os.setAutoDetectUnicode(true);
        os << answer;
        socket->close();
        if (socket->state() == QTcpSocket::UnconnectedState) {
            delete socket;
        }
    }
}

void Reader::disconnect(){
    QTcpSocket* socket = (QTcpSocket*)sender();
    socket->deleteLater();
}
