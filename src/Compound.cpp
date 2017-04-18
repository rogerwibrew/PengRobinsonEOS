#include "Compound.hpp"

Compound::Compound(std::string name, float critPres, float critTemp, float accentric):
m_name{name},
m_critPres{critPres},
m_critTemp{critTemp},
m_accentric{accentric}

{
   
}

Compound::~Compound(){
}

std::string Compound::getName(){
    return m_name;
}

float Compound::getCriticalPressure(){
    return m_critPres;
}

float Compound::getCriticalTemperature(){
    return m_critTemp;
}

float Compound::getAccentricFactor(){
    return m_accentric;
}


