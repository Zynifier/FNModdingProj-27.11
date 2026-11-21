// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PointLightComponent.h"
#include "Components/SpotLightComponent.h"
#include "FortLightComponents.generated.h"

UENUM(BlueprintType)
enum class FLightOverrideLevel : uint8
{
	Default = 0,
	High = 1,
	Count = 2,
};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FLightOverrideSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Light")
	FLightOverrideLevel OverrideLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Light")
	float Intensity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Light")
	float AttenuationRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Light")
	bool CastsShadows;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Light")
	bool UseInverseSquaredFalloff;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Light")
	float LightFalloffExponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Light")
	float ShadowResolutionScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Light")
	float ShadowBias;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object", "LightShafts", "Object", "LightShafts", "Object", "LightShafts", "Trigger", "Activation", "Components|Activation", "Physics", "Trigger", "Activation", "Components|Activation", "Physics", "Trigger", "PhysicsVolume"), ClassGroup=("Lights", "Common"), meta=(BlueprintSpawnableComponent))
class UFortPointLightComponent : public UPointLightComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, EditFixedSize, AdvancedDisplay, Category="Light")
	TArray<FLightOverrideSettings> OverrideSettings;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object", "LightShafts", "Object", "Object", "LightShafts", "Object", "LightShafts", "Trigger", "Activation", "Components|Activation", "Physics", "Trigger", "Activation", "Components|Activation", "Physics", "Trigger", "PhysicsVolume"), ClassGroup=("Lights", "Common"), meta=(BlueprintSpawnableComponent))
class UFortSpotLightComponent : public USpotLightComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, EditFixedSize, AdvancedDisplay, Category="Light")
	TArray<FLightOverrideSettings> OverrideSettings;

};

