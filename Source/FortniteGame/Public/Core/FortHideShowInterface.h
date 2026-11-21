// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHideShowInterface.generated.h"

UINTERFACE(BlueprintType, Blueprintable)
class UFortHideShowInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortHideShowInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void DoHideUI();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void DoShowUI();

};

