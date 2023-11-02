#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>

#define NUMOFCARDS 10
#define NUMOFSUITS 4

using namespace std;

int getRandomNumber(int n) {
    return rand() % n;
}

void printHand(int value, int suit, const char* person) {
    const string SUITS[] = { "Diamonds", "Hearts", "Clubs", "Spades" };
    cout << person << " picked the ";
    if (value == 1) cout << "Ace";
    else cout << value;
    cout << " of " << SUITS[suit] << endl;
}

void printTotal(int dealerTotal, int playerTotal) {
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "Dealer value: " << dealerTotal << endl;
    cout << "Player Value: " << playerTotal << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}

void printHint(ifstream& fin, int playerTotal) {
    string line;
    cout << setw(8) << left << "Player " << "2 3 4 5 6 7 8 9 10 A" << endl;
    int i = 0;
    while (getline(fin, line)) {
        if (i == 0) cout << setw(8) << "5-7: ";
        else cout << setw(7) << i + 7 << " ";

        for (char x : line) cout << setw(3) << x;
        i++;
        cout << endl;
    }

    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "Suggestion: ";
    if (playerTotal < 13) cout << "[Hit]";
    else cout << "[Stand]";
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}
int main() {
    const char* DEALER = "Dealer";
    const char* PLAYER = "You";

    int playerValue, playerTotal, playerSuit;
    int dealerValue, dealerTotal, dealerSuit;
    int choice;
    bool isGamePlaying = false;

    ifstream fin;
    fin.open("blackJack-play-suggestion.txt");

    srand(time(NULL));
    while (1) {
        cout << "*****" << endl;
        cout << "1) New Hand" << endl;
        cout << "2) Hit Me" << endl;
        cout << "3) Stand" << endl;
        cout << "4) Hint" << endl;
        cout << "5) Exit" << endl;
        cout << "*****" << endl;
        cout << "Your Choice? > ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (isGamePlaying) {
                cout << "Current game is not finished yet." << endl;
                break;
            }
            isGamePlaying = true;
            dealerTotal = dealerValue = getRandomNumber(NUMOFCARDS) + 1;
            dealerSuit = getRandomNumber(NUMOFSUITS);
            playerTotal = playerValue = getRandomNumber(NUMOFCARDS) + 1;
            playerSuit = getRandomNumber(NUMOFSUITS);
            printHand(dealerValue, dealerSuit, DEALER);
            printHand(playerValue, playerSuit, PLAYER);
            printTotal(dealerTotal, playerTotal);
            break;
        case 2:
            if (!isGamePlaying) {
                cout << "Start a new game first." << endl;
                break;
            }
            playerValue = getRandomNumber(NUMOFCARDS) + 1;
            playerSuit = getRandomNumber(NUMOFSUITS);
            printHand(playerValue, playerSuit, PLAYER);
            playerTotal += playerValue;
            printTotal(dealerTotal, playerTotal);
            if (playerTotal == 21) {
                cout << "Blackjack! You win!" << endl;
                isGamePlaying = false;
            }
            if (playerTotal > 21) {
                cout << "You bust! House wins" << endl;
                isGamePlaying = false;
            }
            break;
        case 3:
            if (!isGamePlaying) {
                cout << "Start a new game first." << endl;
                break;
            }
            while (dealerTotal < 17) {
                dealerValue = getRandomNumber(NUMOFCARDS) + 1;
                dealerSuit = getRandomNumber(NUMOFSUITS);
                printHand(dealerValue, dealerSuit, DEALER);
                dealerTotal += dealerValue;
                printTotal(dealerTotal, playerTotal);
            }
            if (dealerTotal == 21) {
                cout << "Blackjack! You lose! House wins!" << endl;
            }
            if (dealerTotal > 21) {
                cout << "House busts! You win!" << endl;
            }
            else if (dealerTotal < playerTotal) {
                cout << "You win!" << endl;
            }
            else if (dealerTotal == playerTotal) {
                cout << "Push!" << endl;
            }
            else cout << "House wins!" << endl;
            isGamePlaying = false;
            break;
        case 4:
            printHint(fin, playerTotal);
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice." << endl;
        }
    }
    fin.close();
    return 0;
}