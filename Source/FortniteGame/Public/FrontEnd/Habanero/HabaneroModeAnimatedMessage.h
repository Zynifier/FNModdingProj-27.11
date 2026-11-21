// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "HabaneroModeAnimatedMessage.generated.h"

enum class EHabaneroAnimatedMessage : uint8;

UENUM()
enum class EHabaneroAnimatedMessage : uint8
{
	None = 0,
	HabaneroEngaged = 1,
	ReadyUp = 2,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class FORTNITEGAME_API UHabaneroModeAnimatedMessage : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void HandleAnimationComplete();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayAnimation(const FText& InGameMode, const FText& InSeasonName, EHabaneroAnimatedMessage InMessageType);

};

