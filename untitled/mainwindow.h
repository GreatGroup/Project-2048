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
#include <QKeyEvent>

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

    void on_tableWidget_itemSelectionChanged();

    void on_left_clicked();

    void on_right_clicked();

    void on_down_clicked();

    void on_up_clicked();

protected:
    void keyPressEvent(QKeyEvent* event);

private:
    Ui::MainWindow *ui;
    Matrix matrix;
    QMap<int, QString> colorMap;
    void setupTable();
    void changeTable();
    QList<QTableWidgetItem *>  tableItems; //[4][4] *tableItems;
};

#endif // MAINWINDOW_H
