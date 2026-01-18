#ifndef TRO_H
#define TRO_H
#include"linhkien.h"
#include<vector>
#include<string>
class tro :public linhkien
{
private:
    std::string giatri;
    std::string loai;
    std::string tenfile;
public:
    tro();
    std::string getgiatri() const;
    void setgiatri(const std::string &gt);
    std::string getloai() const ;
    void setloai(const std::string &l);
    void nhapt(int maso);
    void xuatt();
    void xuats();
    void luutro();
    void xuatfv();
    void xoa(int &ms);
    void suatro(int ms,const std::string &sua, const std::string &suathanh);
    ~tro();
};
 extern std::vector<tro> list_tro;
#endif 