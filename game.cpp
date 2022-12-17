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

vector<pair<string, wordStat> > Game::getHints() const {
    return hints_;
}

bool Game::go(const std::string& word, int step) {
    if (!dict_->find(word)){
        return false;
    }
    Player& current = alice_, opposite = bob_;
    if (step == 2) {
        std::swap(current, opposite);
    }
    if (!current.makeTurn(word)) {
        return false;
    }
    wordStat stat = dict_->getWordStat(word);
    dict_->del(word);

    opposite.updHp(-stat.del);
    current.updHp(stat.add);
    current.addNewLetters(generateLetters(word.size()));

    hints_ = dict_->getHints(opposite.getLets());

    return true;
}

bool Game::finish() const {
    return alice_.getHp() <= 0 || bob_.getHp() <= 0; 
}

vector<char> Game::generateLetters(int cnt) {
    vector<char> res(cnt);
    for(int i = 0; i < cnt; ++i){
        res[i] = dict_->getLet();
    }
    return res;
}
