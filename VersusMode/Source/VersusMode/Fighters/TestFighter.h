// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "CoreMinimal.h"
#include "BaseFighterCharacter.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "TestFighter.generated.h"

UCLASS()
class VERSUSMODE_API ATestFighter : public ABaseFighterCharacter
{
	GENERATED_BODY()
public:
	ATestFighter();

protected:
	void SetStats() override;
};
