#include <iostream>
#include <vector>

void gameboard(std::vector<char> a) {
  std::cout << " " << a[0] << " | " << a[1] << " | " << a[2] << " \n";
  std::cout << "---+---+---\n";
  std::cout << " " << a[3] << " | " << a[4] << " | " << a[5] << " \n";
  std::cout << "---+---+---\n";
  std::cout << " " << a[6] << " | " << a[7] << " | " << a[8] << " \n";
};

int player_turn(int player_num, std::vector<char> answers) {
  int choice;
  bool choice_loop = true;
  while(choice_loop){
  std::cout << "Player "<< player_num << "\'s Turn: ";
    std::cin >> choice;
    choice -= 1;
    if(answers[choice] == 'X' || answers[choice] == 'O'){
      std::cout << "Space already taken!\n";
    } else {
      choice_loop = false;
    }
  }
  return choice;
}

bool new_answer_check(std::vector<char> answers, std::vector<std::vector<int> > keys) {
  for(int i = 0; i < keys.size(); i++){
    if(answers[keys[i][0]] == 'X' && answers[keys[i][1]] == 'X' && answers[keys[i][2]] == 'X') {
      std::cout << "Player 1 Wins!\n";
      return false;
    } else if(answers[keys[i][0]] == 'O' && answers[keys[i][1]] == 'O' && answers[keys[i][2]] == 'O') {
      std::cout << "Player 2 Wins!\n";
      return false;
    } 

  }
  return true;
}

int main() {
  std::vector<char> answers = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
  std::vector<std::vector<int> > keys{ {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6} }; 
  bool game_loop = true;

  std::cout << "===========\nTIC-TAC-TOE\n===========\n";

  gameboard(answers);
  while (game_loop == true) {
    answers[player_turn(1, answers)] = 'X';
    gameboard(answers);
    game_loop = new_answer_check(answers, keys);
    if(game_loop == false) {
      break;
    }
    answers[player_turn(2, answers)] = 'O';
    gameboard(answers);
    game_loop = new_answer_check(answers, keys);
  }
}

/*
clear; g++ ttt.cpp; ./a.out
*/