#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>

class Loan{
    std::string isbn;
    std::string memberId;
    std::string startDate;
    std::string dueDate;
    bool returned;

    public:

    Loan(std::string i,
    std::string mi,
    std::string sd,
    std::string dd,
    bool r) : isbn(i), memberId(mi), startDate(sd), dueDate(dd), returned(r) {
        if (dueDate < startDate) {
        throw std::invalid_argument("due date cannot be lower than start date");
        }
    }


    void markReturned(){
        returned = true;
    }

    bool isOverdue(const std::string& today) const {
        return !returned && today > dueDate;
    }

    std::string to_string() const {
        return "isbn: " + isbn +
        "Member Id: " + memberId + 
        "Start date: " + startDate +
        "Returned: " + std::to_string(returned);
    }

    

};
