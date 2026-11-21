// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FortActivityHabaneroButton.generated.h"

class UFortHabaneroTierWidget;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortActivityHabaneroButton : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void CommitCurrentHabaneroSelection() const;

	UFUNCTION(BlueprintCallable)
	void RefreshHabaneroSelection();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ToggleFillOnlyVisibility(const bool bIsFillOnlyEnabled);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortActivityHabaneroButton")
	bool bCommitSelectionOnClick;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDesiredHabaneroSelectionChanged(const bool bIsSelected);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHabaneroAvailabilityChanged(const bool bIsAvailable);

private:
	UPROPERTY(BlueprintReadWrite, Export, Category="FortActivityHabaneroButton", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortHabaneroTierWidget> HabaneroWidget;

};

