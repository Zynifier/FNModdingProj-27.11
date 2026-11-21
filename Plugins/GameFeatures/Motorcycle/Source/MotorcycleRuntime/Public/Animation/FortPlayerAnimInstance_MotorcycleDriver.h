// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/CachedAnimData.h"
#include "UObject/SoftObjectPath.h"
#include "Animation/FortPlayerAnimInstance_MotorcycleRider.h"
#include "FortPlayerAnimInstance_MotorcycleDriver.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPlayerAnimInstance_MotorcycleDriver : public UFortPlayerAnimInstance_MotorcycleRider
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bHasMoved;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	float SteeringRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bIsInInventoryMode;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bShouldJump;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bShouldAllowHeadAO;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	float FeetDragPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bShouldJumpCharge;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bIsLandingInPlace;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bStateRuleFallingToMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bShouldApplyChargingNoise;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Motorcycle Driver|Nativized")
	float JumpTimer;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bShouldAllowJump;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bIsSurfaceWater;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bSlopeAlphaShouldIncrease;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Motorcycle Driver|Nativized")
	float SlopeAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bHasPassenger;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bIsOneHandedDualWield;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bShouldApplyBodyTwistForMelee;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bIsMelee;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bIsRangedOrConsumable;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bShouldApplyFeetNoise;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	float CachedFallingStartTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bWasFalling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bIsRevving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	float StoppieLeanAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Motorcycle Driver|Nativized")
	bool bShouldPlayMovingJump;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Motorcycle Driver|Nativized")
	bool bWasJumpTrickLeftOrRight;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Motorcycle Driver|Nativized")
	bool bIsFromJumpTrick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bShouldAllowMovingJumpLand;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bStateTransitionRuleToReverseLoop;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bIsReverseNoFeet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	float WalkSPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	float LeanSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	float LeanAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Motorcycle Driver|Nativized")
	bool bIsCombatTransition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bShouldBrake;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bShouldExitFromLocomotion;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bEarlyOutBrakingOutro;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bIsRightInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bShouldPlayReverseOutro;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bShouldApplyHipSuspension;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bIsDefaultJumpTrick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bIsLeftJumpTrick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bIsRightJumpTrick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bIsNoneJumpTrick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bIsSoloJumpTrick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bShouldExitFromDefaultJumpTrick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bEarlyOutFromMoveStart;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bShouldStop;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Motorcycle Driver|Nativized")
	float CachedTrickIntroTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bShouldPlayJumpTrickIntroLeft;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bShouldPlayJumpTrickIntroRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bStateRuleNeutralToJumpTrickLeft;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bStateRuleNeutralToJumpTrickRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bShouldJumpTrick;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Motorcycle Driver|Nativized")
	bool bHasJumpChargeStarted;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	bool bIsJumpTrickLanding;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Motorcycle Driver|Nativized")
	bool bWasSoloJumping;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Motorcycle Driver|Nativized")
	bool bWasStoppieLanding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	float UpperBodyBlendAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	float StoredJumpTrickIntroPosition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	float JumpTrickIntroPosition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Driver|Nativized")
	float JumpChargeLegIKAlpha;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Motorcycle Driver|Settings")
	FSoftObjectPath ScytheMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Motorcycle Driver|Settings")
	FName JumpTrickIntroPositionCurveName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Driver|Settings")
	FCachedAnimRelevancyData FallStartCachedTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Driver|Settings")
	FCachedAnimRelevancyData TrickCachedTime;

};

