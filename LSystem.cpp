#include "LSystem.h"

LSystem::LSystem()
{
      // These values should be overwritten by the config loaded from file
      m_name = "";
      m_axiom = "X";
      m_angle = 20.0f;
      m_numIter = 4;
      m_turtleInstructions = "";
      m_lineLength = 1;
      m_rootX = 0;
      m_rootY = 0;
      m_randSeed = 1;
      m_gen.seed(m_randSeed);
      std::uniform_real_distribution<> m_dis(0.0, 1.0);
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

void LSystem::SetName(std::string name)
{
  m_name = name;
}

void LSystem::SetRoot(int rootX, int rootY)
{
  m_rootX = rootX;
  m_rootY = rootY;
}

void LSystem::ComputeTurtleInstructions()
{
  m_gen.seed(m_randSeed);

  std::string input = m_axiom;
  std::string output = "";

  if (m_numIter >= 1)
  {
    for (int i=1; i<=m_numIter; i++)
    {

      for(char c : input) {
          output += m_grammar.GetProduction(c, GenRandProb());
      }

      input = output;
      
      if (i == m_numIter)
      {
        m_turtleInstructions = output;
      }
      
      output.clear();
    }
  }
  else
  {
    m_turtleInstructions = m_axiom;
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

int LSystem::GetNumIterations()
{
  return m_numIter;
}

int LSystem::GetRootX()
{
  return m_rootX;
}

int LSystem::GetRootY()
{
  return m_rootY;
}

std::string LSystem::GetName()
{
  return m_name;
}

int LSystem::GetRandSeed()
{
  return m_randSeed;
}

void LSystem::LoadFromFile(std::string fileName) 
{
  fileName = "LSystemConfigs/" + fileName + ".txt";
  std::ifstream configFile (fileName);

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
        SetName(line);
      }
      else if (count == 1)
      {
        SetLineLength(std::stof (line,&sz));
      }
      else if (count == 2)
      {
        SetIterations(std::stoi (line,&sz));
      }
      else if (count == 3)
      {
        SetAngle(std::stof (line,&sz));
      }
      else if (count == 4)
      {
        SetAxiom(line.c_str());
      }
      else
      {
        // https://stackoverflow.com/questions/10617094/how-to-split-a-file-lines-with-space-and-tab-differentiation
        std::istringstream iss(line);
        std::string token;
        while(std::getline(iss, token, '|'))
          productionRules.push_back(token);
      }

      count++;
    }

    configFile.close();

    m_grammar.AddProductionRules(productionRules);

    std::cout << "Loaded LSystem: " << GetName() << std::endl;

  }

  else
  {
    std::cout << "Unable to open file: " << fileName << std::endl; 
  } 

}

void LSystem::IncrementIterations()
{
  if (m_numIter <= 9)
  {
    m_numIter++;
  }
}

void LSystem::DecrementIterations()
{
  if (m_numIter >= 1)
  {
    m_numIter--;
  }
}

void LSystem::IncrementLineLength()
{
  if (m_lineLength <= 99)
  {
    m_lineLength++;
  }
}

void LSystem::DecrementLineLength()
{
  if (m_lineLength >= 2)
  {
    m_lineLength--;
  }
}

void LSystem::IncrementAngle()
{
  if (m_angle <= 179)
  {
    m_angle++;
  }
}

void LSystem::DecrementAngle()
{
  if (m_angle >= 2)
  {
    m_angle--;
  }
}

void LSystem::ToggleRoot(int windowX, int windowY)
{

  // This function toggles the root of the l-system
  // between the centre and centre bottom of the screen
  // TODO: Add logic to specify root from config file
  
  static int count = 0;

  if (count%2 == 0)
  {
    m_rootX = windowX / 2;
    m_rootY = windowY - 10;
  }
  else
  {
    m_rootX = windowX / 2;
    m_rootY = windowY / 2;
  }

  count++;

}

void LSystem::SetRandSeed(int seed)
{
  m_randSeed = seed;
}


float LSystem::GenRandProb()
{
  // https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
  return m_dis(m_gen);
}

void LSystem::IncrementRandSeed()
{
  if (m_randSeed <= 9)
  {
    m_randSeed++;
  }
}

void LSystem::DecrementRandSeed()
{
  if (m_randSeed >= 2)
  {
    m_randSeed--;
  }
}