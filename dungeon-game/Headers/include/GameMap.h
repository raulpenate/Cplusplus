# include "MapCell.h"

class GameMap
{
private:
public:
    GameMap();

    bool isGameOver;

    MapCell* PlayerCell;
    MapCell cells[15][10];

    void Draw();
    void DrawIntro();
    void DrawVictory();

    // We get player coords and update map accordingly
    bool SetPlayerCell(int PlayerX, int PlayerY);

protected:
    void LoadMapFile();
};