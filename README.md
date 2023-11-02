# BlackJack_Game_Development_Project

Pseudocode

Input: 1 (New Hand), 2 (Hit Me), 3 (Stand), 4 (Hint), 5 (Exit)
Output: Your Choice?, Dealer Value, Player Value, whether the player win or not, etc

1. declare int getRandomNumber(int n) {
return rand() % n;
}
2. declare void printHand(int value, int suit, const char* person) {

const string SUITS[] = { "Diamonds", "Hearts", "Clubs", "Spades" }; cout << person << “picked: ”;
if (value == 1)
cout << “Ace";

else
cout << value;

cout << " of " << SUITS[suit] << endl; }

3. declare void printTotal(int dealerTotal, int playerTotal) { cout << “^^^^^^.....” << endl;
cout << "Dealer value: " << dealerTotal << endl;
cout << "Player value: " << playerTotal << endl;

cout << “^^^^^^.....” << endl;

}
4. declare void printHint(ifstream& fin, int playerTotal) { string line;

cout<<setw(8)<<left<<"Player"<<"2345... A”<<endl; int i = 0;

while loop
(getline(fin, line)) {
if (i == 0)
cout << setw(8) << "5-7: "; else
cout << setw(7) << i + 7 << " “;

for loop

(char x : line)

cout << setw(3) << x;

i++;

cout << endl;
} //end while loop

cout << “^^^^^^.....” << endl; cout << "suggestion: “;
if (playerTotal < 13)
cout << "[Hit]";

else
cout << “[Stand]";

cout << “^^^^^^.....” << endl; } 

5. int main() {
6. const char* DEALER = “Dealer";
const char* PLAYER = “You";
7. int playerValue, playerTotal, playerSuit; int dealerValue, dealerTotal, dealerSuit; int choice;
bool isGamePlaying = false;
8. ifstream fin; fin.open("blackJack-play-suggestion.txt"); 9. srand(time(NULL));
10. while loop
(1) {
cout << "*****" << endl;
cout << "1) New Hand" << endl;
cout << "2) Hit Me" << endl;
cout << "3) Stand" << endl;
cout << "4) Hint" << endl;
cout << "5) Exit" << endl;
cout << "*****" << endl;
cout << "Your Choice? > ";
cin >> choice;

11. switch (choice) { case 1:

if (isGamePlaying) { //error

cout << "current game is not finished yet." << endl; break;
}
isGamePlaying = true;

dealerTotal = dealerValue = getRandomNumber(NUMOFCARDS) + 1; dealerSuit = getRandomNumber(NUMOFSUITS);
playerTotal = playerValue = getRandomNumber(NUMOFCARDS) + 1; playerSuit = getRandomNumber(NUMOFSUITS); printHand(dealerValue, dealerSuit, DEALER);

printHand(playerValue, playerSuit, PLAYER); printTotal(dealerTotal, playerTotal);
break;
12. case 2:

if (!isGamePlaying) {
cout << "Start a new game first." << endl;
break;
}
playerValue = getRandomNumber(NUMOFCARDS) + 1; playerSuit = getRandomNumber(NUMOFSUITS); printHand(playerValue, playerSuit, PLAYER); playerTotal += playerValue;
printTotal(dealerTotal, playerTotal);
if (playerTotal == 21) {
cout << "Blackjack! You win!" << endl; //user win case

isGamePlaying = false; }

if (playerTotal > 21) {
cout << "You bust! House wins" << endl; //dealer win case
isGamePlaying = false;
}
break;
13. case 3:
if (!isGamePlaying) {
cout << "start a new game first." << endl;
break;
}
while loop
(dealerTotal < 17) {
dealerValue = getRandomNumber(NUMOFCARDS) + 1;
dealerSuit = getRandomNumber(NUMOFSUITS);
printHand(dealerValue, dealerSuit, DEALER);
dealerTotal += dealerValue;
printTotal(dealerTotal, playerTotal);
}
if (dealerTotal == 21) {
cout << "Blackjack! You lose! House wins!" << endl; //when dealer=user, dealer win case }
if (dealerTotal > 21) {
cout << "House busts! You win!" << endl; // 21 > dealer, user win case
}
else if (dealerTotal < playerTotal) {

cout << "You win!" << endl; //user > dealer, user win case

}
else if (dealerTotal == playerTotal) {
cout << "Push!" << endl; //dealer = user, continue case }
else
cout << "House wins!" << endl; // house win case isGamePlaying = false;
break;
14.case 4:
printHint(fin, playerTotal);
break;
15. case 5:
exit(0);
16. default:
cout << "Invalid choice." << endl; //error

} }

17. fin.close(); return 0;

}

