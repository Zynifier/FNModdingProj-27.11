// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/Data/FortWeaponItemDefinition.h"
#include "FortBuildingItemDefinition.generated.h"

class UBuildingEditModeMetadata;
class UTexture2D;

UENUM(BlueprintType)
enum class ESmartBuildMode : uint8
{
	None = 0,
	Auto = 1,
	Box = 2,
	Bridge = 3,
	Tower = 4,
	ProtectedRamp = 5,
};

UENUM(BlueprintType)
enum class ESmartBuildPlayerLocationInCell : uint8
{
	Anywhere = 0,
	Forward = 1,
	Back = 2,
};

USTRUCT(BlueprintType)
struct FSmartBuildingActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SmartBuildingActor")
	TSoftObjectPtr<UBuildingEditModeMetadata> BuildingMetaData;

	UPROPERTY(EditAnywhere, Category="SmartBuildingActor")
	int32 RotationIterations;

	UPROPERTY(EditAnywhere, Category="SmartBuildingActor")
	ESmartBuildPlayerLocationInCell SelectOnlyIfPlayerLocationInCell;

	UPROPERTY(EditAnywhere, Category="SmartBuildingActor")
	float BuildDistanceOffset;

	UPROPERTY(EditAnywhere, Category="SmartBuildingActor")
	bool bTryToConnectToPieceUnderPlayerFeet;

};

USTRUCT(BlueprintType)
struct FSmartBuildSelection
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SmartBuildSelection")
	float IdealViewPitch;

	UPROPERTY(EditAnywhere, Category="SmartBuildSelection")
	TArray<FSmartBuildingActor> BuildingActors;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortBuildingItemDefinition : public UFortWeaponItemDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="BuildingMetaData")
	TSoftObjectPtr<UBuildingEditModeMetadata> BuildingMetaData;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TSoftObjectPtr<UTexture2D> InactivePreviewImage;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortSmartBuildingItemDefinition : public UFortBuildingItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="BuildingMetaData")
	ESmartBuildMode SmartBuildMode;

	UPROPERTY(EditDefaultsOnly, Category="BuildingMetaData")
	float TurboBuildInterval;

	UPROPERTY(EditAnywhere, Category="BuildingMetaData")
	TArray<FSmartBuildSelection> BuildSelections;

};

