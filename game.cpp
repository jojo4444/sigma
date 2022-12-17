#include "game.h"

Game::Game(Word *dict) a(dict), b(dict){
}

Game::~Game(){

}

bool Game::go(std::string word, int step){

}

bool Game::finish() const {
    return a.getHp() <= 0 || b.getHp() <= 0; 
}