// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortGender.h"
#include "STW/Heroes/FortCharacterType.h"
#include "FortWorkerType.generated.h"

class UFortItemIconDefinition;

UCLASS(MinimalAPI, NotBlueprintable)
class UFortWorkerType : public UFortCharacterType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Cosmetic")
	TEnumAsByte<EFortCustomGender::Type> Gender;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetic")
	TSoftObjectPtr<UFortItemIconDefinition> FixedPortrait;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Manager")
	bool bIsManager;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Manager", meta=(EditCondition="bIsManager"))
	FGameplayTagContainer ManagerSynergyTag;

	UPROPERTY(EditDefaultsOnly, Category="Manager")
	FGameplayTagContainer FixedPersonalityTag;

	UPROPERTY(EditDefaultsOnly, Category="Worker")
	FGameplayTagContainer FixedSetBonusTag;

	UPROPERTY(EditDefaultsOnly, Category="Manager")
	int32 MatchingPersonalityBonus;

	UPROPERTY(EditDefaultsOnly, Category="Manager")
	int32 MismatchingPersonalityPenalty;

};

