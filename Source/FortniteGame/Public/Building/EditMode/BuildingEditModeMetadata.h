// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BuildingEditModeMetadata.generated.h"

class UAIHotSpotConfig;
class UBuildingActorHotSpotConfig;

USTRUCT()
struct FConnectivityCube
{
	GENERATED_BODY()

};

UCLASS(Abstract, MinimalAPI)
class UBuildingEditModeMetadata : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BuildingEditModeMetadata")
	uint8 bSupportNextPieceAssist : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI")
	uint8 bHasNavigableOpening : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI")
	uint8 bHasCustomAttackLocation : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI")
	TObjectPtr<UBuildingActorHotSpotConfig> DefaultHotspotConfig;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI")
	TObjectPtr<UAIHotSpotConfig> ShootingHotSpotConfig;

protected:
	UPROPERTY()
	FConnectivityCube ConnectivityCubeData;

};

