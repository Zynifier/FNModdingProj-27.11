// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BattleLab/BattleLabDeviceGameplayActor_VendingMachine.h"
#include "Net/UnrealNetwork.h"

void ABattleLabDeviceGameplayActor_VendingMachine::AddStoredItemDefinitionMulti_Implementation(const UFortItemDefinition* InItemDefinition)
{
}

void ABattleLabDeviceGameplayActor_VendingMachine::OnFunnelCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void ABattleLabDeviceGameplayActor_VendingMachine::OnRep_DroppedIntoFunnelPickup()
{
}

void ABattleLabDeviceGameplayActor_VendingMachine::PreviewImageLoadedFromItemDef(TSoftObjectPtr<UTexture2D> PreviewImage)
{
}

bool ABattleLabDeviceGameplayActor_VendingMachine::ServerOnAttemptInteract(const FInteractionType& InteractType)
{
	return false;
}

void ABattleLabDeviceGameplayActor_VendingMachine::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABattleLabDeviceGameplayActor_VendingMachine, DroppedIntoFunnelPickup);
}
