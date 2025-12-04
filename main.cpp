#include <iostream>
#include "Library.h"
using namespace std;

int main() {
    Library lib;

 
    Author a1("Иван Вазов", 1850);
    Author a2("Елин Пелин", 1877);

    Book b1("Под игото", a1, 1894, 30.89, "ISBN-001");
    Book b2("Немили-недраги", a1, 1900, 17.50, "ISBN-002");
    Book b3("Гераците", a2, 1907, 23.67, "ISBN-003");

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);

   
    lib.addMember(Member("Петър Петров", "M001", 2023));
    lib.addMember(Member("Мария Иванова", "M002", 2022));

    cout << lib.to_string() << "\n";

   
    if (lib.loanBook("ISBN-001", "M001", "2025-12-01", "2025-12-15"))
        cout << "Loan created for ISBN-001.\n";
    if (lib.loanBook("ISBN-003", "M002", "2025-12-02", "2025-12-16"))
        cout << "Loan created for ISBN-003.\n";

    cout << "Members, Books and Loans now: " << lib.to_string() << " " << endl;
    cout << endl;
 

    
    cout << "Available ISBN-001? " << boolalpha
         << lib.isBookAvailable("ISBN-001") << "\n";

    
    lib.returnBook("ISBN-001", "M001");
    cout << "Is ISBN-001 Available after return? " << boolalpha
         << lib.isBookAvailable("ISBN-001") << "\n";

   
    cout << "Books by Иван Вазов:\n";
    for (const auto& bk : lib.findByAuthor("Иван Вазов"))
        cout << bk.to_string() << "\n";

    return 0;
}
