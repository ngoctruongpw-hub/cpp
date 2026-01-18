#ifndef FILE_H
#define FILE_H
#include<string>
class file
{
private:
    std::string filelk;
public:
    file(const std::string &file);
    void readfile();
    void xoafile(const std::string &xoa);
    void openfile();
    void searchfile();
    void gopfile();
    ~file();
};

#endif