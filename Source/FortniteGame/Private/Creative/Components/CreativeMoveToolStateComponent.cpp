// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/CreativeMoveToolStateComponent.h"
#include "Net/UnrealNetwork.h"

void UCreativeMoveToolStateComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UCreativeMoveToolStateComponent, bPreview);
}
