#include "list_view.h"

#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QString>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QRegExp>
#include <QRegExpValidator>
#include <QValidator>
#include <QDebug>
List_view::List_view(list_type e_type, QString list_type_str, QWidget *parent) :
    QWidget(parent)
{    

    m_type = e_type;
    list = new List_interface(e_type);

    b_push_back = new QPushButton("Push back");
    b_push_front= new QPushButton("Push front");
    b_insertAt= new QPushButton("Insert at");

    QVBoxLayout *v_insert_layout = new QVBoxLayout;
    v_insert_layout->addWidget(b_push_back);
    v_insert_layout->addWidget(b_push_front);
    v_insert_layout->addWidget(b_insertAt);



    b_pop_back= new QPushButton("Pop back");
    b_pop_front= new QPushButton("Pop front");
    b_deleteAt= new QPushButton("Delete at");

    QVBoxLayout *v_delete_layout = new QVBoxLayout;
    v_delete_layout->addWidget(b_pop_back);
    v_delete_layout->addWidget(b_pop_front);
    v_delete_layout->addWidget(b_deleteAt);


    b_sort = new QPushButton("Sort");

    QHBoxLayout * h_del_ins_layout = new QHBoxLayout;
    h_del_ins_layout->addLayout(v_insert_layout);
    h_del_ins_layout->addLayout(v_delete_layout);

    b_reverse = new QPushButton("reverse");


    QVBoxLayout * all_btn = new QVBoxLayout;
    all_btn->addLayout(h_del_ins_layout);
    all_btn->addWidget(b_sort);
    all_btn->addWidget(b_reverse);



    l_value = new QLabel("value");
    line_value = new QLineEdit;
    QVBoxLayout * value_layout = new QVBoxLayout;
    value_layout->addWidget(l_value);
    value_layout->addWidget(line_value);

    l_position = new QLabel("position");
    line_position = new QLineEdit;
    QVBoxLayout * position_layout = new QVBoxLayout;
    position_layout->addWidget(l_position);
    position_layout->addWidget(line_position);

    QHBoxLayout * value_position_lay = new QHBoxLayout;
    value_position_lay->addLayout(value_layout);
    value_position_lay->addLayout(position_layout);

    l_status = new QLabel("[*] Status");

    QString m_list_type_str = list_type_str;
    g_box = new QGroupBox("Your " + m_list_type_str+" list");

    QVBoxLayout *main_layout = new QVBoxLayout;
    linked_list = new QLabel("");
    main_layout->addWidget(linked_list);
    main_layout->addLayout(all_btn);
    main_layout->addLayout(value_position_lay);
    main_layout->addWidget(l_status);


    QObject::connect(b_push_back, SIGNAL(clicked()), this, SLOT(b_push_back_clicked()));
    QObject::connect(b_push_front, SIGNAL(clicked()), this, SLOT(b_push_front_clicked()));

    QObject::connect(b_pop_back, SIGNAL(clicked()), this, SLOT(b_pop_back_clicked()));
    QObject::connect(b_pop_front, SIGNAL(clicked()), this, SLOT(b_pop_front_clicked()));

    QObject::connect(b_insertAt, SIGNAL(clicked()), this, SLOT(b_insertAt_clicked()));
    QObject::connect(b_deleteAt, SIGNAL(clicked()), this, SLOT(b_deleteAt_clicked()));

    QObject::connect(b_sort, SIGNAL(clicked()), this, SLOT(b_sort_clicked()));
    QObject::connect(b_reverse, SIGNAL(clicked()), this, SLOT(b_reverse_clicked()));

    switch (e_type)
    {
        case t_int:
            line_value->setValidator( new QRegExpValidator(QRegExp("[0-9]{0,5}")));
            break;
        case t_double:
            line_value->setValidator( new QRegExpValidator(QRegExp("[0-9]{0,5}")));
            break;
        case t_char:
            line_value->setValidator( new QRegExpValidator(QRegExp("[A-Za-z0-9]{0,1}")));
            break;
    }


    line_position->setValidator(new QRegExpValidator(QRegExp("[0-9][0-9]{0,1}")));



    setLayout(main_layout);
}


List_view::~List_view()
{
    delete b_push_back;
    delete b_push_front;
    delete b_pop_back;
    delete b_pop_front;
    delete b_insertAt;
    delete b_deleteAt;
    delete b_sort;
    delete b_reverse;
    delete g_box;
    delete l_value;
    delete l_position;
    delete line_value;
    delete line_position;
    delete l_status;
    delete linked_list;
    delete list;
}
void List_view::set_linked_list()
{
    linked_list->setText(QString::fromStdString(list->show()));
}

void List_view::b_push_back_clicked()
{
    if(line_value->text()=="")
        return;
    QString val =  line_value->text();
    line_value->clear();
    switch (m_type)
    {
        case t_int:
            list->push_back(val.toInt());
            break;
        case t_double:
            list->push_back(val.toDouble());
            break;
        case t_char:
            list->push_back(val.at(0).toLatin1());
            break;
    }
    set_linked_list();

    l_status->setStyleSheet("QLabel { background-color : grey; color : blue; }");
    l_status->setText("[*] value inserted");


}
void List_view::b_push_front_clicked()
{
    if(line_value->text()=="")
        return;
    QString val =  line_value->text();
    line_value->clear();
    switch (m_type)
    {
        case t_int:
            list->push_front(val.toInt());
            break;
        case t_double:
            list->push_front(val.toDouble());
            break;
        case t_char:
            list->push_front(val.at(0).toLatin1());
            break;
    }
    set_linked_list();
    l_status->setStyleSheet("QLabel { background-color : grey; color : blue; }");
    l_status->setText("[*] value inserted");
}

void List_view::b_pop_back_clicked()
{
    list->pop_back();
    set_linked_list();

    l_status->setStyleSheet("QLabel { background-color : yellow; color : black; }");
    l_status->setText("[!] value deleted");
}
void List_view::b_pop_front_clicked()
{
    list->pop_front();
    set_linked_list();

    l_status->setStyleSheet("QLabel { background-color : yellow; color : black; }");
    l_status->setText("[!] value deleted");
}

void List_view::b_insertAt_clicked()
{
    if(line_value->text()=="")
        return;
    QString val =  line_value->text();
    QString pos = line_position->text();

    int i_pos = pos.toInt();

    switch (m_type)
    {
        case t_int:
            list->insertAt(i_pos, val.toInt());
            break;
        case t_double:
            list->insertAt(i_pos,val.toDouble());
            break;
        case t_char:
            list->insertAt(i_pos,(val.at(0)).toLatin1());
            break;
    }

    i_pos++;

    line_value->clear();
    line_position->clear();
    line_position->setText(QString::number( i_pos));
    set_linked_list();
    l_status->setStyleSheet("QLabel { background-color : grey; color : blue; }");
    l_status->setText("[*] value inserted");
}
void List_view::b_deleteAt_clicked()
{
    QString pos = line_position->text();
    int i_pos = pos.toInt();
    list->deleteAt(i_pos);
    if(i_pos>0)
        i_pos--;

    line_position->setText(QString::number(i_pos));
    set_linked_list();
    l_status->setStyleSheet("QLabel { background-color : yellow; color : black; }");
    l_status->setText("[!] value deleted");
}
void List_view::b_sort_clicked()
{
    list->sort();
    set_linked_list();
    l_status->setStyleSheet("QLabel { background-color : green; color : yellow; }");
    l_status->setText("[*] list sorted");
}

void List_view::b_reverse_clicked()
{
    list->reverse();
    set_linked_list();
    l_status->setStyleSheet("QLabel { background-color : green; color : yellow; }");
    l_status->setText("[*] list reversed");
}
