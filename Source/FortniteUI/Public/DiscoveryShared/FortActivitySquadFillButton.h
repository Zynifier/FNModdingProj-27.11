// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FortActivitySquadFillButton.generated.h"

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortActivitySquadFillButton : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void CommitCurrentFillSelection() const;

	UFUNCTION(BlueprintPure)
	bool GetPreferredDisabledFillOption() const;

	UFUNCTION(BlueprintCallable)
	void RefreshSquadFillAvailability();

	UFUNCTION(BlueprintCallable)
	void RefreshSquadFillSelection();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ToggleFillOnlyVisibility(const bool bIsFillOnlyEnabled);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortActivitySquadFillButton")
	FText FillOnlyText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortActivitySquadFillButton")
	bool bCommitSelectionOnClick;

	UPROPERTY(BlueprintReadOnly, Category="FortActivitySquadFillButton")
	bool bIsPrivateGameSelected;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDesiredSquadFillSelectionChanged(const bool bIsSelected);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSquadFillAvailabilityChanged(const bool bIsAvailable);

};

