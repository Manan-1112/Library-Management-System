#include<iostream>
#include <string>
#include <vector>
using namespace std;
class Book{
public:
    string title;
    string author;
    bool Isavailable;
    string ISBN;
    Book(string t,string a,string isbn,bool available=true){
        title=t;
        author=a;
        ISBN=isbn;
        Isavailable=available;
    }
    void displaybook(){
        cout<<"Book Details are :"<<endl;
        cout<<"TITLE : "<<title<<endl;
        cout<<"AUTHOR : "<<author<<endl;
        cout<<"ISBN : "<<ISBN<<endl;
        if(Isavailable==true){
            cout<<"BOOK IS AVAILABLE"<<endl;
        }
        else if(Isavailable==false){
            cout<<"BOOK IS NOT AVAILABLE"<<endl;
        }
        else{
            cout<<"CONTACT TO LIBRARIAN"<<endl;
        }

    }
    void markIssued(){
        Isavailable=true;
        cout<<"BOOK HAS BEEN ISSUED SUCCESSFULLY! "<<endl;
    }
    void markReturned(){
        Isavailable=false;
        cout<<"BOOK HAS BEEN RETURNED SUCCESSFULLY"<<endl;
    }

};
class User{
public:
    string name;
    int UserId;
    vector<string> borrowedBooks;
    User(string n,int id){
        name=n;
        UserId=id;
    }
    void borrowBook(string isbn){
        cout<<"BOOK WITH ISBN "<<isbn<<" BORROWED SUCCESSFULLY !"<<endl;
        borrowedBooks.push_back(isbn);
    }
    void returnBook(string isbn){
        cout<<"BOOK WITH ISBN "<<isbn<<" RETURNED !"<<endl;
        for(auto it=borrowedBooks.begin();it!=borrowedBooks.end();it++){
            if(*it==isbn){
                borrowedBooks.erase(it);
            }
        }
    }
    void DisplayUser(){
        cout<<"User Name : "<<name<<endl;
        cout<<"User Id : "<<UserId<<endl;
        cout<<"BORROWED BOOKS ISBN's ARE : "<<endl;
        for(string val : borrowedBooks){
            cout<<val;
        }
    }

};
class Library{
    vector<Book> books;
    vector<User> users;

public:
    void addBook(Book b){
        books.push_back(b);
        cout<<"BOOK ADDED SUCCESSFULLY !"<<endl;
    }
    void removeBook(string isbn){
        for(auto it=books.begin();it!=books.end();it++){
            if(it->ISBN==isbn){
                books.erase(it);
            }

        }
        cout<<"BOOK REMOVED SUCCESSFULLY !"<<endl;
    }
    void addUser(User u){
        users.push_back(u);
    }
    void IssueBook(string isbn,int id){
        for(auto &book : books){
            if(book.ISBN==isbn && book.Isavailable){
                book.Isavailable=false;

            }
        }
        for(auto &user : users){
            if(user.UserId==id){
                user.borrowedBooks.push_back(isbn);
            }
        }

    }
    void returnBook(string isbn,int id){
        for(auto book: books){
            if(book.ISBN==isbn){
                book.markReturned();
            }
        }
        for(auto user:users){
            if(user.UserId==id){
                user.returnBook(isbn);
            }
        }
    }
    void DisplayallBooks(){
        for(auto &book:books){
            book.displaybook();
            
        }
    }
    void DIsplayallUsers(){
        for(auto user:users){
            user.DisplayUser();
        }
    }

};
int main(){
    Library lib;
    int choice;
    cout<<"ENTER WHO IS THERE /n 1.LIBRARY STAFF /n "<<endl;
    cin>>choice;

    if (choice==1)
    {
        cout<<"Enter what you want to do/n";
        cout<<"1.ADD BOOK"<<endl;
        cout<<"2.ISSUE BOOK"<<endl;
        cout<<"3.RETURN BOOK"<<endl;
        cout<<"4.REMOVE BOOK"<<endl;
        cout<<"5.ADD USER"<<endl;
        cout<<"6.DISPLAY ALL THE BOOKS"<<endl;
        cout<<"7.DISPLAY ALL THE USERS"<<endl;
        cin>>choice;
        if(choice==1){
            string title;
            string author;
            bool Isavailable;
            string ISBN;
            cout<<"ENTER TITLE OF THE BOOK"<<endl;
            cin.ignore();
            getline(cin,title);
            cout<<"ENTER ISBN OF THE BOOK"<<endl;
            getline(cin,ISBN);
            cout<<"ENTER AUTHOR OF THE BOOK"<<endl;
            getline(cin,author);
            cout<<"ENTER True if book is available and false if not"<<endl;
            cin>>Isavailable;
            Book b(title,author,ISBN);
            lib.addBook(b);
        }
        else if(choice==2){
            string isbn;
            int id;
            cout<<"ENTER ISBN OF THE BOOK TO BE ISSUED "<<endl;
            cin.ignore();
            getline(cin,isbn);
            cout<<"ENTER THE ID OF USER "<<endl;
            cin>>id;
            lib.IssueBook(isbn,id);
        }
        else if(choice==3){
            string isbn;
            int id;
            cout<<"ENTER ISBN OF THE BOOK TO BE RETURNED "<<endl;
            cin.ignore();
            getline(cin,isbn);
            cout<<"ENTER THE ID OF USER "<<endl;
            cin>>id;
            lib.returnBook(isbn,id);
        }
        else if(choice==4){
            string isbn;
            cout<<"ENTER ISBN OF THE BOOK TO BE RETURNED "<<endl;
            cin.ignore();
            getline(cin,isbn);
            lib.removeBook(isbn);
        }
        else if(choice==5){
            string name;
            int UserId;
            cout<<"ENTER USER ID"<<endl;
            cin>>UserId;
            cout<<"ENTER NAME"<<endl;
            cin.ignore();
            getline(cin,name);
            User u(name,UserId);
            lib.addUser(u);
        }
        else if(choice==6){
            lib.DisplayallBooks();
        }
        else if(choice==7){
            lib.DIsplayallUsers();
        }
        else{
            cout<<"ENTERED A CORRECT NUMBER";
        }
        
    }

    return 0;
}