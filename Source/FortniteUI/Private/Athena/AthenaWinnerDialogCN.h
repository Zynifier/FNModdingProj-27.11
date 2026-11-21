// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaWinnerDialogCN.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaWinnerDialogCN : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnOpenMessage();

	UFUNCTION()
	void OnWinConditionWasMet();

	UFUNCTION(BlueprintCallable)
	void OnWinnerLeavingGame();

};

