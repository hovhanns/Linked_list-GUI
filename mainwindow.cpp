#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVector>
#include <QString>

#include "list_view.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_btn = new QPushButton(tr("Create"));
    connect(m_btn, SIGNAL(clicked()),
                          this, SLOT(create_clicked()));
    m_lbl = new QLabel(tr("Type: "));
    m_cbox = new QComboBox;
    QVector <QString> types = {"int", "char", "double"};
    for(int i = 0; i< types.size(); i++)
    {
        m_cbox->addItem((QString)types[i]);
    }

    QHBoxLayout * top_layout = new QHBoxLayout;
    top_layout->addWidget(m_lbl);
    top_layout->addWidget(m_cbox);
    top_layout->addWidget(m_btn);

    setWindowTitle("Create linked list");
    QWidget *wid = new QWidget();
    wid->setLayout(top_layout);
    setCentralWidget(wid);
}


void MainWindow::create_clicked()
{
    QString m_box_text = m_cbox->currentText();    
    List_view *vi;
    if(m_box_text=="int")        
        vi = new List_view(list_type::t_int,m_box_text);
    else
        if(m_box_text=="char")
            vi = new List_view(list_type::t_char,m_box_text);
        else
            if(m_box_text=="double")
                vi = new List_view(list_type::t_double,m_box_text);
    vi->show();
}
MainWindow::~MainWindow()
{
    delete m_btn;
    delete m_cbox;
    delete m_lbl;
}
