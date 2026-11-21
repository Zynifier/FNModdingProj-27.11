// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask_ApplyRootMotion_Base.h"
#include "GameFramework/RootMotionSource.h"
#include "Math/MathFwd.h"
#include "FortMantisTypes.h"
#include "FortAbilityTask_ApplyRootMotionMantisForce.generated.h"

class UAnimMontage;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FApplyRootMotionMantisForceDelegate);

USTRUCT()
struct FFortRootMotionSource_Mantis : public FRootMotionSource
{
	GENERATED_BODY()

public:
	UPROPERTY(NotReplicated)
	float CurrentTechniqueTime;

	UPROPERTY()
	TObjectPtr<UAnimMontage> TechniqueMontage;

	UPROPERTY()
	FFortMantisRootMotionWarpInfo WarpInfo;

	UPROPERTY(NotReplicated)
	FVector LatestRepMovementLocation;

};

UCLASS()
class UFortAbilityTask_ApplyRootMotionMantisForce : public UAbilityTask_ApplyRootMotion_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FApplyRootMotionMantisForceDelegate OnFinish;

protected:
	UPROPERTY(Replicated)
	float Duration;

	UPROPERTY(Replicated)
	TObjectPtr<UAnimMontage> TechniqueMontage;

	UPROPERTY(Replicated)
	FFortMantisRootMotionWarpInfo WarpInfo;

};

