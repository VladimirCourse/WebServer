#ifndef HTMLPARSER_H
#define HTMLPARSER_H

#include <QString>
#include <QRegExp>
#include <QDebug>
#include "datastorage.h"

class HtmlParser{
public:
    HtmlParser();
    QString parseHtml(QString page);
private:
    typedef QString (HtmlParser::*ParseFunc)(QString);
    QMap <QString, ParseFunc> m_regTags;
    QString bookListTag(QString tag);
    QString bookInfoTag(QString tag);
    QString authorListTag(QString tag);
    QString authorInfoTag(QString tag);
    QString authorListBoxTag(QString tag);
    QString createBookLinks(QString authorId = "");
    QString getIdFromTag(QString tag);
    QString createLink(QString link, QString title);
};


#endif // HTMLPARSER_H
