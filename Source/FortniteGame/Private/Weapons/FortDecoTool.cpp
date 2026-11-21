// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/FortDecoTool.h"
#include "Net/UnrealNetwork.h"

void AFortDecoTool::ClientDestroyDecoPreview_Implementation()
{
}

void AFortDecoTool::OnCarriedActorDestroyed(AActor* DestroyedActor)
{
}

void AFortDecoTool::OnRep_CarriedActor(AActor* OldCarriedActor)
{
}

void AFortDecoTool::OnRep_ItemDefinition()
{
}

void AFortDecoTool::OnUnEquip()
{
}

void AFortDecoTool::ServerCreateBuildingAndSpawnDeco_Implementation(FVector_NetQuantize10 BuildingLocation, FRotator BuildingRotation, FVector_NetQuantize10 Location, FRotator Rotation, EBuildingAttachmentType InBuildingAttachmentType, bool bSpawnDecoOnExtraPiece, FVector BuildingExtraPieceLocation)
{
}
bool AFortDecoTool::ServerCreateBuildingAndSpawnDeco_Validate(FVector_NetQuantize10 BuildingLocation, FRotator BuildingRotation, FVector_NetQuantize10 Location, FRotator Rotation, EBuildingAttachmentType InBuildingAttachmentType, bool bSpawnDecoOnExtraPiece, FVector BuildingExtraPieceLocation)
{
	return true;
}

void AFortDecoTool::ServerSpawnDeco_Implementation(FVector Location, FRotator Rotation, ABuildingSMActor* AttachedActor, EBuildingAttachmentType InBuildingAttachmentType)
{
}
bool AFortDecoTool::ServerSpawnDeco_Validate(FVector Location, FRotator Rotation, ABuildingSMActor* AttachedActor, EBuildingAttachmentType InBuildingAttachmentType)
{
	return true;
}

void AFortDecoTool::SetDecoObjectPreview(const UFortItemDefinition* InItemDefinition, bool bUpdatePreviewPosition)
{
}

void AFortDecoTool::SetHelper(AFortDecoHelper* InHelper)
{
}

bool AFortDecoTool::TryToPlace()
{
	return false;
}

void AFortDecoTool::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortDecoTool, ItemDefinition);
	DOREPLIFETIME(AFortDecoTool, CarriedActor);
}
