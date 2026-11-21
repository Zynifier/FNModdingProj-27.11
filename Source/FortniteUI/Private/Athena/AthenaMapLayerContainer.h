// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "CommonActivatablePanelLegacy.h"
#include "AthenaMapLayerContainer.generated.h"

class UAthenaFullScreenMapBrowsingControlsWidget;
class UAthenaInGameMapIconsOverlay;
class UAthenaMapChallengeListView;
class UAthenaMapLayer;
class UCommonTextBlock;
class UFortQuestItem;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaMapLayerContainer : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleNewContextualObjectives(const TArray<UFortQuestItem*>& ContextualQuests);

	UFUNCTION()
	void OnTeleportToMarkerTimeChanged(float TimeLeftBeforeTeleport);

private:
	UPROPERTY(EditAnywhere, Category="AthenaMapLayerContainer")
	FVector2D NormalizedMapWidgetPosition;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMapLayerContainer", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaMapLayer> AthenaMapLayer;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMapLayerContainer", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaFullScreenMapBrowsingControlsWidget> MapBrowsingControlsPanel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaInGameMapIconsOverlay> AthenaMapIconsOverlay_Main;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaMapChallengeListView> ListView_NonLocationIconsBelowMap;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMapLayerContainer", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CreativeTeleportCountdown;

	UPROPERTY(EditAnywhere, Category="AthenaMapLayerContainer")
	bool bConsumePointerOnTouchInteraction;

};

