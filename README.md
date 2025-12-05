Проект: Мини "Библиотечна система"(Library System)

<br>


Описание: <br>
Проектът мини "Библиотечна система" представлява С++ система,която моделира работа с книги,читатели и заеми,съставена е от 5 взаимосвързани класа.Той представя прилагането на основни ООП принципи в С++ : <br> <br>


• конструктори и деструктори <br>
• капсулация <br>
• работене със статични членове <br>
• използване на const методи , валидация на данни <br>
• Прилагане на принципите на "Rule of 3-5" <br>


Структура на проекта:




LibrarySystem/ <br>
├── Author.h <br>
├── Book.h <br>
├── Member.h <br>
├── Loan.h <br>
├── Member.h <br>
├── image.png <br>
├── README.md <br>
└── main.cpp <br>







Компилация и изпълнение: <br>


Отворете терминал в директорията LibrarySystem/ и изпълнете: <br>

g++ -std=c++17 -Wall -Wextra -O2 main.cpp -o main <br>

След това стартирайте програмата: <br>

./main <br>

Примерен изход от програмата:  <br>


Total book: 3 <br>
Total members: 2 <br>
Total loans: 0 <br>
<br>
Loan created for ISBN-001. <br>
Loan created for ISBN-003. <br>
<br>
Members and loans now: <br> <br>
Total book: 3 <br>
Total members: 2 <br>
Total loans: 2 <br>
<br>
Available ISBN-001? true <br>
Is ISBN-001 Available after return? false <br>
Books by Иван Вазов: <br>
Title: Под игото Year: 1894 Price: 30.890000 Isbn: ISBN-001 TotalBooks: 0 <br>
Title: Немили-недраги Year: 1900 Price: 17.500000 Isbn: ISBN-002 TotalBooks: 0 <br>
<br>
<br>



Класове: 



Author

<br>
Членове: <br>
*std::string name - Име на автор <br>
*int birthYear - Година на раждане на автор <br>

<br>


Методи: <br>
* Author() : name("Unknown"), birthYear(1900){} - конструктор по подразбиране
* Author(std::string n, int by) : name(n), birthYear(by){} - параметризиран конструктор със списък за инициализация
* to_string - Връща текстово описание на обекта
* getName() - Връща име на автор
* get BirthYear() - Връща година на раждане
* setBirthYear() - Задава година на раждане


<br>
<br>  





Book
<br>




Членове: <br>
* std::string title - Име на книга
* Author author - Обект от тип Автор
* int year - година на издаване
* double price - цена
* std::string isbn - код на книга
* static int totalBooks - статичен член(тотален брой книги)
<br>
  

Методи: <br>
* Book() – конструктор по подразбиране
* Book(t,a,y,p,i) – параметризиран конструктор със списък за инициализация
* Book(const Book&) – копи-конструктор
* Book(Book&&) – move конструктор
* ~Book() – деструктор
* getTitle() – връща заглавие
* getAuthor() – връща автор
* getYear() – връща година
* getIsbn() – връща ISBN
* setTitle() – задава заглавие
* setAuthor() – задава автор
* setYear() – задава година
* setPrice() – задава цена
* to_string() – текстово описание
* getTotalBooks() – връща брой книги
<br>
<br>





Member
<br>


Членове: <br>
* std::string name – име на член
* std::string memberId – идентификатор на член
* int yearJoined – година на присъединяване

  
<br>


Методи: <br>
* Member() – конструктор по подразбиране
* Member(n,mi,yj) – параметризиран конструктор със списък за инициализация
* validate() – проверка на данни
* to_string() – текстово описание



<br>
<br>


  
  

Loan
<br>


Членове: <br>
* std::string isbn – ISBN код
* std::string memberId – ID на член
* std::string startDate – дата на заемане
* std::string dueDate – дата за връщане
* bool returned – статус върнато
<br>  

Методи: <br>
* Loan(i,mi,sd,dd,r) – параметризиран конструктор
* markReturned() – отбелязва върнато
* isOverdue() – проверка за просрочие
* to_string() – текстово описание
<br>
<br>




Library
<br>


Членове: <br>
* std::vector<Book> books – списък книги
* std::vector<Member> members – списък членове
* std::vector<Loan> loans – списък заеми
<br>  

Методи: <br>
* addBook() – добавя книга
* addMember() – добавя член
* hasBook() – проверява наличност
* isBookAvailable() – проверява свободна книга
* loanBook() – създава заем
* returnBook() – връща книга
* findByAuthor() – намира по автор
* to_string() – обобщена информация
<br>
<br>



Екранна снимка: <br>

<br>

<img width="995" height="491" alt="image" src="https://github.com/user-attachments/assets/97207d79-7719-4afa-a907-0220f6749650" />

<br>
<br>
<br>




Автор: <br>

<br>

Сонер Дениз / №22224 / ООП / 5.12.2025






















