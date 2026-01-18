#include <iostream> //để dùng cho cin và cout
#include <fstream> //dùng làm việc với file
#include <string> // dùng cho chuỗi string
#include <chrono> // thư viện làm việc với thời gian
#include <filesystem> //thư viện làm việc với hệ thống file
#include<vector> // thư viện làm việc với vecto
using namespace std; //dùng để tránh std nhiều lần

class quanLy
{
protected:
    string file; // tên file
public:
    int maso;
    string ten;
    string diachi;
    float sodiem;
    quanLy(const string &file);
    ~quanLy();
    void openfile();
    void writefile(const string &nd);
    void Readfile();
    void Searchfile(const string &key);
};
quanLy::quanLy(const string &file):file(file){}
quanLy::~quanLy(){}

void quanLy::openfile(){
    fstream f; // khởi tạo biến f
    f.open(file , ios::in | ios::out | ios::app);
    // chức năng  mở đọc ghi (file có nghĩa là dùng chung 1 file)
    if(f.is_open()){
        cout<<"quan ly"<<endl;
    }
    else cout<<"mo that bai "<<endl;
    f.close();
}
void quanLy::writefile(const string &nd){
    fstream f;
    f.open(file, ios::out | ios::app);
    if(f.is_open()){
       f<<nd<<endl;
    }
    f.close();
}
void quanLy::Readfile(){
    fstream f;
    string nd;
    f.open(file, ios::in);
    if(!f.is_open()){ 
        /*!f là trường hợp đảo của đúng trong fstream
        đúng thành sai mà sai thành đúng 
        !f == true nghĩa là dòng code trên là chỉ khiểm 
        tra xem file có mở được không
        nếu đúng không mở được thì in ra lỗi file*/
        cout<<"Khong mo duoc file"<<endl;
        return;
    }
    while (getline(f,nd))
    {
        cout<<nd<<endl;
    }
    f.close();
}
void quanLy::Searchfile(const string &key){

    fstream f;
    string  nd;
    f.open(file, ios::in);
    if(!f.is_open()) return;
    while (getline(f,nd))
    {
        if(nd.find(key) != string::npos){
            cout<<nd<<endl;
        }
    }
    f.close();
}
/*class Thanhvien:public quanLy
{
public:
    Thanhvien(const string &filebandau2) :file(filebandau);
    ~Thanhvien();
};

Thanhvien::Thanhvien(const string &filebandau2)
Thanhvien::~Thanhvien(){}*/

class Tainguyen :public quanLy
{
    private :
    string tainguyen;
public:
vector<quanLy> ql;
Tainguyen(const string &tainguyen);
    ~Tainguyen(); 
    void open();
    void Nhapsach(const string &nd);
    void hienthisach();
    void timkiem(const string &key);
    void xoasach(); 
    void suasach();
    void savefile();
};
Tainguyen::Tainguyen(const string &tainguyen):quanLy(tainguyen){}//overload khi chạy thì sẽ tùy vào tham số còn trong trường hợp này là gọi constructỏ cha trước
Tainguyen::~Tainguyen(){}
void Tainguyen::open(){
    openfile();
}
void Tainguyen::Nhapsach(const string &nd ){
    // truyền đối số từ bên ngoài vào vì là biến không tên nên phải có const
   ql.emplace_back( nd);

}
void Tainguyen::hienthisach(){
    for (int i=0; i<ql.size();i++)
    {
        cout<<ql[i]<<endl;
    };
    
};
void Tainguyen::timkiem(const string &key){
    Searchfile( key);
}
void Tainguyen::xoasach(){
}
void Tainguyen::suasach(){}
void Tainguyen::savefile(){
    fstream f;
    f.open(file, ios::in | ios::out |ios::app);
    for (const quanLy &t :ql)
    {
        f<<t.ten<<endl;
    };
    f.close();
}

int main(){
    int n;
    
     Tainguyen tn("data1.txt");
     //Thanhvien tv("data3.txt");
     tn.open();
     //q.writefile("da nhap thanh cong");
     tn.Nhapsach("dac nhantam");
     //tn.hienthisach();
     tn.savefile();
     tn.hienthisach();
     cout<<endl;
     //tn.timkiem("2");
    /* cout<<"----Quan Ly----"<<endl;
     cout<<"1.Sach"<<endl;
     cout<<"2.Thanh Vien"<<endl;
     cin>>n;
     switch (n)
     {
     case 1:
       cout<<"----Sach----"<<endl;
       int a;
       cout<<"1. Nhap sach"<<endl;
       cout<< "2. Hien thi sach"<<endl;
       cout<<"3.Tim kiem"<<endl;
       cout<<"4.Sua"<<endl;
       cout<<"5.Xoa sach"<<endl;
       cin>>a;
       switch (a)
       {
       case 1:
         tn.Nhapsach();
         break;
         case 2:
         tn.hienthisach();
         break;
         case 3: 
         tn.timkiem();
         break;
         case 4:
         tn.suasach();
         break;
         case 5:
         tn.xoasach();
        break;
       }
        break;
     case 2:
       cout<<"----Thanh vien----"<<endl;
       int b;
       cin>>b;
       switch (b)
       {
       case 1:
        break;
       
     }
     tn.hienthisach();
     q.openfile();*/
    return 0;
    }
