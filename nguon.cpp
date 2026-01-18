#include"nguon.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<filesystem>
using namespace std;
vector<nguon> list_nguon;
nguon::nguon():tenfile("nguon.txt"){}
void nguon::setloainguon(const std::string &nguon){loainguon= nguon;}
std::string nguon::getloainguon() const {return this->loainguon;}
void nguon::nhapn(int maso){
    nhaplk(maso);
           cout<< "Loai nguon:"<< endl;
               cin.ignore();
               getline(cin,loainguon);
}
void nguon::xuatn(){
        xuatlk();
              cout<< "Loai nguon: "<< loainguon <<  endl;
}
void nguon::xuats(){
        xuatlk();
              cout<< "Loai nguon: "<< loainguon <<  endl;
              cout<< "Ma so: "<<maso<<endl;
    
}
void nguon::luun(){
     fstream f;
     f.open(tenfile, ios::in | ios::app);
     if (!f.is_open())
     {
          cout<< "That bai"<< endl;
          return ;
     };
     f <<ten<<"|"<<giatien<<"|"<<tinhtrang<<"|"<<mota<<"|"<< loainguon << "|"<<maso<< endl;
     
     f.close();
}
void nguon::xoa(int &ms){
   fstream fin;
    fin.open(tenfile, ios::in);
    if (!fin.is_open())
    {
       cout<<"That bai"<<endl;
       return;
    }
    fstream fo;
    string tmp = tenfile +".tmp";
    fo.open(tmp, ios::out);
    
    while (getline(fin,ten,'|'))
       {   getline(fin,giatien,'|');
             getline(fin,tinhtrang,'|');
             getline(fin,mota,'|');
             getline(fin,loainguon,'|'); 
             string mss;
             getline(fin,mss);
             int maso=stoi(mss);
       if (ms!=maso)
       {
        fo<<ten<<"|"<<giatien<<"|"<<tinhtrang<<"|"<<mota<<"|"<< loainguon << "|"<<maso<<endl;
       }
    }
    fin.close();
    fo.close();
    std::error_code ec;
    std::filesystem::remove (tenfile, ec);
    std::filesystem::rename (tmp, tenfile, ec);
    
}
void nguon::xuatfv(){
      fstream f;
        f.open(tenfile, ios::in | ios::out);
        if (!f.is_open())
        {
            cout<< "That bai" <<endl;
            return;
        };
        nguon ng;
       while (getline(f,ng.ten,'|'))
       {   getline(f,ng.giatien,'|');
             getline(f,ng.tinhtrang,'|');
             getline(f,ng.mota,'|');
             getline(f,ng.loainguon,'|'); 
             string mss;
             getline(f,mss);
             int maso=stoi(mss);
             ng.setmaso(maso); 
             list_nguon.push_back(ng);
        f.close();
}
}
void nguon::suan(int ms,const std::string &sua, const std::string &suathanh){
       fstream f;
     f.open(tenfile, ios::in | ios::out);
     if (!f.is_open())
     {
          cout<< "That bai"<< endl;
          return ;
     };
    for (size_t i = 0; i < list_nguon.size(); i++)
    {if (list_nguon[i].getmaso()==ms)
    {
        if (sua==list_nguon[i].getten() )
        {
           list_nguon[i].setten(suathanh);
        };
        if (sua==list_nguon[i].gettinhtrang() )
        {
            list_nguon[i].settinhtrang(suathanh);
        };
        if (sua==list_nguon[i].getloainguon())
        {
           list_nguon[i].setloainguon(suathanh);
        };
        if (sua ==list_nguon[i].getgiatien())
        {
            list_nguon[i].setgiatien(suathanh);
        };
        if (sua==list_nguon[i].getmota())
        {
           list_nguon[i].setmota(suathanh);
        };
    }f <<list_nguon[i].getten()<<"|"<<list_nguon[i].getgiatien()<<"|"<<list_nguon[i].gettinhtrang()<<"|"<<list_nguon[i].getmota()<<"|"<< list_nguon[i].getloainguon() << "|"<<list_nguon[i].getmaso()<< endl;
    }  fstream fout;
   string tmp= tenfile +".tmp";
   fout.open(tmp, ios::out);
   string line;
   while (getline(f,line))
   {
    if (sua!=line)
    {
       fout<< line <<endl;
    }
   }
   fout.close();
   std::error_code ec;
   std::filesystem::remove (tenfile, ec);
   std::filesystem::rename (tmp,tenfile, ec);
   f.close();
}
nguon::~nguon()
{
}