#include<iostream>

#include "Compound.hpp"
#include "Eos.hpp"

using namespace std;

int main(){
    
    std::string name;
    float critTemperature, critPressure, factor;
    float temperature, pressure;
    
    
    cout << "Welcome to Peng-Robinson EOS solver for pure components" << endl;
    cout << "Please enter Compound Name, Critical Pressure, Critical";
    cout << " Temperature and Accentric Factor" << endl;
    
    cin >> name;
    cin >> critPressure;
    cin >> critTemperature;
    cin >> factor;
    
    Compound compound(name, pressure, temperature, factor);
    
    Eos eos(compound);
    
    cout << "Please enter the temperature and pressure you wish to solve for";
    cout << endl;
    
    cin >> temperature;
    cin >> pressure;
    
    eos.setTemperature(temperature);
    eos.setPressure(pressure);
    
    eos.solve();

    return 0;
}