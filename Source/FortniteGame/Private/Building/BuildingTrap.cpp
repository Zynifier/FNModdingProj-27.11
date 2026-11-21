// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingTrap.h"
#include "Net/UnrealNetwork.h"

void ABuildingTrap::AddDamageComponent(UPrimitiveComponent* DamageComponent)
{
}

void ABuildingTrap::AddTriggerComponent(UPrimitiveComponent* TriggerComponent)
{
}

void ABuildingTrap::AttemptRetrigger(float Seconds)
{
}

bool ABuildingTrap::BP_IsValidTarget_Implementation(const AActor* PossibleTarget) const
{
	return false;
}

bool ABuildingTrap::BP_ShouldTrigger_Implementation(const TArray<AActor*>& TouchingActors) const
{
	return false;
}

void ABuildingTrap::FinishTrigger()
{
}

void ABuildingTrap::GameplayCue_Abilities_Activation_Traps(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters)
{
}

FGameplayTag ABuildingTrap::GetActivateTrapGameplayCueTag() const
{
	return FGameplayTag();
}

TArray<UFortAlterationItemDefinition*> ABuildingTrap::GetAlterations() const
{
	return TArray<UFortAlterationItemDefinition*>();
}

float ABuildingTrap::GetArmTime()
{
	return float();
}

ABuildingSMActor* ABuildingTrap::GetBuildingAttachedTo() const
{
	return nullptr;
}

FVector ABuildingTrap::GetCenter()
{
	return FVector();
}

float ABuildingTrap::GetDamageDelay() const
{
	return float();
}

FGameplayTag ABuildingTrap::GetDelayBeginGameplayCueTag() const
{
	return FGameplayTag();
}

float ABuildingTrap::GetDurabilityPercent() const
{
	return float();
}

float ABuildingTrap::GetFireDelay() const
{
	return float();
}

float ABuildingTrap::GetMaxDurability() const
{
	return float();
}

int32 ABuildingTrap::GetNumberOfRemainingDelayedAttachingAttempts_Implementation() const
{
	return int32();
}

FGameplayTag ABuildingTrap::GetReloadBeginGameplayCueTag() const
{
	return FGameplayTag();
}

float ABuildingTrap::GetReloadTime()
{
	return float();
}

TArray<AActor*> ABuildingTrap::GetTouchingDamageTargets(const FFortTargetFilter& Filter) const
{
	return TArray<AActor*>();
}

int32 ABuildingTrap::GetTrapLevel() const
{
	return int32();
}

int32 ABuildingTrap::GetTrapRating() const
{
	return int32();
}

bool ABuildingTrap::HasDurability() const
{
	return false;
}

void ABuildingTrap::OnBlockingBuildingDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void ABuildingTrap::OnRep_AttachedTo()
{
}

void ABuildingTrap::OnRep_bTrapRecharging()
{
}

void ABuildingTrap::OnRep_ReplicatedAppliedAlterations()
{
}

void ABuildingTrap::OnTriggerEndTouch(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void ABuildingTrap::OnTriggerTouch(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void ABuildingTrap::OverrideMarkerDisplayInfo(const FMarkedActorDisplayInfo& NewDisplayInfo)
{
}

void ABuildingTrap::ResetTeamOnMinigameEnd()
{
}

void ABuildingTrap::ResetTrapLevel()
{
}

void ABuildingTrap::SetAttachedTo(ABuildingSMActor* ActorAttachedTo)
{
}

void ABuildingTrap::SetTeamForMinigameStart()
{
}

void ABuildingTrap::SpawnedFromItemDefinition(const UFortTrapItemDefinition* ItemDef, int32 InTrapLevel)
{
}

void ABuildingTrap::SwitchToAlternateMaterial_Implementation()
{
}

bool ABuildingTrap::TriggerIfAppropriate()
{
	return false;
}

void ABuildingTrap::TriggerOverlapEnd(AActor* OtherActor)
{
}

bool ABuildingTrap::UseAttachedToWhenTargeted()
{
	return false;
}

void ABuildingTrap::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingTrap, TrapData);
	DOREPLIFETIME(ABuildingTrap, AppliedAlterations);
	DOREPLIFETIME(ABuildingTrap, AttachedTo);
	DOREPLIFETIME(ABuildingTrap, TrapLevel);
	DOREPLIFETIME(ABuildingTrap, OriginalTrapLevel);
	DOREPLIFETIME(ABuildingTrap, bTrapRecharging);
}
