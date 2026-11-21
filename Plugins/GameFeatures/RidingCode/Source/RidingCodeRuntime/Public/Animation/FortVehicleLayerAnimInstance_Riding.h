// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/CachedAnimData.h"
#include "Math/MathFwd.h"
#include "UObject/SoftObjectPath.h"
#include "Animation/FortAnimInstance.h"
#include "Animation/FortVehicleOccupantAnimInstance.h"
#include "FortCombatTypes.h"
#include "FortVehicleLayerAnimInstance_Riding.generated.h"

class UAnimInstance;
enum class ERidingFootPhase : uint8;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class RIDINGCODERUNTIME_API UFortVehicleLayerAnimInstance_Riding : public UFortVehicleOccupantAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetFootPhase(const ERidingFootPhase InFootPhase);

	UPROPERTY(EditAnywhere, Category="FortVehicleLayerAnimInstance_Riding")
	FCachedAnimRelevancyData IntoVehicleCachedData;

	UPROPERTY(EditAnywhere, Category="FortVehicleLayerAnimInstance_Riding")
	FCachedAnimRelevancyData OutOfVehicleCachedData;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance_Riding")
	float InTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance_Riding")
	float OutTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance_Riding")
	float BodyYawOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance_Riding")
	FRotator BodyCounterRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance_Riding")
	float BodyCounterRotationAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance_Riding")
	bool bIsReloading;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance_Riding")
	bool bIsTargeting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance_Riding")
	bool bIsFiring;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance_Riding")
	bool bIsUsingConsumable;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance_Riding")
	bool bIsInAction;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance_Riding")
	bool bIsThrowConsumable;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance_Riding")
	bool bIsTargetingOrThrowingConsumable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding")
	bool bIsTurningInPlace;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding")
	bool bIsRidingSprinting;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding")
	bool bIsRidingPetting;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding")
	float TurnInPlaceRotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding")
	float TurnInPlaceAngleDelta;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding")
	bool bIsRidingMovingBackward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="SlopeSliding")
	bool bIsSlopeSliding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="SlopeSliding")
	float SlopeSlidingPitch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="SlopeSliding")
	float SlopeSlidingRoll;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding")
	float RiderReferentialRidableYaw;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding")
	float AimYawDegreesCoverage;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance_Riding")
	float SmoothedAimYaw;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	bool bJustEntered;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	bool bIsRidableMoving;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	bool bIsRideMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	float RidableVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	float BodyYaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding")
	float BoostPlayRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding")
	float RidingMovePlayRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	float FalseBlendTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	float CombatToRideYaw;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	float InPlaceYaw;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	float HeadAOAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	FRotator MeleeTwistRot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding|Melee")
	bool bIsDualWield;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding|Melee")
	bool bIsOneHandedDualWield;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding|Melee")
	bool bIsTwoHandedSword;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding|Melee")
	bool bShouldAdjustBodyTwistForMelee;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	FVector PlayerOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	float NoiseAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	bool bIsLobsterBlockActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding")
	float SlopePitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Riding|Height Adjustment")
	float RiderHeightAdjustmentSpringConstant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Riding|Height Adjustment")
	float MinSlopePitchForRiderHeightAdjustment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Riding|Height Adjustment")
	float MaxSlopePitchForRiderHeightAdjustment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Riding|Height Adjustment")
	float RiderHeightAdjustmentForMinSlopePitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Riding|Height Adjustment")
	float RiderHeightAdjustmentForMaxSlopePitch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding|Petting")
	float PettingRotAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding|Petting")
	FRotator PettingRot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Riding|Petting|Settings")
	float PettingPitchFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Riding|Petting|Settings")
	float PettingRollFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding")
	FVector HandAttachLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding")
	FVector HandAttachRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding")
	float HandAttachAlpha;

	UPROPERTY(EditAnywhere, BlueprintSetter=SetFootPhase, Transient, Category="Riding|Foot Phase")
	ERidingFootPhase FootPhase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding|Foot Phase|Conduit Values")
	bool bIsFootPhase_FeetInAir;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding|Foot Phase|Conduit Values")
	bool bIsFootPhase_FrontFeetPlanted;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding|Foot Phase|Conduit Values")
	bool bIsFootPhase_BackFeetPlanted;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding|Foot Phase|Conduit Values")
	bool bIsFootPhase_LeftBackFeetForward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding|Foot Phase|Conduit Values")
	bool bIsFootPhase_RightBackFeetForward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding|Foot Phase|Conduit Values")
	bool bIsFootPhase_LeftPlantedRightPass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding|Foot Phase|Conduit Values")
	bool bIsFootPhase_RightPlantedLeftPass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding")
	float TurnInPlaceModulatedSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding")
	bool bIsTurnInPlaceAngleDeltaPositive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding|Petting")
	float SlopeRoll;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	float MovingVelocityLowerBound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	float JustEnteredDelayTimeSec;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	float FalseBlendTime_Moving;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	float FalseBlendTime_NotMoving;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	FVector PlayerOffsetMale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	FVector PlayerOffsetFemale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	FSoftObjectPath ScytheMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	FSoftObjectPath BRSwordMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	TEnumAsByte<EFortWeaponCoreAnimation::Type> MeleeDualWieldCoreAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	FVector SlopePitchTraceStart;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	FVector SlopePitchTraceEnd;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	FVector HandAttachLocationLeftMale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	FVector HandAttachLocationRightMale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	FVector HandAttachLocationLeftFemale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	FVector HandAttachLocationRightFemale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	FName PlayerHandAttachLeft;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	FName PlayerHandAttachRight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	FName DisableHandAttachCurveName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	FName AllowRidingNoiseAdditiveCurveName;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BlueprintCollectRidableAnimBPData(const UAnimInstance* RidableAnimInstance);

	UFUNCTION(BlueprintNativeEvent)
	void PlaceHandIKTargets();

	UFUNCTION(BlueprintNativeEvent)
	void UpdateBoostPlayRate();

	UFUNCTION(BlueprintNativeEvent)
	void UpdateSlopePitchForRiding();

};

