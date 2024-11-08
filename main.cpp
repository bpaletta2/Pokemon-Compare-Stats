//
// Created by Bobby Paletta on 9/8/24.
//
#include "Trainer.h"
#include <fstream>
#include <iostream>
#include <chrono>

void createPokedex(vector<Pokemon>& pokedex) {
    ifstream fileIn;
    fileIn.open("../pokemonNew2.csv");
    if (fileIn) {
        cout << "File opened" << endl;
        string header;
        getline(fileIn, header);

// declare variables
        int id = 0;
        string name = "Pokemon";
        string typeOne = "Poke";
        string typeTwo = "Mon";
        int total = 100;
        int hp = 100;
        int attack = 50;
        int defense = 50;
        int spAttack = 55;
        int spDefense = 55;
        int speed = 10;
        int generation = 0;
        int legendary = 0;
        string percentage_male = "1.0";
        double capture_rate = 0;
        string classification = "Mon";
        char comma = ',';
        string newLine;
        string negative;
        char quote = '"';
        string numInt;

        while (fileIn.peek() != EOF) {

            //read number
            fileIn >> id;
            fileIn >> comma;
            // read name
            getline(fileIn, name, comma);
            // read typeOne
            getline(fileIn, typeOne, comma);
            // read typeTwo
            getline(fileIn, typeTwo, comma);
            // read total
            fileIn >> total;
            fileIn >> comma;
            // read hp
            fileIn >> hp;
            fileIn >> comma;
            // read attack
            fileIn >> attack;
            fileIn >> comma;
            // read the defense
            fileIn >> defense;
            fileIn >> comma;
            // read spAttack
            fileIn >> spAttack;
            fileIn >> comma;
            //read spDefense
            fileIn >> spDefense;
            fileIn >> comma;
            //read speed
            fileIn >> speed;
            fileIn >> comma;
            //read generation
            fileIn >> generation;
            fileIn >> comma;
            //read legendary
            fileIn >> legendary;
            fileIn >> comma;
            //read percent male
            getline(fileIn, percentage_male, comma);
            //read capture rate
            fileIn >> capture_rate;
            fileIn >> comma;
            //read classification
            getline(fileIn, classification, '\r');


            pokedex.push_back(Pokemon(id, name, typeOne, typeTwo, total, hp,
                                      attack, defense, spAttack, spDefense,
                                      speed, generation, legendary, percentage_male,
                                      capture_rate, classification));
        }

    } else {
        cout << "Error opening file" << endl;
    }
    fileIn.close();
};
string getStat(string input){
    if (input == "A"){
        return "Total";
    }
    else if (input == "B"){
        return "HP";
    }
    else if (input == "C"){
        return "Attack";
    }
    else if (input == "D"){
        return "Defense";
    }
    else if (input == "E"){
        return "Special Attack";
    }
    else if (input == "F"){
        return "Special Defense";
    }
    else if (input == "G"){
        return "Speed";
    }
    else if (input == "H"){
        return "Generation";
    }
}
int main() {
    //create the pokedex using the getDataFromFile method in the pokemon class
    vector<Pokemon> pokedex;
    createPokedex(pokedex);


    bool check = false;
    string input;
    string fName;
    string lName;
    cout << "Welcome to the World of Pokemon! Let's begin your journey in this magical new world "
            "by learning something about you new trainer!" << endl;
    //Prompt for the user to enter their first name
    while (!check) {
        check = true;
        //string input;
        // bool check = true;
        cout << "Enter your first name: ";
        getline(std::cin, input);
        for (char c: input) {
            if (isspace(c)) {
                check = false;
            }
        }
        if (input.empty()) {
            cout << "No input. ";
            check = false;
        }

        if (check) {
            fName = input;
        } else {
            cout << "Invalid." << endl;
        }
    }
    //Prompt for the user to enter their last name
    check = false;
    while (!check) {
        check = true;
        //string input;
        // bool check = true;
        cout << "Enter your last name: ";
        getline(std::cin, input);
        for (char c: input) {
            if (isspace(c)) {
                check = false;
            }
        }
        if (input.empty()) {
            cout << "No input. ";
            check = false;
        }

        if (check) {
            lName = input;
        } else {
            cout << "Invalid." << endl;
        }
    }

    //Create a trainer object with the inputted first and last name and add pokemon to the trainers team
    Trainer newTrainer = Trainer(fName, lName);

    cout << "Welcome to this new world " << newTrainer.getfName() << " " << newTrainer.getlName() << "!" << endl;

    cout << "Now it is time to assemble your team of Pokemon!" << endl;


    //while invalid input and the size of the team is less than 6, reprompt until it is correct
    bool choice = true;
    while (choice && newTrainer.getSize() < 6) {
        check = false;
        cout << "Choose Pokemon #" << newTrainer.getSize() + 1 << endl;
        while (!check) {
            getline(std::cin, input);
            for (int i = 0; i < input.size(); i++) {
                input[i] = tolower(input[i]);
            }
            input[0] = toupper(input[0]);
            if (!checkName(pokedex, input)) {
                cout << "That is not a valid Pokemon. Please try again!" << endl;
            } else if (checkName(pokedex, input)) {
                check = true;
                newTrainer.addPokemon(getPokemon(pokedex, input));
            }
        }
        cout << "Great choice! " << getPokemon(pokedex, input).getName() << " is the "
             << getPokemon(pokedex, input).getClassifictaion() << endl;
        if (newTrainer.getSize() < 6) {
            cout << "Would you like to add another Pokemon to your team? (Y/N)" << endl;
            check = false;
            while (!check) {
                getline(std::cin, input);
                if (input == "N") {
                    choice = false;
                    check = true;
                } else if (input == "Y") {
                    check = true;
                } else {
                    cout << "Invalid option. Try again." << endl;
                }

            }
        }
    }

    string selectionOne, selectionTwo;
    bool relationCheck = false;
    cout << "Now it is time to compare your teams stats! You have the option to compare their "
            "base totals(a), hp(b), attack(c), defense(d), special attack(e), special defense(f),"
            "speed(g) and generation(h). " << endl;

    //loop through until the user makes a valid selection
    while (!relationCheck) {
        cout << "Please select one of the previous options. " << endl;
        getline(std::cin, selectionOne);
        std::transform(selectionOne.begin(), selectionOne.end(), selectionOne.begin(), ::toupper);

        if (selectionOne == "A" || selectionOne == "B" || selectionOne == "C" || selectionOne == "D" ||
            selectionOne == "E" || selectionOne == "F" ||
            selectionOne == "G" || selectionOne == "H") {
            relationCheck = true;
        } else {
            cout << "Invalid option" << endl;
        }
    }
    //reset the loop until it gets another valid selection
    relationCheck = false;
    while (!relationCheck) {
        cout << "Please select a second statistic. " << endl;
        getline(std::cin, selectionTwo);
        std::transform(selectionTwo.begin(), selectionTwo.end(), selectionTwo.begin(), ::toupper);

        if (selectionTwo == "A" || selectionTwo == "B" || selectionTwo == "C" || selectionTwo == "D" ||
            selectionTwo == "E" || selectionTwo == "F" ||
            selectionTwo == "G" || selectionTwo == "H") {
            relationCheck = true;
        } else {
            cout << "Invalid option" << endl;
        }
    }
    /*for every pokemon that the trainer has chosen, check which selections were
     * chosen and write to the file that specified pokemons first chosen statistic
     * value, the second chosen statistic value, the name of the pokemon, and both
     * statistic names.
     * */
    int count = 0;
    std::ofstream outFile;
    outFile.open("/Users/bobbypaletta/CLionProjects/M3OEP-rpaletta/project4_outfile.csv");
    for (int i = 0; i < newTrainer.getSize(); i++) {
        if (selectionOne == "A") {
            outFile << newTrainer.getPokemon(i).getTotal() << ",";
        } else if (selectionOne == "B") {
            outFile << newTrainer.getPokemon(i).getHP() << ",";
        } else if (selectionOne == "C") {
            outFile << newTrainer.getPokemon(i).getAttack() << ",";
        } else if (selectionOne == "D") {
            outFile << newTrainer.getPokemon(i).getDefense() << ",";
        } else if (selectionOne == "E") {
            outFile << newTrainer.getPokemon(i).getSpAttack() << ",";
        } else if (selectionOne == "F") {
            outFile << newTrainer.getPokemon(i).getSpDefense() << ",";
        } else if (selectionOne == "G") {
            outFile << newTrainer.getPokemon(i).getSpeed() << ",";
        } else if (selectionOne == "H") {
            outFile << newTrainer.getPokemon(i).getGeneration() << ",";
        }

        if (selectionTwo == "A") {
            outFile << newTrainer.getPokemon(i).getTotal() << ",";
        } else if (selectionTwo == "B") {
            outFile << newTrainer.getPokemon(i).getHP() << ",";
        } else if (selectionTwo == "C") {
            outFile << newTrainer.getPokemon(i).getAttack() << ",";
        } else if (selectionTwo == "D") {
            outFile << newTrainer.getPokemon(i).getDefense() << ",";
        } else if (selectionTwo == "E") {
            outFile << newTrainer.getPokemon(i).getSpAttack() << ",";
        } else if (selectionTwo == "F") {
            outFile << newTrainer.getPokemon(i).getSpDefense() << ",";
        } else if (selectionTwo == "G") {
            outFile << newTrainer.getPokemon(i).getSpeed() << ",";
        } else if (selectionTwo == "H") {
            outFile << newTrainer.getPokemon(i).getGeneration() << ",";
        }
        outFile << newTrainer.getPokemon(i).getName() << ",";

        if (count < 1) {
            outFile << getStat(selectionOne) << ",";
            outFile << getStat(selectionTwo) << endl;
            count++;
        }
        else{
            outFile << endl;
        }

    }
    outFile.close();

    return 0;
};