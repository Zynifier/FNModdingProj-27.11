// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortLetoWatermark.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortLetoWatermark : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortLetoWatermark(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

