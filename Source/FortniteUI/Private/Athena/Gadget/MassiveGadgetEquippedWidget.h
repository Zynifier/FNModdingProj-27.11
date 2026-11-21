// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "MassiveGadgetEquippedWidget.generated.h"

UCLASS(meta=(DisableNativeTick))
class UMassiveGadgetEquippedWidget : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleMassiveTagChanged(const FGameplayTag Tag, int32 Count);

};

