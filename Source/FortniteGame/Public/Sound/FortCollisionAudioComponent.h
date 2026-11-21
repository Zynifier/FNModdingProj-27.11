// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "FortCollisionAudioComponent.generated.h"

class USoundBase;

USTRUCT(BlueprintType)
struct FFortCollisionAudioTriggerData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Data")
	TObjectPtr<USoundBase> Asset;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	FVector2D ImpulseMagnitudeRange;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	bool bImpulseMagnitudeLowerBound;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	bool bImpulseMagnitudeUpperBound;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	FVector2D VolumeRange;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	FVector2D PitchRange;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	float MinRetriggerTime;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	float MaxTriggerDistance;

};

UCLASS(MinimalAPI, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortCollisionAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Audio")
	void OnCollision(const FVector& HitLocation, const FVector& HitNormalImpulse, bool& OutResult, float& OutMagnitude);

	UFUNCTION(BlueprintCallable, Category="Audio")
	void SetCollisionSoundAtIndex(int32 Index, USoundBase* SoundToUse);

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TArray<FFortCollisionAudioTriggerData> CollisionSounds;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	float CheckCollisionLeashInterval;

};

