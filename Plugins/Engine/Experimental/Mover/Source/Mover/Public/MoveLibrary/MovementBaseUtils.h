// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "MovementBaseUtils.generated.h"

class UPrimitiveComponent;

/** Data about the object a Mover actor is basing its movement on, such as when standing on a moving platform */
USTRUCT(BlueprintType)
struct MOVER_API FRelativeBaseInfo
{
	GENERATED_BODY()

public:
	/** Component we are moving relative to */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Export, Category="Mover", meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> MovementBase;

	/** Bone name on component, for skeletal meshes. NAME_None if not a skeletal mesh or if bone is invalid. */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Mover")
	FName BoneName;

	/** Last captured worldspace location of MovementBase / Bone */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Mover")
	FVector Location;

	/** Last captured worldspace orientation of MovementBase / Bone */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Mover")
	FQuat Rotation;

	/** Last captured location of the tethering point where the Mover actor is "attached". */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Mover")
	FVector ContactLocalPosition;

};

/**
 * MovementBaseUtils: a collection of stateless static BP-accessible functions for based movement
 */
UCLASS()
class MOVER_API UMovementBaseUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Get the transform (local-to-world) for the given MovementBase, optionally at the location of a bone. Returns false if MovementBase is nullptr, or if BoneName is not a valid bone. */
	UFUNCTION(BlueprintCallable, Category="Mover/MovementBases")
	static bool GetMovementBaseTransform(const UPrimitiveComponent* MovementBase, const FName BoneName, FVector& OutLocation, FQuat& OutQuat);

	/** Determine whether MovementBase can possibly move. */
	UFUNCTION(BlueprintCallable, Category="Mover/MovementBases")
	static bool IsADynamicBase(const UPrimitiveComponent* MovementBase);

	/** Convert a local direction to a world direction for a given MovementBase. Returns false if MovementBase is nullptr, or if BoneName is not a valid bone. Scaling is ignored. */
	UFUNCTION(BlueprintCallable, Category="Mover/MovementBases")
	static bool TransformBasedDirectionToWorld(const UPrimitiveComponent* MovementBase, const FName BoneName, FVector LocalDirection, FVector& OutDirectionWorldSpace);

	/** Convert a local location to a world location for a given MovementBase. Returns false if MovementBase is nullptr, or if BoneName is not a valid bone. Scaling is ignored. */
	UFUNCTION(BlueprintCallable, Category="Mover/MovementBases")
	static bool TransformBasedLocationToWorld(const UPrimitiveComponent* MovementBase, const FName BoneName, FVector LocalLocation, FVector& OutLocationWorldSpace);

	/** Convert a local rotator to world space for a given MovementBase. Returns false if MovementBase is nullptr, or if BoneName is not a valid bone. Scaling is ignored. */
	UFUNCTION(BlueprintCallable, Category="Mover/MovementBases")
	static bool TransformBasedRotatorToWorld(const UPrimitiveComponent* MovementBase, const FName BoneName, FRotator LocalRotator, FRotator& OutWorldSpaceRotator);

	/** Convert a world direction to a local direction for a given MovementBase, optionally relative to the orientation of a bone. Returns false if MovementBase is nullptr, or if BoneName is not a valid bone. Scaling is ignored. */
	UFUNCTION(BlueprintCallable, Category="Mover/MovementBases")
	static void TransformDirectionToLocal(FQuat BaseQuat, FVector WorldSpaceDirection, FVector& OutLocalDirection);

	/** Convert a local direction to a world direction for a given MovementBase. Returns false if MovementBase is nullptr, or if BoneName is not a valid bone. Scaling is ignored. */
	UFUNCTION(BlueprintCallable, Category="Mover/MovementBases")
	static void TransformDirectionToWorld(FQuat BaseQuat, FVector LocalDirection, FVector& OutDirectionWorldSpace);

	/** Convert a world location to a local location for a given MovementBase, optionally at the location of a bone. Returns false if MovementBase is nullptr, or if BoneName is not a valid bone. Scaling is ignored. */
	UFUNCTION(BlueprintCallable, Category="Mover/MovementBases")
	static void TransformLocationToLocal(FVector BasePos, FQuat BaseQuat, FVector WorldSpaceLocation, FVector& OutLocalLocation);

	/** Convert a local location to a world location for a given MovementBase. Returns false if MovementBase is nullptr, or if BoneName is not a valid bone. Scaling is ignored. */
	UFUNCTION(BlueprintCallable, Category="Mover/MovementBases")
	static void TransformLocationToWorld(FVector BasePos, FQuat BaseQuat, FVector LocalLocation, FVector& OutLocationWorldSpace);

	/** Convert a world space rotator to a local rotator for a given MovementBase, optionally relative to the orientation of a bone. Returns false if MovementBase is nullptr, or if BoneName is not a valid bone. Scaling is ignored. */
	UFUNCTION(BlueprintCallable, Category="Mover/MovementBases")
	static void TransformRotatorToLocal(FQuat BaseQuat, FRotator WorldSpaceRotator, FRotator& OutLocalRotator);

	/** Convert a local rotator to world space for a given MovementBase. Returns false if MovementBase is nullptr, or if BoneName is not a valid bone. Scaling is ignored. */
	UFUNCTION(BlueprintCallable, Category="Mover/MovementBases")
	static void TransformRotatorToWorld(FQuat BaseQuat, FRotator LocalRotator, FRotator& OutWorldSpaceRotator);

	/** Convert a world direction to a local direction for a given MovementBase, optionally relative to the orientation of a bone. Returns false if MovementBase is nullptr, or if BoneName is not a valid bone. Scaling is ignored. */
	UFUNCTION(BlueprintCallable, Category="Mover/MovementBases")
	static bool TransformWorldDirectionToBased(const UPrimitiveComponent* MovementBase, const FName BoneName, FVector WorldSpaceDirection, FVector& OutLocalDirection);

	/** Convert a world location to a local location for a given MovementBase, optionally at the location of a bone. Returns false if MovementBase is nullptr, or if BoneName is not a valid bone. Scaling is ignored. */
	UFUNCTION(BlueprintCallable, Category="Mover/MovementBases")
	static bool TransformWorldLocationToBased(const UPrimitiveComponent* MovementBase, const FName BoneName, FVector WorldSpaceLocation, FVector& OutLocalLocation);

	/** Convert a world space rotator to a local rotator for a given MovementBase, optionally relative to the orientation of a bone. Returns false if MovementBase is nullptr, or if BoneName is not a valid bone. Scaling is ignored. */
	UFUNCTION(BlueprintCallable, Category="Mover/MovementBases")
	static bool TransformWorldRotatorToBased(const UPrimitiveComponent* MovementBase, const FName BoneName, FRotator WorldSpaceRotator, FRotator& OutLocalRotator);

};

