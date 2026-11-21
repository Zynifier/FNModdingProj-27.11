// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortMissionCSVEventMap.generated.h"

UCLASS(BlueprintType)
class UFortMissionCSVEventMap : public UPrimaryDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Mission Event Mappings")
	TMap<FName, FString> MissionMappings;

};

