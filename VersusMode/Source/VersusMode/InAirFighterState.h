// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "BaseFighterState.h"
#include "CoreMinimal.h"

/**
 * 
 */
class VERSUSMODE_API InAirFighterState : public BaseFighterState
{
public:
	void HandleInput(BaseFighter& fighter, BaseCommand& input) override;
	void Enter(BaseFighter& fighter) override;
	void Exit(BaseFighter& fighter) override;
	void Update(BaseFighter& fighter) override;
	void PhysicsUpdate(BaseFighter& fighter) override;
	void AnimationTriggerEvent(BaseFighter& fighter) override;
};
