#include "Enemy.h"
#include <cstdlib>

Enemy::Enemy()
{
    x = 1;
    y = 1;
}

void Enemy::setPosition(int PositionX, int PositionY)
{
    x = PositionX;
    y = PositionY;
}

void Enemy::moveInX(bool move)
{
    if (move)
    {
        x = x + 1;
    }
    else
    {
        x = x - 1;
    }
} 

void Enemy::moveInY(bool move)
{
    if (move)
    {
        y = y + 1;
    }
    else
    {
        y = y - 1;
    }
}

void Enemy::moveInRandomWalk(int maxX, int maxY)
{
    int rngMove = rand() % 4;

    if(rngMove == 0){
        x = x + 1;
    }

    if(rngMove == 1){
        x = x - 1;
    }

    if(rngMove == 2){
        y = y + 1;
    }

    if(rngMove == 3){
        y = y - 1;
    }
}

void Enemy::moveInRandomTp(int maxX, int maxY)
{
    int rngMove = rand() % 2;

    if(rngMove == 0){
        x = rand() % maxX;
    }

    if(rngMove == 1){
        y = rand() % maxY;
    }

}