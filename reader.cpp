#include "reader.h"
#include "datastorage.h"

Reader::Reader(QObject *parent): QObject(parent){

}
//чтение запроса
void Reader::read(){
    QTcpSocket* socket = (QTcpSocket*)sender();
    QString data;
    if(socket->bytesAvailable()){
        data = QString(socket->readAll());
        //разделяем построчно запрос
        QStringList socketContent = data.split("\n");
        //разделяем первую стоку на пробелы
        QStringList headContent = socketContent[0].split(" ");
        //строка с ответом
        QString answer = "HTTP/1.0 200 Ok\r\n"
                "Content-Type: text/html; charset=\"utf-8\"\r\n"
                "\r\n" ;
        //если гет запрос
        if (headContent[0] == "GET"){
            //если страница есть в списке страниц, парсим и возвращаем
            if (DataStorage::pages.contains(headContent[1])){
                answer += m_htmlParser.parseHtml(DataStorage::pages[headContent[1]]);
            }else{
                //если страницы нет в списке страниц, проверяем, является ли это каким-то гет-запросом
                answer += m_processor.processRequest(headContent[1]);
            }
        }else{
            //пытаемся найти запрос и дать ответ, в socketContent в последней строке находятся параметы запроса
            answer += m_processor.processRequest(headContent[1] + "?" + socketContent.last());
        }
        //вывод ответа в сокет
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
