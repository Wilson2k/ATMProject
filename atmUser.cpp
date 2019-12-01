//
//  atmUser.cpp
//  ATMProject
//
//  Created by Wilson Chen on 11/26/19.
//  Copyright © 2019 Wilson Chen. All rights reserved.
//

#include "atmUser.hpp"

atmUser::atmUser(){
    atmUser("No Name", 1234, 0.0, 0.0, 0);
};
atmUser::atmUser(std::string NAME){
    atmUser(NAME, 1234, 0.0, 0.0, 0);
};
atmUser::atmUser(std::string NAME, int PIN){
    atmUser(NAME, PIN, 0.0, 0.0, 0);
};
atmUser::atmUser(std::string NAME, int PIN, float CBALANCE){
    atmUser(NAME, PIN, CBALANCE, 0.0, 0);
};
atmUser::atmUser(std::string NAME, int PIN, float CBALANCE, float SBALANCE){
    atmUser(NAME, PIN, CBALANCE, SBALANCE, 0);
};
atmUser::atmUser(std::string NAME, int PIN, float CBALANCE, float SBALANCE, int ID){
    atmUser_Name = NAME;
    atmUser_PIN = PIN;
    atmUser_CBalance = CBALANCE;
    atmUser_SBalance = SBALANCE;
    atmUser_ID = ID;
    ObjCounter++;
};

atmUser::atmUser(const atmUser &obj){
    atmUser_Name = obj.atmUser_Name;
    atmUser_PIN = obj.atmUser_PIN;
    atmUser_ID = obj.atmUser_ID;
    atmUser_SBalance = obj.atmUser_SBalance;
    atmUser_CBalance = obj.atmUser_CBalance;
};

int atmUser::getID(){
    return atmUser_ID;
};
void atmUser::setID(int ID){
    atmUser_ID = ID;
};

int atmUser::getPIN(){
    return atmUser_PIN;
};
void atmUser::setPIN(int PIN){
    atmUser_PIN = PIN;
};

std::string atmUser::getName(){
    return atmUser_Name;
};
void atmUser::setName(std::string NAME){
    atmUser_Name = NAME;
};

float atmUser::getSavingBalance(){
    return atmUser_SBalance;
};
void atmUser::setSavingBalance(float BALANCE){
    atmUser_SBalance = BALANCE;
};

float atmUser::getCheckingBalance(){
    return atmUser_CBalance;
};
void atmUser::setCheckingBalance(float BALANCE){
    atmUser_CBalance = BALANCE;
};

atmUser::~atmUser(){
    ObjCounter--;
};

int atmUser::ObjCount(){
    return ObjCounter;
};
