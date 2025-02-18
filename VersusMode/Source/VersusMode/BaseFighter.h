// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "BaseCommand.h"
#include "JumpCommand.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"
#include "MoveUpCommand.h"
#include "MoveDownCommand.h"
#include "RunLeftCommand.h"
#include "RunRightCommand.h"
#include "SlideLeftCommand.h"
#include "SlideRightCommand.h"
#include "SuperSlideLeftCommand.h"
#include "SuperSlideRightCommand.h"
#include "FastFallCommand.h"
#include "CoreMinimal.h"

class BaseFighterState;

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
	BaseCommand* spacebar;
	BaseCommand* runLeft;
	BaseCommand* runRight;
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
protected:
	virtual void SetStats() = 0;
};
