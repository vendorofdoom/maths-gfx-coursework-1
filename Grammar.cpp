#include "Grammar.h"

Grammar::Grammar()
{
  m_successors = {};
  m_probabilities = {};
  m_seed = 1;
}

void Grammar::AddProductionRule(char symbol, float probability, std::string successor)
{

  if ( m_successors.find(symbol) == m_successors.end() ||
       m_probabilities.find(symbol) == m_probabilities.end() ) 
  {
    m_successors[symbol].push_back(successor);
    m_probabilities[symbol].push_back(probability);
  }
  else
  {
    m_successors[symbol] = {successor};
    m_probabilities[symbol] = {probability};
  }
  
}

void Grammar::AddProductionRules(std::vector<std::string> rules)
{
  std::string::size_type sz;
  char symbol;
  std::string successor;
  float probability;

  for (int i=0; i<rules.size(); i++)
  {

    if (i%3 == 0)
    {
      // symbol
      symbol = rules[i][0];
      std::cout << symbol << std::endl;
    }
    else if (i%3 == 1)
    {
      // probability
      probability = std::stof(rules[i],&sz);
    }
    else if (i%3 == 2)
    {
      // successor & AddRule
      successor = rules[i];
      AddProductionRule(symbol, probability, successor);
    }

  }

}

std::string Grammar::GetProduction(char symbol)
{
  std::vector<std::string> successors;
  std::vector<float> probabilities;

  

  if (m_successors.find(symbol) == m_successors.end())
  {
    return std::string(1, symbol);
  }
  else
  {
    return m_successors[symbol][0];
    // TODO: Add code here to return successor based on probability
  }
  
}
