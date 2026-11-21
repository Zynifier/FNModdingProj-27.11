// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Online/Collections/FortMcpCollectionBase.h"
#include "FortMcpCollectionPlayerAugment.generated.h"

class AFortPlayerController;

USTRUCT(BlueprintType)
struct FFortMcpCollectedPlayerAugmentProperties
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortMcpCollectionPlayerAugment : public UFortMcpCollectionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void AddToPlayerCollection(const AFortPlayerController* PlayerController, const FGameplayTag PlayerAugmentVariantTag);

	UFUNCTION(BlueprintCallable)
	static void MarkSeenForPlayer(AFortPlayerController* PlayerController, FGameplayTag VariantTag);

};

