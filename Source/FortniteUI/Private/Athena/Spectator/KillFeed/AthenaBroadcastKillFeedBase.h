// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "Spectator/AthenaBroadcastKillFeedEntryInfo.h"
#include "AthenaBroadcastKillFeedBase.generated.h"

class UFortDynamicEntryBox;

UCLASS(Abstract)
class UAthenaBroadcastKillFeedBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaBroadcastKillFeedBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> KillFeedEntryBox;

	UPROPERTY(EditDefaultsOnly, Category="AthenaBroadcastKillFeedBase")
	float TimeToShowEntry;

private:
	UFUNCTION()
	void AddKillFeedEntry(const FAthenaBroadcastKillFeedEntryInfo& KillFeedEntryInfo);

	UFUNCTION()
	void OnTimelineScrubbed();

	UFUNCTION()
	void OnToggleShowKillFeed(bool bShowKillFeed);

};

