// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortPlayerPerksItemDefinition.generated.h"

class UDataTable;
class UFortSpyTechItemDefinition;

USTRUCT(BlueprintType)
struct FPlayerPerkLevel
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PlayerPerkLevel")
	TArray<TObjectPtr<UFortSpyTechItemDefinition>> PlayerPerks;

};

USTRUCT(BlueprintType)
struct FTechCurrentLevelCap
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="TechCurrentLevelCap")
	FString CalendarEvent;

	UPROPERTY(EditAnywhere, Category="TechCurrentLevelCap")
	FString EventFlag;

	UPROPERTY(EditAnywhere, Category="TechCurrentLevelCap")
	int32 LevelCap;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Frontend", "Tooltips", "Functionality", "OwnedTags", "FortItemDefinition"))
class UFortPlayerPerksItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortPlayerPerksItemDefinition")
	FGameplayTag SecondaryXpSource;

	UPROPERTY(EditAnywhere, Category="FortPlayerPerksItemDefinition", meta=(DisplayThumbnail="false"))
	TObjectPtr<UDataTable> XpCurve;

	UPROPERTY(EditAnywhere, EditFixedSize, Category="FortPlayerPerksItemDefinition")
	TArray<FPlayerPerkLevel> PlayerPerkLevels;

	UPROPERTY(EditAnywhere, Category="FortPlayerPerksItemDefinition")
	TArray<FTechCurrentLevelCap> LevelCaps;

};

