// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AthenaGamePhaseEnum.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_HideHUDElements.generated.h"

USTRUCT(BlueprintType)
struct FHUDElementsToHideData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="HUDElementsToHideData")
	EAthenaGamePhase StartHidingGamePhase;

	UPROPERTY(EditDefaultsOnly, Category="HUDElementsToHideData")
	int32 StartHidingSafeZonePhase;

	UPROPERTY(EditDefaultsOnly, Category="HUDElementsToHideData")
	EAthenaGamePhase StopHidingGamePhase;

	UPROPERTY(EditDefaultsOnly, Category="HUDElementsToHideData")
	int32 StopHidingSafeZonePhase;

	UPROPERTY(EditDefaultsOnly, Category="HUDElementsToHideData")
	FGameplayTagContainer HUDElementsToHide;

};

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_HideHUDElements : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_HideHUDElements")
	TArray<FHUDElementsToHideData> HUDElementsToHideDataArray;

};

