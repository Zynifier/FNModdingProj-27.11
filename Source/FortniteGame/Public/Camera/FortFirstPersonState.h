// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "FortFirstPersonState.generated.h"

class UFortGameplayAbility;

UENUM()
enum class EMotionTarget : uint8
{
	Camera = 0,
	AimedObject = 1,
	Count = 2,
};

UCLASS(Transient, BlueprintType)
class UFortFirstPersonState : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void NativeWeaponFired(UFortGameplayAbility* GameplayAbility, FGameplayTagContainer AbilityTags);

	UPROPERTY(Transient)
	float BlendAlpha;

	UPROPERTY(Transient)
	float BlendWeight;

	UPROPERTY(Transient)
	int32 HeadBoneIndex;

	UPROPERTY(Transient)
	int32 AimedObjectBoneIndex;

	UPROPERTY(Transient)
	int32 CameraBoneIndex;

	UPROPERTY(Transient)
	int32 HandleBoneIndex;

	UPROPERTY(Transient)
	FTransform AimedObjectHandleOffset;

	UPROPERTY(Transient)
	FTransform OpticAttachTransform;

	UPROPERTY(Transient)
	bool bShouldOwnerBeVisible;

};

