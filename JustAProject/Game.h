#pragma once
#include "lib.h"
#include "Sprite.h"
#include "ShaderProgram.h"
#include "Rectangle.h"
#include "FieldFrag.h"
#include "Plants.h"

using namespace std;


enum Type
{
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	PLANT,
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
	Sprite* background;
	Sprite* main;
	Sprite* selected;
	Sprite*wareHouse;
	vector<FieldFrag*> field;
	vector<Plants*> plantList;
	Sprite * target;
	int treeSelected;
	bool clickSubMenu;
	vector<Menu> menuList;
	vector<Menu> subMenuList;
	void CreatePlantList();
	void LoadSubMenu();
	void DesSubMenu();
	bool canMove(int a, int b, int x, int y);
};