// By Roberto Valentino Reynoso (RvRproduct)


#include "FighterHud.h"

void UFighterHud::NativeConstruct()
{
	Super::NativeConstruct();
	SetFighterOnePercent(0.0f);
	SetFighterTwoPercent(0.0f);
}

UTextBlock* UFighterHud::GetFighterOnePercent()
{
	return FighterOnePercentRef;
}

UTextBlock* UFighterHud::GetFighterTwoPercent()
{
	return FighterTwoPercentRef;
}

void UFighterHud::SetFighterOnePercent(float _fighterPercent)
{
	int32 percentToInt = FMath::RoundToInt(_fighterPercent);
	FString percentToString = FString::FromInt(percentToInt);
	percentToString.Append(" %");
	FighterOnePercentRef->SetText(FText::FromString(percentToString));
}

void UFighterHud::SetFighterTwoPercent(float _fighterPercent)
{
	int32 percentToInt = FMath::RoundToInt(_fighterPercent);
	FString percentToString = FString::FromInt(percentToInt);
	percentToString.Append(" %");
	FighterTwoPercentRef->SetText(FText::FromString(percentToString));
}

