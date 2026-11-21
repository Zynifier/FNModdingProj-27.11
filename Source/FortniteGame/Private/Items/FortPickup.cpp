// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortPickup.h"
#include "Net/UnrealNetwork.h"

void AFortPickup::AddSpawnSourceTags(const FGameplayTagContainer& AdditionalTagsToAdd)
{
}

bool AFortPickup::AllowLongRangeAutoPickup_Implementation(const AFortPlayerPawn* FortPawn)
{
	return false;
}

bool AFortPickup::BlueprintCanInteract_Implementation(const AFortPlayerPawn* FortPawn, bool& bCanInteractOverride)
{
	return false;
}

bool AFortPickup::BlueprintGetInteractErrorText_Implementation(FText& OverrideInteractErrorText)
{
	return false;
}

void AFortPickup::BlueprintSetPickupTarget(AFortPawn* PickupTarget, bool bPlayPickupSound)
{
}

FText AFortPickup::GetDisplayName() const
{
	return FText();
}

bool AFortPickup::GetInteractErrorText(FText& OutInteractErrorText, FGameplayTag& OutInteractErrorIconTag)
{
	return false;
}

bool AFortPickup::GetInteractText(FText& InteractText)
{
	return false;
}

const FFortItemEntry& AFortPickup::GetItemEntry(int32 ItemIndex) const
{
	static FFortItemEntry Dummy;
	return Dummy;
}

int32 AFortPickup::GetItemEntryNum() const
{
	return int32();
}

float AFortPickup::GetMovementCapsuleHalfHeight()
{
	return float();
}

float AFortPickup::GetMovementCapsuleRadius()
{
	return float();
}

AFortPlayerController* AFortPickup::GetOwnerPlayerController() const
{
	return nullptr;
}

AFortPawn* AFortPickup::GetPawnWhoDroppedPickup() const
{
	return nullptr;
}

AFortPickupEffect* AFortPickup::GetPickupEffectBlueprint() const
{
	return nullptr;
}

USkeletalMeshComponent* AFortPickup::GetPickupSkeletalMeshComponent() const
{
	return nullptr;
}

UStaticMeshComponent* AFortPickup::GetPickupStaticMeshComponent() const
{
	return nullptr;
}

const UFortItemDefinition* AFortPickup::GetPrimaryItemDefinition() const
{
	return nullptr;
}

const FFortItemEntry& AFortPickup::GetPrimaryItemEntry() const
{
	static FFortItemEntry Dummy;
	return Dummy;
}

FGuid AFortPickup::GetTrackerGuid() const
{
	return FGuid();
}

void AFortPickup::HandleConnectedActorDestroyed(AActor* DamageCauser)
{
}

void AFortPickup::HandleConnectedPhysicsActorWake(AActor* PhysicsActor)
{
}

void AFortPickup::HandleGiveItemSpawnedPickup(const AFortPlayerController* PlayerController, AFortPickup* Pickup)
{
}

void AFortPickup::HandleMoveIgnoredActorEndPlay(AActor* EndPlayActor, EEndPlayReason::Type Reason)
{
}

bool AFortPickup::IsSkeletalMeshComponent() const
{
	return false;
}

void AFortPickup::NotifyQuestManager(EFortQuestObjectiveStatEvent StatEvent, const FGameplayTagContainer& EventTags)
{
}

void AFortPickup::OnOwnerEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason)
{
}

void AFortPickup::OnRep_bPickedUp()
{
}

void AFortPickup::OnRep_ForceHideMinimapIndicator()
{
}

void AFortPickup::OnRep_PickupLocationData()
{
}

void AFortPickup::OnRep_PickupOwnerData()
{
}

void AFortPickup::OnRep_PrimaryPickupItemEntry()
{
}

void AFortPickup::OnRep_ServerImpactSoundFlash()
{
}

void AFortPickup::OnRep_ServerStoppedSimulation()
{
}

void AFortPickup::OnRep_TossedFromContainer()
{
}

void AFortPickup::OnServerBounceCallback(const FHitResult& Hit, const FVector& OldVelocity)
{
}

void AFortPickup::OnServerStopCallback(const FHitResult& Hit)
{
}

bool AFortPickup::PickedUp() const
{
	return false;
}

void AFortPickup::SetCombinePickupsWhenTossCompletes(const bool CombinePickupsWhenTossCompletes)
{
}

void AFortPickup::SetDespawnTime(float InDespawnTime)
{
}

void AFortPickup::SetDropper(const AFortPlayerController* Dropper)
{
}

void AFortPickup::SetOverrideInteractRadius(float NewRadius)
{
}

void AFortPickup::SetPickedUp(const bool bInPickedUp)
{
}

void AFortPickup::TossPickup(const FVector FinalLocation, AFortPawn* ItemOwner, int32 OverrideMaxStackCount, bool bToss, bool bShouldCombinePickupsWhenTossCompletes, const EFortPickupSourceTypeFlag InPickupSourceTypeFlags, const EFortPickupSpawnSource InPickupSpawnSource)
{
}

void AFortPickup::UpdateVolumeToNearestSpatialInterface(FVector InNewLocation, const UObject* WorldContext)
{
}

void AFortPickup::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPickup, PrimaryPickupItemEntry);
	DOREPLIFETIME(AFortPickup, MultiItemPickupEntries);
	DOREPLIFETIME(AFortPickup, PickupLocationData);
	DOREPLIFETIME(AFortPickup, OptionalOwnerID);
	DOREPLIFETIME(AFortPickup, bPickedUp);
	DOREPLIFETIME(AFortPickup, bTossedFromContainer);
	DOREPLIFETIME(AFortPickup, bForceHideMinimapIndicator);
	DOREPLIFETIME(AFortPickup, bCombinePickupsWhenTossCompletes);
	DOREPLIFETIME(AFortPickup, bServerStoppedSimulation);
	DOREPLIFETIME(AFortPickup, ServerImpactSoundFlash);
	DOREPLIFETIME(AFortPickup, OverrideInteractAimRadius);
	DOREPLIFETIME(AFortPickup, PawnWhoDroppedPickup);
	DOREPLIFETIME(AFortPickup, SpecialActorID);
	DOREPLIFETIME(AFortPickup, bRandomRotation);
}
