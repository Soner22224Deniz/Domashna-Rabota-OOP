#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include "Author.h"

class Book{
    std::string title;
    Author author;
    int year;
    double price;
    std::string isbn;
    static int totalBooks;

    public:

    Book() = default;
    Book(std::string t, Author a, int y, double p, std::string i) : title(t), author(a), year(y), price(p), isbn(i) {}
    Book(const Book& other) = default;
    Book(Book&& other) = default;
    ~Book() = default;

    std::string getTitle() const {return title;}
    Author getAuthor() const {return author;}
    int getYear() const {return year;}
    std::string getIsbn() const {return isbn;}

    void setTitle(std::string t){
        title = t;
    }

    void setAuthor(Author a){
        author = a;
    }

    void setYear(int y){
        if(y >= 1850 && y <= 2025){
            year = y;
        }
    }

    void setPrice(double p){
        if(p >= 0){
            price = p;
        } 
    }

    std::string to_string() const{
        return "Title: " + title + " " + "Year: " 
        + std::to_string(year) + " " + "Price: " + std::to_string(price) + " " + "Isbn: " 
        + isbn + " " + "TotalBooks : " + std::to_string(totalBooks);
    }
    
    static int getTotalBooks() {return totalBooks;}

};


inline int Book::totalBooks = 0;