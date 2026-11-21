// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortCameraModeOverrideComponent.generated.h"

class UFortCameraMode;

UCLASS(MinimalAPI, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortCameraModeOverrideComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Camera Override")
	TSubclassOf<UFortCameraMode> CameraModeOverride;

};

