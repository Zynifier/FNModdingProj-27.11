// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortHUDObjectiveSizeInterface.h"
#include "FortMissionTrackerList.generated.h"

class UFortMissionTrackerEntry;
class UObject;
class UVerticalBox;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMissionTrackerListVisibilityChanged);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortMissionTrackerList : public UCommonUserWidget, public IFortHUDObjectiveSizeInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void UpdateVisibleMissionCategories(int32 InVisibleMissionCategories);

protected:
	UFUNCTION()
	void HandleMissionsUpdated();

	UFUNCTION()
	void HandleSizeEstimateChanged(UObject* ChangedElement);

	UFUNCTION()
	void UpdateVisibility();

	UPROPERTY(EditInstanceOnly, Category="Missions")
	TSubclassOf<UFortMissionTrackerEntry> MissionEntryClass;

	UPROPERTY(EditInstanceOnly, Category="Missions")
	bool bConfigureAsHUD;

	UPROPERTY(BlueprintReadOnly, Export, Category="Missions", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> MissionsListBox;

	UPROPERTY(BlueprintReadOnly, Export, Category="Missions", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UVerticalBox> SecondaryMissionsListBox;

	UPROPERTY(BlueprintAssignable, Category="Missions")
	FOnMissionTrackerListVisibilityChanged OnMissionTrackerListVisibilityChanged;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMissionTrackerList", meta=(BitMask, BitmaskEnum="/Script/FortniteGame.EMissionGenerationCategory"))
	int32 VisibleMissionCategories;

	UPROPERTY()
	FOnSizeEstimateChanged OnSizeEstimateChangedDelegate;

};

