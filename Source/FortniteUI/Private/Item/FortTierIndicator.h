// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "FortBrushSize.h"
#include "FortTierIndicator.generated.h"

class UFortItem;

UCLASS(BlueprintType)
class UFortTierIndicator : public UWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Tier Indicator")
	void ClearPreviewState();

	UFUNCTION(BlueprintCallable, Category="Tier Indicator")
	void SetBrushSize(EFortBrushSize::Type BrushSize);

	UFUNCTION(BlueprintCallable, Category="Tier Indicator")
	void SetInterPipPadding(float InterPipPadding);

	UFUNCTION(BlueprintCallable, Category="Tier Indicator")
	void SetItemToRepresent(UFortItem* ItemToRepresent);

	UFUNCTION(BlueprintCallable, Category="Tier Indicator")
	void SetPreviewState(int32 TierIncrease);

	UPROPERTY(BlueprintReadOnly, Category="Tier Indicator", meta=(ExposeOnSpawn))
	TWeakObjectPtr<UFortItem> ItemToRepresent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tier Indicator", meta=(ExposeOnSpawn))
	TEnumAsByte<EFortBrushSize::Type> BrushSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tier Indicator", meta=(ExposeOnSpawn))
	float InterPipPadding;

};

