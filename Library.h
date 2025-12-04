#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <vector>
#include "Book.h"
#include "Member.h"
#include "Loan.h"
#include <vector>
#include <algorithm>


class Library{
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Loan> loans;

    public:

    void addBook(const Book& b){books.push_back(b);}
    void addMember(const Member& m){ members.push_back(m);}


    bool hasBook(const std::string& isbn) const{
        return std::any_of(books.begin(), books.end(),
            [&](const Book& b) { return b.getIsbn() == isbn; });

    }


     bool isBookAvailable(const std::string& isbn) const {
        return std::none_of(loans.begin(), loans.end(),
            [&](const Loan& l) {
                return l.isOverdue("9999-99-99") == false && 
                       !l.isOverdue("0000-00-00") &&     
                       l.to_string().find(isbn) != std::string::npos; 
            });
    }


     bool loanBook(const std::string& isbn,
                  const std::string& memberId,
                  const std::string& start,
                  const std::string& due)
    {
        if (!hasBook(isbn)) return false;


         bool memberFound = std::any_of(members.begin(), members.end(),
            [&](const Member& m){ return m.to_string().find(memberId) != std::string::npos; });
        if (!memberFound) return false;

        
        if (!isBookAvailable(isbn)) return false;

        loans.emplace_back(isbn, memberId, start, due, false);
        return true;
    }




     bool returnBook(const std::string& isbn, const std::string& memberId) {
        for (auto& l : loans) {
            if (l.to_string().find(isbn) != std::string::npos &&
                l.to_string().find(memberId) != std::string::npos)
            {
                l.markReturned();
                return true;
            }
        }
        return false;
    }





    std::vector<Book> findByAuthor(const std::string& authorName) const {
        std::vector<Book> result;

        for (const auto& b : books) {
            if (b.getAuthor().getName() == authorName) {
                result.push_back(b);
            }
        }
        return result;
    }
 




    std::string to_string() const {
        return "\nTotal book: " + std::to_string(books.size()) +
        "\nTotal members: " + std::to_string(members.size()) +
        "\nTotal loans: " + std::to_string(loans.size());
    }


};



