//
// Created by Bobby Paletta on 10/3/24.
//
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "string.h"
#include "Pokemon.h"
using std::string, std::vector, std::ifstream, std::cout, std::endl, std::ostream, std::setw, std:: right, std::left;

// Default constructor that gives values to each variable
    Pokemon::Pokemon() {
        id = 0;
        name = "Pokemon";
        typeOne = "Poke";
        typeTwo = "Mon";
        total = 100;
        hp = 100;
        attack = 50;
        defense = 50;
        spAttack = 55;
        spDefense = 55;
        speed = 10;
        generation = 0;
        legendary = 0;
        percentage_male = "1.0";
        capture_rate = 0;
        classification = "Mon";
    }

/*
 * Constructor that includes all the variables and sets the respective ones equal
 * to eachother
 */
    Pokemon::Pokemon(int id, string name, string typeOne, string typeTwo, int total, int hp,
            int attack, int defense, int spAttack, int spDefense, int speed,
            int generation, int legendary, string percentage_male, double capture_rate,
            string classification) {
        this->id = id;
        this->name = name;
        this->typeOne = typeOne;
        this->typeTwo = typeTwo;
        this->total = total;
        this->hp = hp;
        this->attack = attack;
        this->defense = defense;
        this->spAttack = spAttack;
        this->spDefense = spDefense;
        this->speed = speed;
        this->generation = generation;
        this->legendary = legendary;
        this->percentage_male = percentage_male;
        this->capture_rate = capture_rate;
        this->classification = classification;
    }
// Getters
    int Pokemon::getID() const {
        return id;
    }

    string Pokemon::getName() const {
        return name;
    }

    string Pokemon::getTypeOne() const {
        return typeOne;
    }

    string Pokemon::getTypeTwo() const {
        return typeTwo;
    }

    int Pokemon::getTotal() const {
        return total;
    }

    int Pokemon::getHP() const {
        return hp;
    }

    int Pokemon::getAttack() const {
        return attack;
    }

    int Pokemon::getDefense() const {
        return defense;
    }

    int Pokemon::getSpAttack() const {
        return spAttack;
    }

    int Pokemon::getSpDefense() const {
        return spDefense;
    }

    int Pokemon::getSpeed() const {
        return speed;
    }
    int Pokemon::getGeneration() const {
        return generation;
    }
    int Pokemon::getLegendary() const {
        return legendary;
    }
    string Pokemon::getClassifictaion() const {
        return classification;
    }

    string Pokemon::getPercentageMale() const{
        return percentage_male;
    }

    double Pokemon::getCaptureRate(){
        return capture_rate;
    }

// Setters
    void Pokemon::setID(int id) {
        this->id = id;
    }

    void Pokemon::setName(string name) {
        this->name = name;
    }

    void Pokemon::setTypeOne(string typeOne) {
        this->typeOne = typeOne;
    }

    void Pokemon::setTypeTwo(string typeTwo) {
        this->typeTwo = typeTwo;
    }

    void Pokemon::setTotal(int total) {
        this->total = total;
    }

    void Pokemon::setHP(int hp) {
        this->hp = hp;
    }

    void Pokemon::setAttack(int attack) {
        this->attack = attack;
    }

    void Pokemon::setDefense(int defense) {
        this->defense = defense;
    }

    void Pokemon::setSpAttack(int spAttack) {
        this->spAttack = spAttack;
    }

    void Pokemon::setSpDefense(int spDefense) {
        this->spDefense = spDefense;
    }

    void Pokemon::setSpeed(int speed) {
        this->speed = speed;
    }

    void Pokemon::setGeneration(int generation) {
        this->generation = generation;
    }

    void Pokemon::setLegendary(int legendary) {
        this->legendary = legendary;
    }

//Overloaded operators

    ostream& operator << (ostream& outs, const Pokemon& lec) {
//format the data
        outs << left << setw(5) << lec.id;
        outs << left << setw(10) << lec.name;
        outs << right << setw(35) << "Generation " << lec.generation << endl;
        if (lec.typeTwo == ""){
            outs << setw(12) << lec.name << " is a " << lec.typeOne << " type pokemon." << endl;
        }
        else {
            outs << setw(12) << lec.name << " is a " << lec.typeOne <<
                 " and " << lec.typeTwo << " type pokemon." << endl;
        }

        outs << setw(20) << "Here are some of " << lec.name << "'s statistics!" << endl;
        outs << setw(23) << "HP: " << lec.hp << endl;
        outs <<  setw(18) << "Attack: " << setw(0) << lec.attack << " Special Attack: " << lec.spAttack << endl;
        outs << setw(18) << "Defense: " << setw(0) << lec.defense << " Special Defense: " << lec.spDefense << endl;

        outs << setw(25) << "Speed: "<< lec.speed << endl;
        if(lec.legendary == 0){
            outs << setw(18) << lec.name << " is not a legendary pokemon." << endl;
        }
        else{
            outs << setw(16) << lec.name << " is a legendary pokemon." << endl;
        }
        return outs;

    }

     bool operator== (const Pokemon& lhs, const Pokemon& rhs) {
//if the totals of two pokemon are the same than they are equal
        return lhs.name == rhs.name;
    }

    bool operator!= (const Pokemon& lhs, const Pokemon& rhs) {
    //if the totals of two pokemon are the same than they are equal
        return lhs.name != rhs.name;
    }
    bool operator> (const Pokemon& lhs, const Pokemon& rhs) {
//if the total of a pokemon is greater than another it is greater
        return lhs.total > rhs.total;
    }

    bool operator< (const Pokemon& lhs, const Pokemon& rhs) {
//if the total of a pokemon is less than another it is less
        return lhs.total < rhs.total;
    }

    Pokemon operator-- (vector<Pokemon>& pokedex, int id) {
//given a pokedex and an id of a pokemon, get the pokemon with an id one less than that pokemon
        int newId = id - 1;
        Pokemon select = pokedex[newId];
        return select;
    }

    Pokemon operator++ (vector<Pokemon>& pokedex, int id) {
//given a pokedex and an id of a pokemon, get the pokemon with an id one more than that pokemon
        int newId = id + 1;
        Pokemon select = pokedex[newId];
        return select;
    }


/*Function that checks if the name of a pokemon exists in the pokedex
 * PARAMS: vector<pokemon> pokedex, string selected name
 * RETURNS: boolean representing whether the selected name is in the pokedex
 * */
bool checkName(vector<Pokemon> pokedex, string select){
    string name;
    for (int i = 0; i < pokedex.size(); i++){
        name = pokedex[i].getName();
        if (name == select){
            return true;
        }
    }
    return false;
}
/*Function to get a pokemon object given a pokedex and the name of said pokemon
 * PARAMS: vector<pokemon> pokedex, string name
 * RETURNS: Pokemon object
 * */
Pokemon getPokemon(vector<Pokemon> pokedex, string name) {
    for (int i = 0; i < pokedex.size(); i++) {
        if (pokedex[i].getName() == name) {
            return pokedex[i];
        }
    }
    return Pokemon();
}