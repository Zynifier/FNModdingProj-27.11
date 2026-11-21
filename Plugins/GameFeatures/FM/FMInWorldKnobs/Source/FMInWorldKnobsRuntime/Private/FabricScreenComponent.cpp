// Copyright Epic Games, Inc. All Rights Reserved.

#include "FabricScreenComponent.h"

FVector UFabricScreenComponent::ConvertGridPositionToUnrealLocation(FVector2D GridPosition) const
{
	return FVector();
}

FVector2D UFabricScreenComponent::ConvertUnrealLocationToGridPosition(FVector UnrealPosition) const
{
	return FVector2D();
}

int32 UFabricScreenComponent::GetScreenGridHeight() const
{
	return int32();
}

int32 UFabricScreenComponent::GetScreenGridWidth() const
{
	return int32();
}

void UFabricScreenComponent::Initialize(UWidgetComponent* InScreenWidgetComponent, int32 InWidth, int32 InHeight, UFabricScreenLayoutDataAsset* ScreenLayout)
{
}

void UFabricScreenComponent::OnCopiedKnobActorSet(UFMInWorldKnobActorCopyComponent* CopyComponent, AFMInWorldKnobActorBase* NewKnobActor)
{
}

void UFabricScreenComponent::SetScreenSize(int32 InWidth, int32 InHeight)
{
}

FVector UFabricScreenComponent::SnapUnrealLocationToScreenGrid(FVector UnrealPosition) const
{
	return FVector();
}
