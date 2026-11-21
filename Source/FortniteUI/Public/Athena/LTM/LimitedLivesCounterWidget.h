// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "LimitedLivesCounterWidget.generated.h"

class AFortPlayerStateAthena;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class ULimitedLivesCounterWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent)
	void OnLivesCountUpdated(int32 NewCount);

	UFUNCTION()
	virtual void OnPlayerDied(AFortPlayerStateAthena* DeadPlayer);

	UPROPERTY()
	TWeakObjectPtr<AFortPlayerStateAthena> CurrentPlayerState;

	UPROPERTY(BlueprintReadOnly, Category="LimitedLivesCounterWidget")
	int32 MaxLives;

};

