#pragma once
#include "lib.h"
#include "Sprite.h"

struct Character
{
	char name;
	const char* imagePath;
	Character(char _name, const char* _imagePath) : name(_name), imagePath(_imagePath) {}
};

class Text
{
public:
	Text(string text, glm::vec2 positon, glm::vec2 scale);
	~Text();
	vector<Sprite*> charImgList;

private:
	vector<Character> characters;
	void LoadTextSource();
};