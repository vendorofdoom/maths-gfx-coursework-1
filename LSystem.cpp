#include "LSystem.h"

LSystem::LSystem()
{
      m_axiom = "X";
      m_angle = 20.0f;
      m_numIter = 4;
      m_turtleInstructions = "";
      m_grammar.AddRule('X', "F[+X]F[-X]+X", 1.0f);
      m_grammar.AddRule('F', "FF", 1.0f);

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

void LSystem::ComputeTurtleInstructions()
{
  std::string input = m_axiom;
  std::string output = "";

  for (int i=0; i<= m_numIter; i++)
  {

    for(char c : input) {
        output += m_grammar.GetProduction(c);
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

void LSystem::LoadFromFile(std::ifstream& configFile) 
{

  std::vector<std::string> successors;
  std::vector<std::string> predecessors;
  std::vector<float> probability;

  std::string line;
  int count = 0;

  if (configFile.is_open())
    {
      while ( std::getline (configFile,line) )
      {
        std::cout << line << " " << std::to_string(count) << std::endl;

        if (count == 0)
        {

        }
        else if (count == 1)
        {

        }
        else if (count == 2)
        {
          
        }
        else
        {
          // add to production rules
        }

        count++;
      }
      configFile.close();
    }

  else std::cout << "Unable to open file"; 

}