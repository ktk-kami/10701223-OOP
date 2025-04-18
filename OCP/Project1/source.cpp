#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Интерфейс (абстрактный базовый класс) для калькулятора стоимости
class VehicleCostCalculator {
public:
    virtual double CalculateCost() const = 0;
    virtual string GetVehicleType() const = 0;
    virtual ~VehicleCostCalculator() {};
};

// Класс для легковой машины
class CarCostCalculator : public VehicleCostCalculator {
public:
    double CalculateCost() const override {
        return 20000.0;
    }

    string GetVehicleType() const override {
        return "Легковая машина";
    }
};

// Класс для грузовика
class TruckCostCalculator : public VehicleCostCalculator {
public:
    double CalculateCost() const override {
        return 50000.0;
    }

    string GetVehicleType() const override {
        return "Грузовик";
    }
};

// Класс для спортивной машины
class SportsCarCostCalculator : public VehicleCostCalculator {
public:
    double CalculateCost() const override {
        return 100000.0;
    }

    string GetVehicleType() const override {
        return "Спортивная машина";
    }
};

// Класс, который работает с любыми типами калькуляторов (для считывания и вывода данных на экран)
class CostAnalyzer {
public:
    void ShowCosts(const vector<VehicleCostCalculator*>& vehicles) {
        for (const auto& vehicle : vehicles) {
            cout << vehicle->GetVehicleType() << " cost: $" << vehicle->CalculateCost() << endl;
        }
    }
};

// Основная программа
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

