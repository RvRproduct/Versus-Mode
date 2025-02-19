// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "BaseFighterCharacter.h"
#include "CoreMinimal.h"

/**
 * 
 */
class VERSUSMODE_API BaseFighterState
{
public:
	BaseFighterState() = default;
	virtual ~BaseFighterState() = default;

	virtual bool IsA(const std::type_info& type) = 0;
	virtual void SetMovement(FVector movementDirection) = 0;
	virtual void HandleInput(ABaseFighterCharacter& fighter, BaseCommand& input) = 0;
	virtual void Enter(ABaseFighterCharacter& fighter) = 0;
	virtual void Exit(ABaseFighterCharacter& fighter) = 0;
	virtual void Update(ABaseFighterCharacter& fighter, float DeltaTime) = 0;
	virtual void PhysicsUpdate(ABaseFighterCharacter& fighter) = 0;
	virtual void AnimationTriggerEvent(ABaseFighterCharacter& fighter) = 0;
};
