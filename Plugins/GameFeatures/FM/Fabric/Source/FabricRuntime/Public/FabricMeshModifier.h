// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Math/RandomStream.h"
#include "FabricModulatable.h"
#include "FabricMeshModifier.generated.h"

UENUM(BlueprintType)
enum class EFabricCloneTransformBehavior : uint8
{
	None = 0,
	// No special clone transformation behavior

	Uniform = 1,
	// Clones are affected by the same transformation.

	Stepped = 2,
	// Clones transformations are accumulated.

	SteppedCentered = 3,
	// Center the pivot location for rotational transformations across clones.

	SteppedExponential = 4,
};

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricMeshModifierBase : public UFabricModulatable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMeshModifierBase")
	EFabricCloneTransformBehavior CloneBehavior;

};

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricMeshModifierClone : public UFabricMeshModifierBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMeshModifierClone")
	int32 CloneCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMeshModifierClone")
	FVector PerCloneTranslation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMeshModifierClone")
	bool bCentered;

};

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricMeshModifierRandomize : public UFabricMeshModifierBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FabricMeshModifierRandomize")
	float LocationRandLimit;

	UPROPERTY(BlueprintReadWrite, Category="FabricMeshModifierRandomize")
	float RotationRandLimit;

	UPROPERTY(BlueprintReadWrite, Category="FabricMeshModifierRandomize")
	float ScaleRandLimit;

	UPROPERTY(BlueprintReadWrite, Category="FabricMeshModifierRandomize")
	FVector LocationRandRange;

	UPROPERTY(BlueprintReadWrite, Category="FabricMeshModifierRandomize")
	FVector RotationRandRange;

	UPROPERTY(BlueprintReadWrite, Category="FabricMeshModifierRandomize")
	FVector ScaleRandRangeAdditive;

	UPROPERTY(BlueprintReadWrite, Category="FabricMeshModifierRandomize")
	float ScaleRandRangeRangeBase;

	UPROPERTY(BlueprintReadWrite, Category="FabricMeshModifierRandomize")
	bool bUniformScale;

	UPROPERTY(BlueprintReadWrite, Category="FabricMeshModifierRandomize")
	FRandomStream RandomStream;

};

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricMeshModifierRotate : public UFabricMeshModifierBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMeshModifierRotate")
	FRotator RotationAmount;

};

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricMeshModifierScale : public UFabricMeshModifierBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMeshModifierScale")
	FVector ScaleFactor;

};

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricMeshModifierTranslate : public UFabricMeshModifierBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMeshModifierTranslate")
	FVector PositionOffset;

};

