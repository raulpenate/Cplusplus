#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    public:
        Player();

        void CallInput();
        void ResetToSafePosition();
        
        int x, y;
        int lastX, lastY;

    protected:
    private:
};

#endif