// Copyright Epic Games, Inc. All Rights Reserved.

#include "WorldTiles/WorldTileFoundation.h"
#include "Net/UnrealNetwork.h"

void AWorldTileFoundation::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AWorldTileFoundation, NumRotations);
}
