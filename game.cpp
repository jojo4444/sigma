#include "game.h"

Game::Game(Dict *dict_): a(dict_), b(dict_), dict(dict_){
}

Game::~Game(){

}

bool Game::go(const std::string& word, int step){
    if (used.count(word)){
        return false;
    }
    if (dict->find(word)){
        return false;
    }
    auto& current = a, opposite = b;
    if (step == 2){
        std::swap(current, opposite);
    }
    auto [ok, heal, damage] = current.go(word);
    if (!ok){
        return false;
    }
    current.updHp(heal);
    opposite.updHp(damage);
    used.insert(word);

    //hints = opposite.getHints();
    for (int i = 0; i < word.size(); ++i){
        current.addLetter(dict->getLet());
    }
    
    return ok;
}



bool Game::finish() const {
    return a.getHp() <= 0 || b.getHp() <= 0; 
}