// Copyright Epic Games, Inc. All Rights Reserved.

#include "Diagnostics/ControllerComponentDebugDraw.h"

UControllerComponentDebugDraw::UControllerComponentDebugDraw(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UControllerComponentDebugDraw::Clear_Implementation(const uint32 ChannelID, const uint32 InstanceID) const
{
}

void UControllerComponentDebugDraw::ClearChannel_Implementation(const uint32 ChannelID) const
{
}

void UControllerComponentDebugDraw::DrawDebugBoxInternal_Implementation(const FVector& Center, const FVector& Extent, const FQuat& Rotation, const FColor& Color, const bool bPersistentLines, const float LifeTime, float Thickness, const uint32 ChannelID, const uint32 InstanceID)
{
}

void UControllerComponentDebugDraw::DrawDebugCapsuleInternal_Implementation(const FVector& Center, const float HalfHeight, const float Radius, const FQuat& Rotation, const FColor& Color, const bool bPersistentLines, const float LifeTime, const float Thickness, const uint32 ChannelID, const uint32 InstanceID)
{
}

void UControllerComponentDebugDraw::DrawDebugConeInternal_Implementation(const FVector& Origin, const FVector& Direction, const float Length, const float AngleWidth, const float AngleHeight, int32 NumSides, const FColor& Color, const bool bPersistentLines, const float LifeTime, float Thickness, const uint32 ChannelID, const uint32 InstanceID)
{
}

void UControllerComponentDebugDraw::DrawDebugCylinderInternal_Implementation(const FVector& Start, const FVector& End, const float Radius, int32 Segments, const FColor& Color, const bool bPersistentLines, const float LifeTime, const float Thickness, const uint32 ChannelID, const uint32 InstanceID)
{
}

void UControllerComponentDebugDraw::DrawDebugDirectionalArrowInternal_Implementation(const FVector& LineStart, const FVector& LineEnd, const float ArrowSize, const FColor& Color, const bool bPersistentLines, const float LifeTime, const float Thickness, const uint32 ChannelID, const uint32 InstanceID)
{
}

void UControllerComponentDebugDraw::DrawDebugLineInternal_Implementation(const FVector& LineStart, const FVector& LineEnd, const FColor& Color, const bool bPersistentLines, const float LifeTime, const float Thickness, const uint32 ChannelID, const uint32 InstanceID)
{
}

void UControllerComponentDebugDraw::DrawDebugPointInternal_Implementation(const FVector& Position, const float Size, const FColor& Color, const bool bPersistentLines, const float LifeTime, const uint32 ChannelID, const uint32 InstanceID)
{
}

void UControllerComponentDebugDraw::DrawDebugSphereInternal_Implementation(const FVector& Center, const float Radius, const int32 Segments, const FColor& Color, const bool bPersistentLines, const float LifeTime, const float Thickness, const uint32 ChannelID, const uint32 InstanceID)
{
}

void UControllerComponentDebugDraw::Reset_Implementation(const uint32 ChannelID) const
{
}

void UControllerComponentDebugDraw::SetDebugDrawEnabled_Implementation(const bool bEnabled, const uint32 ChannelID)
{
}
