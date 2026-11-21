// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GalileoWrapperWidget.generated.h"

class AFortGameplayMutator;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UGalileoWrapperWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void NativeOnResumeGame();

	UFUNCTION(BlueprintImplementableEvent)
	void OnResumeGame();

	UPROPERTY(EditDefaultsOnly, Category="GalileoWrapperWidget")
	TSubclassOf<AFortGameplayMutator> MutatorClassToWaitFor;

};

