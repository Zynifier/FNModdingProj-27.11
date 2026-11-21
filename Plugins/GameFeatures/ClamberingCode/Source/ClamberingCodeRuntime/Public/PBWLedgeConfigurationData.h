// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/MathFwd.h"
#include "PBWLedgeConfigurationData.generated.h"

class ABuildingActor;

UENUM()
enum class EPlayerBuiltWallType : uint8
{
	Solid = 0,
	Windows = 1,
	WindowC = 2,
	WindowSide = 3,
	DoorC = 4,
	DoorS = 5,
	DoorSide = 6,
	Archway = 7,
	ArchwayLarge = 8,
	ArchwayLargeSupport = 9,
};

USTRUCT()
struct FLedgeLaunchConfigEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="LedgeLaunchConfigEntry")
	TArray<FTransform> LedgeTransforms;

};

UCLASS()
class UPBWLedgeConfigurationData : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="PBWLedgeConfigurationData")
	TMap<EPlayerBuiltWallType, TSoftClassPtr<ABuildingActor>> MetalWalls;

	UPROPERTY(EditDefaultsOnly, Category="PBWLedgeConfigurationData")
	TMap<EPlayerBuiltWallType, TSoftClassPtr<ABuildingActor>> StoneWalls;

	UPROPERTY(EditDefaultsOnly, Category="PBWLedgeConfigurationData")
	TMap<EPlayerBuiltWallType, TSoftClassPtr<ABuildingActor>> WoodWalls;

	UPROPERTY(EditDefaultsOnly, Category="PBWLedgeConfigurationData")
	TMap<EPlayerBuiltWallType, FLedgeLaunchConfigEntry> Transforms;

};

