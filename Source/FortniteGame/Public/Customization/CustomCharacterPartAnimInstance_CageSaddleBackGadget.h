// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_CageSaddleBackGadget.generated.h"

class AFortPlayerPawn;
class UCurveFloat;
class USkeletalMeshComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_CageSaddleBackGadget : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="Cage Saddle Back Gadget", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cage Saddle Back Gadget")
	TObjectPtr<AFortPlayerPawn> PlayerPawn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cage Saddle Back Gadget")
	FRotator KnobRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cage Saddle Back Gadget")
	float RollAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cage Saddle Back Gadget")
	bool bHasTriggeredGCBurstLocal;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cage Saddle Back Gadget")
	FRotator HeadRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cage Saddle Back Gadget")
	float InflationBlendWeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cage Saddle Back Gadget|Settings")
	FGameplayTagContainer BlockDeploymentTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cage Saddle Back Gadget|Settings")
	FGameplayTag TickTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cage Saddle Back Gadget|Settings")
	float MinDurationRemainingForGCBurstLocal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cage Saddle Back Gadget|Settings")
	FRotator HeadRotation_Sprinting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cage Saddle Back Gadget|Settings")
	FRotator HeadRotation_Otherwise;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cage Saddle Back Gadget|Settings")
	TObjectPtr<UCurveFloat> InflationCurveLong;

};

