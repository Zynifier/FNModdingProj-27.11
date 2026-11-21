// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "AI/FortIntensityCurveSequence.h"
#include "FortSpawnPointsPercentageCurveSequence.generated.h"

UCLASS(BlueprintType)
class UFortSpawnPointsPercentageCurveSequence : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpawnPointsPercentageCurveSequence")
	TArray<FDataTableRowHandle> SpawnPointsPercentageCurves;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpawnPointsPercentageCurveSequence")
	TEnumAsByte<EFortIntensityCurveSequenceType::Type> SequenceType;

};

