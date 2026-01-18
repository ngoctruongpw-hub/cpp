#include"donghe.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<filesystem>
using namespace std;
vector<donghe> list_donghe;
donghe::donghe():tenfile("donghe.txt")
{
}
void donghe::settendn(const std::string &ten){tendonghe=ten;}
std::string donghe::gettendn()const {return this->tendonghe;}
void donghe::nhapdn(int maso){
   nhaplk(maso);
           cout<< "Nhap ten do nghe: "<< endl;
               
               cin.ignore();
               getline(cin,tendonghe);
}
void donghe::xuatdn(){
       xuatlk();
               cout<< "Ten do nghe:" << tendonghe;
    
}
void donghe::xuats(){
       xuatlk();
               cout<< "Ten do nghe:" << tendonghe<< endl;
               cout<< "Ma so: "<<maso<<endl;
    
}
void donghe::luudn(){
   fstream f;
   f.open(tenfile, ios::in | ios::app);
   if (!f.is_open()){
        cout<< "That bai" <<endl;
        return;
   };
   
   f<<ten<<"|"<<giatien<<"|"<<tinhtrang<<"|"<<mota<<"|"<< tendonghe <<"|"<<maso<< endl;
   f.close();
}
void donghe::xoa(int &ms){
    fstream fin;
   fin.open(tenfile, ios::in);
   if (!fin.is_open())
   {
    cout<<"That bai"<<endl;
    return;
   }
   fstream fout;
   string tmp= tenfile +".tmp";
   fout.open(tmp, ios::out);
   while (getline(fin,ten,'|'))
       {getline(fin,giatien,'|');
        getline(fin,tinhtrang,'|');
        getline(fin,mota,'|');
        getline(fin,tendonghe,'|');
        string mss;
        getline(fin,mss);
        int maso= stoi(mss); //chuyển từ chuôi số trong chuỗi chữ
    if (ms!=maso)
    {
       fout<<ten<<"|"<<giatien<<"|"<<tinhtrang<<"|"<<mota<<"|"<< tendonghe <<"|"<<maso<<endl;
    }
    
   }
   fin.close();
   fout.close();
   std::error_code ec;
   std::filesystem::remove (tenfile ,ec);
   std::filesystem::rename (tmp,tenfile ,ec);
}
void donghe::xuatfv(){
  
    fstream f;
        f.open(tenfile, ios::in | ios::out);
        if (!f.is_open())
        {
            cout<< "That bai" <<endl;
            return;
        };
        donghe dn;
       while (getline(f,dn.ten,'|'))
       {getline(f,dn.giatien,'|');
        getline(f,dn.tinhtrang,'|');
        getline(f,dn.mota,'|');
        getline(f,dn.tendonghe,'|');
        string mss;
        getline(f,mss);
        int maso= stoi(mss); //chuyển từ chỗi sang số
        dn.setmaso(maso); //gán giá trị cho biến maso trong đối tượng dn
        list_donghe.push_back(dn);
       }
        f.close();
}
void donghe::suadn(int ms,const std::string &sua, const std::string &suathanh){
    fstream f;
   f.open(tenfile, ios::in | ios::out);
   if (!f.is_open()){
        cout<< "That bai" <<endl;
        return;
   };
        for (size_t i = 0; i < list_donghe.size(); i++)
    {if (list_donghe[i].getmaso()==ms)
    {
        if (sua==list_donghe[i].getten() )
        {
           list_donghe[i].setten(suathanh);
        };
        if (sua==list_donghe[i].gettinhtrang() )
        {
            list_donghe[i].settinhtrang(suathanh);
        };
        if (sua==list_donghe[i].gettendn())
        {
           list_donghe[i].settendn(suathanh);
        };
        if (sua ==list_donghe[i].getgiatien())
        {
            list_donghe[i].setgiatien(suathanh);
        };
        if (sua==list_donghe[i].getmota())
        {
           list_donghe[i].setmota(suathanh);
        };
    }f<<list_donghe[i].getten()<<"|"<<list_donghe[i].getgiatien()<<"|"<<list_donghe[i].gettinhtrang()<<"|"<<list_donghe[i].getmota()<<"|"<< list_donghe[i].gettendn() <<"|"<<list_donghe[i].getmaso()<< endl;
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
donghe::~donghe()
{
}