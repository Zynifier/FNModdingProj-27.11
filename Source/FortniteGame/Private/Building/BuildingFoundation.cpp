// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingFoundation.h"
#include "Net/UnrealNetwork.h"

bool ABuildingFoundation::DoesBuildingFoundationContainActor(AActor* Actor) const
{
	return false;
}

void ABuildingFoundation::EditorOnlyAddAdditionalWorld(FString& LevelPackageName)
{
}

bool ABuildingFoundation::EditorOnlyAddTransformToPreviewLevel(const FTransform& DeltaTransform)
{
	return false;
}

void ABuildingFoundation::EditorOnlyClearAdditionalWorlds()
{
}

void ABuildingFoundation::EditorOnlyEnterBatchPreview()
{
}

void ABuildingFoundation::EditorOnlyExitBatchPreview()
{
}

TArray<FString> ABuildingFoundation::EditorOnlyGetAdditionalWorlds()
{
	return TArray<FString>();
}

bool ABuildingFoundation::EditorOnlyLoadPreviewLevel(bool bCreateLevelInstance)
{
	return false;
}

bool ABuildingFoundation::EditorOnlyRemoveAdditionalWorld(FString& LevelToRemove)
{
	return false;
}

bool ABuildingFoundation::EditorOnlyUnloadPreviewLevel()
{
	return false;
}

#if WITH_EDITOR
bool ABuildingFoundation::GetPreviewFoundationLevelInEditor() const
{
	return false;
}
#endif

bool ABuildingFoundation::GetStreamedInActors(TArray<AActor*>& StreamedInActors) const
{
	return false;
}

void ABuildingFoundation::HideHLODProxies()
{
}

void ABuildingFoundation::OnLevelShown()
{
}

void ABuildingFoundation::OnLevelStreamedIn()
{
}

void ABuildingFoundation::OnLevelStreamedOut()
{
}

void ABuildingFoundation::OnRep_DynamicFoundationRepData()
{
}

void ABuildingFoundation::OnRep_LevelToStream()
{
}

void ABuildingFoundation::OnRep_ServerStreamedInLevel()
{
}

void ABuildingFoundation::OnStaticLevelShown()
{
}

void ABuildingFoundation::SetDynamicFoundationEnabled(bool bEnabled)
{
}

void ABuildingFoundation::SetDynamicFoundationTransform(const FTransform& NewTransform)
{
}

void ABuildingFoundation::ShowHLODProxies()
{
}

void ABuildingFoundation::UpdateMinimapDetailsLocation(const FVector& InLocation)
{
}

void ABuildingFoundation::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingFoundation, bServerStreamedInLevel);
	DOREPLIFETIME(ABuildingFoundation, LevelToStream);
	DOREPLIFETIME(ABuildingFoundation, DynamicFoundationRepData);
}
