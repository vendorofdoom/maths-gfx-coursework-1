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

    private:
      std::string m_axiom;
      float m_angle;
      int m_numIter;
      std::map<char, std::string> m_rules;
      std::string m_turtleInstructions;
};

#endif