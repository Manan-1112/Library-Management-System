#include <iostream>
#include <string>
using namespace std;
class Book{
public:
    Book(){}
    int BookId;
    string Title;
    string Author;
    float price;
    Book(int id,string t,string a,float p){
        BookId=id;
        Title=t;
        Author=a;
        price=p;
    }
    void getdata(){
        cout<<"BOOK ID : "<<BookId<<","<<" TITLE : "<<Title<<","<<" AUTHOR : "<<Author<<" PRICE : "<<price<<endl;
    }
};
int main()
{
    int n,max=0;
    Book obj;
    cout<<"Enter number of books "<<endl;
    cin>>n;
    Book*ptr=new Book[n];
    for (int i = 0; i < n; i++)
    {
        int id;
        string t,a;
        float p;
        cout<<"Enter Bookid : "<<endl;
        cin>>id;
        cin.ignore();
        cout<<"Enter title : "<<endl;
        getline(cin,t);
        cout<<"Enter AUTHOR : "<<endl;
        getline(cin,a);
        cout<<"Enter Price: "<<endl;
        cin>>p;
        ptr[i]=Book(id,t,a,p);
    }
    cout<<"DISPLAYING DATA____________"<<endl;
    ptr[0].price=max;
    for (int i = 0; i < n; i++)
    {
       ptr[i].getdata();
       if(ptr[i].price>max){
        max=ptr[i].price;
        obj=ptr[i];
       }
    }
    cout<<"TITLE of most expensive book is "<<obj.Title<<" and price is "<<max;

    
    delete [] ptr;


    return 0;
}