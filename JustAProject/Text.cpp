#include "Text.h"

Text::Text(string text, glm::vec2 positon, glm::vec2 scale)
{
	LoadTextSource();
	for (int i = 0; i < text.length(); i++)
	{
		char tmp = text.at(i);
		cout << tmp;
		for (auto item : characters)
		{
			if (item.name == tmp)
			{
				charImgList.push_back(new Sprite(item.imagePath, positon));
				charImgList[i]->scale(scale);
				positon.x += 0.5 * scale.x;
				break;
			}
		}
	}
}

Text::~Text()
{
	for (auto item : charImgList)
	{
		delete item;
	}
}

void Text::LoadTextSource()
{
	characters = {
		Character(' ', "Images\\Text\\tile000.png"),
		Character('!', "Images\\Text\\tile001.png"),
		Character('\"', "Images\\Text\\tile002.png"),
		Character('#', "Images\\Text\\tile003.png"),
		Character('$', "Images\\Text\\tile004.png"),
		Character('%', "Images\\Text\\tile005.png"),
		Character('&', "Images\\Text\\tile006.png"),
		Character('\'', "Images\\Text\\tile007.png"),
		Character('(', "Images\\Text\\tile008.png"),
		Character(')', "Images\\Text\\tile009.png"),
		Character('*', "Images\\Text\\tile010.png"),
		Character('+', "Images\\Text\\tile011.png"),
		Character(',', "Images\\Text\\tile012.png"),
		Character('-', "Images\\Text\\tile013.png"),
		Character('.', "Images\\Text\\tile014.png"),
		Character('/', "Images\\Text\\tile015.png"),
		Character('0', "Images\\Text\\tile016.png"),
		Character('1', "Images\\Text\\tile017.png"),
		Character('2', "Images\\Text\\tile018.png"),
		Character('3', "Images\\Text\\tile019.png"),
		Character('4', "Images\\Text\\tile020.png"),
		Character('5', "Images\\Text\\tile021.png"),
		Character('6', "Images\\Text\\tile022.png"),
		Character('7', "Images\\Text\\tile023.png"),
		Character('8', "Images\\Text\\tile024.png"),
		Character('9', "Images\\Text\\tile025.png"),
		Character(':', "Images\\Text\\tile026.png"),
		Character(';', "Images\\Text\\tile027.png"),
		Character('<', "Images\\Text\\tile028.png"),
		Character('=', "Images\\Text\\tile029.png"),
		Character('>', "Images\\Text\\tile030.png"),
		Character('\?', "Images\\Text\\tile031.png"),
		Character('@', "Images\\Text\\tile032.png"),
		Character('A', "Images\\Text\\tile033.png"),
		Character('B', "Images\\Text\\tile034.png"),
		Character('C', "Images\\Text\\tile035.png"),
		Character('D', "Images\\Text\\tile036.png"),
		Character('E', "Images\\Text\\tile037.png"),
		Character('F', "Images\\Text\\tile038.png"),
		Character('G', "Images\\Text\\tile039.png"),
		Character('H', "Images\\Text\\tile040.png"),
		Character('I', "Images\\Text\\tile041.png"),
		Character('J', "Images\\Text\\tile042.png"),
		Character('K', "Images\\Text\\tile043.png"),
		Character('L', "Images\\Text\\tile044.png"),
		Character('M', "Images\\Text\\tile045.png"),
		Character('N', "Images\\Text\\tile046.png"),
		Character('O', "Images\\Text\\tile047.png"),
		Character('P', "Images\\Text\\tile048.png"),
		Character('Q', "Images\\Text\\tile049.png"),
		Character('R', "Images\\Text\\tile050.png"),
		Character('S', "Images\\Text\\tile051.png"),
		Character('T', "Images\\Text\\tile052.png"),
		Character('U', "Images\\Text\\tile053.png"),
		Character('V', "Images\\Text\\tile054.png"),
		Character('W', "Images\\Text\\tile055.png"),
		Character('S', "Images\\Text\\tile056.png"),
		Character('Y', "Images\\Text\\tile057.png"),
		Character('Z', "Images\\Text\\tile058.png"),
		Character('[', "Images\\Text\\tile059.png"),
		Character('\\', "Images\\Text\\tile060.png"),
		Character(']', "Images\\Text\\tile061.png"),
		Character('^', "Images\\Text\\tile062.png"),
		Character('_', "Images\\Text\\tile063.png"),
		Character('`', "Images\\Text\\tile064.png"),
		Character('a', "Images\\Text\\tile065.png"),
		Character('b', "Images\\Text\\tile066.png"),
		Character('c', "Images\\Text\\tile067.png"),
		Character('d', "Images\\Text\\tile068.png"),
		Character('e', "Images\\Text\\tile069.png"),
		Character('f', "Images\\Text\\tile070.png"),
		Character('g', "Images\\Text\\tile071.png"),
		Character('h', "Images\\Text\\tile072.png"),
		Character('i', "Images\\Text\\tile073.png"),
		Character('j', "Images\\Text\\tile074.png"),
		Character('k', "Images\\Text\\tile075.png"),
		Character('l', "Images\\Text\\tile076.png"),
		Character('m', "Images\\Text\\tile077.png"),
		Character('n', "Images\\Text\\tile078.png"),
		Character('o', "Images\\Text\\tile079.png"),
		Character('p', "Images\\Text\\tile080.png"),
		Character('q', "Images\\Text\\tile081.png"),
		Character('r', "Images\\Text\\tile082.png"),
		Character('s', "Images\\Text\\tile083.png"),
		Character('t', "Images\\Text\\tile084.png"),
		Character('u', "Images\\Text\\tile085.png"),
		Character('v', "Images\\Text\\tile086.png"),
		Character('w', "Images\\Text\\tile087.png"),
		Character('x', "Images\\Text\\tile088.png"),
		Character('y', "Images\\Text\\tile089.png"),
		Character('z', "Images\\Text\\tile090.png"),
		Character('{', "Images\\Text\\tile091.png"),
		Character('|', "Images\\Text\\tile092.png"),
		Character('}', "Images\\Text\\tile093.png"),
		Character('~', "Images\\Text\\tile094.png")
	};
}
