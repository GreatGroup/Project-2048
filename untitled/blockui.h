ifndef BLOCKUI_H
#define BLOCKUI_H

#include <QWidget>

namespace Ui {
class BlockUI;
}

class BlockUI : public QWidget
{
    Q_OBJECT

public:
    explicit BlockUI(QWidget *parent = 0);
    ~BlockUI();

private:
    Ui::BlockUI *ui;
};

#endif // BLOCKUI_H
