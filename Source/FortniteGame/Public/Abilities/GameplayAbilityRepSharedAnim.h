// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilityRepSharedAnim.generated.h"

class UAnimMontage;

UENUM(BlueprintType)
enum class EFortSharedAnimationState : uint8
{
	Anim_Walk = 0,
	Anim_Run = 1,
	Anim_Turn = 2,
	Anim_Attack = 3,
	Anim_Death = 4,
	Anim_Knockback = 5,
	Anim_FullBodyHit = 6,
	Anim_Pushed = 7,
	Anim_Dance = 8,
	Anim_Idle = 9,
	Anim_RangedAttack = 10,
	//MAXIMUM

	Anim_MAX = 11 UMETA(hidden),
};

USTRUCT()
struct FGameplayAbilityRepSharedAnim_Base
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EFortSharedAnimationState AnimState;

	UPROPERTY()
	uint8 MontageSectionToPlay;

};

USTRUCT()
struct FGameplayAbilityRepSharedAnim : public FGameplayAbilityRepSharedAnim_Base
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UAnimMontage> AnimMontage;

};

USTRUCT()
struct FGameplayAbilityRepSharedAnim_Index : public FGameplayAbilityRepSharedAnim_Base
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 MontageIndex;

};

