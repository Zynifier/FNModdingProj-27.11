// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameFramework/OnlineReplStructs.h"
#include "FortMicIndicatorWidget.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortMicIndicatorWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Mic Indicator Widget")
	void OnPlayerMicAvailable(bool bIsTalking);

	UFUNCTION(BlueprintImplementableEvent, Category="Mic Indicator Widget")
	void OnPlayerMuted(bool bIsMuted);

	UFUNCTION(BlueprintImplementableEvent, Category="Mic Indicator Widget")
	void OnPlayerTalkingChanged(bool bIsTalking);

	UFUNCTION(BlueprintCallable, Category="Mic Indicator Widget")
	void SetPlayerUniqueId(const FUniqueNetIdRepl& InPlayerUniqueId);

};

