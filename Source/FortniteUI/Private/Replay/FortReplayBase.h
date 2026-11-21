// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "FortReplayBase.generated.h"

class UFortReplayContext;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortReplayBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPlaybackTimeChanged(float NowTime);

	UFUNCTION(BlueprintImplementableEvent)
	void OnReplayPausedChanged(bool bIsPaused);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTimelineRangeChanged(float StartTime, float EndTime);

	UFUNCTION(BlueprintCallable)
	void SetReplayContext(UFortReplayContext* InReplayContext);

protected:
	UPROPERTY()
	TObjectPtr<UFortReplayContext> ReplayContext;

};

