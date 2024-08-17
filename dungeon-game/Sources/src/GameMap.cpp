#include "GameMap.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

GameMap::GameMap()
{
    isGameOver = false;
    PlayerCell = NULL;
    LoadMapFile();
}


void GameMap::Draw()
{
    for (int i = 0; i < 15; i++)
    {
        for (int p = 0; p < 10; p++)
        {
            cout << cells[i][p].id;
        }
        cout << endl;
    }
}

void GameMap::DrawIntro()
{
    string line;
    int row = 0;
    ifstream MyFile("Intro.txt");

    if(MyFile.is_open())
    {
        while (getline(MyFile, line))
        {
            cout << line << endl;
        }

        cin >> line;

    }
    else{
        cout << "FATAL ERROR: INTRO FILE COULD NOT BE LOADED!" << endl;
    }
}

void GameMap::DrawVictory()
{
    string line;
    int row = 0;
    ifstream MyFile("Victory.txt");

    if(MyFile.is_open())
    {
        while (getline(MyFile, line))
        {
            cout << line << endl;
        }

        cin >> line;

    }
    else{
        cout << "FATAL ERROR: INTRO FILE COULD NOT BE LOADED!" << endl;
    }
}

bool GameMap::SetPlayerCell(int PlayerX, int PlayerY)
{
    if(cells[PlayerX][PlayerY].IsBlocked() == false){
        if(cells[PlayerX][PlayerY].id == '$')
        {
            DrawVictory();
            return true;
        }
        else
        {
            if(PlayerCell != NULL)
            {
                PlayerCell->id = ' ';
            }

            PlayerCell = &cells[PlayerX][PlayerY];
            PlayerCell->id = 'H';
        }

        return true;
    }
    else{
        return false;
    }

}

void GameMap::LoadMapFile()
{
    // ofstream FileCreated("Map.txt");

    // if(FileCreated.is_open()){

    // }else{
    //     cout << "FATAL ERROR: MAP FILE COULD NOT BE LOADED!" << endl;
    // }

    string line;
    int row = 0;
    ifstream MyFile("Map.txt");

    if(MyFile.is_open())
    {
        while (getline(MyFile, line))
        {
            for(int p = 0; p < line.length(); p++)
            {
                if(line[p] == ' ')
                    cells[row][p].id = ' ';
                else{
                    cells[row][p].id = line[p];
                }
            }

            row++;

            cout << line << endl;
        }
        
    }
    else{
        cout << "FATAL ERROR: MAP FILE COULD NOT BE LOADED!" << endl;
    }
}