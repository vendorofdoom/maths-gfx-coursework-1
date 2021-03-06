#ifndef PRODUCTIONRULES_H
#define PRODUCTIONRULES_H

#include <string>
#include <vector>
#include <map>
#include <random>
#include <iostream>

class ProductionRules
{
  public:
    ProductionRules();
    void AddProductionRule(char symbol, float probability, std::string successor);
    void AddProductionRules(std::vector<std::string> rules);
    std::string GetProduction(char symbol, float prob);

  private:
    std::map<char, std::vector<std::string>> m_successors;
    std::map<char, std::vector<float>> m_probabilities;

};


#endif