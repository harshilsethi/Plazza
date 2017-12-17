/*
** EPITECH PROJECT, 2017
** PISCINE CPP
** File description:
** Window.h
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <list>
#include "Order.h"
#include <iostream>
#include <ncurses.h>
#include <menu.h>
#include <cstring>
#include <ncurses.h>
#include <vector>

class WindowFront {
public:
	WindowFront();
	~WindowFront();
	WINDOW* createTitle(WINDOW* win);
	WINDOW* createMenuwin(WINDOW* local_win);
	WINDOW* createUserwin(WINDOW *local_win);
	void createCurses();
	int getOrderFlag();
	void runNewOrder(WINDOW *displayComannd, WINDOW *local_win);

public:
	std::list<Order> getOrders() const;
	const std::vector<std::string> &getLastCommands() const;
private:
	std::list<Order> orders;
	std::vector<std::string> lastCommand;
	int orderFlag = 0;
private:
	std::string choosePizza(WINDOW *local_win);
	std::string chooseSize(WINDOW *local_win, std::string command);
	void continueOrder(WINDOW *local_win, WINDOW *displayComannd);
};
void destroy_win(WINDOW *local_win);
void createSimpleTitle(WINDOW *win);
void createFooter(int y, int x);

#endif //WINDOW_H
