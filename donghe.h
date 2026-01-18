#ifndef DONGHE_H
#define DONGHE_H
#include"linhkien.h"
#include<vector>
#include<string>
class donghe : public linhkien
{
private:
    std::string tenfile;
    std::string tendonghe;
public:
    donghe();
    std::string gettendn() const;
    void settendn(const std::string &ten);
    void nhapdn(int maso);
    void xuatdn();
    void luudn();
    void xuatfv();
    void xuats();
    void xoa(int &ms);
    void suadn(int ms,const std::string &sua, const std::string &suathanh);
    ~donghe();
};
extern std::vector<donghe> list_donghe;
#endif