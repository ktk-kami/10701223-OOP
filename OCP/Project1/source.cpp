#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ��������� (����������� ������� �����) ��� ������������ ���������
class VehicleCostCalculator {
public:
    virtual double CalculateCost() const = 0;
    virtual string GetVehicleType() const = 0;
    virtual ~VehicleCostCalculator() {};
};

// ����� ��� �������� ������
class CarCostCalculator : public VehicleCostCalculator {
public:
    double CalculateCost() const override {
        return 20000.0;
    }

    string GetVehicleType() const override {
        return "�������� ������";
    }
};

// ����� ��� ���������
class TruckCostCalculator : public VehicleCostCalculator {
public:
    double CalculateCost() const override {
        return 50000.0;
    }

    string GetVehicleType() const override {
        return "��������";
    }
};

// ����� ��� ���������� ������
class SportsCarCostCalculator : public VehicleCostCalculator {
public:
    double CalculateCost() const override {
        return 100000.0;
    }

    string GetVehicleType() const override {
        return "���������� ������";
    }
};

// �����, ������� �������� � ������ ������ ������������� (��� ���������� � ������ ������ �� �����)
class CostAnalyzer {
public:
    void ShowCosts(const vector<VehicleCostCalculator*>& vehicles) {
        for (const auto& vehicle : vehicles) {
            cout << vehicle->GetVehicleType() << " cost: $" << vehicle->CalculateCost() << endl;
        }
    }
};

// �������� ���������
int main() {
    setlocale(LC_ALL, "RU");
    vector<VehicleCostCalculator*> vehicleCalculators;

    vehicleCalculators.push_back(new CarCostCalculator());
    vehicleCalculators.push_back(new TruckCostCalculator());
    vehicleCalculators.push_back(new SportsCarCostCalculator());

    CostAnalyzer analyzer;
    analyzer.ShowCosts(vehicleCalculators);

    for (auto& vehicle : vehicleCalculators) {
        delete vehicle;
    }

    return 0;
}

