#include "LSystem.h"
#include <iostream>

LSystem::LSystem()
{
      m_axiom = "X";
      m_angle = 20.0f;
      m_numIter = 7;
      m_rules = {{'X', "F[+X]F[-X]+X"}, 
        {'F', "FF"}};
      m_turtleInstructions = "";
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

  for (int i=0; i<= m_numIter; i++)
  {

    for(char c : input) {
      if (m_rules[c] != "")
      {
        output += m_rules[c];
      }
      else
      {
        output += c;
      }
      
    }

    input = output;
    
    if (i == m_numIter)
    {
      m_turtleInstructions = output;
    }
    
    output.clear();
  }

}

std::string LSystem::GetInstructions()
{
  return m_turtleInstructions;
}

float LSystem::GetAngle()
{
  return m_angle;
}