// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FrontEnd/FortItemPreviewActor.h"
#include "FortItemPreviewMultiAngleActor.generated.h"

class UCameraComponent;
class UCurveFloat;
class UMaterialInstance;
class USceneComponent;

UCLASS()
class AFortItemPreviewMultiAngleActor : public AFortItemPreviewActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateFloorMaterial(bool bEnableAutotestBackground);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewMultiAngleActor", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> CameraRotationRootComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewMultiAngleActor", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> PrimaryCameraComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortItemPreviewMultiAngleActor")
	TObjectPtr<UMaterialInstance> AutotestFloorMaterial;

private:
	UPROPERTY(EditAnywhere, Category="FortItemPreviewMultiAngleActor", meta=(AllowPrivateAccess="TRUE"))
	float AngleTransitionDuration;

	UPROPERTY(EditAnywhere, Category="FortItemPreviewMultiAngleActor", meta=(AllowPrivateAccess="TRUE"))
	TObjectPtr<UCurveFloat> AngleTransitionCurve;

	UPROPERTY(VisibleAnywhere, Export, Category="FortItemPreviewMultiAngleActor", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<UCameraComponent> ActiveCameraAngle;

};

