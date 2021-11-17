#ifndef SNOWFLAKEINITIATOR_H
#define SNOWFLAKEINITIATOR_H

#include <vector>

class snowflakeInitiator
{
  public:
    snowflakeInitiator();
    ~snowflakeInitiator();

    void AddVertex(float xPos, float yPos);
    int NumEdges();
    bool GetEdge(float *x1, float *y1, float *x2, float *y2, int index);

  private:
    std::vector<float> m_vertexX;
    std::vector<float> m_vertexY;
};

#endif