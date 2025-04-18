#include <iostream>
#include <string>

using namespace std;

// Класс, отвечающий за параметры и управление двигателем
class Engine {
private:
    int power; //мощность
    int torque; //крутящий момент
    double fuelConsumption; //расход топлива

public:
    Engine(int p, int t, double fc) : power(p), torque(t), fuelConsumption(fc) {}

    //функционал двигателя
    void Start() {
        cout << "Двигатель запущен" << endl;
    }//завести двигатель

    void Stop() {
        cout << "Двигатель остановлен" << endl;
    }//заглушить двигатель

    void ShowSpecs() {
        cout << "Мощность: " << power << " HP" << endl;
        cout << "Крутящий момент: " << torque << " Nm" << endl;
        cout << "Расход топлива: " << fuelConsumption << " Л/100км" << endl;
    }//отображение данных о двигателе
};

// Класс, отвечающий за управление трансмиссией
class Transmission {
private:
    string type; //тип трансмиссии

public:
    Transmission(const string& t) : type(t) {}

    //функции трансмисси
    void ShiftUp() {
        cout << "Скорость увеличена" << endl;
    }//ускорение

    void ShiftDown() {
        cout << "Скорость уменьшена" << endl;
    }//замедление

    void ShowType() {
        cout << "Тип трансмиссии: " << type << endl;
    }//отображение данных о трансмиссии
};

// Класс, отвечающий за систему охлаждения
class CoolingSystem {
private:
    double temperature; //температура двигателя

public:
    CoolingSystem() : temperature(90.0) {}

    //функции системы охлаждения
    void CheckTemperature() {
        cout << "Текущая температура: " << temperature << " °C" << endl;
    }// отображение температуры двигателя

    void CoolDown() {
        cout << "Охлаждение двигателя..." << endl;
        temperature -= 10.0;
        if (temperature < 60.0) temperature = 60.0;
    }//охлаждение двигателя
};

// Класс, координирующий все компоненты — транспортное средство
class Vehicle {
private:
    Engine engine;
    Transmission transmission;
    CoolingSystem coolingSystem;

public:
    Vehicle(int power, int torque, double fuelConsumption, const string& transmissionType)
        : engine(power, torque, fuelConsumption),
        transmission(transmissionType),
        coolingSystem() {}

    void StartVehicle() {
        cout << "=== Запуск транспортного средства ===" << endl;
        engine.Start();
        engine.ShowSpecs();
        transmission.ShowType();
        transmission.ShiftUp();
        coolingSystem.CheckTemperature();
    }

    void StopVehicle() {
        cout << "=== Остановка транспортного средтсва ===" << endl;
        coolingSystem.CoolDown();
        coolingSystem.CheckTemperature();
        engine.Stop();
    }
};

// Основная программа
int main() {
    setlocale(LC_ALL, "RU");
    Vehicle car(250, 320, 8.5, "Automatic");

    car.StartVehicle();
    cout << endl;
    car.StopVehicle();

    return 0;
}
