#include <SFML/Graphics.hpp>
#include<iostream>
#include"menu.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 768), "Hospital Management System");
    std::vector<std::string> mainMenu {    "PATIENT ","DOCTOR","LAB REPORT","HELP","EXIT"};
    std::vector<std::string> p_Menu {    "TAKE A APPOINTMENT ","TAKE A ADMISSION","LAB TEST","HELP","EXIT"};
     Menu menu(window.getSize().x, window.getSize().y,mainMenu,1100,130,0,70);
     patient_menu Pmenu(window.getSize().x, window.getSize().y,p_Menu,400,130,0,70);
     sf::Font font;
     if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		// handle error
	}
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;
				case sf::Keyboard::Down:
					menu.MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "patirnt button has been pressed" << std::endl;
                        Pmenu.p_draw(window);
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						break;
                    case 2:
						std::cout << "lab button has been pressed" << std::endl;
						break;
                    case 3:
						std::cout << "help button has been pressed" << std::endl;
						break;
					case 4:
						window.close();
						break;
					}
					break;
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		window.clear();
		menu.draw(window);
		window.display();
	}


}


