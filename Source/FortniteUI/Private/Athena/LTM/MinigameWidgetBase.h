// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaGameMessage.h"
#include "FortHUDElementWidget.h"
#include "MinigameWidgetBase.generated.h"

class AActor;
class AFortMinigame;
class UFortMinigameStatFilter;
class USoundCue;
enum class EAthenaGameMsgType : uint8;
enum class EFortMinigameState : uint8;

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EMinigameCaptureObjectiveIconState : uint8
{
	NotCaptured = 0,
	Captured = 1,
};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UMinigameWidgetBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	int32 GetStatValue(UFortMinigameStatFilter* InFilter, const bool bGameTotal = false) const;

	UFUNCTION()
	virtual void HandleOwningPlayerChangedTeams();

	UFUNCTION(BlueprintPure)
	static FAthenaGameMessageData MakeMessageData(EAthenaGameMsgType MsgType = EAthenaGameMsgType::None, FText MsgText = FText::GetEmpty(), USoundCue* MsgSound = nullptr, float DisplayTime = 5.000000f);

	UFUNCTION(BlueprintImplementableEvent, meta=(DeprecatedFunction, DeprecationMessage="Renamed to OnDisplayMinigameInProgressUI"))
	void OnDisplayCaptureObjectiveUI(bool bDisplay);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayMiniGameAbortUI(bool bDisplay);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayMinigameEndUI(bool bDisplay);

	UFUNCTION(BlueprintNativeEvent)
	void OnDisplayMinigameInProgressUI(bool bDisplay);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayMinigamePregameCountdownUI(bool bDisplay);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayMinigameStartUI(bool bDisplay);

	UFUNCTION(BlueprintImplementableEvent)
	void OnObjectiveUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnOwningPlayerChangedTeams();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerStatUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void ResetDisplayValues();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="MinigameWidgetBase")
	bool bDisplayCaptureObjectiveRow;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Minigame")
	TObjectPtr<AFortMinigame> CurrentMinigame;

private:
	UFUNCTION()
	void HandlePlayerStatChanged();

	UFUNCTION()
	void HideAllMinigameWidgetUI();

	UFUNCTION()
	void OnCurrentStateChangedDelegate(AFortMinigame* Minigame, EFortMinigameState MinigameState);

	UFUNCTION()
	void OnVolumeMinigameChanged(AFortMinigame* Minigame);

	UPROPERTY()
	TObjectPtr<AActor> CurrentContainer;

};

