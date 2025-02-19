// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "CoreMinimal.h"

class ABaseFighterCharacter;

/**
 * 
 */
class VERSUSMODE_API BaseCommand
{
public:
	BaseCommand();
	virtual ~BaseCommand();
	virtual void Execute(ABaseFighterCharacter* fighter) = 0;
};
