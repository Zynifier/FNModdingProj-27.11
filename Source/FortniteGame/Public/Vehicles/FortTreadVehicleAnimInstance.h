// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortVehicleAnimInstance.h"
#include "Vehicles/FortTreadVehicle.h"
#include "FortTreadVehicleAnimInstance.generated.h"

class AFortTreadVehicle;
class USkeletalMeshComponent;

USTRUCT(BlueprintType)
struct FRollerAnimState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="RollerAnimState")
	FName BoneName;

	UPROPERTY(BlueprintReadOnly, Category="RollerAnimState")
	int32 BoneIndex;

	UPROPERTY(BlueprintReadOnly, Category="RollerAnimState")
	TEnumAsByte<ETreadSide::Type> TreadSide;

	UPROPERTY(BlueprintReadOnly, Category="RollerAnimState")
	FVector Offset;

	UPROPERTY(BlueprintReadOnly, Category="RollerAnimState")
	float Compression;

	UPROPERTY(BlueprintReadOnly, Category="RollerAnimState")
	float CompressionTarget;

	UPROPERTY(BlueprintReadOnly, Category="RollerAnimState")
	float CompressionVelocity;

	UPROPERTY(BlueprintReadOnly, Category="RollerAnimState")
	FRotator Rotation;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortTreadVehicleAnimInstance : public UFortVehicleAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Tread Vehicle")
	TMap<FName, FRollerAnimState> RollerAnimStates;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tread Vehicle")
	TArray<FName> RollerBoneNames;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tread Vehicle", meta=(ClampMin="0"))
	float MaxCompression;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tread Vehicle", meta=(ClampMin="1"))
	float CompressionMass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tread Vehicle", meta=(ClampMin="1"))
	float CompressionStiffness;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tread Vehicle")
	TObjectPtr<AFortTreadVehicle> TreadVehicle;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="Tread Vehicle", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;

};

