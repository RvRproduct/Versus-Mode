// By Roberto Valentino Reynoso (RvRproduct)


#include "NormalCommand.h"

// Fighter
#include "VersusMode/Fighters/BaseFighterCharacter.h"
#include "VersusMode/FNormal.h"

void NormalCommand::Execute(ABaseFighterCharacter* fighter)
{
	if (!fighter->fighterAttack->GetAttackActive())
	{
		if (fighter->GetIsOnGround())
		{
			if (fighter->GetIsFacingRight())
			{
				fighter->fighterAttack->SetOffsetForAttack(FVector(180.0f, 0, 0));
			}
			else
			{
				fighter->fighterAttack->SetOffsetForAttack(FVector(-180.0f, 0, 0));
			}
		}
		else
		{
			if (fighter->GetIsAirFacingRight())
			{
				fighter->fighterAttack->SetOffsetForAttack(FVector(180.0f, 0, 0));
			}
			else
			{
				fighter->fighterAttack->SetOffsetForAttack(FVector(-180.0f, 0, 0));
			}
		}
	}
}
