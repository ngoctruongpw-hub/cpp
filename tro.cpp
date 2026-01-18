#include"tro.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<filesystem>
using namespace std;
vector<tro> list_tro;
tro::tro():tenfile("tro.txt"){}
std::string tro::getgiatri() const {return this->giatri;}
void tro::setgiatri(const std::string &gt){giatri = gt;}
std::string  tro::getloai() const {return this->loai;}
void tro::setloai(const std::string &l){loai=l;}
void tro::nhapt(int maso){
    nhaplk(maso);
    cout<< "Loai:" << endl;
   cin.ignore();
   getline(cin,loai);
    cout<< "Gia tri:" <<endl;
    cin.ignore();
    getline(cin,giatri);
}
void tro::xuatt(){
    xuatlk();
    cout<< "Loai: " <<loai << endl;
    cout<< "Gia tri: " << giatri<< endl;
}
void tro::xuats(){
    xuatlk();
    cout<< "Loai: " <<loai << endl;
    cout<< "Gia tri: " << giatri<<endl;
    cout<< "Ma so: "<<maso<<endl;
}
void tro::luutro(){
   fstream f;
   f.open(tenfile, ios::in | ios::app);
   if (!f.is_open())
   {
    cout<< " That bai" << endl;
    return;
   }
   f<<ten<<"|"<<giatien<<"|"<<tinhtrang<<"|"<<mota<<"|"<< loai <<"|"<< giatri << "|"<<maso<< endl;
   f.close();
}
void tro::xuatfv(){
        fstream f;
        f.open(tenfile, ios::in | ios::out);
        if (!f.is_open())
        {
            cout<< "That bai" <<endl;
            return;
        };
        tro tr;
       while (getline(f,tr.ten,'|'))
       {
             getline(f,tr.giatien,'|');
             getline(f,tr.tinhtrang,'|');
              getline(f,tr.mota,'|');
             getline(f,tr.loai,'|');
             getline(f,tr.giatri,'|');
             string mss;
             getline(f,mss);
             int maso = stoi(mss);
             tr.setmaso(maso);
        list_tro.push_back(tr);
       }
        f.close();
}
void tro::xoa(int &ms){
    fstream fin;
    fin.open(tenfile, ios::in);
    if (!fin.is_open())
    {
      cout<<"That bai"<<endl;
      return;
    }
    fstream fout;
    string tmp = tenfile + ".tmp";
    fout.open(tmp, ios::out);
    
     while (getline(fin,ten,'|'))
       {
             getline(fin,giatien,'|');
             getline(fin,tinhtrang,'|');
              getline(fin,mota,'|');
             getline(fin,loai,'|');
             getline(fin,giatri,'|');
             string mss;
             getline(fin,mss);
             int maso = stoi(mss);
       if (ms!=maso)
       {
        fout<<ten<<"|"<<giatien<<"|"<<tinhtrang<<"|"<<mota<<"|"<< loai <<"|"<< giatri << "|"<<maso<<endl;
       }
       
    }
    fin.close();
    fout.close();
    std::error_code ec;
    std::filesystem::remove(tenfile, ec);
    std::filesystem::rename(tmp,tenfile, ec);

}
void tro::suatro(int ms , const std::string &sua, const std::string &suathanh){
       fstream f;
   f.open(tenfile, ios::in | ios::out);
   if (!f.is_open())
   {
    cout<< " That bai" << endl;
    return;
   }
    for (size_t i = 0; i < list_tro.size(); i++)
    {if (list_tro[i].getmaso()==ms)
    {
        if (sua==list_tro[i].getten() )
        {
           list_tro[i].setten(suathanh);
        };
        if (sua==list_tro[i].gettinhtrang() )
        {
            list_tro[i].settinhtrang(suathanh);
        };
        if (sua==list_tro[i].getloai())
        {
           list_tro[i].setloai(suathanh);
        };
        if (sua ==list_tro[i].getgiatien())
        {
            list_tro[i].setgiatien(suathanh);
        };
        if (sua==list_tro[i].getmota())
        {
           list_tro[i].setmota(suathanh);
        };
        if (sua==list_tro[i].getgiatri())
        {
           list_tro[i].setgiatri(suathanh);
        }
    }
        f<<list_tro[i].getten()<<"|"<<list_tro[i].getgiatien()<<"|"<<list_tro[i].gettinhtrang()<<"|"<<list_tro[i].getmota()<<"|"<< list_tro[i].getloai() <<"|"<< list_tro[i].getgiatri() << "|"<<list_tro[i].getmaso()<< endl;
    } fstream fout;
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
tro::~tro(){}