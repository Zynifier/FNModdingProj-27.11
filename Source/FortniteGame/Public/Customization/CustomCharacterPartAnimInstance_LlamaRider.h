// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_LlamaRider.generated.h"

class UAnimMontage;
class USkeletalMeshComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_LlamaRider : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_LlamaRider")
	TObjectPtr<UAnimMontage> LlamaEmote;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Export, Category="CustomCharacterPartAnimInstance_LlamaRider", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> MeshToCopy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_LlamaRider")
	FRotator CurrentDiveJiggle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_LlamaRider")
	FVector FallingAnimDynUpForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_LlamaRider")
	float LlamaHeadPhysAlpha;

};

