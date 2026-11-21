// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortAIVisibilityDataTable.generated.h"

UENUM(BlueprintType, meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class EAIVisibilityOptions : uint8
{
	None = 0 UMETA(Hidden),
	AlwaysHidden = 1,
	AlwaysVisible = 2,
	HiddenWhenIdle = 4,
	HiddenWhenCrouched = 8,
	HiddenWhenIdleAndCrouched = 12,
	VisibleWhenOverlappingPerceivedActor = 16,
	CheckPriorVisibility = 32,
};

USTRUCT(BlueprintType)
struct FAIVisibilityRangeSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Visibility")
	uint8 bUsesRangeSettings : 1;

	UPROPERTY(EditDefaultsOnly, Category="Visibility", meta=(Bitmask, BitmaskEnum="/Script/FortniteAI.EAIVisibilityOptions"))
	uint8 VisibilitySettings;

	UPROPERTY(EditDefaultsOnly, Category="Visibility", meta=(EditCondition="bUsesRangeSettings", EditConditionHides))
	float Range;

	UPROPERTY(EditDefaultsOnly, Category="Visibility", meta=(EditCondition="VisibilitySettings & '/Script/FortniteAI.EAIVisibilityOptions::HiddenWhenIdle'", EditConditionHides))
	float IdleTime;

};

USTRUCT()
struct FFortAIVisibilityDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Visibility")
	FGameplayTagQuery VisibilityTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="Visibility")
	TArray<FAIVisibilityRangeSettings> RangeSettings;

};

