#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>

class Author{

    std::string name;
    int birthYear;

    public:

    Author() : name("Unknown"), birthYear(1900){}
    Author(std::string n, int by) : name(n), birthYear(by){}


    std::string to_string() const{
        return "Name: " + name + " " + "BirthYear: " + std::to_string(birthYear);
    }

    std::string getName() const {return name;}
    int getBirthYear() const {return birthYear;}


    void setBirthYear(int by){
        if (birthYear >= 1850 && birthYear <= 2025){
            birthYear = by;
    }

}

};