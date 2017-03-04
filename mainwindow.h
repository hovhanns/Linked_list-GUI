#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QString>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void create_clicked();

private:
    QPushButton *m_btn;
    QLabel *m_lbl;
    QComboBox *m_cbox;

};

#endif // MAINWINDOW_H
