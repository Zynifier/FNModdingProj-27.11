// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "FortHUDElementWidget.h"
#include "AthenaTimeWidgetBase.generated.h"

class AActor;
class AFortVolume;
class APlayerState;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaTimeWidgetBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void ClientEnteredVolume(APlayerState* PlayerState, AFortVolume* FortVolume);

	UFUNCTION(BlueprintNativeEvent)
	bool IsTextStyleValid(const FName& DisplayTextStyle);

	UFUNCTION(BlueprintNativeEvent, meta=(DisplayName="On Minigame Ended"))
	void OnMinigameEnded();

	UFUNCTION(BlueprintNativeEvent, meta=(DisplayName="On Minigame Started"))
	void OnMinigameStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStartTimeDisplay();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStopTimeDisplay();

	UFUNCTION()
	void OnTimerWidgetActorUpdated(const AActor* TimerWidgetActor);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateDisplay(const FText& DisplayText, const FName& DisplayTextStyle);

	UFUNCTION()
	void UpdateTimeText();

	UPROPERTY(Transient)
	FTimerHandle UpdateTimerHandle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaTimeWidgetBase")
	FText CachedDisplayText;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaTimeWidgetBase")
	FName CachedDisplayTextStyle;

	UPROPERTY(Transient)
	bool bIsDisplaying;

};

