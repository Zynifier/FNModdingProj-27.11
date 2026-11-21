// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_Cape.generated.h"

class UClothingSimulationInteractor;
class USkeletalMeshComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_Cape : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Export, Category="CustomCharacterPartAnimInstance_Cape", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> MeshToCopy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Cape")
	TObjectPtr<UClothingSimulationInteractor> ClothingSimInteractor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Cape")
	FVector FakeWindVelocityDBNO;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Cape")
	float BlendOutForksAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Cape")
	bool bBlendInBackwardPose;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Cape")
	FVector CapeFakeVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Cape")
	FVector FakeWindVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Cape")
	FVector AimOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Cape")
	float AimOffsetMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Cape")
	FVector FinalCapeWindVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Cape")
	float FinalCapeBlendOutAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Cape")
	float SwingRotateAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Cape")
	float Cape05TrailControllerAlpha;

};

