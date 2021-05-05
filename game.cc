#include "game.h"

void Game::Init() {
  screen_.AddMouseEventListener(*this);
  screen_.AddAnimationEventListener(*this);
  player_.SetX(10);
  player_.SetY(screen_.GetHeight() - 75);
}

void Game::CreateOpponents() {
  for (int i = 0; i < 5; i++) {
    opponent_.push_back(std::make_unique<Opponent>(50 * i + 15, 50));
  }
}

int Game::GetScore() { return game_score_; }

bool Game::HasLost() { return Lost; }

void Game::UpdateScreen() {
  screen_.DrawRectangle(0, 0, 800, 600, 255, 255, 255);
  for (int i = 0; i < opponent_.size(); i++) {
    if (opponent_[i]->GetIsActive() == true) {
      opponent_[i]->Draw(screen_);
    }
  }
  for (int i = 0; i < opponent_pro.size(); i++) {
    if (opponent_pro[i]->GetIsActive() == true) {
      opponent_pro[i]->Draw(screen_);
    }
  }
  for (int i = 0; i < player_pro.size(); i++) {
    if (player_pro[i]->GetIsActive() == true) {
      player_pro[i]->Draw(screen_);
    }
  }
  if (player_.GetIsActive() == true) {
    player_.Draw(screen_);
  }

  screen_.DrawText(10, 10, std::to_string(game_score_), 35, 0, 0, 0);
}

void Game::MoveGameElements() {
  for (int i = 0; i < player_pro.size(); i++) {
    player_pro[i]->Move(screen_);
  }
  for (int i = 0; i < opponent_pro.size(); i++) {
    opponent_pro[i]->Move(screen_);
  }
  for (int i = 0; i < opponent_.size(); i++) {
    opponent_[i]->Move(screen_);
  }
}

void Game::FilterIntersections() {
  // plane and UFO
  for (int j = 0; j < opponent_.size(); j++) {
    if (player_.IntersectsWith(opponent_[j].get()) == true) {
      player_.SetIsActive(false);
      opponent_[j]->SetIsActive(false);
      Lost = true;
    }
  }
  // Beam and Plane
  for (int i = 0; i < opponent_pro.size(); i++) {
    if (opponent_pro[i]->IntersectsWith(&player_) == true) {
      player_.SetIsActive(false);
      opponent_pro[i]->SetIsActive(false);
      Lost = true;
    }
  }
  // Bullet and UFO
  for (int p = 0; p < player_pro.size(); p++) {
    for (int k = 0; k < opponent_.size(); k++) {
      if (player_pro[p]->IntersectsWith(opponent_[k].get()) == true) {
        player_pro[p]->SetIsActive(false);
        opponent_[k]->SetIsActive(false);
        if (player_.GetIsActive() == true) {
          game_score_++;
        }
      }
    }
  }
}
void Game::OnAnimationStep() {
  if (opponent_.size() == 0) {
    CreateOpponents();
  }
  MoveGameElements();
  LaunchProjectiles();
  FilterIntersections();
  RemoveInactive();
  UpdateScreen();
  screen_.Flush();
}

void Game::LaunchProjectiles() {
  for (int i = 0; i < opponent_.size(); i++) {
    if (opponent_[i]->LaunchProjectile() != nullptr) {
      std::unique_ptr<OpponentProjectile> Cannon;
      Cannon = std::make_unique<OpponentProjectile>();
      Cannon->SetX(opponent_[i]->GetX());
      Cannon->SetY(opponent_[i]->GetY());
      opponent_pro.push_back(std::move(Cannon));
    }
  }
}

void Game::OnMouseEvent(const graphics::MouseEvent &mouse) {
  if (mouse.GetX() > 0 && mouse.GetY() > 0 &&
      mouse.GetX() < screen_.GetWidth() && mouse.GetY() < screen_.GetHeight()) {
    player_.SetX(mouse.GetX() - 25);
    player_.SetY(mouse.GetY() - 25);
  }
  if (mouse.GetMouseAction() == graphics::MouseAction::kPressed) {
    std::unique_ptr<PlayerProjectile> Missle =
        std::make_unique<PlayerProjectile>(mouse.GetX(), mouse.GetY() + 25);
    player_pro.push_back(std::move(Missle));
  }
  if (mouse.GetMouseAction() == graphics::MouseAction::kDragged) {
    std::unique_ptr<PlayerProjectile> Missle =
        std::make_unique<PlayerProjectile>(mouse.GetX(), mouse.GetY() + 25);
    player_pro.push_back(std::move(Missle));
  }
}

void Game::RemoveInactive() {
  for (int i = player_pro.size() - 1; i >= 0; i--) {
    if (player_pro[i]->GetIsActive() == false) {
      player_pro.erase(player_pro.begin() + i);
    }
  }
  for (int i = opponent_pro.size() - 1; i >= 0; i--) {
    if (opponent_pro[i]->GetIsActive() == false) {
      opponent_pro.erase(opponent_pro.begin() + i);
    }
  }
  for (int i = opponent_.size() - 1; i >= 0; i--) {
    if (!opponent_[i]->GetIsActive()) {
      opponent_.erase(opponent_.begin() + i);
    }
  }
}
