#include "game.h"

Game::Game(Dict *dict_): a(0), b(0), dict(dict_){
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
    if (!current.go(word)){
        return false;
    }
    auto stat = dict->getWordStat(word);
    current.updHp(stat.add);
    opposite.updHp(stat.del);
    used.insert(word);

    addLetterToPlayer(current, word.size());

    return true;
}

bool Game::finish() const {
    return a.getHp() <= 0 || b.getHp() <= 0; 
}

void Game::addLetterToPlayer(Player& player, int cnt){
    for(int i = 0; i < cnt; ++i){
        player.addLetter(dict->getLet());
    }
}

vector<string> Game::getHints(const Player& player) const{
    return dict->getHints(player.getLet());
}
