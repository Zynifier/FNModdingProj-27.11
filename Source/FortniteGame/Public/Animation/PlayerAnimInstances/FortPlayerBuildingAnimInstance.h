// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "Building/BuildingTypes.h"
#include "FortGender.h"
#include "FortPlayerBuildingAnimInstance.generated.h"

class AFortPlayerPawn;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPlayerBuildingAnimInstance : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerBuildingAnimInstance")
	TObjectPtr<AFortPlayerPawn> FortPlayerPawn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerBuildingAnimInstance")
	TEnumAsByte<EFortBuildingState::Type> BuildingState;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerBuildingAnimInstance")
	TEnumAsByte<EFortCustomGender::Type> Gender;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerBuildingAnimInstance")
	uint8 bIsCrouching : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerBuildingAnimInstance")
	uint8 bIsInBuildingEditMode : 1;

};

