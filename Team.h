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
#include "Cooker.h"

class Team {
private:
	std::queue<Cooker *> cookers;
public:
	explicit Team(int);
	~Team();

	void getBackCooker(Cooker &aCooker);
	Cooker takeCooker();
};

#endif //TEAM_H__
