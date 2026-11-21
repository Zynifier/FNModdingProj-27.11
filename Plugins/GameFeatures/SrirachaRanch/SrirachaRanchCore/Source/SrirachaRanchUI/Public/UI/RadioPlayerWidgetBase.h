// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "Components/StreamingRadioPlayerComponent.h"
#include "FortHUDElementWidget.h"
#include "Media/FortBaseStreamingVideo.h"
#include "RadioPlayerWidgetBase.generated.h"

class AFortPawn;
class UStreamingRadioPlayerComponent;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class URadioPlayerWidgetBase : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	float GetRadioStatusOnScreenTime();

	UFUNCTION(BlueprintPure)
	bool HaveToChangeSongInfo(const FFortMediaInBandMetadata& MediaMetadata);

	UFUNCTION(BlueprintPure)
	bool IsMetadataEmpty(const FFortMediaInBandMetadata& MediaMetadata);

	UFUNCTION()
	void NativeEnteredVehicle();

	UFUNCTION()
	void NativeExitedVehicle();

	UFUNCTION()
	void OnControllerGainedNewFortPawn(AFortPawn* FortPawn);

	UFUNCTION(BlueprintImplementableEvent)
	void OnFailedToOpenSource(UStreamingRadioPlayerComponent* Radio, FAthenaRadioStation Source);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLoadingNewSource(UStreamingRadioPlayerComponent* Radio, FAthenaRadioStation Source);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMetadataChanged(FFortMediaInBandMetadata MediaMetadata);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRadioStopped(UStreamingRadioPlayerComponent* Radio, FAthenaRadioStation LastSource);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSourceFinished(UStreamingRadioPlayerComponent* Radio, FAthenaRadioStation Source);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSourcePlaying(UStreamingRadioPlayerComponent* Radio, FAthenaRadioStation Source);

	UFUNCTION(BlueprintImplementableEvent)
	void SetControllable(bool bCanControl);

	UPROPERTY(EditAnywhere, Category="RadioPlayerWidgetBase")
	FFortPrioritizedWidgetData PriorityData;

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UStreamingRadioPlayerComponent> LastValidComp;

};

