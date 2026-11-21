// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CineCameraActor.h"
#include "GameplayTagContainer.h"
#include "FortArenaCamera.generated.h"

class UFortSpectatorCameraComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Rendering", "AutoPlayerActivation", "Input", "Rendering"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortArenaCamera : public ACineCameraActor
{
	GENERATED_BODY()

public:
	AFortArenaCamera(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ArenaCamera")
	uint8 bEnabled : 1;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ArenaCamera")
	FGameplayTag CameraZone;

	UPROPERTY()
	TSubclassOf<UFortSpectatorCameraComponent> CameraComponentType;

};

