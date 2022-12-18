#include "game_interface.hpp"

void GameInterface::drawLettersBar(const vector<char>& letters, int player){
    int rowNum = player == 1? 13 : 3;
    shiftCol(-85);
    shiftRow(rowNum - 1);
    for (int i = 3, j = 0; j < letters.size(); j++, i += 4){
        shiftCol(i - 1);
        cells[rowNum - 1][i - 1].sym = '╔';
        cells[rowNum - 1][i - 1].paint();
        shiftCol(i);
        cells[rowNum - 1][i].sym = '═';
        cells[rowNum - 1][i].paint()
        shiftCol(i + 1);
        cells[rowNum - 1][i + 1].sym = '╗';
        cells[rowNum - 1][i + 1].paint()
    }
    shiftToBeginCol();
    shiftRow(rowNum + 1);
    for (int i = 3, j = 0; j < letters.size(); j++, i += 4){
        shiftCol(i - 1);
        cells[rowNum + 1][i - 1].sym = '╚';
        cells[rowNum + 1][i - 1].paint()
        shiftCol(i);
        cells[rowNum + 1][i].sym = '═';
        cells[rowNum + 1][i].paint()
        shiftCol(i + 1);
        cells[rowNum + 1][i + 1].sym = '╝';
        cells[rowNum + 1][i + 1].paint()
    }
    shiftToBeginCol();
    shiftRow(rowNum);
    for (int i = 3, j = 0; j < letters.size(); j++, i += 4){
        
        shiftCol(i - 1);
        cells[rowNum][i - 1].sym = '║';
        cells[rowNum][i - 1].paint();

        shiftCol(i);
        cells[rowNum][i].sym = letters[j];
        cells[rowNum][i].paint();

        shiftCol(i + 1);
        cells[rowNum][i - 1].sym = '║';
        cells[rowNum][i - 1].paint();
    }
    shiftToBeginCol();
    shiftRow(-rowNum);
    shiftCol(85);
}

void GameInterface::drawHpBar(int hp, int player){
  auto str = std::to_string(hp);
  int rowNum = player == 1? 18 : 10
  shiftCol(-85);
  shiftRow(rowNum);
  const int mcol = 6;
  for (int i = (str.size() >> 1), j = mcol; i >= 0; --i, --j){
    cells[rowNum][j].sym = str[i];
    cells[rowNum][j].paint();
  }
  for (int i = (str.size() >> 1) + 1, j = mcol + 1; i < str.size(); ++i, ++j){
    cells[rowNum][j].sym = str[i];
    cells[rowNum][j].paint();
  }
  shiftToBeginCol();
  shiftRow(-rowNum);
  shiftCol(85);
}