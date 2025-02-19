// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "BaseCommand.h"
#include "CoreMinimal.h"

/**
 * 
 */
class VERSUSMODE_API SlideLeftCommand : public BaseCommand
{
public:
	void Execute(BaseFighter* fighter) override;
};
