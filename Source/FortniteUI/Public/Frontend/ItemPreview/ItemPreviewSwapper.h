// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Frontend/ItemPreview/FortItemPreviewScene.h"
#include "ItemPreviewSwapper.generated.h"

class UCurveFloat;
class UFortAccountItemDefinition;

UCLASS(BlueprintType, Blueprintable)
class AItemPreviewSwapper : public AFortItemPreviewSceneChanger
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnReadyToSwap(const UFortAccountItemDefinition* PrimaryRequestedItem, const FSceneTransitionOptions& Options);

	UFUNCTION(BlueprintCallable)
	void SwapComplete();

	UFUNCTION(BlueprintCallable)
	void UpdateNewSceneTransform(const FTransform& RelativeTransform);

	UFUNCTION(BlueprintCallable)
	void UpdatePreviousSceneTransform(const FTransform& RelativeTransform);

private:
	UPROPERTY(EditAnywhere, Category="ItemPreviewSwapper", meta=(AllowPrivateAccess))
	TObjectPtr<UCurveFloat> CameraTransitionCurve;

	UPROPERTY(EditAnywhere, Category="ItemPreviewSwapper", meta=(AllowPrivateAccess))
	float CameraTransitionLerpDuration;

};

