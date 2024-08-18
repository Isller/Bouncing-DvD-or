#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{

	int currentMessage{ 1 };
	std::vector<std::string> messages
	{
		"Welcome to the \n[Bd,obr\.\.\.owywtctstlliibbifiin,\nbaccutpor-lp(lgocaioc)sawcdit\niaatttc:mosmiagv(ocidnhtrytac\ncuwiavbwisatvi)aiirtb(tp(ip)\notbf)mimitid\.ykiijabm\.\.\.\n(sbtihtwagoyetbicndibm\.\.\.\ntwad\.\.\.)\.]\n\nBasically this is my first C++ \nvisual project using the SFML\nlibrary.\n\n      Press SPACE to continue!",

		"I bet you are wondering what\nis this weird-nonsense\n-disordred-spam of alphabets.\nWell, all that nonsense thing\nis the title of my project,\nwhich stands for:\n\n\n\n\n\n\n\n      Press SPACE to continue!",

		"Look, to be honest, it is such\na big text that will not fit\nin this box, so I will just\nswitch between theboxes for\nthe moment\.\n\n\n\n\n\n\n\n\n        Press SPACE to switch!",

		"It means:\nBouncing DvD, or bouncing rectangle\.\.\. or\nwhatever you want to call that shape that\nlooks like it is bouncing but in fact it is\nnot, because a computer cannot understand the\nprinciples of real-life physics(like gravity\nor collision as in our case) so all we can do\nis to implement an algorithm that tells the\ncomputer: make our shape move in a given\nvelocity(of course i do not have to remind\nyou that a computer cannot understand what is\na velocity but we implement simple algorithms\nto visualize it)\n                     Press SPACE to continue!",
	
		"It means:\nBouncing DvD, or bouncing rectangle\.\.\. or\nwhatever you want to call that shape that\nlooks like it is bouncing but in fact it is\nnot, because a computer cannot understand the\nprinciples of real-life physics(like gravity\nor collision as in our case) so all we can do\nis to implement an algorithm that tells the\ncomputer: make our shape move in a given\nvelocity(of course i do not have to remind\nyou that a computer cannot understand what is\na velocity but we implement simple algorithms\nto visualize it)",

		"and if it reaches the\nboundaries(the position(in\npixels)of that bouncing field)\nmake it move in the inverse\ndirection\.You know it is just\na basic math\.\.\.(so basic that\nI had to watch a guy on\nyoutube explaining this\nbecause I could not do it by\nmyself\.\.\.Tsk what a dumb\.\.\.)\.\n\n\n\n        Press SPACE to return!",

		"okey now that you have\nunderstand almost everything;\nnot everything because you\nstill do not know what is SFML\n\nSFML stands for: Simple and \nFast Multimedia Library\.\n\nNow we can modify things for\nthe sake of our eyes\.\n\n\n\n        Press SPACE to modify!",

		"TADA!!!\n\nThis is the end, that was my\nvery simple project, thank you\nfor your time and it would be\na pleasure for me to hear all\nkinds of critics.\n\nPress ESC to close the program\n\n(or you can just keep staring\nat that shape acting like it\nis bouncing and wait for it to\nhit the perfect angle)"
		};

	// Texts========================
	sf::Font font;
	if (!font.loadFromFile("C:\\Users\\pikai\\source\\repos\\Bouncing_Dvd\\ANDALEMO.TTF"))
		std::cout << "Failed to load font\n";

	sf::Text title;
		title.setFont(font);
		title.setCharacterSize(25);
		std::string Ttitle{ "Bd,obr\.\.\.owywtctstlliibbifiin,baccutpor-lp(lgocaioc)sawcditiaatttc:mosmiagv(ocidnhtry\ntaccuwiavbwisatvi)aiirtb(tp(ip)otbf)mimitid\.ykiijabm\.\.\.(sbtihtwagoyetbicndibm\.\.\.twad\.\.\.)\."};
		title.setString(Ttitle);
		title.setFillColor(sf::Color::White);
		title.setStyle(sf::Text::Bold);
		title.setLetterSpacing(0.3);
		title.setPosition(15, 30);

	
	sf::Text text;
		text.setFont(font);
		text.setString(messages[0]);
		text.setCharacterSize(20);
		text.setStyle(sf::Text::Bold);
		text.setFillColor(sf::Color::White);
		text.setPosition(40, 145);

	sf::Text s_text;
		s_text.setFont(font);
		s_text.setCharacterSize(20);
		s_text.setStyle(sf::Text::Bold);
		s_text.setFillColor(sf::Color(255,255,255));
		s_text.setPosition(480, 143);

	// Bouncing field=================
	sf::RectangleShape shape(sf::Vector2f(600,330));
		shape.setPosition(470, 140);
		shape.setFillColor(sf::Color::Black);
		shape.setOutlineThickness(3);
		shape.setOutlineColor(sf::Color::White);

	// Text field=====================
	sf::RectangleShape txtshape(sf::Vector2f(405,330));
		txtshape.setPosition(30, 140);
		txtshape.setFillColor(sf::Color::Black);
		txtshape.setOutlineThickness(3);
		txtshape.setOutlineColor(sf::Color::White);

	// Bouncing shape===================
	sf::RectangleShape s_bounce(sf::Vector2f(70,71));
	sf::Vector2f s_pos{150,250};
		s_bounce.setPosition(s_pos);
		s_bounce.setFillColor(sf::Color(255,255,255,0));
	sf::RectangleShape bounce(sf::Vector2f(70,70));
		bounce.setFillColor(sf::Color::White);
	sf::Vector2f bouncePos{730,265};

	float xVelocity {2.71};
	float yVelocity {1.9};
	float sxVelocity {2.71};
	float syVelocity {1.9};

	// Window rendering==================
	sf::RenderWindow window(sf::VideoMode(1100,540),"Bouncing DvD, or...");
	window.setFramerateLimit(75);
	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				switch (currentMessage)
				{
					case 1:
					{
						currentMessage++;
						text.setString(messages[1]);
						break;
					}
					case 2:
					{
						currentMessage++;
						text.setString(messages[2]);
						break;
					}
					case 3:
					{
						currentMessage++;
						s_text.setString(messages[3]);
						s_text.setPosition(480, 143);
						text.setFillColor(sf::Color(255,255,255,0));
						bounce.setFillColor(sf::Color(255,255,255,0));
						s_bounce.setFillColor(sf::Color(255,255,255,255));
						break;
					}
					case 4:
					{
						currentMessage++;
						s_text.setString(messages[4]);
						text.setString(messages[5]);
						text.setFillColor(sf::Color(255,255,255));
						s_bounce.setFillColor(sf::Color(255,255,255,0));
						break;
					}
					case 5:
					{
						currentMessage++;
						s_text.setFillColor(sf::Color(255,255,255,0));
						text.setString(messages[6]);
						bounce.setFillColor(sf::Color(255,255,255));
						break;
					}
					case 6:
					{
						currentMessage++;
						title.setString("Bouncing DvD, or\.\.\.");
						title.setCharacterSize(80);
						title.setPosition(27, 20);
						title.setStyle(sf::Text::Bold | sf::Text::Underlined);
						text.setString(messages[7]);
						break;
					}
					default:
						break;
				}
			}
		}

		//physics===================
		if (bouncePos.x < 470 || bouncePos.x > 1000)
		{
		xVelocity *= -1;
		}
		if (bouncePos.y < 140 || bouncePos.y > 400)
		{
		yVelocity *= -1;
		}
		bouncePos.x += xVelocity;
		bouncePos.y += yVelocity;
		bounce.setPosition(bouncePos);
		
		if (s_pos.x < 30 || s_pos.x > 360)
		{
		sxVelocity *= -1;
		}
		if (s_pos.y < 140 || s_pos.y > 400)
		{
		syVelocity *= -1;
		}
		s_pos.x += sxVelocity;
		s_pos.y += syVelocity;
		s_bounce.setPosition(s_pos);
		
		//window drawing==============
		window.clear(sf::Color::Black);
		window.draw(shape);
		window.draw(bounce);
		window.draw(title);
		window.draw(txtshape);
		window.draw(text);
		window.draw(s_text);
		window.draw(s_bounce);
		window.display();
	}

	return 0;
}