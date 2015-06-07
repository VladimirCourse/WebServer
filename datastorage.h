#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <QMap>
#include <QString>

struct Book{
    QString title;
    QString author;
    QString year;
    QString publisher;
};

struct Author{
    QString firstName;
    QString lastName;
    QString bornYear;
};

class DataStorage{
public:
    static QMap <QString, Book> books;
    static QMap <QString, Author> authors;
    static QMap <QString, QString> pages;
    static QMap <QString, QString> hiddenPages;
    DataStorage();
private:
    void initBooks();
    void initPages();
    void initAuthors();
};

#endif //DATASTORAGE_H
