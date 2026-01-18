#include"bandan.h"
#include<string>
#include<fstream>
#include<iostream>
#include<vector>
#include<filesystem>
using namespace std;
vector<diode> list_diode;
vector<bjt> list_bjt;
bjt::bjt(): tenfile("bjt.txt"){}
std::string bjt::getl() const {return this->loai;}
void bjt::setl(const std::string &l){loai =l;}
void bjt::nhapbjt(int maso){
    nhaplk(maso);
        cout<<"Loai:  ";
             cin.ignore();
             getline(cin,loai);
}
void bjt::xuatbjt(){
     xuatlk();
           cout<< "Loai: "<< loai <<endl;
};
void bjt::xuats(){
     xuatlk();
           cout<< "Loai: "<< loai <<endl;
           cout<< "Ma so: "<<maso<<endl;
};
void bjt::luubjt(){
    fstream f;
    f.open(tenfile, ios::in | ios::app);
    if (!f.is_open())
    {
        cout<< "That bai" << endl;
        return;
    }
    f<<ten<<"|"<<giatien<<"|"<<tinhtrang<<"|"<<mota<<"|"<< loai <<"|"<<maso<< endl;
    f.close();
}
void bjt::xoab(int &ms){
    fstream fin("bjt.txt",ios::in);
    if (!fin.is_open())
    {
        cout<<"That bai"<<endl;
        return;
    }
    fstream fout;
    string tmp = "bjt_tmp.txt";
    fout.open(tmp, ios::out);
    while (getline(fin,ten,'|'))
       {getline(fin,giatien,'|');
        getline(fin,tinhtrang,'|');
        getline(fin,mota,'|');
        getline(fin,loai,'|');
        string mss;
        getline(fin,mss);
        int maso=stoi(mss);
if (ms!=maso)
{
    fout<<ten<<"|"<<giatien<<"|"<<tinhtrang<<"|"<<mota<<"|"<< loai <<"|"<<maso<<endl;
}
    } 
    fin.close();
    fout.close();
    std::error_code ec;
    std::filesystem::remove("bjt.txt",ec);
    std::filesystem::rename(tmp,"bjt.txt",ec);
}
void bjt::xuatfbv(){
    fstream f;
        f.open(tenfile, ios::in | ios::out);
        if (!f.is_open())
        {
            cout<< "That bai" <<endl;
            return;
        };
       bjt bj;
       while (getline(f,bj.ten,'|'))
       {getline(f,bj.giatien,'|');
        getline(f,bj.tinhtrang,'|');
        getline(f,bj.mota,'|');
        getline(f,bj.loai,'|');
        string mss;
        getline(f,mss);
        int maso=stoi(mss);
        bj.setmaso(maso);
        list_bjt.push_back(bj);
       }
        f.close();
}
void bjt::suab(int ms ,const std::string &sua, const std::string &suathanh){
    fstream f;
    f.open(tenfile, ios::in | ios::out);
    if (!f.is_open())
    {
        cout<< "That bai" << endl;
        return;
    }
        for (size_t i = 0; i < list_bjt.size(); i++)
    {if (list_bjt[i].getmaso()==ms);
    {
        if (sua==list_bjt[i].getten() )
        {
           list_bjt[i].setten(suathanh);
        };
        if (sua==list_bjt[i].gettinhtrang() )
        {
            list_bjt[i].settinhtrang(suathanh);
        };
        if (sua==list_bjt[i].getl())
        {
           list_bjt[i].setl(suathanh);
        };
        if (sua ==list_bjt[i].getgiatien())
        {
            list_bjt[i].setgiatien(suathanh);
        };
        if (sua==list_bjt[i].getmota())
        {
           list_bjt[i].setmota(suathanh);
        };
    } f<<list_bjt[i].getten()<<"|"<<list_bjt[i].getgiatien()<<"|"<<list_bjt[i].gettinhtrang()<<"|"<<list_bjt[i].getmota()<<"|"<< list_bjt[i].getl() <<"|"<<list_bjt[i].getmaso()<< endl;
    }  fstream fout;
   string tmp= tenfile +"tmp";
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
bjt::~bjt(){}

diode::diode():tenfile("diode.txt"){}
void diode::setloai(const std::string &l){loai=l;}
std::string diode::getloai(){return this->loai;}
void diode::xoa(int &ms){
    fstream fin;
    fin.open("diode.txt",ios::in);
    if(!fin.is_open()) {
        cout<<"That bai"<<endl;
        return;
    }
    fstream fout;
    string tmp = "diode_tmp.txt";
    fout.open(tmp,ios::out);
    string line;
    while (getline(fin,ten,'|'))
       { getline(fin,giatien,'|');
        getline(fin,tinhtrang,'|');
        getline(fin,mota,'|');
        getline(fin,loai,'|');
        string mss;
        getline(fin,mss);
        int maso=stoi(mss);
        if (ms!=maso)
        {fout<<ten<<"|"<<giatien<<"|"<<tinhtrang<<"|"<<mota<<"|"<< loai <<"|"<<maso<<endl;
        }
        
    }
    fin.close();
    fout.close();
    std::error_code ec;
    std::filesystem::remove("diode.txt",ec);
    std::filesystem::rename(tmp,"diode.txt",ec);
}
void diode::nhapdiode(int maso){
    nhaplk(maso);
            cout<<"Loai:";
            cin.ignore();
                 getline(cin,loai);
};
void diode::xuatdiode(){
    xuatlk();
           cout<<"Loai: "<< loai << endl;
    
}
void diode::xuats(){
    xuatlk();
           cout<<"Loai: "<< loai << endl;
           cout<< "Ma so: "<<maso<<endl;
    
}
void diode::luudiode(){
    fstream f;
    f.open(tenfile, ios::in | ios::app);
    if (!f.is_open())
    {
        cout<< "That bai" << endl;
        return;
    }
 
    f<<ten<<"|"<<giatien<<"|"<<tinhtrang<<"|"<<mota<<"|"<< loai <<"|"<<maso<< endl;
    f.close();
}
void diode::xuatfdv(){
 fstream f;
        f.open(tenfile, ios::in | ios::out);
        if (!f.is_open())
        {
            cout<< "That bai" <<endl;
            return;
        };
       diode dd;
       while (getline(f,dd.ten,'|'))
       { getline(f,dd.giatien,'|');
        getline(f,dd.tinhtrang,'|');
        getline(f,dd.mota,'|');
        getline(f,dd.loai,'|');
        string mss;
        getline(f,mss);
        int maso=stoi(mss);
        dd.setmaso(maso);
        list_diode.push_back(dd);
       }
        f.close();
}
void diode::suad(int ms ,const std::string &sua, const std::string &suathanh){
    fstream f;
    f.open(tenfile, ios::in | ios::out);
    if (!f.is_open())
    {
        cout<< "That bai" << endl;
        return;
    }
        for (size_t i = 0; i < list_diode.size(); i++)
    {if (list_diode[i].getmaso()==ms)
    {
        if (sua==list_diode[i].getten() )
        {
           list_diode[i].setten(suathanh);
        };
        if (sua==list_diode[i].gettinhtrang() )
        {
            list_diode[i].settinhtrang(suathanh);
        };
        if (sua==list_diode[i].getloai())
        {
           list_diode[i].setloai(suathanh);
        };
        if (sua ==list_diode[i].getgiatien())
        {
            list_diode[i].setgiatien(suathanh);
        };
        if (sua==list_diode[i].getmota())
        {
           list_diode[i].setmota(suathanh);
        };
    }  f<<list_diode[i].getten()<<"|"<<list_diode[i].getgiatien()<<"|"<<list_diode[i].gettinhtrang()<<"|"<<list_diode[i].getmota()<<"|"<< list_diode[i].getloai() <<"|"<<list_diode[i].getmaso()<< endl;
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
diode::~diode(){}