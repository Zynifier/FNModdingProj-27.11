// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "FortAircraft.generated.h"

class UFortCameraMode_ThirdPerson;

UCLASS(BlueprintType, Blueprintable)
class AFortAircraft : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(ReplicatedUsing=OnRep_JumpFlashCount)
	int32 JumpFlashCount;

protected:
	UFUNCTION()
	void OnRep_JumpFlashCount();

	UFUNCTION(BlueprintImplementableEvent, Category="Aircraft")
	void PlayEffectsForPlayerJumped();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aircraft")
	TSubclassOf<UFortCameraMode_ThirdPerson> CameraModeClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aircraft")
	FRotator CameraInitialRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aircraft", meta=(MakeEditWidget="TRUE"))
	FVector ExitLocation;

};

