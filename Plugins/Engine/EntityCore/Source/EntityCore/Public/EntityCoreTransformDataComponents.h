// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "EntityDataBackedComponent.h"
#include "EntityCoreTransformDataComponents.generated.h"

/** How the object is moved */
UENUM()
enum class EMovementType : uint8
{
	/** Do not teleport physics body. This means velocity will reflect the movement between initial and final position, and collisions along the way will occur */
	SweepPhysics = 0,
	/** Teleport physics body so that velocity remains the same and no collision occurs */
	TeleportPhysics = 1,
	/** Teleport physics body and reset physics state completely */
	ResetPhysics = 2,
};

USTRUCT()
struct FEntityCoreSystemRelativePositionComponentData : public FComponentData
{
	GENERATED_BODY()

};

USTRUCT()
struct FEntityPositionComponentData : public FComponentData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector WorldPosition;

};

USTRUCT()
struct FEntityRotationComponentData : public FComponentData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FRotator WorldRotation;

};

USTRUCT()
struct FEntityScaleComponentData : public FComponentData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector WorldScale3D;

};

UCLASS()
class ENTITYCORE_API UEntityCoreDataBackedRelativePositionComponent : public UEntityDataBackedComponent
{
	GENERATED_BODY()

};

UCLASS()
class ENTITYCORE_API UEntityPositionComponent : public UEntityDataBackedComponent
{
	GENERATED_BODY()

};

UCLASS()
class ENTITYCORE_API UEntityRotationComponent : public UEntityDataBackedComponent
{
	GENERATED_BODY()

};

UCLASS()
class ENTITYCORE_API UEntityScaleComponent : public UEntityDataBackedComponent
{
	GENERATED_BODY()

};

