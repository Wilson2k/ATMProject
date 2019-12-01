//
//  atmUser.hpp
//  ATMProject
//
//  Created by Wilson Chen on 11/26/19.
//  Copyright © 2019 Wilson Chen. All rights reserved.
//

#ifndef atmUser_hpp
#define atmUser_hpp

#include <stdio.h>
#include <string>

class atmUser{
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
    
    atmUser(const atmUser &obj);
    
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

#endif /* atmUser_hpp */
