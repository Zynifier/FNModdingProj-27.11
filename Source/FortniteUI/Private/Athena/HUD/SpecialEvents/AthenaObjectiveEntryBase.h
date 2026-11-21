// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "GameplayTagContainer.h"
#include "Athena/AthenaChallengeEntry.h"
#include "FortUrgentQuestData.h"
#include "AthenaObjectiveEntryBase.generated.h"

class UDynamicEntryBox;
class UFortEventDateTimeTextBlock;
class UOverlay;
class UProgressBar;
class UUserWidget;
enum class EFortEarnedSubRewardType : uint8;
enum class EPlayerBountyThreatLevel : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnObjectiveReadyToRemoveEntry, UUserWidget*, Entry);

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaObjectiveEntryBase : public UAthenaChallengeEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void OnEntryCompleted(const bool bIsQuestCompleted);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDescOverrideChanged(const FGameplayTag& OverrideTag);

	UFUNCTION(BlueprintImplementableEvent)
	void OnObjectiveEntrySetup(const FUrgentQuestData& UrgentQuestData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnObjectiveRewardSet(const int32 RewardQuantity, const EFortEarnedSubRewardType RewardType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTimerTextBlockUpdated(const double RemainingTime);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateBountyThreatInformationVisibilityChange(ESlateVisibility NewVisibility);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateBountyThreatLevel(EPlayerBountyThreatLevel NewPlayerBountyThreatLevel);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdatePrimaryObjectiveProgress(const FText& Text);

	UPROPERTY(EditAnywhere, Category="AthenaObjectiveEntryBase")
	float RefreshRate;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaObjectiveEntryBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UProgressBar> ProgressBar_ObjectiveProgress;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaObjectiveEntryBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEventDateTimeTextBlock> Text_Timer;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaObjectiveEntryBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_ProgressBar;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaObjectiveEntryBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_ProgressValue_Title;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaObjectiveEntryBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_Timer;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaObjectiveEntryBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_BountyThreat;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaObjectiveEntryBase", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UDynamicEntryBox> DynamicEntryBox_OptionalEntries;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaObjectiveEntryBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_OptionalObjectives;

private:
	UFUNCTION()
	void HandleOnPlayerBountyThreatLevelEnded();

	UFUNCTION()
	void HandleOnPlayerBountyThreatLevelUpdated(EPlayerBountyThreatLevel NewPlayerBountyThreatLeve);

};

