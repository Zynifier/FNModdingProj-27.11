// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "FortHUDElementWidget.h"
#include "FortHUDEquipProgressBase.generated.h"

class AFortPlayerControllerSpectating;
class AFortPlayerState;
class UCommonTextBlock;
class UImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortHUDEquipProgressBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnProgressEnded();

	UFUNCTION(BlueprintImplementableEvent)
	void OnProgressStarted(const float Duration);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTimeRemainingChanged(const float TimeRemaining);

private:
	UFUNCTION()
	void HandleFollowedPlayerChanged(AFortPlayerControllerSpectating* SpectatorPC, AFortPlayerState* NewFollowedPlayer);

	UFUNCTION()
	void HandleReplayScrubComplete();

	UFUNCTION()
	void HandleUIGameplayCueEvent(FName CueName, EGameplayCueEvent::Type EventType, const FGameplayCueParameters& Parameters);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortHUDEquipProgressBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ProgressBar;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortHUDEquipProgressBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TimeRemaining;

	UPROPERTY(EditAnywhere, Category="FortHUDEquipProgressBase")
	FGameplayTagContainer RelevantGameplayCueTags;

	UPROPERTY(EditAnywhere, Category="FortHUDEquipProgressBase")
	FName ProgressBarMaterialParamName;

};

