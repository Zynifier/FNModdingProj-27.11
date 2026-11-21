// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CCP_AnimInstance_Body_FemaleLargeBlonde.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCCP_AnimInstance_Body_FemaleLargeBlonde : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Large Blonde")
	FVector GravityOverride;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Large Blonde")
	float RigidsAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Large Blonde")
	float FootRotate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Large Blonde")
	float LookUpRCollar;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Large Blonde")
	float LookDownRCollar;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Large Blonde")
	float LookUpLCollar;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Large Blonde")
	float LookDownLCollar;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Large Blonde")
	float ExtraLiftRCollar;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Large Blonde")
	float ExtraLiftLCollar;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Large Blonde")
	float ChestPushInR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Large Blonde")
	float ChestPushInRCorr;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Large Blonde")
	float CollarPopRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Large Blonde")
	float CollarPop;

	UPROPERTY(BlueprintReadWrite, Category="Female Large Blonde|Settings")
	FVector GravityOverride_Normal;

	UPROPERTY(BlueprintReadWrite, Category="Female Large Blonde|Settings")
	FVector GravityOverride_ParachuteOpened;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Female Large Blonde|Settings")
	FName BallRightBoneName;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float FootRotate_InRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float FootRotate_InRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float FootRotate_OutRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float FootRotate_OutRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float LookUpRCollar_InRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float LookUpRCollar_InRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float LookUpRCollar_OutRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float LookUpRCollar_OutRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float LookDownRCollar_InRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float LookDownRCollar_InRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float LookDownRCollar_OutRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float LookDownRCollar_OutRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float LookUpLCollar_InRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float LookUpLCollar_InRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float LookUpLCollar_OutRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float LookUpLCollar_OutRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float LookDownLCollar_InRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float LookDownLCollar_InRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float LookDownLCollar_OutRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float LookDownLCollar_OutRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float ExtraLiftRCollar_InRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float ExtraLiftRCollar_InRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float ExtraLiftRCollar_OutRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float ExtraLiftRCollar_OutRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float ExtraLiftLCollar_InRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float ExtraLiftLCollar_InRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float ExtraLiftLCollar_OutRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float ExtraLiftLCollar_OutRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float ChestPushInR_InRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float ChestPushInR_InRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float ChestPushInR_OutRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float ChestPushInR_OutRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float ChestPushInRCorr_InRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float ChestPushInRCorr_InRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float ChestPushInRCorr_OutRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float ChestPushInRCorr_OutRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float CollarPopRight_InRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float CollarPopRight_InRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float CollarPopRight_OutRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float CollarPopRight_OutRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float CollarPop_InRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float CollarPop_InRangeB;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float CollarPop_OutRangeA;

	UPROPERTY(BlueprintReadOnly, Category="Female Large Blonde|Settings|Ranges")
	float CollarPop_OutRangeB;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Large Blonde")
	float SkydivingRigidBodyAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Large Blonde")
	bool bIsJumpingOrFalling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Large Blonde")
	float IsNotCrouchingAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Large Blonde")
	float IsCrouchSprintingAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Large Blonde")
	float IsInFrontEndAlpha;

};

