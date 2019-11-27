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
            while(getline(writeReceipt, line)){
                cout << line << endl;
            }
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
                saveData << currentUser.getName() << "|" << currentUser.getPIN() << " " << currentUser.getDebitBalance() << " " << currentUser.getCreditBalance() << " " << currentUser.getID() << endl;
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

void mainMenu(atmUser currentUser){
    int userChoice, withdrawChoice;
    char userResponse = 'Y';
    float transactionAmount = 0;
    string addChoice;
    displayMainmenu();
    cin >> userChoice;
    while(not(userChoice > 0 && userChoice < 7)){
        cout << "Please choose an option" << endl;
        cin >> userChoice;
    }
    ifstream atmReceipt ("atmReceipt.txt", ios::trunc);
    atmReceipt.close();
    ofstream storeReceipt ("atmReceipt.txt");
    if(storeReceipt.is_open()){
        storeReceipt << "Name: " << currentUser.getName() << endl;
        while(userResponse == 'Y' || userResponse == 'y'){
            switch (userChoice) {
                case 1: // (1) Withdraw option
                    displayWithdrawmenu();
                    cin >> withdrawChoice;
                    switch (withdrawChoice) {
                        case 1:
                            if(20 > currentUser.getDebitBalance()){
                                 cout << "Not enough money to withdraw." << endl;
                            }
                            else{
                                currentUser.setDebitBalance(currentUser.getDebitBalance() - 20);
                                storeReceipt << "Withdraw: $20" << endl;
                            }
                            break;
                        case 2:
                            if(20 > currentUser.getDebitBalance()){
                                 cout << "Not enough money to withdraw." << endl;
                            }
                            else{
                                currentUser.setDebitBalance(currentUser.getDebitBalance() - 40);
                                storeReceipt << "Withdraw: $40" << endl;
                            }
                            break;
                        case 3:
                            if(20 > currentUser.getDebitBalance()){
                                 cout << "Not enough money to withdraw." << endl;
                            }
                            else{
                                currentUser.setDebitBalance(currentUser.getDebitBalance() - 60);
                                storeReceipt << "Withdraw: $60" << endl;
                            }
                            break;
                        case 4:
                            if(20 > currentUser.getDebitBalance()){
                                 cout << "Not enough money to withdraw." << endl;
                            }
                            else{
                                currentUser.setDebitBalance(currentUser.getDebitBalance() - 80);
                                storeReceipt << "Withdraw: $80" << endl;
                            }
                            break;
                        case 5:
                            if(20 > currentUser.getDebitBalance()){
                                 cout << "Not enough money to withdraw." << endl;
                            }
                            else{
                                currentUser.setDebitBalance(currentUser.getDebitBalance() - 100);
                                storeReceipt << "Withdraw: $100" << endl;
                            }
                            break;
                        case 6:
                            if(20 > currentUser.getDebitBalance()){
                                 cout << "Not enough money to withdraw." << endl;
                            }
                            else{
                                currentUser.setDebitBalance(currentUser.getDebitBalance() - 200);
                                storeReceipt << "Withdraw: $200" << endl;
                            }
                            break;
                        case 7:
                            if(20 > currentUser.getDebitBalance()){
                                 cout << "Not enough money to withdraw." << endl;
                            }
                            else{
                                currentUser.setDebitBalance(currentUser.getDebitBalance() - 300);
                                storeReceipt << "Withdraw: $300" << endl;
                            }
                            break;
                        case 8:
                            cout << "Enter an amount to withdraw." << endl;
                            cin >> transactionAmount;
                            if(transactionAmount > currentUser.getDebitBalance()){
                                cout << "Not enough money to withdraw." << endl;
                            }
                            else{
                                currentUser.setDebitBalance(currentUser.getDebitBalance() - transactionAmount);
                                storeReceipt << "Withdraw: $" << transactionAmount << endl;
                            }
                            break;
                        default:
                            while(not(withdrawChoice > 0 && withdrawChoice < 9)){
                                cout << "Please choose an option" << endl;
                                cin >> withdrawChoice;
                            }
                    }
                    cout << "Would you like another transaction? (Y/N)" << endl;
                    cin >> userResponse;
                    while(!(userResponse == 'Y' || userResponse == 'y' || userResponse == 'N' || userResponse == 'n')){
                        cout << "Please choose an option." << endl;
                        cin >> userResponse;
                    }
                    if(userResponse == 'Y' || userResponse == 'y'){
                        displayMainmenu();
                        cin >> userChoice;
                    }
                    break;
                case 2: // (2) Deposit option
                    cout << "Enter an amount to deposit: ";
                    cin >> transactionAmount;
                    while(transactionAmount < 0){
                        cout << "Please deposit a valid amount." << endl;
                        cin >> transactionAmount;
                    }
                    currentUser.setDebitBalance(currentUser.getDebitBalance() + transactionAmount);
                    storeReceipt << "Deposit: $" << transactionAmount << endl;
                    cout << "Would you like another transaction? (Y/N)" << endl;
                    cin >> userResponse;
                    while(!(userResponse == 'Y' || userResponse == 'y' || userResponse == 'N' || userResponse == 'n')){
                        cout << "Please choose an option." << endl;
                        cin >> userResponse;
                    }
                    if(userResponse == 'Y' || userResponse == 'y'){
                        displayMainmenu();
                        cin >> userChoice;
                    }
                    break;
                case 3: // (3) Check Balance
                    cout << "Your current balance is: " << "$" << currentUser.getDebitBalance() << endl;
                    cout << "Would you like another transaction? (Y/N)" << endl;
                    cin >> userResponse;
                    while(!(userResponse == 'Y' || userResponse == 'y' || userResponse == 'N' || userResponse == 'n')){
                        cout << "Please choose an option." << endl;
                        cin >> userResponse;
                    }
                    if(userResponse == 'Y' || userResponse == 'y'){
                        displayMainmenu();
                        cin >> userChoice;
                    }
                    break;
                case 4: // (4) Transfer or make payments
                    

                    cout << "Would you like another transaction? (Y/N)" << endl;
                    cin >> userResponse;
                    while(!(userResponse == 'Y' || userResponse == 'y' || userResponse == 'N' || userResponse == 'n')){
                        cout << "Please choose an option." << endl;
                        cin >> userResponse;
                    }
                    if(userResponse == 'Y' || userResponse == 'y'){
                        displayMainmenu();
                        cin >> userChoice;
                    }
                    break;
                case 5: // (5) Other Options
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
                        cout << "New PIN: " << currentUser.getPIN() << endl;
                    }
                    else if(addChoice == "2"){
                        displayNearby();
                    }
                    cout << "Would you like another transaction? (Y/N)" << endl;
                    cin >> userResponse;
                    while(!(userResponse == 'Y' || userResponse == 'y' || userResponse == 'N' || userResponse == 'n')){
                        cout << "Please choose an option." << endl;
                        cin >> userResponse;
                    }
                    if(userResponse == 'Y' || userResponse == 'y'){
                        displayMainmenu();
                        cin >> userChoice;
                    }
                    break;
                case 6:
                    cout << "Thank you, have a good day." << endl;
                    userResponse = '0';
                    break;
            }
        }
        storeReceipt << "Current Balance: $" << currentUser.getDebitBalance() << endl;
        storeReceipt.close();
        if(userResponse != 0){
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
    ofstream storeData ("atmData.txt", ios::app);
    if(storeData.is_open()){
        storeData << newUser.getName() << "|" << newUser.getPIN() << " " << newUser.getDebitBalance() << " " << newUser.getCreditBalance() << " " << newUser.getID() << endl;
        storeData.close();
    }
}

void login(){
    string userName, storedName, line;
    int userPIN, storedPIN,storedID;
    float storedDebit, storedCredit;
    cout << "Enter your full name: ";
    getline(cin, userName);
    cout << "Enter PIN: ";
    cin >> userPIN;
    ifstream atmData ("atmData.txt");
    if (atmData.is_open())
    {
        while (getline(atmData, line))
        {
            stringstream currentline(line);
            getline(currentline, storedName, '|');
            currentline >> storedPIN >> storedDebit >> storedCredit >> storedID;
            if (userName == storedName && userPIN == storedPIN)
            {
                cout << "Login successful." << endl;
                atmUser currentUser(storedName, storedPIN, storedDebit, storedCredit, storedID);
                mainMenu(currentUser);
                break;
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
