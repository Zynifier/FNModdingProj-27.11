// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortAbilityTagRelationshipMapping.generated.h"

USTRUCT()
struct FFortAbilityTagRelationship
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Ability", meta=(Categories="Gameplay.Action"))
	FGameplayTag AbilityTag;

	UPROPERTY(EditAnywhere, Category="Ability")
	bool bExactAbilityTagMatchOnly;

	UPROPERTY(EditAnywhere, Category="Ability", meta=(Categories="Gameplay.Action"))
	FGameplayTagContainer AbilityTagsToBlock;

	UPROPERTY(EditAnywhere, Category="Ability", meta=(Categories="Gameplay.Action"))
	FGameplayTagContainer AbilityTagsToCancel;

};

UCLASS()
class UFortAbilityTagRelationshipMapping : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Ability", meta=(TitleProperty="AbilityTag"))
	TArray<FFortAbilityTagRelationship> AbilityTagRelationships;

};

