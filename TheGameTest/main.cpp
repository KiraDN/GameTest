#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


using namespace std;


const int rows = 10;
const int cols = 10;
const int rowss = 10;
const int colss = 10;
int sapper[rows][cols];
int fields[rowss][colss];

void sapField()
{
	int count = 0;
	srand(time(0));																			// "zerno" dlya randoma
	while (count < 10)
	{

		for (int i = 0; i < rows; i++)														// zapolnenie massiva + random
		{
			for (int j = 0; j < cols; j++)
			{
				int k = rand() % 10;
				if (k == 1 && count < 10)
				{
					sapper[i][j] = 1;
					count++;
				}
				else if (sapper[i][j] != 1) 
				{
					sapper[i][j] = 0;
				}
			}

		}
	}
	for (int i = 0; i < rows; i++)															// vivod massiva v konsol
	{
		for (int j = 0; j < cols; j++)
		{
			cout << sapper[i][j] << "\t";
		}
		cout << endl;
		
	}
	cout << endl;
}
//void field()																				// zakritoe pole
//{
//
//	for (int n = 0; n < rows; n++)														
//	{
//		for (int m = 0; m < cols; m++)
//		{
//			fields[n][m] = 1;
//		}
//	}
//
//	for (int n = 0; n < rows; n++)														
//	{
//		for (int m = 0; m < cols; m++)
//		{
//			cout << fields[n][m] << "\t";
//		}
//		cout << endl;
//	}
//}
int main()
{
	sapField();
	//field();
	sf::RenderWindow window(sf::VideoMode(420, 420), "Mine Sweeper the Game");				// sozdanie okna
	

	sf::Texture mainState, bomb, emptyField, closedBox;										// inicialize texture
	mainState.loadFromFile("mainstate.jpg");
	sf::Sprite mainSprite(mainState);														// sozdanie spraita
	bomb.loadFromFile("mine_boom.jpg");
	sf::Sprite bombSprite(bomb);
	emptyField.loadFromFile("empty_slot.jpg");
	sf::Sprite emptySprite(emptyField);
	closedBox.loadFromFile("closed_box.jpg");
	sf::Sprite closedSprite(closedBox);
			
	while (window.isOpen())																	// cikl raboti okna
	{
		window.clear();																		// Clear screen
		window.draw(mainSprite);															// Draw the sprite

	
		sf::Event event;																	//Process events
		while (window.pollEvent(event))
		{
																							
			if (event.type == sf::Event::Closed)											// Close window: exit
				window.close();
		}
		for (int i = 0; i < rows; i++)														// zapolnenie massiva + random
		{
			for (int j = 0; j < cols; j++)
			{
				sf::Vector2f position(i % 10 * 40 + 10.f, j % 10 * 40 + 10.f);
				
				
				if (sapper[j][i] == 1)
				{
					bombSprite.setPosition(position);
					window.draw(bombSprite);
				}
				else
				{
					emptySprite.setPosition(position);
					window.draw(emptySprite);
				}	
				//window.draw(closedSprite);												// zakritie polya
			}
		}
		/*for (int n = 0; n < rows; n++)
		{
			for (int m = 0; m < cols; m++)
			{
				sf::Vector2f positionn(n % 10 * 40 + 10.f, m % 10 * 40 + 10.f);
				if (fields[n][m] == 1)
				{
					closedSprite.setPosition(positionn);
					window.draw(closedSprite);
				}
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						fields[n][m] = 0;
					}
				}
			}
		}*/
		
		
		
		window.display();																	// Display screen
	}
}