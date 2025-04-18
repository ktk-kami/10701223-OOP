#include <iostream>
#include <windows.h>

using namespace std;

//Разделение интерфейса VehicleOperations на более мелкие
class IEngineOperations {
public:
	virtual void Start() = 0;
	virtual void Stop() = 0;
};

class IDriving {
public:
	virtual void Accelerate() = 0;
};

class IFlying {
public:
	virtual void Fly() = 0;
};

class ISailing {
public:
	virtual void Sail() = 0;
};

class Car : public IEngineOperations, public IDriving {
public:
	void Start() override {
		cout << "Двигатель машины начал работу!\n";
	}

	void Stop() override {
		cout << "Двигатель машины закончил работу!\n";
	}

	void Accelerate() override {
		cout << "Машина набирает скорость!\n";
	}
};

class Plane : public IEngineOperations, public IFlying {
public:
	void Start() override {
		cout << "\nДвигатель самолета начал работу!\n";
	}

	void Stop() override {
		cout << "Двигатель самолета закончил работу!\n";
	}

	void Fly() override {
		cout << "Самолет взлетает!\n";
	}
};

class Boat : public IEngineOperations, public ISailing {
public:
	void Start() override {
		cout << "\nДвигатель лодки начал работу!\n";
	}

	void Stop() override {
		cout << "Двигатель лодки закончил работу!\n";
	}

	void Sail() override {
		cout << "Лодка плывет!\n";
	}
};

int main() {
	SetConsoleOutputCP(65001);

	Car car;
	car.Start();
	car.Accelerate();
	car.Stop();

	Plane plane;
	plane.Start();
	plane.Fly();
	plane.Stop();

	Boat boat;
	boat.Start();
	boat.Sail();
	boat.Stop();

	return 0;
}