#include <iostream>
#include "Player.h"

Player::Player()
{
    x = 1;
    y = 1;

    lastX = 1;
    lastY = 1;
}

void Player::CallInput()
{
    char UserInput = ' ';

    std::cin >> UserInput;

    std::cout << UserInput << std::endl;

    switch (UserInput)
    {
    case 'a':
        lastY = y;
        y = y - 1;
        std::cout << "Player moves left" << std::endl;
        break;

    case 's':
        lastY = y;
        y = y + 1;
        std::cout << "Player right" << std::endl;
        break;

    case 'r':
        lastX = x;
        x = x + 1;
        std::cout << "Player down" << std::endl;
        break;

    case 'w':
        lastX = x;
        x = x - 1;
        std::cout << "Player up" << std::endl;
        break;

    default:
        break;
    }

    std::cout << "Player is in coords" << y << "," << x << std::endl;
} 

void Player::ResetToSafePosition()
{
    x = lastX;
    y = lastY;
}