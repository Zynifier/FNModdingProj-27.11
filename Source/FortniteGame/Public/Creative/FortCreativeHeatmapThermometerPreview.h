// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "FortCreativeHeatmapThermometerPreview.generated.h"

class AActor;
class AFortPlayerStateAthena;

USTRUCT()
struct FFortCreativeHeatmapThermometerPreviewData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSoftClassPtr<AActor> ActorClass;

	UPROPERTY()
	FVector Location;

	UPROPERTY()
	FVector RelativeLocation;

	UPROPERTY()
	FRotator RelativeRotation;

	UPROPERTY()
	float InfluenceDistance;

	UPROPERTY()
	int32 ActorTemplateID;

	UPROPERTY()
	TWeakObjectPtr<AFortPlayerStateAthena> OwningPlayerState;

};

UCLASS()
class AFortCreativeHeatmapThermometerPreview : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TMap<FGuid, FFortCreativeHeatmapThermometerPreviewData> PreviewDataMap;

};

