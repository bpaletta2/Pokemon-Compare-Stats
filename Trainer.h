//
// Created by Bobby Paletta on 10/3/24.
//

#ifndef M2OEP_TRAINER_H
#define M2OEP_TRAINER_H

#include "Pokemon.h"


class Trainer{
public:
    /*
     *
     *
     */
    Trainer();
    /*
     *
     */
    Trainer(std::string fName, std::string lName);

    /*
     *
     */
    std::string getfName();


    std::string getlName();

    /*
     *
     */
    void addPokemon(Pokemon teammate);

    Pokemon getPokemon(int index);

    int getSize();


private:
    std::string fName;
    std::string lName;
    std::vector<Pokemon> team;
};


#endif //M2OEP_Trainer_H
