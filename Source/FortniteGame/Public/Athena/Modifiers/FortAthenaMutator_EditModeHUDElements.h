// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortPropertyOverrideData.h"
#include "FortAthenaMutator_EditModeHUDElements.generated.h"

UCLASS(Abstract, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"), meta=(NotBlueprintType="true"))
class AFortAthenaMutator_EditModeHUDElements : public AFortAthenaMutator
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleMutatorSettingsChanged(const FPropertyOverrideData& OverrideData);

	UFUNCTION()
	void OnRep_PendingNotify();

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Edit Mode HUD")
	FGameplayTagContainer HealthAndShieldHUDElements;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Edit Mode HUD")
	FGameplayTagContainer ResourcesHUDElements;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Edit Mode HUD")
	FGameplayTagContainer BelowMinimapInfoHUDElements;

	UPROPERTY()
	bool bShowHealthAndShieldEditMode;

	UPROPERTY()
	bool bShowResourcesEditMode;

	UPROPERTY()
	bool bShowBelowMinimapInfoEditMode;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PendingNotify)
	bool bPendingNotify;

};

