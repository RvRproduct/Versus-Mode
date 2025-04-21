// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "OnGroundFighterState.h"
#include "CoreMinimal.h"

/**
 * 
 */
class VERSUSMODE_API GroundNormalFighterState : OnGroundFighterState
{
public:
	FVector currentFighterMovement = FVector::Zero();

	void SetMovement(FVector movementDirection) override;
	void HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input) override;
	void Enter(ABaseFighterCharacter& fighter) override;
	void Exit(ABaseFighterCharacter& fighter) override;
	void Update(ABaseFighterCharacter& fighter, float DeltaTime) override;
	void PhysicsUpdate(ABaseFighterCharacter& fighter) override;
	void AnimationTriggerEvent(ABaseFighterCharacter& fighter) override;
};
