// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/SpecialActor/FortUIInfoComponent.h"
#include "Net/UnrealNetwork.h"

void UFortUIInfoComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortUIInfoComponent, LabelText);
	DOREPLIFETIME(UFortUIInfoComponent, DescriptionText);
	DOREPLIFETIME(UFortUIInfoComponent, TextureSoftPointer);
}
