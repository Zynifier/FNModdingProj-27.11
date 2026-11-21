// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHexMapTypes.generated.h"

class AActor;
class UDataAsset;
class UObject;

UENUM(BlueprintType)
namespace EFortHexTileAdjacency
{
	enum Type
	{
		North = 0,
		NorthEast = 1,
		SouthEast = 2,
		South = 3,
		SouthWest = 4,
		NorthWest = 5,
		Max_None = 6 UMETA(DisplayName="Self"),
	};
}

USTRUCT()
struct FFortHexMapCoord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 Horizontal;

	UPROPERTY()
	int32 Vertical;

	UPROPERTY()
	int32 Depth;

};

USTRUCT(BlueprintType)
struct FFortZoneEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ZoneEvent")
	FName EventType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ZoneEvent")
	TObjectPtr<UObject> EventFocus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ZoneEvent")
	TObjectPtr<UDataAsset> EventContent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ZoneEvent")
	TObjectPtr<AActor> EventInstigator;

};

