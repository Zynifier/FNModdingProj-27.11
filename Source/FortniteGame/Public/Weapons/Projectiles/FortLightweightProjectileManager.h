// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "GameplayEffectTypes.h"
#include "Math/MathFwd.h"
#include "FortLightweightProjectileManager.generated.h"

class AActor;
class ABulletWhipTrackerSystem;
class AFortLightweightProjectileConfig;

UENUM()
enum class ELightweightProjectileRequestType : uint8
{
	None = 0,
	Single = 1,
	Looping = 2,
};

USTRUCT()
struct FFortLightweightProjectileRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AActor> Requester;

	UPROPERTY()
	TWeakObjectPtr<AActor> FiringWeapon;

	UPROPERTY()
	TSubclassOf<AFortLightweightProjectileConfig> ProjectileConfigClass;

	UPROPERTY()
	FVector StartPosition;

	UPROPERTY()
	FVector StartDirection;

	UPROPERTY()
	ELightweightProjectileRequestType RequestType;

	UPROPERTY()
	TEnumAsByte<EGameplayCueEvent::Type> GameplayCueType;

	UPROPERTY()
	float TimeBetweenShots;

	UPROPERTY()
	float NextFireTime;

	UPROPERTY()
	float Timestamp;

	UPROPERTY()
	int32 NumProjectilesSpawned;

};

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortLightweightProjectileManager : public AInfo
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<ABulletWhipTrackerSystem> BulletWhipTrackerSystem;

};

