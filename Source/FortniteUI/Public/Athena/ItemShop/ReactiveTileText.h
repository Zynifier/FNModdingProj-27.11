// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonTextBlock.h"
#include "ReactiveTileText.generated.h"

UCLASS(PrioritizeCategories=("Content"))
class UAthenaItemShopReactiveTileText : public UCommonTextBlock
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintPure)
	int32 GetMaxCharacterCountBeforeScaling() const;

	UFUNCTION(BlueprintCallable)
	void SetMaxCharacterCountBeforeScaling(int32 InMaxCharacterCountBeforeScaling);

	UPROPERTY(EditAnywhere, Category="Scaling")
	int32 MaxCharacterCountBeforeScaling;

	UPROPERTY(EditAnywhere, Category="Scaling", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	float MaxScaleDownPercentage;

	UPROPERTY(EditAnywhere, Category="Scaling")
	bool bDebugScaling;

	UPROPERTY(Transient)
	float InitialFontSize;

};

