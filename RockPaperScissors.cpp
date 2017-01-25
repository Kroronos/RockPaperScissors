#include "iostream"
#include "stdafx.h"
#include "string"
#include "cctype"
#include "ctime"

using namespace std;

char makeRandomChoice() {
	srand(time(NULL));

	int determiner = rand() % 3;

	if (determiner == 0) {
		return 'S';
	}

	if (determiner == 1) {
		return 'P';
	}

	if (determiner == 2) {
		return 'R';
	}

	return 'P';

}

char aiMakeChoice(char a, char b, bool c) {
	
	//If Previous Result was draw select at random
	if (a == b) {
		return makeRandomChoice();
	}
	//Opponent won
	if (c == true) {
		//Operate under assumption that winning player is unlikely to change 
		if (b == 'S') {
			return 'P';
		}

		if (b == 'R') {
			return 'S';
		}

		if (b == 'P') {
			return 'S';
		}

	}

	//Opponent lost
	if (c == false) {
		if (b == 'S') {
			return a;
		}

		if (b == 'R') {
			return a;
		}

		if (b == 'P') {
			return a;
		}
	}

	return 'P';
}

void printRules() {
	cout << endl << "Rock beats scissors. Scissors beats paper. Paper beats rock" << endl << "Enter P for Paper, R for Rock, or S for scissors" << endl;
}

int whoWins(char a, char b) {

	//Return 0 if draw
	if (a == b)
		return 0;

	//Return 1 if player 1 wins
	if (b == 'S' && a == 'R') {
		return 1;
	}

	//Return 2 if player 2 wins
	if (a == 'S' && b == 'R') {
		return 2;
	}

	if (a == 'P' && b == 'R') {
		return 1;
	}

	if (b == 'P' && a == 'R') {
		return 2;
	}

	if (a == 'S' && b == 'P') {
		return 1;
	}

	if (b == 'S' && a == 'P') {
		return 2;
	}

	return -1;
}


int main()
{
	//Print welcome menu
	cout << "Welcome to Rock Paper Scissors" << endl;
	cout << endl << "Would you like to play a two player or a single player game?" << endl;

	int playerSelection = 0;
	while(playerSelection == 0) {

		//First single v. two player selection
		cout << "1. Single Player" << endl << "2. Two Player" << endl;

		//Process cin to remove bad input / avoid input mismatch
		cin >> playerSelection;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (playerSelection == 0) {
			cout << "Please enter a valid input";
		}
	}

	//Put gameplay instantiation into loop so that player may continue playing for as long as they want
	int gameLoop = 0;
	while (gameLoop == 0) {
		
		//Single player
		if (playerSelection == 1) {
			//Make player select number of rounds they would like to play
			cout << "How many rounds would you like to play?" << endl;
			int roundSelection = 0;
			cin >> roundSelection;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			while (roundSelection == 0) {
				cout << "Invalid Choice. Please enter a valid selection." << endl;
				cin >> roundSelection;

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			char previousPlayerWin = false;
			char playerOnePreviousChoice = 'a';
			char playerOneChoice = 'a';

			char aiPreviousChoice = 'a';
			char aiChoice = 'a';
			printRules();

			for (int i = 0; i < roundSelection; i++) {
				if (i == 0)
					aiChoice = makeRandomChoice();

				if (i > 0) {
					//Have aiMakeChoice based on prior rounds
					char aiChoice = aiMakeChoice(playerOnePreviousChoice, aiPreviousChoice, previousPlayerWin);
				}

				//Log Player One's Selection
				cout << "Player One Enter Your Selection \n";
				cin >> playerOneChoice;
				//Process cin
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				//Fix To Upper
				playerOneChoice = toupper(playerOneChoice);

				while (playerOneChoice != 'S' && playerOneChoice != 'R' && playerOneChoice != 'P') {
					cout << "Invalid choice. Please choose a valid selection. \n";
					cin >> playerOneChoice;
					//Process cin
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}

				//Determine winner
				int victory = whoWins(playerOneChoice, aiChoice);

				if (victory == 0)
					cout << "It's a draw! \n" << endl;

				if (victory == 1)
					cout << "You win! \n" << endl;

				if (victory == 2)
					cout << "You lose! \n" << endl;

				//Set previous move variables based on round
				playerOnePreviousChoice = playerOneChoice;
				aiPreviousChoice = aiChoice;

			}

			cout << endl << "Press 1 if you would like to play again." << endl << "Press 2 if you would like to exit." << endl << endl;
			//User input determines if gameloop continues
			int userInt;
			cin >> userInt;

			//Process cin
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			//Exit condition
			gameLoop = userInt - 1;

			if (gameLoop == 0) {
				//Reset playerSelection
				playerSelection = 0;
				while (playerSelection == 0) {
					//Second single v. two player selection
					cout << "1. Single Player" << endl << "2. Two Player" << endl;

					//Process cin to remove bad input / avoid input mismatch
					cin >> playerSelection;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					if (playerSelection == 0) {
						cout << "Please enter a valid input";
					}
				}
			}
			
		}

		//Two player
		if (playerSelection == 2) {

			//Make player select number of rounds they would like to play
			cout << "How many rounds would you like to play?" << endl;
			int roundSelection = 0;
			cin >> roundSelection;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			while (roundSelection == 0) {
				cout << "Invalid Choice. Please enter a valid selection." << endl;
			}
			char playerOneChoice = 'a';
			char playerTwoChoice = 'a';
			printRules();
			
			for (int i = 0; i < roundSelection; i++) {
				//Log Player One's Selection
				cout << "Player One Enter Your Selection \n";
				cin >> playerOneChoice;
				//Process cin
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				//Fix To Upper
				playerOneChoice = toupper(playerOneChoice);

				while (playerOneChoice != 'S' && playerOneChoice != 'R' && playerOneChoice != 'P') {
					cout << "Invalid choice. Please choose a valid selection. \n";
					cin >> playerOneChoice;
					//Process cin
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}

				//Log Player Two's Selection
				cout << "Player Two Enter Your Selection \n ";
				cin >> playerTwoChoice;

				//Process cin
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				//Fix To Upper
				playerTwoChoice = toupper(playerTwoChoice);

				while (playerTwoChoice != 'S' && playerTwoChoice != 'R' && playerTwoChoice != 'P') {
					cout << "Invalid choice. Please choose a valid selection. \n";
					cin >> playerTwoChoice;
					//Process cin
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}

				int victory = whoWins(playerOneChoice, playerTwoChoice);

				if (victory == 0)
					cout << "\n It's a draw! \n" << endl;

				if (victory == 1)
					cout << "\n Player 1 wins! \n" << endl;

				if (victory == 2)
					cout << "\n Player 2 wins! \n" << endl;
			}
			
			
			cout << endl << "Press 1 if you would like to play again." << endl << "Press 2 if you would like to exit." << endl << endl;
			//User input determines if gameloop continues
			int userInt;
			cin >> userInt;

			//Process cin
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
			//Exit Condition
			gameLoop = userInt -1;

			if (gameLoop == 0) {
				//Reset playerSelection
				playerSelection = 0;
				while (playerSelection == 0) {
					//Second single v. two player selection
					cout << "1. Single Player" << endl << "2. Two Player" << endl;

					//Process cin to remove bad input / avoid input mismatch
					cin >> playerSelection;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					if (playerSelection == 0) {
						cout << "Please enter a valid input";
					}
				}
			}
		}
	}
    return 0;
}

