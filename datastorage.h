#ifndef DATASTORAGE_H
#define DATASTORAGE_H


#include <QMap>
#include <QString>

//структура книги, в качестве автора идет его id
struct Book{
    QString title;
    QString author;
    QString year;
    QString publisher;
};
//структура автора
struct Author{
    QString firstName;
    QString lastName;
    QString bornYear;
};
//класс-хранитель html-страниц, книг и авторов
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
