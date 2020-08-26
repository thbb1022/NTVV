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
	SHOOT
};

struct Action
{
	Type _type;
	std::pair<bool,char> iskey_pressed;
	glm::vec2 mouse_pos;
};


class Game
{
public:
	Game();

	~Game();

	void input(vector<Action> actions);

	void Draw(ShaderProgram* shader);

	void LoadMenu();

private:
	Sprite* background;
	Sprite * target;
	//Sprite* sun;
	//Sprite* planet;
	//Sprite* planet_mask;
	//Sprite* planet2;
	//Sprite* enemy;

	Sprite *tree;
	Sprite* main;
	vector<Sprite*> dat;
	bool flag;

	Texture* bullet;
	vector<Rectangle*> bullets;
};