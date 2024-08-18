class Enemy
{
    private:
    public:
        Enemy();

        int x,y;

        void setPosition(int PositionX, int PositionY);

        void moveInX(bool move);

        void moveInY(bool move);
        
        void moveInRandomTp(int maxX, int maxY);

        void moveInRandomWalk(int maxX, int maxY);
};