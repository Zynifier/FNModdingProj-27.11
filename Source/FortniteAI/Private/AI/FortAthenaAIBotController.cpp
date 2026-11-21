// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/FortAthenaAIBotController.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaAIBotController::AddTargetInfo(AActor* Target, const bool bForceTarget, const EPerceptionState PerceptionState, const float ForgetTime, const float ForgetDistance)
{
}

void AFortAthenaAIBotController::AddTargetInfos(const TArray<AActor*>& Targets, const EPerceptionState PerceptionState, const float ForgetTime, const float ForgetDistance)
{
}

void AFortAthenaAIBotController::ChangeActiveVariantForCosmeticItem(FName ItemTemplateToChange, FGameplayTag VariantChannelToChange, FGameplayTag DesiredActiveVariant)
{
}

void AFortAthenaAIBotController::Cheat_ClearForcedCosmeticItems_Implementation()
{
}
bool AFortAthenaAIBotController::Cheat_ClearForcedCosmeticItems_Validate()
{
	return true;
}

void AFortAthenaAIBotController::Cheat_ForceAthenaCosmeticItemInSlot_Implementation(const UAthenaCosmeticItemDefinition* CosmeticItem, EAthenaCustomizationCategory Slot, int32 Index)
{
}
bool AFortAthenaAIBotController::Cheat_ForceAthenaCosmeticItemInSlot_Validate(const UAthenaCosmeticItemDefinition* CosmeticItem, EAthenaCustomizationCategory Slot, int32 Index)
{
	return true;
}

AFortWeapon* AFortAthenaAIBotController::EquipBestWeapon(const bool bUpdateBB)
{
	return nullptr;
}

AFortWeapon* AFortAthenaAIBotController::EquipMeleeWeapon()
{
	return nullptr;
}

AFortWeapon* AFortAthenaAIBotController::EquipWeapon(const UFortWorldItem* Weapon, const bool bUpdateBB)
{
	return nullptr;
}

AFortWeapon* AFortAthenaAIBotController::EquipWeaponByTag(const FGameplayTag& WeaponTag)
{
	return nullptr;
}

AActor* AFortAthenaAIBotController::GetBotOwner() const
{
	return nullptr;
}

AActor* AFortAthenaAIBotController::GetCurrentTarget() const
{
	return nullptr;
}

AActor* AFortAthenaAIBotController::GetCurrentThreat() const
{
	return nullptr;
}

UAthenaMarkerComponent* AFortAthenaAIBotController::GetMarkerComponent() const
{
	return nullptr;
}

const UFortWorldItem* AFortAthenaAIBotController::GetSlotItemByItemDefinition(const UFortItemDefinition* ItemDefinition) const
{
	return nullptr;
}

const UFortWorldItem* AFortAthenaAIBotController::GetSlotItemByTag(const FGameplayTag& TagToCheck) const
{
	return nullptr;
}

bool AFortAthenaAIBotController::IsAnAthenaGameParticipant() const
{
	return false;
}

void AFortAthenaAIBotController::NotifyPickupsSpawnedOnDeath(const TArray<AFortPickup*>& SpawnedPickups, const int32 SpawnRequestId)
{
}

void AFortAthenaAIBotController::OnAgentDBNO(AFortPawn* InPlayer, bool bInIsDBNO)
{
}

void AFortAthenaAIBotController::OnBeginSpectating(AFortPlayerStateZone* Spectator)
{
}

void AFortAthenaAIBotController::OnCurrentHarvestableDestroyed(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void AFortAthenaAIBotController::OnEndSpectating(AFortPlayerStateZone* Spectator)
{
}

void AFortAthenaAIBotController::OnKnockbacked(const FGameplayTag KnockbackTypeTag)
{
}

void AFortAthenaAIBotController::OnLaunched(const FVector LaunchVelocity, const bool bXYOverride, const bool bZOverride)
{
}

void AFortAthenaAIBotController::OnMovementModeChange(ACharacter* InCharacter, EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
}

void AFortAthenaAIBotController::OnPawnDidDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* HitComponent, FName BoneName, FVector Momentum)
{
}

void AFortAthenaAIBotController::OnPawnWeaponChanged(AFortWeapon* NewWeapon, AFortWeapon* OldWeapon)
{
}

void AFortAthenaAIBotController::OnPerceptionSensed(AActor* SourceActor, FAIStimulus Stim)
{
}

void AFortAthenaAIBotController::OnPossesedPawnDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void AFortAthenaAIBotController::OnPossessedPawnReceiveDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void AFortAthenaAIBotController::OnServerMarkerAdded(const FFortWorldMarkerData& MarkerData)
{
}

void AFortAthenaAIBotController::OnTargetActorDestroyed(AActor* DestroyedActor)
{
}

void AFortAthenaAIBotController::OnTargetBuildingDestroyed(ABuildingActor* Building, AAthenaAIController* AIController)
{
}

void AFortAthenaAIBotController::OnTargetPawnDamaged(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void AFortAthenaAIBotController::OnTargetPawnDead(AFortPawn* FortPawn)
{
}

void AFortAthenaAIBotController::OnTargetPawnDestroyed()
{
}

void AFortAthenaAIBotController::OverrideAggressivenessPlayStyle(bool bInIsAggressive)
{
}

void AFortAthenaAIBotController::OverrideSkill(const float NewSkill)
{
}

void AFortAthenaAIBotController::PlayEmote(const FPrimaryAssetId& EmotePrimaryAssetId)
{
}

void AFortAthenaAIBotController::QueueStim(AActor* SourceActor, const FVector& SourceLocation, const FVector& SourceDirection, const EStimType NewStimType, const float StimStrength, const FName StimTag)
{
}

void AFortAthenaAIBotController::ReleaseBuildTool()
{
}

void AFortAthenaAIBotController::RemoveEmoteRequest()
{
}

void AFortAthenaAIBotController::RemoveSkillSet(TSubclassOf<UFortAthenaAIBotSkillSet> SkillSetClass)
{
}

void AFortAthenaAIBotController::RequestEmote(const FPrimaryAssetId& EmotePrimaryAssetId, float InfiniteEmoteMaxDuration)
{
}

void AFortAthenaAIBotController::RequestMoveAwayFromBox(const FBox& MoveAwayBox)
{
}

void AFortAthenaAIBotController::ResetPerceptionAndTargets(const EBlackboardUpdateType BlackboardUpdateType)
{
}

void AFortAthenaAIBotController::SetBotOwner(AActor* InBotOwner)
{
}

void AFortAthenaAIBotController::SetLeashActorToFollow(const AActor* ActorToFollow, const float LeashLocationUpdateRate, const FVector LocalOffset)
{
}

void AFortAthenaAIBotController::SetLeashGameplayVolume(const AGameplayVolume* InLeashGameplayVolume)
{
}

void AFortAthenaAIBotController::SetLeashReturnLocationMode(ELeashReturnLocationMode ReturnMode)
{
}

void AFortAthenaAIBotController::SetLeashVolume(AFortAthenaAILeashVolume* InLeashVolume)
{
}

void AFortAthenaAIBotController::SetPatrollingEnable(const bool bEnable)
{
}

void AFortAthenaAIBotController::SetRadialLeashAlertLevelOverride(const FLeashInfoOverride& LeashInfoOverride, EAlertLevel AlertLevel)
{
}

void AFortAthenaAIBotController::SetRadialLeashInnerRadius(const float InnerRadius)
{
}

void AFortAthenaAIBotController::SetRadialLeashLocation(const FVector& Location)
{
}

void AFortAthenaAIBotController::SetRadialLeashOuterRadius(const float OuterRadius)
{
}

void AFortAthenaAIBotController::SetSkillSet(TSubclassOf<UFortAthenaAIBotSkillSet> SkillSetClass)
{
}

void AFortAthenaAIBotController::StartFire()
{
}

void AFortAthenaAIBotController::StartSecondaryFire()
{
}

void AFortAthenaAIBotController::StopEmote()
{
}

void AFortAthenaAIBotController::StopFire()
{
}

void AFortAthenaAIBotController::StopSecondaryFire(const bool bFireWhenStopping)
{
}

void AFortAthenaAIBotController::SwitchTeam(uint8 TeamIndex)
{
}

void AFortAthenaAIBotController::ThankBusDriver()
{
}

void AFortAthenaAIBotController::UpdateLeashActorToFollowLocation()
{
}

void AFortAthenaAIBotController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaAIBotController, Inventory);
}
