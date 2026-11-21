// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "FortIntensityCurveSequence.generated.h"

UENUM()
namespace EFortIntensityCurveSequenceType
{
	enum Type
	{
		/** Uses the curves from first to last then repeats the last. */
		Sequence = 0,
		/** Uses the curves from first to last then repeats from the beginning. */
		Loop = 1,
		/** Uses random curves. */
		Random = 2,
		Max_None = 3 UMETA(Hidden),
	};
}

UCLASS(BlueprintType)
class UFortIntensityCurveSequence : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntensityCurveSequence")
	TArray<FDataTableRowHandle> IntensityCurves;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntensityCurveSequence")
	TEnumAsByte<EFortIntensityCurveSequenceType::Type> SequenceType;

};

