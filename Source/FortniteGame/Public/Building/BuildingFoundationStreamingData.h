// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "BuildingFoundationStreamingData.generated.h"

class AFortHLODSMActor;

USTRUCT(BlueprintType)
struct FBuildingFoundationStreamingData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="BuildingFoundationStreamingData")
	FName FoundationName;

	UPROPERTY(BlueprintReadOnly, Category="BuildingFoundationStreamingData")
	FGuid FoundationGUID;

	UPROPERTY(BlueprintReadOnly, Category="BuildingFoundationStreamingData")
	FVector FoundationLocation;

	UPROPERTY(BlueprintReadOnly, Category="BuildingFoundationStreamingData")
	FBox BoundingBox;

	UPROPERTY(BlueprintReadOnly, Category="BuildingFoundationStreamingData")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(BlueprintReadOnly, Category="BuildingFoundationStreamingData")
	FIntPoint GridCoordinates;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TArray<TLazyObjectPtr<AFortHLODSMActor>> ProxyInfo;
#endif

	UPROPERTY()
	TArray<TWeakObjectPtr<AFortHLODSMActor>> ProxyInfoV2;

	UPROPERTY()
	TArray<TWeakObjectPtr<AFortHLODSMActor>> OverlayHLODs;

	UPROPERTY()
	TArray<int32> ChildStreamingDataIndices;

	UPROPERTY()
	uint8 PersistentHLODLevelIndex;

};

