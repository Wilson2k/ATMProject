//
//  main.cpp
//  ATMProject
//
//  Created by Wilson Chen on 11/3/19.
//  Copyright © 2019 Wilson Chen. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include "atmUser.hpp"
using namespace std;

void displayAccountChoice() { // Display menu that asks for account choice
    cout << " _________________________________" << endl;
    cout << "|                                 |" << endl;
    cout << "| Which account are you using?    |" << endl;
    cout << "| [1] Checkings Account           |" << endl;
    cout << "| [2] Savings Account             |" << endl;
    cout << "|_________________________________|" << endl;
}

void displayCardMenu(){ // Display menu that ask for card type
    cout << " _____________________________________" << endl;
    cout << "|                                     |" << endl;
    cout << "| Credit Card Withdraw Fees           |" << endl;
    cout << "| Under $200: 5%                      |" << endl;
    cout << "| $200 to $500: 10%                   |" << endl;
    cout << "| $500 or more: 15%                   |" << endl;
    cout << "|_____________________________________|" << endl;
    cout << "|                                     |" << endl;
    cout << "| What kind of card are you using?    |" << endl;
    cout << "| [1] Debit Card                      |" << endl;
    cout << "| [2] Credit Card                     |" << endl;
    cout << "|_____________________________________|" << endl;
}

void displayMainmenu() { // Display the main menu after login/creating an account
    cout << " _________________________________" << endl;
    cout << "|                                 |" << endl;
    cout << "| What would you like to do?      |" << endl;
    cout << "| [1] Withdraw                    |" << endl;
    cout << "| [2] Deposit                     |" << endl;
    cout << "| [3] Check Balance               |" << endl;
    cout << "| [4] Transfer or make payments   |" << endl;
    cout << "| [5] Other Options               |" << endl;
    cout << "| [6] Quit                        |" << endl;
    cout << "|_________________________________|" << endl;
}

void displayWithdrawmenu() { //Display withdraw menu when user chooses [1] Withdraw
    cout << " ___________________________________" << endl;
    cout << "|                                   |" << endl;
    cout << "| How much do you want to withdraw? |" << endl;
    cout << "| [1] $20                           |" << endl;
    cout << "| [2] $40                           |" << endl;
    cout << "| [3] $60                           |" << endl;
    cout << "| [4] $80                           |" << endl;
    cout << "| [5] $100                          |" << endl;
    cout << "| [6] $200                          |" << endl;
    cout << "| [7] $300                          |" << endl;
    cout << "| [8] Other Amount                  |" << endl;
    cout << "|___________________________________|" << endl;
}

void displayNearby() { // Displays nearby locations for [5] Other options
    cout << " ________________________________________________________________________________________" << endl;
    cout << "|                                                                                        |" << endl;
    cout << "| 3300 COLLEGE DR, SAN BRUNO, CA 94066 BUILDING 6, FIRST FLOOR - 0 Miles away            |" << endl;
    cout << "| BANK OF AMERICA ATM 486 Manor Plaza, Pacifica, CA 94044 - 3.1 Miles away               |" << endl;
    cout << "| BANK OF AMERICA ATM 1322 El Camino Real, San Bruno, CA 94066 - 3.3 Miles away          |" << endl;
    cout << "| BANK OF AMERICA ATM 955 El Camino Real South San Francisco, CA 94080 - 3.6 Miles away  |" << endl;
    cout << "| BANK OF AMERICA ATM Daly City, CA - 3.7 Miles                                          |" << endl;
    cout << "| BANK OF AMERICA ATM 99 Serramonte Center Daly City, CA 94015 - 3.9 Miles away          |" << endl;
    cout << "| ATM (BANK OF AMERICA) 465 San Mateo Ave, San Bruno, CA 94066 - 4.1 Miles away          |" << endl;
    cout << "| BANK OF AMERICA  ATM 1375 Linda Mar Shopping Ctr, Pacifica, CA 94044 - 5 Miles away    |" << endl;
    cout << "| BANK OF AMERICA ATM San Francisco Peninsula, San Francisco, CA 94128 - 7.7 Miles away  |" << endl;
    cout << "|________________________________________________________________________________________|" << endl;
}

void writeReceipt() { // Asks user if they want a receipt, and prints receipt if they do
    string line, receiptChoice, userEmail;
    cout << "Would you like a receipt? (Y/N)" << endl;
    cin >> receiptChoice;
    if (receiptChoice == "y" || receiptChoice == "Y") {
        cout << " _____________________________ " << endl;
        cout << "|                             |" << endl;
        cout << "| Please select an option.    |" << endl;
        cout << "| [1] Print Receipt           |" << endl;
        cout << "| [2] Email Receipt only      |" << endl;
        cout << "| [3] Print and Email Receipt |" << endl;
        cout << "|_____________________________|" << endl;
        cin >> receiptChoice;
        if (receiptChoice == "1") { // Print Receipt only
            ifstream writeReceipt("atmReceipt.txt");
            if (writeReceipt.is_open()) {
                cout << "-----------------------------------------" << endl;
                while (getline(writeReceipt, line)) {
                    cout << line << endl;
                }
                cout << "-----------------------------------------" << endl;
            }
        }
        if (receiptChoice == "2") { // Email receipt only
            cout << "Please enter your email address: ";
            cin >> userEmail;
            cout << "An email of your receipt has been sent to " << userEmail << endl;
        }
        if (receiptChoice == "3") { // Print and email receipt
            ifstream writeReceipt("atmReceipt.txt");
            if (writeReceipt.is_open()) {
                cout << "_________________________________________" << endl;
                while (getline(writeReceipt, line)) {
                    cout << line << endl;
                }
                cout << "_________________________________________" << endl;
            }
            cout << "Please enter your email address: ";
            cin >> userEmail;
            cout << "An email of your receipt has been sent to " << userEmail << endl;
        }
    }
    else if ((receiptChoice == "N" || receiptChoice == "n")) {
        cout << "Thank you, have a good day." << endl;
    }
}

void saveData(atmUser& currentUser) { // Updates stored data
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

atmUser getUser(string userName, int userID) { // returns an atmUser object with stored data if it is found, if no matching user data found then returns empty atmUser object
    string storedName, line;
    int storedPIN, storedID;
    float storedSaving, storedChecking;
    atmUser targetUser;
    ifstream atmData("atmData.txt");
    if (atmData.is_open())
    {
        while (getline(atmData, line))
        {
            stringstream currentline(line); // Creates string stream to use getline on current line in file
            getline(currentline, storedName, '|');
            currentline >> storedPIN >> storedChecking >> storedSaving >> storedID; // Grabs rest of stored data
            if (userName == storedName) // If name matches checks ID
            {
                if (userID == storedID) { // If ID matches as well, then sets the object's member variables equal to the stored data
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

void mainMenu(atmUser& currentUser) {
    char anotherTransaction = 'Y';
    char mainChoice = '0';
    char withdrawChoice = '0';
    
    char accountChoice = '0'; // Variable for cases [1] Withdraw and [2] Deposit: 1 = Checkings Account, 2 = Savings Account
    char cardType = '0'; // Variable for case [1] Withdraw: 1 = Debit card, 2 = Credit card
    float withdrawFee = 0;
    float transactionAmount = 0;
    
    char transferChoice = '0'; // Variable for case [4] Transfer or make Payments: 1 = Transfer between checkings/savings, 2 = Payments to others
    string transferRecipient = "";
    int transferRecipientID = 0;
    
    string addChoice = "0"; // Variable for case [5] Other Options: 1 = Change pin, 2 = Display nearby locations
    char paymentChoice = '0'; // Variable for case [4] Transfer or make Payments: 1 = Payments to others within same bank, 2 = Payments to outisde world

    displayMainmenu();
    cin >> mainChoice;
    mainChoice = checkMainChoice(mainChoice);
    ifstream atmReceipt("atmReceipt.txt", ios::trunc); // Opens receipt file in trunc mode, clearing old data
    atmReceipt.close();
    ofstream storeReceipt("atmReceipt.txt"); // Opens stream to write to clean receipt file
    if (storeReceipt.is_open()) {
        storeReceipt << "Name: " << currentUser.getName() << endl; // Writes down users name at the top of  receipt
        do { // Main do while loop of program, while anotherTransaction function is = 'Y', keeps looping
            switch (mainChoice) {
            case '1': // -------------------------------------------------- Case [1] Withdraw option -------------------------------------------------- //
                displayCardMenu();
                cin >> cardType;
                cardType = checkAccountChoice(cardType);
                displayAccountChoice();
                cin >> accountChoice;
                accountChoice = checkAccountChoice(accountChoice);
                cout << " _________________________________" << endl;
                cout << "|                                 |" << endl;
                cout << "| Withdraw Limit: $2,000.00       |" << endl;
                cout << "|_________________________________|" << endl;
                if (accountChoice == '1') { // ------------------ Using checkings account ------------------ //
                    displayWithdrawmenu();
                    cin >> withdrawChoice;
                    switch (withdrawChoice) {
                        case '1': // $20 Withdraw
                            withdrawFee = 20*0.05;
                            if (20 > currentUser.getCheckingBalance()) {
                                cout << "Not enough money to withdraw." << endl;
                            }
                            else if(cardType == '1') { // Debit card ( No Fee )
                                currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 20);
                                cout << "You successfully withdrew $20.00 from checkings" << endl;
                                storeReceipt << "Withdraw from checkings: $20.00" << endl;
                            }
                            else if(cardType == '2'){ // Credit card ( Fee )
                                if((20+withdrawFee) <= currentUser.getCheckingBalance()){ // If using credit card, includes fees so user cant overdraw cash.
                                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - (20 + withdrawFee));
                                    cout << "You successfully withdrew $20.00 from checkings" << endl;
                                    cout << "Credit Card Fee: $" << withdrawFee << endl;
                                    storeReceipt << "Withdraw from checkings: $20.00" << endl;
                                    storeReceipt << "Withdraw Fee: $" << withdrawFee << endl;
                                }
                                else{
                                    cout << "Not enough money to withdraw including $" << withdrawFee << " fee." << endl;
                                }
                            }
                            break;
                        case '2': // $40 Withdraw
                            withdrawFee = 40*0.05;
                            if (40 > currentUser.getCheckingBalance()) {
                                cout << "Not enough money to withdraw." << endl;
                            }
                            else if(cardType == '1') {
                                currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 40);
                                cout << "You successfully withdrew $40.00 from checkings" << endl;
                                storeReceipt << "Withdraw from checkings: $40.00" << endl;
                            }
                            else if(cardType == '2'){
                                if((40+withdrawFee) <= currentUser.getCheckingBalance()){
                                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - (40 + withdrawFee));
                                    cout << "You successfully withdrew $40.00 from checkings" << endl;
                                    cout << "Credit Card Fee: $" << withdrawFee << endl;
                                    storeReceipt << "Withdraw from checkings: $40.00" << endl;
                                    storeReceipt << "Withdraw Fee: $" << withdrawFee << endl;
                                }
                                else{
                                    cout << "Not enough money to withdraw including $" << withdrawFee << " fee." << endl;
                                }
                            }
                            break;
                        case '3': // $60 Withdraw
                            withdrawFee = 60*0.05;
                            if (60 > currentUser.getCheckingBalance()) {
                                cout << "Not enough money to withdraw." << endl;
                            }
                            else if(cardType == '1') {
                                currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 60);
                                cout << "You successfully withdrew $60.00 from checkings" << endl;
                                storeReceipt << "Withdraw from checkings: $60.00" << endl;
                            }
                            else if(cardType == '2'){
                                if((60+withdrawFee) <= currentUser.getCheckingBalance()){
                                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - (60 + withdrawFee));
                                    cout << "You successfully withdrew $60.00 from checkings" << endl;
                                    cout << "Credit Card Fee: $" << withdrawFee << endl;
                                    storeReceipt << "Withdraw from checkings: $60.00" << endl;
                                    storeReceipt << "Withdraw Fee: $" << withdrawFee << endl;
                                }
                                else{
                                    cout << "Not enough money to withdraw including $" << withdrawFee << " fee." << endl;
                                }
                            }
                            break;
                        case '4': // $80 Withdraw
                            withdrawFee = 80*0.05;
                            if (80 > currentUser.getCheckingBalance()) {
                                cout << "Not enough money to withdraw." << endl;
                            }
                            else if(cardType == '1') {
                                currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 80);
                                cout << "You successfully withdrew $80.00 from checkings" << endl;
                                storeReceipt << "Withdraw from checkings: $80.00" << endl;
                            }
                            else if(cardType == '2'){
                                if((80+withdrawFee) <= currentUser.getCheckingBalance()){
                                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - (80 + withdrawFee));
                                    cout << "You successfully withdrew $80.00 from checkings" << endl;
                                    cout << "Credit Card Fee: $" << withdrawFee << endl;
                                    storeReceipt << "Withdraw from checkings: $80.00" << endl;
                                    storeReceipt << "Withdraw Fee: $" << withdrawFee << endl;
                                }
                                else{
                                    cout << "Not enough money to withdraw including $" << withdrawFee << " fee." << endl;
                                }
                            }
                            break;
                        case '5': // $100 Withdraw
                            withdrawFee = 100*0.05;
                            if (100 > currentUser.getCheckingBalance()) {
                                cout << "Not enough money to withdraw." << endl;
                            }
                            else if(cardType == '1') {
                                currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 100);
                                cout << "You successfully withdrew $100.00 from checkings" << endl;
                                storeReceipt << "Withdraw from checkings: $100.00" << endl;
                            }
                            else if(cardType == '2'){
                                if((100+withdrawFee) <= currentUser.getCheckingBalance()){
                                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - (100 + withdrawFee));
                                    cout << "You successfully withdrew $100.00 from checkings" << endl;
                                    cout << "Credit Card Fee: $" << withdrawFee << endl;
                                    storeReceipt << "Withdraw from checkings: $100.00" << endl;
                                    storeReceipt << "Withdraw Fee: $" << withdrawFee << endl;
                                }
                                else{
                                    cout << "Not enough money to withdraw including $" << withdrawFee << " fee." << endl;
                                }
                            }
                            break;
                        case '6': // $200 Withdraw
                            withdrawFee = 200*0.10;
                            if (200 > currentUser.getCheckingBalance()) {
                                cout << "Not enough money to withdraw." << endl;
                            }
                            else if(cardType == '1') {
                                currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 200);
                                cout << "You successfully withdrew $200.00 from checkings" << endl;
                                storeReceipt << "Withdraw from checkings: $200.00" << endl;
                            }
                            else if(cardType == '2'){
                                if((200+withdrawFee) <= currentUser.getCheckingBalance()){
                                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - (200 + withdrawFee));
                                    cout << "You successfully withdrew $200.00 from checkings" << endl;
                                    cout << "Credit Card Fee: $" << withdrawFee << endl;
                                    storeReceipt << "Withdraw from checkings: $200.00" << endl;
                                    storeReceipt << "Withdraw Fee: $" << withdrawFee << endl;
                                }
                                else{
                                    cout << "Not enough money to withdraw including $" << withdrawFee << " fee." << endl;
                                }
                            }
                            break;
                        case '7': // $300 Withdraw
                            withdrawFee = 300*0.10;
                            if (300 > currentUser.getCheckingBalance()) {
                                cout << "Not enough money to withdraw." << endl;
                            }
                            else if(cardType == '1') {
                                currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 300);
                                cout << "You successfully withdrew $300.00 from checkings" << endl;
                                storeReceipt << "Withdraw from checkings: $300.00" << endl;
                            }
                            else if(cardType == '2'){
                                if((300+withdrawFee) <= currentUser.getCheckingBalance()){
                                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - (300 + withdrawFee));
                                    cout << "You successfully withdrew $300.00 from checkings" << endl;
                                    cout << "Credit Card Fee: $" << withdrawFee << endl;
                                    storeReceipt << "Withdraw from checkings: $300.00" << endl;
                                    storeReceipt << "Withdraw Fee: $" << withdrawFee << endl;
                                }
                                else{
                                    cout << "Not enough money to withdraw including $" << withdrawFee << " fee." << endl;
                                }
                            }
                            break;
                        case '8': // Other Amount Withdraw
                            cout << "Enter an amount to withdraw." << endl;
                            cin >> transactionAmount;
                            if(transactionAmount >= 500){
                                withdrawFee = transactionAmount*0.15;
                            }
                            else if(transactionAmount >= 200){
                                withdrawFee = transactionAmount*0.10;
                            }
                            else{
                                withdrawFee = transactionAmount*0.05;
                            }
                            if (transactionAmount > currentUser.getCheckingBalance()) {
                                cout << "Not enough money to withdraw." << endl;
                            }
                            else if (transactionAmount > 2000) {
                                cout << "Sorry, you cannot withdraw more than $2,000." << endl;
                            }
                            else if (cardType == '1'){
                                currentUser.setCheckingBalance(currentUser.getCheckingBalance() - transactionAmount);
                                cout << "You successfully withdrew $" << transactionAmount << " from checkings." << endl;
                                storeReceipt << "Withdraw from checkings: $" << transactionAmount << endl;
                            }
                            else if (cardType == '2'){
                                if((transactionAmount+withdrawFee) <= currentUser.getCheckingBalance()){
                                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - (transactionAmount + withdrawFee));
                                    cout << "You successfully withdrew $" << transactionAmount << " from checkings." << endl;
                                    cout << "Credit Card Fee: $" << withdrawFee << endl;
                                    storeReceipt << "Withdraw from checkings: $" << transactionAmount << endl;
                                    storeReceipt << "Withdraw Fee: $" << withdrawFee << endl;
                                }
                                else{
                                    cout << "Not enough money to withdraw including $" << withdrawFee << " fee." << endl;
                                }
                            }
                            break;
                        default:
                            withdrawChoice = checkWithdrawChoice(withdrawChoice);
                        }
                }
                else if (accountChoice == '2') { // ------------------ Using savings account ------------------ //
                    displayWithdrawmenu();
                    cin >> withdrawChoice;
                    switch (withdrawChoice) {
                        case '1': // $20 Withdraw
                            withdrawFee = 20*0.05;
                            if (20 > currentUser.getSavingBalance()) {
                                cout << "Not enough money to withdraw." << endl;
                            }
                            else if(cardType == '1') { // Debit card ( No Fee)
                                currentUser.setSavingBalance(currentUser.getSavingBalance() - 20);
                                cout << "You successfully withdrew $20.00 from savings" << endl;
                                storeReceipt << "Withdraw from savings: $20.00" << endl;
                            }
                            else if(cardType == '2'){ // Credit card ( Fee )
                                if((20+withdrawFee) <= currentUser.getSavingBalance()){
                                    currentUser.setSavingBalance(currentUser.getSavingBalance() - (20 + withdrawFee));
                                    cout << "You successfully withdrew $20.00 from savings" << endl;
                                    cout << "Credit Card Fee: $" << withdrawFee << endl;
                                    storeReceipt << "Withdraw from savings: $20.00" << endl;
                                    storeReceipt << "Withdraw Fee: $" << withdrawFee << endl;
                                }
                                else{
                                    cout << "Not enough money to withdraw including $" << withdrawFee << " fee." << endl;
                                }
                            }
                            break;
                        case '2': // $40 Withdraw
                            withdrawFee = 40*0.05;
                            if (40 > currentUser.getSavingBalance()) {
                                cout << "Not enough money to withdraw." << endl;
                            }
                            else if(cardType == '1') {
                                currentUser.setSavingBalance(currentUser.getSavingBalance() - 40);
                                cout << "You successfully withdrew $40.00 from savings" << endl;
                                storeReceipt << "Withdraw from savings: $40.00" << endl;
                            }
                            else if(cardType == '2'){
                                if((40+withdrawFee) <= currentUser.getSavingBalance()){
                                    currentUser.setSavingBalance(currentUser.getSavingBalance() - (40 + withdrawFee));
                                    cout << "You successfully withdrew $40.00 from savings" << endl;
                                    cout << "Credit Card Fee: $" << withdrawFee << endl;
                                    storeReceipt << "Withdraw from savings: $40.00" << endl;
                                    storeReceipt << "Withdraw Fee: $" << withdrawFee << endl;
                                }
                                else{
                                    cout << "Not enough money to withdraw including $" << withdrawFee << " fee." << endl;
                                }
                            }
                            break;
                        case '3': // $60 Withdraw
                            withdrawFee = 60*0.05;
                            if (60 > currentUser.getSavingBalance()) {
                                cout << "Not enough money to withdraw." << endl;
                            }
                            else if(cardType == '1') {
                                currentUser.setSavingBalance(currentUser.getSavingBalance() - 60);
                                cout << "You successfully withdrew $60.00 from savings" << endl;
                                storeReceipt << "Withdraw from savings: $60.00" << endl;
                            }
                            else if(cardType == '2'){
                                if((60+withdrawFee) <= currentUser.getSavingBalance()){
                                    currentUser.setSavingBalance(currentUser.getSavingBalance() - (60 + withdrawFee));
                                    cout << "You successfully withdrew $60.00 from savings" << endl;
                                    cout << "Credit Card Fee: $" << withdrawFee << endl;
                                    storeReceipt << "Withdraw from savings: $60.00" << endl;
                                    storeReceipt << "Withdraw Fee: $" << withdrawFee << endl;
                                }
                                else{
                                    cout << "Not enough money to withdraw including $" << withdrawFee << " fee." << endl;
                                }
                            }
                            break;
                        case '4': // $80 Withdraw
                            withdrawFee = 80*0.05;
                            if (80 > currentUser.getSavingBalance()) {
                                cout << "Not enough money to withdraw." << endl;
                            }
                            else if(cardType == '1') {
                                currentUser.setSavingBalance(currentUser.getSavingBalance() - 80);
                                cout << "You successfully withdrew $80.00 from savings" << endl;
                                storeReceipt << "Withdraw from savings: $80.00" << endl;
                            }
                            else if(cardType == '2'){
                                if((80+withdrawFee) <= currentUser.getSavingBalance()){
                                    currentUser.setSavingBalance(currentUser.getSavingBalance() - (80 + withdrawFee));
                                    cout << "You successfully withdrew $80.00 from savings" << endl;
                                    cout << "Credit Card Fee: $" << withdrawFee << endl;
                                    storeReceipt << "Withdraw from savings: $80.00" << endl;
                                    storeReceipt << "Withdraw Fee: $" << withdrawFee << endl;
                                }
                                else{
                                    cout << "Not enough money to withdraw including $" << withdrawFee << " fee." << endl;
                                }
                            }
                            break;
                        case '5': // $100 Withdraw
                            withdrawFee = 100*0.05;
                            if (100 > currentUser.getSavingBalance()) {
                                cout << "Not enough money to withdraw." << endl;
                            }
                            else if(cardType == '1') {
                                currentUser.setSavingBalance(currentUser.getSavingBalance() - 100);
                                cout << "You successfully withdrew $100.00 from savings" << endl;
                                storeReceipt << "Withdraw from savings: $100.00" << endl;
                            }
                            else if(cardType == '2'){
                                if((100+withdrawFee) <= currentUser.getSavingBalance()){
                                    currentUser.setSavingBalance(currentUser.getSavingBalance() - (100 + withdrawFee));
                                    cout << "You successfully withdrew $100.00 from savings" << endl;
                                    cout << "Credit Card Fee: $" << withdrawFee << endl;
                                    storeReceipt << "Withdraw from savings: $100.00" << endl;
                                    storeReceipt << "Withdraw Fee: $" << withdrawFee << endl;
                                }
                                else{
                                    cout << "Not enough money to withdraw including $" << withdrawFee << " fee." << endl;
                                }
                            }
                            break;
                        case '6': // $200 Withdraw
                            withdrawFee = 200*0.10;
                            if (200 > currentUser.getSavingBalance()) {
                                cout << "Not enough money to withdraw." << endl;
                            }
                            else if(cardType == '1') {
                                currentUser.setSavingBalance(currentUser.getSavingBalance() - 200);
                                cout << "You successfully withdrew $200.00 from savings" << endl;
                                storeReceipt << "Withdraw from savings: $200.00" << endl;
                            }
                            else if(cardType == '2'){
                                if((200+withdrawFee) <= currentUser.getSavingBalance()){
                                    currentUser.setSavingBalance(currentUser.getSavingBalance() - (200 + withdrawFee));
                                    cout << "You successfully withdrew $200.00 from savings" << endl;
                                    cout << "Credit Card Fee: $" << withdrawFee << endl;
                                    storeReceipt << "Withdraw from savings: $200.00" << endl;
                                    storeReceipt << "Withdraw Fee: $" << withdrawFee << endl;
                                }
                                else{
                                    cout << "Not enough money to withdraw including $" << withdrawFee << " fee." << endl;
                                }
                            }
                            break;
                        case '7': // $300 Withdraw
                            withdrawFee = 300*0.10;
                            if (300 > currentUser.getSavingBalance()) {
                                cout << "Not enough money to withdraw." << endl;
                            }
                            else if(cardType == '1') {
                                currentUser.setSavingBalance(currentUser.getSavingBalance() - 300);
                                cout << "You successfully withdrew $300.00 from savings" << endl;
                                storeReceipt << "Withdraw from savings: $300.00" << endl;
                            }
                            else if(cardType == '2'){
                                if((300+withdrawFee) <= currentUser.getSavingBalance()){
                                    currentUser.setSavingBalance(currentUser.getSavingBalance() - (300 + withdrawFee));
                                    cout << "You successfully withdrew $300.00 from savings" << endl;
                                    cout << "Credit Card Fee: $" << withdrawFee << endl;
                                    storeReceipt << "Withdraw from savings: $300.00" << endl;
                                    storeReceipt << "Withdraw Fee: $" << withdrawFee << endl;
                                }
                                else{
                                    cout << "Not enough money to withdraw including $" << withdrawFee << " fee." << endl;
                                }
                            }
                            break;
                        case '8': // Other Amount Withdraw
                            cout << "Enter an amount to withdraw." << endl;
                            cin >> transactionAmount;
                            if(transactionAmount >= 500){ // Calculates withdraw fee based on entered transaction amount
                                withdrawFee = transactionAmount*0.15;
                            }
                            else if(transactionAmount >= 200){
                                withdrawFee = transactionAmount*0.10;
                            }
                            else{
                                withdrawFee = transactionAmount*0.05;
                            }
                            if (transactionAmount > currentUser.getSavingBalance()) {
                                cout << "Not enough money to withdraw." << endl;
                            }
                            else if (transactionAmount > 2000) {
                                cout << "Sorry, you cannot withdraw more than $2,000." << endl;
                            }
                            else if (cardType == '1'){
                                currentUser.setSavingBalance(currentUser.getSavingBalance() - transactionAmount);
                                cout << "You successfully withdrew $" << transactionAmount << " from savings" << endl;
                                storeReceipt << "Withdraw from savings: $" << transactionAmount << endl;
                            }
                            else if (cardType == '2'){
                                if((transactionAmount+withdrawFee) <= currentUser.getSavingBalance()){
                                    currentUser.setSavingBalance(currentUser.getSavingBalance() - (transactionAmount + withdrawFee));
                                    cout << "You successfully withdrew $" << transactionAmount << " from savings" << endl;
                                    cout << "Credit Card Fee: $" << withdrawFee << endl;
                                    storeReceipt << "Withdraw from savings: $" << transactionAmount << endl;
                                    storeReceipt << "Withdraw Fee: $" << withdrawFee << endl;
                                }
                                else{
                                    cout << "Not enough money to withdraw including $" << withdrawFee << " fee." << endl;
                                }
                            }
                            break;
                        default:
                            withdrawChoice = checkWithdrawChoice(withdrawChoice);
                        }
                }
                cout << "Would you like another transaction? (Y/N)" << endl; // Asks if user wants another transaction, this block is at the end of each case
                cin >> anotherTransaction;
                anotherTransaction = checkAdditionalTrans(anotherTransaction);
                if (anotherTransaction == 'Y' || anotherTransaction == 'y') {
                    displayMainmenu();
                    cin >> mainChoice;
                    mainChoice = checkMainChoice(mainChoice);
                }
                break;
            case '2': // -------------------------------------------------- Case [2] Deposit option -------------------------------------------------- //
                displayAccountChoice();
                cin >> accountChoice;
                accountChoice = checkAccountChoice(accountChoice);
                cout << " _________________________________" << endl;
                cout << "|                                 |" << endl;
                cout << "| Deposit Limit: $5,000.00        |" << endl;
                cout << "|_________________________________|" << endl;
                if (accountChoice == '1') { // Using checkings account
                    cout << "Enter an amount to deposit: ";
                    cin >> transactionAmount;
                    while (transactionAmount < 0 || transactionAmount > 5000) { // Makes sure deposit is not negative or more than $5,000
                        cout << "Please deposit a valid amount." << endl;
                        cin >> transactionAmount;
                    }
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() + transactionAmount);
                    storeReceipt << "Deposit to checking: $" << transactionAmount << endl;
                    cout << "You successfully deposited $" << transactionAmount << " to checkings." << endl;
                }
                else if (accountChoice == '2') { // Using savings account
                    cout << "Enter an amount to deposit: ";
                    cin >> transactionAmount;
                    while (transactionAmount < 0 || transactionAmount > 5000) { // Makes sure deposit is not negative or more than $5,000
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
            case '3': // -------------------------------------------------- Case [3] Check Balance -------------------------------------------------- //
                displayAccountChoice();
                cin >> accountChoice;
                accountChoice = checkAccountChoice(accountChoice);
                if (accountChoice == '1') { // Checkings account
                    cout << "Your current checking balance is: " << "$" << currentUser.getCheckingBalance() << endl;
                }
                else if (accountChoice == '2') { // Savings account
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
            case '4': // -------------------------------------------------- Case [4] Transfer or make payments -------------------------------------------------- //
                displayAccountChoice();
                cin >> accountChoice;
                accountChoice = checkAccountChoice(accountChoice);
                if (accountChoice == '1') { // ------------------ Using checkings account ------------------ //
                    cout << " _______________________________" << endl;
                    cout << "|                               |" << endl;
                    cout << "| [1] Transfer money to savings |" << endl;
                    cout << "| [2] Make Payments             |" << endl;
                    cout << "|_______________________________|" << endl;
                    cin >> transferChoice;
                    transferChoice = checkTransferChoice(transferChoice);
                    if (transferChoice == '1') { // Transfer money to savings
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
                    else if (transferChoice == '2') { // Make payments
                        cout << " _________________________________________" << endl;
                        cout << "|                                         |" << endl;
                        cout << "| Please select an option                 |" << endl;
                        cout << "| [1] Payments to others within this bank |" << endl;
                        cout << "| [2] Payments elsewhere                  |" << endl;
                        cout << "|_________________________________________|" << endl;
                        cin >> paymentChoice;
                        paymentChoice = checkTransferChoice(paymentChoice);
                        if (paymentChoice == '1') { // Payments to other users within this bank ( Must be saved in data file )
                            cout << "Enter name of payment recipient: ";
                            cin.ignore();
                            getline(cin, transferRecipient);
                            cout << "Enter recipient ID: "; // User must know ID of transfer recipient, acts like psuedo routing number
                            cin >> transferRecipientID;
                            if (userExist(transferRecipient, transferRecipientID)) { // Checks data to make sure name and ID are valid
                                cout << "Enter payment amount: ";
                                cin >> transactionAmount;
                                if (transactionAmount <= currentUser.getCheckingBalance() && transactionAmount > 0) {
                                    atmUser transferUser(getUser(transferRecipient, transferRecipientID)); // GetUser grabs transfer recipient data, and then we create a new atmUser object that is a clone of what GetUser grabs
                                    transferMoney(currentUser, transferUser, transactionAmount, accountChoice);
                                    storeReceipt << "Payment to " << transferUser.getName() << " from checking: $" << transactionAmount << endl;
                                }
                                else {
                                    cout << "Invalid transfer amount." << endl;
                                }
                            }
                        }
                        else if (paymentChoice == '2') { // Payments elsewhere
                            cout << "Enter name of payment recipient: ";
                            cin.ignore();
                            getline(cin, transferRecipient);
                            cout << "Enter payment amount: ";
                            cin >> transactionAmount;
                            if (transactionAmount <= currentUser.getCheckingBalance() && transactionAmount > 0) {
                                currentUser.setCheckingBalance(currentUser.getCheckingBalance() - transactionAmount);
                                cout << "Payment to " << transferRecipient << " from checking: $" << transactionAmount << endl;
                                storeReceipt << "Payment to " << transferRecipient << " from checking: $" << transactionAmount << endl;
                            }
                            else {
                                cout << "Invalid transfer amount." << endl;
                            }
                        }
                    }
                }
                else if (accountChoice == '2') { // ------------------ Using savings account ------------------ //
                    cout << " _________________________________" << endl;
                    cout << "|                                 |" << endl;
                    cout << "| [1] Transfer money to checkings |" << endl;
                    cout << "| [2] Make Payments               |" << endl;
                    cout << "|_________________________________|" << endl;
                    cin >> transferChoice;
                    transferChoice = checkTransferChoice(transferChoice);
                    if (transferChoice == '1') { // Transfer money to checkings
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
                    else if (transferChoice == '2') { // Make payments
                        cout << " _________________________________________" << endl;
                        cout << "|                                         |" << endl;
                        cout << "| [1] Payments to others within this bank |" << endl;
                        cout << "| [2] Payments elsewhere                  |" << endl;
                        cout << "|_________________________________________|" << endl;
                        cin >> paymentChoice;
                        paymentChoice = checkTransferChoice(paymentChoice);
                        if (paymentChoice == '1') { // Payments to other users within this bank ( Must be saved in data file )
                            cout << "Enter name of transfer recipient: ";
                            cin.ignore(); // Clear cin stream
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
                        else if (paymentChoice == '2') { // Payments elsewhere
                            cout << "Enter name of payment recipient: ";
                            cin.ignore(); // Clear cin stream
                            getline(cin, transferRecipient);
                            cout << "Enter payment amount: ";
                            cin >> transactionAmount;
                            if (transactionAmount <= currentUser.getSavingBalance() && transactionAmount > 0) {
                                currentUser.setSavingBalance(currentUser.getSavingBalance() - transactionAmount);
                                cout << "Payment to " << transferRecipient << " from checking: $" << transactionAmount << endl;
                                storeReceipt << "Payment to " << transferRecipient << " from checking: $" << transactionAmount << endl;
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
                cout << " ______________________________" << endl;
                cout << "|                              |" << endl;
                cout << "| [1] Change PIN               |" << endl;
                cout << "| [2] Nearby ATM Locations     |" << endl;
                cout << "|______________________________|" << endl;
                cin.ignore(); // Ignores "\n" character, clears out cin stream
                getline(cin, addChoice);
                while (!(addChoice == "1" || addChoice == "2")) {
                    cout << "| Please enter a valid option: |" << endl;
                    cout << "|______________________________|" << endl;
                    cin >> addChoice;
                }
                if (addChoice == "1") {
                    int newPIN;
                    cout << "Choose a new PIN:";
                    cin >> newPIN;
                    while (newPIN > 9999 || newPIN <= 999) { // Makes sure new pin is valid
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

        storeReceipt << "Current Checking balance: $" << currentUser.getCheckingBalance() << endl; // Adds current user balance to end of receipt
        storeReceipt << "Current Saving balance: $" << currentUser.getSavingBalance() << endl;
        storeReceipt.close();

        if (anotherTransaction != '0') { // If user doesn't choose to quit, asks for receipt
            writeReceipt();
        }
        saveData(currentUser);
    }
}

void splashMenu(atmUser& currentUser) { // adds splash menu before main menu, allows user to quick withdraw
    string splashChoice = "0";
    string withdrawChoice = "0";
    char cardType = '0';
    float withdrawFee = 0;
    cout << " ________________________________" << endl;
    cout << "|                                |" << endl;
    cout << "| What would you like to do?     |" << endl;
    cout << "| [1] Quick Withdraw             |" << endl;
    cout << "| [2] Main Menu                  |" << endl;
    cout << "| [3] Quit                       |" << endl;
    cout << "|________________________________|" << endl;
    cin.ignore();
    getline(cin, splashChoice);
    while (splashChoice > "3" || splashChoice < "1") { // Makes sure user chooses valid choice 1-3
        cout << "| Please choose a valid choice.  |" << endl;
        cout << "|________________________________|" << endl;
        getline(cin, splashChoice);
    }
    if (splashChoice == "1") {
        displayCardMenu();
        cin >> cardType;
        cardType = checkAccountChoice(cardType);
        cin.ignore();
        if (currentUser.getCheckingBalance() >= (80+(80*0.05))) { // If user has at least 80 dollars + withdraw fee, shows all quick withdraw options
            cout << " _______________________________" << endl;
            cout << "| Choose an amount to withdraw. |" << endl;
            cout << "| [1] $20                       |" << endl;
            cout << "| [2] $40                       |" << endl;
            cout << "| [3] $60                       |" << endl;
            cout << "| [4] $80                       |" << endl;
            cout << "| [5] Main Menu                 |" << endl;
            cout << "| [6] Quit                      |" << endl;
            cout << "|_______________________________|" << endl;
            getline(cin, withdrawChoice);
            while (!(withdrawChoice == "1" || withdrawChoice == "2" || withdrawChoice == "3" || withdrawChoice == "4" || withdrawChoice == "5" || withdrawChoice == "6")) {
                cout << "Please choose a valid option." << endl;
                getline(cin, withdrawChoice);
            }
            if(cardType == '1'){ // Debit Card
                if (withdrawChoice == "1") {
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 20);
                    cout << "$20.00 has been withdrawn from your checkings account." << endl;
                }
                else if (withdrawChoice == "2") {
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 40);
                    cout << "$40.00 has been withdrawn from your checkings account." << endl;
                }
                else if (withdrawChoice == "3") {
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 60);
                    cout << "$60.00 has been withdrawn from your checkings account." << endl;
                }
                else if (withdrawChoice == "4") {
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 80);
                    cout << "$80.00 has been withdrawn from your checkings account." << endl;
                }
                else if (withdrawChoice == "5") {
                    mainMenu(currentUser);
                }
                else if(withdrawChoice == "6"){
                    cout << "Thank you have a good day." << endl;
                }
            }
            else if(cardType == '2'){ // Credit card
                if (withdrawChoice == "1") {
                    withdrawFee = 20*0.05;
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - (20 + withdrawFee));
                    cout << "$20.00 has been withdrawn from your checkings account." << endl;
                    cout << "Withdraw Fee: $" << withdrawFee << endl;
                }
                else if (withdrawChoice == "2") {
                    withdrawFee = 40*0.05;
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - (40 + withdrawFee));
                    cout << "$40.00 has been withdrawn from your checkings account." << endl;
                    cout << "Withdraw Fee: $" << withdrawFee << endl;
                }
                else if (withdrawChoice == "3") {
                    withdrawFee = 60*0.05;
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - (60 + withdrawFee));
                    cout << "$60.00 has been withdrawn from your checkings account." << endl;
                    cout << "Withdraw Fee: $" << withdrawFee << endl;
                }
                else if (withdrawChoice == "4") {
                    withdrawFee = 80*0.05;
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - (80 + withdrawFee));
                    cout << "$80.00 has been withdrawn from your checkings account." << endl;
                    cout << "Withdraw Fee: $" << withdrawFee << endl;
                }
                else if (withdrawChoice == "5") {
                    mainMenu(currentUser);
                }
                else if(withdrawChoice == "6"){
                    cout << "Thank you have a good day." << endl;
                }
            }
        }
        else if (currentUser.getCheckingBalance() >= (60+(60*0.05))) { // If user has 60 dollars + withdraw fee in checking, shows fewer options
            cout << " _______________________________" << endl;
            cout << "| Choose an amount to withdraw. |" << endl;
            cout << "| [1] $20                       |" << endl;
            cout << "| [2] $40                       |" << endl;
            cout << "| [3] $60                       |" << endl;
            cout << "| [4] Main Menu                 |" << endl;
            cout << "| [5] Quit                      |" << endl;
            cout << "|_______________________________|" << endl;
            getline(cin, withdrawChoice);
            while (!(withdrawChoice == "1" || withdrawChoice == "2" || withdrawChoice == "3" || withdrawChoice == "4" || withdrawChoice == "5")) {
                cout << "| Please choose a valid option. |" << endl;
                cout << "|_______________________________|" << endl;
                getline(cin, withdrawChoice);
            }
            if(cardType == '1'){ // Debit card
                if (withdrawChoice == "1") {
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 20);
                    cout << "$20.00 has been withdrawn from your checkings account." << endl;
                }
                else if (withdrawChoice == "2") {
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 40);
                    cout << "$40.00 has been withdrawn from your checkings account." << endl;
                }
                else if (withdrawChoice == "3") {
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 60);
                    cout << "$60.00 has been withdrawn from your checkings account." << endl;
                }
                else if (withdrawChoice == "4") {
                    mainMenu(currentUser);
                }
                else if(withdrawChoice == "5"){
                    cout << "Thank you have a good day." << endl;
                }
            }
            else if(cardType == '2'){ // Credit card
                if (withdrawChoice == "1") {
                    withdrawFee = 20*0.05;
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - (20 + withdrawFee));
                    cout << "$20.00 has been withdrawn from your checkings account." << endl;
                    cout << "Withdraw Fee: $" << withdrawFee << endl;
                }
                else if (withdrawChoice == "2") {
                    withdrawFee = 40*0.05;
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - (40 + withdrawFee));
                    cout << "$40.00 has been withdrawn from your checkings account." << endl;
                    cout << "Withdraw Fee: $" << withdrawFee << endl;
                }
                else if (withdrawChoice == "3") {
                    withdrawFee = 60*0.05;
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - (60 + withdrawFee));
                    cout << "$60.00 has been withdrawn from your checkings account." << endl;
                    cout << "Withdraw Fee: $" << withdrawFee << endl;
                }
                else if (withdrawChoice == "4") {
                    mainMenu(currentUser);
                }
                else if(withdrawChoice == "5"){
                    cout << "Thank you have a good day." << endl;
                }
            }
        }
        else if (currentUser.getCheckingBalance() >= (40+(40*0.05))) { // If user has 40 dollars + withdraw fee in checking, shows fewer options
            cout << " _______________________________" << endl;
            cout << "| Choose an amount to withdraw. |" << endl;
            cout << "| [1] $20                       |" << endl;
            cout << "| [2] $40                       |" << endl;
            cout << "| [3] Main menu                 |" << endl;
            cout << "| [4] Quit                      |" << endl;
            cout << "|_______________________________|" << endl;
            getline(cin, withdrawChoice);
            while (!(withdrawChoice == "1" || withdrawChoice == "2" || withdrawChoice == "3" || withdrawChoice == "4")) {
                cout << "| Please choose a valid option. |" << endl;
                cout << "|_______________________________|" << endl;
                getline(cin, withdrawChoice);
            }
            if(cardType == '1'){ // Debit card
                if (withdrawChoice == "1") {
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 20);
                    cout << "$20.00 has been withdrawn from your checkings account." << endl;
                }
                else if (withdrawChoice == "2") {
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 40);
                    cout << "$40.00 has been withdrawn from your checkings account." << endl;
                }
                else if (withdrawChoice == "3") {
                    mainMenu(currentUser);
                }
                else if(withdrawChoice == "4"){
                    cout << "Thank you have a good day." << endl;
                }
            }
            else if(cardType == '2'){ // Credit card
                if (withdrawChoice == "1") {
                    withdrawFee = 20*0.05;
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - (20 + withdrawFee));
                    cout << "$20.00 has been withdrawn from your checkings account." << endl;
                    cout << "Withdraw Fee: $" << withdrawFee << endl;
                }
                else if (withdrawChoice == "2") {
                    withdrawFee = 40*0.05;
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - (40 + withdrawFee));
                    cout << "$40.00 has been withdrawn from your checkings account." << endl;
                    cout << "Withdraw Fee: $" << withdrawFee << endl;

                }
                else if (withdrawChoice == "3") {
                    mainMenu(currentUser);
                }
                else if(withdrawChoice == "4"){
                    cout << "Thank you have a good day." << endl;
                }
            }
        }
        else if (currentUser.getCheckingBalance() >= (20+(20*0.05))) { // If user has 20 dollars + withdraw fee in checking, shows fewer options
            cout << " _______________________________" << endl;
            cout << "| Choose an amount to withdraw. |" << endl;
            cout << "| [1] $20                       |" << endl;
            cout << "| [2] Main menu                 |" << endl;
            cout << "| [3] Quit                      |" << endl;
            cout << "|_______________________________|" << endl;
            getline(cin, withdrawChoice);
            while (!(withdrawChoice == "1" || withdrawChoice == "2" || withdrawChoice == "3")) {
                cout << "| Please choose a valid option. |" << endl;
                cout << "|_______________________________|" << endl;
                getline(cin, withdrawChoice);
            }
            if(cardType == '1'){ // Debit card
                if (withdrawChoice == "1") {
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 20);
                    cout << "$20.00 has been withdrawn from your checkings account." << endl;
                }
                else if (withdrawChoice == "2") {
                    mainMenu(currentUser);
                }
                else if(withdrawChoice == "3"){
                    cout << "Thank you have a good day." << endl;
                }
            }
            else if(cardType == '2'){ // Credit card
                if (withdrawChoice == "1") {
                    withdrawFee = 20*0.05;
                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - (20 + withdrawFee));
                    cout << "$20.00 has been withdrawn from your checkings account." << endl;
                    cout << "Withdraw Fee: $" << withdrawFee << endl;
                }
                else if (withdrawChoice == "2") {
                    mainMenu(currentUser);
                }
                else if(withdrawChoice == "3"){
                    cout << "Thank you have a good day." << endl;
                }
            }
        }
        else { // If user has less than 20 dollars + withdraw fee in checking, shows main menu or quit option
            cout << " __________________________________________________" << endl;
            cout << "|                                                  |" << endl;
            cout << "| Not enough money in checkings to quick withdraw. |" << endl;
            cout << "| [1] Main menu                                    |" << endl;
            cout << "| [2] Quit                                         |" << endl;
            cout << "|__________________________________________________|" << endl;
            getline(cin, withdrawChoice);
            while (!(withdrawChoice == "1" || withdrawChoice == "2")) {
                cout << "| Please choose a valid option.                      |" << endl;
                cout << "|____________________________________________________|" << endl;
                getline(cin, withdrawChoice);
            }
            if (withdrawChoice == "1") {
                mainMenu(currentUser);
            }
            else if(withdrawChoice == "2"){
                cout << "Thank you have a good day." << endl;
            }
        }
    }
    else if (splashChoice == "2") {
        mainMenu(currentUser);
    }
    else if (splashChoice == "3") {
        cout << "Thank you, have a good day." << endl;
    }
    saveData(currentUser); // Updates users data
}

void registerUser() { //Creating a new user account
    string newUser_Name;
    int newUser_PIN;
    int userCount = 1;
    cout << "Enter your full name: ";
    getline(cin, newUser_Name);
    cout << "Create your pin: ";
    cin >> newUser_PIN;
    while (newUser_PIN > 9999 || newUser_PIN <= 999) { // Makes sure pin is valid
        cout << "Invalid pin." << endl;
        cout << "Create your pin: ";
        cin >> newUser_PIN;
    }
    ifstream atmData("atmData.txt"); // Opens saved data
    if (atmData.is_open())
    {
        string line;
        while (getline(atmData, line)) { // Counts each line in the file until the end starting from userCount = 1, the number of lines = number of current users, so userCount becomes new users ID
            userCount++;
        }
        atmData.close();
    }
    atmUser newUser(newUser_Name, newUser_PIN, 0.0, 0.0, userCount);
    cout << "Your ID is: " << userCount << endl;
    cout << "Remember it as you will need it to login." << endl;
    ofstream storeData("atmData.txt", ios::app);
    if (storeData.is_open()) { // Store data by NAME |PIN CHECKINGBALANCE SAVINGBALANCE USERID
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
    if (atmData.is_open()) // Opens saved data
    {
        while (getline(atmData, line))
        {
            stringstream currentline(line); // Creats a string stream called currentline, that copies the current line (line) in file so we can read from it
            getline(currentline, storedName, '|'); // Reads until "|" character to get name, then reads in rest of data into corresponding variables
            currentline >> storedPIN >> storedChecking >> storedSaving >> storedID;
            if (userName == storedName && userPIN == storedPIN) // If entered name and pin match a stored name and pin, program then checks ID in case two users have same name
            {
                if (userID == storedID) {
                    cout << "Login successful." << endl;
                    atmUser currentUser(storedName, storedPIN, storedChecking, storedSaving, storedID);
                    splashMenu(currentUser);
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
    string startChoice = "1";
    cout << "_________________________________________" << endl;
    cout << "|                                       |" << endl;
    cout << "|        What do you want to do?        |" << endl;
    cout << "| [1] Login                             |" << endl;
    cout << "| [2] Register                          |" << endl;
    cout << "| [3] Quit                              |" << endl;
    cout << "|_______________________________________|" << endl;
    getline(cin, startChoice);
    while (startChoice > "3" || startChoice < "1") {
        cout << "| Please choose a valid choice.         |" << endl;
        cout << "|_______________________________________|" << endl;
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
