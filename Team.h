/*                                                                              
** EPITECH PROJECT, 2017                                                        
** Plazza project
** File description:                                                            
** Team.h
*/

#ifndef TEAM_H__
#define TEAM_H__

#include <iostream>
#include <string>
#include <queue>
#include "Kitchen.h"
#include "Cooker.h"

class Team {
private:
	std::queue<Cooker *> cookers;
public:
	Team(int);
	~Team();
	void addCooker();
	Cooker &takeCooker();
};


#endif //TEAM_H__
