// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "BaseCommand.h"
#include "CoreMinimal.h"

/**
 * 
 */
class VERSUSMODE_API MoveDownCommand : public BaseCommand
{
public:
	void Execute(ABaseFighterCharacter* fighter) override;
};
