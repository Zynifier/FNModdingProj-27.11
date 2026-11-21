// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Player/FortPlayerControllerSpectating.h"
#include "FortReplaySequenceComponent.generated.h"

class UFortReplayContext;

UCLASS(BlueprintType)
class UFortReplaySequenceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetCurrentShotIndex() const;

	UFUNCTION(BlueprintPure)
	int32 GetNumberOfShotsInSequence() const;

	UFUNCTION(BlueprintCallable)
	void NextShot();

	UFUNCTION()
	void OnReplayLevelStreamingChanged(bool bIsStreaming);

	UFUNCTION(BlueprintCallable)
	void PreviousShot();

	UFUNCTION(BlueprintCallable)
	void RestartSequence();

protected:
	UFUNCTION()
	void OnPlaybackTimeChanged(float NowTime);

	UPROPERTY()
	FSavedSpectatorCameras SequenceShots;

	UPROPERTY()
	int32 CurrentShotIdx;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortReplaySequenceComponent")
	TObjectPtr<UFortReplayContext> ReplayContext;

private:
	UFUNCTION()
	void NoRecorderVideoFinishedCallback();

	UFUNCTION()
	void OnVideoExportFinished(bool bSuccess, const FString& Video);

};

