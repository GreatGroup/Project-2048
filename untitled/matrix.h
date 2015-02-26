#ifndef MATRIX_H
#define MATRIX_H

#include "QTime" // Классс необходим для получения случайного числа.
#include "QList"
class Matrix
{
public:
    Matrix();
    ~Matrix();

    /* Функция сдвига влево*/
    void left();

    /* Функция сдвига вправо*/
    void right();

    /* Функция сдвига вверх*/
    void up();

    /* Функция сдвига вних*/
    void down();

    /* Функция проверяет возможность сдвига влево*/
    bool canMoveLeft();
    bool canMoveLeftLine(int line);

    /* Функция проверяет возможность сдвига вправо*/
    bool canMoveRight();
    bool canMoveRightLine(int line);

    /*Функция проверяет возможность сдвига вверх*/
    bool canMoveUp();

    /*Функция проверяет возможность сдвига вниз*/
    bool canMoveDown();

    /*Структура для хранения состояния блока матрицы*/
    struct Block{
        int Value;
        bool Moved;
    };

    int getElementAt(int i, int j);

    int getCarma();

private:

    int carma;

    Block mMatrix [4][4];
    /**
     * @brief getRandomNullCoords -  Функция для получения координат случайного нуля
     * @param nulls - число нулей в матрице
     * @return - список из двух чисел, координаты нуля в матрице
     */
    QList<int> getRandomNullCoords(int nulls);

    /*Функция для получения числа нулей*/
    int getNullsCount();

    /* Функции для зануления матрицы */
    void setAllNulls();

    /*Функция для генерации случайного числоа 2||4*/
    int getRandomValue();

    void swapLeft(int i, int j);
    void swapRight(int i, int j);
    void swapUp(int i, int j);
    void swapDown(int i, int j);

    void setAllMovedFalse();
};
#endif // MATRIX_H
