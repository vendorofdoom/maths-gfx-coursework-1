#include<math.h>
#include "Turtle.h"

Turtle::Turtle()
{
  m_pRenderer = NULL;
  m_x = 0.0f, m_y = 0.0f;
  m_r = 255, m_g = 255, m_b = 255, m_alpha = 255;
  m_angle = 0.0f;
  m_length = 1.0f;
  m_penDown = false;
}

void Turtle::SetRenderer(SDL_Renderer *pRenderer)
{
  m_pRenderer = pRenderer;
}

void Turtle::PenUp()
{
  m_penDown = false;
}

void Turtle::PenDown()
{
  m_penDown = true;
}

void Turtle::SetPenColour(int r, int g, int b, int alpha)
{
  m_r = r;
  m_g = g;
  m_b = b;
  m_alpha = alpha;
}

void Turtle::SetAngle(float angle)
{
  m_angle = angle;
}

void Turtle::SetLength(float length)
{
  m_length = length;
}

void Turtle::MoveTo(float xPos, float yPos)
{
  m_x = xPos;
  m_y = yPos;
}

void Turtle::RotateRight(float angle)
{
  m_angle += angle * (M_PI / 180.0);
}

void Turtle::RotateLeft(float angle)
{
  m_angle -= angle * (M_PI / 180.0);
}

void Turtle::LookAt(float xPos, float yPos)
{
  float dx = xPos - m_x;
  float dy = yPos - m_y;

  if (dx == 0.0) 
  {
      if (dy > 0.0) 
      {
        m_angle = M_PI / 2.0;
      } else
      {
        m_angle = M_PI + (M_PI / 2.0);
      }
  } else
  {
    m_angle = atan(dy/dx);
  }

  if (dx < 0.0)
  {
    m_angle += M_PI;
  }

}

void Turtle::Step()
{
  float startX = m_x;
  float startY = m_y;
  float endX = startX + (cos(m_angle) * m_length);
  float endY = startY + (sin(m_angle) * m_length);

  m_x = endX;
  m_y = endY;

  if ((m_pRenderer != NULL) && m_penDown)
  {
    SDL_SetRenderDrawColor(m_pRenderer, m_r, m_g, m_b, m_alpha);
    SDL_RenderDrawLine(m_pRenderer,
      static_cast<int>(round(startX)), static_cast<int>(round(startY)),
      static_cast<int>(round(endX)), static_cast<int>(round(endY)));
  }
}

float Turtle::GetX()
{
  return m_x;
}

float Turtle::GetY()
{
  return m_y;
}

float Turtle::GetAngle()
{
  return m_angle;
}

void Turtle::AssumeStartPosition(int startX, int startY)
{
  // Initialise turtle stuff
  PenUp();
  MoveTo(startX, startY); // move to the middle of the bottom of the window
  SetAngle(- M_PI / 2); // point the turtle up
  PenDown();
  SetLength(5);
}

void Turtle::DrawLeaf()
{
  float originalLength = m_length;
  SetLength(m_length * 2);

  RotateLeft(45);
  for (int i=0; i<4; i++)
  {
    Step();
    RotateRight(90);
  }
  RotateRight(45);

  SetLength(m_length);

}