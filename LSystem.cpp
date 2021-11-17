#include "LSystem.h"
#include <iostream>

LSystem::LSystem()
{
      m_axiom = "AF";
      m_angle = 45.0f;
      m_numIter = 2;
      m_rules = {{'F', "FF"}, {'A', "FAA"}};
      m_turtleInstructions = "F";
}

void LSystem::SetAxiom(std::string axiom)
{
  m_axiom = axiom;
}

void LSystem::SetAngle(float angle)
{
  m_angle = angle;
}

void LSystem::SetIterations(int numIter)
{
  m_numIter = numIter;
}

void LSystem::AddRule(char input, std::string output)
{
  m_rules[input] = output;
}

void LSystem::ComputeTurtleInstructions()
{
  std::string input = m_axiom;
  std::string output = "";

  std::cout << m_axiom;
  std::cout << "\n";

  for (int i=0; i<= m_numIter; i++)
  {

    for(char c : input) {
      output.append(m_rules[c]);
    }

    input = output;
    
//    std::cout << output;
//    std::cout << "\n";
    
    output.clear();

  }

  m_turtleInstructions = output;
}