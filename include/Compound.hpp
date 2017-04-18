#ifndef COMPOUND_HPP
#define COMPOUND_HPP

#include<string>

class Compound{
    
    private:
    
    std::string m_name;
    float m_critPres;
    float m_critTemp;
    float m_accentric;
    
    public:
    
    Compound(std::string name, float critPres, float critTemp, float accentric);
    ~Compound();
    
    std::string getName();
    float getCriticalPressure();
    float getCriticalTemperature();
    float getAccentricFactor();
    
};


#endif // COMPOUND_HPP