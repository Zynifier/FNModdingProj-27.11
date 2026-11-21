// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingGameplayActor.h"
#include "DeployableBaseCore.generated.h"

class ADeployableBasePlot;
class UParticleSystem;
class USoundBase;

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ADeployableBaseCore : public ABuildingGameplayActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent)
	FTransform GetSimpleDeathFXTransform() const;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Deployable Base")
	TObjectPtr<ADeployableBasePlot> Plot;

	UPROPERTY(EditDefaultsOnly, Category="DeathFX")
	TSoftObjectPtr<UParticleSystem> SimpleDeathParticles;

	UPROPERTY(EditDefaultsOnly, Category="DeathFX")
	TSoftObjectPtr<USoundBase> SimpleDeathSound;

	UPROPERTY(EditDefaultsOnly, Category="AbilitySystem")
	uint8 bRegisterAsGlobalGameplayEventListener : 1;

};

