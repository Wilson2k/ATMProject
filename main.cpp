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

void displayAccountChoice(){
    cout << "Which account are you using?" << endl;
    cout << "[1] Checkings Account" << endl;
    cout << "[2] Savings Account" << endl;
}

void displayMainmenu(){ // Display the main menu after login/creating account
    cout << "What would you like to do?" << endl;
    cout << "[1] Withdraw" << endl;
    cout << "[2] Deposit" << endl;
    cout << "[3] Check Balance" << endl;
    cout << "[4] Transfer or make payments" << endl;
    cout << "[5] Other Options" << endl;
    cout << "[6] Quit" << endl;
}

void displayWithdrawmenu(){ //Display withdraw menu when user chooses (1) Withdraw
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

void additonalOptiions(){
    cout << "[1] Change PIN" << endl;
    cout << "[2] Nearby ATM Locations" << endl;
}

void displayNearby(){ // Displays nearby locations for [5] Other options
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

void writeReceipt(){ // Call to ask user if they want receipt, and write receipt
    string line, receiptChoice;
    cout << "Would you like a receipt? (Y/N)" << endl;
    cin >> receiptChoice;
    while(!(receiptChoice == "Y" || receiptChoice == "y" || receiptChoice == "N" || receiptChoice == "n")){
        cout << "Please choose an option." << endl;
        cin >> receiptChoice;
    }
    if(receiptChoice == "Y" || receiptChoice == "y"){
        ifstream writeReceipt("atmReceipt.txt");
        if(writeReceipt.is_open()){
            cout << "-----------------------------------------" << endl;
            while(getline(writeReceipt, line)){
                cout << line << endl;
            }
            cout << "-----------------------------------------" << endl;
        }
    }
    else{
        cout << "Thank you, have a good day." << endl;
    }
}

void saveData(atmUser currentUser){ // Updates stored data
    ifstream readData("atmData.txt");
    ofstream saveData("temp.txt");
    if (readData.is_open())
    {
        int counter = 1;
        string line;
        while (getline(readData, line)){
            if(counter == currentUser.getID()){
                saveData << currentUser.getName() << "|" << currentUser.getPIN() << " " << currentUser.getCheckingBalance() << " " << currentUser.getSavingBalance() << " " << currentUser.getID() << endl;
                counter++;
            }
            else{
                saveData << line << endl;
                counter++;
            }
        }
        readData.close();
    }
    remove("atmData.txt");
    rename("temp.txt","atmData.txt");
}

atmUser getUser(string userName, int userID){ // returns an atmUser object with user data if it is found, if  no matching user data found then returns empty atmUser object
    string storedName, line;
    int storedPIN, storedID;
    float storedSaving, storedChecking;
    atmUser targetUser;
    ifstream atmData ("atmData.txt");
    if (atmData.is_open())
    {
        while (getline(atmData, line))
        {
            stringstream currentline(line);
            getline(currentline, storedName, '|');
            currentline >> storedPIN >> storedChecking >> storedSaving >> storedID;
            if (userName == storedName)
            {
                if(userID == storedID){
                    targetUser.setID(storedID);
                    targetUser.setName(storedName);
                    targetUser.setPIN(storedPIN);
                    targetUser.setCheckingBalance(storedChecking);
                    targetUser.setSavingBalance(storedSaving);
                    break;
                }
                else if(atmData.peek() == EOF){
                    cout << "Error grabbing user data." << endl;
                    break;
                }
            }
            else if(atmData.peek() == EOF){
                cout << "Error grabbing user data." << endl;
                break;
            }
        }
        atmData.close();
    }
    return targetUser;
}

bool userExist(string userName, int userID){ // Checks if user exists in saved data
    bool userStatus = false;
    string storedName, line;
    int storedPIN, storedID;
    float storedDebit, storedCredit;
    ifstream atmData ("atmData.txt");
    if (atmData.is_open())
    {
        while (getline(atmData, line))
        {
            stringstream currentline(line);
            getline(currentline, storedName, '|');
            currentline >> storedPIN >> storedDebit >> storedCredit >> storedID;
            if (userName == storedName)
            {
                if(userID == storedID){
                    userStatus = true;
                    break;
                }
                else if(atmData.peek() == EOF){
                    cout << "Sorry, we couldn't find that user." << endl;
                    break;
                }
            }
            else if(atmData.peek() == EOF){
                cout << "Sorry, we couldn't find that user." << endl;
                break;
            }
        }
        atmData.close();
    }
    return userStatus;
}

void transferMoney(atmUser &currentUser, atmUser &transferUser, float transferAmount, char account){ // Transfer money between two atmUser objects
    if(account == '1'){
        currentUser.setCheckingBalance(currentUser.getCheckingBalance() - transferAmount);
        transferUser.setCheckingBalance(transferUser.getCheckingBalance() + transferAmount);
        cout << "You successfully transferred $" << transferAmount << " to " << transferUser.getName() << " from checkings." << endl;
    }
    else if(account == '2'){
        currentUser.setSavingBalance(currentUser.getSavingBalance() - transferAmount);
        transferUser.setCheckingBalance(transferUser.getCheckingBalance() + transferAmount);
        cout << "You successfully transferred $" << transferAmount << " to " << transferUser.getName() << " from savings." << endl;
    }
    saveData(currentUser);
    saveData(transferUser);
}

char checkWithdrawChoice(char withdrawChoice){ // Checks that withdraw menu choice is valid
    while(!(withdrawChoice == '1' || withdrawChoice == '2' || withdrawChoice == '3' || withdrawChoice == '4' || withdrawChoice == '5' || withdrawChoice == '6' || withdrawChoice == '7' || withdrawChoice == '8')){
        cout << "Please choose an option" << endl;
        cin >> withdrawChoice;
    }
    return withdrawChoice;
}

char checkUserResponse(char userResponse){ // Checks response to "Would you like another transaction? is valid"
    while(!(userResponse == 'Y' || userResponse == 'y' || userResponse == 'N' || userResponse == 'n')){
        cout << "Please choose an option." << endl;
        cin >> userResponse;
    }
    return userResponse;
}

char checkMainChoice(char userChoice){ // Checks that main menu choice is valid
    while(!(userChoice == '1' || userChoice == '2' || userChoice == '3' || userChoice == '4' || userChoice == '5' || userChoice == '6')){
        cout << "Please choose an option" << endl;
        cin >> userChoice;
    }
    return userChoice;
}

char checkAccountChoice(char accountChoice){ // Checks response to checkings or savings menu
    while(!(accountChoice == '1' || accountChoice == '2')){
        cout << "Please choose an option." << endl;
        cin >> accountChoice;
    }
    return accountChoice;
}

char checkTransferChoice(char transferChoice){ // Checks response to transfer menu
    while(!(transferChoice == '1' || transferChoice == '2')){
        cout << "Please choose an option." << endl;
        cin >> transferChoice;
    }
    return transferChoice;
}

void mainMenu(atmUser currentUser){
    char userResponse = 'Y';
    char userChoice = '0';
    char withdrawChoice = '0';
    char accountChoice = '0';
    char transferOrPayment = '0';
    char transferChoice = '0';
    float transactionAmount = 0;
    string transferRecipient = "";
    int transferID = 0;
    float transferAmount = 0;
    string addChoice;
    displayMainmenu();
    cin >> userChoice;
    userChoice = checkMainChoice(userChoice);
    ifstream atmReceipt ("atmReceipt.txt", ios::trunc);
    atmReceipt.close();
    ofstream storeReceipt ("atmReceipt.txt");
    if(storeReceipt.is_open()){
        storeReceipt << "Name: " << currentUser.getName() << endl;
        while(userResponse == 'Y' || userResponse == 'y'){
            switch (userChoice) {
                case '1': // [1] Withdraw option
                    displayAccountChoice();
                    cin >>  accountChoice;
                    accountChoice = checkAccountChoice(accountChoice);
                    if(accountChoice == '1'){
                        displayWithdrawmenu();
                        cin >> withdrawChoice;
                        switch (withdrawChoice) {
                            case '1':
                                if(20 > currentUser.getCheckingBalance()){
                                     cout << "Not enough money to withdraw." << endl;
                                }
                                else{
                                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 20);
                                    cout << "You successfully withdrew $20.00" << endl;
                                    storeReceipt << "Withdraw: $20" << endl;
                                }
                                break;
                            case '2':
                                if(20 > currentUser.getCheckingBalance()){
                                     cout << "Not enough money to withdraw." << endl;
                                }
                                else{
                                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 40);
                                    cout << "You successfully withdrew $40.00" << endl;
                                    storeReceipt << "Withdraw: $40" << endl;
                                }
                                break;
                            case '3':
                                if(20 > currentUser.getCheckingBalance()){
                                     cout << "Not enough money to withdraw." << endl;
                                }
                                else{
                                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 60);
                                    cout << "You successfully withdrew $60.00" << endl;
                                    storeReceipt << "Withdraw: $60" << endl;
                                }
                                break;
                            case '4':
                                if(20 > currentUser.getCheckingBalance()){
                                     cout << "Not enough money to withdraw." << endl;
                                }
                                else{
                                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 80);
                                    cout << "You successfully withdrew $80.00" << endl;
                                    storeReceipt << "Withdraw: $80" << endl;
                                }
                                break;
                            case '5':
                                if(20 > currentUser.getCheckingBalance()){
                                     cout << "Not enough money to withdraw." << endl;
                                }
                                else{
                                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 100);
                                    cout << "You successfully withdrew $100.00" << endl;
                                    storeReceipt << "Withdraw: $100" << endl;
                                }
                                break;
                            case '6':
                                if(20 > currentUser.getCheckingBalance()){
                                     cout << "Not enough money to withdraw." << endl;
                                }
                                else{
                                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 200);
                                    cout << "You successfully withdrew $200.00" << endl;
                                    storeReceipt << "Withdraw: $200" << endl;
                                }
                                break;
                            case '7':
                                if(20 > currentUser.getCheckingBalance()){
                                     cout << "Not enough money to withdraw." << endl;
                                }
                                else{
                                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - 300);
                                    cout << "You successfully withdrew $300.00" << endl;
                                    storeReceipt << "Withdraw: $300" << endl;
                                }
                                break;
                            case '8':
                                cout << "Enter an amount to withdraw." << endl;
                                cin >> transactionAmount;
                                if(transactionAmount > currentUser.getCheckingBalance()){
                                    cout << "Not enough money to withdraw." << endl;
                                }
                                else{
                                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - transactionAmount);
                                    cout << "You successfully withdrew $" << transactionAmount << endl;
                                    storeReceipt << "Withdraw: $" << transactionAmount << endl;
                                }
                                break;
                            default:
                                withdrawChoice = checkWithdrawChoice(withdrawChoice);
                        }
                    }
                    else if(accountChoice == '2'){
                        displayWithdrawmenu();
                        cin >> withdrawChoice;
                        switch (withdrawChoice) {
                            case '1':
                                if(20 > currentUser.getSavingBalance()){
                                     cout << "Not enough money to withdraw." << endl;
                                }
                                else{
                                    currentUser.setSavingBalance(currentUser.getSavingBalance() - 20);
                                    cout << "You successfully withdrew $20.00" << endl;
                                    storeReceipt << "Withdraw: $20" << endl;
                                }
                                break;
                            case '2':
                                if(20 > currentUser.getSavingBalance()){
                                     cout << "Not enough money to withdraw." << endl;
                                }
                                else{
                                    currentUser.setSavingBalance(currentUser.getSavingBalance() - 40);
                                    cout << "You successfully withdrew $40.00" << endl;
                                    storeReceipt << "Withdraw: $40" << endl;
                                }
                                break;
                            case '3':
                                if(20 > currentUser.getSavingBalance()){
                                     cout << "Not enough money to withdraw." << endl;
                                }
                                else{
                                    currentUser.setSavingBalance(currentUser.getSavingBalance() - 60);
                                    cout << "You successfully withdrew $60.00" << endl;
                                    storeReceipt << "Withdraw: $60" << endl;
                                }
                                break;
                            case '4':
                                if(20 > currentUser.getSavingBalance()){
                                     cout << "Not enough money to withdraw." << endl;
                                }
                                else{
                                    currentUser.setSavingBalance(currentUser.getSavingBalance() - 80);
                                    cout << "You successfully withdrew $80.00" << endl;
                                    storeReceipt << "Withdraw: $80" << endl;
                                }
                                break;
                            case '5':
                                if(20 > currentUser.getSavingBalance()){
                                     cout << "Not enough money to withdraw." << endl;
                                }
                                else{
                                    currentUser.setSavingBalance(currentUser.getSavingBalance() - 100);
                                    cout << "You successfully withdrew $100.00" << endl;
                                    storeReceipt << "Withdraw: $100" << endl;
                                }
                                break;
                            case '6':
                                if(20 > currentUser.getSavingBalance()){
                                     cout << "Not enough money to withdraw." << endl;
                                }
                                else{
                                    currentUser.setSavingBalance(currentUser.getSavingBalance() - 200);
                                    cout << "You successfully withdrew $200.00" << endl;
                                    storeReceipt << "Withdraw: $200" << endl;
                                }
                                break;
                            case '7':
                                if(20 > currentUser.getSavingBalance()){
                                     cout << "Not enough money to withdraw." << endl;
                                }
                                else{
                                    currentUser.setSavingBalance(currentUser.getSavingBalance() - 300);
                                    cout << "You successfully withdrew $300.00" << endl;
                                    storeReceipt << "Withdraw: $300" << endl;
                                }
                                break;
                            case '8':
                                cout << "Enter an amount to withdraw." << endl;
                                cin >> transactionAmount;
                                if(transactionAmount > currentUser.getSavingBalance()){
                                    cout << "Not enough money to withdraw." << endl;
                                }
                                else{
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
                    cin >> userResponse;
                    userResponse = checkUserResponse(userResponse);
                    if(userResponse == 'Y' || userResponse == 'y'){
                        displayMainmenu();
                        cin >> userChoice;
                        userChoice = checkMainChoice(userChoice);
                    }
                    break;
                case '2': // [2] Deposit option
                    displayAccountChoice();
                    cin >>  accountChoice;
                    accountChoice = checkAccountChoice(accountChoice);
                    if(accountChoice  == '1'){
                        cout << "Enter an amount to deposit: ";
                        cin >> transactionAmount;
                        while(transactionAmount < 0){
                            cout << "Please deposit a valid amount." << endl;
                            cin >> transactionAmount;
                        }
                        currentUser.setCheckingBalance(currentUser.getCheckingBalance() + transactionAmount);
                        storeReceipt << "Deposit to checking: $" << transactionAmount << endl;
                        cout << "You successfully deposited $" << transactionAmount << " to checkings." << endl;
                    }
                    else if(accountChoice == '2'){
                        cout << "Enter an amount to deposit: ";
                        cin >> transactionAmount;
                        while(transactionAmount < 0){
                            cout << "Please deposit a valid amount." << endl;
                            cin >> transactionAmount;
                        }
                        currentUser.setSavingBalance(currentUser.getSavingBalance() + transactionAmount);
                        storeReceipt << "Deposit to saving: $" << transactionAmount << endl;
                        cout << "You successfully deposited $" << transactionAmount << " to savings." << endl;
                    }
                    cout << "Would you like another transaction? (Y/N)" << endl;
                    cin >> userResponse;
                    userResponse = checkUserResponse(userResponse);
                    if(userResponse == 'Y' || userResponse == 'y'){
                        displayMainmenu();
                        cin >> userChoice;
                        userChoice = checkMainChoice(userChoice);
                    }
                    break;
                case '3': // [3] Check Balance
                    displayAccountChoice();
                    cin >> accountChoice;
                    accountChoice = checkAccountChoice(accountChoice);
                    if(accountChoice == '1'){
                        cout << "Your current checking balance is: " << "$" << currentUser.getCheckingBalance() << endl;
                    }
                    else if(accountChoice == '2'){
                        cout << "Your current saving balance is: " << "$" << currentUser.getSavingBalance() << endl;
                    }
                    cout << "Would you like another transaction? (Y/N)" << endl;
                    cin >> userResponse;
                    userResponse = checkUserResponse(userResponse);
                    if(userResponse == 'Y' || userResponse == 'y'){
                        displayMainmenu();
                        cin >> userChoice;
                        userChoice = checkMainChoice(userChoice);
                    }
                    break;
                case '4': // [4] Transfer or make payments
                    displayAccountChoice();
                    cin >> accountChoice;
                    accountChoice = checkAccountChoice(accountChoice);
                    if(accountChoice == '1'){
                        cout << "[1] Transfer money" << endl;
                        cout << "[2] Make Payments" << endl;
                        cin >> transferOrPayment;
                        transferOrPayment = checkTransferChoice(transferOrPayment);
                        if(transferOrPayment == '1'){
                            cout << "[1] Transfer to savings" << endl;
                            cout << "[2] Transfer to others" << endl;
                            cin >>  transferChoice;
                            transferChoice = checkTransferChoice(transferChoice);
                            if(transferChoice == '1'){
                                cout << "Enter transfer amount: ";
                                cin >>  transferAmount;
                                if(transferAmount <= currentUser.getCheckingBalance() && transferAmount > 0){
                                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() - transferAmount);
                                    currentUser.setSavingBalance(currentUser.getSavingBalance() + transferAmount);
                                    cout << "You successfully transferred  $" << transferAmount << " from checking to savings." << endl;
                                    storeReceipt << "Transfer from checkings to savings: $"  << transferAmount << endl;
                                }
                                else{
                                    cout << "Invalid transfer amount." << endl;
                                }
                                
                            }
                            else if(transferChoice == '2'){
                                cout << "Enter name of transfer recipient: ";
                                cin.ignore();
                                getline(cin, transferRecipient);
                                cout << "Enter recipient ID: ";
                                cin >> transferID;
                                if(userExist(transferRecipient, transferID)){
                                    cout << "Enter transfer amount: ";
                                    cin >> transferAmount;
                                    if(transferAmount <= currentUser.getCheckingBalance() && transferAmount > 0){
                                        atmUser transferUser(getUser(transferRecipient, transferID)); // GetUser grabs transfer recipient data, and then we create a new atmUser object that is a clone of what GetUser grabs
                                        transferMoney(currentUser, transferUser , transferAmount, accountChoice);
                                        storeReceipt << "Transfer to " << transferUser.getName() << " from checking: $" << transferAmount << endl;
                                    }
                                    else{
                                        cout << "Invalid transfer amount." << endl;
                                    }
                                }
                            }
                        }
                        else if(transferOrPayment == '2'){
                            
                        }
                    }
                    else if(accountChoice == '2'){
                        cout << "[1] Transfer money" << endl;
                        cout << "[2] Make Payments" << endl;
                        cin >> transferOrPayment;
                        transferOrPayment = checkTransferChoice(transferOrPayment);
                        if(transferOrPayment == '1'){
                            cout << "[1] Transfer to checking" << endl;
                            cout << "[2] Transfer to others" << endl;
                            cin >>  transferChoice;
                            transferChoice = checkTransferChoice(transferChoice);
                            if(transferChoice == '1'){
                                cout << "Enter transfer amount: ";
                                cin >>  transferAmount;
                                if(transferAmount <= currentUser.getSavingBalance() && transferAmount > 0){
                                    currentUser.setSavingBalance(currentUser.getSavingBalance() - transferAmount);
                                    currentUser.setCheckingBalance(currentUser.getCheckingBalance() + transferAmount);
                                    cout << "You successfully transferred  $" << transferAmount << " from savings to checking." << endl;
                                    storeReceipt << "Transfer from savings to checkings: $"  << transferAmount << endl;
                                }
                                else{
                                    cout << "Invalid transfer amount." << endl;
                                }
                                
                            }
                            else if(transferChoice == '2'){
                                cout << "Enter name of transfer recipient: ";
                                cin.ignore();
                                getline(cin, transferRecipient);
                                cout << "Enter recipient ID: ";
                                cin >> transferID;
                                if(userExist(transferRecipient, transferID)){
                                    cout << "Enter transfer amount: ";
                                    cin >> transferAmount;
                                    if(transferAmount <= currentUser.getSavingBalance() && transferAmount > 0){
                                        atmUser transferUser(getUser(transferRecipient, transferID)); // GetUser grabs transfer recipient data, and then we create a new atmUser object that is a clone of what GetUser grabs
                                        transferMoney(currentUser, transferUser , transferAmount, accountChoice);
                                        storeReceipt << "Transfer to " << transferUser.getName() << " from saving: $" << transferAmount << endl;
                                    }
                                    else{
                                        cout << "Invalid transfer amount." << endl;
                                    }
                                }
                            }
                        }
                        else if(transferOrPayment == '2'){
                            
                        }
                    }
                    
                    cout << "Would you like another transaction? (Y/N)" << endl;
                    cin >> userResponse;
                    userResponse = checkUserResponse(userResponse);
                    if(userResponse == 'Y' || userResponse == 'y'){
                        displayMainmenu();
                        cin >> userChoice;
                        userChoice = checkMainChoice(userChoice);
                    }
                    break;
                case '5': // [5] Other Options
                    additonalOptiions();
                    addChoice = "0";
                    getline(cin, addChoice);
                    while(!(addChoice == "1" || addChoice == "2")){
                        cout << "Please enter a valid option: ";
                        cin >> addChoice;
                    }
                    if(addChoice == "1"){
                        int newPIN;
                        cout << "Choose a new PIN" << endl;
                        cin >> newPIN;
                        while(newPIN > 9999 || newPIN <= 999){
                            cout << "Invalid pin." << endl;
                            cout << "Create your pin: ";
                            cin >> newPIN;
                        }
                        currentUser.setPIN(newPIN);
                        cout << "Your new PIN: " << currentUser.getPIN() << endl;
                    }
                    else if(addChoice == "2"){
                        displayNearby();
                    }
                    cout << "Would you like another transaction? (Y/N)" << endl;
                    cin >> userResponse;
                    userResponse = checkUserResponse(userResponse);
                    if(userResponse == 'Y' || userResponse == 'y'){
                        displayMainmenu();
                        cin >> userChoice;
                        userChoice = checkMainChoice(userChoice);
                    }
                    break;
                case '6': // Quit option
                    cout << "Thank you, have a good day." << endl;
                    userResponse = '0';
                    break;
            }
        }
        storeReceipt << "Current Checking balance: $" << currentUser.getCheckingBalance() << endl;
        storeReceipt << "Current Saving balance: $" << currentUser.getSavingBalance() << endl;
        storeReceipt.close();
        if(userResponse != '0'){
            writeReceipt();
        }
        saveData(currentUser);
    }
}

void registerUser(){ //Creating a new user account
    string newUser_Name;
    int newUser_PIN;
    int userCount = 1;
    cout << "Enter your full name: ";
    getline(cin, newUser_Name);
    cout << "Create your pin: ";
    cin >> newUser_PIN;
    while(newUser_PIN > 9999 || newUser_PIN <= 999){
        cout << "Invalid pin." << endl;
        cout << "Create your pin: ";
        cin >> newUser_PIN;
    }
    ifstream atmData ("atmData.txt");
    if (atmData.is_open())
    {
        string line;
        while (getline(atmData, line)){
            userCount++;
        }
        atmData.close();
    }
    atmUser newUser(newUser_Name, newUser_PIN, 0.0, 0.0, userCount);
    cout << "Your ID is: " << userCount << endl;
    cout << "Remember it as you will need it to login." << endl;
    ofstream storeData ("atmData.txt", ios::app);
    if(storeData.is_open()){
        storeData << newUser.getName() << "|" << newUser.getPIN() << " " << newUser.getCheckingBalance() << " " << newUser.getSavingBalance() << " " << newUser.getID() << endl;
        storeData.close();
    }
}

void login(){
    string userName, storedName, line;
    int userPIN, storedPIN, userID, storedID;
    float storedChecking, storedSaving;
    cout << "Enter your full name: ";
    getline(cin, userName);
    cout << "Enter PIN: ";
    cin >> userPIN;
    cout << "Enter ID: ";
    cin >> userID;
    ifstream atmData ("atmData.txt");
    if (atmData.is_open())
    {
        while (getline(atmData, line))
        {
            stringstream currentline(line);
            getline(currentline, storedName, '|');
            currentline >> storedPIN >> storedChecking >> storedSaving >> storedID;
            if (userName == storedName && userPIN == storedPIN)
            {
                if(userID == storedID){
                    cout << "Login successful." << endl;
                    atmUser currentUser(storedName, storedPIN, storedChecking, storedSaving, storedID);
                    mainMenu(currentUser);
                    break;
                }
                else if(atmData.peek() == EOF){
                    cout << "Wrong username or password!" << endl;
                    break;
                }
            }
            else if(atmData.peek() == EOF){
                cout << "Wrong username or password!" << endl;
                break;
            }
        }
        atmData.close();
    }
}

void startMenu(){
    string startChoice = "0";
    cout << "What do you want to do?" << endl;
    cout << "[1] Login" << endl;
    cout << "[2] Register" << endl;
    cout << "[3] Quit" << endl;
    getline(cin, startChoice);
    while(startChoice > "3" || startChoice < "1"){
        cout << "Please choose a valid choice." << endl;
        getline(cin, startChoice);
    }
    if(startChoice == "1"){
        login();
    }
    if(startChoice == "2"){
        registerUser();
        cin.ignore();
        startMenu();
    }
    if(startChoice == "3"){
        cout << "Thank you, have a good day." << endl;
    }
}

int main() {
    startMenu();
    return 0;
}
