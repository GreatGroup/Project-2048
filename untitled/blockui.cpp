#include "blockui.h"
#include "ui_blockui.h"

BlockUI::BlockUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlockUI)
{
    ui->setupUi(this);
}

BlockUI::~BlockUI()
{
    delete ui;
}
