// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DaySequenceProvider.h"
#include "EnvironmentLightingActor.generated.h"

class UDirectionalLightComponent;
class UExponentialHeightFogComponent;
class USceneComponent;
class USkyAtmosphereComponent;
class USkyLightComponent;
class UVolumetricCloudComponent;

UCLASS()
class AEnvironmentLightingActor : public ADaySequenceProvider
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Environment", meta=(AllowPrivateAccess="true", EditInline="true", NoEditInline))
	TObjectPtr<USkyAtmosphereComponent> SkyAtmosphereComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Environment", meta=(AllowPrivateAccess="true", EditInline="true", NoEditInline))
	TObjectPtr<USkyLightComponent> SkyLightComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Environment", meta=(AllowPrivateAccess="true", EditInline="true", NoEditInline))
	TObjectPtr<USceneComponent> SunRootComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Environment", meta=(AllowPrivateAccess="true", EditInline="true", NoEditInline))
	TObjectPtr<UDirectionalLightComponent> SunComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Environment", meta=(AllowPrivateAccess="true", EditInline="true", NoEditInline))
	TObjectPtr<UExponentialHeightFogComponent> ExponentialHeightFogComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Environment", meta=(AllowPrivateAccess="true", EditInline="true", NoEditInline))
	TObjectPtr<UVolumetricCloudComponent> VolumetricCloudComponent;

};

