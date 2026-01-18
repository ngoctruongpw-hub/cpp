#include"tu.h"
#include<iostream>
#include<fstream>
#include<filesystem>
#include<vector>
using namespace std;
  vector<tu> list_tu;
void tu::nhaptu(int maso){
    nhaplk( maso);
           cout<< "Gia tri:";
                cin.ignore();
                getline(cin,giatri);
           cout<< "Loai:";
                cin.ignore();
                getline(cin,loai);
}
void tu::xuattu(){
           xuatlk();
           cout<<"Gia tri: "<< giatri <<endl;
           cout<<"Loai: "<< loai << endl;
}
void tu::xuats(){
           xuatlk();
           cout<<"Gia tri: "<< giatri <<endl;
           cout<<"Loai: "<< loai << endl;
           cout<< "Ma so: "<<maso<<endl;
           
}
tu::tu() :tenfile("tu.txt"){ }
void tu::luutu(){
     fstream f;
     f.open(tenfile, ios::in | ios::app);
     if (!f.is_open())
     {
          cout<< "That bai"<< endl;
          return ;
     };
     f<< ten<<"|"<<giatien<<"|"<<tinhtrang<<"|"<<mota<<"|"<< giatri <<"|"<< loai <<"|"<<maso<< endl;
     f.close();
}
void tu::xuatfv(){
      fstream f;
        f.open(tenfile, ios::in | ios::out);
        if (!f.is_open())
        {
            cout<< "That bai" <<endl;
            return;
        };
        tu tt;
       while (getline(f,tt.ten,'|'))
       { 
        getline(f,tt.giatien,'|');
          getline(f,tt.tinhtrang,'|');
          getline(f,tt.mota,'|');
          getline(f,tt.giatri,'|');
          getline(f,tt.loai,'|');
          string mss; //getline chỉ đọc được chuỗi nên phải tạo 1 biến trnung gian để chuyển đổi
          getline(f,mss);
          int maso=stoi(mss);  // chuyen đỏi chuỗi thành số nguyên
          tt.setmaso(maso); // gán giá trị maso cho đối tượng tt
          list_tu.push_back(tt);
       }
        f.close();
}
void tu::suatu(int ms,const std::string &sua, const string &suathanh){
    fstream ff;
     ff.open(tenfile, ios::in | ios::out);
     if (!ff.is_open())
     {
          cout<< "That bai"<< endl;
          return ;
     };
         for (size_t i = 0; i < list_tu.size(); i++)
    {if (list_tu[i].getmaso()==ms)
    {
        if (sua ==list_tu[i].getten() )
        {
           list_tu[i].setten(suathanh);
        };
        if (sua ==list_tu[i].gettinhtrang() )
        {
            list_tu[i].settinhtrang(suathanh);
        };
        if (sua ==list_tu[i].getloai())
        {
           list_tu[i].setloai(suathanh);
        };
        if (sua ==list_tu[i].getgiatien())
        {
            list_tu[i].setgiatien(suathanh);
        };
        if (sua==list_tu[i].getmota())
        {
           list_tu[i].setmota(suathanh);
        };
        if (sua==list_tu[i].getgiatri())
        {
            list_tu[i].setgiatri(suathanh);
        }
    }    ff<< list_tu[i].getten()<<"|"<<list_tu[i].getgiatien()<<"|"<<list_tu[i].gettinhtrang()<<"|"<<list_tu[i].getmota()<<"|"<< list_tu[i].getgiatri() <<"|"<< list_tu[i].getloai() <<"|"<<list_tu[i].getmaso()<< endl;
    }
     fstream fout;
   string tmp= tenfile +".tmp";
   fout.open(tmp, ios::out);
   string line;
   while (getline(ff,line))
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
     ff.close();
}
void tu::xoa(int &ms){
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
    // tu tt;
    while (getline(fin,ten,'|'))
    {  
        getline(fin,giatien,'|');
          getline(fin,tinhtrang,'|');
          getline(fin,mota,'|');
          getline(fin,giatri,'|');
          getline(fin,loai,'|');
          string mss; //getline chỉ đọc được chuỗi nên phải tạo 1 biến trnung gian để chuyển đổi
          getline(fin,mss);
          int maso = stoi(mss);  // chuyen đỏi chuỗi thành số nguyên
          
       if (maso!=ms)
       {
        fout<<ten<<"|"<<giatien<<"|"<<tinhtrang<<"|"<<mota<<"|"<< giatri <<"|"<< loai <<"|"<<maso<<endl;
       }
    }
    fin.close();
    fout.close();
    std::error_code ec;
    std::filesystem::remove(tenfile, ec);
    std::filesystem::rename(tmp,tenfile, ec);
}
void tu::setgiatri(const std::string &gt){giatri = gt;}
std::string tu::getgiatri()const {return this->giatri;}
void tu::setloai(const std::string &l){loai=l;};
std::string tu::getloai() const {return this->loai;}
tu::~tu(){}
