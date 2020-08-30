#include "Game.h"

Game::Game()
{
	CreatePlantList();
	
	background = new Sprite("Images\\bg.png",glm::vec2(0));
	background->scale(glm::vec2(2000,2000));

	main = new Sprite("Images\\main.png", glm::vec2(700, 500));
	main->scale(glm::vec2(100));

	wareHouse = new Sprite("Images\\nhakho.png", glm::vec2(800, 450));
	wareHouse->scale(glm::vec2(100));

	float x = 1400, y = 500, tmp = 1;
	for (int i = 0; i < 81; i++)
	{
		field.push_back(new FieldFrag());
		field[i]->plantID = 0;
		field[i]->setStatus(BLANK);
		field[i]->image = new Sprite("Images\\plant\\0.png", glm::vec2(x, y));
		field[i]->image->scale(glm::vec2(70));
		if (tmp < 9)
		{
			x += 45;
			tmp++;
		}
		else
		{
			y += 45;
			x = 1400;
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
			if( main->getposition().x > wareHouse->getposition().x-50 &&  main->getposition().x < wareHouse->getposition().x+80)
			{ 
				if (canMove(main->getposition().x, main->getposition().y, wareHouse->getposition().x+20, wareHouse->getposition().y+30) == true)
				{
					main->move_up(0);
				}
				else
					main->move_up(2);
			}
			else if (main->getposition().y == 450)
				main->move_up(0);
			else
				main->move_up(2);
			break;
		case MOVE_DOWN:
			if (main->getposition().y == 910)
				main->move_right(0);
			else
				main->move_down(2);
			break;
		case MOVE_LEFT:
			if (main->getposition().x > wareHouse->getposition().x  && main->getposition().y < wareHouse->getposition().y+40)
			{
				if (canMove(main->getposition().x, main->getposition().y, wareHouse->getposition().x+30, wareHouse->getposition().y+20) == true)
				{
					main->move_left(0);
				}
				else
					main->move_left(2);
			}
			else if (main->getposition().x<0)
				main->move_left(0);
			else
				main->move_left(2);
			break;
		case MOVE_RIGHT:
			if (main->getposition().x > 1850)
				main->move_right(0);
			else if(main->getposition().x+80 > wareHouse->getposition().x && main->getposition().y+80>wareHouse->getposition().y)
			{
				if (canMove(main->getposition().x, main->getposition().y, wareHouse->getposition().x, wareHouse->getposition().y+20 ) == true)
				{
					main->move_right(0);
				}
				else
					main->move_right(2);
			}
			else
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
			int duration = (std::clock() - i->start) / (int)CLOCKS_PER_SEC;
			cout << duration << endl;
			if (duration >= (i->life / 2) && duration < (i->life) && i->getStatus() != MIDDLE && i->getStatus() != RIPEN)
			{
				i->setStatus(MIDDLE);
				cout << i->getStatus();
				i->image = new Sprite(plantList[i->plantID - 1]->getImage(i->getStatus()), glm::vec2(x, y));
				i->image->scale(glm::vec2(70));
				return;
			}
			else if (duration >= (i->life) && i->getStatus() != RIPEN)
			{
				i->setStatus(RIPEN);
				i->image = new Sprite(plantList[i->plantID - 1]->getImage(i->getStatus()), glm::vec2(x, y));
				i->image->scale(glm::vec2(70));
				return;
			}
		}
	}

	for (auto i : field)
	{
		//x,y
		int x = i->image->getposition().x;
		int y = i->image->getposition().y;
		//
		if (main->getposition().x - x <= 10
			&& main->getposition().y - y <= 10 )
		{
			target = new Sprite("Images\\target.png", glm::vec2(x + 22.5, y + 22.5));
			target->scale(glm::vec2(30));
			if (plantFlag == true && i->isPlanted() == false && treeSelected !=0)
			{
				i->setStatus(GROW);
				i->image =  new Sprite(plantList[treeSelected - 1]->getImage(i->getStatus()), glm::vec2(x, y));
				i->image->scale(glm::vec2(70));
				i->life = plantList[treeSelected - 1]->getLifeTime();
				i->plantID = treeSelected;
				i->start = std::clock(); // counter grown time
				plantFlag = false;
				cout << plantList[treeSelected - 1]->getImage(i->getStatus());
				return;
			}
			else if (destroyPlantFlag == true)
			{
				i->setStatus(BLANK);
				i->image = new Sprite("Images\\plant\\0.png", glm::vec2(x, y));
				i->image->scale(glm::vec2(70));
				destroyPlantFlag = false;
			}
			return;
		}
		else
		{
			target = nullptr;
		}
	}
}

void Game::Draw(ShaderProgram* shader)
{

	//bg
	shader->Send_Mat4("model_matrx", background->transformation());
	background->draw();

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

	//nhakho
	shader->Send_Mat4("model_matrx", wareHouse->transformation());
	wareHouse->draw();

	//mui ten
	if(target != nullptr)
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
		"Images\\plant\\gieohat.png",
		"Images\\plant\\2-uong.png",
		"Images\\plant\\2-chin.png"));
	plantList.push_back(new Plants(3, 10, 100, 100,
		"Images\\menu\\3.png",
		"Images\\plant\\gieohat.png",
		"Images\\plant\\3-uong.png",
		"Images\\plant\\3-chin.png"));
	plantList.push_back(new Plants(4, 10, 100, 100,
		"Images\\menu\\4.png",
		"Images\\plant\\gieohat.png",
		"Images\\plant\\4-uong.png",
		"Images\\plant\\4-chin.png"));
	plantList.push_back(new Plants(5, 10, 100, 100,
		"Images\\menu\\5.png",
		"Images\\plant\\gieohat.png",
		"Images\\plant\\5-uong.png",
		"Images\\plant\\5-chin.png"));
	plantList.push_back(new Plants(6, 100, 100, 100,
		"Images\\menu\\6.png",
		"Images\\plant\\gieohat.png",
		"Images\\plant\\6-uong.png",
		"Images\\plant\\6-chin.png"));
	plantList.push_back(new Plants(7, 100, 100, 100,
		"Images\\menu\\7.png",
		"Images\\plant\\gieohat.png",
		"Images\\plant\\7-uong.png",
		"Images\\plant\\7-chin.png"));
	plantList.push_back(new Plants(8, 100, 100, 100,
		"Images\\menu\\8.png",
		"Images\\plant\\gieohat.png",
		"Images\\plant\\8-uong.png",
		"Images\\plant\\8-chin.png"));
	plantList.push_back(new Plants(9, 100, 100, 100,
		"Images\\menu\\9.png",
		"Images\\plant\\gieohat.png",
		"Images\\plant\\9-uong.png",
		"Images\\plant\\9-chin.png"));
	plantList.push_back(new Plants(10, 100, 100, 100,
		"Images\\menu\\10.png",
		"Images\\plant\\gieohat.png",
		"Images\\plant\\10-uong.png",
		"Images\\plant\\10-chin.png"));
	plantList.push_back(new Plants(11, 100, 100, 100,
		"Images\\menu\\11.png",
		"Images\\plant\\gieohat.png",
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

	subMenuList.push_back(Menu("0", new Sprite("Images\\menu\\quit.png", glm::vec2(menux, menuy))));
	subMenuList[menuID-1].icon->scale(glm::vec2(100));

	clickSubMenu = true;
}

void Game::DesSubMenu()
{
	subMenuList.clear();
}
bool Game::canMove(int a, int b, int x, int y)
{
	if (a-x<=50 && b-y<=50)
	{
		return true;
	}
	else 
		return false;
}

