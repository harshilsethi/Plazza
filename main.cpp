#include <iostream>
#include "Manager.h"
#include "Order.h"
#include <ncurses.h>
#include <menu.h>
#include <cstring>
#include <ncurses.h>
#include <iostream>
#include <vector>

static int numberOrder = 0;
void destroy_win(WINDOW *local_win)
{
	wrefresh(local_win);
	delwin(local_win);
}

void createSimpleTitle(WINDOW *win)
{
	wattron(win,COLOR_PAIR(1));
	wattron(win,A_BOLD);
	mvwprintw(win,1, 35,"   _______   ___            __     ________  ________        __      ");
	mvwprintw(win,2, 35,"  |   __ \"\\ |\"  |          /\"\"\\   (\"      \"\\(\"      \"\\      /\"\"\\     ");
	mvwprintw(win,3, 35,"  (. |__) :)||  |         /    \\   \\___/   :)\\___/   :)    /    \\    ");
	mvwprintw(win,4, 35,"  |:  ____/ |:  |        /' /\\  \\    /  ___/   /  ___/    /' /\\  \\   ");
	mvwprintw(win,5, 35,"  (|  /      \\  |___    //  __'  \\  //  \\__   //  \\__    //  __'  \\  ");
	mvwprintw(win,6, 35," /|__/ \\    ( \\_|:  \\  /   /  \\\\  \\(:   / \"\\ (:   / \"\\  /   /  \\\\  \\ ");
	mvwprintw(win,7, 35,"(_______)    \\_______)(___/    \\___)\\_______) \\_______)(___/    \\___)");
	wattroff(win,A_BOLD);
	wattroff(win,COLOR_PAIR(1));
	wrefresh(win);
}

void createFooter(int y, int x)
{
	mvprintw(y, x, 		                 "        ,----,                                                                                           ");
	mvprintw(y++, x, 			 "      ,/   .`|                                                                                           ");
	mvprintw(y++, x, 			 "    ,`   .'  :  ,---,                                  ,-.                                               ");
	mvprintw(y++, x,                         "  ,	  ,	 ;    ;	    ;    ;     /,--.' |                              ,--/ /|                 ,---,                         ");
	mvprintw(y++, x, 			 ".'___,/    ,' |  |  :                      ,---, ,--. :/ |                /_ ./|   ,---.           ,--,  ");
	mvprintw(y++, x, 			 "|    :     |  :  :  :                  ,-+-. /  |:  : ' /           ,---, |  ' :  '   ,'\\        ,'_ /|  ");
	mvprintw(y++, x, 			 ";    |.';  ;  :  |  |,--.  ,--.--.    ,--.'|'   ||  '  /           /___/ \\.  : | /   /   |  .--. |  | :  ");
	mvprintw(y++, x, 			 "`----'  |  |  |  :  '   | /       \\  |   |  ,\"' |'  |  :            .  \\  \\ ,' '.   ; ,. :,'_ /| :  . |  ");
	mvprintw(y++, x, 			 "    '   :  ;  |  |   /' :.--.  .-. | |   | /  | ||  |   \\            \\  ;  `  ,''   | |: :|  ' | |  . .  ");
	mvprintw(y++,x,		                 "    |   |  '  '  :  | | | \\__\\/: . . |   | |  | |'  : |. \\            \\  \\    ' '   | .; :|  | ' |  | |  ");
	mvprintw(y++,x, 			 "    '   :  |  |  |  ' | : ,\" .--.; | |   | |  |/ |  | ' \\ \\            '  \\   | |   :    |:  | : ;  ; |  ");
	mvprintw(y++,x, 			 "    ;   |.'   |  :  :_:,'/  /  ,.  | |   | |--'  '  : |--'              \\  ;  ;  \\   \\  / '  :  `--'   \\ ");
	mvprintw(y++,x, 			 "    '---'     |  | ,'   ;  :   .'   \\|   |/      ;  |,'                  :  \\  \\  `----'  :  ,      .-./ ");
	mvprintw(y++,x,			         "              `--''     |  ,     .-./'---'       '--'                     \\  ' ;           `--`----'     ");
	mvprintw(y++,x , 			 "                         `--`---'                                          `--`                          ");
	refresh();
}

WINDOW* createTitle(WINDOW* win)
{
	//wborder(win,  '|', '|', '-' ,'_', '|', '|', '|', '|');
	init_pair(1,COLOR_BLACK,139);
	createSimpleTitle(win);
	return win;
}

WINDOW* createMenuwin(WINDOW* local_win)
{
	init_pair(2,COLOR_BLACK, COLOR_YELLOW);
	wbkgd(local_win, COLOR_PAIR(2));
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

WINDOW* createUserwin(WINDOW *local_win, std::vector<std::string> commands, Order *order)
{
	WINDOW *displayCommand;
	int pizza, size, number;
	int i = 2;
	char endIt;
	std::string command;
	std::string commandToTransfer;

	init_pair(3,COLOR_BLACK, 85);
	init_pair(4,COLOR_BLACK, 203);
	wbkgd(local_win, COLOR_PAIR(3));
	wborder(local_win,  '|', '|', '-' ,'_', '|', '|', '|', '|');
	mvwprintw(local_win, 2, 3,"Please choose your pizza");
	mvwprintw(local_win, 3, 3 ,"Enter the number corresponding to the pizza");
	wrefresh(local_win);
	displayCommand = newwin(12,40,14, 98);
	wbkgd(displayCommand, COLOR_PAIR(4));
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
		mvwprintw(local_win, 4, 3, "Which size do you want ?");
		mvwprintw(local_win,5,3, "Please enter the corresponding number");
		wrefresh(local_win);
		size = static_cast<char>(getch());
		getch();
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
			command = command + " " + std::to_string(number) + " ; ";
			commandToTransfer = command;
			commands.push_back(command);
		}
		wrefresh(local_win);
	}
	mvwprintw(local_win,9,3,"Do you want to make another order");
	mvwprintw(local_win,10,3,"Y or y for Yes and N or n for No");
	endIt = (char) wgetch(local_win);
	if(endIt == 'Y' || endIt == 'y') {
		destroy_win(local_win);
		destroy_win(displayCommand);
		local_win = newwin(12,50,14, 40);
		createUserwin(local_win, commands, order);
	} else if(endIt == 'N' || endIt == 'n') {
		order->setCommand(commandToTransfer);
		mvwprintw(displayCommand,1,3,"List of commands %d", numberOrder);
		for(std::string command : commands){
			mvwprintw(displayCommand,i,3,command.c_str());
			wrefresh(displayCommand);
			i++;
		}
		numberOrder++;
	}
	return local_win;
}

void createCurses(std::vector<std::string> commands)
{
	WINDOW *titleWin;
	WINDOW *menuWin;
	WINDOW *userWin;
	Order order;

	// Initialize curses
	int y, x;
	initscr();
	cbreak();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	start_color();
	init_pair(0,COLOR_BLACK, COLOR_WHITE);
	bkgdset(COLOR_PAIR(0));
	getmaxyx(stdscr,y,x);		/* get the number of rows and columns */
	box(stdscr,'*','*');
	//Create Windows
	titleWin = newwin(10, x - 2, 5,1);
	menuWin = newwin(12,30,14,1);
	userWin = newwin(12,50,14, 40);
	refresh();
	//Display windows
	titleWin = createTitle(titleWin);
	menuWin = createMenuwin(menuWin);
	userWin = createUserwin(userWin, commands, &order);
	refresh();
	//Display thank you
	//Display Thank You
	createFooter(y - 15 ,(COLS - 2) / 5);
	getch();
	//Destroy windows
	destroy_win(titleWin);
	destroy_win(menuWin);
	destroy_win(userWin);
	getch();
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