#include <iostream>
#include <string>

using namespace std;

// �����, ���������� �� ��������� � ���������� ����������
class Engine {
private:
    int power; //��������
    int torque; //�������� ������
    double fuelConsumption; //������ �������

public:
    Engine(int p, int t, double fc) : power(p), torque(t), fuelConsumption(fc) {}

    //���������� ���������
    void Start() {
        cout << "��������� �������" << endl;
    }//������� ���������

    void Stop() {
        cout << "��������� ����������" << endl;
    }//��������� ���������

    void ShowSpecs() {
        cout << "��������: " << power << " HP" << endl;
        cout << "�������� ������: " << torque << " Nm" << endl;
        cout << "������ �������: " << fuelConsumption << " �/100��" << endl;
    }//����������� ������ � ���������
};

// �����, ���������� �� ���������� ������������
class Transmission {
private:
    string type; //��� �����������

public:
    Transmission(const string& t) : type(t) {}

    //������� ����������
    void ShiftUp() {
        cout << "�������� ���������" << endl;
    }//���������

    void ShiftDown() {
        cout << "�������� ���������" << endl;
    }//����������

    void ShowType() {
        cout << "��� �����������: " << type << endl;
    }//����������� ������ � �����������
};

// �����, ���������� �� ������� ����������
class CoolingSystem {
private:
    double temperature; //����������� ���������

public:
    CoolingSystem() : temperature(90.0) {}

    //������� ������� ����������
    void CheckTemperature() {
        cout << "������� �����������: " << temperature << " �C" << endl;
    }// ����������� ����������� ���������

    void CoolDown() {
        cout << "���������� ���������..." << endl;
        temperature -= 10.0;
        if (temperature < 60.0) temperature = 60.0;
    }//���������� ���������
};

// �����, �������������� ��� ���������� � ������������ ��������
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
        cout << "=== ������ ������������� �������� ===" << endl;
        engine.Start();
        engine.ShowSpecs();
        transmission.ShowType();
        transmission.ShiftUp();
        coolingSystem.CheckTemperature();
    }

    void StopVehicle() {
        cout << "=== ��������� ������������� �������� ===" << endl;
        coolingSystem.CoolDown();
        coolingSystem.CheckTemperature();
        engine.Stop();
    }
};

// �������� ���������
int main() {
    setlocale(LC_ALL, "RU");
    Vehicle car(250, 320, 8.5, "Automatic");

    car.StartVehicle();
    cout << endl;
    car.StopVehicle();

    return 0;
}
