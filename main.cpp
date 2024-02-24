//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;


#define max_word_length 50
#define max_attempts 7


int letterFill (char, string, string&);

// Illustrates the hangman upon a wrong guess
// Source for the art: https://gist.github.com/chrishorton/8510732aa9a80a03c829b09f12e20d9c
string hangman_art[] = {
    " +---+\n"
    " |   |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    " |   |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|   |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "/    |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "/ \\  |\n"
    "     |\n"
    "=========="
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main ()
{
    // This whole portion sets up the list of random words.
    // There are FIVE total words it can choose from.
    string name;
	char letter;
	int attempts = 0;
	string word;
	string words[] =
	{
		"pizza", "keyboard", "astronomy", "coding", "hangman"
	};


	// Picks one word randomly
	int n = rand()% 5;
	word = words[n];


	// For each letter in the random word, there is an underscore
	string unknown(word.length(),'_');


    // Introduction of the executed program for the user
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\n";
	cout << "\n\nWelcome to the game of Hangman!";
	cout << "\n";
    cout << "\n";
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\n";
	cout << "\n\nTry your best to guess which random word is presented to you!";
	cout << "\n\nYou have " << max_attempts << " tries to try and guess the word.";
    cout << "\n";
    cout << "\n";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\n";


	// Loop until all of the guesses are used up...
	while (attempts < max_attempts)
	{
		cout << hangman_art[attempts] << "\n";
        cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;


		// If a guess is incorrect...
		if (letterFill(letter, word, unknown)==0)
		{
            cout << hangman_art[attempts] << "\n";
			cout << endl << "Oh no! That letter is not in this word!" << endl;
			attempts++;
		}


        // If a guess is correct...
		else
		{
			cout << endl << "You found a letter!" << endl;
		}


		// Tell user how many guesses has left...
		cout << "You have " << max_attempts - attempts;
		cout << " guesses left." << endl;


		// If the word is guessed exactly right...
		if (word == unknown)
		{
            cout << hangman_art[attempts] << "\n";
			cout << word << endl;
			cout << "Congratulations! You got it correct!!!";
			break;
		}
	}

    // If the user expends all attempts and does not get ther answer...
	if (attempts == max_attempts)
	{
        cout << hangman_art[attempts] << "\n";
		cout << "\nSorry, you are all out of attempts..." << endl;
		cout << "The random word was : " << word << endl;
	}

	cin.ignore();
	cin.get();
	return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Fills in the correct guesses (letter) and inserts it into the mystery word
// in the appropriate underscore...
int letterFill (char guess, string secretword, string &guessword)
{
	int i;
	int matches = 0;
	int len = secretword.length();
	for (i = 0; i< len; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;

		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
