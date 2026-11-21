// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUserWidget.h"
#include "FortBluGloCounter.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortBluGloCounter : public UFortUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="ItemCollector Methods")
	void OnBluGloQuantityChanged(int32 Quantity);

};

