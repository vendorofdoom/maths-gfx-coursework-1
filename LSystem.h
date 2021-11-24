#ifndef LSYSTEM_H
#define LSYSTEM_H

#include <SDL2/SDL.h>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include "Grammar.h"

class LSystem
{
  public:
    LSystem();

    void SetAxiom(std::string axiom);
    void SetAngle(float angle);
    void SetIterations(int numIter);
    
    void ComputeTurtleInstructions();

    std::string GetInstructions();
    float GetAngle();

    void LoadFromFile(std::ifstream& configFile);


    private:
      std::string m_axiom;
      int m_numIter;
      Grammar m_grammar;
      float m_angle;
      std::string m_turtleInstructions;
      
};

#endif