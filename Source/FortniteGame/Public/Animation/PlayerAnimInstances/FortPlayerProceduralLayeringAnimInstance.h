// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Animation/PlayerAnimInstances/FortPlayerAnimInstanceProxy.h"
#include "FortPlayerProceduralLayeringAnimInstance.generated.h"

class UAnimSequence;
class UFortAnimationLayeringWeightsDataAsset;
class UFortProceduralMotionDataAsset;
class UProxyTable;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPlayerProceduralLayeringAnimInstance : public UFortPlayerAnimInstanceProxy
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPlayerProceduralLayeringAnimInstance")
	FGameplayTag SwingingTag;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerProceduralLayeringAnimInstance")
	bool HideWeapon;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerProceduralLayeringAnimInstance")
	bool bIsSwinging;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerProceduralLayeringAnimInstance")
	float BlendStackBlendTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerProceduralLayeringAnimInstance")
	float AdditiveLayeringAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerProceduralLayeringAnimInstance")
	float ProceduralLayeringAlpha;

	UPROPERTY(Transient)
	bool bWasRelaxed;

	UPROPERTY(Transient)
	bool bWasPlayingUpperBodyTargeting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerProceduralLayeringAnimInstance")
	bool bShouldApplyMeshSpaceRotation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="FortPlayerProceduralLayeringAnimInstance")
	TObjectPtr<UProxyTable> ProxyTableNoWeaponBasePose;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="FortPlayerProceduralLayeringAnimInstance")
	TObjectPtr<UAnimSequence> NoWeaponItemPoseBase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="FortPlayerProceduralLayeringAnimInstance")
	TObjectPtr<UAnimSequence> SwingNoWeaponBasePose;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPlayerProceduralLayeringAnimInstance")
	TObjectPtr<UFortAnimationLayeringWeightsDataAsset> AdditiveWeightsDataAsset;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPlayerProceduralLayeringAnimInstance")
	TObjectPtr<UFortAnimationLayeringWeightsDataAsset> LayeringWeightsDataAsset;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPlayerProceduralLayeringAnimInstance")
	TObjectPtr<UFortProceduralMotionDataAsset> ProceduralMotionDataAsset;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortPlayerProceduralLayeringAnimInstance")
	TObjectPtr<UFortProceduralMotionDataAsset> ProceduralMotionArmLDataAsset;

};

