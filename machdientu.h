#ifndef MACHDIENTU_H
#define MACHDIENTU_H
#include"linhkien.h"
#include<string>
#include<vector>
class machdientu :public linhkien
{
private:
    std::string loaimach;
    std::string tenfile;
public:
    machdientu(/* args */);
    std::string getloaimach() const;
    void setloaimach(const std::string &mach);
    void nhapm(int maso);
    void xuatm();
    void luum();
    void xuats();
    void xoa(int &ms);
    void suam(int ms,const std::string &sua, const std::string &suathanh);
    void xuatfv();

    ~machdientu();
};
extern std::vector<machdientu> list_machdientu;
#endif