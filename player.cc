#include "player.h"

void Player::Draw(graphics::Image &my_player) {
  // player right side
  graphics::Image(GetWidth(), GetHeight());

  my_player.DrawLine(21 + x_, 15 + y_, 23 + x_, 15 + y_, 0, 0, 0, 1);
  my_player.DrawLine(23 + x_, 15 + y_, 23 + x_, 18 + y_, 0, 0, 0, 1);
  my_player.DrawLine(23 + x_, 18 + y_, 24 + x_, 18 + y_, 0, 0, 0, 1);
  my_player.DrawLine(24 + x_, 18 + y_, 24 + x_, 22 + y_, 0, 0, 0, 1);
  my_player.DrawLine(25 + x_, 23 + y_, 25 + x_, 20 + y_, 0, 0, 0, 1);
  my_player.DrawLine(24 + x_, 20 + y_, 27 + x_, 20 + y_, 0, 0, 0, 1);
  my_player.DrawLine(27 + x_, 20 + y_, 27 + x_, 27 + y_, 0, 0, 0, 1);
  my_player.DrawLine(28 + x_, 24 + y_, 28 + x_, 28 + y_, 0, 0, 0, 1);
  my_player.DrawLine(28 + x_, 24 + y_, 30 + x_, 24 + y_, 0, 0, 0, 1);
  // bottom side
  my_player.DrawLine(30 + x_, 24 + y_, 30 + x_, 33 + y_, 0, 0, 0, 1);
  my_player.DrawLine(30 + x_, 33 + y_, 28 + x_, 33 + y_, 0, 0, 0, 1);
  my_player.DrawLine(28 + x_, 33 + y_, 28 + x_, 32 + y_, 0, 0, 0, 1);
  my_player.DrawLine(28 + x_, 32 + y_, 23 + x_, 32 + y_, 0, 0, 0, 1);

  my_player.DrawLine(27 + x_, 32 + y_, 27 + x_, 31 + y_, 0, 0, 0, 1);
  my_player.DrawLine(26 + x_, 32 + y_, 26 + x_, 30 + y_, 0, 0, 0, 1);
  my_player.DrawLine(23 + x_, 33 + y_, 23 + x_, 31 + y_, 0, 0, 0, 1);
  my_player.DrawLine(23 + x_, 33 + y_, 21 + x_, 33 + y_, 0, 0, 0, 1);
  my_player.DrawLine(21 + x_, 33 + y_, 21 + x_, 31 + y_, 0, 0, 0, 1);
  my_player.DrawLine(21 + x_, 32 + y_, 16 + x_, 32 + y_, 0, 0, 0, 1);
  my_player.DrawLine(17 + x_, 31 + y_, 17 + x_, 32 + y_, 0, 0, 0, 1);
  my_player.DrawLine(18 + x_, 30 + y_, 18 + x_, 32 + y_, 0, 0, 0, 1);
  my_player.DrawLine(16 + x_, 33 + y_, 14 + x_, 33 + y_, 0, 0, 0, 1);
  my_player.DrawRectangle(24 + x_, 30 + y_, 2, 2, 255, 0, 0);
  my_player.DrawRectangle(19 + x_, 30 + y_, 2, 2, 255, 0, 0);
  my_player.SetRed(20 + x_, 29 + y_, 1);
  my_player.SetRed(24 + x_, 29 + y_, 1);
  // left side
  my_player.DrawLine(14 + x_, 33 + y_, 14 + x_, 24 + y_, 0, 0, 0, 1);
  my_player.DrawLine(17 + x_, 24 + y_, 14 + x_, 24 + y_, 0, 0, 0, 1);
  my_player.SetBlue(18 + x_, 25 + y_, 1);
  my_player.SetBlue(19 + x_, 24 + y_, 1);
  my_player.SetBlue(25 + x_, 24 + y_, 1);
  my_player.SetBlue(26 + x_, 25 + y_, 1);
  my_player.DrawLine(16 + x_, 24 + y_, 16 + x_, 28 + y_, 255, 0, 0, 1);
  my_player.DrawLine(17 + x_, 20 + y_, 17 + x_, 27 + y_, 255, 0, 0, 1);
  my_player.DrawLine(17 + x_, 20 + y_, 20 + x_, 20 + y_, 255, 0, 0, 1);
  my_player.DrawLine(19 + x_, 20 + y_, 19 + x_, 23 + y_, 255, 0, 0, 1);

  my_player.DrawLine(20 + x_, 22 + y_, 22 + x_, 18 + y_, 0, 0, 0, 1);
  my_player.DrawLine(20 + x_, 18 + y_, 21 + x_, 18 + y_, 0, 0, 0, 1);
  my_player.DrawLine(21 + x_, 18 + y_, 21 + x_, 15 + y_, 0, 0, 0, 1);
}
void PlayerProjectile::Draw(graphics::Image &my_player_pro) {
  // opponent projectile
  graphics::Image(GetWidth(), GetHeight());
  my_player_pro.DrawCircle(2 + x_, 2 + y_, 2, 0, 0, 255);
  my_player_pro.DrawCircle(2 + x_, 2 + y_, 2, 0, 0, 255);
}
void Player::Move(const graphics::Image &move) {}
void PlayerProjectile::Move(const graphics::Image &move) {
  SetY(GetY() - 1);
  if (IsOutOfBounds(move)) {
    SetIsActive(false);
  }
}
