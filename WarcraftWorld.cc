 ///
 /// @file    WarcraftWorld.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-19 23:35:40
 ///
 
#include "WarcraftWorld.h"
#include "GameConfig.h"
#include "Warrior.h"

#include <iostream>
using namespace std;
 
namespace warcraft
{

void WarcraftWorld::init() 
{
	_redHeadquarters = new RedHeadquarters(
		GameConfig::getInstance()->headquartersInitialElements());

	_blueHeadquarters = new BlueHeadquarters(
		GameConfig::getInstance()->headquartersInitialElements());
}

void WarcraftWorld::start() 
{
	for(int idx = 0; idx != 10; ++idx) {
		Warrior * warrior = _redHeadquarters->create();
		if(warrior) {
			WarriorView * view = _redHeadquarters->getWarriorView(warrior);
			view->show();
		}
	}
}
 
}// end of namespace warcraft
