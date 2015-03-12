#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObjectList objList = ui->centralWidget->children();
    for (int i = 0; i < objList.size(); i++){
        if (objList.at(i)->objectName() != "codeArea")
            objList.at(i)->installEventFilter(this);
    }
    colorMap[0] = "#CCC0B3";
    colorMap[2] = "#EEE4DA";
    colorMap[4] = "#EDE0C8";
    colorMap[8] = "#F2B179";
    colorMap[16] = "#F59563";
    colorMap[32] = "#F67C5F";
    colorMap[64] = "#F65E3B";
    colorMap[128] = "#EDCF72";
    colorMap[256] = "#EDCC61";
    colorMap[512] = "#EDC850";
    colorMap[1024] = "#EDC53F";
    colorMap[2048] = "#EDC22E";
    setupTable();
    changeTable();
    ui->carma->setText(QString::number(matrix.getCarma()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupTable()
{
    QTableWidget * table = ui->tableWidget;
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setColumnCount(4);
    table->setRowCount(4);
    for (int i = 0; i < 4; i++){
        table->horizontalHeader()->resizeSection(i, 101);
        table->verticalHeader()->resizeSection(i, 101);

    }
    for (int i = 0; i < 4; i++){
        for (int j =0; j < 4; j++){
            QTableWidgetItem *item = new QTableWidgetItem("");
            QFont font;
            font.setPixelSize(35);
            font.setBold(true);
            item->setTextColor(QColor("#2F2D2B"));
            item->setBackgroundColor(QColor (colorMap.value(0, 0)));
            item->setFont(font);
            item->setTextAlignment(0x0084);
            tableItems << item;
            table->setItem(i, j, item);
        }
    }

}

void MainWindow::changeTable()
{
    int number = 0;
    for (int i = 0; i < 4; i++){
        for (int j =0; j < 4; j++){
            tableItems.at(number)->setBackgroundColor(QColor (colorMap.value(matrix.getElementAt(i, j), 0)));
            if (matrix.getElementAt(i, j) > 0)
                tableItems.at(number)->setText(QString::number(matrix.getElementAt(i, j)));
            else
                tableItems.at(number)->setText("");
            number++;
            //table->setItem(i, j, item);
        }
    }
}

void MainWindow::on_tableWidget_itemSelectionChanged()
{
    ui->tableWidget->clearSelection();
    clearFocus();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    switch (key) {
    case 0x01000012:
        on_left_clicked();
        break;
    case 0x01000013:
        on_up_clicked();
        break;
    case 0x01000014:
        on_right_clicked();
        break;
    case 0x01000015:
        on_down_clicked();
        break;
    default:
        break;
    }
}

void MainWindow::on_left_clicked()
{
    matrix.left();
    changeTable();
    ui->carma->setText(QString::number(matrix.getCarma()));
    ui->left->clearFocus();
}

void MainWindow::on_right_clicked()
{
    matrix.right();
    changeTable();
    ui->carma->setText(QString::number(matrix.getCarma()));
    ui->right->clearFocus();
}

void MainWindow::on_down_clicked()
{
    matrix.down();
    changeTable();
    ui->carma->setText(QString::number(matrix.getCarma()));
    ui->down->clearFocus();
}

void MainWindow::on_up_clicked()
{
    matrix.up();
    changeTable();
    ui->carma->setText(QString::number(matrix.getCarma()));
    ui->up->clearFocus();
}
/*bool MainWindow::eventFilter(QObject* obj, QEvent* event)
{
    Q_UNUSED(obj)

    if (event->type() == QEvent::KeyRelease) {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);

        switch (key->key()) {
        case Qt::Key_Left:
            on_left_clicked();
            break;
        case Qt::Key_Up:
            on_up_clicked();
            break;
        case Qt::Key_Right:
            on_right_clicked();
            break;
        case Qt::Key_Down:
            on_down_clicked();
            break;
        }
    }

    return QMainWindow::eventFilter(obj, event);
}*/
