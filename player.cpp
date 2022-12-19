#include "player.hpp"

Player::Player(int hp) : hp_(hp) {}

int Player::getHp() const {
    return hp_;
}

vector<char> Player::getLets() const {
    vector<char> res = let_;
    std::sort(res.begin(), res.end(), [](char a, char b) {
        bool a_glas = (a == 'a' || a == 'e' || a == 'u' || a == 'o' || a == 'i');
        bool b_glas = (b == 'a' || b == 'e' || b == 'u' || b == 'o' || b == 'i');
        if (a_glas != b_glas) {
            return a_glas > b_glas;
        }
        return a < b;
    });
    return res;
}

void Player::updHp(int dh) {
    hp_ += dh;
}

void Player::turn(const string& word) {    
    for(char c : word){
        let_.erase(std::find(let_.begin(), let_.end(), c));
    }
}

bool Player::checkTurn(const string& word) const {
    std::map<char, int> mp;
    for (char c: let_) {
        mp[c]--;
    }
    for(char c : word) if (++mp[c] > 0) {
        return false;
    }
    return true;
}

void Player::addNewLetters(const vector<char>& nlet) {    
    let_.insert(let_.end(), nlet.begin(), nlet.end());
}

void Player::updateLetters(const vector<char>& nlet) {    
    let_ = nlet;
}

