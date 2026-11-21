// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CCP_AnimInstance_Body_MaleRaptorKnightLowMs.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCCP_AnimInstance_Body_MaleRaptorKnightLowMs : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="Male Raptor Knight LowMS")
	FVector GravityOverride;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Raptor Knight LowMS")
	FVector SlopeRootTrans;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Raptor Knight LowMS")
	FRotator SlopeFootRot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Raptor Knight LowMS")
	float ArmLiftRAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Raptor Knight LowMS")
	bool bIsAimingRifle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Male Raptor Knight LowMS|Settings|Ranges")
	float ArmLiftR_InRangeA;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Male Raptor Knight LowMS|Settings|Ranges")
	float ArmLiftR_InRangeB;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Male Raptor Knight LowMS|Settings|Ranges")
	float ArmLiftR_OutRangeA;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Male Raptor Knight LowMS|Settings|Ranges")
	float ArmLiftR_OutRangeB;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Raptor Knight LowMS")
	bool bIsSkydiving_Any;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Raptor Knight LowMS")
	bool bIsJumpingOrFalling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Raptor Knight LowMS")
	float IsNotFrontEndAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Raptor Knight LowMS")
	float IsFrontEndAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Raptor Knight LowMS")
	float IsFrontEndSwordConstraintsAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Raptor Knight LowMS")
	float IsPlayingFullBodySlotInFrontEndAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Raptor Knight LowMS")
	float IsSkyDivingAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Raptor Knight LowMS")
	float IsAimingRifleAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Raptor Knight LowMS")
	bool bSwordPassEnabled_0;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Raptor Knight LowMS")
	bool bSwordPassEnabled_1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Raptor Knight LowMS")
	bool bSwordPassEnabled_2;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Raptor Knight LowMS")
	bool bSwordPassEnabled_3;

};

