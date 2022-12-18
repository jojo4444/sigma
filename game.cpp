#include "game.hpp"

Game::Game(Dict *dict): alice_(DEFAULT_PLAYER_HP), bob_(DEFAULT_PLAYER_HP), dict_(dict) {
    if (dict_ == nullptr) {
        std::cerr << "empty dictionary\n";
        exit(-1);        
    }
    alice_.addNewLetters(generateLetters(DEFAULT_PLAYER_LETTERS_COUNT));
    bob_.addNewLetters(generateLetters(DEFAULT_PLAYER_LETTERS_COUNT));
    hints_ = dict_->getHints(alice_.getLets());
}

pair<vectorHints, vectorHints> Game::getHints() const {
    return hints_;
}

Player Game::getPlayer(int player) const {
    return player == 1 ? alice_ : bob_;
}

bool Game::checkGo(const std::string& word, int player) const {
    if (!dict_->correct(word)) {
        return false;
    }
    if (!dict_->find(word)){
        return false;
    }
    if (player == 1 && !alice_.checkTurn(word)) {
        return false;
    }
    if (player == 2 && !bob_.checkTurn(word)) {
        return false;
    }
    return true;
}

void Game::go(const std::string& word, int player) {
    Player* current = &alice_;
    Player* opposite = &bob_;
    if (player == 2) {
        std::swap(current, opposite);
    }
    current->turn(word);

    wordStat stat = dict_->getWordStat(word);
    dict_->del(word);

    opposite->updHp(-stat.del);
    current->updHp(stat.add);
    current->addNewLetters(generateLetters(word.size()));

    hints_ = dict_->getHints(opposite->getLets());
}

bool Game::finish() const {
    return alice_.getHp() <= 0 || bob_.getHp() <= 0; 
}

vector<char> Game::generateLetters(int cnt) {
    vector<char> res(cnt);
    for(int i = 0; i < cnt; ++i) {
        res[i] = dict_->getLet();
    }
    return res;
}
