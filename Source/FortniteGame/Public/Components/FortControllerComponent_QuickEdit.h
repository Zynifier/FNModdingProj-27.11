// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_QuickEdit.generated.h"

class UBuildingEditModeMetadata_Floor;
class UBuildingEditModeMetadata_Roof;
class UBuildingEditModeMetadata_Stair;
class UBuildingEditModeMetadata_Wall;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_QuickEdit : public UFortControllerComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnBuildingQuickEditOptionChanged, const FName, QuickEditClassName, const bool, bPreviewMirrored, const uint8, PreviewRotations);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="EditMode")
	TArray<TObjectPtr<UBuildingEditModeMetadata_Wall>> QuickEditWallPatterns;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="EditMode")
	TArray<TObjectPtr<UBuildingEditModeMetadata_Floor>> QuickEditFloorPatterns;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="EditMode")
	TArray<TObjectPtr<UBuildingEditModeMetadata_Roof>> QuickEditRoofPatterns;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="EditMode")
	TArray<TObjectPtr<UBuildingEditModeMetadata_Stair>> QuickEditStairsPatterns;

	UPROPERTY(BlueprintAssignable, Category="Building")
	FOnBuildingQuickEditOptionChanged OnBuildingQuickEditOptionChanged;

	UPROPERTY(Transient, Replicated)
	bool bEnabled;

};

