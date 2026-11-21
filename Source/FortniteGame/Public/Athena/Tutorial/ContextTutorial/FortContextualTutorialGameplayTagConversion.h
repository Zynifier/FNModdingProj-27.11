// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortContextualTutorialGameplayTagConversion.generated.h"

UCLASS(Config=Game, MinimalAPI, BlueprintType)
class UFortContextualTutorialGameplayTagConversion : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialGameplayTagConversion")
	TMap<int32, FGameplayTag> ContextualTutorialIndexToGameplayTags;

};

