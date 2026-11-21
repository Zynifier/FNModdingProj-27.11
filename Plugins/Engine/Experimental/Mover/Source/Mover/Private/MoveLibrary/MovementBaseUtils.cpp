// Copyright Epic Games, Inc. All Rights Reserved.

#include "MoveLibrary/MovementBaseUtils.h"

bool UMovementBaseUtils::GetMovementBaseTransform(const UPrimitiveComponent* MovementBase, const FName BoneName, FVector& OutLocation, FQuat& OutQuat)
{
	return false;
}

bool UMovementBaseUtils::IsADynamicBase(const UPrimitiveComponent* MovementBase)
{
	return false;
}

bool UMovementBaseUtils::TransformBasedDirectionToWorld(const UPrimitiveComponent* MovementBase, const FName BoneName, FVector LocalDirection, FVector& OutDirectionWorldSpace)
{
	return false;
}

bool UMovementBaseUtils::TransformBasedLocationToWorld(const UPrimitiveComponent* MovementBase, const FName BoneName, FVector LocalLocation, FVector& OutLocationWorldSpace)
{
	return false;
}

bool UMovementBaseUtils::TransformBasedRotatorToWorld(const UPrimitiveComponent* MovementBase, const FName BoneName, FRotator LocalRotator, FRotator& OutWorldSpaceRotator)
{
	return false;
}

void UMovementBaseUtils::TransformDirectionToLocal(FQuat BaseQuat, FVector WorldSpaceDirection, FVector& OutLocalDirection)
{
}

void UMovementBaseUtils::TransformDirectionToWorld(FQuat BaseQuat, FVector LocalDirection, FVector& OutDirectionWorldSpace)
{
}

void UMovementBaseUtils::TransformLocationToLocal(FVector BasePos, FQuat BaseQuat, FVector WorldSpaceLocation, FVector& OutLocalLocation)
{
}

void UMovementBaseUtils::TransformLocationToWorld(FVector BasePos, FQuat BaseQuat, FVector LocalLocation, FVector& OutLocationWorldSpace)
{
}

void UMovementBaseUtils::TransformRotatorToLocal(FQuat BaseQuat, FRotator WorldSpaceRotator, FRotator& OutLocalRotator)
{
}

void UMovementBaseUtils::TransformRotatorToWorld(FQuat BaseQuat, FRotator LocalRotator, FRotator& OutWorldSpaceRotator)
{
}

bool UMovementBaseUtils::TransformWorldDirectionToBased(const UPrimitiveComponent* MovementBase, const FName BoneName, FVector WorldSpaceDirection, FVector& OutLocalDirection)
{
	return false;
}

bool UMovementBaseUtils::TransformWorldLocationToBased(const UPrimitiveComponent* MovementBase, const FName BoneName, FVector WorldSpaceLocation, FVector& OutLocalLocation)
{
	return false;
}

bool UMovementBaseUtils::TransformWorldRotatorToBased(const UPrimitiveComponent* MovementBase, const FName BoneName, FRotator WorldSpaceRotator, FRotator& OutLocalRotator)
{
	return false;
}
