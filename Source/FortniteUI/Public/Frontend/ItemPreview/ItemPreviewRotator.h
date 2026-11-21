// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Frontend/ItemPreview/FortItemPreviewScene.h"
#include "ItemPreviewRotator.generated.h"

class UFortAccountItemDefinition;

UCLASS(BlueprintType, Blueprintable)
class FORTNITEUI_API AItemPreviewRotator : public AFortItemPreviewSceneChanger
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void CameraTransitionComplete();

	UFUNCTION(BlueprintPure)
	FInterpolatedTransitionCamera GetInterpolatedTransitionCameraPosition(const FTransform& TransitionCameraTransform, float TransitionCameraFieldOfView, float ProgressThroughTransitionSecs, float TransitionDurationSecs) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnCameraTransitionReady(bool bPrimaryToSecondary, const UFortAccountItemDefinition* PrimaryRequestedItem, const FSceneTransitionOptions& Options);

private:
	UPROPERTY(EditAnywhere, Category="ItemPreviewRotator", meta=(AllowPrivateAccess="TRUE"))
	float CameraTransitionLerpDuration;

};

