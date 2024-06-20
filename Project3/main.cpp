/*
	﻿Напишіть коротку програму, яка оголошує клас з однією звичайною змінною-членом та однією статичною змінною-членом.
	Створіть конструктор, який виконує ініціалізацію змінної-члена та збільшення статичної змінної-члена.
	Потім оголосіть деструктор, який зменшує на одиницю значення статичної змінної.
*/

#include <iostream>
#include <string>

class myRabbit
{
public:
	myRabbit(std::string name) :name_(name) { ++jumps; }//кролик розпочав свій путь 
	~myRabbit() { --jumps; }//вернувся на 1 шаг назад та на відпочинок
	static int jumps;
	
	void Show() {
		std::cout << "Name Rabbit: " << name_ << std::endl;
		std::cout << "jump" << name_ << " = " << jumps << std::endl;
	}

	static void SpeedRabbit() {//
		jumps += 4;
	}

private:
	std::string name_;
};

int myRabbit::jumps = 0;// початкове місце кролика 

int main()
{
		myRabbit Romchik{ "Romchik" };
		Romchik.Show();

		myRabbit::SpeedRabbit();//Cтатичні методи через познаку області видимості працює 
		Romchik.Show();

	return 0;
}








