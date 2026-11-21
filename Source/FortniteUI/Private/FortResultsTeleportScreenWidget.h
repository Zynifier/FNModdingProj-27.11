// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortResultsTeleportScreenWidget.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortResultsTeleportScreenWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="FortResultsTeleportScreenWidget")
	void OnExitTimePercentagePassedUpdated(float Percent);

	UFUNCTION(BlueprintImplementableEvent, Category="FortResultsTeleportScreenWidget")
	void OnExitTimeRemainingUpdated(int32 TimeRemainingSeconds);

	UFUNCTION(BlueprintImplementableEvent, Category="FortResultsTeleportScreenWidget")
	void OnExitTimerFinished();

	UFUNCTION(BlueprintCallable, Category="FortResultsTeleportScreenWidget")
	void StartExitTimer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortResultsTeleportScreenWidget")
	float ExitTime;

};

