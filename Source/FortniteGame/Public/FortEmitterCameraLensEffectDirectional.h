// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "NiagaraLensEffectBase.h"
#include "Particles/EmitterCameraLensEffectBase.h"
#include "Camera/FortDirectionCameraLensInterface.h"
#include "FortEmitterCameraLensEffectDirectional.generated.h"

class AActor;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Activation", "Components|Activation", "Input", "Collision", "Game|Damage"))
class AFortEmitterCameraLensEffectDirectional : public AEmitterCameraLensEffectBase, public IFortDirectionCameraLensInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<AActor> DamageDealer;

	UPROPERTY()
	FVector DamageDealerLocation;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	FName RotationParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	uint8 bRotateActor : 1;

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	float Strength;

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	float Distance;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("NiagaraActorActivation", "Components|Activation", "Input", "Collision", "Game|Damage", "Activation", "Components|Activation", "Input", "Collision", "Game|Damage"))
class AFortNiagaraCameraLensEffectDirectional : public ANiagaraLensEffectBase, public IFortDirectionCameraLensInterface
{
	GENERATED_BODY()

public:
	AFortNiagaraCameraLensEffectDirectional(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY()
	TObjectPtr<AActor> DamageDealer;

	UPROPERTY()
	FVector DamageDealerLocation;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	FName RotationParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	uint8 bRotateActor : 1;

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	float Strength;

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	float Distance;

};

