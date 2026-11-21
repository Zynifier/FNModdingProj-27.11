// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaEndGamePlacementWidget.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaEndGamePlacementWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Activate();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetPlacement(int32 NewPlacement);

};

