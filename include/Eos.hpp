#ifndef EOS_HPP
#define EOS_HPP

#include<iostream>
#include<vector>
#include "Cubic.hpp"
#include "Compound.hpp"

using namespace std;

class Eos{
    
    private:
    
    Compound m_compound;
    float m_temperature;
    float m_pressure;
    float m_A;
    float m_B;
    float m_Alpha;
    float m_reducedTemperature;
    float m_reducedPressure;
    float m_z[3];
    
    void calcReducedTemp();
    void calcReducedPress();
    void calcAlpha();
    void calcA();
    void calcB();
    void resetZ();
    bool calcCubicZ();
    
    public:
    
    Eos(Compound& compound);
    ~Eos();
    
    void setTemperature(float temperature);
    void setPressure(float pressure);
    
    void solve();
    
};


#endif // EOS_HPP