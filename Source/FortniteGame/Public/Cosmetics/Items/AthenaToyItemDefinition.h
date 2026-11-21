// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaDanceItemDefinition.h"
#include "AthenaToyItemDefinition.generated.h"

class AActor;
class AFortToyPreviewActor;
class UFortGameplayAbility;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition", "Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaToyItemDefinition : public UAthenaDanceItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(meta=(CallInEditor="true"))
	void BakeLaunchPositions();

	UFUNCTION(BlueprintPure)
	TSoftClassPtr<AActor> GetToyActorClass() const;

protected:
	UPROPERTY(EditAnywhere, Category="Visual")
	TSoftClassPtr<UFortGameplayAbility> ToySpawnAbility;

	UPROPERTY(EditAnywhere, Category="Visual")
	TSoftClassPtr<AActor> ToyActorClass;

	UPROPERTY(EditAnywhere, Category="Visual")
	TSoftClassPtr<AFortToyPreviewActor> FrontEndPreviewActor;

};

