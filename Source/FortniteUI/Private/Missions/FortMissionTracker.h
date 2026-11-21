// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "Missions/FortCheatManagerMissionsInterface.h"
#include "FortMissionTracker.generated.h"

class UCommonNumericTextBlock;
class UFortMissionTrackerList;
class UFortQuestTrackerList;
class UObject;
class UWidget;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortMissionTracker : public UFortHUDElementWidget, public IFortMissionTrackerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetEnableMainQuestList(bool bEnable);

	UFUNCTION(BlueprintCallable)
	void SetEnablePinnedQuestList(bool bEnable);

protected:
	UFUNCTION()
	void HandleDebugHUDObjectiveHeightChanged(bool bIsDebugging);

	UFUNCTION()
	void HandleSizeEstimateChanged(UObject* ChangedElement);

	UFUNCTION()
	void RefreshSizeEstimate();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMissionTracker", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMissionTrackerList> MissionTrackerList;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMissionTracker", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortQuestTrackerList> MainQuestList;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMissionTracker", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortQuestTrackerList> PinnedQuestsList;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMissionTracker", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> AdditionalEntriesIndicator;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMissionTracker", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> DebugHeightEstimate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMissionTracker")
	float AllowedSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMissionTracker")
	bool bEnforceHeightLimit;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMissionTracker")
	bool bEnableMainQuestList;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMissionTracker")
	bool bEnablePinnedQuestList;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMissionTracker", meta=(BitMask, BitmaskEnum="/Script/FortniteGame.EMissionGenerationCategory"))
	int32 VisibleMissionCategories;

	UPROPERTY(Transient)
	bool bSizeEstimateNeedsRefresh;

	UPROPERTY(Transient)
	float LastRemainingSizeForPinnedQuests;

};

