//PROGRAM TO STORE DETAILS OF STUDENT USING STRUCTURE AND PRINT THE DETAILS ALSO 

#include<iostream>
using namespace std;
struct student{
    int roll;
    char name[];
};

int main(){
    int n;
    cout<<"ENTER NUMBER OF STUDENTS ";
    cin>>n;
    struct student s[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"ENTER ROLL NUMBER ";
        cin>>s[i].roll;
        cout<<"ENTER NAME ";
        cin>>s[i].name;
        
   }
for(int i=0;i<n;i++){
    cout<<"NAME :"<<s[i].name<<endl;
    cout<<"ROLL :"<<s[i].roll<<endl;
}
    return 0;
}