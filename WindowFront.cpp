//
// EPITECH PROJECT, 2017
// Plazza Project
// File description:
// WindowFront.cpp
//

#include "WindowFront.h"

static int numberOrder = 1;

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

WindowFront::WindowFront()
{
	createCurses();
}

WindowFront::~WindowFront()
{}

void WindowFront::createCurses()
{
	WINDOW *titleWin;
	WINDOW *menuWin;
	WINDOW *userWin;
	// Initialize curses
	int y, x;
	initscr();
	cbreak();
	raw();
	//noecho();
	keypad(stdscr, TRUE);
	start_color();
	init_pair(0,COLOR_BLACK, COLOR_WHITE);
	bkgdset(COLOR_PAIR(0));
	getmaxyx(stdscr,y,x);
	box(stdscr,'*','*');
	//Create Windows
	titleWin = newwin(10, x - 2, 5,1);
	menuWin = newwin(12,30,14,1);
	userWin = newwin(12,50,14, 40);
	refresh();
	//Display windows
	titleWin = createTitle(titleWin);
	menuWin = createMenuwin(menuWin);
	userWin = createUserwin(userWin);
	refresh();
	//Display Thank You
	createFooter(y - 15 ,(COLS - 2) / 5);
	getch();
	//Destroy windows
	destroy_win(titleWin);
	destroy_win(menuWin);
	destroy_win(userWin);
	endwin();
}

WINDOW* WindowFront::createUserwin(WINDOW *local_win)
{
	WINDOW *displayCommand;
	std::string result;
	int pizza, size, number;
	int i = 2;
	char endOrder, endPro, endError;
	bool flag = true;
	std::string command;
	init_pair(3,COLOR_BLACK, 85);
	init_pair(4,COLOR_BLACK, 203);
	wbkgd(local_win, COLOR_PAIR(3));
	wclear(local_win);
	wrefresh(local_win);
	wborder(local_win,  '|', '|', '-' ,'_', '|', '|', '|', '|');
	mvwprintw(local_win, 2, 3,"Please choose your pizza");
	mvwprintw(local_win, 3, 3 ,"Enter the number corresponding to the pizza:");
	wrefresh(local_win);
	displayCommand = newwin(12,40,14, 98);
	wbkgd(displayCommand, COLOR_PAIR(4));
	wborder(displayCommand,  '|', '|', '-' ,'_', '|', '|', '|', '|');
	wrefresh(displayCommand);
	pizza = static_cast<char>(wgetch(local_win));
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
			wclear(local_win);
			mvwprintw(local_win, 5, 3,"You entered a wrong number ");
			command = std::string("");
			wgetch(local_win);
	}
	wgetch(local_win);
	if(!command.empty()) {
		mvwprintw(local_win, 4, 3, "Which size do you want ?");
		mvwprintw(local_win,5,3, "Please enter the corresponding number:");
		wrefresh(local_win);
		size = static_cast<char>(wgetch(local_win));
		wgetch(local_win);
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
				wclear(local_win);
				mvwprintw(local_win,5,3,"You entered a wrong number");
				command = std::string("");
				wrefresh(local_win);
				wgetch(local_win);
		}
		if (!command.empty()) {
			mvwprintw(local_win, 6, 3, "How many pizzas do you want ?");
			mvwprintw(local_win, 7, 3, "Enter the number:");
			wscanw(local_win, const_cast<char *>("%d"), &number);
			if(number == 0) {
				wclear(local_win);
				mvwprintw(local_win, 6, 3, "You haven't entered a number");
				wgetch(local_win);
				wrefresh(local_win);
				command = std::string("");
			} else {
				wrefresh(local_win);
				command = command + " " + std::to_string(number);
				lastCommand.push_back(command);
			}
		}
		wrefresh(local_win);
	}
	if(!command.empty()) {
		mvwprintw(local_win, 9, 3, "Do you want to add pizzas to this order ?");
		mvwprintw(local_win, 10, 3, "Y or y for Yes to continue OR any key to exit ");
		endOrder = (char) wgetch(local_win);
		if (endOrder == 'Y' || endOrder == 'y') {
			wclear(local_win);
			wclear(displayCommand);
			wrefresh(local_win);
			wrefresh(displayCommand);
			createUserwin(local_win);
		} else if (endOrder == 'N' || endOrder == 'n') {
			mvwprintw(displayCommand, 1, 3, "Let's recap your order :");
			for (std::string command : lastCommand) {
				result = result + command + ";";
				mvwprintw(displayCommand, i, 3, command.c_str());
				wrefresh(displayCommand);
				i++;
			}
			wclear(local_win);
			wrefresh(local_win);
			Order order(result);
			orders.push_back(order);
			mvwprintw(local_win, 1, 3, "Do you want to make another order ?");
			mvwprintw(local_win, 2, 3, "Enter Y or y to continue OR any key to exit ");
			endPro = (char) wgetch(local_win);
			if (endPro == 'Y' || endPro == 'y') {
				orderFlag = 1;
			} else {
				orderFlag = 0;
			}
			wrefresh(displayCommand);
		}
	}
	while (command.empty() && flag){
		i = 1;
		wclear(local_win);
		wrefresh(local_win);
		mvwprintw(local_win,5,3,"Do you want to remake the order ?");
		mvwprintw(local_win,6,3,"Enter Y or y to continue OR N or n to exit ");
		endError = static_cast<char>(wgetch(local_win));
		if(endError == 'Y' || endError == 'y') {
			createUserwin(local_win);
			flag = false;
			break;
		} else if(endError == 'N' || endError == 'n') {
			for (std::string command : lastCommand) {
				result = result + command + ";";
				mvwprintw(displayCommand, i, 3, command.c_str());
				wrefresh(displayCommand);
				i++;
			}
			flag = false;
			break;
		}
		wrefresh(local_win);
	}
	return local_win;
}

WINDOW* WindowFront::createTitle(WINDOW *win)
{
	init_pair(1,COLOR_BLACK,139);
	createSimpleTitle(win);
	return win;
}

WINDOW* WindowFront::createMenuwin(WINDOW *local_win)
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

std::list<Order> WindowFront::getOrders() const {
	return orders;
}

const std::vector<std::string> &WindowFront::getLastCommands() const {
	return lastCommand;
}

int WindowFront::getOrderFlag() {
	return orderFlag;
}

void WindowFront::runNewOrder(WINDOW *displayCommand, WINDOW *local_win) {
	this->lastCommand.clear();
	numberOrder++;
	wclear(local_win);
	wclear(displayCommand);
	wrefresh(local_win);
	wrefresh(displayCommand);
	createUserwin(local_win);
}