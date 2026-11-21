// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_BuffetFaceAcc.generated.h"

class USkeletalMeshComponent;

USTRUCT(BlueprintType)
struct FBuffetFaceAccGravityOverrideInput
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Gravity Offset")
	float TimeOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Gravity Offset")
	float PerlinScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Gravity Offset")
	FVector Frequency;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Gravity Offset")
	FVector Amplitude;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Gravity Offset")
	FVector Offset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Gravity Offset")
	FName ReorientationJoint;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_BuffetFaceAcc : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="Buffet Face Accessory|Skeletal Mesh Components", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> BodyMesh;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet Face Accessory|Simulation Alphas")
	float RigidBodyAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet Face Accessory|Simulation Alphas")
	float TrailAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet Face Accessory|Simulation Alphas")
	float SkydiveFloatPoseFixAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet Face Accessory|Simulation Alphas")
	float IsBackblingOnAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet Face Accessory|Simulation Alphas")
	float BackpackOnHeadUpDnAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet Face Accessory|Simulation Alphas")
	float IsLongBackblingOnAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet Face Accessory|Simulation Alphas")
	float IsShortBackblingOnAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet Face Accessory|Simulation Alphas")
	float IsJumpPoseFixNeededAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet Face Accessory|Simulation Values")
	float RelaxSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet Face Accessory|Simulation Values")
	float HeadFwdBwdRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet Face Accessory|Simulation Bools")
	bool bIsBackblingOn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet Face Accessory|Simulation Bools")
	bool bIsLongBackblingOn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet Face Accessory|Simulation Bools")
	bool bIsShortBackblingOn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet Face Accessory|Simulation Bools")
	bool bIsHairConstraintOn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet Face Accessory|Gravity Info")
	FVector GravityOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Buffet Face Accessory|Magic Numbers")
	float RelaxSpeedInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Buffet Face Accessory|Magic Numbers")
	float RelaxSpeedInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Buffet Face Accessory|Magic Numbers")
	float RelaxSpeedOutRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Buffet Face Accessory|Magic Numbers")
	float RelaxSpeedOutRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Buffet Face Accessory|Magic Numbers")
	float TrailAlphaSkydiving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Buffet Face Accessory|Magic Numbers")
	float TrailAlphaFalling;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Buffet Face Accessory|Magic Numbers")
	float LongBackblingThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Buffet Face Accessory|Magic Numbers")
	float RigidBodyAlphaSkydiving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Buffet Face Accessory|Magic Numbers")
	float GravityStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Buffet Face Accessory|Magic Names")
	FName DeltaTransformHead;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Buffet Face Accessory|Magic Names")
	FName DeltaTransformNeck;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Buffet Face Accessory|Magic Structs")
	FBuffetFaceAccGravityOverrideInput GravityOverrideInput;

protected:
	UFUNCTION(BlueprintCallable, Category="Buffet Face Accessory|On Blueprint Events")
	void GenerateBackpackAlphas();

};

