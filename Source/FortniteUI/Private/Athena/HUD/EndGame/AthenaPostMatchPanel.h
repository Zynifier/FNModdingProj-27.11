// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaPostMatchScreenContainerTabInterface.h"
#include "Athena/HUD/EndGame/FortPostGameScreen.h"
#include "CommonActivatablePanelLegacy.h"
#include "AthenaPostMatchPanel.generated.h"

class UUserWidget;
enum class EUIExtensionSlot : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaPostMatchPanel : public UCommonActivatablePanelLegacy, public IAthenaPostMatchScreenContainerTabInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsAutoAdvanceTabValid() const;

	UPROPERTY(EditAnywhere, Category="Post Match Tab")
	FAthenaPostMatchScreenContainerTabInfo PostMatchTabInfo;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnActivatePanel();

	UFUNCTION(BlueprintImplementableEvent)
	void OnExtensionWidgetAdded(const EUIExtensionSlot ExtensionSlot, UUserWidget* ExtensionWidget);

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitializePanel();

	UFUNCTION(BlueprintCallable)
	void OnPanelReady();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSpectatingToggled(const bool bIsSpectating);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTransistionedFromAnotherPostMatchPanel();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateElementsVisibility();

private:
	UPROPERTY(EditAnywhere, Category="AthenaPostMatchPanel")
	bool bShouldOverrideDefaultPostGameScreenConfig;

	UPROPERTY(EditAnywhere, Category="AthenaPostMatchPanel", meta=(EditCondition="bShouldOverrideDefaultPostGameScreenConfig"))
	FFortPostGameScreenConfig PanelPostGameScreenConfig;

};

