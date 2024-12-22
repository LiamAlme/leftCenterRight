#include "player.h"
#include <stdlib.h>
#include <algorithm>
#include <iostream>

using namespace std;

Player::Player(int playerNumber, Player* left, Player* right): playerNumber(playerNumber), left(left), right(right){};

bool Player::roll(int& players){
    if(coins == 0){
        return false;
    }
    int rolls = min(3, coins);
    for(int i = 0; i < rolls; i++){
        int roll = rand()%6;
        if(roll > 2){
            coins--;
            if(roll == 3){
                if(left->coins == 0){
                    players++;
                }
                left->coins++;
            }
            else if(roll == 4){
                if(right->coins == 0){
                    players++;
                }
                right->coins++;
            }
        }
    }
    if(coins == 0){
        players--;
    }
    if(players == 1){
        return true;
    }
    return false;
}

void Player::reset(){
    coins = 3;
}

void Player::setLeft(Player* left){
    this->left = left;
}

void Player::setRight(Player* right){
    this->right = right;
}