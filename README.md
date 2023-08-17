<h1 align=center>
	<b>so_long</b>
	 
  <i>42cursus' project #5</i>
</h2>
In this project, we'll code a simple 2D game to get familiar with the mlx library and UI in general.
  <h1 align=center>

![so_longe](https://github.com/spnzed/so_long/assets/95354392/664cc4dd-7f9e-4ab6-848f-170149abf7bc)

---

<h3 align=center>
Mandatory
</h3>

<b>Game actions:</b>
> <i>The player can move in four directions but cannot move into walls. To exit the game, the player needs to collect something. The WASD keys are used to move the main character, and the game has a top-down 2D view. The movements are displayed in the shell, and pressing ESC must close the window and quit the program cleanly. </i>

<b>Graphics actions:</b>
> <i>The program should display the image within a window, and window management should be smooth, such as switching to another window or minimizing. Pressing the [ESC] key should close the window and quit the program cleanly. The usage of MiniLibX images is mandatory.</i>

<b>Map actions:</b>
> <i>The map must be rectangular/square in shape, surrounded by walls with a clear path to the exit. It should be able to parse any type of map as long as it follows the aforementioned rules and contains three components - the exit, player start position, and collectibles. Additionally, if there is a misconfiguration in the map, the program should return an error message to indicate the issue.</i>

<h3 align=center>


<h2>
The Project
</h2>

### 🗺️ Map Rules

<b>Map Requisites:</b>
- Only ``P`` *(Character)*, ``1`` *(wall)*, ``0`` *(empty)*, ``C`` *(collectible)*, and ``E`` *(exit)* will be accepted characters in our map (except if you add enemies as bonus)
- The map must be rectangular, i.e. all rows must have the same length
- There must be at least one exit, one player, and one collectible on the map
- The map must be closed, i.e. surrounded by walls

> <i>If any of these checks fail, the game must end with a error message.</i>

🏆 | The goal is for the player(s) to collect all the collectibles on the map before going to an exit in the least possible number of steps

<b>Map Creation:</b>
- Create a new text file with a .ber extension. This will be your map file.
- Open the text file in a text editor.
- Define the map dimensions using this 5 symbols to represent different elements on the map:
	- 0 for an empty space
	- 1 for a wall
	- C for a collectible
	- E for a map exit,
	- P for the player’s starting position.

- Create a rectangular or square map, knowing that the map must be surrounded by '1's (walls) and must contain only one 'P' (player's starting point), one 'E' (exit), and multiple 'C's (collectibles). To test all the game features and have a better gaming experience, create a good level design using other game objects such as '0' for empty spaces (where the player can move).
- After creating the map, you can run it by passing the path where the map was created:

### 📁 Structure

* ```libft/```  My own Libft library.
* ```maps/```  Some maps (for running and testing the game).
* ```mlx/```  Mlx library.
* ```src/```  The sauce!
* ```textures/```  All sprites used in the game in .xpm.


---
<h2>
Usage
</h2>

### Prerequisites

**Linux and MacOS**
This project requires the [GNU Compiler Collection](https://gcc.gnu.org/), the [GNU Make](https://www.gnu.org/software/make/) compiler, internet to clone [MiniLibX](https://github.com/42Paris/minilibx-linux#readme) in the libraryfolder and X11 Development Libraries and Headers (`sudo apt-get install libx11-dev`).

**Windows**

You'll need to install Xserver in your machine seeing as the library runs on X-Window system. You may also use WSL on Windows 11 and run ```wsl --update``` and you should be good to go. <br>
❗️| Make sure you have all the required tools installed on your local machine, then continue with these steps.<br>

### 🛠️ Instructions

**0. Download the archives**

```bash
# Clone the repository
$ git clone https://github.com/spnzed/so_long.git

# Enter into the directory
$ cd so_long/
```

**1. Run the Game**
```bash
# Run the command make root directory to run the mandatory part
$ make

# This command compiles the executable file 'so_long' and runs it along with any map
# of your choice (or a custom one) located in the directory 'maps'.
#	To execute it, run the following command:
$ ./so_long map.ber
```
**2. How to play**
- Control the player using the arrow keys (up, down, left, and right) or the letter keys (w, a, s, and d).
- Press the 'R' key on your keyboard to reset the current level.
- Press the [ESC] key or Click in the 'X' window to exit the game.

<p align="center">
<img width="841" alt="Captura de pantalla 2023-08-17 a las 12 01 43" src="https://github.com/spnzed/so_long/assets/95354392/ea6a73d7-2560-4c9f-b3d8-5e7263044a35">

</p>
