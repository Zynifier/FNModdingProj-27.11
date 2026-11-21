// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_PlayerDamage.generated.h"

UENUM()
enum class EPlayerDamageHeightRatioDetectionType : uint8
{
	/** Detection is deactivated */
	None = 0,
	/** Ratio starts from character bottom (example: Ratio = 0.8f -> valid if hit is in the 20% of the upper body) */
	FromBottom = 1,
	/** Ratio starts from character top (example: Ratio = 0.8f -> valid if hit is in the 20% of the lower body) */
	FromTop = 2,
};

USTRUCT(BlueprintType)
struct FBonePlayerDamageMultiplier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="BonePlayerDamageMultiplier")
	FName BoneName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="BonePlayerDamageMultiplier")
	FScalableFloat DamageMultiplier;

};

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_PlayerDamage : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	bool bIsUsingHitResult;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator")
	FGameplayTagQuery DamageTagQuery;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator")
	float DamageMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator")
	TArray<FBonePlayerDamageMultiplier> BoneDamageMultipliers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator")
	EPlayerDamageHeightRatioDetectionType DetectionType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator")
	FScalableFloat HeightRatio;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator")
	FScalableFloat HeightRatioDamageMultiplier;

};

