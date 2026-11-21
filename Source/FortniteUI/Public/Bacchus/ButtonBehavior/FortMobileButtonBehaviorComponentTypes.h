// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "FortMobileButtonBehaviorComponentTypes.generated.h"

class UPaperSprite;

UENUM(BlueprintType)
enum class ETagComparisonType : uint8
{
	HasAny = 0,
	HasAll = 1,
	HasNone = 2,
	HasAnyExact = 3,
	HasAllExact = 4,
};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FIconPicker
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="IconPicker")
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, Category="IconPicker")
	ETagComparisonType ComparisonType;

	UPROPERTY(EditDefaultsOnly, Category="IconPicker")
	TObjectPtr<UPaperSprite> Sprite;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FTagColor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TagColor")
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, Category="TagColor")
	ETagComparisonType ComparisonType;

	UPROPERTY(EditDefaultsOnly, Category="TagColor")
	FColor Color;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FTagFilterOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TagFilterOverride")
	FGameplayTagContainer OverridingTags;

	UPROPERTY(EditDefaultsOnly, Category="TagFilterOverride")
	ETagComparisonType ComparisonTypeToOverride;

	UPROPERTY(EditDefaultsOnly, Category="TagFilterOverride")
	FGameplayTagContainer TagsToFilterOut;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FTagVisibility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TagVisibility")
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, Category="TagVisibility")
	ETagComparisonType ComparisonType;

	UPROPERTY(EditDefaultsOnly, Category="TagVisibility")
	ESlateVisibility Visibility;

};

