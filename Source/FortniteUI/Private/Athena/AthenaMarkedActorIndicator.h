// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Markers/FortWorldMarker.h"
#include "Athena/Markers/FortWorldMarkerIndicatorInterface.h"
#include "Athena/Markers/MarkedActorDisplayInfo.h"
#include "FortActorIndicatorWidget.h"
#include "AthenaMarkedActorIndicator.generated.h"

class UCommonTextBlock;
class UFortMarkerDetailsTable;
class UPanelWidget;
class USoundBase;
class UWidgetSwitcher;

UCLASS(Abstract)
class UAthenaMarkedActorIndicator : public UFortActorIndicatorWidget, public IFortWorldMarkerIndicatorInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetMarkerData(const FFortWorldMarkerData& FortWorldMarkerData);

	UPROPERTY(BlueprintReadOnly, Category="AthenaMarkedActorIndicator")
	FFortWorldMarkerData MarkerData;

	UPROPERTY(BlueprintReadOnly, Category="AthenaMarkedActorIndicator")
	FMarkedActorDisplayInfo MarkerDisplay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMarkedActorIndicator")
	TObjectPtr<UFortMarkerDetailsTable> DetailsTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	float FreshLargeItemShowTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	float IndicatorDotSizeThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMarkedActorIndicator")
	TObjectPtr<USoundBase> MarkerConfirmationSound;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMarkedActorIndicator", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_IndicatorSize;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_SmallIndicator;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_LargeIndicator;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMarkedActorIndicator", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Distance;

};

