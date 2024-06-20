/*
	 Змініть програму з попередньої вправи таким чином, щоб клас Саг теж став ADT,
	 і зробіть від нього три нові класи: SportsCar (Спортивний автомобіль), Wagon (Фургон) та Coupe (Двомісний автомобіль-купе).
	 У класі Car повинна заміщатися одна з віртуальних функцій, оголошених у класі Vehicle, з викликом базового класу.
*/
#include <iostream>
#include <cstring>

class Vehicle
{
public:
	Vehicle() {}
	virtual ~Vehicle() {}
	virtual int GetSpeed()const = 0;
	virtual int GetPlaces()const = 0;
	virtual std::string GetDrive()const = 0;
};

enum DRIVE { FWD, RWD, AWD };//FWD (Front-Wheel Drive), RWD (Rear-Wheel Drive), AWD (All-Wheel Drive)
class Car :public Vehicle
{
public:
	Car(int drive, int places, const char* name);
	virtual~Car();

	virtual void Show()const = 0;
	virtual int GetSpeed()const = 0;
	virtual std::string GetDrive()const;
	virtual int GetPlaces()const { return places_Car; }
	virtual const char* GetName() const { return name_Car ? name_Car : ""; }
private:
	int drive_Car;
	int places_Car;
	char* name_Car;
	int len;//(lenght)
};

Car::Car(int drive, int places, const char* name)
	:drive_Car(drive), places_Car(places), name_Car(nullptr), len(0) {

	if (name != nullptr && std::strlen(name) != 0) {
		size_t lenght = std::strlen(name);
		len = lenght;
		name_Car = new char[lenght + 1];
		strcpy_s(name_Car, lenght + 1, name);
	}

}
std::string Car::GetDrive() const
{
	switch (drive_Car)
	{
	case FWD:
		return "Front-Wheel Drive";
	case RWD:
		return "Rear-Wheel Drive";
	case AWD:
		return "All-Wheel Drive";
	default:
		return "Unknown drive type";
	}
}
Car::~Car() {
	if (name_Car != nullptr) {
		delete[] name_Car;
		name_Car = nullptr;
	}
	len = 0;
}



class SportsCar//(Спортивний автомобіль)
	:public Car
{
public:

	SportsCar(const char* name, int speed, int drive, int places) :Car(drive, places, name), speed_S(speed) {}

	int GetSpeed()const { return speed_S; }

	void Show()const override;

private:
	int speed_S;
};

void SportsCar::Show()const {
	std::cout << "Name sports car: [" << GetName() << "]\n";
	std::cout << "Average speed: [" << GetSpeed() << "]\n";
	std::cout << "drive: ["<<GetDrive()<< "]\n";
	std::cout << "Number of seats in" << GetName() << ": [" << GetPlaces() << "]\n\n";
}



class Wagon//(Фургон)
	:public Car
{
public:

	Wagon(const char* name, int speed, int drive, int places,int load_capacity) :Car(drive, places, name), speed_W(speed), load_capacity_W(load_capacity){}

	int GetSpeed()const { return speed_W; }
	int GetLoad_Capacity()const { return load_capacity_W; }

	void Show()const override;

private:
	int speed_W;
	int load_capacity_W;
};

void Wagon::Show()const {
	std::cout << "Name sports car: [" << GetName() << "]\n";
	std::cout << "Average speed: [" << GetSpeed() << "]\n";
	std::cout << "drive: [" << GetDrive() << "]\n";
	std::cout << "load capacity: [" << GetLoad_Capacity() << "(t.)]\n";
	std::cout << "Number of seats in" << GetName() << ": [" << GetPlaces() << "]\n\n";
}



class Coupe//(Двомісний автомобіль - купе)
	:public Car
{
public:

	Coupe(const char* name, int speed, int drive) :Car(drive, 2, name), speed_C(speed) {}// місць буде 2 за замовчуванням

	int GetSpeed()const { return speed_C; }
	void Show()const override;

private:
	int speed_C;
};

void Coupe::Show()const {
	std::cout << "Name sports car: [" << GetName() << "]\n";
	std::cout << "Average speed: [" << GetSpeed() << "]\n";
	std::cout << "drive: [" << GetDrive() << "]\n";
	std::cout << "Number of seats in" << GetName() << ": [" << GetPlaces() << "]\n\n";
}

int main()
{

	SportsCar scar{ "lamborghini",200,RWD,23 };
	scar.Show();

	Coupe cupe{ "Lanos",90,FWD };
	cupe.Show();
	return 0;
}


