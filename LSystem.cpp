#include "LSystem.h"

LSystem::LSystem()
{
      // These values should be overwritten by the config loaded from file
      m_axiom = "X";
      m_angle = 20.0f;
      m_numIter = 4;
      m_turtleInstructions = "";
      m_lineLength = 1;
      //m_grammar.AddProductionRule('X', "F[+X]F[-X]+X", 1.0f);
      //m_grammar.AddProductionRule('F', "FF", 1.0f);

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

void LSystem::SetLineLength(float lineLength)
{
  m_lineLength = lineLength;
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

float LSystem::GetLineLength()
{
  return m_lineLength;
}

void LSystem::LoadFromFile(std::string fileName) 
{
  std::ifstream configFile ("LSystemConfigs/" + fileName + ".txt");

  std::string::size_type sz;
  std::vector<std::string> productionRules;
  std::string line;
  int count = 0;

  if (configFile.is_open())
  {

    while ( std::getline (configFile,line) )
    {
      if (count == 0)
      {
        SetLineLength(std::stoi (line,&sz));
      }
      else if (count == 1)
      {
        SetIterations(std::stoi (line,&sz));
      }
      else if (count == 2)
      {
        SetAngle(std::stof (line,&sz));
      }
      else if (count == 3)
      {
        SetAxiom(line.c_str());
      }
      else
      {
        // https://stackoverflow.com/questions/10617094/how-to-split-a-file-lines-with-space-and-tab-differentiation
        std::istringstream iss(line);
        std::string token;
        while(std::getline(iss, token, '|'))
          //std::cout << token << std::endl;
          productionRules.push_back(token);
      }

      count++;
    }

    configFile.close();

    m_grammar.AddProductionRules(productionRules);

  }

  else
  {
    std::cout << "Unable to open file" << std::endl; 
  } 

}

