// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortSpectatedPlayerSwitcher.generated.h"

class AFortPlayerStateAthena;

USTRUCT(BlueprintType)
struct FPotentialSpectatorTarget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="PotentialSpectatorTarget")
	int32 Rank;

	UPROPERTY(BlueprintReadWrite, Category="PotentialSpectatorTarget")
	TWeakObjectPtr<AFortPlayerStateAthena> PlayerState;

	UPROPERTY(BlueprintReadWrite, Category="PotentialSpectatorTarget")
	bool bCurrentViewTarget;

};

UCLASS(BlueprintType)
class UFortSpectatedPlayerSwitcher : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortSpectatedPlayerSwitcher(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void FocusWidget();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayedTargetsUpdated();

	UFUNCTION(BlueprintPure)
	bool ShouldBeVisible() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSpectatedPlayerSwitcher")
	int32 MaxPlayersToShow;

	UPROPERTY(BlueprintReadOnly, Category="FortSpectatedPlayerSwitcher")
	TArray<FPotentialSpectatorTarget> DisplayedTargets;

private:
	UPROPERTY()
	TArray<FPotentialSpectatorTarget> AvailableTargets;

};

