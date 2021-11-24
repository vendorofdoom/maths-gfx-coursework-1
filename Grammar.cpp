#include "Grammar.h"

Grammar::Grammar()
{
  m_successors = {};
  m_probabilities = {};
  m_seed = 1;
}

void Grammar::AddRule(char symbol, std::string successor, float probability)
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
