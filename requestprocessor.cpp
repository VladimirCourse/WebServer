#include "requestprocessor.h"
#include <QDebug>

RequestProcessor::RequestProcessor(){
    m_requests["/getBookInfo"] = &RequestProcessor::getBookInfo;
    m_requests["/addBook"] = &RequestProcessor::addBook;
    m_requests["/addAuthor"] = &RequestProcessor::addAuthor;
    m_requests["/getAuthorInfo"] = &RequestProcessor::getAuthorInfo;
}

QString RequestProcessor::processRequest(QString req){
    QStringList reqContent = req.split("?");
    QString reqType;
    reqType = reqContent[0];
    if (m_requests.contains(reqType) && reqContent.size() > 1){
        return  (this->*m_requests[reqType])(reqContent[1]);
    }else{
        return "WRONG REQUEST";
    }
}

QVector <QString> RequestProcessor::getParamValues(QStringList params){
    QStringList::iterator it;
    QVector <QString> paramValues;
    for (it = params.begin(); it != params.end(); it++){
        paramValues.push_back(it->split("=").last());
    }
    return paramValues;
}

QString RequestProcessor::addBook(QString req){
    Book book;
    QVector <QString> paramValues = getParamValues(req.split("&"));
    book.title =paramValues[0];
    book.publisher = paramValues[1];
    book.year = paramValues[2];
    book.author = paramValues[3];
    QString bookId = QString::number(DataStorage::books.size() + 1);
    DataStorage::books[bookId] = book;
    return req;
}

QString RequestProcessor::addAuthor(QString req){
    Author author;
    QVector <QString> paramValues = getParamValues(req.split("&"));
    author.firstName = paramValues[0];
    author.lastName = paramValues[1];
    author.bornYear = paramValues[2];
    QString authorId = QString::number(DataStorage::authors.size() + 1);
    DataStorage::authors[authorId] = author;
    return req;
}

QString RequestProcessor::replacedIdPage(QString pagename, QString id){
    QString page = DataStorage::hiddenPages[pagename];
    page.replace("id_rep", id);
    return page;
}

QString RequestProcessor::getBookInfo(QString req){
    return m_htmlParser.parseHtml(replacedIdPage("/book_info", req.split("=").last()));
}

QString RequestProcessor::getAuthorInfo(QString req){
    return m_htmlParser.parseHtml(replacedIdPage("/author_info", req.split("=").last()));
}
