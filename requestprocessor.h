#ifndef REQUESTPROCESSOR_H
#define REQUESTPROCESSOR_H

#include <QString>
#include "datastorage.h"
#include "htmlparser.h"

//класс-обработчик запросов
class RequestProcessor{

public:
    RequestProcessor();
    QString processRequest(QString req);

private:
    HtmlParser m_htmlParser;
    typedef QString (RequestProcessor::*ReqFunc)(QString);
    QMap <QString, ReqFunc> m_requests;
    QString getBookInfo(QString req);
    QString addBook(QString req);
    QString getAuthorInfo(QString req);
    QString addAuthor(QString req);
    QString replacedIdPage(QString pagename, QString id);
    QVector <QString> getParamValues(QStringList params);
};

#endif // REQUESTPROCESSOR_H
