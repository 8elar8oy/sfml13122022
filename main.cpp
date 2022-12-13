#include "settings.h"
#include "functions.h"
using namespace sf;

int main()
{

	srand(time(nullptr));

	
	// Объект, который, собственно, является главным окном приложения

	RenderWindow window(VideoMode(length, width), "SFML Works!");
	window.setFramerateLimit(60);
	Texture textur;
	textur.loadFromFile("futbl.jpg");
	Texture textur1;
	textur1.loadFromFile("setka.png");
	//шарик
	CircleShape ball;
	{
		initBall(ball, ballStartPos);
	}

	float arr_speed[]{ -5.f,5.f };
	int index = rand() % 2;
	float ball_speedx = arr_speed[index];
	index = rand() % 2;
	float ball_speedy = arr_speed[index];
	//поле футбольное
	RectangleShape pl(Vector2f(800, 600));
	pl.setTexture(&textur);
	//ракетки
	RectangleShape leftbat, rightbat;
	{
		initBat(leftbat, batcolor1, leftBatStartPos);
		initBat(rightbat, batcolor1, rightBatStartPos);
	}
	float leftBаtSpeedY = 0.f;
	float rightBаtSpeedY = 0.f;
	//счет
	int LeftPlayerScore = 0;
	int RightPlayerScore = 0;
	Font font;
	font.loadFromFile("ds-digib.ttf");
	Text LeftPlayerScoreText;
	LeftPlayerScoreText.setString(std::to_string(LeftPlayerScore));
	LeftPlayerScoreText.setFont(font);
	initScore(LeftPlayerScoreText, leftScorePos);
	
	Text RightPlayerScoreText;
	RightPlayerScoreText.setString(std::to_string(RightPlayerScore));
	RightPlayerScoreText.setFont(font);
	initScore(RightPlayerScoreText, rightScorePos);
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		//проверка нажатий клавиш
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			leftBаtSpeedY = -batSpeed;
			if (leftbat.getPosition().y <= 0)
			{
				leftbat.setPosition(otstup, 0);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			leftBаtSpeedY = batSpeed;
			if (leftbat.getPosition().y >= (width - 80))
			{
				leftbat.setPosition(otstup, width - 80);
			}
		}
		leftbat.move(0, leftBаtSpeedY);
		leftBаtSpeedY = 0.f;
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			rightBаtSpeedY = -batSpeed;
			if (rightbat.getPosition().y <= 0)
			{
				rightbat.setPosition(length - otstup - 20, 0);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			rightBаtSpeedY = batSpeed;
			if (rightbat.getPosition().y >= (width - 80))
			{
				rightbat.setPosition(length - otstup - 20, width - 80);
			}
		}
		rightbat.move(0, rightBаtSpeedY);
		rightBаtSpeedY = 0.f;
		// движение шарика
		ball.move(ball_speedx, ball_speedy);
		if (ball.getPosition().x <= 0) {
			ball_speedx = -ball_speedx;
			RightPlayerScore++;
			RightPlayerScoreText.setString(std::to_string(RightPlayerScore));
		}
		if (ball.getPosition().x >= (length - 2 * ballradius)) {
			ball_speedx = -ball_speedx;
			LeftPlayerScore++;
			LeftPlayerScoreText.setString(std::to_string(LeftPlayerScore));
		}
		if (ball.getPosition().y <= 0 || ball.getPosition().y >= (width - 2 * ballradius))
		{
			ball_speedy = -ball_speedy;
		}
		float midLeftX = ball.getPosition().x;
		float midLeftY = ball.getPosition().y + ballradius;
		float midRightX = ball.getPosition().x + 2 * ballradius;
		float midRightY = ball.getPosition().y + ballradius;
		float midUpX = ball.getPosition().x + ballradius;
		float midUpY = ball.getPosition().y;
		float midDownX = ball.getPosition().x + ballradius;
		float midDownY = ball.getPosition().y + 2 * ballradius;
		//левая ракетка
		if ((leftbat.getPosition().x <= midLeftX) && (midLeftX <= (leftbat.getPosition().x + length_bat)) && (leftbat.getPosition().y <= midLeftY) && (midLeftY <= leftbat.getPosition().y + width_bat))
		{
			ball_speedx = -ball_speedx;

		}
		if ((leftbat.getPosition().x <= midRightX) && (midRightX <= (leftbat.getPosition().x + length_bat)) && (leftbat.getPosition().y <= midRightY) && (midRightY <= leftbat.getPosition().y + width_bat))
		{
			ball_speedx = -ball_speedx;
		}
		if ((leftbat.getPosition().x <= midUpX) && (midUpX <= (leftbat.getPosition().x + length_bat)) && (leftbat.getPosition().y <= midUpY) && (midUpY <= leftbat.getPosition().y + width_bat))
		{
			if (ball_speedy < 0) {
				ball_speedy = -ball_speedy;
			}
		}
		if ((leftbat.getPosition().x <= midDownX) && (midDownX <= (leftbat.getPosition().x + length_bat)) && (leftbat.getPosition().y >= midDownY) && (midDownY > leftbat.getPosition().y - 1))
		{
			if (ball_speedy > 0) {
				ball_speedy = -ball_speedy;
			}
		}
		//правая ракетка
		if ((rightbat.getPosition().x <= midLeftX) && (midLeftX <= (rightbat.getPosition().x + length_bat)) && (rightbat.getPosition().y <= midLeftY) && (midLeftY <= rightbat.getPosition().y + width_bat))
		{
			ball_speedx = -ball_speedx;

		}
		if ((rightbat.getPosition().x <= midRightX) && (midRightX <= (rightbat.getPosition().x + length_bat)) && (rightbat.getPosition().y <= midRightY) && (midRightY <= rightbat.getPosition().y + width_bat))
		{
			ball_speedx = -ball_speedx;
		}
		if ((rightbat.getPosition().x <= midUpX) && (midUpX <= (rightbat.getPosition().x + length_bat)) && (rightbat.getPosition().y <= midUpY) && (midUpY <= rightbat.getPosition().y + width_bat))
		{
			if (ball_speedy < 0) {
				ball_speedy = -ball_speedy;
			}
		}
		if ((rightbat.getPosition().x <= midDownX) && (midDownX <= (rightbat.getPosition().x + length_bat)) && (rightbat.getPosition().y <= midDownY) && (midDownY <= rightbat.getPosition().y + width_bat))
		{
			if (ball_speedy > 0) {
				ball_speedy = -ball_speedy;
			}
		}
		//отрисовка обьектов
		window.clear(Color::Black);
		window.draw(pl);
		window.draw(leftbat);
		window.draw(rightbat);
		window.draw(ball);
		window.draw(LeftPlayerScoreText);
		window.draw(RightPlayerScoreText);
		window.display();
	}
	return 0;
}