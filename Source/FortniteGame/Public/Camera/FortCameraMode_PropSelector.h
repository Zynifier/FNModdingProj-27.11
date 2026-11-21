// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FortCameraMode_ThirdPerson.h"
#include "FortCameraMode_PropSelector.generated.h"

UCLASS()
class UFortCameraMode_PropSelector : public UFortCameraMode_ThirdPerson
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PossessedProp")
	FVector PropOffsetScale_ViewTargetSpace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PossessedProp")
	FVector MinPropOffset_ViewTargetSpace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PossessedProp")
	FVector MaxPropOffset_ViewTargetSpace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PossessedProp")
	FVector PropOffsetScale_CameraSpace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PossessedProp")
	FVector MinPropOffset_CameraSpace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PossessedProp")
	FVector MaxPropOffset_CameraSpace;

};

