// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "FortMultiSize.h"
#include "SquadManagement/FortSquadTypeLandingPageBase.h"
#include "FortSurvivorSquadSelectorButton.generated.h"

class UFortWorker;

USTRUCT(BlueprintType)
struct FFortSurvivorSquadSelectorButtonPersonalityMatches
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Summary Stats")
	int32 NumPersonalityMatches;

	UPROPERTY(BlueprintReadOnly, Category="Summary Stats")
	int32 TotalNonLeaderSquadMembers;

	UPROPERTY(BlueprintReadOnly, Category="Summary Stats")
	bool HavePersonalityIcons;

	UPROPERTY(BlueprintReadOnly, Category="Summary Stats")
	FFortMultiSizeBrush PersonalityIcons;

};

USTRUCT(BlueprintType)
struct FFortSurvivorSquadSelectorButtonSummaryStats
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Summary Stats")
	FName SquadId;

	UPROPERTY(BlueprintReadOnly, Category="Summary Stats")
	FGameplayAttribute FortAttribute;

	UPROPERTY(BlueprintReadOnly, Category="Summary Stats")
	float FortAttributeValue;

	UPROPERTY(BlueprintReadOnly, Category="Summary Stats")
	FGameplayAttribute FortTeamAttribute;

	UPROPERTY(BlueprintReadOnly, Category="Summary Stats")
	float TeamFortAttributeValue;

	UPROPERTY(BlueprintReadOnly, Category="Summary Stats")
	float SquadPowerValue;

	UPROPERTY(BlueprintReadOnly, Category="Summary Stats")
	FText FortAttributeName;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortSurvivorSquadSelectorButton : public UFortSquadSelectorButton
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="SurivivorSquadData")
	bool TryGetPersonalityMatches(FFortSurvivorSquadSelectorButtonPersonalityMatches& OutPersonalityMatches);

	UFUNCTION(BlueprintPure, Category="SurivivorSquadData")
	bool TryGetSquadMembers(TArray<UFortWorker*>& OutSquadMembers);

	UFUNCTION(BlueprintPure, Category="SurivivorSquadData")
	bool TryGetSummaryStats(FFortSurvivorSquadSelectorButtonSummaryStats& OutSummaryStats);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SurivivorSquadData")
	TArray<FGameplayAttribute> FortStatAttributes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SurivivorSquadData")
	TArray<FGameplayAttribute> FortTeamStatAttributes;

};

