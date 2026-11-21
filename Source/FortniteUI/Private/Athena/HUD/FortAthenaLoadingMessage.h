// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortAthenaLoadingMessage.generated.h"

class AFortPlayerControllerAthena;

UCLASS(meta=(DisableNativeTick))
class UFortAthenaLoadingMessage : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortAthenaLoadingMessage(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void LoadingScreenStateChanged(bool bEnableLoadScreen, const FText& HUDReasonText);

private:
	UFUNCTION()
	void HandleInGameLoadScreenChanged(AFortPlayerControllerAthena* PlayerController, bool bEnableLoadScreen, FText HUDReasonText);

};

