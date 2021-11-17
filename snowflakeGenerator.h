#ifndef SNOWFLAKEGENERATOR_H
#define SNOWFLAKEGENERATOR_H

#include <vector>
#include "Turtle.h"

class snowflakeGenerator
{
  public:
    snowflakeGenerator();
    ~snowflakeGenerator(); // destructor

    void SetStartPoint(float xPos, float yPos);
    void SetEndPoint(float xPos, float yPos);
    void AddNode(float angle);
    bool Compute();
    int NumEdges();
    bool GetEdge(float *x1, float *y1, float *x2, float *y2, int index);

  private:
    std::vector<float> m_nodeAngle;
    std::vector<float> m_x1;
    std::vector<float> m_y1;
    std::vector<float> m_x2;
    std::vector<float> m_y2;
    Turtle m_turtle;
    float m_startX, m_startY;
    float m_endX, m_endY;
    int m_numEdges;  
};

#endif