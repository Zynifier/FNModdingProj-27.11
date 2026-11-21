// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/FortUICameraManagerComponent.h"
#include "FrontEndSettings.generated.h"

class AVolume;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class AFrontEndSettings : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Cameras")
	TArray<FCameraPair> Cameras;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DynamicLevelStreamingLocations")
	TArray<TObjectPtr<AVolume>> LevelStreamingLocations;

};

