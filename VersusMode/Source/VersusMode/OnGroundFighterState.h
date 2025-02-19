// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "BaseFighterState.h"
#include "CoreMinimal.h"

/**
 * 
 */
class VERSUSMODE_API OnGroundFighterState : public BaseFighterState
{
public:
	void SetMovement(FVector movementDirection) override;
	bool IsA(const std::type_info& type) override;
	void HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input) override;
	void Enter(ABaseFighterCharacter& fighter) override;
	void Exit(ABaseFighterCharacter& fighter) override;
	void Update(ABaseFighterCharacter& fighter, float DeltaTime) override;
	void PhysicsUpdate(ABaseFighterCharacter& fighter) override;
	void AnimationTriggerEvent(ABaseFighterCharacter& fighter) override;
};
