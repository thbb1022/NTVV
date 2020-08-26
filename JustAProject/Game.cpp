#include "Game.h"

Game::Game()
{
	background = new Sprite("c9ca3d19204877.562d67dc6f516.jpg",glm::vec2(0));
	background->scale(glm::vec2(2000,2000));

	float x = 1400, y = 500, tmp = 0;
	for (int i = 0; i < 81; i++)
	{
		dat.push_back(new Sprite("0.png", glm::vec2(x, y)));
		dat[i]->scale(glm::vec2(70));
		x += 45;
		tmp++;
		if (tmp >= 9)
		{
			x = 1400;
			y += 45;
			tmp = 0;
		}
	}

	clickSubMenu = false;

	tree = new Sprite("cay.png", glm::vec2(700, 700));
	tree->scale(glm::vec2(200));

	main = new Sprite("laibuon.gif", glm::vec2(700, 500));
	main->scale(glm::vec2(100));

	int menux = 50, menuy = 300;
	menuList.push_back(Menu("1", new Sprite("Images\\menu\\trong.png", glm::vec2(menux, menuy))));
	menuList[0].icon->scale(glm::vec2(100));
	menuList.push_back(Menu("2", new Sprite("Images\\menu\\tuoi.png", glm::vec2(menux, menuy + 150))));
	menuList[0].icon->scale(glm::vec2(100));
	menuList.push_back(Menu("3", new Sprite("Images\\menu\\pha.png", glm::vec2(menux, menuy + 300))));
	menuList[0].icon->scale(glm::vec2(100));
}

Game::~Game()
{
	delete target;
	delete background;
	delete main;
	for (auto item: dat) {
		delete item;
	}
	for (auto item : platList) {
		delete item;
	}
}

void Game::input(vector<Action> actions)
{
	flag = false, plant = false, destroyPlant = false;
	for (auto action : actions)
	{
		switch (action._type)
		{
			case MOVE_UP:
				main->move_up(2);
				break;
			case MOVE_DOWN:
				main->move_down(2);
				break;
			case MOVE_LEFT:
				main->move_left(2);
				break;
			case MOVE_RIGHT:
				main->move_right(2);
				break;
			case PLANT:
				plant = true;
				break;
			case SELECTMENU1:
				LoadSubMenu();
				break;
			case SELECTMENU2:
				break;
			case SELECTMENU3:
				if (destroyPlant == true)
					destroyPlant = false;
				else destroyPlant = true;
				break;
			case SELECTSPMENU1:
				if (clickSubMenu == true)
				{
					treeSelected = 1;
				}
				break;
			case SELECTSPMENU2:
				if (clickSubMenu == true)
				{
					treeSelected = 2;
				}
				break;
			case SELECTSPMENU3:
				if (clickSubMenu == true)
				{
					treeSelected = 3;
				}
				break;
			case QUITSPMENU:
				if (clickSubMenu == true)
				{
					DesSubMenu();
				}
			default:
				break;
		}
	}
	
	for (int i = 0; i < 81; i++)
	{
		//x,y
		int x = dat[i]->getposition().x, y = dat[i]->getposition().y;
		//
		if (main->getposition().x - x <= 10
			&& main->getposition().y - y <= 10 )
		{
			target = new Sprite("download.gif", glm::vec2(dat[i]->getposition().x + 25, dat[i]->getposition().y + 20));
			target->scale(glm::vec2(30));
			if (plant == true && isPlanted(i) == false)
			{
				if(treeSelected == 1)
					dat[i] = new Sprite("Images\\plant\\1-chin.png", glm::vec2(x, y));
				else if (treeSelected == 2)
					dat[i] = new Sprite("Images\\plant\\2-chin.png", glm::vec2(x, y));
				else if (treeSelected == 3)
					dat[i] = new Sprite("Images\\plant\\3-chin.png", glm::vec2(x, y));
				dat[i]->scale(glm::vec2(70));
				field.push_back(i);
				plant = false;
			}
			if (destroyPlant == true)
			{
				dat[i] = new Sprite("0.png", glm::vec2(x, y));
				dat[i]->scale(glm::vec2(70));
			}
			return;
		}
	}
}

void Game::Draw(ShaderProgram* shader)
{

	//bg
	shader->Send_Mat4("model_matrx", background->transformation());
	background->draw();

	//dat
	for (int i = 0; i < 81; i++)
	{
		shader->Send_Mat4("model_matrx", dat[i]->transformation());
		dat[i]->draw();
	}

	//nv
	shader->Send_Mat4("model_matrx", main->transformation());
	main->draw();

	//sub menu
	for (int i = 0; i < 4; i++)
	{
		if (!subMenuList.empty())
		{
			shader->Send_Mat4("model_matrx", subMenuList[i].icon->transformation());
			subMenuList[i].icon->draw();
		}
	}

	//menu
	for (int i = 0; i < 3; i++)
	{
		shader->Send_Mat4("model_matrx", menuList[i].icon->transformation());
		menuList[i].icon->draw();
	}

	//tree
	shader->Send_Mat4("model_matrx", tree->transformation());
	tree->draw();


	//mui ten
	if(target->getposition() != glm::vec2(0))
	{
		shader->Send_Mat4("model_matrx", target->transformation());
		target->draw();
	}
}

void Game::LoadSubMenu()
{
	int menux = 150, menuy = 300;
	subMenuList.push_back(Menu("1", new Sprite("Images\\menu\\1.png", glm::vec2(menux, menuy))));
	subMenuList[0].icon->scale(glm::vec2(100));
	subMenuList.push_back(Menu("2", new Sprite("Images\\menu\\2.png", glm::vec2(menux + 150, menuy))));
	subMenuList[0].icon->scale(glm::vec2(100));
	subMenuList.push_back(Menu("3", new Sprite("Images\\menu\\3.png", glm::vec2(menux + 300, menuy))));
	subMenuList[0].icon->scale(glm::vec2(100));
	subMenuList.push_back(Menu("4", new Sprite("Images\\menu\\quit.png", glm::vec2(menux + 450, menuy))));
	subMenuList[0].icon->scale(glm::vec2(100));
	clickSubMenu = true;
}

void Game::DesSubMenu()
{
	subMenuList.clear();
}

bool Game::isPlanted(int location)
{
	for (auto i : field)
	{
		if (i == location) // da trong
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

