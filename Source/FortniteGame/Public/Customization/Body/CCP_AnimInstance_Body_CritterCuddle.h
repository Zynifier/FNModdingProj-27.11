// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CCP_AnimInstance_Body_CritterCuddle.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCCP_AnimInstance_Body_CritterCuddle : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Critter Cuddle|Native Floats")
	float RightArmLift;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Critter Cuddle|Native Booleans")
	bool bIsWearingBackpack;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Critter Cuddle|Native Booleans")
	bool bIsWearingCape;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Critter Cuddle|Native Booleans")
	bool bIsInAir;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Names")
	FName ArmLiftSourceBone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Names")
	FName ArmLiftBaseBone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Numbers")
	float RightArmMapInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Numbers")
	float RightArmMapInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Numbers")
	float RightArmMapOutRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Numbers")
	float RightArmMapOutRangeB;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Critter Cuddle|Anim Graph|Native Floats")
	float AnimDynamicsAlpha_LeafI;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Critter Cuddle|Anim Graph|Native Floats")
	float RigidBodyAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Critter Cuddle|Anim Graph|Native Booleans")
	bool bIsWearingBackpackOrCape;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Critter Cuddle|Anim Graph|Native Booleans")
	bool bIsInAirWithoutCape;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Anim Graph|Magic Numbers")
	float AnimDynamicsAlpha_LeafI_True;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Anim Graph|Magic Numbers")
	float AnimDynamicsAlpha_LeafI_False;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Anim Graph|Magic Numbers")
	float RigidBodyAlpha_True;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Anim Graph|Magic Numbers")
	float RigidBodyAlpha_False;

protected:
	UFUNCTION(BlueprintCallable, Category="Critter Cuddle|Native Functions")
	void DetectBackbling();

};

