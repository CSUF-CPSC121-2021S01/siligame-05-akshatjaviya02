#include <iostream>
#include <string>
#include "cpputils/graphics/image.h"
#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H
class GameElement {
 public:
  GameElement() : x_(0), y_(0), width_(50), height_(50) {}
  GameElement(int x, int y, int width, int height)
      : x_(x), y_(y), width_(width), height_(height) {}
  int GetX() const { return x_; }
  int GetY() const { return y_; }
  bool GetIsActive() const { return active_; }
  void SetIsActive(bool active) { active_ = active; }
  void SetX(int x) { x_ = x; }
  void SetY(int y) { y_ = y; }
  int GetWidth() const { return width_; }
  int GetHeight() const { return height_; }
  virtual void Draw(graphics::Image &rectangle) = 0;
  virtual void Move(const graphics::Image &move) = 0;
  bool IsOutOfBounds(const graphics::Image &bounds);
  bool IntersectsWith(GameElement *element);

 protected:
  int x_;
  int y_;
  int width_;
  int height_;
  bool active_ = true;
};
#endif
