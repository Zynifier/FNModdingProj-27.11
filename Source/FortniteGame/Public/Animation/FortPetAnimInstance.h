// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/CachedAnimData.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/FortAnimInstance.h"
#include "FortPetAnimInstance.generated.h"

class AFortPlayerPawn;
class AFortPlayerPet;
class UFortMontageItemDefinitionBase;

UCLASS(Abstract, NotBlueprintable, HideCategories=("AnimInstance"))
class UFortPetAnimInstanceShared : public UFortAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="General")
	TObjectPtr<AFortPlayerPawn> OwnerFortPawn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="General")
	TObjectPtr<AFortPlayerPet> OwnerPet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Jump")
	uint8 bIsOnGround : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="General")
	uint8 bIsFrontEndPreview : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="General")
	uint8 bLobbySkyDive_IsDiving : 1;

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="General")
	float DeltaTime;

	UPROPERTY(EditAnywhere, Transient, Category="General")
	FGameplayTagContainer PendingActiveVariantContextTags;

	UPROPERTY(Transient)
	FGameplayTagContainer ActiveVariantContextTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="General")
	uint8 bAreActiveFlagChangesPending : 1;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPetAnimInstance : public UFortPetAnimInstanceShared
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ApplyOrRemoveFlagsFromEmote(const UFortMontageItemDefinitionBase* Emote, bool bApply);

	UFUNCTION(BlueprintCallable)
	FGameplayTag TEMP_GetActiveTag();

	UFUNCTION(BlueprintImplementableEvent)
	void TEMP_OnActiveTagChanged(FGameplayTag NewTag);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Default")
	FFortAnimInput_Skydiving SkydivingState;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Skydive")
	FRotator SkydiveRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LookAt")
	float LookAtAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LookAt")
	FVector LookAtTargetLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LookAt")
	float LookAtTargetingSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LookAt")
	float LookAtOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Jump")
	int32 JumpAnimIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydive")
	FName OwnerBoneNameToFollowInVortex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydive")
	FVector2D SkydiveRollInVortexOwnerRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydive")
	FVector2D SkydiveRollInVortexRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydive")
	float SkydiveRollWhenFloating;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydive")
	float SkydiveRollWhenDiving;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydive")
	float SkydiveRollInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Default")
	float DownSightsToLocomotionTimeRemaining;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Default")
	float FaceCurveOverrideValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Default")
	bool bIsFlyingPet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="IK")
	float HandIKAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="IK")
	float LegIKAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Jump")
	uint8 bIsSlopeSliding : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Jump")
	uint8 bIsJumpLandComplete : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Jump")
	uint8 bIsZiplining : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Jump")
	uint8 bIsBallooning : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Jump")
	uint8 bIsFlying : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Jump")
	uint8 bIsSurfaceSwimming : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Jump")
	uint8 bIsInAirNotJumping : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Skydive")
	uint8 bUseSkydiveRotation : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Skydive")
	uint8 bIsSkydivingInGame : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Combat")
	uint8 bIsPlayingMeleeAnim : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="General")
	uint8 bIsTargeting : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="General")
	uint8 bIsDBNO : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="General")
	uint8 bIsHappy : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="General")
	uint8 bIsHunker : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="General")
	uint8 bIsInFrontEnd : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="General")
	uint8 bIsFrontEndLobbyPartyMember : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="General")
	uint8 bIsOwnerPawnBeingControlledByNonPlayerAnimBP : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsCrouching : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsMoving2D : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsLocomotion : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsJogging : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsSprinting : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsCrouchSprinting : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsCrouchMoving : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsTargetingAndMoving : 1;

	UPROPERTY(EditAnywhere, Category="FortPetAnimInstance")
	FCachedAnimRelevancyData CachedAnimData_DownSightsToIdle;

	UPROPERTY(EditAnywhere, Category="FortPetAnimInstance")
	FCachedAnimRelevancyData CachedAnimData_JumpLand;

	UPROPERTY(EditAnywhere, Category="FortPetAnimInstance")
	FCachedAnimRelevancyData CachedAnimData_IdleHappy;

	UPROPERTY(EditAnywhere, Category="FortPetAnimInstance")
	FCachedAnimRelevancyData CachedAnimData_CrouchInternalHappy;

	UPROPERTY(EditAnywhere, Category="FortPetAnimInstance")
	FCachedAnimRelevancyData CachedAnimData_ParachuteSkydive;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_LocomotionToIdle_To_Locomotion : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Locomotion_To_LocomotionToIdle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_JumpFall_To_Skydive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_JumpLand_To_Locomotion : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_DownSightsToIdle_To_Locomotion : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Idle_IdleLobby : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Idle_Locomotion : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_InnerIdle_IdleToHappy : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Locomotion_StartJump : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Locomotion_LocomotionHappy : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Crouch_CrouchToLocomotion : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Crouching_CrouchToIdle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Crouching_CrouchToCrouchADSNotMoving : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_CrouchToCrouchADSNotMoving_Crouching : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_SkyDive_Idle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_SkyDiveGliding_SkyDiveDiving : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Hunker_Idle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Hunker_Locomotion : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Hunker_HunkerToCrouch : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_DownSights_ADSToCrouch : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_DownSights_DownSightsToIdle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_CrouchWalkingDownSights_DownSights : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_IdleLobby_Idle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_FrontEndSkydive_LobbyHunker : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_FrontEndSkydive_IdleLobby : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_LobbyHunker_HunkerToLobby : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Happy_HappyToIdle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Happy_HappyToCrouchInternal : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_ParachuteToSkydiveGlide_Skydive : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Responses")
	uint8 bEmotePlaying_WhereHunkeringIsBest : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Responses")
	uint8 bEmotePlaying_WhereHappyIsBest : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Responses")
	uint8 bResponse_ShouldBeHappy : 1;

private:
	UPROPERTY()
	TObjectPtr<UFortMontageItemDefinitionBase> LastObservedFrontEndEmote;

};

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPetAnimInstance_AnimDynamics : public UFortPetAnimInstanceShared
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginCrouching();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginDiveMode();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginFloating();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginSkydiving();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginTargeting();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndCrouching();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndDiveMode();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndFloating();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndSkydiving();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndTargeting();

	UFUNCTION(BlueprintImplementableEvent)
	void OnParachuteClosed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnParachuteOpened();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	float PawnSpeedForAnimDynamics;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	float PawnSpeedForPlayingEmote;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	float PawnSpeedForDBNO;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsJoggingOrSprinting : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bPetWantsAnimDynamics : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsPlayingEmote : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsDBNO : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsPlayingEmoteOrDBNO : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsSkyDiving : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsParachuteOpened : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsSkydiveDiveMode : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsSkydiveFloating : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsCrouching : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsTargeting : 1;

};

