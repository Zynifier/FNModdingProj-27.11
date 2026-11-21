// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/FortActivatablePanelLTM.h"
#include "Athena/Modifiers/FortAthenaMutator_PerkSystemMutator.h"
#include "InfiltrationPerkSelectionPanel.generated.h"

class AFortAthenaMutator_PerkSystemMutator;
class UOverlay;
class UPerkIntroScreenWidget;
class UPerkSelectionEntryWidget;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UInfiltrationPerkSelectionPanel : public UFortActivatablePanelLTM
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void AttempShowPerkIntro();

	UFUNCTION()
	void NativeOnPerkIntroFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPerkIntroFinished();

	UFUNCTION(BlueprintCallable)
	void OnReRollSelected();

	UFUNCTION()
	void OnSelectionMade(UPerkSelectionEntryWidget* Widget);

	UFUNCTION(BlueprintImplementableEvent)
	void SetReRollCount(int32 NewCount);

	UFUNCTION(BlueprintImplementableEvent)
	void SetTimeRemaining(float TimeRemaining);

	UFUNCTION(BlueprintImplementableEvent)
	void StartClosingWidget();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateBackgroundImage(const bool bShouldShowBackground);

	UPROPERTY()
	TWeakObjectPtr<AFortAthenaMutator_PerkSystemMutator> CachedMutator;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UPerkSelectionEntryWidget>> EntryWidgets;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPerkIntroScreenWidget> PerkIntroScreenWidget;

	UPROPERTY()
	FPerkMutatorData MutatorData;

	UPROPERTY(BlueprintReadOnly, Export, Category="InfiltrationPerkSelectionPanel", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UOverlay> PerkIntroOverlay;

};

