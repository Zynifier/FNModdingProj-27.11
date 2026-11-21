// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/FortControllerComponent.h"
#include "Items/FortItemEntry.h"
#include "Online/Collections/FortMcpCollectableFish.h"
#include "FortControllerComponent_Collections.generated.h"

class APawn;
class UFortControllerComponent_Collections;
enum class ECollectionsComponentValidityResult : uint8;
enum class EFortCollectedState : uint8;

UENUM(BlueprintType)
enum class ECollectionsComponentValidityResult : uint8
{
	IsValid = 0,
	IsNotValid = 1,
};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_Collections : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(ExpandEnumAsExecs="OutIsValid"))
	static UFortControllerComponent_Collections* GetCollectionsComponent(const APawn* Pawn, ECollectionsComponentValidityResult& OutIsValid);

	UFUNCTION(BlueprintCallable)
	void OnFishCollected(const FFortItemEntry& ItemEntry, const FFortMcpCollectedFishProperties& FishProperties, FGameplayTag& OutFishCollectionTag, FGameplayTag& OutAnalyticsTag, EFortCollectedState& OutNewSeenState);

};

