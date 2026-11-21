// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraTypes.h"
#include "Camera/PlayerCameraManager.h"
#include "Math/MathFwd.h"
#include "Camera/Fort3PCameraMode.h"
#include "Camera/FortAimedObjectConfig.h"
#include "Camera/FortCameraMode.h"
#include "Camera/FortOpticConfig.h"
#include "FortCameraMode_ThirdPerson.generated.h"

class AActor;
class UFirstPersonUpdateFunction;
class UFortFirstPersonState;

UENUM()
namespace ECameraOrigin
{
	enum Type
	{
		ViewTargetTransform = 0,
		BoneTransform = 1,
	};
}

USTRUCT(BlueprintType)
struct FInterpOffsetData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ViewOffset")
	FVector ViewOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ViewOffset")
	FVector LargeBodyTypeAddtnlOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ViewOffset")
	float PitchAngle;

};

USTRUCT(BlueprintType)
struct FInterpOffset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ViewOffset")
	TArray<FInterpOffsetData> SamplePoints;

};

UCLASS(Abstract, MinimalAPI)
class UFortCameraMode_ThirdPerson : public UFortCameraMode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Instanced, Category="FortCameraMode_ThirdPerson")
	TArray<UFirstPersonUpdateFunction*> FirstPersonUpdateFunctions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	float PenetrationBlendInTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	float PenetrationBlendOutTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	bool bPreventPenetration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	bool bDoPredictiveAvoidance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	float CollisionPushOutDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	float HidePawnPenetrationPercent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	bool bHidePawnWhileNotFullyWeighted;

	UPROPERTY(Transient)
	FName LastAttachSocketName;

	UPROPERTY(Transient)
	FMinimalViewInfo LastBasePOV;

	UPROPERTY(Transient)
	FMinimalViewInfo DeltaBasePOV;

	UPROPERTY(Transient)
	float BlendAlpha;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void GetAdditionalPenetrationIgnoreActors(const AActor* ViewTarget, const FVector& CameraLoc, const FVector& TargetLoc, TArray<AActor*>& OutIgnoreActors);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraSettings")
	float FOV;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraSettings")
	float CameraSpaceForwardDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraSettings")
	bool bClampCameraPitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraSettings")
	bool bClampCameraYaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraSettings", meta=(ClampMax="89.9", ClampMin="-89.9", EditCondition="bClampCameraPitch", UIMax="89.9", UIMin="-89.9"))
	float CameraPitchMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraSettings", meta=(ClampMax="89.9", ClampMin="-89.9", EditCondition="bClampCameraPitch", UIMax="89.9", UIMin="-89.9"))
	float CameraPitchMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraSettings", meta=(ClampMax="189.9", ClampMin="-189.9", EditCondition="bClampCameraYaw", UIMax="189.9", UIMin="-189.9"))
	float CameraYawMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraSettings", meta=(ClampMax="189.9", ClampMin="-189.9", EditCondition="bClampCameraYaw", UIMax="189.9", UIMin="-189.9"))
	float CameraYawMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraPivot")
	TEnumAsByte<ECameraOrigin::Type> CameraOrigin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraPivot")
	FName CameraOriginSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraPivot")
	FVector CameraOriginInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraPivot | StepUp")
	float StepUpCameraOriginInterpVerticalSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraPivot | StepUp", meta=(ForceUnits="sec"))
	float StepUpCameraOriginInterpDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraPivot | StepUp", meta=(ForceUnits="cm"))
	float StepUpDistanceThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraPivot")
	FBox CameraLocationErrorConstraintBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraPivot")
	FInterpOffset ViewTargetSpaceViewOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraPivot")
	FInterpOffset ViewTargetSpaceViewOffset_Crouch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraPivot")
	FVector ViewTargetSpaceViewOffseInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraPivot")
	FInterpOffset CameraSpaceViewOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraPivot")
	float ViewTargetAlignmentFlipInterpDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraPivot")
	bool bScaleViewOffsetByViewTargetScale;

	UPROPERTY(EditDefaultsOnly, Category="Collision")
	bool bUseLocationAsReferenceFrameTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	bool bSupportsShoulderSwap;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_ThirdPerson")
	uint8 bControlsWeaponTransform : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_ThirdPerson", meta=(EditCondition="bControlsWeaponTransform", EditConditionHides))
	FFortOpticConfig OpticConfig;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_ThirdPerson", meta=(EditCondition="bControlsWeaponTransform", EditConditionHides))
	FFortAimedObjectConfig AimedObjectConfig;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_ThirdPerson", meta=(EditCondition="bControlsWeaponTransform", EditConditionHides))
	bool bControlsWeaponTransformOnTargetingOnly;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_ThirdPerson", meta=(EditCondition="bControlsWeaponTransform", EditConditionHides))
	bool bShouldHideWeaponReticle;

	UPROPERTY(Transient)
	UFortFirstPersonState* FirstPersonState;

	UPROPERTY(Transient)
	FVector LastCameraOrigin;

	UPROPERTY(Transient)
	FVector CameraOriginLocalOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collision")
	TArray<FPenetrationAvoidanceFeeler> PenetrationAvoidanceFeelers;

	UPROPERTY(Transient)
	float SafeLocToAimLineBlockedPct;

	UPROPERTY(Transient)
	float AimLineToDesiredPosBlockedPct;

	UPROPERTY(Transient)
	float LastDrawDebugTime;

	UPROPERTY(Transient)
	FVector LastViewTargetSpaceViewOffset;

	UPROPERTY(Transient)
	FVector LastViewTargetAlignmentUp;

	UPROPERTY(Transient)
	float ViewTargetAlignmentFlipInterpTime;

	UPROPERTY(Transient)
	FVector LastCameraPivot;

	UPROPERTY(Transient)
	FVector CachedLookAtLocation;

	UPROPERTY(Transient)
	float CachedPitchLimitMin;

	UPROPERTY(Transient)
	float CachedPitchLimitMax;

	UPROPERTY(Transient)
	float CachedYawLimitMin;

	UPROPERTY(Transient)
	float CachedYawLimitMax;

	UPROPERTY(Transient)
	bool bLastViewTargetValidGroupEmoteLookTarget;

	UPROPERTY(Transient)
	AActor* IgnoreActorForCameraPenetration;

	UPROPERTY(Transient)
	TArray<AActor*> DebugActorsHitDuringCameraPenetration;

	UPROPERTY(Transient)
	uint8 bWasInVehicle : 1;

	UPROPERTY(Transient)
	AActor* PreviousIgnoreActorForCameraPenetration;

	UPROPERTY(Transient)
	FTViewTarget PreviousVT;

	UPROPERTY(Transient)
	bool bIsActive;

	UPROPERTY(Transient)
	bool bLockCameraWhileInactive;

};

