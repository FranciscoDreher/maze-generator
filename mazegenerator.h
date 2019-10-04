/*
 * maze-generator
 * It allows to generate a maze for any use.
 * LICENSE: This file is part of maze-generator.
 * maze-generator is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * maze-generator is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with maze-generator. If not, see <http://www.gnu.org/licenses/>.
 * @copyright Copyright (c) 2019 Francisco Elias Dreher (<>)
 * @license http://www.gnu.org/licenses/ GPL License
 * @version 1.0
 * @link <>
 * @since File available since Release 1.0
*/

#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <utility>
#include <time.h>
#include <cstdlib>

using namespace std;

class MazeGenerator
{
    private:
        int size;

        vector< vector<int> > maze;

    public:
		MazeGenerator(int size)
		{
			if(size >= 0)
			{
				this->size = size;
			}
			else
				{
					this->size = 0;
				}
		}
		
		bool setSize(int size)
		{
			if(size >= 0)
			{
				this->size = size;
				return true;
			}
			else
				{
					this->size = 0;
					return false;
				}
		}
		
		bool generateBlindMaze(int amountOfSteps)
		{
			if(this->size == 0)
			{
				return false;
			}
			else
			{
				/*Integers in maze vector
				*
				* 1 => Wall
				*
				* 0 => Floor
				*/
				vector<int> aux;
				
				//fill the maze with walls (integer 1)
				for(int y=0;y<this->size;y++)
				{
					for(int x=0;x<this->size;x++)
						aux.push_back(1);
					this->maze.push_back(aux);
					aux.clear();
				}
				
				//amount of walls in the final maze
				int finalWalls = ((this->size - 1) * (this->size - 1)) / 3;
				
				//amount of walls in the actual maze
				int amountOfWalls = (this->size - 1) * (this->size - 1);
				
				//maximum steps that the algorithm can take
				int steps = amountOfSteps;
				
				srand(time(NULL));
				
				//first position indexes
				//dirX stands for ROW
				//dirY stands for COLUMN
				int dirX=1, dirY=1;
				
				//directions that the algorithm can take
				int direction;
				
				//first position with Floor
				this->maze[dirX][dirY] = 0;
				
				//generates the floor while the actual amount of walls is greater than the final amount
				while(amountOfWalls > finalWalls)
				{
					//sets a random direction
					//0 down, 1 up, 2 right, 3 left
					direction = rand()%4;
					
					if(direction == 0)
					{
						//iterates while there are steps remaining and the X index did not reach the lower border
						while((dirX < (this->size - 2)) && (steps >= 0))
						{
							dirX++;
							this->maze[dirX][dirY] = 0;
							steps--;
						}
						
						//restarts the steps to the original amount
						steps = amountOfSteps;
					}
					else if(direction == 1)
					{
						//iterates while there are steps remaining and the X index did not reach the upper border
						while((dirX > 1) && (steps >= 0))
						{
							dirX--;
							this->maze[dirX][dirY] = 0;
							steps--;
						}
						
						//restarts the steps to the original amount
						steps = amountOfSteps;
					}
					else if(direction == 2)
					{
						//iterates while there are steps remaining and the Y index did not reach the right border
						while((dirY < (this->size - 2)) && (steps >= 0))
						{
							dirY++;
							this->maze[dirX][dirY] = 0;
							steps--;
						}
						
						//restarts the steps to the original amount
						steps = amountOfSteps;
					}
					else if(direction == 3)
					{
						//iterates while there are steps remaining and the Y index did not reach the left border
						while((dirY > 1) && (steps >= 0))
						{
							dirY--;
							this->maze[dirX][dirY] = 0;
							steps--;
						}
						//restarts the steps to the original amount
						steps = amountOfSteps;
					}
					
					amountOfWalls--;
				}
				
				return true;
			}
		}
		
		void printMaze()
		{
			for(int i=0; i<this->size;i++)
			{
				for(int j=0; j<this->size; j++)
				{
					cout << (char)this->maze[i][j] << " ";
				}
				
				cout << endl;
			}
		}
		
		~MazeGenerator()
		{
			for(int i=0; i<this->size; i++)
			{
				this->maze[i].clear();
			}
		}
};

#endif // MAZEGENERATOR_H
