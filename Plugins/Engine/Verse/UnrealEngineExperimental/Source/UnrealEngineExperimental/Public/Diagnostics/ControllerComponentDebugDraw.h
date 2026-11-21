// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "ControllerComponentDebugDraw.generated.h"

class ULineBatchComponent;

USTRUCT()
struct FPersistentLineBatcher
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<ULineBatchComponent> PersistentLineBatcher;

};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UControllerComponentDebugDraw : public UControllerComponent
{
	GENERATED_BODY()

public:
	UControllerComponentDebugDraw(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(Client, Reliable)
	void Clear(const uint32 ChannelID, const uint32 InstanceID) const;

	UFUNCTION(Client, Reliable)
	void ClearChannel(const uint32 ChannelID) const;

	UFUNCTION(Client, Reliable)
	void Reset(const uint32 ChannelID) const;

	UFUNCTION(NetMulticast, Reliable)
	void SetDebugDrawEnabled(const bool bEnabled, const uint32 ChannelID);

protected:
	UFUNCTION(Client, Reliable)
	void DrawDebugBoxInternal(const FVector& Center, const FVector& Extent, const FQuat& Rotation, const FColor& Color, const bool bPersistentLines, const float LifeTime, float Thickness, const uint32 ChannelID, const uint32 InstanceID);

	UFUNCTION(Client, Reliable)
	void DrawDebugCapsuleInternal(const FVector& Center, const float HalfHeight, const float Radius, const FQuat& Rotation, const FColor& Color, const bool bPersistentLines, const float LifeTime, const float Thickness, const uint32 ChannelID, const uint32 InstanceID);

	UFUNCTION(Client, Reliable)
	void DrawDebugConeInternal(const FVector& Origin, const FVector& Direction, const float Length, const float AngleWidth, const float AngleHeight, int32 NumSides, const FColor& Color, const bool bPersistentLines, const float LifeTime, float Thickness, const uint32 ChannelID, const uint32 InstanceID);

	UFUNCTION(Client, Reliable)
	void DrawDebugCylinderInternal(const FVector& Start, const FVector& End, const float Radius, int32 Segments, const FColor& Color, const bool bPersistentLines, const float LifeTime, const float Thickness, const uint32 ChannelID, const uint32 InstanceID);

	UFUNCTION(Client, Reliable)
	void DrawDebugDirectionalArrowInternal(const FVector& LineStart, const FVector& LineEnd, const float ArrowSize, const FColor& Color, const bool bPersistentLines, const float LifeTime, const float Thickness, const uint32 ChannelID, const uint32 InstanceID);

	UFUNCTION(Client, Reliable)
	void DrawDebugLineInternal(const FVector& LineStart, const FVector& LineEnd, const FColor& Color, const bool bPersistentLines, const float LifeTime, const float Thickness, const uint32 ChannelID, const uint32 InstanceID);

	UFUNCTION(Client, Reliable)
	void DrawDebugPointInternal(const FVector& Position, const float Size, const FColor& Color, const bool bPersistentLines, const float LifeTime, const uint32 ChannelID, const uint32 InstanceID);

	UFUNCTION(Client, Reliable)
	void DrawDebugSphereInternal(const FVector& Center, const float Radius, const int32 Segments, const FColor& Color, const bool bPersistentLines, const float LifeTime, const float Thickness, const uint32 ChannelID, const uint32 InstanceID);

	UPROPERTY(Transient)
	TArray<FPersistentLineBatcher> PersistentLineBatchers;

};

