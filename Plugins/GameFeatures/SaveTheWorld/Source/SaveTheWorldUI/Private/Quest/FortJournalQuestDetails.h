// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortItemQuantityPair.h"
#include "FortJournalQuestDetails.generated.h"

class UFortQuestItem;
class UFortQuestObjectiveInfo;
enum class EFortTheaterMapTileType : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortJournalQuestDetails : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Quest Details")
	bool CanGotoQuest();

	UFUNCTION(BlueprintCallable, Category="Quest Details")
	bool CanPartyLeaderPlayQuest();

	UFUNCTION(BlueprintCallable, Category="Quest Details")
	bool CanPlayQuest();

	UFUNCTION(BlueprintCallable, Category="Quest Details")
	EFortTheaterMapTileType GetActiveMissionTileType();

	UFUNCTION(BlueprintCallable, Category="Quest Details")
	void GetFutureObjectives(TArray<UFortQuestObjectiveInfo*>& FutureObjectives);

	UFUNCTION(BlueprintCallable, Category="Quest Details")
	void GetRewards(TArray<FFortItemInstanceQuantityPair>& OutRewards, TArray<FFortItemInstanceQuantityPair>& OutSelectableRewards);

	UFUNCTION(BlueprintCallable, Category="Quest Details")
	void GetVisibleObjectives(TArray<UFortQuestObjectiveInfo*>& VisibleObjectives);

	UFUNCTION(BlueprintCallable, Category="Quest Details")
	void SetCurrentQuest(UFortQuestItem* InCurrentQuest);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest Details")
	TObjectPtr<UFortQuestItem> CurrentQuest;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Quest Details")
	void HandleCurrentQuestChangedBP();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndSpokenDialog();

	UFUNCTION(BlueprintCallable)
	void RegisterEndSpokenDialogEvent();

};

