#ifndef TU_H
#define TU_H
#include"linhkien.h"
#include<vector>
class tu :public linhkien
{
private:
    std::string giatri ;
    std::string loai;
    std::string tenfile;
public:
    tu();
    void setgiatri(const std::string &gt);
    std::string getgiatri() const;
    void setloai(const std::string &l);
    std::string getloai() const;
   void nhaptu(int maso);
   void xuattu();
   void xuats();
   void luutu();
   void xuatfv();
   void xoa(int &ms);
   void suatu(int ms,const std::string &sua, const std::string &suathanh);
    ~tu();
};
extern std::vector<tu> list_tu;
#endif