#include "game.h"

Game::Game(Word *dict): a(dict), b(dict){
}

Game::~Game(){

}

bool Game::go(const std::string& word, int step){
    if (used.count(word)){
        return false;
    }

    auto& [current, opposite] = step & 1 ? std::tie(a, b) : std::tie(b, a);
    auto [ok, heal, damage] = current.go(word);
    if (ok){
        current.updHp(heal);
        opposite.updHp(damage);
        used.insert(word);    
        hints = opposite.getHints();
    }

    return ok;
}

bool Game::finish() const {
    return a.getHp() <= 0 || b.getHp() <= 0; 
}