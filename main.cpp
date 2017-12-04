#include <iostream>
#include "Manager.h"
#include "Order.h"
#include <ncurses.h>
#include <menu.h>
#include <cstring>
/*
WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	if(has_colors() == FALSE){
		endwin();
		wprintw(local_win, "Your terminal doesn't support color");
		exit(1);
	}
	// Start color
	init_pair(1, COLOR_RED,COLOR_BLUE);
	/* The parameters taken are
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window
	 * 3. rs: character to be used for the right side of the window
	 * 4. ts: character to be used for the top side of the window
	 * 5. bs: character to be used for the bottom side of the window
	 * 6. tl: character to be used for the top left corner of the window
	 * 7. tr: character to be used for the top right corner of the window
	 * 8. bl: character to be used for the bottom left corner of the window
	 * 9. br: character to be used for the bottom right corner of the window
	 */
/*
	wborder(local_win,  '|', '|', '-' ,'_', '|', '|', '|', '|');
	attron(A_BOLD);
	mvwprintw(local_win,1,width/5, "Welcome to The PLAZZA PIZZA");
	attroff(A_BOLD);
	mvwprintw(local_win, 3, static_cast<int>((width / 2 ) - 12), "Menu");
	mvwprintw(local_win,4,1," 1 - Margarita");
	mvwprintw(local_win,5,1," 2 - Regina");
	mvwprintw(local_win,6,1," 3 - American");
	mvwprintw(local_win,7,1," 4 - Fantasia");
	mvwprintw(local_win, 10, static_cast<int>((width / 2 ) - 12), "Size");
	mvwprintw(local_win,11,1,"1 - M (Standard)");
	mvwprintw(local_win,12,1,"2 - L (Large)");
	mvwprintw(local_win,13,1,"3 - XL (Super)");



	wrefresh(local_win);		/* Show that window 		*/
/*
	return local_win;
}

void destroy_win(WINDOW *local_win)
{
	wrefresh(local_win);
	delwin(local_win);
}

void createCurse(std::vector<std::string> commands){

	/* For the calcul*/
/*	int startx, starty, width, height;
	int row, col;
	char pizza;
	char size;
	char number;
	char endIt;
	WINDOW* window;
	std::string command;
	bool end = false;
	/* Initialize curses */
/*	initscr();
	cbreak();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	getmaxyx(stdscr,row,col);		/* get the number of rows and columns */

	/* Initialize Window Menu */
/*	height = 15;
	width = 40;
	starty = (LINES - height) /2 ;/* Calculating for a center placement */
/*	startx = (COLS - width) / 2;	/*		*/
/*	attron(COLOR_PAIR(1));
	printw("Please choose your pizza \n Enter the number before the pizza \n");
	refresh();
	window = create_newwin(height, width, starty, startx);
	refresh();
	pizza = static_cast<char>(getch());
	switch (pizza){
		case '1':
			command = "Margarita";
			break;
		case '2':
			command = "Regina";
			break;
		case '3':
			command = "American";
			break;
		case '4':
			command = "Fantasia";
			break;
		default:
			printw("Please Enter the correct number \n");
			refresh();
	}
	printw(command.c_str());
	refresh();
	if(command != "") {
		printw("Please choose your size \n Enter the number \n");
		size = static_cast<char>(getch());
		switch (size) {
			case '1':
				command = command + " " + "M";
				break;
			case '2':
				command.append(" ");
				command.append("L");
				break;
			case '3':
				command.append(" ");
				command.append("XL");
				break;
			default:
				printw("Please Enter the correct number \n");
				refresh();
		}
		refresh();
		printw("Please choose the number of pizza you want \n Enter the number");
		scanw("%d",&number);
		command = command + " " + std::to_string(number) + "\n";
		commands.push_back(command);
		refresh();
	}
	printw("%s" , command.c_str());
	printw("Do you want to make another order \n Y for Yes and N for No \n");
	endIt = getch();
	if(endIt == 'Y') {
		printw("Ok Here's your orders \n");
		for(auto command : commands){
			printw(command.c_str());
			printw("\n");
		}
		printw("Thank You and See You Again \n");

	} else {
		erase();
		createCurse(commands);
	}
	attroff(COLOR_PAIR(1));
	getch();
	command.empty();
	refresh();
	destroy_win(window);
	endwin();
}

int main()
{
	std::vector<std::string> commands;
	createCurse(commands);
	return 0;
}
*/
int main() {
	Manager manager;
	std::string input1 = "Margarita L 2 ; American XL 1";
	Order order1(input1);

	manager.convertInputIntoOrder(order1);

	return 0;
}