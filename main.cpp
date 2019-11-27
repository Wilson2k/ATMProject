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
#include "atmUser.hpp"
using namespace std;

void displayMainmenu(){ // Display the main menu after login/creating account
    cout << "What would you like to do?" << endl;
    cout << "[1] Withdraw" << endl;
    cout << "[2] Deposit" << endl;
    cout << "[3] Check Balance" << endl;
    cout << "[4] Transfer or make payments" << endl;
    cout << "[5] Other Options" << endl;
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

void mainMenu(atmUser currentUser){
    int userChoice, withdrawChoice;
    char userResponse = 'Y';
    float transactionAmount = 0;
    displayMainmenu();
    cin >> userChoice;
    while(not(userChoice > 0 && userChoice < 6)){
        cout << "Please choose an option" << endl;
        cin >> userChoice;
    }
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
                        }
                        break;
                    case 2:
                        if(20 > currentUser.getDebitBalance()){
                             cout << "Not enough money to withdraw." << endl;
                        }
                        else{
                            currentUser.setDebitBalance(currentUser.getDebitBalance() - 40);
                        }
                        break;
                    case 3:
                        if(20 > currentUser.getDebitBalance()){
                             cout << "Not enough money to withdraw." << endl;
                        }
                        else{
                            currentUser.setDebitBalance(currentUser.getDebitBalance() - 60);
                        }
                        break;
                    case 4:
                        if(20 > currentUser.getDebitBalance()){
                             cout << "Not enough money to withdraw." << endl;
                        }
                        else{
                            currentUser.setDebitBalance(currentUser.getDebitBalance() - 80);
                        }
                        break;
                    case 5:
                        if(20 > currentUser.getDebitBalance()){
                             cout << "Not enough money to withdraw." << endl;
                        }
                        else{
                            currentUser.setDebitBalance(currentUser.getDebitBalance() - 100);
                        }
                        break;
                    case 6:
                        if(20 > currentUser.getDebitBalance()){
                             cout << "Not enough money to withdraw." << endl;
                        }
                        else{
                            currentUser.setDebitBalance(currentUser.getDebitBalance() - 200);
                        }
                        break;
                    case 7:
                        if(20 > currentUser.getDebitBalance()){
                             cout << "Not enough money to withdraw." << endl;
                        }
                        else{
                            currentUser.setDebitBalance(currentUser.getDebitBalance() - 300);
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
                currentUser.setDebitBalance(currentUser.getDebitBalance() + transactionAmount);
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
                string addChoice = "0";
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
        }
    }
}

//void saveData(atmUser currentUser){
//    ofstream outFile("temp.txt");
//    ifstream readFile("atmData.txt");
//    string readout;
//    string search;
//    string replace;
//    while(getline(readFile,readout)){
//      if(readout == search){
//        outFile << replace;
//      }
//      else {
//        outFile << readout;
//      }
//    }
//}

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
    ofstream storedata ("atmData.txt", ios::app);
    if(storedata.is_open()){
        storedata << newUser.getName() << "|" << newUser.getPIN() << " " << newUser.getDebitBalance() << " " << newUser.getCreditBalance() << " " << newUser.getID() << endl;
        storedata.close();
    }
};

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
    getline(cin, startChoice);
    while(startChoice > "2" || startChoice < "1"){
        cout << "Please choose a valid choice." << endl;
        getline(cin, startChoice);
    }
    if(startChoice == "1"){
        login();
    }
    if(startChoice == "2"){
        registerUser();
    }
}

int main() {
    startMenu();
    return 0;
}