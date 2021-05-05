#include "opponent.h"
void Opponent::Draw(graphics::Image &my_opponent) {
  graphics::Image(GetWidth(), GetHeight());
  my_opponent.DrawRectangle(3 + x_, 2 + y_, 11, 5, 255, 0, 0);
  my_opponent.DrawRectangle(16 + x_, 2 + y_, 11, 5, 255, 0, 0);
  my_opponent.DrawRectangle(28 + x_, 2 + y_, 11, 5, 255, 0, 0);
  my_opponent.DrawRectangle(40 + x_, 2 + y_, 11, 5, 255, 0, 0);
  my_opponent.DrawRectangle(3 + x_, 9 + y_, 11, 5, 255, 0, 0);
  my_opponent.DrawRectangle(16 + x_, 9 + y_, 11, 5, 255, 0, 0);
  my_opponent.DrawRectangle(28 + x_, 9 + y_, 11, 5, 255, 0, 0);
  my_opponent.DrawRectangle(40 + x_, 9 + y_, 11, 5, 255, 0, 0);
  my_opponent.DrawRectangle(3 + x_, 16 + y_, 11, 5, 255, 0, 0);
  my_opponent.DrawRectangle(16 + x_, 16 + y_, 11, 5, 255, 0, 0);
  my_opponent.DrawRectangle(28 + x_, 16 + y_, 11, 5, 255, 0, 0);
  my_opponent.DrawRectangle(40 + x_, 16 + y_, 11, 5, 255, 0, 0);
}
void OpponentProjectile::Draw(graphics::Image &my_opponent_pro) {
  graphics::Image(GetWidth(), GetHeight());
  my_opponent_pro.DrawCircle(x_ + 2, y_ + 2, 2, 255, 0, 0);
  my_opponent_pro.DrawCircle(x_ + 2, y_ + 2, 2, 255, 0, 0);
}
void Opponent::Move(const graphics::Image &move) {
  SetX(GetX() + 1);
  SetY(GetY() + 1);
  if (IsOutOfBounds(move)) {
    SetIsActive(false);
  }
}
void OpponentProjectile::Move(const graphics::Image &move) {
  SetX(GetX() + 1);
  SetY(GetY() + 1);
  if (IsOutOfBounds(move)) {
    SetIsActive(false);
  }
}
std::unique_ptr<OpponentProjectile> Opponent::LaunchProjectile() {
  if (beam_firing_rate >= 10) {
    beam_firing_rate = 0;
    std::unique_ptr<OpponentProjectile> BeamofLight;
    BeamofLight = std::make_unique<OpponentProjectile>();
    return std::move(BeamofLight);
  } else {
    beam_firing_rate++;
    return nullptr;
  }
}
