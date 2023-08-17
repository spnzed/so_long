<h1 align=center>
	<b>so_long</b>
	 
  <i>42cursus' project #5</i>
</h2>
May it be a file, stdin, or even later a network connection, you will always need a way to read content line by line. It is time to start working on this function, which will be essential for your future projects. In this repo you will find all the files regarding the implementations of the <b>get_next_line</b> functions, both its <b>mandatory</b> and <b>bonus</b> versions.
  <h1 align=center>

![so_longe](https://github.com/spnzed/so_long/assets/95354392/664cc4dd-7f9e-4ab6-848f-170149abf7bc)

---

<h3 align=center>
Mandatory
</h3>

Game actions:
> <i>The player can move in four directions but cannot move into walls. To exit the game, the player needs to collect something. The WASD keys are used to move the main character, and the game has a top-down 2D view. The movements are displayed in the shell, and pressing ESC must close the window and quit the program cleanly. </i>

Graphics actions:
> <i>The program should display the image within a window, and window management should be smooth, such as switching to another window or minimizing. Pressing the [ESC] key should close the window and quit the program cleanly. The usage of MiniLibX images is mandatory.</i>

Map actions:
> <i>The map must be rectangular/square in shape, surrounded by walls with a clear path to the exit. It should be able to parse any type of map as long as it follows the aforementioned rules and contains three components - the exit, player start position, and collectibles. Additionally, if there is a misconfiguration in the map, the program should return an error message to indicate the issue.</i>

<h3 align=center>
Bonus
</h3>

> <i>The <b>bonus</b> part must behave like the mandatory part but adding up functionality to handle multiple file descriptors opened at once. The bonus function must also deal with only one static variable.</i>

---

<h2>
The project
</h2>

### Mandatory implementation

- [`header file`](get_next_line.h)
- [`get_next_line`](get_next_line.c)	- the main function and its additionals
- [`get_next_line_utils`](get_next_line_utils.c)	- additional functions from [`libft`](https://github.com/caroldaniel/42sp-cursus-libft)

### Bonus implementation

- [`header file`](get_next_line_bonus.h)
- [`get_next_line_bonus`](get_next_line_bonus.c)	- the main function and its additionals
- [`get_next_line_utils_bonus`](get_next_line_utils_bonus.c)	- additional functions from [`libft`](https://github.com/caroldaniel/42sp-cursus-libft)


---
<h2>
Usage
</h2>

### Instructions

When compiling `get_next_line` or its **bonus** version, be sure to include the following flags

```sh
$> gcc -Wall -Wextra -Werror -D BUFFER_SIZE=xxx <files>.c.
```

Where the `xxx` can be substituted by the number of bytes read at a time into the buffer for the `read` function. 
