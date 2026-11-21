// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortGameplayTagContainer.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisplayName="Generic Gameplay Tag Container"))
class UFortGameplayTagContainer : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay Tag Container")
	FGameplayTagContainer GameplayTags;

};

