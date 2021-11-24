#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <string>
#include <vector>
#include <map>
#include <random>

class Grammar
{
  public:
    Grammar();
    void AddRule(char symbol, std::string successor, float probability);
    std::string GetProduction(char symbol);

  private:
    std::map<char, std::vector<std::string>> m_successors;
    std::map<char, std::vector<float>> m_probabilities;
    int m_seed; // for the stochastic production rules
};


#endif