#include "List_interface.h"
List_interface::List_interface(list_type e_type)
{
    m_type = e_type;
    switch (m_type)
    {
        case t_int: m_lst = new List <int>; break;
        case t_double: m_lst = new List <double>; break;
        case t_char: m_lst = new List <char>; break;
    }
}
List_interface::~List_interface()
{
    delete m_lst;
}
void List_interface::sort()
{
    m_lst->sort();
}
void List_interface::reverse()
{
    m_lst->reverse();
}
string List_interface::show()
{
    return m_lst->show();
}

void List_interface::deleteAt(int pos)
{
    m_lst->deleteAt(pos);
}
void List_interface::pop_back()
{
    switch (m_type)
    {
        case t_int:
            static_cast <List <int> * > (m_lst)->pop_back();
            break;
        case t_double:
            static_cast <List <double> * > (m_lst)->pop_back();
            break;
        case t_char:
            static_cast <List <char> * > (m_lst)->pop_back();
            break;
    }
}
void List_interface::pop_front()
{
    switch (m_type)
    {
        case t_int:
            static_cast <List <int> * > (m_lst)->pop_front();
            break;
        case t_double:
            static_cast <List <double> * > (m_lst)->pop_front();
            break;
        case t_char:
            static_cast <List <char> * > (m_lst)->pop_front();
            break;
    }
}
