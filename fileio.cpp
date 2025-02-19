#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
    string st;
    string vst;
    ofstream out;
    out.open("FileIO.txt");
    cout<<"Enter text you want to write in the file: ";
    getline(cin,st);
    out<<st;
    out.close();
    ifstream in("FileIO.txt");
    int i=0;
    getline(in,st);
    for (int i = 0; i!=in.eof(); i++)
    {
        if(st[i]=='a'){
            vst=st;
        }
    }
    cout<<vst;
    in.close();
    
    return 0;
}