// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Analytics/FortBlueprintAnalytics.h"
#include "DeployableTurretLibrary.generated.h"

class AActor;
class UObject;
class USkeletalMeshComponentBudgeted;

UENUM(BlueprintType)
enum class EDeployableTurretState : uint8
{
	/** Similar to deactivated, currently unused (keeping to maintain BP functionality) */
	Collapsed = 0,
	/** Transforming into turret on deploy */
	Transforming = 1,
	/** Looking for a target */
	Scanning = 2,
	/** Tracking a target but not yet attacking */
	Tracking = 3,
	/** Attacking a target */
	Attacking = 4,
	/** Deactivated, such as by EMP */
	Deactivated = 5,
	/** Short state right before attacking */
	WindUp = 6,
	/** Short state right after attacking */
	WindDown = 7,
};

UCLASS()
class UDeployableTurretLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Visuals")
	static float DeployableTurret_CalculateTargetingLaserScale(const AActor* TurretActor, const FTransform& CurrentTurretAimTransform, const FVector& LaserOrigin, const float MaxLaserRange, const float DistMult);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Skeletal Mesh")
	static void DeployableTurret_EnableSkeletalMeshComponentBudgeting(USkeletalMeshComponentBudgeted* SkeletalMesh, bool bEnable);

	UFUNCTION(BlueprintCallable, Category="Aim")
	static FVector DeployableTurret_GetAimLocationForTargetActor(const AActor* TargetActor, const TMap<FGameplayTag, FScalableFloat>& NonPlayerPawnTargetTagToZOffsetMap);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Analytics", meta=(WorldContext="WorldContextObject"))
	static void FireAnalyticsEvent_DeployableTurretSessionEnd(UObject* WorldContextObject, const FUniqueNetIdRepl& TurretOwnerAccountId, const TArray<FFortAnalyticsEventAttribute>& Attributes);

};

