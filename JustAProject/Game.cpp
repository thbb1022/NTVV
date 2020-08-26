#include "Game.h"

Game::Game()
{
	background = new Sprite("c9ca3d19204877.562d67dc6f516.jpg",glm::vec2(0));
	background->scale(glm::vec2(2000,2000));

	//sun = new Sprite("sun.png",glm::vec2(-50,500));
	//sun->scale(glm::vec2(400));



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

	tree = new Sprite("cay.png", glm::vec2(700, 700));
	tree->scale(glm::vec2(200));

	main = new Sprite("laibuon.gif", glm::vec2(700, 500));
	main->scale(glm::vec2(100));

	//tree->rr(30);







	//planet = new Sprite("planet.png", glm::vec2(1200,250));
	//planet->scale(glm::vec2(200));

	//planet_mask = new Sprite("Mask Right 1.png", glm::vec2(1200,250));
	//planet_mask->scale(glm::vec2(201));


	//planet2 = new Sprite("planet2.png", glm::vec2(1500,500));
	//planet2->scale(glm::vec2(600));

	//enemy = new Sprite("main.png", glm::vec2(700,200));
	//enemy->scale(glm::vec2(50));



	//bullet = new Texture("bullet.png");
}

Game::~Game()
{
	delete target;
	delete background;
	//delete sun;
	//delete planet;
	//delete planet_mask;
	//delete planet2;
	delete main;
}
int i = 1;
void Game::input(vector<Action> actions)
{

	for (auto action : actions)
	{
		switch (action._type)
		{
			case MOVE_UP:
				main->move_up(2);
				//target->move_up(5);
				break;
			case MOVE_DOWN:
				main->move_down(2);
				//target->move_down(5);
				break;
			case MOVE_LEFT:
				main->move_left(2);
				//target->move_left(5);
				break;
			case MOVE_RIGHT:
				main->move_right(2);
				break;
			//case SHOOT:
			//{
			//	//generate rectangles as bullets
			//	Rectangle* rect = new Rectangle();
			//	glm::vec2 pos = main->getposition();
			//	pos += 40;
			//	rect->setposition(pos);
			//	rect->setscale(glm::vec2(20,40));
			//	bullets.push_back(rect);
			//}
			//	break;
			default:
				break;
		}
	}
	//flag = false;
	//for (int i = 0; i < 9; i++)
	//{
	//	if (/*flag == false &&*/ main->getposition().x - dat[i]->getposition().x <= 30
	//		&& main->getposition().y - dat[i]->getposition().y <= 30)
	//	{
	//		//flag = true;
	//		target = new Sprite("down.png", glm::vec2(dat[i]->getposition().x + 55, dat[i]->getposition().y + 50));
	//		target->scale(glm::vec2(30));
	//		return;
	//	}
	//	else
	//	{
	//		//delete target;
	//	}
	//}
}

void Game::Draw(ShaderProgram* shader)
{
	shader->Send_Mat4("model_matrx", background->transformation());
	background->draw();

	/*shader->Send_Mat4("model_matrx", sun->transformation());
	sun->draw();

	shader->Send_Mat4("model_matrx", planet->transformation());
	planet->draw();

	shader->Send_Mat4("model_matrx", planet_mask->transformation());
	planet_mask->draw();

	shader->Send_Mat4("model_matrx", planet2->transformation());
	planet2->draw();*/


	for (int i = 0; i < 81; i++)
	{
		shader->Send_Mat4("model_matrx", dat[i]->transformation());
		dat[i]->draw();
	}


	shader->Send_Mat4("model_matrx", tree->transformation());
	tree->draw();

	shader->Send_Mat4("model_matrx", main->transformation());
	main->draw();


	//if(target->getposition() != glm::vec2(NULL,NULL))
	//{
	//	shader->Send_Mat4("model_matrx", target->transformation());
	//	target->draw();
	//}


	/*shader->Send_Mat4("model_matrx", enemy->transformation());
	enemy->draw()*/;


	//bullet->use();
	//for(size_t i =0; i < bullets.size(); ++i)
	//{
	//	auto tmp = bullets[i]->getposition();
	//	if(tmp.y < -10)
	//	{
	//		delete bullets[i];
	//		bullets.erase(bullets.begin() + i);
	//		continue;
	//	}

	//	tmp.y -= 10;
	//	bullets[i]->setposition(tmp);


	//	shader->Send_Mat4("model_matrx", bullets[i]->GetTransformationMatrx());
	//	bullets[i]->Draw();
	//}
}

void Game::LoadMenu()
{
}
