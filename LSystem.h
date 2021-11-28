#ifndef LSYSTEM_H
#define LSYSTEM_H

#include <SDL2/SDL.h>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include "ProductionRules.h"
#include <sstream>

class LSystem
{
  public:
    LSystem();

    void SetAxiom(std::string axiom);
    void SetAngle(float angle);
    void SetIterations(int numIter);
    void SetLineLength(float lineLength);
    void SetName(std::string name);
    void SetRoot(int rootX, int rootY);
    void SetRandSeed(int seed);
    
    std::string GetInstructions();
    float GetAngle();
    float GetLineLength();
    int GetNumIterations();
    int GetRootX();
    int GetRootY();
    std::string GetName();
    int GetRandSeed();

    void ComputeTurtleInstructions();
    void LoadFromFile(std::string fileName);

    // Support for user input via hotkeys
    void DecrementIterations();
    void IncrementIterations();
    void IncrementLineLength();
    void DecrementLineLength();
    void IncrementAngle();
    void DecrementAngle();
    void IncrementRandSeed();
    void DecrementRandSeed();
    void ToggleRoot(int windowX, int windowY);

    private:
      std::string m_name;
      std::string m_axiom;
      int m_numIter;
      ProductionRules m_productionRules;
      float m_angle;
      std::string m_turtleInstructions;
      float m_lineLength;
      int m_rootX;
      int m_rootY;
      
      void AddRules(std::vector<std::string> productions);

      float GenRandProb();
      int m_randSeed;
      std::mt19937 m_gen;
      std::uniform_real_distribution<> m_dis;
      
};

#endif