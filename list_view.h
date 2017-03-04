#ifndef LIST_VIEW_H
#define LIST_VIEW_H

#include <QWidget>
#include <QString>
class QPushButton;
class QLabel;
class QGroupBox;
class QString;
class QLineEdit;


#include "List_interface.h"

class List_view : public QWidget
{
    Q_OBJECT

public:
    explicit List_view(list_type, QString list_type_str, QWidget *parent = 0);
    ~List_view();
signals:
public slots:
private:
    QPushButton *b_push_back;
    QPushButton *b_push_front;

    QPushButton *b_pop_back;
    QPushButton *b_pop_front;

    QPushButton *b_insertAt;
    QPushButton *b_deleteAt;

    QPushButton *b_sort;
    QPushButton *b_reverse;

    QGroupBox *g_box;

    QLabel  *l_value;
    QLabel  *l_position;

    QLineEdit *line_value;
    QLineEdit *line_position;

    QLabel  *l_status;
    QLabel *linked_list;

    List_interface * list;
    list_type m_type;
    void set_linked_list();
private slots:
    void b_push_back_clicked();
    void b_push_front_clicked();

    void b_pop_back_clicked();
    void b_pop_front_clicked();

    void b_insertAt_clicked();
    void b_deleteAt_clicked();
    void b_sort_clicked();
    void b_reverse_clicked();
};

#endif // LIST_VIEW_H
