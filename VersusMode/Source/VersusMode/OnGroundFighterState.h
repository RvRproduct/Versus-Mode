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
	void HandleInput(BaseFighter& fighter, BaseCommand& input) override;
};
