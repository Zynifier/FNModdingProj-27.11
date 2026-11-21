// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaDiscoverabilityBase.h"
#include "AthenaVisitedAreaDisplay.generated.h"

class UCommonTextBlock;
class UFortQuestItem;
class USoundCue;
class UUserWidget;
enum class EUIExtensionSlot : uint8;

UCLASS()
class UAthenaVisitedAreaDisplay : public UAthenaDiscoverabilityBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Playlist Extension Widget Created"))
	void BP_HandlePlaylistExtensionWidgetCreated(UUserWidget* Widget, EUIExtensionSlot SlotType);

	UFUNCTION()
	void HandleContextualObjectivesInvalidated();

	UFUNCTION()
	void HandleNewContextualObjectives(const TArray<UFortQuestItem*>& ContextualQuests);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewVisited(const FText& LocalizedLocationName, const TSoftObjectPtr<USoundCue>& DiscoveredSoundCue, bool bIsNamedLocation, bool bIsDiscovered);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaVisitedAreaDisplay", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> CommonTextBlock_AvailableChallenges;

};

