// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "InAirFighterState.h"
#include "CoreMinimal.h"

/**
 * 
 */
class VERSUSMODE_API FastFallFighterState : public InAirFighterState
{
public:
	void HandleInput(BaseFighter& fighter, BaseCommand& input) override;
	void Enter(BaseFighter& fighter) override;
	void Exit(BaseFighter& fighter) override;
	void Update(BaseFighter& fighter) override;
	void PhysicsUpdate(BaseFighter& fighter) override;
	void AnimationTriggerEvent(BaseFighter& fighter) override;
};
