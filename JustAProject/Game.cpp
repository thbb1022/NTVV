#include "Game.h"

Game::Game()
{
	CreatePlantList();
	start = std::clock(); 

	background = new Sprite("Images\\bg.png",glm::vec2(0));
	background->scale(glm::vec2(2000,2000));

	main = new Sprite("Images\\laibuon.png", glm::vec2(700, 500));
	main->scale(glm::vec2(100));

	float x = 1300, y = 450, tmp = 1;
	for (int i = 0; i < 25; i++)
	{
		field.push_back(new FieldFrag());
		field[i]->plantID = 0;
		field[i]->setStatus(BLANK);
		field[i]->image = new Sprite("Images\\plant\\012.png", glm::vec2(x, y));
		field[i]->image->scale(glm::vec2(70));
		if (tmp < 5)
		{
			x += 70;
			tmp++;
		}
		else
		{
			y += 70;
			x = 1300;
			tmp = 1;
		}
	}

	clickSubMenu = false;
	int menux = 50, menuy = 300;
	for (int i = 0; i < 3;i++)
	{
		string path = "Images\\menu\\menu" + to_string(i+1) + ".png";
		menuList.push_back(Menu(to_string(i+1), new Sprite(path.c_str(), glm::vec2(menux, menuy))));
		menuList[i].icon->scale(glm::vec2(100));
		menuy += 150;
	}
}

Game::~Game()
{
	delete target;
	delete background;
	delete main;
	delete selected;
	for (auto item : field)
	{
		delete item;
	}
	for (auto item : plantList)
	{
		delete item;
	}
}
void Game::input(vector<Action> actions)
{
	glm::vec2 select;
	bool slFlag = false, plantFlag = false, destroyPlantFlag = false;
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
		case SELECTMENU1:
			LoadSubMenu();
			treeSelected = 0;
			select = menuList[0].icon->getposition();
			selected = new Sprite("Images\\menu\\selected.png", select);
			selected->scale(glm::vec2(110));
			break;
		case SELECTMENU2:
			DesSubMenu();
			treeSelected = 0;
			select = menuList[1].icon->getposition();
			selected = new Sprite("Images\\menu\\selected.png", select);
			selected->scale(glm::vec2(110));
			break;
		case SELECTMENU3:
			destroyPlantFlag = true;
			DesSubMenu();
			treeSelected = 0;
			select = menuList[2].icon->getposition();
			selected = new Sprite("Images\\menu\\selected.png", select);
			selected->scale(glm::vec2(110));
			break;
		case SELECTSPMENU1:
			if (clickSubMenu == true)
			{
				treeSelected = 1;
				slFlag = true;
			}
			break;
		case SELECTSPMENU2:
			if (clickSubMenu == true)
			{
				treeSelected = 2;
				slFlag = true;
			}
			break;
		case SELECTSPMENU3:
			if (clickSubMenu == true)
			{
				treeSelected = 3;
				slFlag = true;
			}
			break;
		case SELECTSPMENU4:
			if (clickSubMenu == true)
			{
				treeSelected = 4;
				slFlag = true;
			}
			break;
		case SELECTSPMENU5:
			if (clickSubMenu == true)
			{
				treeSelected = 5;
				slFlag = true;
			}
			break;
		case SELECTSPMENU6:
			if (clickSubMenu == true)
			{
				treeSelected = 6;
				slFlag = true;
			}
			break;
		case SELECTSPMENU7:
			if (clickSubMenu == true)
			{
				treeSelected = 7;
				slFlag = true;
			}
			break;
		case SELECTSPMENU8:
			if (clickSubMenu == true)
			{
				treeSelected = 8;
				slFlag = true;
			}
			break;
		case SELECTSPMENU9:
			if (clickSubMenu == true)
			{
				treeSelected = 9;
				slFlag = true;
			}
			break;
		case SELECTSPMENU10:
			if (clickSubMenu == true)
			{
				treeSelected = 10;
				slFlag = true;
			}
			break;
		case SELECTSPMENU11:
			if (clickSubMenu == true)
			{
				treeSelected = 11;
				slFlag = true;
			}
			break;
		case QUITSPMENU:
			if (clickSubMenu == true)
			{
				select = menuList[0].icon->getposition();
				selected = new Sprite("Images\\menu\\selected.png", select);
				selected->scale(glm::vec2(110));
				treeSelected = 0;
				DesSubMenu();
			}
		case PLANT:
			plantFlag = true;
			break;
		default:
			break;
		}
	}

	if (treeSelected != 0 && slFlag)
	{
		cout << treeSelected;
		select = subMenuList[treeSelected - 1].icon->getposition();
		selected = new Sprite("Images\\menu\\selected.png", select);
		selected->scale(glm::vec2(110));
		slFlag = false;
	}

	for (auto i : field)
	{
		//x,y
		int x = i->image->getposition().x;
		int y = i->image->getposition().y;
		//

		if (i->getStatus() != BLANK)
		{
			int duration = (std::clock() - start) / (int)CLOCKS_PER_SEC;
			cout << duration << endl;
			if (duration- (i->plantTime) == (i->life / 2) /*&& duration - (i->plantTime) < (i->life)*/ && i->getStatus() != MIDDLE && i->getStatus() != RIPEN)
			{
				i->setStatus(MIDDLE);
				cout << i->getStatus();
				i->image = new Sprite(plantList[i->plantID - 1]->getImage(i->getStatus()), glm::vec2(x, y));
				i->image->scale(glm::vec2(70));
				return;
			}
			else if (duration - (i->plantTime) == (i->life) && i->getStatus() != RIPEN)
			{
				i->setStatus(RIPEN);
				i->image = new Sprite(plantList[i->plantID - 1]->getImage(i->getStatus()), glm::vec2(x, y));
				i->image->scale(glm::vec2(70));
				return;
			}
		}
	}

	if (getTarget() != -1)
	{
		int targetx = field[getTarget()]->image->getposition().x;
		int targety = field[getTarget()]->image->getposition().y;
		target = new Sprite("Images\\target.png", glm::vec2(targetx + 22.5, targety + 22.5));
		target->scale(glm::vec2(30));
		if (plantFlag == true && field[getTarget()]->isPlanted() == false && treeSelected != 0)
		{
			field[getTarget()]->setStatus(GROW);
			field[getTarget()]->image = new Sprite(plantList[treeSelected - 1]->getImage(field[getTarget()]->getStatus()), glm::vec2(targetx, targety));
			field[getTarget()]->image->scale(glm::vec2(70));
			field[getTarget()]->life = plantList[treeSelected - 1]->getLifeTime();
			field[getTarget()]->plantID = treeSelected;
			field[getTarget()]->plantTime = (std::clock() - start) / (int)CLOCKS_PER_SEC;
			plantFlag = false;
			cout << plantList[treeSelected - 1]->getImage(field[getTarget()]->getStatus());
		}
		else if (destroyPlantFlag == true)
		{
			field[getTarget()]->setStatus(BLANK);
			field[getTarget()]->image = new Sprite("Images\\plant\\0.png", glm::vec2(targetx, targety));
			field[getTarget()]->image->scale(glm::vec2(70));
			destroyPlantFlag = false;
		}
	}
}

void Game::Draw(ShaderProgram* shader)
{

	//bg
	shader->Send_Mat4("model_matrx", background->transformation());
	background->draw();

	glPointSize(4);
	glBegin(GL_POINT);
	glVertex2f(main->getposition().x, main->getposition().y);
	glEnd();

	//field

	for (auto fieldFrag : field)
	{
		shader->Send_Mat4("model_matrx", fieldFrag->image->transformation());
		fieldFrag->image->draw();
	}

	//sub menu
	for (auto menu : subMenuList)
	{
		if (!subMenuList.empty())
		{
			shader->Send_Mat4("model_matrx", menu.icon->transformation());
			menu.icon->draw();
		}
	}

	//menu
	for (auto menu: menuList)
	{
		shader->Send_Mat4("model_matrx", menu.icon->transformation());
		menu.icon->draw();
	}

	//nv
	shader->Send_Mat4("model_matrx", main->transformation());
	main->draw();

	//mui ten
	if(getTarget() !=-1)
	{
		shader->Send_Mat4("model_matrx", target->transformation());
		target->draw();
	}

	if (selected != nullptr)
	{
		shader->Send_Mat4("model_matrx", selected->transformation());
		selected->draw();
	}
}

void Game::CreatePlantList()
{
	plantList.push_back(new Plants(1, 10, 100, 100,
		"Images\\plant\\1.png",
		"Images\\plant\\1.png",
		"Images\\plant\\1-uong.png",
		"Images\\plant\\1-chin.png"));
	plantList.push_back(new Plants(2, 10, 100, 100,
		"Images\\menu\\2.png",
		"Images\\plant\\2.png",
		"Images\\plant\\2-uong.png",
		"Images\\plant\\2-chin.png"));
	plantList.push_back(new Plants(3, 10, 100, 100,
		"Images\\menu\\3.png",
		"Images\\plant\\3.png",
		"Images\\plant\\3-uong.png",
		"Images\\plant\\3-chin.png"));
	plantList.push_back(new Plants(4, 10, 100, 100,
		"Images\\menu\\4.png",
		"Images\\plant\\4.png",
		"Images\\plant\\4-uong.png",
		"Images\\plant\\4-chin.png"));
	plantList.push_back(new Plants(5, 10, 100, 100,
		"Images\\menu\\5.png",
		"Images\\plant\\5.png",
		"Images\\plant\\5-uong.png",
		"Images\\plant\\5-chin.png"));
	plantList.push_back(new Plants(6, 100, 100, 100,
		"Images\\menu\\6.png",
		"Images\\plant\\6.png",
		"Images\\plant\\6-uong.png",
		"Images\\plant\\6-chin.png"));
	plantList.push_back(new Plants(7, 100, 100, 100,
		"Images\\menu\\7.png",
		"Images\\plant\\7.png",
		"Images\\plant\\7-uong.png",
		"Images\\plant\\7-chin.png"));
	plantList.push_back(new Plants(8, 100, 100, 100,
		"Images\\menu\\8.png",
		"Images\\plant\\8.png",
		"Images\\plant\\8-uong.png",
		"Images\\plant\\8-chin.png"));
	plantList.push_back(new Plants(9, 100, 100, 100,
		"Images\\menu\\9.png",
		"Images\\plant\\9.png",
		"Images\\plant\\9-uong.png",
		"Images\\plant\\9-chin.png"));
	plantList.push_back(new Plants(10, 100, 100, 100,
		"Images\\menu\\10.png",
		"Images\\plant\\10.png",
		"Images\\plant\\10-uong.png",
		"Images\\plant\\10-chin.png"));
	plantList.push_back(new Plants(11, 100, 100, 100,
		"Images\\menu\\11.png",
		"Images\\plant\\11.png",
		"Images\\plant\\11-uong.png",
		"Images\\plant\\11-chin.png"));
}

void Game::LoadSubMenu()
{
	int menux = 150, menuy = 300, menuID = 1;

	for (auto plant:plantList)
	{
		string path = "Images\\menu\\" + to_string(menuID) + ".png";
		subMenuList.push_back(Menu(to_string(menuID), new Sprite(path.c_str(), glm::vec2(menux, menuy))));
		subMenuList[menuID -1].icon->scale(glm::vec2(100));
		if (menuID % 5 != 0)
		{
			menux += 150;
		}
		else
		{
			menux = 150;
			menuy +=150;
		}
		
		menuID++;
	}

	subMenuList.push_back(Menu("0", new Sprite("Images\\menu\\x.png", glm::vec2(menux, menuy))));
	subMenuList[menuID-1].icon->scale(glm::vec2(100));

	clickSubMenu = true;
}

void Game::DesSubMenu()
{
	subMenuList.clear();
}

int Game::getTarget()
{
	float x = 1300, y = 450, tmp = 1;
	for (int i = 0; i < 25; i++)
	{
		int mainx = main->getposition().x, mainy = main->getposition().y;
		if (mainx + 22.5 >= x && mainx + 22.5 <= x + 70)
		{
			if (mainy + 45 >= y && mainy + 45 <= y + 70)
			{
				return i;
			}
		}
		if (tmp < 5)
		{
			x += 70;
			tmp++;
		}
		else
		{
			y += 70;
			x = 1300;
			tmp = 1;
		}
	}
	return -1;
}



