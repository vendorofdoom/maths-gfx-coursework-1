#ifndef LSYSTEM_H
#define LSYSTEM_H

#include <SDL2/SDL.h>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include "Grammar.h"
#include <sstream>

class LSystem
{
  public:
    LSystem();

    void SetAxiom(std::string axiom);
    void SetAngle(float angle);
    void SetIterations(int numIter);
    void SetLineLength(float lineLength);
    
    void ComputeTurtleInstructions();

    std::string GetInstructions();
    float GetAngle();
    float GetLineLength();

    void LoadFromFile(std::string fileName);
    void AddRules(std::vector<std::string> productions);

    void DecrementIterations();
    void IncrementIterations();

    void IncrementLineLength();
    void DecrementLineLength();

    void IncrementAngle();
    void DecrementAngle();

    private:
      std::string m_axiom;
      int m_numIter;
      Grammar m_grammar;
      float m_angle;
      std::string m_turtleInstructions;
      int m_lineLength;
      
};

#endif