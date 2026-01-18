#ifndef NGUON_H
#define NGUON_H
#include<string>
#include"linhkien.h"
#include<vector>
class nguon : public linhkien
{
private:
    std::string loainguon;
    std::string tenfile;
public:
    nguon();
    void setloainguon(const std::string &nguon);
    std::string getloainguon() const;
    void nhapn(int maso);
    void xuatn();
    void luun();
    void xuats();
    void xuatfv();
    void xoa(int &ms);
    void suan(int ms,const std::string &sua, const std::string &suathanh);
    ~nguon();
};
extern std::vector<nguon> list_nguon;

#endif