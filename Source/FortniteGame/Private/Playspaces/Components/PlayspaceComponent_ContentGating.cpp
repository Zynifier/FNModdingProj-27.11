// Copyright Epic Games, Inc. All Rights Reserved.

#include "Playspaces/Components/PlayspaceComponent_ContentGating.h"
#include "Net/UnrealNetwork.h"

void UPlayspaceComponent_ContentGating::OnRep_ContentProfileChanged()
{
}

void UPlayspaceComponent_ContentGating::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UPlayspaceComponent_ContentGating, ContentProfile);
}
