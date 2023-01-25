#include "KeyInputSystem.h"

void KeyInputSystem::handleKeyInput(SDL_Event* e, DynamicObject* p, OverworldState state, LocationManager* lm)
{
	// Check if key is pressed
	if (e->type == SDL_KEYDOWN)
	{
		SDL_KeyCode keyPressed = static_cast<SDL_KeyCode>(e->key.keysym.sym);

		switch (state)
		{
			case OverworldState::null:
			case OverworldState::Event:
			case OverworldState::Transition_FadeIn:
			case OverworldState::Transition_FadeOut:
			case OverworldState::Transition_Inside_ChangeWorld:
			case OverworldState::Transition_Outside_ChangeWorld:
				std::cout << "Cannot press key at this time" << std::endl;
				break;

			case OverworldState::Overworld:
			case OverworldState::Inside:
				handlePlayerInput(keyPressed, p, state, lm);
				break;

			case OverworldState::Battle:
				// Handle battle input
				break;

			case OverworldState::Paused:
				// handle pause input
				break;

			case OverworldState::Dialog:
				// handle dialogue input
				break;
		}

	}
}

void KeyInputSystem::handlePlayerInput(SDL_Keycode key, DynamicObject* p, OverworldState state, LocationManager* lm)
{
	KeyComponent* kc = ComponentCasting::KeyCasting(p->getComponent(Component_Type::KEY));

	if (kc == nullptr)
	{
		return;
	}

	KeyAction ka = kc->getKey(key);

	switch (ka)
	{
		case KeyAction::MoveUp:
			MovementSystem::MoveUp(p, lm);
			break;
		case KeyAction::MoveDown:
			MovementSystem::MoveDown(p, lm);
			break;
		case KeyAction::MoveLeft:
			MovementSystem::MoveLeft(p, lm);
			break;
		case KeyAction::MoveRight:
			MovementSystem::MoveRight(p, lm);
			break;
		case KeyAction::Pause:
			OverworldStateController::changeState(OverworldState::Paused);
			break;
	}
}
