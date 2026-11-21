// Copyright Epic Games, Inc. All Rights Reserved.

#include "ObjectTracking/FortClassTrackerComponent.h"
#include "Net/UnrealNetwork.h"

void UFortClassTrackerComponent::AddActor(AActor* Actor, TScriptInterface<IFortSpatialGameplayInterface> Volume)
{
}

void UFortClassTrackerComponent::RemoveActor(AActor* Actor, TScriptInterface<IFortSpatialGameplayInterface> Volume)
{
}

void UFortClassTrackerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortClassTrackerComponent, bEnabled);
	DOREPLIFETIME(UFortClassTrackerComponent, ClassTracker);
	DOREPLIFETIME(UFortClassTrackerComponent, ExcludeActorTags);
}
