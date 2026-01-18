#ifndef LINHKIEN_H
#define LINHKIEN_H
#include "file.h"
#include<string>
#include<vector>
class linhkien :public file
{
protected:
   int maso =0;
   std::string ten;
   std::string tinhtrang;
   std::string giatien ;
   std::string mota;
   std::string tenfile;
   
public:
    linhkien();
    std::string getten() const;
    std::string gettinhtrang()const ;
    std::string getmota() const;
    std::string getgiatien() const;
    int getmaso( ) const ;
    void setmaso(int  &ms);
    void setten(const std::string &t);
    void settinhtrang(const std::string &tt);
    void setmota(const std::string &mt);
    void setgiatien(const std::string &gia);
    void nhaplk(int ms);
    void xuatlk();
    ~linhkien();
};

#endif