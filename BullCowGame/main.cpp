#include <iostream>
#include <string>
#include "FBullCowGame.h"

// these were changed to get more familiar with the unreal standards
using ftext = std::string;
using int32 = int;


void PrintIntro();
/*std:: is the standard library (can circumvent by using the "using" key word, but this is bad codding practice if using more than one namspace.
	Never use the "using" keyword in a header file because any class that imports that header will use that namespace.
 */
ftext getGuess();
FBullCowGame Game;
void PlayGame();
bool AskToReplay();
void PrintSummary();


int main(){
	
	
	do {
		PrintIntro();
		PlayGame();
	} while (AskToReplay());
	
	return 0; 
}


void PlayGame()
{
	FBullCowCount count;
	Game.Reset();// resets games values and hidden word to defaults

	int32 maxGuesses = Game.getMaxTries();

	//The turns of the game
	while(!(Game.IsGameWon()) && Game.getCurrentTry() <= maxGuesses) {
		
		ftext guess = getGuess(); //prompts user 4 guess and stores it as a string
		
	
		count = Game.awardAnimals(guess); //the method awardAnimals() calculates the amount of bulls and cows  and returns both values in a single type, "struct"
		std::cout << std::endl << "Bulls: " << count.bulls << std::endl << "Cows: " << count.cows << std::endl << std::endl;
	}
	PrintSummary();

}
  
bool AskToReplay()
{
	std::cout << "Would you like to play again?" << std::endl << "Y = yes, N = no" << std::endl;
	ftext choice = " ";
	getline(std::cin, choice);
	char first = choice[0];
	if (first == 'y' || first == 'Y')
	{
		return true;
	}
	else {
		if (first == 'n' || first == 'N')
		{
			return false;
		}
	}
}

void PrintSummary()
{
	if (Game.IsGameWon())
	{
		std::cout << "Congragulations you Won!!!!" << std::endl;
	}
	else
	{
		std::cout << "Better luck next time!" << std::endl;
	}
}



std::string getGuess() 
{
	EGuessValidity	validity = EGuessValidity::INVALID;
	do {
		int32 tryNum = Game.getCurrentTry();
		std::cout << std::endl << "Try " << tryNum << ": Enter your guess";
		std::cout << "(" << Game.getMaxTries() - Game.getCurrentTry() << " tries left)." << std::endl;
		std::string guess = "";
		getline(std::cin, guess);
		validity = Game.confirmWord(guess);	//submits guess to be validated returns an enumeration of the words validity
		switch (validity)
		{
		case EGuessValidity::WRONG_LENGTH:
			std::cout << "Please enter a word of the correct length." << std::endl << "The correct length should be " << Game.getHiddenWordLength() << " letters long.\n";
			break;
		case EGuessValidity::NOT_ISOGRAM:
			std::cout << "The word entered was not an issogram. An issogram has no repeating letters.\nPlease try again:\n";
			break;
		case EGuessValidity::NOT_LOWERCASE:
			std::cout << "The word entered has uppercase letters. Please re-enter it with only lowercase\n";
			break;
		default:
			return guess;


		} 
	} while (validity != EGuessValidity::OK);
}

void PrintIntro() { 
	 int32 maxLength = Game.getHiddenWordLength(); 
	std::cout << "Welcome to Bulls and Cows!\nCan you guess the " << maxLength << " letter isogram that I'm thinking of?";
	return;
}
