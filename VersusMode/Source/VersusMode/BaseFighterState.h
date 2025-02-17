// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "BaseFighter.h"
#include "BaseCommand.h"
#include "CoreMinimal.h"

/**
 * 
 */
class VERSUSMODE_API BaseFighterState
{
public:
	BaseFighterState();
	virtual ~BaseFighterState();

	virtual void HandleInput(BaseFighter& fighter, BaseCommand& input) = 0;
	virtual void Enter(BaseFighter& fighter) = 0;
	virtual void Exit(BaseFighter& fighter) = 0;
	virtual void Update(BaseFighter& fighter) = 0;
	virtual void PhysicsUpdate(BaseFighter& fighter) = 0;
	virtual void AnimationTriggerEvent(BaseFighter& fighter) = 0;
};
