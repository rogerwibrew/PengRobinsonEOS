#include "Eos.hpp"

Eos::Eos(Compound& compound):
m_compound{compound}
{
    
}

Eos::~Eos(){
    
}

void Eos::calcReducedTemp(){
    m_reducedTemperature = m_temperature/m_compound.getCriticalTemperature();
}

void Eos::calcReducedPress(){
    m_reducedPressure = m_pressure/m_compound.getCriticalPressure();
}

void Eos::calcAlpha(){
    float tempAcentric = m_compound.getAccentricFactor();
    float temp1 = (0.37464 + 1.5422*tempAcentric -0.26992*pow(tempAcentric,2.0));
    float temp2 = (1-pow(m_reducedTemperature,0.5));
    
    m_Alpha = pow((1+temp1*temp2),2.0);
}

void Eos::calcA(){
    m_A = 0.45724*m_Alpha*m_reducedPressure / pow(m_reducedTemperature, 2.0);
}

void Eos::calcB(){
    m_B = 0.07780 * m_reducedPressure / m_reducedTemperature;
}

void Eos::resetZ(){
    for(int i=0; i<3; i++){
        m_z[i] = 0;
    }
}

bool Eos::calcCubicZ(){
    
    float a{1};
    float b{-(1-m_B)};
    float c{m_A - 3*pow(m_B,2.0) - 2*m_B};
    float d{-((m_A*m_B) - pow(m_B, 2.0) - pow(m_B, 3.0))};
    
    bool answer = cubic(a, b, c, d, m_z);

    return answer;
    
}

void Eos::solve(){
    
    calcReducedTemp();
    calcReducedPress();
    calcAlpha();
    calcA();
    calcB();
    
    bool test = calcCubicZ();
    
    if(test){
        cout << "There are two phases.  Unless satruated only one will be stable."  << endl
        cout << "The largest compresability is the gas,";
        cout << "the smallest compresability is the liquid the middle is meaningless" << endl;
        for(int i = 0; i < 3; i++)
            cout << m_z[i] << endl;
    }
    else{
        cout << "There is only one phase - the compresability is :";
        cout << m_z[0] << endl;
        }
    
}

void Eos::setPressure(float pressure){
   m_pressure = pressure;
}

void Eos::setTemperature(float temperature){
    m_temperature = temperature;
}