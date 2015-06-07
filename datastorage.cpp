#include "datastorage.h"
#include <QDebug>

QMap <QString, QString> DataStorage::pages;
QMap <QString, QString> DataStorage::hiddenPages;
QMap <QString, Book> DataStorage::books;
QMap <QString, Author> DataStorage::authors;

DataStorage::DataStorage(){
    initPages();
    initBooks();
    initAuthors();
}

void DataStorage::initBooks(){
    Book b;
    b.author = "1";
    b.publisher = "Publ";
    b.title = "Ssss";
    b.year = "1992";
    books["1"] = b;
}

void DataStorage::initAuthors(){
    Author aut;
    aut.firstName = "Vasiliy";
    aut.lastName = "Petrov";
    aut.bornYear = "1984";
    authors["1"] = aut;
}

void DataStorage::initPages(){
    pages["/"] = "<div align = \"center\">"
            "<h1> List of all books </h1>"
            "<booklist> "
            "<h1> List of all authors </h1>"
            "<authorlist>"
            "</div>";
    pages["/add_author"] = "<form method = \"post\" action=\"addAuthor\">"
            "<p>Input</p>"
            "<p><input type=\"text\" name=\"fname\" placeholder = \"First name\"></p>"
            "<p><input type=\"text\" name=\"lname\" placeholder = \Last name\"></p>"
            "<p><input type=\"text\" name=\"bornyear\" placeholder = \"ear\"></p>"
            "<p><input type=\"submit\" value=\"Add\"></p>"
            "</form>";
    pages["/add_book"] =  "<form method = \"post\" action=\"addBook\">"
            "<p>Input</p>"
            "<p><input type=\"text\" name=\"title\" placeholder = \"Titile\"></p>"
            "<p><input type=\"text\" name=\"publilsher\" placeholder = \Publisher\"></p>"
            "<p><input type=\"text\" name=\"year\" placeholder = \"Year\"></p>"
            "<p> <authorlistbox> </p>"
            "<p><input type=\"submit\" value=\"Add\"></p>"
            "</form>";
    hiddenPages["/book_info"] = "<h1> Book information </h1>"
            "<bookinfo bookid = id_rep>";
    hiddenPages["/author_info"] = "<h1> Author information </h1>"
            "<authorinfo authorid = id_rep>";
}
