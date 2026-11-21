// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_SnufflesLeaderFace.generated.h"

class USkeletalMeshComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_SnufflesLeaderFace : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="CustomCharacterPartAnimInstance_SnufflesLeaderFace", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> MeshToCopy;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_SnufflesLeaderFace")
	FVector EyebrowsNoiseVector;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_SnufflesLeaderFace")
	FVector EarbrowNoiseVectorA;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_SnufflesLeaderFace")
	FVector EarbrowNoiseVectorB;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_SnufflesLeaderFace")
	FVector HitBoneScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_SnufflesLeaderFace")
	FVector HashTagBoneScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_SnufflesLeaderFace")
	FVector CheekLineBoneScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_SnufflesLeaderFace")
	FVector EarlineBoneScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_SnufflesLeaderFace")
	float DynamicsDisabledAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_SnufflesLeaderFace")
	float HeadForwardAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_SnufflesLeaderFace")
	float PlayerHealth;

};

