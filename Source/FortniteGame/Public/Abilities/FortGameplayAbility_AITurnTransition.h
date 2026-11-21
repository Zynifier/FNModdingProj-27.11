// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortMovementEnums.h"
#include "FortGameplayAbility_AITurnTransition.generated.h"

class UAnimMontage;

UENUM(BlueprintType)
enum class FTurnTransitionCondition : uint8
{
	None = 0,
	Inplace = 1,
	Start = 2,
	Moving = 3,
};

USTRUCT()
struct FMinTurnTransitionYawAngleCondition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="MinTurnTransitionYawAngleCondition")
	FTurnTransitionCondition Condition;

	UPROPERTY(EditAnywhere, Category="MinTurnTransitionYawAngleCondition")
	float YawAngle;

};

USTRUCT(BlueprintType)
struct FPickedTurnTransitionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickedTurnTransitionData")
	TObjectPtr<UAnimMontage> MontageToPlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickedTurnTransitionData")
	float PlayRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickedTurnTransitionData")
	FName StartSection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickedTurnTransitionData")
	FName RotateCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickedTurnTransitionData")
	bool bStopWhenAbilityEnds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickedTurnTransitionData")
	float RootMotionTranslationScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickedTurnTransitionData")
	FTurnTransitionCondition Condition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickedTurnTransitionData")
	bool bDisablePhysicsRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickedTurnTransitionData")
	float FacingPrecision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickedTurnTransitionData")
	bool bMaintainRotationOnFacing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickedTurnTransitionData")
	bool bLockBehaviorTree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickedTurnTransitionData")
	bool bUnlockBehaviorTreeOnFacing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickedTurnTransitionData")
	bool bScaleRotationToMatchDesired;

	UPROPERTY(EditAnywhere, Category="Transitions")
	bool bUpdateRotationToMatchDesired;

	UPROPERTY(EditAnywhere, Category="Transitions")
	float MinRotationScaleToMatchDesired;

	UPROPERTY(EditAnywhere, Category="Transitions")
	float MaxRotationScaleToMatchDesired;

	UPROPERTY(EditAnywhere, Category="Transitions")
	float MaxUpdateRotationAngle;

	UPROPERTY(EditAnywhere, Category="Transitions")
	TEnumAsByte<EFortMovementUrgency::Type> RequiredMovementUrgency;

	UPROPERTY(EditAnywhere, Category="Transitions")
	FGameplayTagQuery RequiredTagQuery;

	UPROPERTY(EditAnywhere, Category="Transitions")
	FGameplayTagContainer RequiredGameplayTags;

	UPROPERTY(EditAnywhere, Category="Transitions")
	FGameplayTagContainer GameplayTagsToRemoveOnFinished;

};

USTRUCT()
struct FTurnFloatRange
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Transitions")
	float Min;

	UPROPERTY(EditAnywhere, Category="Transitions")
	float Max;

};

USTRUCT()
struct FTurnTransitionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Transitions")
	FTurnTransitionCondition ApplyConstraint;

	UPROPERTY(EditAnywhere, Category="Transitions")
	bool bUseMontageForTurnTransition;

	UPROPERTY(EditAnywhere, Category="Transitions", meta=(EditCondition="bUseMontageForTurnTransition"))
	TObjectPtr<UAnimMontage> MontageToPlay;

	UPROPERTY(EditAnywhere, Category="Transitions", meta=(EditCondition="bUseMontageForTurnTransition"))
	FName MontageSectionName;

	UPROPERTY(EditAnywhere, Category="Transitions")
	float MinYawAngle;

	UPROPERTY(EditAnywhere, Category="Transitions")
	float MaxYawAngle;

	UPROPERTY(EditAnywhere, Category="Transitions")
	bool bUseCurveForRotation;

	UPROPERTY(EditAnywhere, Category="Transitions", meta=(EditCondition="bUseCurveForRotation"))
	FName CurveNameForRotation;

	UPROPERTY(EditAnywhere, Category="Transitions", meta=(EditCondition="bUseCurveForRotation==false"))
	float TurnRate;

	UPROPERTY(EditAnywhere, Category="Transitions")
	float PlayRate;

	UPROPERTY(EditAnywhere, Category="Transitions")
	TEnumAsByte<EFortMovementUrgency::Type> RequiredMovementUrgency;

	UPROPERTY(EditAnywhere, Category="Transitions")
	FGameplayTagQuery RequiredTagQuery;

	UPROPERTY(EditAnywhere, Category="Transitions")
	FGameplayTagContainer RequiredGameplayTags;

	UPROPERTY(EditAnywhere, Category="Transitions")
	FGameplayTagContainer GameplayTagsToRemoveOnFinished;

	UPROPERTY(EditAnywhere, Category="Transitions")
	int32 PriorityLevel;

	UPROPERTY(EditAnywhere, Category="Transitions")
	FTurnFloatRange SpeedConstraintRange;

	UPROPERTY(EditAnywhere, Category="Transitions")
	bool bEnableSpeedConstraint;

	UPROPERTY(EditAnywhere, Category="Transitions")
	bool bSkipTransitionInCrowd;

	UPROPERTY(EditAnywhere, Category="Transitions")
	bool bDisablePhysicsRotation;

	UPROPERTY(EditAnywhere, Category="Transitions")
	float FacingPrecision;

	UPROPERTY(EditAnywhere, Category="Transitions")
	bool bMaintainRotationOnFacing;

	UPROPERTY(EditAnywhere, Category="Transitions")
	bool bLockBehaviorTree;

	UPROPERTY(EditAnywhere, Category="Transitions")
	bool bUnlockBehaviorTreeOnFacing;

	UPROPERTY(EditAnywhere, Category="Transitions")
	bool bScaleRotationToMatchDesired;

	UPROPERTY(EditAnywhere, Category="Transitions")
	bool bUpdateRotationToMatchDesired;

	UPROPERTY(EditAnywhere, Category="Transitions")
	float MinRotationScaleToMatchDesired;

	UPROPERTY(EditAnywhere, Category="Transitions")
	float MaxRotationScaleToMatchDesired;

	UPROPERTY(EditAnywhere, Category="Transitions")
	float MaxUpdateRotationAngle;

};

UCLASS()
class UFortGameplayAbility_AITurnTransition : public UFortGameplayAbility
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, Category="Ability", meta=(DisplayName="GetTurnTransitionData"))
	void GetTurnTransitionMontageSectionNameAndYawRotationRate(FName& MontageSectionName, float& TurnYawRotationRate, float& DesiredRotationYawDelta, float& TurnTime, bool& bTurnTransitionUsesMontage) const;

	UPROPERTY(EditAnywhere, Category="Transitions")
	FGameplayTagContainer RequiredWeaponTags;

	UPROPERTY(EditAnywhere, Category="Transitions")
	float MinTurnTransitionYawAngle;

	UPROPERTY(EditAnywhere, Category="Transitions")
	TArray<FMinTurnTransitionYawAngleCondition> MinTurnTransitionYawAngleConditions;

	UPROPERTY(EditAnywhere, Category="Transitions")
	TArray<FTurnTransitionData> TransitionPriorityList;

	UPROPERTY(BlueprintReadOnly, Category="TurnTransition")
	bool bPickedTurnTransitionUsesMontage;

	UPROPERTY(BlueprintReadOnly, Category="TurnTransition")
	bool bPickedUseCurveForRotation;

	UPROPERTY(BlueprintReadOnly, Category="TurnTransition")
	FName PickedCurveNameForRotation;

	UPROPERTY(BlueprintReadOnly, Category="TurnTransition")
	FName PickedMontageSectionName;

	UPROPERTY(BlueprintReadOnly, Category="TurnTransition")
	float PickedTurnYawRotationRate;

	UPROPERTY(BlueprintReadOnly, Category="TurnTransition")
	float StartingDesiredRotationYawDelta;

	UPROPERTY(BlueprintReadOnly, Category="TurnTransition")
	float PickedTurnTime;

	UPROPERTY(BlueprintReadOnly, Category="TurnTransition")
	FPickedTurnTransitionData PickedData;

};

