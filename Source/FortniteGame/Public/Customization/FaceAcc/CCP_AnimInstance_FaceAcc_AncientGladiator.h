// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CCP_AnimInstance_FaceAcc_AncientGladiator.generated.h"

class AFortPlayerPawn;
class USkeletalMeshComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCCP_AnimInstance_FaceAcc_AncientGladiator : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="Ancient Gladiator", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> SkeletalMesh;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Ancient Gladiator")
	TObjectPtr<AFortPlayerPawn> FortPlayerPawnOwner;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="Ancient Gladiator", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> BackpackMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Ancient Gladiator")
	FVector GravityVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Ancient Gladiator")
	float HeadDelta;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Ancient Gladiator")
	float HeadDeltaFwd;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Ancient Gladiator")
	bool bIsWearingBackpack;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Ancient Gladiator")
	bool bIsWearingCape;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Ancient Gladiator")
	bool bIsCharacterPack;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Ancient Gladiator")
	bool bIsCharacterPack_AncientGladiator;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Ancient Gladiator")
	float IsCharacterPackAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Ancient Gladiator")
	float IsGenericBackpackAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ancient Gladiator|Settings")
	FVector2D HeadDeltaInputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ancient Gladiator|Settings")
	FVector2D HeadDeltaOutputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ancient Gladiator|Settings")
	FVector2D HeadDeltaFwdInputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ancient Gladiator|Settings")
	FVector2D HeadDeltaFwdOutputRange;

};

