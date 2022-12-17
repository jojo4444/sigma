#include "player.h"

Player::Player(Dict *dict_): hp(0), dict(dict_) {
}

Player::~Player() {
}

int Player::getHp() const {
    return hp;
}

vector<char> Player::getLet() const {
    return let;
}

void Player::addLetter(char c) {
    let.push_back(c);
}

void Player::updHp(int dh) {
    hp += dh;
}

tuple<bool, int, int> Player::go(const string& word) {    
    if (!checkWordLetters(word)){
        return tuple<bool, int, int> (false, 0, 0);
    }
    auto stat = dict->getWordStat(word);
    erraseLetters(word);
    return tuple<bool, int, int> (true, stat.add, stat.del);

}

vector<string> Player::getHints() const {
    return dict->getHints(let);
}

void Player::erraseLetters(const string& word){
    for(char c : word){
        auto found = std::find(let.begin(), let.end(), c);
        let.erase(found);
    }
} 

bool Player::checkWordLetters(const string& word) const{
    std::map<char, int> mp;
    for(char c : word){
        mp[c]++;
    }
    for (char c: let){
        mp[c]--;
    }
    for (auto [c, cnt]: mp) if (cnt > 0){
        return false;
    }
    return true;
}
