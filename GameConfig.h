 ///
 /// @file    GameConfig.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-19 20:51:16
 ///
 
#include "Types.h"
#include <map>
#include <vector>
#include <iostream>
using namespace std;
 
namespace warcraft
{

class GameConfig {
public:
	template <typename Iterator>
	void setWarriorOrder(Iterator beg, Iterator end)
	{
		while(beg != end) {
			_initOrder.push_back(*beg);
			++beg;
		}
	}

	void setWarriorOrder(const vector<WARRIOR_TYPE> & initOrder) 
	{	_initOrder = initOrder;	}

	void readFromConsole();
	void readFromFile(const string & filename);
	void increaseGroupId() {	++_currentGroupId;	}
	size_t currentGroupId()	const {	return _currentGroupId;	}
	size_t groups() const {	return _groups.size();	}
	size_t headquartersInitialElements();
	size_t warriorInitalLife(WARRIOR_TYPE key); 
	void debug() const;

	static GameConfig * getInstance()
	{
		if(nullptr == _pInstance) {
			_pInstance = new GameConfig();
		}
		return _pInstance;
	}

	static void destroy() 
	{
		if(_pInstance)
			delete _pInstance;
	}

private:
	GameConfig() : _currentGroupId(0){	cout << "GameConfig()" << endl;	}
	~GameConfig(){	cout << "~GameConfig()" << endl;	}
	void readFromStream(istream & is);

	struct InitData
	{
		size_t _initElements;
		map<WARRIOR_TYPE, size_t> _initLifes;
	};
private:
	static GameConfig * _pInstance;

	vector<WARRIOR_TYPE> _initOrder;
	vector<InitData> _groups;
	size_t _currentGroupId;//当前组的测试数据的id
};
 
}// end of namespace warcraft