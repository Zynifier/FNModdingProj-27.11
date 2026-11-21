// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortActorComponent_FortInteractExtension.h"
#include "Net/UnrealNetwork.h"

UFortActorComponent_FortInteractExtension::UFortActorComponent_FortInteractExtension(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortActorComponent_FortInteractExtension::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortActorComponent_FortInteractExtension, AllowedActorsForInteraction);
}
