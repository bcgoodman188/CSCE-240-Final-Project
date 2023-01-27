# CSCE 240 Fall 2021 Final Project - 75 points - Due 12/9/21 at Midnight
Your task will be to create a simple text-based simulation that inherits from a pre-existing World class. 

The “scenario” in the simulation that you develop can either be one described below in Part 1 or a “scenario” of your choice. However, if you would like to create your own “scenario” that differs significantly from the ones below you **must run your idea by me first so that I can approve it (so you do not put any wasted effort in to something)**. 

In addition to the creation of your simulation, you will also be in charge of creating a document that describes what you are simulating. This needs to include all of the details or “rules” of your scenario. This is an important step as if I cannot figure out the logic of your simulation then you will likely not receive many points. 

Lastly, be sure to also read and implement all of the required components on the checklist described in Part 1 (technical program requirements, good programming practices, formatting, commenting, etc.). 

## Part 1 - The Simulation - 65 points
You must use the World.h provided as a starting point for your code. At least one object in your solution should meaningfully inherit from this class. DO NOT MODIFY THE WORLD CLASS in any way. Note that the World class is abstract and there are a few pure virtual functions for you to implement in **your object** that inherits from the world. Namely, you will need to implement: 

1. void PrintGrid() - This function should print the grid (10 by 10 char array) to standard out. 
2. void UpdateGrid() - This function should update your characters' positions on the grid
3. void initGrid() - This function should set your grid up (implement your "starting conditions" here)

The scenarios that you will simulate will be confined to a 10x10 grid (defined in the World class as `grid`) and be subject to at least 10 distinct rules. In addition, there must be at least 2 different objects or “characters” interacting in your simulation. Each should be defined in their own class. Initially, characters should be spawned in random positions in the grid. Their movement on each day (or round of simulation) should be governed by the rules that you develop. After each day or round of your simulation, an updated grid showing the position of all characters should be printed to the standard output. There should be some clear stopping condition of your simulation. In addition, in at least one of your objects should overload at least two operators in a meaningful way. Ex. You may choose to overload your + operator to determine what will result if two of your characters interact. Your program should not contain any memory leaks. Where appropriate, you should use the const keyword. 

### Example Scenario: 

Life Simulation

**Starting Condition**: The simulation will start with 10 Humans, age 0 with immunity of 1, (5 female and 5 male) and 1 Virus object randomly placed in the grid. Each round of the program will symbolize a year passed.

Example Rules: 
1. Every year a Human object can make one random move vertically, horizontally or diagonally in the grid. 
2. If two Human objects come in contact with one another then if they are of the opposite gender, are unmarried and over age 18 then they will spawn another Human object somewhere in the grid (gender will be randomly assigned). 
3. Every 10 years another Virus object appears on the grid in a random spot. 
4. If a Human object comes in contact with a Virus object then if their immunity value is greater than 0.25 then a number between 0 and 1 will be randomly calculated and subtracted from the Human’s immunity value.
5. If a Human object comes in contact with a Virus object then if their immunity value is less than 0.25 then they will disappear from the grid. 
6. If the randomly generated move for any Human is illegal (out of bounds) then no move is made. 
...

**Stopping Condition**: The 10x10 grid has filled up or 1000 years (rounds) have passed. 

### Checklist:
- Inherit from the World class provided
- Implement the 3 pure virtual functions in the World class
- Implement 10 distinct rules
- Include at least 2 other objects as "characters" in your sim
- Make sure that there is an option for printing each iteration of the sim to standard out
- Make sure there is a clear stopping condition
- Overload at least two operators in at least one of your objects
- No memory leaks if you choose to use pointers in any way
- Where appropriate, use the const keyword. 

## Part 2 - The Write Up - 10 points
In Part 2 of this assignment, you will need to write a ~one-page document describing your scenario and the rules that you implemented. This needs to be detailed enough that I can understand what you are trying to accomplish without question. This includes **line numbers or names of functions for each rule that you create.** 

You should call this file "Final_WriteUp" and it should be uploaded to your git repo. 

## Running your code
