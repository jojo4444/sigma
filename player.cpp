#include "player.hpp"

Player::Player(int hp) : hp_(hp) {}

int Player::getHp() const {
    return hp_;
}

vector<char> Player::getLets() const {
    return let_;
}

void Player::addLetter(char c) {
    let_.push_back(c);
}

void Player::updHp(int dh) {
    hp_ += dh;
}

bool Player::makeTurn(const string& word) {    
    if (!checkWordLetters(word)){
        return false;
    }
    erraseLetters(word);
    return true;
}

void Player::addNewLetters(const vector<char>& nlet) {    
    let_.insert(let_.end(), nlet.begin(), nlet.end());
}

void Player::erraseLetters(const string& word) {
    for(char c : word){
        let_.erase(std::find(let_.begin(), let_.end(), c));
    }
} 

bool Player::checkWordLetters(const string& word) const {
    std::map<char, int> mp;
    for (char c: let_) {
        mp[c]--;
    }
    for(char c : word) if (++mp[c] > 0) {
        return false;
    }
    return true;
}
