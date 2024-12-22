#include "player.h"
#include <iostream>

using namespace std;

int main(){
    int totalPlayers;
    int games;
    int draws = 0;
    cout << "How many players?" << endl;
    cin >> totalPlayers;
    cout << "How many games?" << endl;
    cin >> games;

    int curPlayers = totalPlayers;

    int* wins = new int[totalPlayers];

    Player* player1 = new Player(0, nullptr, nullptr);
    Player* curPlayer = player1;

    for(int i = 1; i < totalPlayers; i++){
        curPlayer->setLeft(new Player(i, nullptr, curPlayer));
        curPlayer = curPlayer->getLeft();
    }
    curPlayer->setLeft(player1);
    player1->setRight(curPlayer);

    for(int i = 0; i < games; i++){
        curPlayer = player1;
        curPlayers = totalPlayers;
        while(!curPlayer->roll(curPlayers)){
            curPlayer = curPlayer->getLeft();
        }
        for(int j = 0; j < totalPlayers; j++){
            if(curPlayer->getCoins() != 0){
                wins[curPlayer->getNumber()]++;
            }
            curPlayer->reset();
            curPlayer = curPlayer->getLeft(); 
        }
        if((i+1)%(games/20) == 0 && i != 0){
            cout << "Simulated " << i+1 << " games." << endl;
        }
    }

    for(int i = 0; i < totalPlayers; i++){
        cout << "Player " << i+1 << " won " << static_cast<double>(wins[i])/games * 100 << "% of games" << endl;
    }

    return 0;
}