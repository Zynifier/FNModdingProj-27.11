// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Common/FortMultiSizeImage.h"
#include "FortUITypes.h"
#include "FortComparisonResultIndicator.generated.h"

enum class EFortBuffState : uint8;

UCLASS(BlueprintType)
class UFortComparisonResultIndicator : public UFortMultiSizeImage
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Comparison Result Indicator")
	void SetComparisonResult(EFortBuffState ComparisonResult);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Comparison Result Indicator", meta=(ExposeOnSpawn))
	bool bShouldCollapseWhenNotShown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Comparison Result Indicator", meta=(ExposeOnSpawn))
	EFortBuffState ComparisonResult;

};

