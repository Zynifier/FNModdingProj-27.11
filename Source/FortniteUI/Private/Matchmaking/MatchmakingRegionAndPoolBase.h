// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MatchmakingRegionAndPoolBase.generated.h"

UCLASS()
class UMatchmakingRegionAndPoolBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UMatchmakingRegionAndPoolBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRegionChanged();

};

