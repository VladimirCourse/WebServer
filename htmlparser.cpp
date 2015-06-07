#include "htmlparser.h"

HtmlParser::HtmlParser(){
    m_regTags["<\\s*booklist((\\s*)|(\\s+authorid\\s*=\\s*\\d+)?)\\s*>"] = &HtmlParser::bookListTag;
    m_regTags["<\\s*bookinfo\\s+bookid\\s*=\\s*\\d+\\s*>"] = &HtmlParser::bookInfoTag;
    m_regTags["<\\s*authorlistbox\\s*>"] = &HtmlParser::authorListBoxTag;
    m_regTags["<\\s*authorlist\\s*>"] = &HtmlParser::authorListTag;
    m_regTags["<\\s*authorinfo\\s+authorid\\s*=\\s*\\d+\\s*>"] = &HtmlParser::authorInfoTag;
}

QString HtmlParser::parseHtml(QString page){
    QMap <QString, ParseFunc>::iterator it;
    for (it = m_regTags.begin(); it != m_regTags.end(); it++){
        QRegExp exp(it.key());
        int pos = exp.indexIn(page);
        while(pos != -1){
            QString replaceTag = (this->*(*it))(exp.cap());
            page.replace(pos, exp.matchedLength(), replaceTag);
            pos = exp.indexIn(page);
        }
    }
    return page;
}

QString HtmlParser::createLink(QString link, QString title){
    return "<a href = \"/" + link + "\">" + title + "</a>";
}

QString HtmlParser::getIdFromTag(QString tag){
    tag.replace(" ", "");
    int pos = tag.indexOf("=");
    if (pos != -1){
        int end = tag.indexOf(">");
        return  tag.mid(pos + 1, end - pos -1);
    }
    return "";
}

QString HtmlParser::createBookLinks(QString authorId){
    QString links;
    QMap <QString, Book>::iterator it;
    for (it = DataStorage::books.begin(); it != DataStorage::books.end(); it++){
        if (it->author == authorId || authorId == ""){
            links +=  createLink("getBookInfo?id=" + it.key(), it->title) + "<br>";
        }
    }
    return links;
}

QString HtmlParser::bookListTag(QString tag){
    QString authorId = getIdFromTag(tag);
    return createBookLinks(authorId);
}

QString HtmlParser::bookInfoTag(QString tag){
    QString id = getIdFromTag(tag);
    Book book = DataStorage::books[id];
    QString parsedTag;
    parsedTag += "Titile: " + book.title + "<br>";
    parsedTag += "Year: " + book.year + "<br>";
    parsedTag += "Publisher: " + book.publisher + "<br>";
    parsedTag += createLink ("getAuthorInfo?id=" + book.author, "View author info")  + "<br>";
    return parsedTag;
}

QString HtmlParser::authorListTag(QString tag){
    QString links;
    QMap <QString, Author>::iterator it;
    for (it = DataStorage::authors.begin(); it != DataStorage::authors.end(); it++){
            links +=  createLink("getAuthorInfo?id=" + it.key(), it->firstName) + "<br>";
    }
    return links;
}

QString HtmlParser::authorInfoTag(QString tag){
    QString id = getIdFromTag(tag);
    Author author = DataStorage::authors[id];
    QString parsedTag;
    parsedTag += "First name: " + author.firstName + "<br>";
    parsedTag += "Last lane: " + author.lastName + "<br>";
    parsedTag += "Born year: " + author.bornYear + "<br>";
    parsedTag += parseHtml("<booklist authorid = " + id + ">");
    return parsedTag;
}

QString HtmlParser::authorListBoxTag(QString tag){
    QString parsedTag = "<select name=\"author\" >";
    QMap <QString, Author>::iterator it;
    for (it = DataStorage::authors.begin(); it != DataStorage::authors.end(); it++){
        parsedTag +=  "<option value = \"" + it.key() + "\">" + it->firstName + "</option>";
    }
    parsedTag +=   "</select>";
    return parsedTag;
}
