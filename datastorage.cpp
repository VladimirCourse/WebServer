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
//тут можно добавлять книги, если надо
void DataStorage::initBooks(){

}
//тут можно добавлять авторов
void DataStorage::initAuthors(){

}
//инициализация страниц
void DataStorage::initPages(){
    //главная страница
    pages["/"] =
            "<div align = \"center\">"
            "<h1> Library </h2>"
            "<a href = \"/add_book\"> Add book </a> <br>"
            "<a href = \"/add_author\"> Add author </a> "
            "<h2> List of all books </h2>"
            "<booklist> "
            "<h2> List of all authors </h2>"
            "<authorlist>"
            "</div>";
    //страница с формой добавления автора
    pages["/add_author"] =
            "<div align = \"center\">"
            "<a href = \"/\"> Home page </a> "
            "<h1> Add author </h2>"
            "<form method = \"post\" action=\"addAuthor\">"
            "<p>Input</p>"
            "<p><input type=\"text\" name=\"fname\" placeholder = \"First name\"></p>"
            "<p><input type=\"text\" name=\"lname\" placeholder = \"Last name\"></p>"
            "<p><input type=\"text\" name=\"bornyear\" placeholder = \"Born year\"></p>"
            "<p><input type=\"submit\" value=\"Add\"></p>"
            "</form>"
            "</div>";
    //страница с формой добавления книги
    pages["/add_book"] =
            "<div align = \"center\">"
            "<a href = \"/\"> Home page </a> "
            "<h1> Add book </h2>"
            "<form method = \"post\" action=\"addBook\">"
            "<p>Input</p>"
            "<p><input type=\"text\" name=\"title\" placeholder = \"Titile\"></p>"
            "<p><input type=\"text\" name=\"publilsher\" placeholder = \"Publisher\"></p>"
            "<p><input type=\"text\" name=\"year\" placeholder = \"Year\"></p>"
            "<p> <authorlistbox> </p>"
            "<p><input type=\"submit\" value=\"Add\"></p>"
            "</form>"
            "</div>";
    //страница с информацией о книге
    hiddenPages["/book_info"] =
            "<div align = \"center\">"
            "<a href = \"/\"> Home page </a> "
            "<h1> Book information </h1>"
            "<bookinfo bookid = id_rep>"
            "</div>";
    //страница с информацией об авторе
    hiddenPages["/author_info"] =
            "<div align = \"center\">"
            "<a href = \"/\"> Home page </a> "
            "<h1> Author information </h1>"
            "<authorinfo authorid = id_rep>"
            "</div>";
}
