// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimationBlueprintLibrary.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CCP_AnimInstance_GalaticNew.generated.h"

UCLASS(MinimalAPI, HideCategories=("AnimInstance"))
class UCCP_AnimInstance_GalaticNew : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Galatic")
	void UpdatePostPlayerMovement(float XMovement, float YMovement);

	UPROPERTY(BlueprintReadOnly, Transient, Category="Galactic")
	float ThighRotL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Galactic")
	float ThighRotR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Galactic")
	bool bHair;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Galactic")
	float ThighRotUpR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Galactic")
	float ThighRotInrR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Galactic")
	float ThighRotOtrR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Galactic")
	float ThighRotUpL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Galactic")
	float ThighRotInrL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Galactic")
	float ThighRotOtrL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Galactic")
	float JumpingAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Galactic")
	float IsNotCrouchRunning;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Galactic")
	float ParachuteAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Galactic")
	float SkydiveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Galactic")
	float BwdMovement;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Galactic")
	float RightMovement;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Galactic")
	float LeftMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|BP Param")
	FName ThighLBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|BP Param")
	FName ThighRBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|BP Param")
	FName PelvisBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|BP Param")
	FVector2D ThighAlphaInputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|BP Param")
	FVector2D ThighAlphaOutputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|BP Param")
	FVector ThighAlphaTwistAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|BP Param")
	TEnumAsByte<EAlphaFromDeltaTypes::Type> ThighRotationDeltaComponentType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float ThighRotRUpInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float ThighRotRUpInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float ThighRotRInrInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float ThighRotRInrInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float ThighRotROtrInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float ThighRotROtrInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float ThighRotLUpInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float ThighRotLUpInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float ThighRotLInrInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float ThighRotLInrInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float ThighRotLOtrInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float ThighRotLOtrInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float PawnVelocityZThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float XMovementMultiplyer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float YMovementMultiplyer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float InRangeABwdMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float InRangeBBwdMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float OutRangeABwdMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float OutRangeBBwdMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float InRangeADirMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float InRangeBDirMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float OutRangeADirMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float OutRangeBDirMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float InRangeAXMovementRightClamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float InRangeBXMovementRightClamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float OutRangeAXMovementRightClamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float OutRangeBXMovementRightClamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float InRangeAXMovementLeftClamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float InRangeBXMovementLeftClamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float OutRangeAXMovementLeftClamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Galactic|Magic Float")
	float OutRangeBXMovementLeftClamp;

};

