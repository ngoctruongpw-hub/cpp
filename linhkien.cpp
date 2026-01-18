#include"linhkien.h"
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
void linhkien::nhaplk(int ms){
  maso=ms;
    cout<< "Ten: ";
    cin.ignore();
    getline(cin,ten);
    cout<< "Gia tien: ";
    cin>>giatien;
    cin.ignore();
    cout<< "Tinh trang: ";
       getline(cin,tinhtrang);
    cout<<"Mo ta: ";
   getline(cin,mota);
};
void linhkien::xuatlk(){
    cout<<"Ten: "<< ten <<endl  ;
     cout<<"Gia tien: "<< giatien<< endl;
    cout<< "Tinh trang:"<<tinhtrang <<endl;
    cout<<"Mo ta:"<< mota <<endl ;
}
void linhkien::setten(const std::string &t){ten = t;};
int linhkien::getmaso(  ) const{return this->maso;};
void linhkien::setmaso(int &ms){maso = ms;};
    void linhkien::settinhtrang(const std::string &tt){tinhtrang = tt;};
    void linhkien::setmota(const std::string &mt){mota = mt;};
    void linhkien::setgiatien(const std::string &gia){giatien =gia;};
    std::string linhkien::getten() const {return this->ten;};
    std::string linhkien::gettinhtrang() const {return this->tinhtrang;};
    std::string linhkien::getmota() const {return this->mota;};
    std::string linhkien::getgiatien() const {return this->giatien;};

linhkien::linhkien() : file("tong.txt"), tenfile("tong.txt")
{}
linhkien::~linhkien()
{
}