// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AudioShapeSubsystem.generated.h"

class APlayerController;
class UAudioShapeComponent;

/**
 * UAudioShapeSubsystem - Per world subsystem used to manage and update audio shapes
 */
UCLASS()
class AUDIOSHAPES_API UAudioShapeSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAudioShapeComponent>> AudioShapes;

	UPROPERTY(Transient)
	TArray<TObjectPtr<APlayerController>> LocalControllers;

};

