/*
** EPITECH PROJECT, 2017
** PISCINE CPP
** File description:
** Window.h
*/
//
// Created by Du Tran Uy on 11/12/2017.
//

#ifndef PLAZZAV1_WINDOW_H
#define PLAZZAV1_WINDOW_H

#include <list>
#include "Order.h"
#include <iostream>
#include <ncurses.h>
#include <menu.h>
#include <cstring>
#include <ncurses.h>
#include <vector>

static int numberOrder = 1;

class WindowFront {
public:
	WindowFront();
	~WindowFront();
	WINDOW* createTitle(WINDOW* win);
	WINDOW* createMenuwin(WINDOW* local_win);
	WINDOW* createUserwin(WINDOW *local_win);
	void createCurses();
public:
	std::list<Order> getOrders() const;
	const std::vector<std::string> &getLastCommands() const;
private:
	std::list<Order> orders;
	std::vector<std::string> lastCommand;
private:
	std::string choosePizza(WINDOW *local_win);
	std::string chooseSize(WINDOW *local_win, std::string command);
	void continueOrder(WINDOW *local_win, WINDOW *displayComannd);
};
void destroy_win(WINDOW *local_win);
void createSimpleTitle(WINDOW *win);
void createFooter(int y, int x);
#endif //PLAZZAV1_WINDOW_H
