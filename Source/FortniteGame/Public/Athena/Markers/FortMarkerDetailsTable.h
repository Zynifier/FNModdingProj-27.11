// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataRegistryId.h"
#include "Engine/DataAsset.h"
#include "Athena/Markers/FortWorldMarker.h"
#include "Athena/Markers/FortWorldMarkerTypeEnum.h"
#include "Athena/Markers/MarkedActorDisplayInfo.h"
#include "FortMarkerDetailsTable.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortMarkerDetailsTable : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FMarkedActorDisplayInfo GetDisplayInfoForMarkerData(const FFortWorldMarkerData& MarkerData);

	UPROPERTY()
	TMap<EFortWorldMarkerType, FMarkedActorDisplayInfo> DefaultMarker_DEPRECATED;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMarkerDetailsTable")
	TMap<EFortWorldMarkerType, FName> MarkerTypeToIdMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMarkerDetailsTable")
	FDataRegistryType MarkerRegistryType;

};

