#pragma once
#include "lib.h"
#include "Sprite.h"
#include "ShaderProgram.h"
#include "Rectangle.h"
#include "FieldFrag.h"
#include "Plants.h"
#include "Camera.h"

using namespace std;


enum Type
{
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	PLANT,
	WAREHOUSE,
	SELECTMENU1,
	SELECTMENU2,
	SELECTMENU3,

	SELECTSPMENU1,
	SELECTSPMENU2,
	SELECTSPMENU3,
	SELECTSPMENU4,
	SELECTSPMENU5,
	SELECTSPMENU6,
	SELECTSPMENU7,
	SELECTSPMENU8,
	SELECTSPMENU9,
	SELECTSPMENU10,
	SELECTSPMENU11,
	QUITSPMENU,

	SELECTWAREHOUSE1,
	SELECTWAREHOUSE2,
	SELECTWAREHOUSE3,
	SELECTWAREHOUSE4,
	SELECTWAREHOUSE5,
	SELECTWAREHOUSE6,
	SELECTWAREHOUSE7,
	SELECTWAREHOUSE8,
	SELECTWAREHOUSE9,
	SELECTWAREHOUSE10,
	SELECTWAREHOUSE11,
	QUITWAREHOUSE,
	SELL
};

struct Action
{
	Type _type;
	std::pair<bool,char> iskey_pressed;
};

struct Menu
{
	string ID;
	Sprite* icon;
	Menu(string _ID, Sprite* _icon):ID(_ID),icon(_icon) {}
};


class Game
{
public:
	Game();

	~Game();

	void input(vector<Action> actions);

	void Draw(ShaderProgram* shader);


private:
	unique_ptr<Camera> cam;

	Sprite* background;
	Sprite* main;
	Sprite* selected;
	Sprite* whmenu;
	vector<FieldFrag*> field;
	vector<Plants*> plantList;
	Sprite * target;
	Sprite* wareHouse;
	int treeSelected, sellSelected;
	int  rice = 0, tomato = 0, carot=0, pineApple = 0, waterMelon = 0, grape = 0, rose = 0, mango = 0, dragonFruit = 0, sunFlower = 0, tulip = 0;
	std::clock_t start;
	bool clickSubMenu, clickWHMenu , openEnventory;
	vector<Menu> menuList;
	vector<Menu> subMenuList;
	vector<Menu> WHMenuList, WHQuantity;
	void CreatePlantList();
	void LoadSubMenu();
	void DesSubMenu();
	void DesWHMenu();
	void LoadWHMenu();
	int getTarget();
	int cropTree(int x);
	bool through(int x, int y, int a, int b);
	int Sell(int x);
};