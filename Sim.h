// Author: Ben Goodman
//Email: BCG2@email.sc.edu
//Section: 002
//Copyright 2021 Ben Goodman

#ifndef SIM_H
#define SIM_H
#include <iostream>
#include "World.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <istream>

using std::vector;
using std::cout;
using std::string;


//S = Snail
//M = Mushroom
//T = Toxic Mushroom
//G = Ground

class Sim: public World{

    public: 
    int day = 0;
    bool snailAte = true;
    int terminationCounter = 0; 
    int snailGenCounter = 0;
    

        struct Snail
        {
            char sName;
            int immunity;
            
            
        };
        struct Mushroom
        {
            char mName;
            int toxcicity;
        };

        bool operator==(const Snail & snailImmunity) const
        {
            bool ret = false;
            if(1 == snailImmunity.immunity)
            {
                ret = false;
            }
            else
            {
                ret = true;
            }
            return ret;
        }

        void initGrid()
        {
            for(int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    int randImmunity = rand() % 1;
                    Snail newSnail = Snail{'S', randImmunity};
                    Mushroom newMushroom = Mushroom {'M', 0};
                    grid[5][0] = newSnail.sName;
                    grid[5][9] = newMushroom.mName;
                    grid[i][j] = 'G';
                }
            }
        }
        void PrintGrid()
            {
                for(int i = 0; i < 10; i++)
                {
                    std::cout << "\n";
                    for(int j = 0 ; j < 10; j++)
                    {
                        std::cout << grid[i][j];
                        std::cout << " ";
                    }
                }
                std::cout << "\n";
            }
            void UpdateGrid()
            {
                MushroomGrowth();
                SnailEating();
                SnailMovement();
                snailGenCounter++;
                if(snailGenCounter == 5)
                {
                    SnailGeneration();
                    snailGenCounter = 0;
                }
                SnailsTerminate();
                MushroomsTerminate();
            }
            void SnailGeneration()
            {
                Snail newSnail = Snail{'S', 1};
                int snailGeneration = rand() % 10;
                grid[snailGeneration][1] = newSnail.sName; 
            }
            void MushroomGrowth()
            {
                for(int i = 0; i < 10; i++)
                {
                    for(int j = 0; j < 10; j++)
                    {
                        Mushroom newMushroom = Mushroom {'M', 0};
                        Mushroom newToxicMushroom = Mushroom {'T', 1};
                        int randMush = rand() % 6;
                        int r2 = rand() % 3;
                        
                        if(r2 == 0 && i-1 >= 0 && grid[i][j] == 'M' && grid[i-1][j] == 'G')
                        {
                            if(randMush == 0 || randMush == 1 || randMush == 2) 
                            {
                                grid[i-1][j] = newMushroom.mName;
                                break;
                            }
                            if(randMush == 3 || randMush == 4 || randMush == 5)
                            {
                                grid[i-1][j] = 'G';
                                break;
                            }
                            if(randMush == 6)
                            {
                                grid[i-1][j] = newToxicMushroom.mName;
                                break;
                            }
                        }
                        //check down
                        else if(r2 == 1 && i+1 <= 9 && grid[i][j] == 'M' && grid[i+1][j] == 'G')
                        {
                            if(randMush == 0 || randMush == 1 || randMush == 2)
                            {
                               grid[i+1][j] = newMushroom.mName;
                               break;
                            }
                            if(randMush == 3 || randMush == 4 || randMush == 5)
                            {
                                grid[i+1][j] = newToxicMushroom.mName;
                                break;
                            }
                            if(randMush == 6)
                            {
                                grid[i+1][j] = 'G';
                                break;
                            }
                        }
                        //check left
                        else if(r2 == 2 && j-1 >= 0 && grid[i][j-1] == 'G' && grid[i][j] == 'M')
                        {
                            if(randMush == 0 || randMush == 1 || randMush == 2)
                            {
                                grid[i][j-1] = newMushroom.mName;
                                break;
                            }
                            if(randMush == 3 || randMush == 4 || randMush == 5)
                            {
                                grid[i][j-1] = newToxicMushroom.mName;
                                break;
                            }
                            if(randMush == 6)
                            {
                                grid[i][j-1] = 'G';
                                break;
                            }
                        }
                        //check right
                        else if(r2 == 3 && j+1 <= 9 && grid[i][j+1] == 'G' && grid[i][j] == 'M')
                        {
                            if(randMush == 0 || randMush == 1 || randMush == 2)
                            {
                                grid[i][j+1] = newMushroom.mName;
                                break;
                            }
                            if(randMush == 3 || randMush == 4 || randMush == 5)
                            {
                                grid[i][j+1] = newToxicMushroom.mName;
                                break;
                            }
                            if(randMush == 6)
                            {
                                grid[i][j+1] = 'G';
                                break;
                            }
                        }
                    }
                }
            }
            void SnailEating()
            {
                int r = rand() % 1;
                for(int i = 0; i < 10; i++)
                {
                    for(int j = 0; j < 10; j++)
                    {
                        if(grid[i][j] == 'S')
                        {
                            //check up
                            if(i-1 >= 0 && grid[i-1][j] == 'M')
                            {
                                grid[i-1][j] = 'S';
                                snailAte = true;
                                break;
                            }
                            if(i-1 >= 0 && grid[i-1][j] == 'T')
                            {
                                Snail newSnail = Snail {0,r};
                                operator==(newSnail);

                                if(operator==(newSnail) == true)
                                {
                                    grid[i][j] = 'G';
                                    grid[i-1][j] = 'G';
                                }
                                if(operator==(newSnail) == false)
                                {
                                    grid[i-1][j] = 'G';
                                }
                                snailAte = true;
                                break;
                            }
                            //check down
                            if(i+1 <= 9 && grid[i+1][j] == 'M')
                            {
                                grid[i+1][j] = 'S';
                                snailAte = true;
                                break;
                            }
                            if(i+1 <= 9 && grid[i+1][j] == 'T')
                            {
                                Snail newSnail = Snail {0,r};
                                operator==(newSnail);

                                if(operator==(newSnail) == true)
                                {
                                    grid[i][j] = 'G';
                                    grid[i+1][j] = 'G';
                                }
                                if(operator==(newSnail) == false)
                                {
                                    grid[i+1][j] = 'G';
                                }
                                snailAte = true;
                                break;
                            }
                            //check left
                            if(j-1 >= 0 && grid[i][j-1] == 'M')
                            {
                                grid[i][j-1] = 'S';
                                snailAte = true;
                                break;
                            }
                            if(j-1 >= 0 && grid[i][j-1] == 'T')
                            {
                                Snail newSnail = Snail {0,r};
                                operator==(newSnail);

                                if(operator==(newSnail) == true)
                                {
                                    grid[i][j] = 'G';
                                    grid[i][j-1] = 'G';
                                }
                                if(operator==(newSnail) == false)
                                {
                                    grid[i][j-1] = 'G';
                                }
                                snailAte = true;
                                break;
                            }
                            //check right
                            if(j+1 <= 9 && grid[i][j+1] == 'M')
                            {
                                grid[i][j+1] = 'S';
                                snailAte = true;
                                break;
                            }
                            if(j+1 <= 9 && grid[i][j+1] == 'T')
                            {
                                Snail newSnail = Snail {0,r};
                                operator==(newSnail);

                                if(operator==(newSnail) == true)
                                {
                                    grid[i][j] = 'G';
                                    grid[i][j+1] = 'G';
                                }
                                if(operator==(newSnail) == false)
                                {
                                    grid[i][j+1] = 'G';
                                }
                                snailAte = true;
                                break;
                            }
                            else
                                snailAte = false;
                        }

                    }
                }
            }
            void SnailMovement()
            {
                if(snailAte == false)
                {
                    for(int i = 0; i < 10; i++)
                    {
                        for(int j = 0; j < 10; j++)
                        {
                            if(grid[i][j] =='S')
                            {
                                int randDirection = rand() % 4 + 1;
                                //check up
                                
                                if(randDirection == 1 && i-1 >= 0 && grid[i-1][j] == 'G' && grid[i-1][j] != 'S')
                                {
                                    grid[i][j] = 'G';
                                    grid[i-1][j] = 'S';
                                    break;
                                }
                                //check down
                                if(randDirection == 2 && i+1 <= 9 && grid[i+1][j] == 'G' && grid[i+1][j] != 'S')
                                {
                                    grid[i][j] = 'G';
                                    grid[i+1][j] = 'S';
                                    break;
                                }
                                
                                //check left
                                
                                if(randDirection == 3 && j-1 >= 0  && grid[i][j-1] == 'G' && grid[i][j-1] != 'S')
                                {
                                    grid[i][j] = 'G';
                                    grid[i][j-1] = 'S';
                                    break;
                                }
                                //check right
                                if(randDirection == 4 && j+1 <= 9 && grid[i][j+1] == 'G' && grid[i][j+1] != 'S')
                                {
                                    grid[i][j] = 'G';
                                    grid[i][j+1] = 'S';
                                    break;
                                }
                                
                            }
                        }
                    }
                }
                if(snailAte == true)
                {
                    return;
                }

            }
            bool SnailsTerminate()
            {
                for(int i = 0; i < 10; i++)
                {
                    for(int j = 0; j < 10; j++)
                    {
                        if(grid[i][j] == 'S')
                        {
                            terminationCounter++;
                        }
                        else if(grid[i][j] == 'G')
                        {
                            terminationCounter++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                if(terminationCounter == 100)
                {
                    return true;
                }
                if(terminationCounter != 100)
                {
                    terminationCounter = 0;
                    return false;
                }
                return false;
            }
            bool MushroomsTerminate()
            {
                for(int i = 0; i < 10; i++)
                {
                    for(int j = 0; j < 10; j++)
                    {
                        if(grid[i][j] == 'M')
                        {
                            terminationCounter++;
                        }
                        else if(grid[i][j] == 'G')
                        {
                            terminationCounter++;
                        }
                        else if(grid[i][j] == 'T')
                        {
                            terminationCounter++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                if(terminationCounter == 100)
                {
                    return true;
                }
                if(terminationCounter != 100)
                {
                    terminationCounter = 0;
                    return false;
                }
                return false;
            }
            void Death()
            {
            for(int i = 0; i < 10; i++)
			{
                std::cout << "\n";
				for(int j = 0; j < 10; j++)
				{
					grid[i][j] = 'X';
                    std::cout  << grid[i][j] << " ";
				}
			}
            std::cout << "\n";
            }
            int DayCycle()
            {
                day++;
                return day;
            }


};


#endif /* SIM_H*/