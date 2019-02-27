#include <iostream>
#include <vector>
#include <NumericalOptimizer.h>

double TestObjectiveFunction(std::vector<double> arguments) {
    double x = arguments.at(0);
    double y = arguments.at(1);
    double z = arguments.at(2);

    return x * y / z;
}

double TestConstrain_1(std::vector<double> arguments) {
    double x = arguments.at(0);
    double y = arguments.at(1);
    double z = arguments.at(2);

    return x - y;
}

double TestConstrain_2(std::vector<double> arguments) {
    double x = arguments.at(0);
    double y = arguments.at(1);
    double z = arguments.at(2);

    return y * z - 5;
}

int main() {
    NumericalOptimizer<double>* numOp = new NumericalOptimizer<double>();
    numOp->SetNumberOfVariables(3);
    numOp->SetObjectiveFunction(TestObjectiveFunction);
    numOp->Go();

    return 0;
}