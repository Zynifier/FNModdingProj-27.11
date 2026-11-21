// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "GameplayTagContainer.h"
#include "FortPlayerCustomizableInterface.h"
#include "FortGameplayMutator.generated.h"

class UFortMutatorListComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameplayMutator : public AInfo, public IFortPlayerCustomizable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Mutator")
	FORTNITEGAME_API bool IsMutatorActive() const;

	UFUNCTION(BlueprintCallable, Category="Mutator")
	FORTNITEGAME_API void SetMutatorActive(bool bEnable);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Mutator", meta=(DisplayName="OnMutatorListPropertiesApplied"))
	FORTNITEGAME_API void BP_OnMutatorListPropertiesApplied(UFortMutatorListComponent* MutatorList);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_bMutatorActive();

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_bMutatorActive, Category="Mutator")
	uint8 bMutatorActive : 1;

	UPROPERTY(EditDefaultsOnly, Category="Mutator", meta=(Bitmask, BitmaskEnum="/Script/FortniteGame.EFortMinigameState"))
	uint32 MutatorEnabledMinigameStates;

	UPROPERTY(EditDefaultsOnly, Category="Mutator")
	bool bAvailableInEditMode;

	UPROPERTY(EditDefaultsOnly, Category="Mutator")
	bool bNetworkDormantWhenDeactivated;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mutator")
	FGameplayTagContainer GameplayTagContainer;

};

