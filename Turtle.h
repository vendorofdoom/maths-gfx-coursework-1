#ifndef TURTLE_H
#define TURTLE_H

#include <SDL2/SDL.h>

class Turtle
{
  public:
    Turtle();

    void SetRenderer(SDL_Renderer *m_pRenderer);

    void PenUp();
    void PenDown();
    void SetPenColour(int r, int g, int b, int alpha);

    void SetAngle(float angle);
    void SetLength(float length);
    void RotateRight(float angle);
    void RotateLeft(float left);
    void LookAt(float xPos, float yPos);

    void MoveTo(float xPos, float yPos);

    float GetX();
    float GetY();
    float GetAngle();

    void Step();

    void AssumeStartPosition(int startX, int startY);
    void DrawLeaf();

    private:
      SDL_Renderer *m_pRenderer;
      float m_x, m_y;
      float m_angle, m_length;
      int m_r, m_g, m_b, m_alpha;
      bool m_penDown;
};

#endif