// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortFloatingPetAnimTypes.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "FortFloatingPetAnimInstance.generated.h"

class AFortPlayerPawn;
class UAnimMontage;
class USkeletalMeshComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortFloatingPetAnimInstance : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void CrouchStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void CrouchStopped();

	UFUNCTION(BlueprintImplementableEvent)
	void MeleeStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void MeleeStopped();

	UFUNCTION(BlueprintImplementableEvent)
	void ParachuteJustOpened();

	UFUNCTION(BlueprintImplementableEvent)
	void RecentlyFired();

	UFUNCTION(BlueprintCallable)
	void UpdateSpringControls(float Stiffness = -1.000000f, float StiffnessInterpSpeed = -1.000000f, float StiffnessInterpSpeedSmooth = -1.000000f, float CriticalDampingFactor = -1.000000f);

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Owners")
	TObjectPtr<AFortPlayerPawn> FortPlayerPawn;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="Floating Pet | Owners", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> PawnSkeletalMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Floating Pet | Spring Inputs")
	FFortFloatingPetTranslationStateOffsets PetTranslationStateOffsets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Floating Pet | Spring Inputs")
	FFortFloatingPetRotationStateOffsets PetRotationStateOffsets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Floating Pet | Spring Inputs")
	FFortFloatingPetSimpleControls SpringSimpleControls;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Floating Pet | Spring Inputs")
	FFortFloatingPetAdvancedControls SpringAdvancedControls;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Spring Outputs")
	FVector CarrierOffsetTotal;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Spring Outputs")
	FVector BackpackTargetVector;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Spring Outputs")
	FRotator RotationYawDefinedHoverOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Spring Outputs")
	FRotator CarrierOffsetRotationVelocity;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Spring Outputs")
	FRotator HoverRotationOffsetTotal;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Spring Outputs")
	float CarrierOffsetRotationVelocityAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Spring Outputs")
	float BackpackTargetVectorAlphaSmooth;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Gameplay Values")
	FVector LocalVelocityGameplay;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Gameplay Values")
	float VelocityZ;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Gameplay Values")
	float MeleeTwistCurveValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Gameplay Values")
	float YawDeltaCurrentTick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Gameplay Values")
	float LocalVelocityYawAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Gameplay Values")
	float RootYawOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Floating Pet | Gameplay Values")
	bool bIsSkydivingParachuteJustOpened;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Floating Pet | Gameplay Values")
	bool bForceBackpackTargetVectorAlphaOnFromRecentlyFired;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Gameplay Values")
	bool bIsSkydivingDiving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Gameplay Values")
	bool bAllowTransitionLocomotionAdditiveCrouchTurning;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Gameplay Values")
	bool bIsDiveJumping;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Gameplay Values")
	bool bHasRecentlyFired;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Gameplay Values")
	bool bIsPlayingAnyEmote;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Gameplay Values")
	bool bIsPlayingEmoteNonPlayerTriggeredMontage;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Gameplay Values")
	bool bIsOperatingTurret;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Floating Pet | Montages")
	TObjectPtr<UAnimMontage> CurrentMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Floating Pet | Montages")
	TObjectPtr<UAnimMontage> EmoteNonPlayerTriggerMontage;

};

