#ifndef LSYSTEM_H
#define LSYSTEM_H

#include <SDL2/SDL.h>
#include <string>
#include <map>

class LSystem
{
  public:
    LSystem();

    void SetAxiom(std::string axiom);
    void SetAngle(float angle);
    void SetIterations(int numIter);
    void AddRule(char input, std::string output);
    
    void ComputeTurtleInstructions();

    std::string GetInstructions();
    float GetAngle();


    private:
      std::string m_axiom;
      int m_numIter;
      std::map<char, std::string> m_rules;
      float m_angle;
      std::string m_turtleInstructions;
      
};

#endif