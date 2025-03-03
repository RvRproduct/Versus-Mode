// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "CoreMinimal.h"
#include "BaseFighterCharacter.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "AITestFighter.generated.h"

UCLASS()
class VERSUSMODE_API AAITestFighter : public ABaseFighterCharacter
{
	GENERATED_BODY()

public:
	AAITestFighter();

protected:
	void SetStats() override;

};
