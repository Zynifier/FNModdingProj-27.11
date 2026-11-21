// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUserWidget.h"
#include "FortLTMVictoryWidgetBase.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortLTMVictoryWidgetBase : public UFortUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void StartIntroSequence();

};

