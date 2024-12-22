#ifndef PLAYER_H
#define PLAYER_H

class Player{
    private:
        int playerNumber;
        int coins = 3;
        Player* left;
        Player* right;
    public:
        Player(int playerNumber, Player* left, Player* right);
        bool roll(int& players);
        void reset();
        void setLeft(Player* left);
        void setRight(Player* right);
        Player* getLeft(){
            return left;
        }
        Player* getRight(){
            return right;
        }
        int getNumber(){
            return playerNumber;
        }
        int getCoins(){
            return coins;
        }
};

#endif