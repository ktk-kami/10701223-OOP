#include <iostream>
#include <string>

using namespace std;

class AssemblyLine {
public:
    virtual string produce() = 0;
    virtual ~AssemblyLine() {};
};

class AssemblyLineA : public AssemblyLine {
public:
    string produce() override {
        return "Product A";
    }
};

class AssemblyLineB : public AssemblyLine {
public:
    string produce() override {
        return "Product B";
    }
};

class AssemblyLineC : public AssemblyLine {
public:
    string produce() override {
        return "Product C";
    }
};

class ProductionManager {
private:
    AssemblyLine* line;

public:
    ProductionManager(AssemblyLine* line) : line(line) {}

    void setLine(AssemblyLine* newLine) {
        line = newLine;
    }

    void startProduction() {
        if (line) {
            cout << "Producing: " << line->produce() << endl;
        }
    }
};

int main() {
    AssemblyLineA lineA;
    AssemblyLineB lineB;
    AssemblyLineC lineC;

    ProductionManager manager(&lineA);
    manager.startProduction();

    manager.setLine(&lineB);
    manager.startProduction();

    manager.setLine(&lineC);
    manager.startProduction();
}