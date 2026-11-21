// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BoneMaskTypes.h"
#include "FortAnimationLayeringWeightsDataAsset.generated.h"

class UFortAnimationLayeringBodyPartsDataAsset;

USTRUCT(BlueprintType)
struct FFortAnimationLayeringWeightsDataSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float LocalSpaceLegs;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float LocalSpacePelvis;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float LocalSpaceTorso;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float LocalSpaceHead;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float LocalSpaceShoulderL;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float LocalSpaceShoulderR;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float LocalSpaceArmL;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float LocalSpaceArmR;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float LocalSpaceWeaponL;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float LocalSpaceWeaponR;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float LocalSpaceHandAttachL;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float LocalSpaceHandAttachR;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float LocalSpaceHandL;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float LocalSpaceHandR;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float LocalSpaceFingersL;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float LocalSpaceFingersR;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float MeshSpaceLegs;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float MeshSpacePelvis;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float MeshSpaceTorso;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float MeshSpaceHead;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float MeshSpaceShoulderL;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float MeshSpaceShoulderR;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float MeshSpaceArmL;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float MeshSpaceArmR;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float MeshSpaceWeaponL;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float MeshSpaceWeaponR;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float MeshSpaceHandAttachL;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float MeshSpaceHandAttachR;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float MeshSpaceHandL;

	UPROPERTY(BlueprintReadOnly, Category="FortAnimationLayeringWeightsDataSet")
	float MeshSpaceHandR;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAnimationLayeringWeightsDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(BlueprintThreadSafe))
	void ApplyTo(FFortAnimationLayeringWeightsDataSet& DataAsset) const;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="FortAnimationLayeringWeightsDataAsset")
	TObjectPtr<UFortAnimationLayeringBodyPartsDataAsset> BodyPartsDefinition;

	UPROPERTY(EditAnywhere, Category="FortAnimationLayeringWeightsDataAsset")
	FBoneMaskEntry Legs;

	UPROPERTY(EditAnywhere, Category="FortAnimationLayeringWeightsDataAsset")
	FBoneMaskEntry Pelvis;

	UPROPERTY(EditAnywhere, Category="FortAnimationLayeringWeightsDataAsset")
	FBoneMaskEntry Torso;

	UPROPERTY(EditAnywhere, Category="FortAnimationLayeringWeightsDataAsset")
	FBoneMaskEntry Head;

	UPROPERTY(EditAnywhere, Category="FortAnimationLayeringWeightsDataAsset")
	FBoneMaskEntry ShoulderL;

	UPROPERTY(EditAnywhere, Category="FortAnimationLayeringWeightsDataAsset")
	FBoneMaskEntry ShoulderR;

	UPROPERTY(EditAnywhere, Category="FortAnimationLayeringWeightsDataAsset")
	FBoneMaskEntry ArmL;

	UPROPERTY(EditAnywhere, Category="FortAnimationLayeringWeightsDataAsset")
	FBoneMaskEntry ArmR;

	UPROPERTY(EditAnywhere, Category="FortAnimationLayeringWeightsDataAsset")
	FBoneMaskEntry WeaponL;

	UPROPERTY(EditAnywhere, Category="FortAnimationLayeringWeightsDataAsset")
	FBoneMaskEntry WeaponR;

	UPROPERTY(EditAnywhere, Category="FortAnimationLayeringWeightsDataAsset")
	FBoneMaskEntry HandAttachL;

	UPROPERTY(EditAnywhere, Category="FortAnimationLayeringWeightsDataAsset")
	FBoneMaskEntry HandAttachR;

	UPROPERTY(EditAnywhere, Category="FortAnimationLayeringWeightsDataAsset")
	FBoneMaskEntry HandL;

	UPROPERTY(EditAnywhere, Category="FortAnimationLayeringWeightsDataAsset")
	FBoneMaskEntry HandR;

	UPROPERTY(EditAnywhere, Category="FortAnimationLayeringWeightsDataAsset")
	FBoneMaskEntry FingersL;

	UPROPERTY(EditAnywhere, Category="FortAnimationLayeringWeightsDataAsset")
	FBoneMaskEntry FingersR;

};

