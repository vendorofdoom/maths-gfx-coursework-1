#include "Grammar.h"

Grammar::Grammar()
{
  m_successors = {};
  m_probabilities = {};
  
}

void Grammar::AddProductionRule(char symbol, float probability, std::string successor)
{

  if ( m_successors.find(symbol) != m_successors.end() &&
       m_probabilities.find(symbol) != m_probabilities.end() ) 
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

  // Clear any existing rules
  // assuming this only called once per lsystem setup
  // TODO: maybe want to call this somewhere else?
  m_successors.clear();
  m_probabilities.clear();

  for (int i=0; i<rules.size(); i++)
  {

    if (i%3 == 0)
    {
      // symbol
      symbol = rules[i][0];
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

std::string Grammar::GetProduction(char symbol, float prob)
{

  if (m_successors.find(symbol) == m_successors.end())
  {
    return std::string(1, symbol);
  }
  else
  {
    float sum = 0.0;
    

    for (int i=0; i<m_probabilities[symbol].size(); i++)
    {
      sum += m_probabilities[symbol][i];
      if (prob <= sum)
      {
        return m_successors[symbol][i];
      }

    }

    // what if probabilities don't add up to 1?

  }
  
}
