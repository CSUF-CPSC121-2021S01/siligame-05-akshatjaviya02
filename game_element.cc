#include "game_element.h"

bool GameElement::IsOutOfBounds(const graphics::Image &bounds) {
  if (GetX() < 0 || GetX() + GetWidth() > bounds.GetWidth()) {
    return true;
  } else if (GetY() < 0 || GetY() + GetHeight() > bounds.GetHeight()) {
    return true;
  } else {
    return false;
  }
}
bool GameElement::IntersectsWith(GameElement *element) {
  return !(GetX() > element->GetX() + element->GetWidth() ||
           element->GetX() > GetX() + GetWidth() ||
           GetY() > element->GetY() + element->GetHeight() ||
           element->GetY() > GetY() + GetHeight());
}
