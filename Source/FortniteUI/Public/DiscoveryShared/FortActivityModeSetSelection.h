// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonListView.h"
#include "OnlineLinkId.h"
#include "FortActivityModeSetSelection.generated.h"

class UFortGameActivity;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick, EntryClass="FortActivityModeSetListEntry"))
class UFortActivityModeSetSelection : public UCommonListView
{
	GENERATED_BODY()

public:
	UFortActivityModeSetSelection(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	FOnlineLinkId GetSelectedLinkId() const;

	UFUNCTION(BlueprintCallable)
	void SetActivity(UFortGameActivity* GameActivity);

	UFUNCTION(BlueprintCallable)
	UFortGameActivity* SetSelectedMnemonic(const FString& Mnemonic);

private:
	UPROPERTY()
	TObjectPtr<UFortGameActivity> CachedGameActivity;

	UPROPERTY()
	TObjectPtr<UFortGameActivity> SavedActivity;

};

