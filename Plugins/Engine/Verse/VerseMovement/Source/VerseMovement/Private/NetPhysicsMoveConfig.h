// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/EngineTypes.h"
#include "Math/MathFwd.h"
#include "NetPhysicsMoveConfig.generated.h"

class UCurveFloat;

UENUM(BlueprintType)
enum class ENetPhysicsMoveResponseEffect : uint8
{
	Force = 0,
	VelocityChange = 1,
	Transform = 2,
};

UENUM(BlueprintType)
enum class ENetPhysicsMoveResponseFrame : uint8
{
	Absolute = 0,
	Object = 1,
	Camera = 2,
};

UENUM(BlueprintType)
enum class ENetPhysicsMoveResponseModifier : uint8
{
	Add = 0,
	TargetTransform = 1,
	TargetVelocity = 2,
	OverrideTransform = 3,
	OverrideVelocity = 4,
};

UENUM(BlueprintType)
enum class ENetPhysicsMoveResponseType : uint8
{
	Linear = 0,
	Angular = 1,
};

UENUM(BlueprintType)
enum class ENetPhysicsMoveTriggerType : uint8
{
	Input = 0,
	Constraint = 1,
	Physics = 2,
	Trace = 3,
	Constant = 4,
};

USTRUCT(BlueprintType)
struct FNetPhysicsMoveResponse
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FVector Vector;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	float Magnitude;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	TObjectPtr<UCurveFloat> MagnitudeCurve;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	ENetPhysicsMoveResponseType Type;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	ENetPhysicsMoveResponseFrame Frame;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	ENetPhysicsMoveResponseEffect Effect;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	ENetPhysicsMoveResponseModifier Modifier;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FVector ClampVector;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	ENetPhysicsMoveResponseFrame ClampFrame;

};

USTRUCT(BlueprintType)
struct FNetPhysicsMoveInputTriggerParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Movement")
	bool bIsAxis;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FName Name;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	TObjectPtr<UCurveFloat> AxisToMagnitudeCurve;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	bool AccumulateAxisInput;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FVector2D ClampAxis;

};

USTRUCT(BlueprintType)
struct FNetPhysicsMovePhysicsTriggerParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FVector SpeedInDirection;

};

USTRUCT(BlueprintType)
struct FNetPhysicsMoveTraceTriggerParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FVector Direction;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	ENetPhysicsMoveResponseFrame Frame;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	float Length;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	TEnumAsByte<ECollisionChannel> CollisionChannel;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FCollisionResponseContainer ResponseParams;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	bool bProportionalToHitDistance;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	TObjectPtr<UCurveFloat> HitDistanceToMagnitudeCurve;

};

USTRUCT(BlueprintType)
struct FNetPhysicsMoveTrigger
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Movement")
	ENetPhysicsMoveTriggerType Type;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FNetPhysicsMoveInputTriggerParams InputParams;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FNetPhysicsMovePhysicsTriggerParams PhysicsParams;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FNetPhysicsMoveTraceTriggerParams TraceParams;

};

USTRUCT(BlueprintType)
struct FNetPhysicsMoveConfigEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FString Name;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	TArray<FNetPhysicsMoveTrigger> Triggers;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	TArray<FNetPhysicsMoveResponse> Responses;

};

USTRUCT(BlueprintType)
struct FNetPhysicsMoveLimits
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Movement")
	bool bClampVelocity;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FVector MaxVelocity;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	bool bClampAngularVelocity;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FVector MaxAngularVelocity;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	bool bClampMaxPosition;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FVector MaxPosition;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	bool bClampMinPosition;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FVector MinPosition;

};

UCLASS()
class UNetPhysicsMoveConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Movement")
	TArray<FNetPhysicsMoveConfigEntry> Entries;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FNetPhysicsMoveLimits Limits;

};

