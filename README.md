# Fillit

 Fillit is not about recoding Tetris, even if it’s still a variant of this game. This program will take a file as parameter, which contains a list of Tetriminos, and arrange them in order to create the smallest square possible.
 
`git clone --recurse-submodules git@github.com:gavrilov/fillit.git`

### The program
 The executable "fillit" takes only one parameter, a file which contains a list of Tetriminos to assemble. This file has a very specific format (see input sample).

### Input Sample
 Each tetraminos is represented with 4 lines of 4 characters, each followed by a new line. A Tetrimino is a classic piece of Tetris composed of 4 blocks. Each character must be either a block character(’#’) or an empty character (’.’). Each block of a Tetrimino must touch at least one other block on any of his 4 sides (up, down, left and right).

	...#
	...#
	...#
	...#

	....
	....
	....
	####

	.###
	...#
	....
	....

	....
	..##
	.##.
	....


### Output Sample
The program displays the smallest assembled square on the standard output. To identify each Tetrimino in the square solution, a capital letter will be assigned to each Tetrimino, starting with ’A’ and increasing for each new Tetrimino.

	ABBBB
	ACCC.
	A..C.
	ADD..
	DD...
