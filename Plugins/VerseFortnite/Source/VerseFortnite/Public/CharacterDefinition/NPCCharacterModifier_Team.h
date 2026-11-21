// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterDefinition/NPCCharacterModifier.h"
#include "NPCCharacterModifier_Team.generated.h"

UENUM()
enum class ETeamOption : uint8
{
	TeamIndex = 0,
	TeamWildlifeAndCreature = 1,
	TeamNeutral = 2,
};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisplayName="NPC Character Team Modifier"))
class UNPCCharacterModifier_Team : public UNPCCharacterModifier
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Team", meta=(AllowPrivateAccess="true"))
	ETeamOption TeamOption;

	UPROPERTY(EditAnywhere, Category="Team", meta=(AllowPrivateAccess="true", ClampMax="100", ClampMin="1", EditCondition="TeamOption == ETeamOption::TeamIndex"))
	uint32 TeamIndex;

};

