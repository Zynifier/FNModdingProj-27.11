// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "Fonts/SlateFontInfo.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortMapLocationStateType.h"
#include "FortGameStateComponent_MiniMapDataOverride.generated.h"

USTRUCT()
struct FMiniMapDataOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="MiniMapDataOverride")
	FGameplayTagContainer ContextTags;

	UPROPERTY(EditAnywhere, Category="MiniMapDataOverride")
	FSlateFontInfo LocationFont;

	UPROPERTY(EditAnywhere, Category="LocationFont")
	uint32 MobileFontSizeOverride;

	UPROPERTY(EditAnywhere, Category="MiniMapDataOverride")
	EMapLocationStateType StateType;

	UPROPERTY(EditAnywhere, Category="MiniMapDataOverride")
	FVector MobilePositionOffset;

};

USTRUCT()
struct FMiniMapDataOverrideRepData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTagContainer ContextTags;

	UPROPERTY()
	FGameplayTagContainer LocationTags;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_MiniMapDataOverride : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UFortGameStateComponent_MiniMapDataOverride(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	const FGameplayTagContainer GetContextTagsForLocationTag(const FGameplayTag LocationTag) const;

	UFUNCTION(BlueprintCallable)
	void OverrideLocations(const FGameplayTagContainer& ContextTags, const FGameplayTagContainer& LocationTags);

private:
	UFUNCTION()
	void OnRep_MiniMapDataOverridesRepDatas();

	UPROPERTY(EditAnywhere, Category="FortGameStateComponent_MiniMapDataOverride")
	TArray<FMiniMapDataOverride> MiniMapDataOverrides;

	UPROPERTY(ReplicatedUsing=OnRep_MiniMapDataOverridesRepDatas)
	TArray<FMiniMapDataOverrideRepData> MiniMapDataOverrideRepDatas;

};

