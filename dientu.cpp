#include<iostream>
#include<fstream>
#include<vector>
#include<filesystem>
#include<string>
#include "tu.h"
#include "tro.h"
#include "bandan.h"
#include "donghe.h"
#include "nguon.h"
#include "machdientu.h"
#include "linhkien.h"
#include"file.h"
using namespace std;
linhkien lk;
tu t;
tro tr;
nguon ng;
bjt bj;
diode d;
machdientu m;
donghe dn;
class quanly :public file
{
private:
   string tenfile; // biến cục bộ tên file
public:
    quanly();
    void display();
    ~quanly();
};
void quanly::display(){
    readfile();
}
quanly::quanly():file("tong.txt"),tenfile("tong.txt"){}
quanly::~quanly(){}
int main (){
    quanly ql;
    file f("tong.txt");
    ql.openfile();
    t.xuatfv();
    dn.xuatfv();
    tr.xuatfv();
    m.xuatfv();
    d.xuatfdv();
    bj.xuatfbv();
    ng.xuatfv();
int n;
do{
  cout<< "----------DIEN TU NGOC TRUONG----------"<<endl;
  cout<< "1. Mach dien tu:"<<endl;
  cout<< "2.Linh kien ban dan:"<<endl;
  cout<< "3.Do nghe:"<<endl;
  cout<< "4. Cac loai tro:"<<endl;
  cout<< "5.Cac loai Tu:"<<endl;
  cout<< "6. Cac loai Nguon:"<<endl;
  cout<< "7 Xuat thong tin" << endl;
  cout<< "8.Thoat"<< endl;
  cout<< "9.Tim kiem"<<endl;
  cin>>n;
  int ms;
  switch (n)
  {
case 1:{
  int a;
    cout<< "1. Nhap thong tin"<<endl;
    cout<< "2. Sua thong tin" << endl;
    cout<< "3.Xem thong tin"<<endl;
    cout<< "4. Xoa"<<endl;
    cin>>a;
          switch (a) {
                     case 1:{
                      for (size_t i = 0; i < list_machdientu.size(); i++)
                          { do
                        {
                             cout<< "Nhap thong tin mach dien tu:"<<endl;
                               cout<< " Nhap mach dien tu co ma so dau 101:"<<endl;
                                  cin>>ms;
                                   if (ms==list_machdientu[i].getmaso())
                                {
                                     cout<< "Ma so da ton tai"<<endl;
                                };
                         } while (ms==list_machdientu[i].getmaso());
                          }
                            m.nhapm(ms);
                            list_machdientu.push_back(m);
                            m.luum();
                            break;}
                     case 2:{ int a;
                      string sua;
                      string st;
                  for (size_t i = 0; i < list_machdientu.size(); i++)
                         {
                          list_machdientu[i].xuats();
                         }
                          cout<< "Ban muon sua"<<endl;
                          cout<<"co ma so"<<endl;
                            int ms; cin>> ms;
                            cout<< "1.Ten"<<endl;
                            cout<< "2.Gia"<<endl;
                            cout<<"3.Tinh trang"<<endl;
                            cout<<"4.Mo ta"<<endl;
                            cout<<"5.Mach dien tu"<<endl;
                            cin>>a;
                          switch (a)
                          {
                          case 1:{
                            cout<<"Nhap ten muon sua"<<endl;
                            cin>>sua;
                            cout<<"sua thanh"<<endl;
                            cin>>st;
                           m.suam(ms,sua,st);
                            break;}
                          case 2:{
                            cout<<"Nhap gia muon sua"<<endl;
                            cin>>sua;
                             cout<<"sua thanh"<<endl;
                             cin>>st;
                            m.suam(ms,sua,st);
                            break;
                          }
                          case 3:{
                            cout<<"Nhap tinh trang muon sua"<<endl;
                            cin>>sua;
                            cout<<"sua thanh"<<endl;
                            cin>>st;
                            m.suam(ms,sua,st);
                            break;
                          }
                          case 4:{
                            cout<<"Nhap mo ta muon sua"<<endl;
                            getline(cin,sua);
                            cout<< "sua thanh"<<endl;;
                            m.suam(ms,sua,st);
                            break;
                          }
                          case 5:{
                            cout<<"Nhap mach muon sua"<<endl;
                            cin>>sua;
                            cout<< "Sua thanh"<<endl;
                            cin>>st;
                           m.suam(ms,sua,st);
                            break;
                          }
                          default:
                            break;
                          }
                         cout<<"sau khi sua"<<endl;
                         for (size_t i = 0; i < list_machdientu.size(); i++)
                         {
                          list_machdientu[i].xuatm();
                         }
                       break;
                       }
                            case 3: {
                              for (size_t i = 0; i < list_machdientu.size(); i++)
                              {
                                list_machdientu[i].xuatm();
                              }
                              break;
                            }
                            case 4: {
                              cout<<"Nhap ma so muon xoa:"<<endl;
                              cout<<"Ma so: "<<endl;
                              cin>>ms;
                              m.xoa(ms);
                              break;
                            }
                            default:
                            break;
                    }; break;
        }
case 2: {int b;
    cout<< "1. Nhap thong tin"<<endl;
    cout<< "2. Sua thong tin" << endl;
    cout<< "3.Xem thong tin"<<endl;
    cout<< "4. Xoa"<<endl;
    cin>>b;
              switch (b){
                        case 1:{
                               int o;
                               cout<<"1.Transistor" << endl;
                                cout<<"2. Diode" <<endl;
                                cin>>o;
                               switch (o)
                               {
                               case 1:{
                               for (size_t i = 0; i < list_bjt.size(); i++)
                                         { do {
                                                cout<< "Nhap thong tin BJT:"<<endl;
                                                 cout<< " Nhap tu co ma so dau 102:"<<endl;
                                                  cin>>ms;
                                                   if (ms==list_bjt[i].getmaso())
                                                      {
                                                      cout<< "Ma so da ton tai"<<endl;
                                                         };
                                            } while (ms==list_bjt[i].getmaso());
                                                }
                                bj.nhapbjt(ms);
                                list_bjt.push_back(bj);
                                bj.luubjt();
                                break;}
                               case 2:{
                                for (size_t i = 0; i < list_diode.size(); i++)
                                        { do
                                    {
                                                cout<< "Nhap thong tin tu:"<<endl;
                                               cout<< " Nhap tu co ma so dau 103:"<<endl;
                                               cin>>ms;
                                                if (ms==list_diode[i].getmaso())
                                              {
                                                       cout<< "Ma so da ton tai"<<endl;
                                            };
                                       } while (ms==list_diode[i].getmaso());
                  
                                     } d.nhapdiode(ms);
                                    list_diode.push_back(d);
                                     d.luudiode();
                                     break;}
                               default:
                                break;
                               } 
                              
                          break;    };
                          case 2:{
                            int k;
                            cout<<"1.Transistor" << endl;
                                cout<<"2. Diode" <<endl;
                                if (k=1)
                               { int a;
                                string sua;
                                string st;
                  for (size_t i = 0; i < list_bjt.size(); i++)
                         {
                          list_bjt[i].xuats();
                         }
                          cout<< "Ban muon sua"<<endl;
                          cout<<"co ma so"<<endl;
                             cin>> ms;
                            cout<< "1.Ten"<<endl;
                            cout<< "2.Gia"<<endl;
                            cout<<"3.Tinh trang"<<endl;
                            cout<<"4.Mo ta"<<endl;
                            cout<<"5.Loai"<<endl;
                            cin>>a;
                          switch (a)
                          {
                          case 1:{
                            cout<<"Nhap ten muon sua"<<endl;
                            cin>>sua;
                            cout<<"sua thanh"<<endl;
                            cin>>st;
                            bj.suab(ms,sua,st);
                            break;}
                          case 2:{
                            cout<<"Nhap gia muon sua"<<endl;
                            cin>>sua;
                             cout<<"sua thanh"<<endl;
                             cin>>st;
                            bj.suab(ms,sua,st);
                            break;
                          }
                          case 3:{
                            cout<<"Nhap tinh trang muon sua"<<endl;
                            cin>>sua;
                            cout<<"sua thanh"<<endl;
                            cin>>st;
                            bj.suab(ms,sua,st);
                            break;
                          }
                          case 4:{ 
                            cout<<"Nhap mo ta muon sua"<<endl;
                            getline(cin,sua);
                            cout<< "sua thanh"<<endl;
                           bj.suab(ms,sua,st);
                            break;
                          }
                          case 5:{
                            cout<<"Nhap loai muon sua"<<endl;
                            cin>>sua;
                            cout<< "Sua thanh"<<endl;
                            cin>>st;
                            bj.suab(ms,sua,st);
                            break;
                          }
                          default:
                            break;
                          }
                         cout<<"sau khi sua"<<endl;
                         for (size_t i = 0; i < list_bjt.size(); i++)
                         {
                          list_bjt[i].xuatbjt();
                         }
                       break;
                       }
                                if (k=2)
                                { int a;
                                  string sua;
                                  string st;
                                  for (size_t i = 0; i < list_diode.size(); i++)
                                 {
                                  list_diode[i].xuats();
                                }
                                cout<< "Ban muon sua"<<endl;
                                  cout<<"co ma so"<<endl;
                                 int ms; cin>> ms;
                                 cout<< "1.Ten"<<endl;
                                 cout<< "2.Gia"<<endl;
                                 cout<<"3.Tinh trang"<<endl;
                                 cout<<"4.Mo ta"<<endl;
                                 cout<<"5.Loai"<<endl;
                                 cin>>a;
                          switch (a)
                          {
                          case 1:{
                            cout<<"Nhap ten muon sua"<<endl;
                            cin>>sua;
                            cout<<"sua thanh"<<endl;
                            cin>>st;
                            d.suad(ms,sua,st);
                            break;}
                          case 2:{
                            cout<<"Nhap gia muon sua"<<endl;
                            cin>>sua;
                             cout<<"sua thanh"<<endl;
                             cin>>st;
                            d.suad(ms,sua,st);
                            break;
                          }
                          case 3:{
                            cout<<"Nhap tinh trang muon sua"<<endl;
                            cin>>sua;
                            cout<<"sua thanh"<<endl;
                            cin>>st;
                            d.suad(ms,sua,st);
                            break;
                          }
                          case 4:{
                            cout<<"Nhap mo ta muon sua"<<endl;
                            getline(cin,sua);
                            cout<< "sua thanh"<<endl;
                            cin>>st;
                            d.suad(ms,sua,st);
                            break;
                          }
                          case 5:{
                            cout<<"Nhap loai muon sua"<<endl;
                            cin>>sua;
                            cout<< "Sua thanh"<<endl;
                            cin>>st;
                           d.suad(ms,sua,st);
                            break;
                          }
                          default:
                            break;
                          }
                         cout<<"sau khi sua"<<endl;
                         for (size_t i = 0; i < list_diode.size(); i++)
                         {
                          list_diode[i].xuatdiode();
                         }
                         
                       break;
                       }
                          }
                         case 3 : {int g;
                                    cout<<"1.Transistor"<<endl;
                                    cout<<"2.Diode"<<endl;
                                    cin>>g;
                                 if (g=1){
                                         for (size_t j = 0; j < list_bjt.size(); j++)
                                          {
                                               list_bjt[j].xuatbjt();
                                          }
                                         break;
                                         };
                                 if (g=2) {
                                          for (size_t i = 0; i < list_diode.size(); i++)
                                        {
                                          list_diode[i].xuatdiode();
                                        }
                                          }; break;
                                 }
                                 case 4: {
                                  cout<<"1 BJT"<<endl;
                                  cout<<"2 Diode"<<endl;
                                  int b;
                                  cin>>b;
                                  if (b=1)
                                  {cout<<"Nhap ma so muon xoa dau 102"<< endl;
                                    cin>>ms;
                                    bj.xoab(ms);
                                  }
                                  if (b=2)
                                  {
                                   cout<<"Nhap ma so muon xoa dau 103"<< endl;
                                   cin>>ms;
                                   d.xoa(ms);
                                  }
                                  break;
                                 }
                        default:
                        break;
      }; 
}
case 3: 
     {int c;
    cout<< "1. Nhap thong tin"<<endl;
    cout<< "2. Sua thong tin" << endl;
    cout<<" 3.Xem thong tin"<<endl;
    cout<< "4.Xoa"<<endl;
    cin>>c;
         switch (c){
                    case 1:{
                           for (size_t i = 0; i < list_tu.size(); i++)
                               { do {
                                     cout<< "Nhap thong tin tu:"<<endl;
                                      cout<< " Nhap tu co ma so dau 106:"<<endl;
                                      cin>>ms;
                                          if (ms==list_tu[i].getmaso()){
                                              cout<< "Ma so da ton tai"<<endl;
                                                                    };
                                   } while (ms==list_tu[i].getmaso());
                               }
                           dn.nhapdn(ms);
                           list_donghe.push_back(dn);
                           dn.luudn();
                           break;
                          };
                    case 2:{ int a;
                      string sua;
                      string st;
                         for (size_t i = 0; i < list_donghe.size(); i++)
                         {
                          list_donghe[i].xuats();
                         }
                          cout<< "Ban muon sua"<<endl;
                          cout<<"co ma so"<<endl;
                            int ms;
                            cin>>ms;
                            cout<< "1.Ten"<<endl;
                            cout<< "2.Gia"<<endl;
                            cout<<"3.Tinh trang"<<endl;
                            cout<<"4.Mo ta"<<endl;
                            cout<<"5.Ten do nghe"<<endl;
                            cin>>a;
                          switch (a)
                          {
                          case 1:{
                            cout<<"Nhap ten muon sua"<<endl;
                            cin>>sua;
                            cout<<"sua thanh"<<endl;
                            cin>>st;
                            dn.suadn(ms,sua,st);
                            break;}
                          case 2:{
                            cout<<"Nhap gia muon sua"<<endl;
                            cin>>sua;
                             cout<<"sua thanh"<<endl;
                             cin>>st;
                            dn.suadn(ms,sua,st);
                            break;
                          }
                          case 3:{
                            cout<<"Nhap tinh trang muon sua"<<endl;
                            cin>>sua;
                            cout<<"sua thanh"<<endl;
                            cin>>st;
                            dn.suadn(ms,sua,st);
                            break;
                          }
                          case 4:{ 
                            cout<<"Nhap mo ta muon sua"<<endl;
                            getline(cin,sua);
                            cout<< "sua thanh"<<endl;
                            cin>>st;
                            dn.suadn(ms,sua,st);
                            break;
                          }
                          case 5:{
                            cout<<"Nhap ten do nghe muon sua"<<endl;
                            cin>>sua;
                            cout<< "Sua thanh"<<endl;
                            cin>>st;
                           dn.suadn(ms,sua,st);
                            break;
                          }
                          default:
                            break;
                          }
                         cout<<"sau khi sua"<<endl;
                         for (size_t i = 0; i < list_donghe.size(); i++)
                         {
                          list_donghe[i].xuatdn();
                         }
                       break;
                       }
                    case 3:{
                         for (size_t i = 0; i < list_donghe.size(); i++)
                         {
                          list_donghe[i].xuatdn();
                         }
                      break;}
                      case 4: {
                        cout<<"Nhap ma so muon xoa"<<endl;
                        cin>>ms;
                        dn.xoa(ms);
                      }
                    default:
                      break;
                   };
                   break;
    }
case 4:
      {int d;
    cout<< "1. Nhap thong tin"<<endl;
    cout<< "2. Sua thong tin" << endl;
    cout<< "3. Xem thong tin"<<endl;
    cout<< "4. Xoa"<<endl;
    cin>>d;
           switch (d){
                     case 1:{int ms;
                      for (size_t i = 0; i < list_tro.size(); i++)
                    { do
                     {
                     cout<< "Nhap thong tin tro:"<<endl;
                       cout<< " Nhap tro co ma so dau 105:"<<endl;
                        cin>>ms;
                       if (ms==list_tro[i].getmaso())
                       {
                        cout<< "Ma so da ton tai"<<endl;
                       };
                  } while (ms==list_tro[i].getmaso());
                    }
                            tr.nhapt(ms);
                            list_tro.push_back(tr);
                            tr.luutro();
                            break;
                            };
                     case 2:{ int a;
                      string sua;
                      string st;
                  for (size_t i = 0; i < list_tro.size(); i++)
                         {
                          list_tro[i].xuats();
                         }
                          cout<< "Ban muon sua"<<endl;
                          cout<<"co ma so"<<endl;
                          int ms;
                          cin>>ms;
                            cout<< "1.Ten"<<endl;
                            cout<< "2.Gia"<<endl;
                            cout<<"3.Tinh trang"<<endl;
                            cout<<"4.Mo ta"<<endl;
                            cout<<"5.Loai"<<endl;
                            cout<<"6.Gia tri"<<endl;
                            cin>>a;
                          switch (a)
                          {
                          case 1:{
                            cout<<"Nhap ten muon sua"<<endl;
                            cin>>sua;
                            cout<<"sua thanh"<<endl;
                            cin>>st;
                            tr.suatro(ms,sua,st);
                            break;}
                          case 2:{
                            cout<<"Nhap gia muon sua"<<endl;
                            cin>>sua;
                             cout<<"sua thanh"<<endl;
                             cin>>st;
                            tr.suatro(ms,sua,st);
                            break;
                          }
                          case 3:{
                            cout<<"Nhap tinh trang muon sua"<<endl;
                            cin>>sua;
                            cout<<"sua thanh"<<endl;
                            cin>>st;
                            tr.suatro(ms,sua,st);
                            break;
                          }
                          case 4:{ 
                            cout<<"Nhap mo ta muon sua"<<endl;
                            getline(cin,sua);
                            cout<< "sua thanh"<<endl;
                            tr.suatro(ms,sua,st);
                            break;
                          }
                          case 5:{
                            cout<<"Nhap loai muon sua"<<endl;
                            cin>>sua;
                            cout<< "Sua thanh"<<endl;
                            cin>>st;
                            tr.suatro(ms,sua,st);
                            break;
                          }
                          case 6:{
                            cout<< "Nhap gia tri muon sua"<<endl;
                            cin>>sua;
                            cout<<"Sua thanh"<<endl;
                            cin>>st;
                           tr.suatro(ms,sua,st);
                           break;
                          }
                          default:
                            break;
                          }
                         cout<<"sau khi sua"<<endl;
                         for (size_t i = 0; i < list_tro.size(); i++)
                         {
                          list_tro[i].xuatt();
                         }
                       break;
                       }
                      case 3: {
                        for (size_t i = 0; i < list_tro.size(); i++)
                        {
                          list_tro[i].xuatt();
                        }
                        break;
                      }
                      case 4: {
                        cout<<"Nhap ma so muon xoa dau 105:"<<endl;
                        cin>>ms;
                        tr.xoa(ms);
                        break;
                      }
                     default:
                           break;
                     };
                     break;
        }
case 5:  
  {int e;
    cout<< "1. Nhap thong tin"<<endl;
    cout<< "2. Sua thong tin" << endl;
    cout<< "3. Xem thong tin"<<endl;
    cout<< "4. Xoa"<<endl;
    cin>>e;
         switch (e){
                  case 1:{
                    for (size_t i = 0; i < list_tu.size(); i++)
                    { do
                        {
                     cout<< "Nhap thong tin tu:"<<endl;
                       cout<< " Nhap tu co ma so dau 106:"<<endl;
                        cin>>ms;
                       if (ms==list_tu[i].getmaso() )
                       {
                        cout<< "Ma so da ton tai"<<endl;
                       };
                         } while (ms==list_tu[i].getmaso());
                    }
                        t.nhaptu(ms);
                        list_tu.push_back(t);
                        t.luutu();
                        break;}
                 case 2:{ int a;
                  string st;
                  string sua;
                  for (size_t i = 0; i < list_tu.size(); i++)
                         {
                          list_tu[i].xuats();
                         }
                          cout<< "Ban muon sua"<<endl;
                          cout<<"co ma so"<<endl;
                           int ms; cin>>ms;
                            cout<< "1.Ten"<<endl;
                            cout<< "2.Gia"<<endl;
                            cout<<"3.Tinh trang"<<endl;
                            cout<<"4.Mo ta"<<endl;
                            cout<<"5.loai "<<endl;
                            cout<<" 6.Gia tri"<<endl;
                            cin>>a;
                          switch (a)
                          { 
                          case 1:{
                            cout<<"Nhap ten muon sua"<<endl;
                            cin>>sua;
                            cout<<"sua thanh"<<endl;
                            cin>>st;
                            t.suatu(ms,sua,st);
                            break;}
                          case 2:{
                            cout<<"Nhap gia muon sua"<<endl;
                            cin>>sua;
                             cout<<"sua thanh"<<endl;
                             cin>>st;
                            t.suatu(ms,sua,st);
                            break;
                          }
                          case 3:{
                            cout<<"Nhap tinh trang muon sua"<<endl;
                            cin>>sua;
                            cout<<"sua thanh"<<endl;
                            cin>>st;
                            t.suatu(ms,sua,st);
                            break;
                          }
                          case 4:{ 
                            cout<<"Nhap mo ta muon sua"<<endl;
                            getline(cin,sua);
                            cout<< "sua thanh"<<endl;
                            cin>>st;
                            t.suatu(ms,sua,st);
                            break;
                          }
                          case 5:{
                            cout<<"Nhap loai muon sua"<<endl;
                            cin>>sua;
                            cout<< "Sua thanh"<<endl;
                            cin>>st;
                            t.suatu(ms,sua,st);
                            break;
                          }
                          case 6:{
                            cout<< "Nhap gia tri muon sua"<<endl;
                            cin>>sua;
                            cout<<"Sua thanh"<<endl;
                            cin>>st;
                            t.suatu(ms,sua,st);
                            break;
                          }
                          default:
                            break;
                          }{
                         cout<<"sau khi sua"<<endl;
                         for (size_t i = 0; i < list_tu.size(); i++)
                         {
                          list_tu[i].xuattu();
                         }
                       break;}
                       }
                       case 3: {
                        for (size_t i = 0; i < list_tu.size(); i++)
                        {
                         list_tu[i].xuattu();
                        } break;
                       }
                       case 4: {
                        cout<<"Nhap ma so muon xoa dau 106:"<<endl;
                        cin>>ms;
                        t.xoa(ms);
                       }
                 default:
                       break;
                    };
                    break;
 }
case 6:
      {int f;
    cout<< "1. Nhap thong tin"<<endl;
    cout<< "2. Sua thong tin" << endl;
    cout<< "3. Xem thong tin"<<endl;
    cout<< "4. Xoa"<<endl;
    cin>>f;
           switch (f){
                     case 1:{
                      for (size_t i = 0; i < list_nguon.size(); i++)
                    { do
                       {
                       cout<< "Nhap thong tin nguon:"<<endl;
                       cout<< " Nhap nguon co ma so dau 107:"<<endl;
                        cin>>ms;
                       if (ms==list_nguon[i].getmaso())
                       {
                        cout<< "Ma so da ton tai"<<endl;
                       };
                       } while (ms==list_nguon[i].getmaso());
                    }
                            ng.nhapn(ms);
                            list_nguon.push_back(ng);
                            ng.luun();
                            break;     
                          };
                    case 2:{ int a;
                      string st;
                      string sua;
                  for (size_t i = 0; i < list_nguon.size(); i++)
                         {
                          list_nguon[i].xuats();
                         }
                          cout<< "Ban muon sua"<<endl;
                          cout<<"co ma so"<<endl;
                            int ms; cin>> ms;
                            cout<< "1.Ten"<<endl;
                            cout<< "2.Gia"<<endl;
                            cout<<"3.Tinh trang"<<endl;
                            cout<<"4.Mo ta"<<endl;
                            cout<<"5.Loai nguon"<<endl;
                            cin>>a;
                          switch (a)
                          {
                          case 1:{
                            cout<<"Nhap ten muon sua"<<endl;
                            cin>>sua;
                            cout<<"sua thanh"<<endl;
                            cin>>st;
                            ng.suan(ms,sua,st);
                            break;}
                          case 2:{
                            cout<<"Nhap gia muon sua"<<endl;
                            cin>>sua;
                             cout<<"sua thanh"<<endl;
                             cin>>st;
                            ng.suan(ms,sua,st);
                            break;
                          }
                          case 3:{
                            cout<<"Nhap tinh trang muon sua"<<endl;
                            cin>>sua;
                            cout<<"sua thanh"<<endl;
                            cin>>st;
                            ng.suan(ms,sua,st);
                            break;
                          }
                          case 4:{ 
                            cout<<"Nhap mo ta muon sua"<<endl;
                            getline(cin,sua);
                            cout<< "sua thanh"<<endl;
                           ng.suan(ms,sua,st);
                            break;
                          }
                          case 5:{
                            cout<<"Nhap loai muon sua"<<endl;
                            cin>>sua;
                            cout<< "Sua thanh"<<endl;
                            cin>>st;
                            ng.suan(ms,sua,st);
                            break;
                          }
                          default:
                            break;
                          }
                         cout<<"sau khi sua"<<endl;
                         for (size_t i = 0; i < list_nguon.size(); i++)
                         {
                          list_nguon[i].xuatn();
                         }
                       break;
                       }
                           case 3:{
                            for (size_t i = 0; i < list_nguon.size(); i++)
                            {
                             list_nguon[i].xuatn();
                            }
                            break;
                           }
                           case 4: {
                            cout<<"Nhap ma so muon xoa dau 107:"<<endl;
                            cin>>ms;
                            ng.xoa(ms);
                           }
                      default:
                            break;
                    };
                    break;
    }
case 7:
ql.gopfile();
      ql.display();
      break;
case 10:{
    string xoa;
    cout<< "Thong tin muon xoa"<< endl;
    cin>>xoa;
   ql.xoafile(xoa);
   break;
       }
case 9 : 
  ql.searchfile();
}
}
 while (n!=8);
    return 0;
}