#include <NumericalOptimizer.h>
#include <iostream>

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