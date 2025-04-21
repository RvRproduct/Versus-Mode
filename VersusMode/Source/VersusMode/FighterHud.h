// By Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "FighterHud.generated.h"

/**
 * 
 */
UCLASS()
class VERSUSMODE_API UFighterHud : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fighter Percent")
	UTextBlock* FighterOnePercentRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fighter Percent")
	UTextBlock* FighterTwoPercentRef;

	UTextBlock* GetFighterOnePercent();

	UTextBlock* GetFighterTwoPercent();

	void SetFighterOnePercent(float _fighterPercent);

	void SetFighterTwoPercent(float _fighterPercent);

protected:
	virtual void NativeConstruct() override;
};
