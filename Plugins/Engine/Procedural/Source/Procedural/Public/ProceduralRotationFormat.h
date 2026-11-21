// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralRotationFormat.generated.h"

UENUM(BlueprintType)
enum class EProceduralRotationFormat : uint8
{
	/** RGB are interpreted as 3D Vector components aligned on +X axis. */
	VectorXAxis = 0 UMETA(DisplayName="3D Vector +X Axis"),
	/** RGB are interpreted as 3D Vector components aligned on -X axis. */
	VectorXAxisNegative = 1 UMETA(DisplayName="3D Vector -X Axis"),
	/** RGB are interpreted as 3D Vector components aligned on +Y axis. */
	VectorYAxis = 2 UMETA(DisplayName="3D Vector +Y Axis"),
	/** RGB are interpreted as 3D Vector components aligned on -Y axis. */
	VectorYAxisNegative = 3 UMETA(DisplayName="3D Vector -Y Axis"),
	/** RGB are interpreted as 3D Vector components aligned on +Z axis. */
	VectorZAxis = 4 UMETA(DisplayName="3D Vector +Z Axis"),
	/** RGB are interpreted as 3D Vector components aligned on -Z axis. */
	VectorZAxisNegative = 5 UMETA(DisplayName="3D Vector -Z Axis"),
	/** RG are interpreted as 2D Vector components aligned on +X axis. */
	Vector2DXAxis = 6 UMETA(DisplayName="2D Vector +X Axis"),
	/** RG are interpreted as 2D Vector components aligned on -X axis. */
	Vector2DXAxisNegative = 7 UMETA(DisplayName="2D Vector -X Axis"),
	/** RG are interpreted as 2D Vector components aligned on +Y axis. */
	Vector2DYAxis = 8 UMETA(DisplayName="2D Vector +Y Axis"),
	/** RG are interpreted as 2D Vector components aligned on -Y axis. */
	Vector2DYAxisNegative = 9 UMETA(DisplayName="2D Vector -Y Axis"),
	/** RG are interpreted as 2D Vector components aligned on +Z axis. */
	Vector2DZAxis = 10 UMETA(DisplayName="2D Vector +Z Axis"),
	/** RG are interpreted as 2D Vector components aligned on -Z axis. */
	Vector2DZAxisNegative = 11 UMETA(DisplayName="2D Vector -Z Axis"),
	/** RGB are interpreted as Rotator components Roll, Pitch and Yaw ([0,1] remapped to Range[Min,Max] in degrees). */
	RangedRotator = 12 UMETA(DisplayName="Ranged Angles"),
};

