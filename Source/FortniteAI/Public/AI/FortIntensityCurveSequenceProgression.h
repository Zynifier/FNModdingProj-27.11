// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "Engine/DataAsset.h"
#include "FortIntensityCurveSequenceProgression.generated.h"

class UFortIntensityCurveSequence;

USTRUCT(BlueprintType)
struct FFortInstensityCurveSequenceProgression
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntensityCurveProgression")
	TObjectPtr<UFortIntensityCurveSequence> CurveSequence;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntensityCurveProgression")
	FCurveTableRowHandle SelectionWeight;

};

UCLASS(BlueprintType, Blueprintable)
class UFortIntensityCurveSequenceProgression : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntensityCurveProgression")
	TArray<FFortInstensityCurveSequenceProgression> IntensityCurveSequences;

};

