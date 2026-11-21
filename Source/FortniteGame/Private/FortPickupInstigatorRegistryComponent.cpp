// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortPickupInstigatorRegistryComponent.h"
#include "Net/UnrealNetwork.h"

int32 UFortPickupInstigatorRegistryComponent::AddPickupInstigator(UObject* PickupInstigator, int32 ItemIndex, bool bItemTemplate)
{
	return int32();
}

void UFortPickupInstigatorRegistryComponent::ClearPickupInstigators()
{
}

void UFortPickupInstigatorRegistryComponent::DestroyDroppedPickups(AActor* ActorContext, int32 TrackedIndex)
{
}

void UFortPickupInstigatorRegistryComponent::DestroySpawnedPickups(AActor* ActorContext, int32 TrackedIndex)
{
}

void UFortPickupInstigatorRegistryComponent::GetDroppedPickups(AActor* ActorContext, int32 TrackedIndex, TArray<AFortPickup*>& DroppedPickups)
{
}

bool UFortPickupInstigatorRegistryComponent::GetInstigator(int32 TrackedIndex, FPickupInstigator& PickupInstigator) const
{
	return false;
}

bool UFortPickupInstigatorRegistryComponent::GetInstigatorData(int32 TrackedIndex, FPickupInstigatorData& InstigatorData) const
{
	return false;
}

bool UFortPickupInstigatorRegistryComponent::GetPickupEventHandler(int32 TrackedIndex, TScriptInterface<IFortPickupEventHandler>& EventHandler) const
{
	return false;
}

void UFortPickupInstigatorRegistryComponent::GetSpawnedPickups(AActor* ActorContext, int32 TrackedIndex, TArray<AFortPickup*>& SpawnedPickups)
{
}

bool UFortPickupInstigatorRegistryComponent::GetTemplateData(int32 TrackedIndex, FCreativeItemTemplateData& TemplateData) const
{
	return false;
}

bool UFortPickupInstigatorRegistryComponent::GetTemplateObjects(TArray<UFortCreativeItemTemplate*>& TemplateObjs, const FItemVariantHandle& VariantHandle, bool bOnlyEnabled) const
{
	return false;
}

void UFortPickupInstigatorRegistryComponent::HandlePickupClaimed(AFortPickup* Pickup, AFortPawn* InteractingPawn, const UFortWorldItemDefinition* ItemDefinition, FVector PickupLocation)
{
}

void UFortPickupInstigatorRegistryComponent::HandlePickupDestroyed(AFortPickup* Pickup)
{
}

void UFortPickupInstigatorRegistryComponent::NotifyItemCaptured(int32 TrackedIndex, APlayerController* PlayerController, const FFortItemEntry& ItemEntry)
{
}

void UFortPickupInstigatorRegistryComponent::NotifyItemRemoved(int32 TrackedIndex, APlayerController* PlayerController, const FFortItemEntry& ItemEntry)
{
}

void UFortPickupInstigatorRegistryComponent::NotifyPickupCaptured(int32 TrackedIndex, AFortPickup* Pickup)
{
}

void UFortPickupInstigatorRegistryComponent::NotifyPickupDropped(int32 TrackedIndex, AFortPickup* Pickup)
{
}

void UFortPickupInstigatorRegistryComponent::NotifyPickupSpawned(int32 TrackedIndex, AFortPickup* Pickup)
{
}

void UFortPickupInstigatorRegistryComponent::OnRep_ItemTemplateRegistry()
{
}

void UFortPickupInstigatorRegistryComponent::PostReplicateRepOverrides()
{
}

void UFortPickupInstigatorRegistryComponent::RemoveAllItemsForPickupInstigator(UObject* PickupInstigator)
{
}

void UFortPickupInstigatorRegistryComponent::RemovePickupInstigator(UObject* PickupInstigator, int32 ItemIndex)
{
}

void UFortPickupInstigatorRegistryComponent::ResolvePendingRepOverrides()
{
}

void UFortPickupInstigatorRegistryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPickupInstigatorRegistryComponent, InstigatorRegistry);
	DOREPLIFETIME(UFortPickupInstigatorRegistryComponent, ItemTemplateRegistry);
}
