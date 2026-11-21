// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CreativeGravityComponent.generated.h"

class AActor;
class UFortSharedGravityMovementData;

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UCreativeGravityComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	bool SetCustomGravityOverride(AActor* PhysicsObject, float CustomMultiplier, bool bUseCustomGravity, float CustomGravity) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	bool SetPresetGravityOverride(AActor* PhysicsObject, int32 PresetIndex, bool bUseCustomGravity, float CustomGravity) const;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="CreativeGravityComponent")
	TObjectPtr<UFortSharedGravityMovementData> GravityPresets;

};

