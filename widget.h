#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QFileDialog>
#include <QMessageBox>
#include <string>
#include <QApplication>
#include<QListWidget>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <QDebug>
#include <locale>
#include <codecvt>
#include<iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <unistd.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_into_parking_btn_clicked();

    void on_rate_check_btn_clicked();

    void on_search_btn_clicked();

    void on_leave_parking_btn_clicked();

    void on_end_btn_clicked();

    void on_listWidget_Test_itemClicked(QListWidgetItem *item);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
