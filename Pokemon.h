//
// Created by Bobby Paletta on 1/29/24.
//

#ifndef PROJECT1_POKEMON_H
#define PROJECT1_POKEMON_H
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "string.h"

using std::string, std::vector, std::ifstream, std::cout, std::endl, std::ostream, std::setw, std:: right, std::left;

class Pokemon {
//declare variables
private:
    string name, typeOne,
            typeTwo, classification;
    int id, total, hp, attack, defense, spAttack, spDefense, speed, generation;
    int legendary;
    double capture_rate;
    string percentage_male;

public:
// Default constructor that gives values to each variable
    Pokemon();

/*
 * Constructor that includes all the variables and sets the respective ones equal
 * to eachother
 */
    Pokemon(int id, string name, string typeOne, string typeTwo, int total, int hp,
            int attack, int defense, int spAttack, int spDefense, int speed,
            int generation, int legendary, string percentage_male, double capture_rate,
            string classification);

// Getters
    int getID() const;

    string getName() const;

    string getTypeOne() const;

    string getTypeTwo() const;

    int getTotal() const;

    int getHP() const;

    int getAttack() const;

    int getDefense() const;

    int getSpAttack() const;

    int getSpDefense() const;

    int getSpeed() const;

    int getGeneration() const;

    int getLegendary() const;

    string getClassifictaion() const;

    string getPercentageMale() const;

    double getCaptureRate();

// Setters
    void setID(int id);

    void setName(string name);

    void setTypeOne(string typeOne);

    void setTypeTwo(string typeTwo);

    void setTotal(int total);

    void setHP(int hp);

    void setAttack(int attack);

    void setDefense(int defense);

    void setSpAttack(int spAttack);

    void setSpDefense(int spDefense);

    void setSpeed(int speed);

    void setGeneration(int generation);

    void setLegendary(int legendary);

//Overloaded operators

    friend ostream &operator<<(ostream &outs, const Pokemon &lec);

    friend bool operator==(const Pokemon &lhs, const Pokemon &rhs);

    friend bool operator!=(const Pokemon &lhs, const Pokemon &rhs);

    friend bool operator>(const Pokemon &lhs, const Pokemon &rhs);

    friend bool operator<(const Pokemon &lhs, const Pokemon &rhs);

    friend Pokemon operator--(vector<Pokemon> &pokedex, int id);

    friend Pokemon operator++(vector<Pokemon> &pokedex, int id);
};


/*Function that checks if the name of a pokemon exists in the pokedex
 * PARAMS: vector<pokemon> pokedex, string selected name
 * RETURNS: boolean representing whether the selected name is in the pokedex
 * */
    bool checkName(vector<Pokemon> pokedex, string select);

/*Function to get a pokemon object given a pokedex and the name of said pokemon
 * PARAMS: vector<pokemon> pokedex, string name
 * RETURNS: Pokemon object
 * */
    Pokemon getPokemon(vector<Pokemon> pokedex, string name);



#endif //PROJECT1_POKEMON_H


