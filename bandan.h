#ifndef BANDAN_H
#define BANDAN_H
#include"linhkien.h"
#include<vector>
class bjt : public linhkien
{
private:
   std::string loai;
   std::string tenfile;
public:
   bjt();
    std::string getl() const;
    void setl(const std::string &l);
    void nhapbjt(int maso);
    void xuatbjt();
    void luubjt();
    void xuatfbv();
    void xuats();
    void xoab(int &ms);
    void suab(int ms,const std::string &sua, const std::string &suathanh);
    ~bjt();
};
extern std::vector<bjt> list_bjt;
class diode : public linhkien
{
private:
   std::string loai;
   std::string tenfile;
public:
    diode();
    ~diode();
void setloai(const std::string &l);
std::string getloai();

    void nhapdiode(int maso);
 void xuatdiode();
 void luudiode();
 void xuatfdv();
 void xoa(int &ms);
 void xuats();

 void suad(int ms,const std::string &sua, const std::string &suathanh);
};
extern std::vector<diode> list_diode;

#endif