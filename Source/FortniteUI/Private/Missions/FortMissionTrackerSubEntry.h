// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortHUDObjectiveSizeInterface.h"
#include "FortMissionTrackerSubEntry.generated.h"

class AFortObjectiveBase;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMissionSubEntryVisibilityChanged);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortMissionTrackerSubEntry : public UCommonUserWidget, public IFortHUDObjectiveSizeInterface
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOnMissionSubEntryVisibilityChanged OnMissionSubEntryVisibilityChanged;

protected:
	UFUNCTION(BlueprintCallable, Category="Missions")
	void NotifyVisibilityChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Missions")
	void OnHiddenByHeightConstraintChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Missions")
	void OnObjectiveSet();

	UPROPERTY(BlueprintReadOnly, Category="Missions")
	bool bConfigureAsHUD;

	UPROPERTY(BlueprintReadOnly, Category="Missions")
	bool bHiddenByHeightConstraint;

	UPROPERTY(BlueprintReadOnly, Category="Missions")
	TObjectPtr<AFortObjectiveBase> TrackedObjective;

	UPROPERTY()
	FOnSizeEstimateChanged OnSizeEstimateChangedDelegate;

};

