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

#include <iostream>
#include "mazegenerator.h"

using namespace std;

int main()
{
	//calls the constructor with size = 20
    MazeGenerator maze(20);
	
	//generates the maze with steps = 4
    maze.generateBlindMaze(4);

	//prints the maze with chars
    maze.printMaze();

	cout << endl << endl << endl;
	system("PAUSE");
	
    return 0;
}

