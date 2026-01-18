#include"machdientu.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<filesystem>
using namespace std;
vector<machdientu> list_machdientu;
machdientu::machdientu():tenfile("machdientu.txt"){}
void machdientu::setloaimach(const std::string &mach){loaimach=mach;}
std::string machdientu::getloaimach( )const {return this->loaimach;}
void machdientu::nhapm(int maso){
    nhaplk(maso);
    cout<< "Nhap loai mach:"<<endl;
    cin.ignore();
    getline(cin,loaimach);
}
void machdientu::xuatm(){
         xuatlk();
                cout<< "Mach dien tu: " << loaimach << endl;
}
void machdientu::xuats(){
         xuatlk();
                cout<< "Mach dien tu: " << loaimach << endl;
                cout<< "Ma so: "<<maso<<endl;
}

void machdientu::luum(){
    fstream f;
    f.open(tenfile, ios::in | ios::app);
    if (!f.is_open())
    {
        cout<< "That bai" <<endl;
        return;
    }
    f<<ten<<"|"<<giatien<<"|"<<tinhtrang<<"|"<<mota<<"|"<< loaimach <<"|"<<maso<< endl;
    f.close(); 
}
 void machdientu::suam(int ms,const string &sua, const string &suathanh){  
    fstream f;
    f.open(tenfile, ios::in | ios::out);
    if (!f.is_open())
    {
        cout<< "That bai" <<endl;
        return;
    }
    for (size_t i = 0; i < list_machdientu.size(); i++)
    {if (list_machdientu[i].getmaso()==ms)
    {
        if (sua==list_machdientu[i].getten() )
        {
           list_machdientu[i].setten(suathanh);
        };
        if (sua==list_machdientu[i].gettinhtrang() )
        {
            list_machdientu[i].settinhtrang(suathanh);
        };
        if (sua==list_machdientu[i].getloaimach())
        {
           list_machdientu[i].setloaimach(suathanh);
        };
        if (sua ==list_machdientu[i].getgiatien())
        {
            list_machdientu[i].setgiatien(suathanh);
        };
        if (sua==list_machdientu[i].getmota())
        {
           list_machdientu[i].setmota(suathanh);
        };
    }  f<<list_machdientu[i].getten()<<"|"<<list_machdientu[i].getgiatien()<<"|"<<list_machdientu[i].gettinhtrang()<<"|"<<list_machdientu[i].getmota()<<"|"<< list_machdientu[i].getloaimach() <<"|"<<list_machdientu[i].getmaso()<< endl;
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
void machdientu::xoa(int &ms){
    fstream fin;
    fin.open(tenfile, ios::in);
    if (!fin.is_open())
    {
        cout<<"That bai"<<endl;
        return;
    }
    string tmp= tenfile + ".tmp";
    fstream fo;
    fo.open(tmp, ios::out);
    while (getline(fin,ten,'|'))
       {getline(fin,giatien,'|');
        getline(fin,tinhtrang,'|');
        getline(fin,mota,'|');
        getline(fin,loaimach,'|');
        string mss;
        getline(fin,mss);
        int maso = stoi(mss);
        if (ms!=maso)
        {
           fo<<ten<<"|"<<giatien<<"|"<<tinhtrang<<"|"<<mota<<"|"<< loaimach <<"|"<<maso<<endl;
        }
        
    }
    fin.close();
    fo.close();
    std::error_code ec;
    std::filesystem::remove (tenfile, ec);
    std::filesystem::rename (tmp, tenfile, ec);
     
    
}
void machdientu::xuatfv(){
fstream f;
        f.open(tenfile, ios::in | ios::out);
        if (!f.is_open())
        {
            cout<< "That bai" <<endl;
            return;
        };
        machdientu mdt;
       while (getline(f,mdt.ten,'|'))
       {getline(f,mdt.giatien,'|');
        getline(f,mdt.tinhtrang,'|');
        getline(f,mdt.mota,'|');
        getline(f,mdt.loaimach,'|');
        string mss;
        getline(f,mss);
        int maso = stoi(mss); // chuyển đổi kiểu chuỗi thành kiêu số
        mdt.setmaso(maso); // gán giá trị cho biến maso trong đối tượng
        list_machdientu.push_back(mdt);
       }
        f.close();
}
machdientu::~machdientu(){}