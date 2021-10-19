#include "SFML/Graphics.hpp"
#include<iostream>
#define MAX_NUMBER_OF_ITEMS 5
typedef char option[50];
typedef char p_option[50];
class Menu
{
protected:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::Text text;
    sf::Text t2;
    sf::Sprite *sprite;
    sf::Texture texture;
    sf::RectangleShape *rec;
     float x1=50,x2=-1366;
public:
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem()
	{ return selectedItemIndex; }
    Menu(float width, float height, std::vector<std::string> mainMenu,int a,int b, int x, int y);
	~Menu();
	Menu(){}

};
class patient_menu : public Menu
{
private:
    sf::Text menu[3];

public:
    patient_menu(float width, float height, std::vector<std::string> p_Menu,int a,int b, int i, int j);
    patient_menu(){}
    ~patient_menu(){}
    void p_draw(sf::RenderWindow &window);


};
