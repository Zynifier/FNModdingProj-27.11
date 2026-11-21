// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Building/EditMode/BuildingEditModeMetadata_BinaryToggle.h"
#include "Building/EditMode/BuildingEditModeSupport.h"
#include "BuildingEditModeSupport_BinaryToggle.generated.h"

class UBuildingEditModeMetadata_BinaryToggle;

UCLASS(Abstract)
class UBuildingEditModeSupport_BinaryToggle : public UBuildingEditModeSupport
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<UBuildingEditModeMetadata_BinaryToggle> BinaryTogglePreviewData;

	UPROPERTY(Transient)
	TEnumAsByte<EBinaryToggleValues> CurToggleAction;

	UPROPERTY(Transient)
	FLinearColor DefaultBlueTileColor;

};

