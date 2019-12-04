#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
using namespace std;

//Define class atmUser
class atmUser {
private:

	std::string atmUser_Name;
	int atmUser_PIN;
	int atmUser_ID;
	float atmUser_CBalance;
	float atmUser_SBalance;
	int ObjCounter;

public:

	atmUser();
	atmUser(std::string NAME);
	atmUser(std::string NAME, int PIN);
	atmUser(std::string NAME, int PIN, float CBALANCE);
	atmUser(std::string NAME, int PIN, float CBALANCE, float SBALANCE);
	atmUser(std::string NAME, int PIN, float CBALANCE, float SBALANCE, int ID);

	atmUser(const atmUser& obj);

	int getPIN();
	int getID();
	std::string getName();
	float getCheckingBalance();
	float getSavingBalance();

	void setID(int ID);
	void setPIN(int PIN);
	void setName(std::string NAME);
	void setCheckingBalance(float BALANCE);
	void setSavingBalance(float BALANCE);

	int ObjCount();

	~atmUser();
};

atmUser::atmUser() {
	atmUser("No Name", 1234, 0.0, 0.0, 0);
};
atmUser::atmUser(std::string NAME) {
	atmUser(NAME, 1234, 0.0, 0.0, 0);
};
atmUser::atmUser(std::string NAME, int PIN) {
	atmUser(NAME, PIN, 0.0, 0.0, 0);
};
atmUser::atmUser(std::string NAME, int PIN, float CBALANCE) {
	atmUser(NAME, PIN, CBALANCE, 0.0, 0);
};
atmUser::atmUser(std::string NAME, int PIN, float CBALANCE, float SBALANCE) {
	atmUser(NAME, PIN, CBALANCE, SBALANCE, 0);
};
atmUser::atmUser(std::string NAME, int PIN, float CBALANCE, float SBALANCE, int ID) {
	atmUser_Name = NAME;
	atmUser_PIN = PIN;
	atmUser_CBalance = CBALANCE;
	atmUser_SBalance = SBALANCE;
	atmUser_ID = ID;
	ObjCounter++;
};

atmUser::atmUser(const atmUser& obj) {
	atmUser_Name = obj.atmUser_Name;
	atmUser_PIN = obj.atmUser_PIN;
	atmUser_ID = obj.atmUser_ID;
	atmUser_SBalance = obj.atmUser_SBalance;
	atmUser_CBalance = obj.atmUser_CBalance;
};

int atmUser::getID() {
	return atmUser_ID;
};
void atmUser::setID(int ID) {
	atmUser_ID = ID;
};

int atmUser::getPIN() {
	return atmUser_PIN;
};
void atmUser::setPIN(int PIN) {
	atmUser_PIN = PIN;
};

std::string atmUser::getName() {
	return atmUser_Name;
};
void atmUser::setName(std::string NAME) {
	atmUser_Name = NAME;
};

float atmUser::getSavingBalance() {
	return atmUser_SBalance;
};
void atmUser::setSavingBalance(float BALANCE) {
	atmUser_SBalance = BALANCE;
};

float atmUser::getCheckingBalance() {
	return atmUser_CBalance;
};
void atmUser::setCheckingBalance(float BALANCE) {
	atmUser_CBalance = BALANCE;
};

atmUser::~atmUser() {
	ObjCounter--;
};

int atmUser::ObjCount() {
	return ObjCounter;
};


// ---------------------------------------------------------------------------------------------

void displayAccountChoice() { // Display menu that asks for account choice
	cout << "Which account are you using?" << endl;
	cout << "[1] Checkings Account" << endl;
	cout << "[2] Savings Account" << endl;
}

void displayMainmenu() { // Display the main menu after login/creating an account
	cout << "What would you like to do?" << endl;
	cout << "[1] Withdraw" << endl;
	cout << "[2] Deposit" << endl;
	cout << "[3] Check Balance" << endl;
	cout << "[4] Transfer or make payments" << endl;
	cout << "[5] Other Options" << endl;
	cout << "[6] Quit" << endl;
}

void displayWithdrawmenu() { //Display withdraw menu when user chooses [1] Withdraw
	cout << "How much do you want to withdraw?" << endl;
	cout << "[1] $20" << endl;
	cout << "[2] $40" << endl;
	cout << "[3] $60" << endl;
	cout << "[4] $80" << endl;
	cout << "[5] $100" << endl;
	cout << "[6] $200" << endl;
	cout << "[7] $300" << endl;
	cout << "[8] Other Amount" << endl;
}

void displayNearby() { // Displays nearby locations for [5] Other options
	cout << "3300 COLLEGE DR, SAN BRUNO, CA 94066 BUILDING 6, FIRST FLOOR - 0 Miles away" << endl;
	cout << "BANK OF AMERICA ATM 486 Manor Plaza, Pacifica, CA 94044 - 3.1 Miles away" << endl;
	cout << "BANK OF AMERICA ATM 1322 El Camino Real, San Bruno, CA 94066 - 3.3 Miles away" << endl;
	cout << "BANK OF AMERICA ATM 955 El Camino Real South San Francisco, CA 94080 - 3.6 Miles away" << endl;
	cout << "BANK OF AMERICA ATM Daly City, CA - 3.7 Miles " << endl;
	cout << "BANK OF AMERICA ATM 99 Serramonte Center Daly City, CA 94015 - 3.9 Miles away" << endl;
	cout << "ATM (BANK OF AMERICA) 465 San Mateo Ave, San Bruno, CA 94066 - 4.1 Miles away" << endl;
	cout << "BANK OF AMERICA  ATM 1375 Linda Mar Shopping Ctr, Pacifica, CA 94044 - 5 Miles away" << endl;
	cout << "BANK OF AMERICA ATM San Francisco Peninsula, San Francisco, CA 94128 - 7.7 Miles away" << endl;
}

void writeReceipt() { // Asks user if they want a receipt, and prints receipt if they do
	string line, receiptChoice;
	cout << "Would you like a receipt? (Y/N)" << endl;
	cin >> receiptChoice;
	if (receiptChoice == "y" || receiptChoice == "Y" ) {
		cout << "Please select an option." << endl;
		cout << "[1] Print Receipt" << endl;
		cout << "[2] Email Receipt only" << endl;
		cout << "[3] Print and Email Receipt" << endl;
		cin >> receiptChoice;
		if (receiptChoice == "1") {
			ifstream writeReceipt("atmReceipt.txt");
			if (writeReceipt.is_open()) {
				cout << "-----------------------------------------" << endl;
				while (getline(writeReceipt, line)) {
					cout << line << endl;
				}
				cout << "-----------------------------------------" << endl;
			}
		}
		if (receiptChoice == "2") {
			cout << "Please enter your email address: ";
				cin >> receiptChoice;
				cout << "An email of your receipt has been sent." << endl;
		}
		if (receiptChoice == "3") {
			ifstream writeReceipt("atmReceipt.txt");
			if (writeReceipt.is_open()) {
				cout << "-----------------------------------------" << endl;
				while (getline(writeReceipt, line)) {
					cout << line << endl;
				}
				cout << "-----------------------------------------" << endl;
			}
			cout << "Please enter your email address: ";
			cin >> receiptChoice;

			cout << "An email of your receipt has been sent." << endl;
		}
	}
	else if ((receiptChoice == "N" || receiptChoice == "n")) {
		cout << "Thank you, have a good day." << endl;
	}
	if (receiptChoice == "Y" || receiptChoice == "y") {
		ifstream writeReceipt("atmReceipt.txt");
		if (writeReceipt.is_open()) {
			cout << "-----------------------------------------" << endl;
			while (getline(writeReceipt, line)) {
				cout << line << endl;
			}
			cout << "-----------------------------------------" << endl;
		}
	}
	else {
		cout << "Thank you, have a good day." << endl;
	}
}
void saveData(atmUser currentUser) { // Updates stored data
	ifstream readData("atmData.txt");
	ofstream saveData("temp.txt");
	if (readData.is_open())
	{
		int counter = 1;
		string line;
		while (getline(readData, line)) {
			if (counter == currentUser.getID()) {
				saveData << currentUser.getName() << "|" << currentUser.getPIN() << " " << currentUser.getCheckingBalance() << " " << currentUser.getSavingBalance() << " " << currentUser.getID() << endl;
				counter++;
			}
			else {
				saveData << line << endl;
				counter++;
			}
		}
		readData.close();
	}
	remove("atmData.txt");
	rename("temp.txt", "atmData.txt");
}

atmUser getUser(string userName, int userID) { // returns an atmUser object with user data if it is found, if no matching user data found then returns empty atmUser object
	string storedName, line;
	int storedPIN, storedID;
	float storedSaving, storedChecking;
	atmUser targetUser;
	ifstream atmData("atmData.txt");
	if (atmData.is_open())
	{
		while (getline(atmData, line))
		{
			stringstream currentline(line);
			getline(currentline, storedName, '|');
			currentline >> storedPIN >> storedChecking >> storedSaving >> storedID;
			if (userName == storedName)
			{
				if (userID == storedID) {
					targetUser.setID(storedID);
					targetUser.setName(storedName);
					targetUser.setPIN(storedPIN);
					targetUser.setCheckingBalance(storedChecking);
					targetUser.setSavingBalance(storedSaving);
					break;
				}
				else if (atmData.peek() == EOF) {
					cout << "Error grabbing user data." << endl;
					break;
				}
			}
			else if (atmData.peek() == EOF) {
				cout << "Error grabbing user data." << endl;
				break;
			}
		}
		atmData.close();
	}
	return targetUser;
}

bool userExist(string userName, int userID) { // Checks if user exists in saved data
	bool userStatus = false;
	string storedName, line;
	int storedPIN, storedID;
	float storedDebit, storedCredit;
	ifstream atmData("atmData.txt");
	if (atmData.is_open())
	{
		while (getline(atmData, line))
		{
			stringstream currentline(line);
			getline(currentline, storedName, '|');
			currentline >> storedPIN >> storedDebit >> storedCredit >> storedID;
			if (userName == storedName)
			{
				if (userID == storedID) {
					userStatus = true;
					break;
				}
				else if (atmData.peek() == EOF) {
					cout << "Sorry, we couldn't find that user." << endl;
					break;
				}
			}
			else if (atmData.peek() == EOF) {
				cout << "Sorry, we couldn't find that user." << endl;
				break;
			}
		}
		atmData.close();
	}
	return userStatus;
}

void transferMoney(atmUser& currentUser, atmUser& transferUser, float transferAmount, char account) { // Transfer money between two atmUser objects
	if (account == '1') { // If account = 1, this means transfer will come from checkings balance
		currentUser.setCheckingBalance(currentUser.getCheckingBalance() - transferAmount);
		transferUser.setCheckingBalance(transferUser.getCheckingBalance() + transferAmount);
		cout << "You successfully transferred $" << transferAmount << " to " << transferUser.getName() << " from checkings." << endl;
	}
	else if (account == '2') { // If account = 2, this means transfer will come from savings balance
		currentUser.setSavingBalance(currentUser.getSavingBalance() - transferAmount);
		transferUser.setCheckingBalance(transferUser.getCheckingBalance() + transferAmount);
		cout << "You successfully transferred $" << transferAmount << " to " << transferUser.getName() << " from savings." << endl;
	}
	saveData(currentUser);
	saveData(transferUser);
}

char checkWithdrawChoice(char withdrawChoice) { // Checks that withdraw menu choice is valid
	while (!(withdrawChoice == '1' || withdrawChoice == '2' || withdrawChoice == '3' || withdrawChoice == '4' || withdrawChoice == '5' || withdrawChoice == '6' || withdrawChoice == '7' || withdrawChoice == '8')) {
		cout << "Please choose an option" << endl;
		cin >> withdrawChoice;
	}
	return withdrawChoice;
}

char checkAdditionalTrans(char response) { // Checks response to "Would you like another transaction? is valid"
	while (!(response == 'Y' || response == 'y' || response == 'N' || response == 'n')) {
		cout << "Please choose an option." << endl;
		cin >> response;
	}
	return response;
}

char checkMainChoice(char mainChoice) { // Checks that main menu choice is valid
	while (!(mainChoice == '1' || mainChoice == '2' || mainChoice == '3' || mainChoice == '4' || mainChoice == '5' || mainChoice == '6')) {
		cout << "Please choose an option" << endl;
		cin >> mainChoice;
	}
	return mainChoice;
}

char checkAccountChoice(char accountChoice) { // Checks response to checkings or savings menu
	while (!(accountChoice == '1' || accountChoice == '2')) {
		cout << "Please choose an option." << endl;
		cin >> accountChoice;
	}
	return accountChoice;
}

char checkTransferChoice(char transferChoice) { // Checks response to transfer menu
	while (!(transferChoice == '1' || transferChoice == '2')) {
		cout << "Please choose an option." << endl;
		cin >> transferChoice;
	}
	return transferChoice;
}

void mainMenu(atmUser currentUser) {
	char anotherTransaction = 'Y';
	char mainChoice = '0';
	char withdrawChoice = '0';
	char accountChoice = '0';
	float transactionAmount = 0;
	char transferChoice = '0';
	string transferRecipient = "";
	int transferRecipientID = 0;
	string addChoice = "0";

	displayMainmenu();
	cin >> mainChoice;
	mainChoice = checkMainChoice(mainChoice);
	ifstream atmReceipt("atmReceipt.txt", ios::trunc); // Opens receipt file in trunc mode, clearing old data
	atmReceipt.close();
	ofstream storeReceipt("atmReceipt.txt"); // Opens stream to write to clean receipt file
	if (storeReceipt.is_open()) {
		storeReceipt << "Name: " << currentUser.getName() << endl; // Writes down users name at the top of  receipt
		do {
			switch (mainChoice) {
			case '1': // -------------------------------------------------- [1] Withdraw option -------------------------------------------------- //
				displayAccountChoice();
				cin >> accountChoice;
				accountChoice = checkAccountChoice(accountChoice);
				if (accountChoice == '1') {
					displayWithdrawmenu();
					cin >> withdrawChoice;
					switch (withdrawChoice) {
					case '1':
						if (20 > currentUser.getCheckingBalance()) {
							cout << "Not enough money to withdraw." << endl;
						}
						else {
							currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 20);
							cout << "You successfully withdrew $20.00" << endl;
							storeReceipt << "Withdraw: $20" << endl;
						}
						break;
					case '2':
						if (20 > currentUser.getCheckingBalance()) {
							cout << "Not enough money to withdraw." << endl;
						}
						else {
							currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 40);
							cout << "You successfully withdrew $40.00" << endl;
							storeReceipt << "Withdraw: $40" << endl;
						}
						break;
					case '3':
						if (20 > currentUser.getCheckingBalance()) {
							cout << "Not enough money to withdraw." << endl;
						}
						else {
							currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 60);
							cout << "You successfully withdrew $60.00" << endl;
							storeReceipt << "Withdraw: $60" << endl;
						}
						break;
					case '4':
						if (20 > currentUser.getCheckingBalance()) {
							cout << "Not enough money to withdraw." << endl;
						}
						else {
							currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 80);
							cout << "You successfully withdrew $80.00" << endl;
							storeReceipt << "Withdraw: $80" << endl;
						}
						break;
					case '5':
						if (20 > currentUser.getCheckingBalance()) {
							cout << "Not enough money to withdraw." << endl;
						}
						else {
							currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 100);
							cout << "You successfully withdrew $100.00" << endl;
							storeReceipt << "Withdraw: $100" << endl;
						}
						break;
					case '6':
						if (20 > currentUser.getCheckingBalance()) {
							cout << "Not enough money to withdraw." << endl;
						}
						else {
							currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 200);
							cout << "You successfully withdrew $200.00" << endl;
							storeReceipt << "Withdraw: $200" << endl;
						}
						break;
					case '7':
						if (20 > currentUser.getCheckingBalance()) {
							cout << "Not enough money to withdraw." << endl;
						}
						else {
							currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 300);
							cout << "You successfully withdrew $300.00" << endl;
							storeReceipt << "Withdraw: $300" << endl;
						}
						break;
					case '8':
						cout << "Enter an amount to withdraw." << endl;
						cin >> transactionAmount;
						if (transactionAmount > currentUser.getCheckingBalance()) {
							cout << "Not enough money to withdraw." << endl;
						}
						else if (transactionAmount > 1000) {
							cout << "Sorry, you cannot withdraw more than $1,000." << endl;
						}
						else {
							currentUser.setCheckingBalance(currentUser.getCheckingBalance() - transactionAmount);
							cout << "You successfully withdrew $" << transactionAmount << endl;
							storeReceipt << "Withdraw: $" << transactionAmount << endl;
						}
						break;
					default:
						withdrawChoice = checkWithdrawChoice(withdrawChoice);
					}
				}
				else if (accountChoice == '2') { // If user chooses to withdraw from savings account
					displayWithdrawmenu();
					cin >> withdrawChoice;
					switch (withdrawChoice) {
					case '1':
						if (20 > currentUser.getSavingBalance()) {
							cout << "Not enough money to withdraw." << endl;
						}
						else {
							currentUser.setSavingBalance(currentUser.getSavingBalance() - 20);
							cout << "You successfully withdrew $20.00" << endl;
							storeReceipt << "Withdraw: $20" << endl;
						}
						break;
					case '2':
						if (20 > currentUser.getSavingBalance()) {
							cout << "Not enough money to withdraw." << endl;
						}
						else {
							currentUser.setSavingBalance(currentUser.getSavingBalance() - 40);
							cout << "You successfully withdrew $40.00" << endl;
							storeReceipt << "Withdraw: $40" << endl;
						}
						break;
					case '3':
						if (20 > currentUser.getSavingBalance()) {
							cout << "Not enough money to withdraw." << endl;
						}
						else {
							currentUser.setSavingBalance(currentUser.getSavingBalance() - 60);
							cout << "You successfully withdrew $60.00" << endl;
							storeReceipt << "Withdraw: $60" << endl;
						}
						break;
					case '4':
						if (20 > currentUser.getSavingBalance()) {
							cout << "Not enough money to withdraw." << endl;
						}
						else {
							currentUser.setSavingBalance(currentUser.getSavingBalance() - 80);
							cout << "You successfully withdrew $80.00" << endl;
							storeReceipt << "Withdraw: $80" << endl;
						}
						break;
					case '5':
						if (20 > currentUser.getSavingBalance()) {
							cout << "Not enough money to withdraw." << endl;
						}
						else {
							currentUser.setSavingBalance(currentUser.getSavingBalance() - 100);
							cout << "You successfully withdrew $100.00" << endl;
							storeReceipt << "Withdraw: $100" << endl;
						}
						break;
					case '6':
						if (20 > currentUser.getSavingBalance()) {
							cout << "Not enough money to withdraw." << endl;
						}
						else {
							currentUser.setSavingBalance(currentUser.getSavingBalance() - 200);
							cout << "You successfully withdrew $200.00" << endl;
							storeReceipt << "Withdraw: $200" << endl;
						}
						break;
					case '7':
						if (20 > currentUser.getSavingBalance()) {
							cout << "Not enough money to withdraw." << endl;
						}
						else {
							currentUser.setSavingBalance(currentUser.getSavingBalance() - 300);
							cout << "You successfully withdrew $300.00" << endl;
							storeReceipt << "Withdraw: $300" << endl;
						}
						break;
					case '8':
						cout << "Enter an amount to withdraw." << endl;
						cin >> transactionAmount;
						if (transactionAmount > currentUser.getSavingBalance()) {
							cout << "Not enough money to withdraw." << endl;
						}
						else {
							currentUser.setSavingBalance(currentUser.getSavingBalance() - transactionAmount);
							cout << "You successfully withdrew $" << transactionAmount << endl;
							storeReceipt << "Withdraw: $" << transactionAmount << endl;
						}
						break;
					default:
						withdrawChoice = checkWithdrawChoice(withdrawChoice);
					}
				}
				cout << "Would you like another transaction? (Y/N)" << endl;
				cin >> anotherTransaction;
				anotherTransaction = checkAdditionalTrans(anotherTransaction);
				if (anotherTransaction == 'Y' || anotherTransaction == 'y') {
					displayMainmenu();
					cin >> mainChoice;
					mainChoice = checkMainChoice(mainChoice);
				}
				break;
			case '2': // -------------------------------------------------- [2] Deposit option -------------------------------------------------- //
				displayAccountChoice();
				cin >> accountChoice;
				accountChoice = checkAccountChoice(accountChoice);
				if (accountChoice == '1') {
					cout << "Enter an amount to deposit: ";
					cin >> transactionAmount;
					while (transactionAmount < 0) {
						cout << "Please deposit a valid amount." << endl;
						cin >> transactionAmount;
					}
					currentUser.setCheckingBalance(currentUser.getCheckingBalance() + transactionAmount);
					storeReceipt << "Deposit to checking: $" << transactionAmount << endl;
					cout << "You successfully deposited $" << transactionAmount << " to checkings." << endl;
				}
				else if (accountChoice == '2') {
					cout << "Enter an amount to deposit: ";
					cin >> transactionAmount;
					while (transactionAmount < 0) {
						cout << "Please deposit a valid amount." << endl;
						cin >> transactionAmount;
					}
					currentUser.setSavingBalance(currentUser.getSavingBalance() + transactionAmount);
					storeReceipt << "Deposit to saving: $" << transactionAmount << endl;
					cout << "You successfully deposited $" << transactionAmount << " to savings." << endl;
				}
				cout << "Would you like another transaction? (Y/N)" << endl;
				cin >> anotherTransaction;
				anotherTransaction = checkAdditionalTrans(anotherTransaction);
				if (anotherTransaction == 'Y' || anotherTransaction == 'y') {
					displayMainmenu();
					cin >> mainChoice;
					mainChoice = checkMainChoice(mainChoice);
				}
				break;
			case '3': // -------------------------------------------------- [3] Check Balance -------------------------------------------------- //
				displayAccountChoice();
				cin >> accountChoice;
				accountChoice = checkAccountChoice(accountChoice);
				if (accountChoice == '1') {
					cout << "Your current checking balance is: " << "$" << currentUser.getCheckingBalance() << endl;
				}
				else if (accountChoice == '2') {
					cout << "Your current saving balance is: " << "$" << currentUser.getSavingBalance() << endl;
				}
				cout << "Would you like another transaction? (Y/N)" << endl;
				cin >> anotherTransaction;
				anotherTransaction = checkAdditionalTrans(anotherTransaction);
				if (anotherTransaction == 'Y' || anotherTransaction == 'y') {
					displayMainmenu();
					cin >> mainChoice;
					mainChoice = checkMainChoice(mainChoice);
				}
				break;
			case '4': // -------------------------------------------------- [4] Transfer or make payments -------------------------------------------------- //
				displayAccountChoice();
				cin >> accountChoice;
				accountChoice = checkAccountChoice(accountChoice);
				if (accountChoice == '1') {
					cout << "[1] Transfer money to savings" << endl;
					cout << "[2] Make Payments" << endl;
					cin >> transferChoice;
					transferChoice = checkTransferChoice(transferChoice);
					if (transferChoice == '1') {
						cout << "Enter transfer amount: ";
						cin >> transactionAmount;
						if (transactionAmount <= currentUser.getCheckingBalance() && transactionAmount > 0) {
							currentUser.setCheckingBalance(currentUser.getCheckingBalance() - transactionAmount);
							currentUser.setSavingBalance(currentUser.getSavingBalance() + transactionAmount);
							cout << "You successfully transferred $" << transactionAmount << " from checking to savings." << endl;
							storeReceipt << "Transfer from checkings to savings: $" << transactionAmount << endl;
						}
						else {
							cout << "Invalid transfer amount." << endl;
						}
					}
					else if (transferChoice == '2') {
						cout << "Enter name of transfer recipient: ";
						cin.ignore();
						getline(cin, transferRecipient);
						cout << "Enter recipient ID: ";
						cin >> transferRecipientID;
						if (userExist(transferRecipient, transferRecipientID)) {
							cout << "Enter transfer amount: ";
							cin >> transactionAmount;
							if (transactionAmount <= currentUser.getCheckingBalance() && transactionAmount > 0) {
								atmUser transferUser(getUser(transferRecipient, transferRecipientID)); // GetUser grabs transfer recipient data, and then we create a new atmUser object that is a clone of what GetUser grabs
								transferMoney(currentUser, transferUser, transactionAmount, accountChoice);
								storeReceipt << "Transfer to " << transferUser.getName() << " from checking: $" << transactionAmount << endl;
							}
							else {
								cout << "Invalid transfer amount." << endl;
							}
						}
					}
				}
				else if (accountChoice == '2') {
					cout << "[1] Transfer money to checkings" << endl;
					cout << "[2] Make Payments" << endl;
					cin >> transferChoice;
					transferChoice = checkTransferChoice(transferChoice);
					if (transferChoice == '1') {
						cout << "Enter transfer amount: ";
						cin >> transactionAmount;
						if (transactionAmount <= currentUser.getSavingBalance() && transactionAmount > 0) {
							currentUser.setSavingBalance(currentUser.getSavingBalance() - transactionAmount);
							currentUser.setCheckingBalance(currentUser.getCheckingBalance() + transactionAmount);
							cout << "You successfully transferred $" << transactionAmount << " from savings to checking." << endl;
							storeReceipt << "Transfer from savings to checkings: $" << transactionAmount << endl;
						}
						else {
							cout << "Invalid transfer amount." << endl;
						}
					}
					else if (transferChoice == '2') {
						cout << "Enter name of transfer recipient: ";
						cin.ignore();
						getline(cin, transferRecipient);
						cout << "Enter recipient ID: ";
						cin >> transferRecipientID;
						if (userExist(transferRecipient, transferRecipientID)) {
							cout << "Enter transfer amount: ";
							cin >> transactionAmount;
							if (transactionAmount <= currentUser.getSavingBalance() && transactionAmount > 0) {
								atmUser transferUser(getUser(transferRecipient, transferRecipientID)); // GetUser grabs transfer recipient data, and then we create a new atmUser object that is a clone of what GetUser grabs
								transferMoney(currentUser, transferUser, transactionAmount, accountChoice);
								storeReceipt << "Transfer to " << transferUser.getName() << " from saving: $" << transactionAmount << endl;
							}
							else {
								cout << "Invalid transfer amount." << endl;
							}
						}
					}
				}
				cout << "Would you like another transaction? (Y/N)" << endl;
				cin >> anotherTransaction;
				anotherTransaction = checkAdditionalTrans(anotherTransaction);
				if (anotherTransaction == 'Y' || anotherTransaction == 'y') {
					displayMainmenu();
					cin >> mainChoice;
					mainChoice = checkMainChoice(mainChoice);
				}
				break;
			case '5': // -------------------------------------------------- [5] Other Options -------------------------------------------------- //
				cout << "[1] Change PIN" << endl;
				cout << "[2] Nearby ATM Locations" << endl;
				getline(cin, addChoice);
				while (!(addChoice == "1" || addChoice == "2")) {
					cout << "Please enter a valid option: ";
					cin >> addChoice;
				}
				if (addChoice == "1") {
					int newPIN;
					cout << "Choose a new PIN:";
					cin >> newPIN;
					while (newPIN > 9999 || newPIN <= 999) {
						cout << "Invalid pin." << endl;
						cout << "Create your pin: ";
						cin >> newPIN;
					}
					currentUser.setPIN(newPIN);
					cout << "Your new PIN: " << currentUser.getPIN() << endl;
				}
				else if (addChoice == "2") {
					displayNearby();
				}
				cout << "Would you like another transaction? (Y/N)" << endl;
				cin >> anotherTransaction;
				anotherTransaction = checkAdditionalTrans(anotherTransaction);
				if (anotherTransaction == 'Y' || anotherTransaction == 'y') {
					displayMainmenu();
					cin >> mainChoice;
					mainChoice = checkMainChoice(mainChoice);
				}
				break;
			case '6': // Quit option
				cout << "Thank you, have a good day." << endl;
				anotherTransaction = '0';
				break;
			}
		} while (anotherTransaction == 'Y' || anotherTransaction == 'y');

		storeReceipt << "Current Checking balance: $" << currentUser.getCheckingBalance() << endl;
		storeReceipt << "Current Saving balance: $" << currentUser.getSavingBalance() << endl;
		storeReceipt.close();

		if (anotherTransaction != '0') {
			writeReceipt();
		}
		saveData(currentUser);
	}
}

void registerUser() { //Creating a new user account
	string newUser_Name;
	int newUser_PIN;
	int userCount = 1;
	cout << "Enter your full name: ";
	getline(cin, newUser_Name);
	cout << "Create your pin: ";
	cin >> newUser_PIN;
	while (newUser_PIN > 9999 || newUser_PIN <= 999) {
		cout << "Invalid pin." << endl;
		cout << "Create your pin: ";
		cin >> newUser_PIN;
	}
	ifstream atmData("atmData.txt");
	if (atmData.is_open())
	{
		string line;
		while (getline(atmData, line)) {
			userCount++;
		}
		atmData.close();
	}
	atmUser newUser(newUser_Name, newUser_PIN, 0.0, 0.0, userCount);
	cout << "Your ID is: " << userCount << endl;
	cout << "Remember it as you will need it to login." << endl;
	ofstream storeData("atmData.txt", ios::app);
	if (storeData.is_open()) {
		storeData << newUser.getName() << "|" << newUser.getPIN() << " " << newUser.getCheckingBalance() << " " << newUser.getSavingBalance() << " " << newUser.getID() << endl;
		storeData.close();
	}
}

void login() { // Login function
	string userName, storedName, line;
	int userPIN, storedPIN, userID, storedID;
	float storedChecking, storedSaving;
	cout << "Enter your full name: ";
	getline(cin, userName);
	cout << "Enter PIN: ";
	cin >> userPIN;
	cout << "Enter ID: ";
	cin >> userID;
	ifstream atmData("atmData.txt");
	if (atmData.is_open())
	{
		while (getline(atmData, line))
		{
			stringstream currentline(line);
			getline(currentline, storedName, '|');
			currentline >> storedPIN >> storedChecking >> storedSaving >> storedID;
			if (userName == storedName && userPIN == storedPIN)
			{
				if (userID == storedID) {
					cout << "Login successful." << endl;
					atmUser currentUser(storedName, storedPIN, storedChecking, storedSaving, storedID);
					mainMenu(currentUser);
					break;
				}
				else if (atmData.peek() == EOF) {
					cout << "Wrong username or password!" << endl;
					break;
				}
			}
			else if (atmData.peek() == EOF) {
				cout << "Wrong username or password!" << endl;
				break;
			}
		}
		atmData.close();
	}
}

void startMenu() { // Start menu, calls login or register function depending on user choice
	string startChoice = "0";
	cout << "What do you want to do?" << endl;
	cout << "[1] Login" << endl;
	cout << "[2] Register" << endl;
	cout << "[3] Quit" << endl;
	getline(cin, startChoice);
	while (startChoice > "3" || startChoice < "1") {
		cout << "Please choose a valid choice." << endl;
		getline(cin, startChoice);
	}
	if (startChoice == "1") {
		login();
	}
	if (startChoice == "2") {
		registerUser();
		cin.ignore();
		startMenu();
	}
	if (startChoice == "3") {
		cout << "Thank you, have a good day." << endl;
	}
}

int main() {
	startMenu();
	return 0;
}