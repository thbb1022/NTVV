#pragma once
#include "lib.h"
#include "Sprite.h"
#include "ShaderProgram.h"
#include "Rectangle.h"
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
	QUITSPMENU,
};

struct Action
{
	Type _type;
	std::pair<bool,char> iskey_pressed;
	glm::vec2 mouse_pos;
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
	Sprite * target;
	int treeSelected;
	Sprite *tree;
	Sprite* main;
	vector<Sprite*> dat;
	bool flag, plant, clickSubMenu;

	vector<int> field;
	vector<Menu> menuList;
	vector<Menu> subMenuList;
	vector<Rectangle*> bullets;
	vector<Sprite*> platList;
	bool isPlanted(int location);
	void LoadSubMenu();
	void DesSubMenu();
	bool destroyPlant;
};