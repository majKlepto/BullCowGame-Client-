#include <iostream>
#include <string>
#include "FBullCowGame.h"



void PrintIntro();
std::string getGuess();

void PlayGame();
bool AskToReplay();

int main(){
	
	
	do {
		std::cout << "test";
		PrintIntro();
		PlayGame();
	} while (AskToReplay());
	
	return 0; 
}

void PlayGame()
{
	FBullCowGame Game;
	constexpr  int MAX_GUESSES = 5;

	for (int i = 0; i < MAX_GUESSES; i++) {

		std::string guess = getGuess();
		std::cout << "Your guess was " << guess << std::endl;  

	}
}

bool AskToReplay()
{
	std::cout << "Would you like to play again?" << std::endl << "Y = yes, N = no" << std::endl;
	std::string choice = " ";
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


std::string getGuess()
{
	std::cout <<std::endl << "Enter your guess" << std::endl;
	std::string guess = "";
	getline(std::cin, guess);
	return guess;
}
void PrintIntro() {
	constexpr int MAX_LENGTH = 5; 
	std::cout << "Welcome to Bulls and Cows!\nCan you guess the " << MAX_LENGTH << " letter isogram that I'm thinking of?";
	return;
}
