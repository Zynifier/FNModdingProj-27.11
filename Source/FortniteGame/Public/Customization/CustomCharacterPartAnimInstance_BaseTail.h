// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAnimInputs.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_BaseTail.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_BaseTail : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Default")
	FFortAnimInput_Skydiving SkydivingState;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Tail")
	float TailSkydiveLean;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Tail")
	float TailDiveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Tail")
	float TailSkydiveYaw;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character")
	float SpeedAdjustedPlayrate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character")
	uint8 bIsInShoppingCartSprinting : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character")
	uint8 bIsInShoppingCartMoving : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character")
	uint8 bIsInShoppingCartCoasting : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character")
	uint8 bIsInShoppingCartInAir : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character")
	uint8 bIsHoverboardJumping : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character")
	uint8 bIsHoverboardLanding : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character")
	uint8 bIsWearingCape : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Transient, Category="Character")
	uint8 bBlendInBackwardPose : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Idle_Locomotion : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Locomotion_Idle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Idle_Skydive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Idle_Crouching : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Skydive_Idle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_StartJump_SkyDive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_JumpLoop_Idle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_DownSights_Conduit_DownSightsToIdle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transition")
	uint8 bTransition_Crouching_Locomotion : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_BaseTail")
	uint8 bShoppingCartSprint_Or_Sprint : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_BaseTail")
	uint8 bIsFalling_Or_IsJumping_Or_IsShoppingCartInAir : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_BaseTail")
	uint8 bIsFalling_Or_IsHoverboardJumping : 1;

};

