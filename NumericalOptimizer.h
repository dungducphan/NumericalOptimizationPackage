#pragma once

#include <vector>

enum DomainOfConstrain {
    kUnderTheCurve,
    kAlongTheCurve,
    kAboveTheCurve
};

template <class T>
class NumericalOptimizer {
    typedef T (*callback_function)(std::vector<T>);
public:
    explicit NumericalOptimizer();
    virtual ~NumericalOptimizer();

    void SetNumberOfVariables(size_t nVars);
    void SetObjectiveFunction(callback_function pObjectiveFunc);
    void AddConstraintDomain(callback_function pConstraintFunc, DomainOfConstrain domain = kAlongTheCurve);

    void Go();

private:
    size_t _NumberOfVariables;
    std::vector<T> _ArgumentSet;

    callback_function _ObjectFunction;
    std::vector<callback_function> _ConstraintEquations;
    std::vector<DomainOfConstrain> _DomainOfConstrains;

};

template class NumericalOptimizer<long double>;
template class NumericalOptimizer<double>;
template class NumericalOptimizer<float>;
template class NumericalOptimizer<long long int>;
template class NumericalOptimizer<long int>;
template class NumericalOptimizer<int>;



