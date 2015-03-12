#include "matrix.h"

Matrix::Matrix()
{
    carma = 0;
    countOfTilesGenedWithVFour = 0;
    countOfTilesGenedWithVTwo = 0;
    setAllNulls();
    QList<int> null = getRandomNullCoords(getNullsCount());
    mMatrix[null.at(0)][null.at(1)].Value = getRandomValue();
    if (mMatrix[null.at(0)][null.at(1)].Value == 2)
        countOfTilesGenedWithVTwo++;
    else
        countOfTilesGenedWithVFour++;
    null = getRandomNullCoords(getNullsCount());
    mMatrix[null.at(0)][null.at(1)].Value = getRandomValue();
    if (mMatrix[null.at(0)][null.at(1)].Value == 2)
        countOfTilesGenedWithVTwo++;
    else
        countOfTilesGenedWithVFour++;
}

Matrix::~Matrix()
{

}

void Matrix::left()
{
    if (canMoveLeft()){
        for (int i=0; i<4; i++) {
            for(int j=0; j<3; j++) {
                if ((mMatrix[i][j].Value == mMatrix[i][j+1].Value)
                        &&(!mMatrix[i][j].Moved)&&(!mMatrix[i][j+1].Moved)
                        &&(mMatrix[i][j].Value!=0)){
                    swapLeft(i, j);
                    continue;
                }
                if ((mMatrix[i][j].Value*mMatrix[i][j+1].Value==0)
                        &&(mMatrix[i][j].Value+mMatrix[i][j+1].Value!=0)
                        &&(!mMatrix[i][j].Moved)&&(!mMatrix[i][j+1].Moved)
                        &&(mMatrix[i][j+1].Value!=0)){
                    swapLeft(i, j);
                    continue;
                }
            }
        }
        QList<int> null = getRandomNullCoords(getNullsCount());
        mMatrix[null.at(0)][null.at(1)].Value = getRandomValue();
        setAllMovedFalse();
    }
    if (!canMoveLeft()||!canMoveRight()||!canMoveUp()||!canMoveDown()){
        // Сигнал о том что больше ходов нет.
    }
}

bool Matrix::canMoveLeft()
{
    for (int i=0; i<4; i++) {
        if (canMoveLeftLine(i))
            return true;
    }
    return false;
}

bool Matrix::canMoveLeftLine(int line)
{
    for(int j=0; j<3; j++) {
        if ((mMatrix[line][j].Value == mMatrix[line][j+1].Value)
                &&(!mMatrix[line][j].Moved)&&(!mMatrix[line][j+1].Moved)
                &&(mMatrix[line][j].Value!=0)){
            return true;
        }
        if ((mMatrix[line][j].Value*mMatrix[line][j+1].Value==0)
                &&(mMatrix[line][j].Value+mMatrix[line][j+1].Value!=0)
                &&(!mMatrix[line][j].Moved)&&(!mMatrix[line][j+1].Moved)
                &&(mMatrix[line][j+1].Value!=0)){
            return true;
        }
    }
    return false;
}

void Matrix::swapLeft(int i, int j)
{
    if (mMatrix[i][j].Value!= 0) {
        mMatrix[i][j].Moved = true;
        carma += mMatrix[i][j].Value*2;
    }
    mMatrix[i][j].Value = mMatrix[i][j].Value + mMatrix[i][j+1].Value;
    mMatrix[i][j+1].Value = 0;
    if (j > 0){
        if (mMatrix[i][j-1].Value == 0){
            swapLeft(i, j-1);
        }
        if ((mMatrix[i][j-1].Value == mMatrix[i][j].Value)
                &&(!mMatrix[i][j].Moved)&&(!mMatrix[i][j-1].Moved)){
            swapLeft(i, j-1);
            if (mMatrix[i][j].Value!= 0)
                mMatrix[i][j].Moved = true;
        }
    }
}

void Matrix::right()
{
    if (canMoveRight()){
        for (int i=0; i<4; i++) {
            for(int j=3; j>0; j--) {
                if ((mMatrix[i][j].Value == mMatrix[i][j-1].Value)
                        &&(!mMatrix[i][j].Moved)&&(!mMatrix[i][j-1].Moved)
                        &&(mMatrix[i][j].Value!=0)){
                    swapRight(i, j);
                    continue;
                }
                if ((mMatrix[i][j].Value*mMatrix[i][j-1].Value==0)
                        &&(mMatrix[i][j].Value+mMatrix[i][j-1].Value!=0)
                        &&(!mMatrix[i][j].Moved)&&(!mMatrix[i][j-1].Moved)
                        &&(mMatrix[i][j-1].Value!=0)){
                    swapRight(i, j);
                    continue;
                }
            }
        }
        QList<int> null = getRandomNullCoords(getNullsCount());
        mMatrix[null.at(0)][null.at(1)].Value = getRandomValue();
        setAllMovedFalse();
    }
    if (!canMoveLeft()||!canMoveRight()||!canMoveUp()||!canMoveDown()){
        // Сигнал о том что больше ходов нет.
    }
}

bool Matrix::canMoveRight()
{
    for (int i=0; i<4; i++) {
        if(canMoveRightLine(i))
            return true;
    }
    return false;
}

bool Matrix::canMoveRightLine(int line)
{
    for(int j=3; j>0; j--) {
        if ((mMatrix[line][j].Value == mMatrix[line][j-1].Value)
                &&(!mMatrix[line][j].Moved)&&(!mMatrix[line][j-1].Moved)
                &&(mMatrix[line][j].Value!=0)){
            return true;
        }
        if ((mMatrix[line][j].Value*mMatrix[line][j-1].Value==0)
                &&(mMatrix[line][j].Value+mMatrix[line][j-1].Value!=0)
                &&(!mMatrix[line][j].Moved)&&(!mMatrix[line][j-1].Moved)
                &&(mMatrix[line][j-1].Value!=0)){
            return true;
        }
    }
    return false;
}

void Matrix::swapRight(int i, int j)
{
    if (mMatrix[i][j].Value!= 0) {
        mMatrix[i][j].Moved = true;
        carma += mMatrix[i][j].Value*2;
    }
    mMatrix[i][j].Value = mMatrix[i][j].Value + mMatrix[i][j-1].Value;
    mMatrix[i][j-1].Value = 0;
    if (j < 3){
        if (mMatrix[i][j+1].Value == 0){
            swapRight(i, j+1);
        }
        if ((mMatrix[i][j+1].Value == mMatrix[i][j].Value)
                &&(!mMatrix[i][j].Moved)&&(!mMatrix[i][j+1].Moved)){
            swapRight(i, j+1);
            if (mMatrix[i][j].Value!= 0)
                mMatrix[i][j].Moved = true;
        }
    }

}

void Matrix::up()
{
    if (canMoveUp()){
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < 3; i++){
                if ((mMatrix[i][j].Value == mMatrix[i+1][j].Value)
                        &&(!mMatrix[i][j].Moved)&&(!mMatrix[i+1][j].Moved)
                        &&(mMatrix[i][j].Value!=0)){
                    swapUp(i, j);
                    continue;
                }
                if ((mMatrix[i][j].Value*mMatrix[i+1][j].Value==0)
                        &&(mMatrix[i][j].Value+mMatrix[i+1][j].Value!=0)
                        &&(!mMatrix[i][j].Moved)&&(!mMatrix[i+1][j].Moved)
                        &&(mMatrix[i+1][j].Value!=0)){
                    swapUp(i, j);
                    continue;
                }
            }
        }
        QList<int> null = getRandomNullCoords(getNullsCount());
        mMatrix[null.at(0)][null.at(1)].Value = getRandomValue();
        setAllMovedFalse();
    }
    if (!canMoveLeft()||!canMoveRight()||!canMoveUp()||!canMoveDown()){
        // Сигнал о том что больше ходов нет.
    }
}

bool Matrix::canMoveUp()
{
    for (int j = 0; j < 4; j++) {
        if (canMoveUpColone(j))
            return true;
    }
    return false;
}

bool Matrix::canMoveUpColone(int colone)
{
    for (int i = 0; i < 3; i++){
        if ((mMatrix[i][colone].Value == mMatrix[i+1][colone].Value)
                &&(!mMatrix[i][colone].Moved)&&(!mMatrix[i+1][colone].Moved)
                &&(mMatrix[i][colone].Value!=0)){
            return true;
        }
        if ((mMatrix[i][colone].Value*mMatrix[i+1][colone].Value==0)
                &&(mMatrix[i][colone].Value+mMatrix[i+1][colone].Value!=0)
                &&(!mMatrix[i][colone].Moved)&&(!mMatrix[i+1][colone].Moved)
                &&(mMatrix[i+1][colone].Value!=0)){
            return true;
        }
    }
    return false;
}

void Matrix::swapUp(int i, int j)
{
    if (mMatrix[i][j].Value!= 0) {
        mMatrix[i][j].Moved = true;
        carma += mMatrix[i][j].Value*2;
    }
    mMatrix[i][j].Value = mMatrix[i][j].Value + mMatrix[i+1][j].Value;
    mMatrix[i+1][j].Value = 0;
    if (i > 0){
        if (mMatrix[i-1][j].Value == 0){
            swapUp(i-1, j);
        }
        if ((mMatrix[i-1][j].Value == mMatrix[i][j].Value)
                &&(!mMatrix[i][j].Moved)&&(!mMatrix[i-1][j].Moved)){
            swapUp(i-1, j);
            if (mMatrix[i][j].Value!= 0)
                mMatrix[i][j].Moved = true;
        }
    }
}

void Matrix::down()
{
    if (canMoveDown()){
        for (int j = 0; j < 4; j++) {
            for (int i = 3; i > 0; i--){
                if ((mMatrix[i][j].Value == mMatrix[i-1][j].Value)
                        &&(!mMatrix[i][j].Moved)&&(!mMatrix[i-1][j].Moved)
                        &&(mMatrix[i][j].Value!=0)){
                    swapDown(i, j);
                    continue;
                }
                if ((mMatrix[i][j].Value*mMatrix[i-1][j].Value==0)
                        &&(mMatrix[i][j].Value+mMatrix[i-1][j].Value!=0)
                        &&(!mMatrix[i][j].Moved)&&(!mMatrix[i-1][j].Moved)
                        &&(mMatrix[i-1][j].Value!=0)){
                    swapDown(i, j);
                    continue;
                }
            }
        }
        QList<int> null = getRandomNullCoords(getNullsCount());
        mMatrix[null.at(0)][null.at(1)].Value = getRandomValue();
        setAllMovedFalse();
    }
    if (!canMoveLeft()||!canMoveRight()||!canMoveUp()||!canMoveDown()){
        // Сигнал о том что больше ходов нет.
    }
}

bool Matrix::canMoveDown()
{
    for (int j = 0; j < 4; j++) {
        if(canMoveDownColone(j))
            return true;
    }
    return false;
}

bool Matrix::canMoveDownColone(int colone)
{
    for (int i = 3; i > 0; i--){
        if ((mMatrix[i][colone].Value == mMatrix[i-1][colone].Value)
                &&(!mMatrix[i][colone].Moved)&&(!mMatrix[i-1][colone].Moved)
                &&(mMatrix[i][colone].Value!=0)){
            return true;
        }
        if ((mMatrix[i][colone].Value*mMatrix[i-1][colone].Value==0)
                &&(mMatrix[i][colone].Value+mMatrix[i-1][colone].Value!=0)
                &&(!mMatrix[i][colone].Moved)&&(!mMatrix[i-1][colone].Moved)
                &&(mMatrix[i-1][colone].Value!=0)){
            return true;
        }
    }
    return false;
}

void Matrix::swapDown(int i, int j)
{
    if (mMatrix[i][j].Value!= 0) {
        mMatrix[i][j].Moved = true;
        carma += mMatrix[i][j].Value*2;
    }
    mMatrix[i][j].Value = mMatrix[i][j].Value + mMatrix[i-1][j].Value;
    mMatrix[i-1][j].Value = 0;
    if (i < 4){
        if (mMatrix[i+1][j].Value == 0){
            swapDown(i+1, j);
        }
        if ((mMatrix[i+1][j].Value == mMatrix[i][j].Value)
                &&(!mMatrix[i][j].Moved)&&(!mMatrix[i+1][j].Moved)){
            swapDown(i+1, j);
            if (mMatrix[i][j].Value!= 0)
                mMatrix[i][j].Moved = true;
        }
    }
}

int Matrix::getElementAt(int i, int j)
{
    return mMatrix[i][j].Value;
}

int Matrix::getCarma()
{
    return carma;
}

QList<int> Matrix::getRandomNullCoords(int nulls)
{
    QTime midnight(0,0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));

    QList<int> result;
    result << -1 << -1;
    int randomValue;
    randomValue = qrand() % nulls;
    int nullCounter = -1;
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (mMatrix[i][j].Value == 0){
                nullCounter++;
                if (nullCounter == randomValue){
                    result.clear();
                    result << i << j;
                    return result;
                }
            }
        }
    }
    return result;
}

int Matrix::getNullsCount()
{
    int result = 0;
    for (int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if (mMatrix[i][j].Value == 0){
                result++;
            }
        }
    }
    return result;
}

void Matrix::setAllNulls()
{
    for (int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            mMatrix[i][j].Value = 0;
            mMatrix[i][j].Moved = false;
        }
    }
}

int Matrix::getRandomValue()
{
    QTime midnight(0,0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));

    int randomValue;
    randomValue = qrand() % 2; // Получаем 0 или 1
    return (randomValue+1)*2; //Возвращаем 2 или 4
}

void Matrix::setAllMovedFalse()
{
    for (int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            mMatrix[i][j].Moved = false;
        }
    }
}
