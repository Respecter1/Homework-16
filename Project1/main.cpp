/*
	Напишіть програму, яка виробляє класи Саг (Легковий автомобіль) та Bus (Автобус) від класу Vehicle (Машина).
	Опишіть клас Vehicle як абстрактний тип даних із двома чистими віртуальними функціями. Класи Саг та Bus не повинні бути абстрактними.
*/

#include <iostream>

class Vehicle
{
public:
	Vehicle() {}
	virtual ~Vehicle() {}
	virtual int GetSpeed()const = 0;
	virtual int GetPlaces()const = 0;
	virtual void Show()const = 0;
};

class Car :public Vehicle
{
public:
	Car(int speed, int places, const char* name);
	~Car();

	int GetSpeed()const { return speed_Car; }
	int GetPlaces()const { return places_Car; }
	const char* GetName() const { return name_Car ? name_Car : ""; }
	virtual void Show()const override {
		std::cout << "Name car: " << GetName() << std::endl;
		std::cout << "Average speed car: " << GetSpeed() << std::endl;
		std::cout << "The number of people who will fit in the car :" << GetPlaces() << "\n\n";
	}
private:
	int speed_Car;
	int places_Car;
	char* name_Car;
	int len;//(lenght)
};

Car::Car(int speed, int places, const char* name)
	:speed_Car(speed), places_Car(places), name_Car(nullptr), len(0)
{

		if (name != nullptr && std::strlen(name) != 0)
		{
			size_t lenght = std::strlen(name);
			len = lenght;
			name_Car = new char[lenght + 1];
			strcpy_s(name_Car, lenght + 1, name);
		}
}

Car::~Car() {
	if (name_Car != nullptr) {
		delete[] name_Car;
		name_Car = nullptr;
	}
	len = 0;
}

class Bus :public Vehicle
{
public:
	Bus(int speed, int places, const char* name);
	~Bus();

	int GetSpeed()const { return speed_; }
	int GetPlaces()const { return places_; }
	const char* GetName() const { return name_ ? name_ : ""; }
	virtual void Show()const override {
		std::cout <<"Name bus: " << GetName() << std::endl;
		std::cout << "Average speed car: " << GetSpeed() << std::endl;
		std::cout << "The number of people who will fit in the bus :" << GetPlaces() << "\n\n";
	}
private:
	int speed_;
	int places_;
	char* name_;
	int len;
};

Bus::Bus(int speed, int places, const char* name)
	:speed_(speed), places_(places), name_(nullptr), len(0)
{
	if (name != nullptr && std::strlen(name) != 0)
	{
		size_t lenght = std::strlen(name);
		len = lenght;
		name_ = new char[lenght + 1];
		strcpy_s(name_, lenght + 1, name);//strcpy_s є більш безпечною версією strcpy, оскільки вона перевіряє переповнення буфера.
	}
}

Bus::~Bus() {
	if (name_ != nullptr) {
		delete[] name_;
		name_ = nullptr;
	}
	len = 0;
}

int main()
{
	Bus bus{ 90,41,"Bogdan" };
	bus.Show();
	Car car{ 140,4,"lanos" };
	car.Show();
	return 0;
}

