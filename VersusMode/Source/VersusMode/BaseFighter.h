// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "BaseCommand.h"
#include "JumpCommand.h"
#include "MoveCommand.h"
#include "RunCommand.h"
#include "SlideCommand.h"
#include "SuperSlideCommand.h"
#include "CrouchCommand.h"
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

	BaseFighterState* currentState;

	float jumpHeight;
	int numberOfJumps;
	float weight;
	float groundWalkSpeed;
	float groundRunSpeed;
	float groundSlideRate;
	float airSpeed;
	float gravity;
	float meterAmount;
protected:
	virtual void SetStats() = 0;
};
