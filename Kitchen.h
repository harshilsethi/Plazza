/*                                                                              
** EPITECH PROJECT, 2017                                                        
** Plazza project
** File description:                                                            
** Kitchen.h
*/

#ifndef KITCHEN_H__
#define KITCHEN_H__

#include <list>
#include <queue>
#include <string>
#include "AKitchen.h"
#include "Cooker.h"

class Kitchen : public AKitchen{
private:
	int nbCookers;
	std::queue<std::string> orders;
	std::list<Cooker> cookers;
public:
	Kitchen(int);
	~Kitchen();
	int getNbCookers();
	std::list<Cooker> &getCookers();
	void addOrder(std::string &);
	void dispatch();
	bool getStatut();
};


#endif //KITCHEN_H__
