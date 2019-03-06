#pragma once

#include <vector>
#include <iostream>

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

template<class T>
NumericalOptimizer<T>::NumericalOptimizer() {
}

template<class T>
NumericalOptimizer<T>::~NumericalOptimizer() {
}

template<class T>
void NumericalOptimizer<T>::SetObjectiveFunction(NumericalOptimizer::callback_function pObjectiveFunc) {
    _ObjectFunction = pObjectiveFunc;
}

template<class T>
void NumericalOptimizer<T>::AddConstraintDomain(NumericalOptimizer::callback_function pConstraintFunc, DomainOfConstrain domain) {
    _ConstraintEquations.push_back(pConstraintFunc);
    _DomainOfConstrains.push_back(domain);
}

template<class T>
void NumericalOptimizer<T>::SetNumberOfVariables(size_t nVars) {
    _NumberOfVariables = nVars;
    _ArgumentSet.clear();
    for (size_t i = 0; i < _NumberOfVariables; i++) {
        _ArgumentSet.push_back(0);
    }
}


// TODO: need to implement this function
template<class T>
void NumericalOptimizer<T>::Go() {
    _ArgumentSet.at(0) = 1;
    _ArgumentSet.at(1) = 5;
    _ArgumentSet.at(2) = 10;

    T value = _ObjectFunction(_ArgumentSet);
    std::cout << "Value of function: " << value << "." << std::endl;
}



