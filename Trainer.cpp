//
// Created by Bobby Paletta on 10/3/24.
//

#include "Trainer.h"


Trainer::Trainer(){
    fName = "Ash";
    lName = "Ketchum";
}
Trainer::Trainer(string fName, string lName){
    this->fName = fName;
    this->lName = lName;
}
string Trainer::getfName() {
    return fName;
}

string Trainer::getlName() {
    return lName;
}

void Trainer::addPokemon(Pokemon teammate){
    team.push_back(teammate);
}

Pokemon Trainer::getPokemon(int index){
    return team[index];
}

int Trainer::getSize(){
    return team.size();
}
