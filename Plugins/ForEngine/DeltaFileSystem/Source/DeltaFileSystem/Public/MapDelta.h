// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "UObject/NoExportTypes.h"
#include "DeltaFile.h"
#include "MapDelta.generated.h"

UCLASS()
class UMapDelta : public UObject, public IDeltaFile
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString PackageToApplyTo;

	UPROPERTY()
	TMap<FGuid, FAddAction> AddActions;

	UPROPERTY()
	TArray<FUpdateAction> UpdateActions;

	UPROPERTY()
	TMap<FGuid, FDeleteAction> DeleteActions;

};

UCLASS()
class UMapDeltaApplier : public UObject, public IDeltaFileApplier
{
	GENERATED_BODY()

};

