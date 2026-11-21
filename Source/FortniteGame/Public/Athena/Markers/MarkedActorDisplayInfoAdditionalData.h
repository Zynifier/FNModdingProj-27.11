// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Athena/Markers/FortWorldMarker.h"
#include "MarkedActorDisplayInfoAdditionalData.generated.h"

UCLASS(BlueprintType)
class UMarkedActorDisplayInfoAdditionalData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	float GetCustomTimeToLive(const FFortWorldMarkerData& InData);

};

UCLASS(BlueprintType)
class UMarkedActorDisplayInfoTeamTTLData : public UMarkedActorDisplayInfoAdditionalData
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="MarkedActorDisplayInfoTeamTTLData")
	float OwnerCustomTimeToLive;

	UPROPERTY(EditAnywhere, Category="MarkedActorDisplayInfoTeamTTLData")
	float FriendlyCustomTimeToLive;

	UPROPERTY(EditAnywhere, Category="MarkedActorDisplayInfoTeamTTLData")
	float EnemyCustomTimeToLive;

};

