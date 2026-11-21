// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "LTMWidgetBase.generated.h"

class AFortGameplayMutator;
class AFortPlayerStateAthena;
class AFortPlayerStateZone;
class UFortLazyImage;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class ULTMWidgetBase : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void SetPlayerPortrait(AFortPlayerStateAthena* Player, UFortLazyImage* PortraitImage) const;

protected:
	UFUNCTION(BlueprintPure)
	virtual AFortPlayerStateAthena* GetViewingPlayerState() const;

	UFUNCTION(BlueprintPure)
	uint8 GetViewingTeam() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Prioritization", meta=(DisplayName="Has Active Content"))
	bool K2_HasActiveContent() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Prioritization", meta=(DisplayName="On Widget Activated"))
	void K2_OnBecomeActive();

	UFUNCTION(BlueprintImplementableEvent, Category="Prioritization", meta=(DeprecatedFunction))
	void K2_OnBecomeInactive();

	UFUNCTION()
	virtual void OnHandleSpectatingChanged(AFortPlayerStateZone* SpectatingTarget);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Mutator Available"))
	void OnMutatorAvailable_BP(const AFortGameplayMutator* MutatorActor);

	UFUNCTION(BlueprintImplementableEvent, Category="Prioritization", meta=(DisplayName="On Widget Interrupted"))
	void OnStompedByOtherWidget();

	UFUNCTION(BlueprintImplementableEvent, Category="Prioritization", meta=(DeprecatedFunction))
	void OnStompFailed();

	UPROPERTY(EditDefaultsOnly, Category="LTMWidgetBase")
	TSubclassOf<AFortGameplayMutator> MutatorClassToWaitFor;

	UPROPERTY(BlueprintReadOnly, Category="LTMWidgetBase")
	TObjectPtr<AFortGameplayMutator> CachedGameplayMutator;

	UPROPERTY(EditAnywhere, Category="Widget Priority")
	FFortPrioritizedWidgetData PrioritizationData;

};

