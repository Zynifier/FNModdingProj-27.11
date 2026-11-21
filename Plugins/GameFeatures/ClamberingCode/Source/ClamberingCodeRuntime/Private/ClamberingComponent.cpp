// Copyright Epic Games, Inc. All Rights Reserved.

#include "ClamberingComponent.h"
#include "Net/UnrealNetwork.h"

void UClamberingComponent::DrawDebugHUD(AHUD* HUD, UCanvas* Canvas)
{
}

UAnimMontage* UClamberingComponent::GetAnimMontage(float& OutPlayRate) const
{
	return nullptr;
}

void UClamberingComponent::HandleOwnerASCInitialized(UFortAbilitySystemComponent* AbilitySystemComponent, AFortPlayerPawn* AffectedPawn)
{
}

void UClamberingComponent::HandleOwnerASCInvalidated()
{
}

void UClamberingComponent::HandleOwnerDBNO()
{
}

void UClamberingComponent::HandleOwnerDied(AFortPawn* DeadPawn)
{
}

void UClamberingComponent::HandleOwnerJumpInput(bool bPressed)
{
}

void UClamberingComponent::HandleOwnerMovementModeChanged(ACharacter* Character, EMovementMode PreviousMovementMode, uint8 PreviousCustomMode)
{
}

void UClamberingComponent::HandleOwnerTeleported(AFortPawn* TeleportedOwner)
{
}

void UClamberingComponent::HandleTargetActorDestroyed(AActor* Actor)
{
}

void UClamberingComponent::HandleTargetActorHealthChanged()
{
}

bool UClamberingComponent::IsAutoClamberingEnabled() const
{
	return false;
}

bool UClamberingComponent::IsClamberingEnabled() const
{
	return false;
}

bool UClamberingComponent::IsTutorialModeEnabled() const
{
	return false;
}

void UClamberingComponent::NetMulticast_ClamberingLedgeFailed_Implementation(EClamberingFailedReason FailedReason, EClamberingState FailedState)
{
}

void UClamberingComponent::OnMutatorUpdated()
{
}

void UClamberingComponent::OnPlayerStatePawnSet(APlayerState* Player, APawn* NewPawn, APawn* OldPawn)
{
}

void UClamberingComponent::OnRep_ReplicatedClamberingState()
{
}

void UClamberingComponent::OnRep_ReplicatedLastTeleportTime()
{
}

void UClamberingComponent::OnRep_ReplicatedTargetingData()
{
}

void UClamberingComponent::RegisterMutatorUpdatedDelegate(APawn* AffectedPawn)
{
}

void UClamberingComponent::ServerStartClambering_Implementation(const FReplicatedClamberingTargetingData InReplicatedTargetingData, const double ClientLastTeleportTime)
{
}
bool UClamberingComponent::ServerStartClambering_Validate(const FReplicatedClamberingTargetingData InReplicatedTargetingData, const double ClientLastTeleportTime)
{
	return true;
}

void UClamberingComponent::SetTutorialModeEnabled(bool bEnabled)
{
}

bool UClamberingComponent::ShouldShowClamberIndicator() const
{
	return false;
}

void UClamberingComponent::UnregisterMutatorUpdatedDelegate()
{
}

void UClamberingComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UClamberingComponent, ReplicatedClamberingState);
	DOREPLIFETIME(UClamberingComponent, ReplicatedTargetingData);
	DOREPLIFETIME(UClamberingComponent, LastTeleportTime);
}
