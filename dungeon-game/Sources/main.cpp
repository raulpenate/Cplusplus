#include <iostream>
#include "Player.h"
#include "MapCell.h"
#include "GameMap.h"
#include <Enemy.h>

using namespace std;

int main()
{
    GameMap Map;
    Player Hero;

    Map.DrawIntro();

    while (Map.isGameOver == false)
    {
        Hero.CallInput();

        if(Map.SetPlayerCell(Hero.x, Hero.y))
        {
            Map.Draw();
        }
        else
        {
            Hero.ResetToSafePosition();
            Map.Draw();
        }
    }
    
    Hero.CallInput();

    return 0;
}