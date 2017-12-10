//
// EPITECH PROJECT, 2017
// Plazza project
// File description:
// main.cpp
//

#include <iostream>
#include "Manager.h"
#include "Order.h"
#include <ncurses.h>
#include <menu.h>
#include <cstring>
#include <ncurses.h>
#include <iostream>
#include <vector>

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

WINDOW* createUserwin(WINDOW *local_win, std::vector<std::string> *commands, std::list<Order> orders)
{
	WINDOW *displayCommand;
	std::string result;
	int pizza, size, number;
	int i = 2;
	int j = 2;
	char endOrder, endPro;
	std::string command;
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
			command = command + " " + std::to_string(number);
			commands->push_back(command);
		}
		wrefresh(local_win);
	}
	mvwprintw(local_win,9,3,"Do you want to add pizza to this order");
	mvwprintw(local_win,10,3,"Y or y for Yes and N or n for No");
	endOrder = (char) wgetch(local_win);
	if(endOrder == 'Y' || endOrder == 'y') {
		//destroy_win(local_win);
		//destroy_win(displayCommand);
		//local_win = newwin(12,50,14, 40);
		wclear(local_win);
		wclear(displayCommand);
		wrefresh(local_win);
		wrefresh(displayCommand);
		createUserwin(local_win,commands, orders);
	} else if(endOrder == 'N' || endOrder == 'n') {
		mvwprintw(displayCommand, 1, 3, "List of Pizza of commands");
		for (std::string command : *commands) {
			result = result + command + ";";
			mvwprintw(displayCommand, i, 3, command.c_str());
			wrefresh(displayCommand);
			i++;
		}
		wclear(local_win);
		wrefresh(local_win);
		Order order(result);
		orders.push_back(order);
		mvwprintw(local_win, 1, 3, "Do you want to make another order");
		endPro = (char) wgetch(local_win);
		if (endPro == 'Y' || endPro == 'y') {
			commands->clear();
			numberOrder++;
			//destroy_win(local_win);
			//destroy_win(displayCommand);
			//local_win = newwin(12, 50, 14, 40);
			wclear(local_win);
			wclear(displayCommand);
			wrefresh(local_win);
			wrefresh(displayCommand);
			createUserwin(local_win, commands, orders);
		} else if(endPro == 'N' || endPro == 'n'){
			wclear(displayCommand);
			i = 1;
			mvwprintw(displayCommand, 1, 3, "You have total of %d orders", numberOrder);
			for(Order order : orders)
			{
				mvwprintw(displayCommand,j,3, "Order %d ", i);
				i++;
				j++;
				mvwprintw(displayCommand, j, 3, order.getCommand().c_str());
				j++;
			}
			wrefresh(displayCommand);
		}
	}
	return local_win;
}

void createCurses(std::list<Order> orders)
{
	WINDOW *titleWin;
	WINDOW *menuWin;
	WINDOW *userWin;
	// Initialize curses
	std::vector<std::string> commands;
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
	userWin = createUserwin(userWin, &commands, orders);
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

void launchOrder (Manager *manager, Order anOrder, int cookersNb){
	manager->convertInputIntoOrder(anOrder);
	manager->manageKitchens(cookersNb);
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>> ORDER #" << manager->getOrderID() << " READY !" << std::endl;
	manager->nextOrderID();
}

int main(int argc,char *argv[]) { //./a.out []

	if (argc < 3) {
		std::cout << "In order to enter the Plazza, please specify the base time and the number of cookers " << std::endl;
		std::cout << "Example : ./a.out [time] [cookers]" << std::endl;
	} else {
		int baseTime;
		int cookersNb;
		Manager manager;
		std::vector<std::string> commands;
		std::string commandsToTransfer;
		std::list<Order> orders;
		std::list<Order> ordersToTransfer;

		baseTime = static_cast<int>(strtol(argv[1], nullptr, 10));
		cookersNb = static_cast<int>(strtol(argv[2], nullptr, 10));

		createCurses(orders);
		manager.setTime(baseTime);

		std::cout << "1 T = " << baseTime << std::endl; //temp (for warnings)
		std::string input1 = "Margarita L 2 ; American XL 11; Fantasia L 7";
		std::string input2 = "Fantasia XL 4; Regina M 6";
		//Order order1(input1);
		//Order order2(input2);

		for (const auto &command : commands) {
			std::cout << "COMMAND : " << command << std::endl;
			commandsToTransfer.append(command);
			commandsToTransfer.append(";");
		}

		for (auto &order : orders) {
			launchOrder(&manager, order, cookersNb);
		}

		//Order order1(commandsToTransfer);
		//manager.convertInputIntoOrder(order1);

		std::cout << std::endl
			  << "===================================" << std::endl
			  << std::endl;

//		launchOrder(&manager, order1, cookersNb);
//		launchOrder(&manager, order2, cookersNb);

		std::queue<std::string> res = manager.getPizzas();
		manager.manageKitchens(cookersNb);

		/*while(!res.empty()){
			std::cout << res.front() << std::endl;
			res.pop();
		}*/
	}

	return (EXIT_SUCCESS);
}