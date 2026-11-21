// Copyright Epic Games, Inc. All Rights Reserved.

#include "DeployableTurretLibrary.h"

float UDeployableTurretLibrary::DeployableTurret_CalculateTargetingLaserScale(const AActor* TurretActor, const FTransform& CurrentTurretAimTransform, const FVector& LaserOrigin, const float MaxLaserRange, const float DistMult)
{
	return float();
}

void UDeployableTurretLibrary::DeployableTurret_EnableSkeletalMeshComponentBudgeting(USkeletalMeshComponentBudgeted* SkeletalMesh, bool bEnable)
{
}

FVector UDeployableTurretLibrary::DeployableTurret_GetAimLocationForTargetActor(const AActor* TargetActor, const TMap<FGameplayTag, FScalableFloat>& NonPlayerPawnTargetTagToZOffsetMap)
{
	return FVector();
}

void UDeployableTurretLibrary::FireAnalyticsEvent_DeployableTurretSessionEnd(UObject* WorldContextObject, const FUniqueNetIdRepl& TurretOwnerAccountId, const TArray<FFortAnalyticsEventAttribute>& Attributes)
{
}
