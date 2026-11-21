// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortColorPickerConfiguration.generated.h"

UENUM(BlueprintType)
enum class EColorPickerColorRepresentation : uint8
{
	HSV = 0,
	RGB = 1,
	// NOT Supported yet!

	Max_NONE = 2 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EColorPickerType : uint8
{
	Swatches = 0,
	CustomColor = 1,
	Both = 2,
};

UCLASS(BlueprintType, Blueprintable)
class UFortColorPickerConfiguration : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortColorPickerConfiguration")
	bool bNoColorOptionAvailable;

	UPROPERTY(EditDefaultsOnly, Category="FortColorPickerConfiguration")
	EColorPickerType ColorPickerType;

	UPROPERTY(EditDefaultsOnly, Category="FortColorPickerConfiguration")
	bool bInitializeCustomColorFromSelectedSwatch;

	UPROPERTY(EditDefaultsOnly, Category="FortColorPickerConfiguration")
	EColorPickerColorRepresentation CustomColorRepresentation;

};

