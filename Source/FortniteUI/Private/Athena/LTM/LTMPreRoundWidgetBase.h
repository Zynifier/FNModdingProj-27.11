// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "LTMPreRoundWidgetBase.generated.h"

class USoundBase;

UCLASS()
class ULTMPreRoundWidgetBase : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandlePreRoundInfo_BP(int32 CurrentRound, const FText& InRoundName, const FText& InPOIName, const USoundBase* InRoundSound);

	UFUNCTION()
	void HandlePreRoundWidgetVisibilityChange(bool bNewVisibility);

	UFUNCTION(BlueprintImplementableEvent)
	void HandlePreRoundWidgetVisibilityChange_BP(bool bNewVisibility);

};

