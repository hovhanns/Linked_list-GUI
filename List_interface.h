#ifndef LIST_INTERFACE_H
#define LIST_INTERFACE_H

#include "my_list.h"
#include <string>
using std::string;

enum list_type{
        t_int, t_double, t_char };

class List_interface
{
public:
    List_interface(list_type =t_int);
    ~List_interface();

    template <typename T>
    void push_back(T val);

    template <typename T>
    void push_front(T val);

    void pop_back();
    void pop_front();

    void sort();
    void reverse();
    string show();

    void deleteAt(int pos);
    template <typename T>
    void insertAt(int, T);

private:
    List_base * m_lst;
    list_type m_type;
};
template <typename T>
void List_interface::push_back(T val)
{
    switch (m_type)
    {
        case t_int:
            static_cast <List <int> * > (m_lst)->push_back(val);
            break;
        case t_double:
            static_cast <List <double> * > (m_lst)->push_back(val);
            break;
        case t_char:
            static_cast <List <char> * > (m_lst)->push_back(val);
            break;
    }


}
template <typename T>
void List_interface::push_front(T val)
{
    switch (m_type)
    {
        case t_int:
            static_cast <List <int> * > (m_lst)->push_front(val);
            break;
        case t_double:
            static_cast <List <double> * > (m_lst)->push_front(val);
            break;
        case t_char:
            static_cast <List <char> * > (m_lst)->push_front(val);
            break;
    }
}
template <typename T>
void List_interface::insertAt(int pos, T val)
{
    switch (m_type)
    {
        case t_int:
            static_cast <List <int> * > (m_lst)->insertAt(pos, val);
            break;
        case t_double:
            static_cast <List <double> * > (m_lst)->insertAt(pos, val);
            break;
        case t_char:
            static_cast <List <char> * > (m_lst)->insertAt(pos, val);
            break;
    }
}
#endif
