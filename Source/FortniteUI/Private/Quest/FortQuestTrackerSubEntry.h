// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonUserWidget.h"
#include "FortHUDObjectiveSizeInterface.h"
#include "FortQuestTrackerSubEntry.generated.h"

class UFortQuestObjectiveInfo;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHUDQuestObjectiveCompleted, UFortQuestObjectiveInfo*, QuestObjective);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestTrackerSubEntry : public UCommonUserWidget, public IUserObjectListEntry, public IFortHUDObjectiveSizeInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleQuestsUpdated();

	UFUNCTION(BlueprintCallable, Category="Quests")
	void NotifyCompletionAnimationFinished();

	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	void OnPlayObjectiveCompletedAnimation();

	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	void OnQuestsUpdated();

	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	void OnSetup();

	UPROPERTY(BlueprintReadOnly, Category="Quests")
	TObjectPtr<UFortQuestObjectiveInfo> TrackedObjective;

	UPROPERTY()
	FOnSizeEstimateChanged OnSizeEstimateChangedDelegate;

	UPROPERTY()
	FOnHUDQuestObjectiveCompleted OnHUDQuestObjectiveCompletedDelegate;

	UPROPERTY(BlueprintReadOnly, Category="Quests")
	bool bConfigureAsHUD;

};

