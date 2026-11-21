// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortPawnComponent_CustomDepth.h"
#include "Net/UnrealNetwork.h"

void UFortPawnComponent_CustomDepth::ForceRenderCustomDepthUpdateForAllActors()
{
}

bool UFortPawnComponent_CustomDepth::IsRenderCustomDepthEnabled() const
{
	return false;
}

void UFortPawnComponent_CustomDepth::OnRep_EnableRenderCustomDepth()
{
}

void UFortPawnComponent_CustomDepth::Update(float DeltaTime, bool bForcedUpdate)
{
}

void UFortPawnComponent_CustomDepth::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPawnComponent_CustomDepth, bEnableRenderCustomDepth);
}
