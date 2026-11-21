// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/MathFwd.h"
#include "AI/FortAITypes.h"
#include "BuildingActorHotSpotConfig.generated.h"

class UAIHotSpotConfig;

USTRUCT()
struct FBuildingActorHotSpotDirection
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="HotSpot")
	TObjectPtr<UAIHotSpotConfig> HotSpotConfig;

	UPROPERTY(EditAnywhere, Category="HotSpot")
	FVector Offset;

	UPROPERTY(EditAnywhere, Category="HotSpot")
	uint8 bMirrorX : 1;

	UPROPERTY(EditAnywhere, Category="HotSpot")
	uint8 bMirrorY : 1;

	UPROPERTY(VisibleAnywhere, Category="HotSpot")
	EFortHotSpotDirection Direction;

	UPROPERTY(EditAnywhere, Category="HotSpot")
	EHotspotTypeConfigMode TypeConfigUsage;

};

UCLASS()
class UBuildingActorHotSpotConfig : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="HotSpot")
	FBuildingActorHotSpotDirection DirectionSetup[6];

	UPROPERTY(EditDefaultsOnly, Category="HotSpot")
	FBuildingActorHotSpotDirection DefaultSetup;

	UPROPERTY(EditDefaultsOnly, Category="HotSpot")
	TObjectPtr<UAIHotSpotConfig> ExtraTypeConfig;

	UPROPERTY()
	uint8 bHasDirectionalSetup : 1;

};

