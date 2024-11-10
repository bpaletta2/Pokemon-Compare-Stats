#### Bobby Paletta 2024
# Pokemon Compare Stats 


This project is a Pokedex Team Builder written in C++ and Python. It allows users to:
 - Create a team of up to 6 Pokémon from a Pokedex of 801 unique characters.
 - Select two Pokémon statistics to compare.
 - Visualize the selected statistics in a scatter plot using Python.

Features
 - Pokedex: Access to a library of Pokémon with various statistics.
 - Trainer: Holds a vector of Pokemon objects and other trainer specifications
 - Team Selection: Users can select up to 6 Pokémon to add to their team.
 - Stat Comparison: Users choose two statistics to compare among team Pokémon.
 - Visualization: A scatter plot of the selected statistics is generated using Python and motplotlib for easy comparison.

Necessary Implementations
 - matplotlib
 - numpy
 - subprocess
 - sys
 - csv

| File            | Purpose |
| :---------------- | :---------: |
| Pokemon.cpp/h       | Class to instantiate a Pokemon object with appropriate methods |
| Trainer.cpp/h          | Class to instantiate a Trainer object with appropriate methods |
| main.cpp   |  Main method that creates a pokedex of 801 pokemon objects, allows the user to make a trainer object and add specified pokemon to their team and select statistics to compare |
| pythonOutput.py |  Python method that compiles and runs the main.cpp file and displays a scatter plot graph using the selected pokemon and statistics |


