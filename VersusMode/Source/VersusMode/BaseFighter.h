// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

class BaseFighterState;
class BaseCommand;

/**
 * 
 */
class VERSUSMODE_API BaseFighter
{
public:
	BaseFighter();
	virtual ~BaseFighter();
protected:
	BaseCommand* wKey;
	BaseCommand* sKey;
	BaseCommand* aKey;
	BaseCommand* dKey;
	BaseCommand* noKey;
	BaseCommand* spacebar;
	BaseCommand* slideLeft;
	BaseCommand* slideRight;
	BaseCommand* superSlideLeft;
	BaseCommand* superSlideRight;

	BaseFighterState* currentState;

	float jumpHeight;
	int numberOfJumps;
	float weight;
	float groundWalkSpeed;
	float groundRunSpeed;
	float groundSlideRate;
	float groundSuperSlideMultiplier;
	float airSpeed;
	float gravity;
	float meterAmount;

	bool isFacingRight;
	bool isRunning;

public:
	bool GetIsRunning()
	{
		return isRunning;
	}

	BaseFighterState* GetCurrentState()
	{
		return currentState;
	}

	void SetCurrentState(BaseFighterState* newState)
	{
		BaseFighterState* oldState = currentState;
		currentState = newState;
		delete oldState;
	}

protected:
	virtual void SetStats() = 0;
};
