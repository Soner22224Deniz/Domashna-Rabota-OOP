#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include "Author.h"


class Member {
    std::string name;
    std::string memberId;
    int yearJoined;

    public:

    Member() = default;
    Member(std::string n, std::string mi, int yj) : name(n), memberId(mi), yearJoined(yj) {}

    void validate() const {
        if (memberId.empty()) {
            throw std::invalid_argument("memberId не може да бъде празен!");
        }
    }


    std::string to_string() const {
        return "Name: " + name + ", ID: " + memberId + ", Year joined: " + std::to_string(yearJoined);
    }


};