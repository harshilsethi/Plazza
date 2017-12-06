#include <iostream>
#include "Manager.h"
#include "Order.h"
#include <ncurses.h>
#include <menu.h>
#include <cstring>
#include <ncurses.h>
#include <iostream>
#include <vector>

void destroy_win(WINDOW *local_win)
{
	wrefresh(local_win);
	delwin(local_win);
}

WINDOW* createTitle(WINDOW* win)
{
	//wborder(win,  '|', '|', '-' ,'_', '|', '|', '|', '|');
	wprintw(win,"\\ \\    / / ___     | |     __      ___    _ __     ___      o O O  | |_     ___      o O O   | _ \\  | |     /   \\   |_  /   |_  /   /   \\  \n"
		" \\ \\/\\/ / / -_)    | |    / _|    / _ \\  | '  \\   / -_)    o       |  _|   / _ \\    o        |  _/  | |__   | - |    / /     / /    | - |  \n"
		"  \\_/\\_/  \\___|   _|_|_   \\__|_   \\___/  |_|_|_|  \\___|            _\\__|   \\___/            _|_|_   |____|  |_|_|   /___|   /___|   |_|_|  ");
	wrefresh(win);
	return win;
}

WINDOW* createMenuwin(WINDOW* local_win)
{
	wborder(local_win,  '|', '|', '-' ,'_', '|', '|', '|', '|');
	mvwprintw(local_win, 1, 8, "     Menu");
	mvwprintw(local_win,2,1,"      1 - Margarita");
	mvwprintw(local_win,3,1,"      2 - Regina");
	mvwprintw(local_win,4,1,"      3 - American");
	mvwprintw(local_win,5,1,"      4 - Fantasia");
	mvwprintw(local_win,7, 8, "     Size");
	mvwprintw(local_win,8,1,"      1 - M (Standard)");
	mvwprintw(local_win,9,1,"      2 - L (Large)");
	mvwprintw(local_win,10,1,"      3 - XL (Super)");
	wrefresh(local_win);
	return local_win;
}

WINDOW* createUserwin(WINDOW *local_win, std::vector<std::string> commands)
{
	WINDOW *displayCommand;
	int pizza, size, number;
	int i = 2;
	char endIt;
	std::string command;
	wborder(local_win,  '|', '|', '-' ,'_', '|', '|', '|', '|');
	mvwprintw(local_win, 2, 3,"Please choose your pizza");
	mvwprintw(local_win, 3, 3 ,"Enter the number before the pizza");
	wrefresh(local_win);
	displayCommand = newwin(12,40,14, 98);
	wborder(displayCommand,  '|', '|', '-' ,'_', '|', '|', '|', '|');
	wrefresh(displayCommand);
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
			mvwprintw(local_win, 2, 3,"Please Enter the correct number");
			command = std::string("");
			wrefresh(local_win);
	}
	wgetch(local_win);
	if(!command.empty()) {
		mvwprintw(local_win, 4, 3, "Please choose your size");
		mvwprintw(local_win,5,3, "Enter the number");
		wrefresh(local_win);
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
				command = std::string("");
				mvwprintw(local_win,6,3,"Please Enter the correct number");
				wrefresh(local_win);
		}
		if (!command.empty()) {
			mvwprintw(local_win, 6, 3, "Please choose the number of pizza you want");
			mvwprintw(local_win, 7, 3, "Enter the number");
			wscanw(local_win, const_cast<char *>("%d"), &number);
			wrefresh(local_win);
			command = command + " " + std::to_string(number) + "\n";
			commands.push_back(command);
		}
		wrefresh(local_win);
	}
	mvwprintw(local_win,9,3,"Do you want to finish your order");
	mvwprintw(local_win,10,3,"Y or y for Yes and N or n for No");
	endIt = (char) wgetch(local_win);
	if(endIt == 'Y' || endIt == 'y') {
		destroy_win(local_win);
		destroy_win(displayCommand);
		local_win = newwin(12,50,14, 40);
		createUserwin(local_win,commands);
	} else if(endIt == 'N' || endIt == 'n') {
		mvwprintw(displayCommand,1,3,"List of commands");
		for(std::string command : commands){
			mvwprintw(displayCommand,i,3,command.c_str());
			wrefresh(displayCommand);
			i++;
		}
	}
	return local_win;
}

void createCurses(std::vector<std::string> commands)
{
	WINDOW *titleWin;
	WINDOW *menuWin;
	WINDOW *userWin;
	// Initialize curses
	int y, x;
	initscr();
	cbreak();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	getmaxyx(stdscr,y,x);		/* get the number of rows and columns */
	box(stdscr,'*','*');
	//Create Windows
	titleWin = newwin(10, x - 2, 5,1);
	menuWin = newwin(12,30,14,1);
	userWin = newwin(12,50,14, 40);
	//start_color(););
	refresh();
	titleWin = createTitle(titleWin);
	menuWin = createMenuwin(menuWin);
	userWin = createUserwin(userWin, commands);
	refresh();
	//Destroy window
	mvprintw(y - 15 ,5,
		 "        ,----,                                                                                           \n"
			 "      ,/   .`|                                                                                           \n"
			 "    ,`   .'  :  ,---,                                  ,-.                                               \n"
			 "  ;    ;     /,--.' |                              ,--/ /|                 ,---,                         \n"
			 ".'___,/    ,' |  |  :                      ,---, ,--. :/ |                /_ ./|   ,---.           ,--,  \n"
			 "|    :     |  :  :  :                  ,-+-. /  |:  : ' /           ,---, |  ' :  '   ,'\\        ,'_ /|  \n"
			 ";    |.';  ;  :  |  |,--.  ,--.--.    ,--.'|'   ||  '  /           /___/ \\.  : | /   /   |  .--. |  | :  \n"
			 "`----'  |  |  |  :  '   | /       \\  |   |  ,\"' |'  |  :            .  \\  \\ ,' '.   ; ,. :,'_ /| :  . |  \n"
			 "    '   :  ;  |  |   /' :.--.  .-. | |   | /  | ||  |   \\            \\  ;  `  ,''   | |: :|  ' | |  . .  \n"
			 "    |   |  '  '  :  | | | \\__\\/: . . |   | |  | |'  : |. \\            \\  \\    ' '   | .; :|  | ' |  | |  \n"
			 "    '   :  |  |  |  ' | : ,\" .--.; | |   | |  |/ |  | ' \\ \\            '  \\   | |   :    |:  | : ;  ; |  \n"
			 "    ;   |.'   |  :  :_:,'/  /  ,.  | |   | |--'  '  : |--'              \\  ;  ;  \\   \\  / '  :  `--'   \\ \n"
			 "    '---'     |  | ,'   ;  :   .'   \\|   |/      ;  |,'                  :  \\  \\  `----'  :  ,      .-./ \n"
			 "              `--''     |  ,     .-./'---'       '--'                     \\  ' ;           `--`----'     \n"
			 "                         `--`---'                                          `--`                          ");
	refresh();
	getch();
	destroy_win(titleWin);
	destroy_win(menuWin);
	destroy_win(userWin);
	endwin();
}

int main()
{
	std::vector<std::string> commands;
	createCurses(commands);
	return 0;
}
/*int main() {
	Manager manager;
	std::string input1 = "Margarita L 3 ; American XL 3; Fantasia L 3";
	Order order1(input1);

	manager.convertInputIntoOrder(order1);

	std::cout << "===================================" << std::endl << std::endl;

	std::queue<std::string> res = manager.getPizzas();
	manager.manageKitchens(6);
	while(!res.empty()){
		std::cout << res.front() << std::endl;
		res.pop();
	}

	return 0;
}*/