// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "FortMiniMapInputComponent.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct FMinimapZoomBounds
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="MinimapZoomBounds")
	bool bUseDynamicMinZoom;

	UPROPERTY(EditAnywhere, Category="MinimapZoomBounds", meta=(DisplayThumbnail="false", EditCondition="bUseDynamicMinZoom"))
	TObjectPtr<UCurveFloat> DynamicMinZoomCurve;

	UPROPERTY(EditAnywhere, Category="MinimapZoomBounds", meta=(DisplayThumbnail="false", EditCondition="bUseDynamicMinZoom"))
	TObjectPtr<UCurveFloat> DynamicMinZoomCurveMobile;

	UPROPERTY(EditAnywhere, Category="MinimapZoomBounds", meta=(EditCondition="!bUseDynamicMinZoom"))
	float MinZoom;

	UPROPERTY(EditAnywhere, Category="MinimapZoomBounds", meta=(EditCondition="!bUseDynamicMinZoom"))
	float MinZoomMobile;

	UPROPERTY(EditAnywhere, Category="MinimapZoomBounds")
	float MaxZoom;

};

UCLASS(HideCategories=("Activation", "Components|Activation"))
class UFortMiniMapInputComponent : public UInputComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleFullScreenMapToggled(bool bMapVisible);

};

