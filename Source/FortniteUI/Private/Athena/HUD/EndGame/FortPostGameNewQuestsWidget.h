// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortPostGameNewQuestsWidget.generated.h"

class UDynamicEntryBox;
class UFortQuestObjectiveInfo;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortPostGameNewQuestsWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayNewQuestsEntryBoxIntroFinished);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayNewQuestsEntryBoxOutroFinished);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayNewQuestsIntroFinished);

public:
	UFUNCTION()
	void PlayNewQuestUpdates();

protected:
	UFUNCTION(BlueprintCallable)
	void HandlePlayNewQuestsEntryBoxIntroAnimFinished();

	UFUNCTION(BlueprintCallable)
	void HandlePlayNewQuestsEntryBoxOutroAnimFinished();

	UFUNCTION(BlueprintCallable)
	void HandlePlayNewQuestsIntroAnimFinished();

	UFUNCTION()
	void HandlePlayNewQuestUpdatesDelayTimerExpired();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayIntro();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayNewQuestsEntryBoxIntro();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayNewQuestsEntryBoxOutro();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayOutro();

	UPROPERTY(EditAnywhere, Category="Config", meta=(DisplayName="New Quests Display Time"))
	float NewQuestsEntryBoxDisplayTime;

private:
	UFUNCTION()
	void HandlePlayNewQuestsEntryBoxIntroFinished();

	UFUNCTION()
	void HandlePlayNewQuestsEntryBoxTimerFinished();

	UFUNCTION()
	void PlayNextNewQuestsBatch();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_NewQuests;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortQuestObjectiveInfo>> UpdatedQuestObjectiveInfoDisplaying;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortQuestObjectiveInfo>> UpdatedQuestObjectiveInfoToDisplay;

	UPROPERTY()
	FOnPlayNewQuestsIntroFinished OnPlayNewQuestsIntroFinishedDelegate;

	UPROPERTY()
	FOnPlayNewQuestsEntryBoxIntroFinished OnPlayNewQuestsEntryBoxIntroFinishedDelegate;

	UPROPERTY()
	FOnPlayNewQuestsEntryBoxOutroFinished OnPlayNewQuestsEntryBoxOutroFinishedDelegate;

};

