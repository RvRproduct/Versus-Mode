// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "CoreMinimal.h"

class BaseFighter;

/**
 * 
 */
class VERSUSMODE_API BaseCommand
{
public:
	BaseCommand();
	virtual ~BaseCommand();
	virtual void Execute(BaseFighter* fighter) = 0;
};
