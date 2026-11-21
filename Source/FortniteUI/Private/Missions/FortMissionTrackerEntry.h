// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortHUDObjectiveSizeInterface.h"
#include "FortMissionTrackerEntry.generated.h"

class AFortMission;
class UCommonTextBlock;
class UFortMissionTrackerSubEntry;
class UImage;
class UVerticalBox;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMissionEntryVisibilityChanged);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortMissionTrackerEntry : public UCommonUserWidget, public IFortHUDObjectiveSizeInterface
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOnMissionEntryVisibilityChanged OnMissionEntryVisibilityChanged;

protected:
	UFUNCTION()
	void HandleMissionInfoSet();

	UFUNCTION()
	void HandleObjectivesChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Missions")
	void OnMissionSet();

	UFUNCTION()
	void UpdateVisibility();

	UPROPERTY(EditInstanceOnly, Category="Missions")
	TSubclassOf<UFortMissionTrackerSubEntry> SubEntryClass;

	UPROPERTY(BlueprintReadOnly, Category="Missions")
	bool bConfigureAsHUD;

	UPROPERTY(BlueprintReadOnly, Category="Missions")
	bool bHiddenByHeightConstraint;

	UPROPERTY(BlueprintReadOnly, Export, Category="Missions", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> MissionNameText;

	UPROPERTY(BlueprintReadOnly, Export, Category="Missions", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> ObjectivesListBox;

	UPROPERTY(BlueprintReadOnly, Export, Category="Missions", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> UpperSeparator;

	UPROPERTY(BlueprintReadOnly, Category="Missions")
	TObjectPtr<AFortMission> TrackedMission;

	UPROPERTY()
	FOnSizeEstimateChanged OnSizeEstimateChangedDelegate;

};

