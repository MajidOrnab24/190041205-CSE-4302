#include "menu.h"


 patient_menu::patient_menu(float width, float height, std::vector<std::string> p_Menu,int a,int b, int x, int y)
{


    if (!font.loadFromFile("Fonts/arial.ttf"))
    {
        // handle error
    }
    for(int i=0; i<3; i++)
    {
        menu[i].setFont(font);
        if(i==0)
        {
            menu[i].setColor(sf::Color::Red);
        }
        else
        {
            menu[i].setColor(sf::Color::Yellow);
        }
        menu[i].setString(p_Menu[i]);
        menu[i].setPosition(sf::Vector2f(a+x*i, b+y*i));
    }

}
void patient_menu::p_draw(sf::RenderWindow &window)
{
    sf::RectangleShape rec(sf::Vector2f(1366,768));
    rec.setFillColor(sf::Color::White);
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
               switch (event.key.code)
				{
               case sf::Keyboard::Escape:
                return;
				case sf::Keyboard::Up:
					this->MoveUp();
					break;
				case sf::Keyboard::Down:
					this->MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (this->GetPressedItem())
					{
					case 0:
						std::cout << "1 button has been pressed" << std::endl;
						break;
					case 1:
						std::cout << "2 button has been pressed" << std::endl;
						break;
                    case 2:
						std::cout << "3 button has been pressed" << std::endl;
						break;
					}
					break;
				}
				break;

            }
        }
        window.clear();
        window.draw(rec);
        for (int i = 0; i < 3; i++)
        {
            window.draw(menu[i]);
        }
        window.display();
        // window.draw(sprite);

    }
}
Menu::Menu(float width, float height, std::vector<std::string> mainMenu, int a,int b, int x, int y)
{

    if (!font.loadFromFile("Fonts/arial.ttf"))
    {
        // handle error
    }
    for(int i=0; i<MAX_NUMBER_OF_ITEMS; i++)
    {
        menu[i].setFont(font);
        if(i==0)
        {
            menu[i].setColor(sf::Color::Red);
        }
        else
        {
            menu[i].setColor(sf::Color::Yellow);
        }
        menu[i].setString(mainMenu[i]);
        menu[i].setPosition(sf::Vector2f(a+x*i, b+y*i));
    }
    selectedItemIndex = 0;
    text.setFont(font);
    text.setString("Hospital Management System");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Blue);
    text.setOutlineColor(sf::Color::White);
    text.setOutlineThickness(5);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    t2.setFont(font);
    t2.setString("Hospital Management System");
    t2.setCharacterSize(50);
    t2.setFillColor(sf::Color::Blue);
    t2.setOutlineColor(sf::Color::White);
    t2.setOutlineThickness(5);
    t2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    texture.loadFromFile("texture.png");
    sprite = new sf::Sprite(texture);
    rec = new sf::RectangleShape(sf::Vector2f(1366,768));
    sprite->setScale(1/2.f,1/2.f);
    sprite->setPosition(sf::Vector2f(75,100));
    rec->setFillColor(sf::Color::White);
}
Menu::~Menu()
{
}
void Menu::draw(sf::RenderWindow &window)
{


    text.setPosition(this->x1,35);
    t2.setPosition(this->x2,35);
    if(this->x1>1366)
    {
        this->x1 = -1366.0f;
    }
    if(x2>1366)
    {
        this->x2 = -1366.0f;
    }
    this->x1+=1;
    this->x2+=1;
    window.draw(*rec);
    window.draw(*sprite);
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
    window.draw(text);
    window.draw(t2);
}
void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setColor(sf::Color::Yellow);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}
void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setColor(sf::Color::Yellow);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}
