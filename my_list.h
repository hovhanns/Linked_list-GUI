#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include "list_base.h"
template <class T>
struct Node
{
    T data;
    struct Node *next;
};
template <class T>
class List : public List_base
{
public:
    List();
    ~List();
    List(const List &);
    void push_back(T);
    void push_front(T);
    void pop_back();
    void pop_front();
    virtual string show();
    bool empty() const;
    virtual void sort();
    void swap(T&, T&);
    T& operator[] (unsigned int );
    void insertAt(int, T);
    void deleteAt(int);
    void reverse();
    int size() const;
private:
    Node <T>* start;
    int m_size;
};
template <class T>
List<T>::List()
{
    start = NULL;
    m_size = 0;
}
template <class T>
List<T>::List(const List &obj)
{
    Node<T> * temp_start = obj.start;
    m_size = obj.m_size;
    start = NULL;
    while(temp_start!=NULL)
    {
        this->push_back(temp_start->data);
        temp_start = temp_start->next;
    }
    delete temp_start;
}
template <class T>
List<T>::~List()
{
    while(start!=NULL)
    {
        Node<T> * temp_start = start;
        delete temp_start;
        start = start->next;
    }
}
template <class T>
void List<T>::push_back(T val)
{
    m_size++;
    Node<T> *temp = new Node<T>;
    temp->data = val;
    temp->next = NULL;
    Node<T> * temp_start = start;
    if (start!=NULL)
    {
        while(start->next!= NULL)
        {
            start = start ->next;
        }
        start -> next = temp;
        start = temp_start;
    }
    else
        start  = temp;
}
template <class T>
void List<T>::push_front(T val)
{
    m_size++;
    Node<T> *temp = new Node<T>;
    temp->data = val;
    temp ->next = start;
    start = temp;
}
template <class T>
void List<T>::pop_back()
{
    Node<T> * temp_start = start;
    if (empty())
    {
        return;
    }
    m_size--;
    if (start -> next == NULL)
    {
        start = NULL;
        delete temp_start;
        return;
    }
    Node<T> * temp;
    while(temp_start->next!=NULL)
    {
        temp = temp_start;
        temp_start = temp_start->next;
    }
    temp->next = NULL;
    delete temp_start;
}
template <class T>
void List<T>::pop_front()
{
    if (empty())
        return;
    m_size--;
    Node<T> * temp_start = start;
    start = start->next;
    delete temp_start;
}
template <class T>
string List <T>::show()
{
    string line = "";
    if (empty())
        return line;
    Node<T> * temp_start = start;
    if(typeid(T).name()==typeid(char).name())
        while(temp_start!=NULL)
        {
            line.push_back(temp_start->data);
            line+=" -> ";
            temp_start = temp_start->next;
        }
    else
        while(temp_start!=NULL)
        {
            line+=  std::to_string(temp_start->data);
            line+=" -> ";
            temp_start = temp_start->next;
        }
    line.pop_back();
    line.pop_back();
    line.pop_back();
    return line;
}
template <class T>
bool List <T>::empty() const
{
    if (start == NULL)
        return true;
    else
        return false;
}
template <class T>
int List <T>:: size() const
{
    return m_size;
}
template <class T>
void List <T>:: sort()
{
    if(empty())
        return;
    struct Node<T> *tmpPtr = start;
    struct Node<T> *tmpNxt = start->next;
    int tmp;
    while(tmpNxt != NULL)
    {
           while(tmpNxt != tmpPtr)
           {
                    if(tmpNxt->data < tmpPtr->data)
                    {
                            tmp = tmpPtr->data;
                            tmpPtr->data = tmpNxt->data;
                            tmpNxt->data = tmp;
                    }
                    tmpPtr = tmpPtr->next;
            }
            tmpPtr = start;
            tmpNxt = tmpNxt->next;
    }
}
template <class T>
T& List <T>::operator[](unsigned int i)
{
    static int e;
    if (i>m_size)
        throw std::out_of_range("index is out of range");
    Node<T> * temp_start = start;
    while(i)
    {
        temp_start = temp_start->next;
        i--;
    }
    return temp_start->data;
}
template <class T>
void List <T>::swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
template <class T>
void List <T>::insertAt(int index, T value)
{
    if (index == 0)
    {
        push_front(value);
        return;
    }
    if (index == m_size)
    {
        push_back(value);
        return;
    }
    if (index > m_size || index < 0)
    {
        throw std::out_of_range("index is out of range");
        return;
    }
    int i = 1;
    Node<T> * temp_start = start;
    Node<T> * temp  = new Node <T>;
    temp->data = value;
    temp->next = NULL;
    while(i!=index)
    {
        temp_start = temp_start->next;
        i++;
    }
    temp->next = temp_start->next;
    temp_start->next = temp;
}
template <class T>
void List <T>::deleteAt(int index)
{
    if (index ==0)
    {
        pop_front();
        return;
    }
    if (index == m_size)
    {
        pop_back();
        return;
    }
    if (index > m_size)
    {
        throw std::out_of_range("index is out of range");
        return;
    }
    if (index < 0)
    {
        throw std::out_of_range("index is out of range");
        return;
    }
    int i = 1;
    Node<T> * temp_start = start->next;
    Node<T> * prev  = start;
    while(i!=index)
    {
        temp_start = temp_start->next;
        prev = prev->next;
        i++;
    }
    prev->next = temp_start->next;
    delete temp_start;
}
template <class T>
void List <T>::reverse()
{
    if (empty())
        return;
    Node<T> * current = NULL;
    Node<T> *prev = NULL;
    Node<T> *next = NULL;
    current = start;
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    start = prev;
}
#endif
