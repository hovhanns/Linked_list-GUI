#ifndef LIST_BASE_H
#define LIST_BASE_H

#include <string>
using std::string;
class List_base
{
public:
    List_base(){}
    virtual ~List_base(){}
    virtual string show() = 0;
    virtual void sort() = 0;
    virtual void reverse() = 0;
    virtual void deleteAt(int) =0;
};

#endif
