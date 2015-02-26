#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QString>
#include <QTableWidgetItem>
#include <QLabel>
#include <QBrush>
#include <QColor>
#include <QFont>
#include <QMap>

#include "matrix.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Matrix matrix;
    QMap<int, QString> colorMap;
    void setupTable();
    void changeTable();
    QList<QTableWidgetItem *>  tableItems; //[4][4] *tableItems;
};

#endif // MAINWINDOW_H
