// Copyright Epic Games, Inc. All Rights Reserved.

#include "Visibility/FortVisibilityManagerComponent.h"
#include "Net/UnrealNetwork.h"

UFortVisibilityManagerComponent::UFortVisibilityManagerComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortVisibilityManagerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortVisibilityManagerComponent, VisibilityInfoArray);
}
