// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CineCameraActor.h"
#include "Math/MathFwd.h"
#include "Camera/FortCameraActorInterface.h"
#include "FortCinematicCameraActor.generated.h"

class AActor;

UCLASS(Config=Game, BlueprintType, Blueprintable, HideCategories=("Input", "Rendering", "AutoPlayerActivation", "Input", "Rendering"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortCinematicCameraActor : public ACineCameraActor, public IFortCameraActorInterface
{
	GENERATED_BODY()

public:
	AFortCinematicCameraActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(EditAnywhere, Config, Category="Focus Control")
	bool bSetFinalControlRotation;

	UPROPERTY(EditAnywhere, Category="Focus Control", meta=(editcondition="bSetFinalControlRotation"))
	TSoftObjectPtr<AActor> FocusedActor;

	UPROPERTY(EditAnywhere, Category="Focus Control", meta=(editcondition="bSetFinalControlRotation"))
	FRotator FinalControlRotation;

};

