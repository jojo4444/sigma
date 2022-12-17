#include "game.h"

Game::Game(Dict *dict_): a(dict_), b(dict_), dict(dict_){
    addLetterToPlayer(a, 10);
    addLetterToPlayer(b, 10);
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

    addLetterToPlayer(current, word.size());

    return ok;
}

bool Game::finish() const {
    return a.getHp() <= 0 || b.getHp() <= 0; 
}

void Game::addLetterToPlayer(Player& player, int cnt){
    for(int i = 0; i < cnt; ++i){
        player.addLetter(dict->getLet());
    }
}
