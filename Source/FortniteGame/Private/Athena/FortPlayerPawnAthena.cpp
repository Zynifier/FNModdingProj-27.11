// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortPlayerPawnAthena.h"
#include "Net/UnrealNetwork.h"

void AFortPlayerPawnAthena::AddComponentToPawnHighlightSet(UPrimitiveComponent* PrimitiveComponent)
{
}

FCustomHighlightingHandle AFortPlayerPawnAthena::AddCustomHighlightingDataOverride(const FCustomHighlighting& CustomHighlightingData, int32 Priority)
{
	return FCustomHighlightingHandle();
}

uint8 AFortPlayerPawnAthena::AddDBNORevivingActor(const AActor* RevivingActorToAdd)
{
	return uint8();
}

void AFortPlayerPawnAthena::CancelMeleeCombatSlow()
{
}

bool AFortPlayerPawnAthena::CanPlayerCreateInCurrentVolume(AFortVolume*& OutCurrentVolume) const
{
	return false;
}

void AFortPlayerPawnAthena::ClientSetGravityJumpMultipliers_Implementation(float NewGravityVal, float NewVehicleGravityVal, float NewJumpZ, float NewJumpHorizontalAcceleration, float NewJumpHorizontalVelocity)
{
}

void AFortPlayerPawnAthena::CreativeToggleGhost(const bool bEnableOnly)
{
}

void AFortPlayerPawnAthena::CreativeToggleInvulnerable()
{
}

void AFortPlayerPawnAthena::FastSharedReplication_Implementation(const FSharedRepMovement& SharedRepMovement)
{
}

void AFortPlayerPawnAthena::ForceReviveFromDBNO(AController* EventInstigator)
{
}

void AFortPlayerPawnAthena::GameplayCue_Creative_PossessProp(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters)
{
}

void AFortPlayerPawnAthena::GameplayCue_PinkOatmeal_MeatPizza_PossessProp(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters)
{
}

UAnimMontage* AFortPlayerPawnAthena::GetAdditiveHitReactsMontage_Implementation()
{
	return nullptr;
}

float AFortPlayerPawnAthena::GetCurrentVoiceAmplitude()
{
	return float();
}

float AFortPlayerPawnAthena::GetDefaultReviveFromDBNOTime()
{
	return float();
}

float AFortPlayerPawnAthena::GetDownedDBNOInvulnerableTime() const
{
	return float();
}

float AFortPlayerPawnAthena::GetMeleeCombatSlowSpeedMultiplier() const
{
	return float();
}

uint8 AFortPlayerPawnAthena::GetNumberOfDBNORevivingActors() const
{
	return uint8();
}

float AFortPlayerPawnAthena::GetReviveFromDBNOTime() const
{
	return float();
}

bool AFortPlayerPawnAthena::IsBackpackEquipped(EBackpackType BackpackType) const
{
	return false;
}

bool AFortPlayerPawnAthena::IsPlayingMinigame() const
{
	return false;
}

void AFortPlayerPawnAthena::LandscapeCheck()
{
}

bool AFortPlayerPawnAthena::LocalIsTryingToEnterVehicle()
{
	return false;
}

void AFortPlayerPawnAthena::MeleeCombatActivated()
{
}

void AFortPlayerPawnAthena::MeleeCombatBlocked()
{
}

void AFortPlayerPawnAthena::NetMulticast_SuccessfulBuildingEdit_Implementation()
{
}

void AFortPlayerPawnAthena::OnRep_AttributeProxy()
{
}

void AFortPlayerPawnAthena::OnRep_bIsCreativeGhostModeActivated()
{
}

void AFortPlayerPawnAthena::OnRep_bIsCreativeModeratorModeActivated()
{
}

void AFortPlayerPawnAthena::OnRep_CapsuleHalfHeightAthena()
{
}

void AFortPlayerPawnAthena::OnRep_CapsuleRadiusAthena()
{
}

void AFortPlayerPawnAthena::OnRep_GravityAttributeReplicationProxy()
{
}

void AFortPlayerPawnAthena::OnRep_ImprovedDBNOEnabled()
{
}

void AFortPlayerPawnAthena::OnRep_MeshHeightAdjustAthena()
{
}

void AFortPlayerPawnAthena::OnRep_ReplayRepAnimMontageInfo()
{
}

bool AFortPlayerPawnAthena::RemoveCustomHighlightingDataOverride(FCustomHighlightingHandle& HandleToRemove)
{
	return false;
}

uint8 AFortPlayerPawnAthena::RemoveDBNORevivingActor(const AActor* RevivingActorToRemove)
{
	return uint8();
}

void AFortPlayerPawnAthena::ResetCachedDBNOInvulnerableTime()
{
}

void AFortPlayerPawnAthena::ServerCreativeToggleGhost_Implementation(const bool bEnableOnly)
{
}
bool AFortPlayerPawnAthena::ServerCreativeToggleGhost_Validate(const bool bEnableOnly)
{
	return true;
}

void AFortPlayerPawnAthena::ServerCreativeToggleInvulnerable_Implementation()
{
}
bool AFortPlayerPawnAthena::ServerCreativeToggleInvulnerable_Validate()
{
	return true;
}

void AFortPlayerPawnAthena::ServerForceImmediateLandscapeCheck_Implementation()
{
}

void AFortPlayerPawnAthena::ServerSetInteractingItem_Implementation(AActor* InteractingItem, bool bClearInteraction)
{
}
bool AFortPlayerPawnAthena::ServerSetInteractingItem_Validate(AActor* InteractingItem, bool bClearInteraction)
{
	return true;
}

void AFortPlayerPawnAthena::ServerSuicide_Implementation(bool bSuppressResurrectionChip, int32 MatchPlacement)
{
}
bool AFortPlayerPawnAthena::ServerSuicide_Validate(bool bSuppressResurrectionChip, int32 MatchPlacement)
{
	return true;
}

void AFortPlayerPawnAthena::SetBushEnabled(bool bEnableBush)
{
}

void AFortPlayerPawnAthena::SetCapsuleHalfHeightAthena(float HalfHeight)
{
}

void AFortPlayerPawnAthena::SetCapsuleRadiusAthena(float Radius)
{
}

bool AFortPlayerPawnAthena::SetCharacterBodyVisibilityForPossession(bool bVisible)
{
	return false;
}

void AFortPlayerPawnAthena::SetDamageCameraShakeClass(TSubclassOf<ULegacyCameraShake> NewValue)
{
}

void AFortPlayerPawnAthena::SetEnableRenderCustomDepth(bool bInEnableRenderCustomDepth)
{
}

void AFortPlayerPawnAthena::SetFallInstigator(AController* NewFallInstigator, FGameplayTagContainer NewFallingDamageTags)
{
}

void AFortPlayerPawnAthena::SetImprovedDBNO(bool bEnable)
{
}

void AFortPlayerPawnAthena::SetIsSignificantForSpecialEventSequence(const bool bIsSignificant)
{
}

void AFortPlayerPawnAthena::SetMeshHeightAdjustAthena(double HeightAdjust)
{
}

void AFortPlayerPawnAthena::SetRimLightIntensity(float Multiplier, const TArray<UMaterialInstanceDynamic*>& AllPawnMaterials)
{
}

void AFortPlayerPawnAthena::SetShouldDropItemsOnDeath(bool bInShouldDropItemsOnDeath)
{
}

void AFortPlayerPawnAthena::SetShouldSkipMovementFullSimulation(bool bInShouldSkipMovementFullSimulation)
{
}

void AFortPlayerPawnAthena::SetUpdateSharedReplicationWhileAttached(bool bNewValue)
{
}

void AFortPlayerPawnAthena::SpawnNiagaraEnvironmentComponents(const bool bRegister)
{
}

void AFortPlayerPawnAthena::StartConsumableUseAudio(USoundBase* Sound)
{
}

void AFortPlayerPawnAthena::StopConsumableUseAudio()
{
}

FVector AFortPlayerPawnAthena::Swinging_VectorToAttachPoint(const FString& CallerID)
{
	return FVector();
}

void AFortPlayerPawnAthena::SwingingUpdateMeshRotation(float DeltaTime)
{
}

void AFortPlayerPawnAthena::TeleportToSkyDive(float HeightAboveGround)
{
}

void AFortPlayerPawnAthena::TurnOnCollisionAfterSkydiveDelay()
{
}

void AFortPlayerPawnAthena::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPlayerPawnAthena, ItemInteractionActor);
	DOREPLIFETIME(AFortPlayerPawnAthena, ServerWorldTimeRevivalTime);
	DOREPLIFETIME(AFortPlayerPawnAthena, ItemSpecialActorID);
	DOREPLIFETIME(AFortPlayerPawnAthena, ItemSpecialActorCategoryTag);
	DOREPLIFETIME(AFortPlayerPawnAthena, CapsuleRadiusAthena);
	DOREPLIFETIME(AFortPlayerPawnAthena, CapsuleHalfHeightAthena);
	DOREPLIFETIME(AFortPlayerPawnAthena, MeshHeightAdjustAthena);
	DOREPLIFETIME(AFortPlayerPawnAthena, AttributeReplicationProxy);
	DOREPLIFETIME(AFortPlayerPawnAthena, GravityAttributeReplicationProxy);
	DOREPLIFETIME(AFortPlayerPawnAthena, ReplayRepAnimMontageInfo);
	DOREPLIFETIME(AFortPlayerPawnAthena, SimulatedProxyActiveGameplayCues);
	DOREPLIFETIME(AFortPlayerPawnAthena, SimulatedProxyMinimalReplicationGameplayCues);
	DOREPLIFETIME(AFortPlayerPawnAthena, FastReplicationMinimalReplicationTags);
	DOREPLIFETIME(AFortPlayerPawnAthena, FastReplicationReplicatedLooseTags);
	DOREPLIFETIME(AFortPlayerPawnAthena, EncryptedPawnReplayData);
	DOREPLIFETIME(AFortPlayerPawnAthena, bIsCreativeGhostModeActivated);
	DOREPLIFETIME(AFortPlayerPawnAthena, bIsCreativeModeratorModeActivated);
	DOREPLIFETIME(AFortPlayerPawnAthena, UpdateSharedReplicationWhileAttachedCount);
	DOREPLIFETIME(AFortPlayerPawnAthena, bImprovedDBNOEnabled);
	DOREPLIFETIME(AFortPlayerPawnAthena, DBNORevivingActorsCount);
}

void AFortPlayerPawnAthena::GetActorSoundParams_Implementation(TArray<FAudioParameter>& Params) const
{
}
