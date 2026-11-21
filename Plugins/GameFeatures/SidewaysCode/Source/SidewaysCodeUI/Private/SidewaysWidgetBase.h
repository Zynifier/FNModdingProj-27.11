// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/SidewaysStateComponent.h"
#include "FortHUDElementWidget.h"
#include "SidewaysWidgetBase.generated.h"

class AFortPawn;
class AFortPlayspaceReplicatedState;
class ASidewaysPlayspace;
class USidewaysStateComponent;
enum class ESidewaysState : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class USidewaysWidgetBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ConfigureUIFromPlayspace(ASidewaysPlayspace* Playspace);

	UFUNCTION()
	void HandleFortPawnChanged(AFortPawn* PossessedPawn);

	UFUNCTION(BlueprintImplementableEvent)
	void InitializeVariables();

	UFUNCTION(BlueprintImplementableEvent)
	bool IsValidPlayspace(ASidewaysPlayspace* Playspace) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnEnterSideways(ASidewaysPlayspace* Playspace);

	UFUNCTION(BlueprintImplementableEvent)
	void OnExitSideways();

	UFUNCTION(BlueprintImplementableEvent)
	void OnParamUpdated(const FGameplayTag& UpdatedParam);

	UFUNCTION()
	void OnSidewaysStateChanged(USidewaysStateComponent* SidewaysStateComponent, ASidewaysPlayspace* NewPlayspace, ESidewaysState OldState, ESidewaysState NewState);

	UPROPERTY(BlueprintReadWrite, Transient, Category="SidewaysWidgetBase")
	TObjectPtr<AFortPlayspaceReplicatedState> ReplicatedState;

	UPROPERTY(BlueprintReadOnly, Category="SidewaysWidgetBase")
	ESidewaysState CurrentSidewaysState;

};

