// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingSMOverridesComponent.h"
#include "Net/UnrealNetwork.h"

UBuildingSMOverridesComponent::UBuildingSMOverridesComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UBuildingSMOverridesComponent::OnRep_OverrideMeshMaterials()
{
}

void UBuildingSMOverridesComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UBuildingSMOverridesComponent, OverrideMeshMaterials);
}
