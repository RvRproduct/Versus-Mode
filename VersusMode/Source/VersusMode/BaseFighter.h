// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class VERSUSMODE_API BaseFighter
{
public:
	BaseFighter();
	virtual ~BaseFighter();
protected:
	float jumpHeight;
	int numberOfJumps;
	float weight;
	float groundWalkSpeed;
	float groundRunSpeed;
	float groundSlideRate;
	float airSpeed;
	float gravity;
	float meterAmount;
protected:
	virtual void SetStats() = 0;
};
