#include "Game.h"

Game::Game()
{
	CreatePlantList();
	start = std::clock(); 

	background = new Sprite("Images\\bg.png",glm::vec2(0));
	background->scale(glm::vec2(2000,2000));

	main = new Sprite("Images\\laibuon.png", glm::vec2(700, 500));
	main->scale(glm::vec2(100));

	float x = 1300, y = 550, tmp = 1;
	for (int i = 0; i < 25; i++)
	{
		field.push_back(new FieldFrag());
		field[i]->plantID = 0;
		field[i]->setStatus(BLANK);
		field[i]->image = new Sprite("Images\\plant\\0.png", glm::vec2(x, y));
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
	clickWHMenu = false;
	clickSubMenu = false;
	int menux = 50, menuy = 300;
	for (int i = 0; i < 3;i++)
	{
		string path = "Images\\menu\\menu" + to_string(i+1) + ".png";
		menuList.push_back(Menu(to_string(i+1), new Sprite(path.c_str(), glm::vec2(menux, menuy))));
		menuList[i].icon->scale(glm::vec2(100));
		menuy += 150;
	}
	wareHouse = new Sprite("Images\\nhakho.png", glm::vec2(850, 400));
	wareHouse->scale(glm::vec2(200));

	whmenu = new Sprite("Images\\menu\\background_menu.png", glm::vec2(400, 380));
	whmenu->scale(glm::vec2(740, 450));
	openEnventory = false;	
	
	Text *text = new Text("A    BC!  z", glm::vec2(300, 300), glm::vec2(50));
	textImg = text->charImgList;
}

Game::~Game()
{
	delete target;
	delete background;
	delete main;
	delete selected;
	delete whmenu;
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
	bool whFlag = false, SellFlag = false, seFlag = false;
	for (auto action : actions)
	{
		switch (action._type)
		{
		case MOVE_UP:
			if (main->getposition().x >= wareHouse->getposition().x - 50 && main->getposition().x <= wareHouse->getposition().x + 150)
			{
				if (through(main->getposition().x, main->getposition().y, wareHouse->getposition().x + 100, wareHouse->getposition().y + 150))
					main->move_up(0);
				else
					main->move_up(2);
			}
			else if (main->getposition().y <470)
				main->move_up(0);
			else
				main->move_up(2);
			break;
		case MOVE_DOWN:
			if (main->getposition().y >= 920)
				main->move_down(0);
			else
				main->move_down(2);
			break;
		case MOVE_LEFT:
			if (main->getposition().x >= wareHouse->getposition().x - 30 && main->getposition().x <= wareHouse->getposition().x + 180)
			{
				if (through(main->getposition().x, main->getposition().y, wareHouse->getposition().x + 150, wareHouse->getposition().y + 100))
					main->move_left(0);
				else
					main->move_left(2);
			}
			else if (main->getposition().x <= 0)
				main->move_left(0);
			else
				main->move_left(2);
			break;
		case MOVE_RIGHT:
			if (main->getposition().x + 80 >= wareHouse->getposition().x && main->getposition().x <= wareHouse->getposition().x + 150)
			{
				if (through(main->getposition().x, main->getposition().y, wareHouse->getposition().x, wareHouse->getposition().y + 100))
					main->move_right(0);
				else
					main->move_right(2);
			}
			else if (main->getposition().x >= 1850)
				main->move_left(0);
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
		case SELECTWAREHOUSE1:
			if (clickWHMenu == true)
			{
				if (rice != 0)
				{
					sellSelected = 1;
					seFlag = true;
				}
			}
			break;
		case SELECTWAREHOUSE2:
			if (clickWHMenu == true)
			{
				if (tomato != 0)
				{
					sellSelected = 2;
					seFlag = true;
				}
			}
			break;
		case SELECTWAREHOUSE3:
			if (clickWHMenu == true)
			{
				if (carot != 0)
				{
					sellSelected = 3;
					seFlag = true;
				}
			}
			break;
		case SELECTWAREHOUSE4:
			if (clickWHMenu == true)
			{
				if (pineApple != 0)
				{
					sellSelected = 4;
					seFlag = true;
				}
			}
			break;
		case SELECTWAREHOUSE5:
			if (clickWHMenu == true)
			{
				if (waterMelon != 0)
				{
					sellSelected = 5;
					seFlag = true;
				}
			}
			break;
		case SELECTWAREHOUSE6:
			if (clickWHMenu == true)
			{
				if (grape != 0)
				{
					sellSelected = 6;
					seFlag = true;
				}
			}
			break;
		case SELECTWAREHOUSE7:
			if (clickWHMenu == true)
			{
				if (rose != 0)
				{
					sellSelected = 7;
					seFlag = true;
				}
			}
			break;
		case SELECTWAREHOUSE8:
			if (clickWHMenu == true)
			{
				if (mango != 0)
				{
					sellSelected = 8;
					seFlag = true;
				}
			}
			break;
		case SELECTWAREHOUSE9:
			if (clickWHMenu == true)
			{
				if (dragonFruit != 0)
				{
					sellSelected = 9;
					seFlag = true;
				}
			}
			break;
		case SELECTWAREHOUSE10:
			if (clickWHMenu == true)
			{
				if (sunFlower != 0)
				{
					sellSelected = 10;
					seFlag = true;
				}
			}
			break;
		case SELECTWAREHOUSE11:
			if (clickWHMenu == true)
			{
				if (tulip != 0)
				{
					sellSelected = 11;
					seFlag = true;
				}
			}
			break;
		case QUITWAREHOUSE:
			if (clickWHMenu == true)
			{
				sellSelected = 0;
				SellFlag = true;
				DesWHMenu();
				openEnventory = false;
			}
			break;
		case PLANT:
			plantFlag = true;
			break;
		case WAREHOUSE:
			whFlag = true;
			break;
		case SELL:
			SellFlag = true;
			break;
		default:
			break;
		}
	}

	if (treeSelected != 0 && slFlag)
	{
		/*cout << treeSelected;*/
		select = subMenuList[treeSelected - 1].icon->getposition();
		selected = new Sprite("Images\\menu\\selected.png", select);
		selected->scale(glm::vec2(110));
		slFlag = false;
	}
	if (sellSelected != 0 && seFlag)
	{
		/*cout << treeSelected;*/
		select = WHMenuList[sellSelected - 1].icon->getposition();
		selected = new Sprite("Images\\menu\\selected.png", select);
		selected->scale(glm::vec2(110));
		slFlag = false;
	}
	if (SellFlag == true && sellSelected != 0)
	{
		cout << Sell(sellSelected);
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
			/*cout << duration << endl;*/
			if (duration- (i->plantTime) == (i->life / 2) /*&& duration - (i->plantTime) < (i->life)*/ && i->getStatus() != MIDDLE && i->getStatus() != RIPEN)
			{
				i->setStatus(MIDDLE);
				/*cout << i->getStatus();*/
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
		if (main->getposition().x >= wareHouse->getposition().x - 50 && main->getposition().x <= wareHouse->getposition().x + 150)
		{
			if (through(main->getposition().x, main->getposition().y, wareHouse->getposition().x + 100, wareHouse->getposition().y + 150))
			{
				target = new Sprite("Images\\target.png", glm::vec2(wareHouse->getposition().x + 80, wareHouse->getposition().y + 150));
				target->scale(glm::vec2(50));
				if (whFlag == true)
				{
					openEnventory = true;
					LoadWHMenu();

					select = menuList[0].icon->getposition();
					selected = new Sprite("Images\\menu\\selected.png", glm::vec2(400, 400));
					selected->scale(glm::vec2(110));
				}
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
			/*cout << plantList[treeSelected - 1]->getImage(field[getTarget()]->getStatus());*/
		}
		else if (destroyPlantFlag == true)
		{
			field[getTarget()]->setStatus(BLANK);
			field[getTarget()]->image = new Sprite("Images\\plant\\0.png", glm::vec2(targetx, targety));
			field[getTarget()]->image->scale(glm::vec2(70));
			destroyPlantFlag = false;
		}
		else if (plantFlag == true && field[getTarget()]->isRipen() == false)
		{
			plantFlag = false;
			field[getTarget()]->image = new Sprite("Images\\plant\\0.png", glm::vec2(targetx, targety));
			field[getTarget()]->image->scale(glm::vec2(70));
			field[getTarget()]->setStatus(BLANK);
			cropTree(plantList[field[getTarget()]->plantID]->getId() - 1);
			
		}
	}
}


void Game::Draw(ShaderProgram* shader)
{

	//bg
	shader->Send_Mat4("model_matrx", background->transformation());
	background->draw();

	
	//main
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
	//nhakho
	shader->Send_Mat4("model_matrx", wareHouse->transformation());
	wareHouse->draw();

	//mtnhakho
	if (main->getposition().x >= wareHouse->getposition().x - 50 && main->getposition().x <= wareHouse->getposition().x + 150)
	{
		if (through(main->getposition().x, main->getposition().y, wareHouse->getposition().x + 100, wareHouse->getposition().y + 150))
		{
			shader->Send_Mat4("model_matrx", target->transformation());
			target->draw();

		}
	}

	if (openEnventory == true)
	{
		shader->Send_Mat4("model_matrx", whmenu->transformation());
		whmenu->draw();
	}
	//menuKho
	for (auto menu : WHMenuList)
	{
		shader->Send_Mat4("model_matrx", menu.icon->transformation());
		menu.icon->draw();
	}

	//text 
	for (auto item : textImg)
	{
		shader->Send_Mat4("model_matrx", item->transformation());
		item->draw();
	}

	
	////menuKho
	//for (auto menu : WHQuantity)
	//{
	//	shader->Send_Mat4("model_matrx", menu.icon->transformation());
	//	menu.icon->draw();
	//}
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
		"Images\\plant\\mam.png",
		"Images\\plant\\2-chin.png"));
	plantList.push_back(new Plants(3, 10, 100, 100,
		"Images\\menu\\3.png",
		"Images\\plant\\gieohat.png",
		"Images\\plant\\mam.png",
		"Images\\plant\\3-chin.png"));
	plantList.push_back(new Plants(4, 10, 100, 100,
		"Images\\menu\\4.png",
		"Images\\plant\\gieohat.png",
		"Images\\plant\\mam.png",
		"Images\\plant\\4-chin.png"));
	plantList.push_back(new Plants(5, 10, 100, 100,
		"Images\\menu\\5.png",
		"Images\\plant\\gieohat.png",
		"Images\\plant\\mam.png",
		"Images\\plant\\5-chin.png"));
	plantList.push_back(new Plants(6, 100, 100, 100,
		"Images\\menu\\6.png",
		"Images\\plant\\gieohat.png",
		"Images\\plant\\mam.png",
		"Images\\plant\\6-chin.png"));
	plantList.push_back(new Plants(7, 100, 100, 100,
		"Images\\menu\\7.png",
		"Images\\plant\\gieohat.png",
		"Images\\plant\\mam.png",
		"Images\\plant\\7-chin.png"));
	plantList.push_back(new Plants(8, 100, 100, 100,
		"Images\\menu\\8.png",
		"Images\\plant\\gieohat.png",
		"Images\\plant\\mam.png",
		"Images\\plant\\8-chin.png"));
	plantList.push_back(new Plants(9, 100, 100, 100,
		"Images\\menu\\9.png",
		"Images\\plant\\gieohat.png",
		"Images\\plant\\mam.png",
		"Images\\plant\\9-chin.png"));
	plantList.push_back(new Plants(10, 100, 100, 100,
		"Images\\menu\\10.png",
		"Images\\plant\\gieohat.png",
		"Images\\plant\\mam.png",
		"Images\\plant\\10-chin.png"));
	plantList.push_back(new Plants(11, 100, 100, 100,
		"Images\\menu\\11.png",
		"Images\\plant\\gieohat.png",
		"Images\\plant\\mam.png",
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

void Game::LoadWHMenu()
{

	int menux = 400, menuy = 400, menuID = 1;

	for (menuID = 1; menuID<12; menuID++)
	{
		string path = "Images\\menu\\" + to_string(menuID) + ".png";
		WHMenuList.push_back(Menu(to_string(menuID), new Sprite(path.c_str(), glm::vec2(menux, menuy))));
		WHMenuList[menuID - 1].icon->scale(glm::vec2(100));
		//WHQuantity.push_back(Menu(to_string(menuID), new Sprite("Images\\Soluong\\0.png", glm::vec2(menux, menuy + 100))));
		//WHQuantity[menuID - 1].icon->scale(glm::vec2(10));
		if (menuID % 5 != 0)
		{
			menux += 150;
		}
		else
		{
			menux = 400;
			menuy += 150;
		}
		
	}
	
	WHMenuList.push_back(Menu("0", new Sprite("Images\\menu\\x.png", glm::vec2(menux, menuy))));
	WHMenuList[menuID - 1].icon->scale(glm::vec2(100));

	clickWHMenu = true;
}

void Game::DesSubMenu()
{
	subMenuList.clear();
}

void Game::DesWHMenu()
{
	WHMenuList.clear();
}

int Game::getTarget()
{
	float x = 1300, y = 550, tmp = 1;
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

bool Game::through(int x, int y, int a, int b)
{
	if (x - a <= 50 && y - b <= 50)
	{
		return true;
	}
	return false;
}

int Game::cropTree(int x)
{
	if (x == 1)
		return  rice += plantList[1]->getQuanity();
	else if (x == 2)
		return  tomato += plantList[2]->getQuanity();
	else if (x == 3)
		return  carot += plantList[3]->getQuanity();
	else if (x == 4)
		return  pineApple += plantList[4]->getQuanity();
	else if (x == 5)
		return  waterMelon += plantList[5]->getQuanity();
	else if (x == 6)
		return  grape += plantList[6]->getQuanity();
	else if (x == 7)
		return  rose += plantList[7]->getQuanity();
	else if (x == 8)
		return  mango += plantList[8]->getQuanity();
	else if (x == 9)
		return  dragonFruit += plantList[9]->getQuanity();
	else if (x == 10)
		return  sunFlower += plantList[10]->getQuanity();
	else if (x == 11)
		return  tulip += plantList[11]->getQuanity();
}

int Game::Sell(int x)
{
	if (x == 1)
		return  rice * plantList[1]->getPrice();
	else if (x == 2)
		return  tomato* plantList[2]->getPrice();
	else if (x == 3)
		return  carot* plantList[3]->getPrice();
	else if (x == 4)
		return  pineApple* plantList[4]->getPrice();
	else if (x == 5)
		return  waterMelon* plantList[5]->getPrice();
	else if (x == 6)
		return  grape* plantList[6]->getPrice();
	else if (x == 7)
		return  rose* plantList[7]->getPrice();
	else if (x == 8)
		return  mango* plantList[8]->getPrice();
	else if (x == 9)
		return  dragonFruit* plantList[9]->getPrice();
	else if (x == 10)
		return  sunFlower* plantList[10]->getPrice();
	else if (x == 11)
		return  tulip* plantList[11]->getPrice();
}

