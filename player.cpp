#include<player.h>

Player::Player(Word *dict_) hp(0), dict(dict_) {
}

Player::~Player(Word *dict) {
}

int Player::getHp() const {
    return hp;
}

std::vector<char> Player::getLet() const {
    return let;
}

void Player::updHp(int dh) {
    hp += dh;
}

std::tuple<bool, int, int> Player::go(std::string word) {

}

std::vector<std::string>  Player::getHints() {
    
}
