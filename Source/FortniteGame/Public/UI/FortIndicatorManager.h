// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortIndicatorManager.generated.h"

class UFortIndicator;
class UFortMiniMapIndicator;

UCLASS(MinimalAPI)
class UFortIndicatorManager : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortIndicator>> AllIndicators;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortMiniMapIndicator>> MiniMapIndicators;

};

