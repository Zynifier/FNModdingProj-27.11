// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "LTMCountdownWidgetBase.generated.h"

class UAudioComponent;
class USoundBase;

USTRUCT(BlueprintType)
struct FFortCountdownSounds
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCountdownSounds")
	TObjectPtr<USoundBase> Sound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCountdownSounds")
	int32 StartTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCountdownSounds")
	int32 StopTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCountdownSounds")
	float FadeOutTime;

	UPROPERTY()
	bool bPlayed;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> PlayInstance;

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class ULTMCountdownWidgetBase : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	FText GetTimeText(int32 TimeRemaining);

	UFUNCTION()
	void HandleCountdownFinished();

	UFUNCTION()
	void HandleCountdownStarted(int32 TimeRemaining);

	UFUNCTION()
	void HandleCountdownUpdate(int32 TimeRemaining);

	UFUNCTION()
	void HandleFinalCountdownStarted(int32 TimeRemaining);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCountdownActivated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCountdownFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCountdownStarted(int32 TimeRemaining);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCountdownUpdate(int32 TimeRemaining);

	UFUNCTION(BlueprintImplementableEvent)
	void OnFinalCountdownStarted(int32 TimeRemaining);

	UPROPERTY(EditAnywhere, Category="Widget Priority")
	FFortPrioritizedWidgetData PrioritizationData;

	UPROPERTY(EditDefaultsOnly, Category="LTMCountdownWidgetBase")
	TArray<FFortCountdownSounds> TrackList;

};

