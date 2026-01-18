#include"file.h"
#include<iostream>
#include<string>
#include<fstream>
#include<filesystem>
#include<cstdio>
using namespace std;

file::file(const std::string &file)
{  filelk = file;
}
void file::openfile(){
fstream f;
f.open("tong.txt",ios::in | ios::out | ios::app);
if (!f.is_open())
{
    cout<< "That bai"<< endl;
    return ;
};
}
void file::readfile(){
    fstream f;
    f.open("tong.txt", ios::in | ios::out);
    if (!f.is_open())
    {
        cout<< " That bai :";
        return;
    };
    string nd;
    while (getline(f,nd))
    {
      cout<< nd << endl;
    };
    f.close();
}
void file::xoafile(const string &xoa){
    fstream fin;
    string fi = filelk +".tmp";
    fin.open(filelk, ios::in );
    if (!fin.is_open())
    {
       cout<< " That bai" << endl;
       return;
    };
    fstream fl;
    fl.open(fi, ios::out );
    string nd;
    while (getline(fin,nd))
    {
      if(nd!=xoa) {fl<< nd << endl;};
    };
    fin.close();
    fl.close();
    std::filesystem::remove(filelk);
    std::filesystem::rename(fi,filelk);
}
void file::searchfile(){
    string noidung;
    cout<<" noi dung muon tim"<< endl;
    cin>>noidung;
     fstream f;
     f.open("tong.txt", ios::in | ios::out);
    if (!f.is_open())
    {
       cout<< "That bai "<< endl;
       return;
    };
    string nd;
    while (getline(f,nd))
    {
  
     if (nd.find(noidung)!=string::npos)
     {
       cout<< nd <<endl;
     }
     
    }
    f.close();
}
void file::gopfile(){
    fstream f1("tu.txt");
    fstream f2("tro.txt");
    fstream f3("donghe.txt");
    fstream f4("diode.txt");
    fstream f5("bjt.txt");
    fstream f6("nguon.txt");
    fstream f7("machdientu.txt");
    fstream f8("tong.txt");
    string nd;
    while (getline(f1,nd))
    {
       f8<<nd<<endl;
    };
    while (getline(f2,nd))
    {
       f8<<nd<<endl;
    };
    while (getline(f3,nd))
    {
       f8<<nd<<endl;
    };
    while (getline(f4,nd))
    {
       f8<<nd<<endl;
    };
    while (getline(f5,nd))
    {
       f8<<nd<<endl;
    };
    while (getline(f6,nd))
    {
       f8<<nd<<endl;
    };
    while (getline(f7,nd))
    {
       f8<<nd<<endl;
    };
    f1.close();
    f2.close();
    f3.close();
    f4.close();
    f5.close();
    f6.close();
    f7.close();
}

file::~file()
{
}
