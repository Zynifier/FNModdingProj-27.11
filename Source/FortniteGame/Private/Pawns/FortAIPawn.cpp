// Copyright Epic Games, Inc. All Rights Reserved.

#include "Pawns/FortAIPawn.h"
#include "Net/UnrealNetwork.h"

void AFortAIPawn::AddFortAbilitySet(UFortAbilitySet* FortAbilitySet)
{
}

void AFortAIPawn::AddUnreachablePickup(AFortPickup* Pickup)
{
}

bool AFortAIPawn::AreCustomizationsLoaded() const
{
	return false;
}

bool AFortAIPawn::BlueprintCanInteract_Implementation(const AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted) const
{
	return false;
}

EPhysicalSurface AFortAIPawn::BlueprintGetPrimaryPhysicalSurface_Implementation() const
{
	return EPhysicalSurface();
}

float AFortAIPawn::BlueprintModifyIncomingDamage_Implementation(float Damage, const FGameplayTagContainer& DamageTags, const FGameplayEffectContextHandle& EffectContext, AController* EventInstigator, AActor* DamageCauser)
{
	return float();
}

bool AFortAIPawn::CanHitTargetWithAbility(FGameplayTagContainer GameplayAbilityTag, AActor* CanHitTarget, bool bUseIdealYawRotationToTarget)
{
	return false;
}

void AFortAIPawn::ClearAIFocalPoint(bool bUseAttackingPriority)
{
}

void AFortAIPawn::DespawnAI(bool bDueToInactivity)
{
}

void AFortAIPawn::DropAllItems(bool bSpawnPickups)
{
}

void AFortAIPawn::FastSharedReplication_Implementation(const FFortAISharedRepMovement& SharedRepMovement)
{
}

const TArray<APawn*> AFortAIPawn::FindValidPawnsUsedOrUsingThisAsABase()
{
	return TArray<APawn*>();
}

void AFortAIPawn::FinishedEncounterSpawn()
{
}

void AFortAIPawn::ForceKillNoDBNO()
{
}

FVector AFortAIPawn::GetBackpackLocation_Implementation() const
{
	return FVector();
}

bool AFortAIPawn::GetBeingControlled() const
{
	return false;
}

EFortCustomGender::Type AFortAIPawn::GetCharacterGender() const
{
	return EFortCustomGender::Type();
}

AActor* AFortAIPawn::GetCurrentAimTarget() const
{
	return nullptr;
}

void AFortAIPawn::GetDeathInfo(FAIDeathInfo& OutDeathInfo) const
{
}

FString AFortAIPawn::GetDefenderItemInstanceId() const
{
	return FString();
}

float AFortAIPawn::GetDifficultyLevel() const
{
	return float();
}

float AFortAIPawn::GetDifficultyRating() const
{
	return float();
}

float AFortAIPawn::GetGroundSpeedForUrgency(AFortAIPawn* FortAIPawn, EFortMovementUrgency::Type Urgency)
{
	return float();
}

USoundBase* AFortAIPawn::GetImpactPhysicalSurfaceSound(const FHitResult& Impact) const
{
	return nullptr;
}

UFortItem* AFortAIPawn::GetInventoryItem(FGuid ItemGuid) const
{
	return nullptr;
}

float AFortAIPawn::GetLocomotionPlayRateScale() const
{
	return float();
}

float AFortAIPawn::GetMaxConvertResistance() const
{
	return float();
}

EFortMovementStyle::Type AFortAIPawn::GetMovementStyle(const AFortAIPawn* FortAIPawn)
{
	return EFortMovementStyle::Type();
}

EFortMovementUrgency::Type AFortAIPawn::GetMovementUrgency(AFortAIPawn* FortAIPawn)
{
	return EFortMovementUrgency::Type();
}

EScoreDistributionType AFortAIPawn::GetScoreDistribution() const
{
	return EScoreDistributionType();
}

int32 AFortAIPawn::GetScoreValue() const
{
	return int32();
}

int32 AFortAIPawn::GetScoreWithoutMutliplierValue() const
{
	return int32();
}

TArray<USkeletalMeshComponent*> AFortAIPawn::GetSkeletalMeshesForAllParts() const
{
	return TArray<USkeletalMeshComponent*>();
}

USkeletalMeshComponent* AFortAIPawn::GetSkeletalMeshForPartTag(FGameplayTag PartTag) const
{
	return nullptr;
}

USkeletalMeshComponent* AFortAIPawn::GetSkeletalMeshForPartType(EFortCustomPartType::Type PartType) const
{
	return nullptr;
}

const FGameplayTagQuery& AFortAIPawn::GetSleepForGoalActors() const
{
	static FGameplayTagQuery Dummy;
	return Dummy;
}

FVector AFortAIPawn::GetSpawnLocation() const
{
	return FVector();
}

int32 AFortAIPawn::GetSpawnPointValue() const
{
	return int32();
}

FRotator AFortAIPawn::GetSpawnRotation() const
{
	return FRotator();
}

bool AFortAIPawn::GetUsesDBNO() const
{
	return false;
}

void AFortAIPawn::GiveAmmo(const int32 AmmoQuantity)
{
}

void AFortAIPawn::GrabPickup(AFortPickup* Pickup)
{
}

void AFortAIPawn::GrabPickupCustomized(AFortPickup* Pickup, float FlyTime)
{
}

bool AFortAIPawn::HasTether() const
{
	return false;
}

void AFortAIPawn::HideMapMarker()
{
}

bool AFortAIPawn::IsDefender() const
{
	return false;
}

bool AFortAIPawn::IsInCombat() const
{
	return false;
}

bool AFortAIPawn::IsInsideTetherBounds(bool bUseRelaxedTetherBounds) const
{
	return false;
}

bool AFortAIPawn::IsUsedAsBaseByPawn() const
{
	return false;
}

UFortItem* AFortAIPawn::K2_FindExistingItemForDefinition(const UFortItemDefinition* ItemDefinition, FGuid ItemVariantGuid, bool bInStorageVault) const
{
	return nullptr;
}

UFortAccountItem* AFortAIPawn::K2_GetDefenderItem() const
{
	return nullptr;
}

void AFortAIPawn::NetMulticast_BatchedDamageCues_Implementation(FFortAIBatchedDamageCues Data)
{
}

void AFortAIPawn::NetMulticast_OnTurn_Implementation(float TurnAngle, float TurnRate)
{
}

void AFortAIPawn::OnEncounterSpawnEnableMeleeAttacking()
{
}

void AFortAIPawn::OnEncounterSpawnEnableRangedAttacking()
{
}

void AFortAIPawn::OnForceEnterVehicle_Implementation()
{
}

void AFortAIPawn::OnForceLeaveVehicle_Implementation()
{
}

FVector AFortAIPawn::OnLaunchCharacter_Implementation(FVector LaunchVelocity, bool bXYOverride, bool bZOverride)
{
	return FVector();
}

void AFortAIPawn::OnRep_AppearanceOverrideEntryIndex()
{
}

void AFortAIPawn::OnRep_AttributeProxy()
{
}

void AFortAIPawn::OnRep_BeingControlled()
{
}

void AFortAIPawn::OnRep_bIsSleeping()
{
}

void AFortAIPawn::OnRep_CanInteract(bool bOldCanInteract)
{
}

void AFortAIPawn::OnRep_CurrentAIRotationRate()
{
}

void AFortAIPawn::OnRep_CustomizationsToLoad()
{
}

void AFortAIPawn::OnRep_EnableBlockingCollisionWithOtherAI()
{
}

void AFortAIPawn::OnRep_Inventory()
{
}

void AFortAIPawn::OnRep_MinimapViewableDistance()
{
}

void AFortAIPawn::OnRep_ReplicatedAnimMontage()
{
}

void AFortAIPawn::OnRep_SharedAnim()
{
}

void AFortAIPawn::OnRep_TetheredFollower()
{
}

void AFortAIPawn::OnRep_UpgradeUIData()
{
}

void AFortAIPawn::OnSleepingAIsFloorBuildingActorDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void AFortAIPawn::OverrideInteractionText(const FText& NewInteractionText)
{
}

void AFortAIPawn::OverrideInteractionType(const TEnumAsByte<TInteractionType>& NewInteractionType)
{
}

void AFortAIPawn::PlayAdditiveHitReactsNative(const FVector& HitDirection, UAnimMontage* NewAnimMontage)
{
}

void AFortAIPawn::ResetAIRotationRateToDefault()
{
}

void AFortAIPawn::RestoreInteractionText()
{
}

void AFortAIPawn::RestoreInteractionType()
{
}

void AFortAIPawn::ReviveFromDBNO()
{
}

void AFortAIPawn::SetAIFocalPoint(AActor* FocusTarget, FVector FocalPoint, bool bUseAttackingPriority)
{
}

void AFortAIPawn::SetAIRotationRate(const FRotator& AIRotationRate)
{
}

void AFortAIPawn::SetAIType(EFortressAIType InAIType)
{
}

void AFortAIPawn::SetBlockCollisionWithOtherAI(bool bInEnableBlockingCollisionWithOtherAI)
{
}

void AFortAIPawn::SetCanBeBaseForOtherPawns(bool bEnable)
{
}

void AFortAIPawn::SetCanInteract(bool CanInteract)
{
}

void AFortAIPawn::SetCanSleep(bool InCanSleep)
{
}

void AFortAIPawn::SetCollisionProfileName(FName InCollisionProfileName)
{
}

void AFortAIPawn::SetCurrentAimTarget(AActor* AimTarget)
{
}

void AFortAIPawn::SetDefenderTrap(ABuildingTrapDefender* InDefenderTrap)
{
}

void AFortAIPawn::SetDesiredCustomization(UFortAIPawnCustomizationDefinition* InCustomizationsToLoad)
{
}

void AFortAIPawn::SetDisplayName(const FText& Name)
{
}

void AFortAIPawn::SetEncounterInfo(UFortAIEncounterInfo* InEncounterInfo)
{
}

void AFortAIPawn::SetEyeColor(FLinearColor NewEyeColor, float NewEyeBrightness)
{
}

void AFortAIPawn::SetForceBossSignificance(bool bEnabled)
{
}

void AFortAIPawn::SetIsCharging(bool bNewIsCharging)
{
}

void AFortAIPawn::SetLocomotionPlayRateScale(const float NewLocomotionPlayRateScale)
{
}

void AFortAIPawn::SetMinimapViewableDistance(float NewMinimapViewableDistance)
{
}

void AFortAIPawn::SetMinimumAILOD(EFortAILODLevel MinimumAILOD)
{
}

void AFortAIPawn::SetMinSignificanceForAnimationCurves(float MinSignificance)
{
}

void AFortAIPawn::SetMovementUrgency(EFortMovementUrgency::Type Urgency)
{
}

void AFortAIPawn::SetOverridenScore(int32 InOverriddenScore)
{
}

void AFortAIPawn::SetOverridenScoreDistribution(const EScoreDistributionType InOverriddenScoreDistribution)
{
}

void AFortAIPawn::SetReplicateGameplayCuesWithFastAbilityReplication(const bool bReplicateGameplayCues)
{
}

void AFortAIPawn::SetReplicateGrantedTagsWithFastAbilityReplication(const bool bReplicateGrantedTags)
{
}

void AFortAIPawn::SetShouldStartSleeping(bool bHintStartSleeping)
{
}

void AFortAIPawn::SetSkinColor(FLinearColor NewSkinColor, float NewSkinBrightness)
{
}

void AFortAIPawn::SetSleepForGoalActors(const FGameplayTagQuery& InQuery)
{
}

void AFortAIPawn::SetUsesDBNO(bool bInUsesDBNO, TInteractionType InDBNOInteractionType, float InDBNOInteractionDuration)
{
}

void AFortAIPawn::SetWeaponCollisionComponent(UShapeComponent* InWeaponCollisionComponent)
{
}

bool AFortAIPawn::ShouldApplyBuildingHitEffect(float Damage, FVector Location, FHitResult HitInfo, bool bPlayerPlaced) const
{
	return false;
}

bool AFortAIPawn::ShouldReplicateGameplayCuesWithFastAbilityReplication() const
{
	return false;
}

bool AFortAIPawn::ShouldReplicateGrantedTagsWithFastAbilityReplication() const
{
	return false;
}

bool AFortAIPawn::ShouldUpdateSkeletalMesh_Implementation()
{
	return false;
}

bool AFortAIPawn::ShouldUseFiringCapsuleCollision_Implementation()
{
	return false;
}

void AFortAIPawn::ShowMapMarker()
{
}

void AFortAIPawn::SpawnPickupInWorldWithLootTierAsync(FName LootTierName, FVector Position, int32 OverrideMaxStackCount, bool bToss, EFortPickupSourceTypeFlag SourceType, EFortPickupSpawnSource Source)
{
}

void AFortAIPawn::TriggerNoWeaponSpeech()
{
}

void AFortAIPawn::TurnOnSleepingOptimizations()
{
}

bool AFortAIPawn::WasDespawned() const
{
	return false;
}

void AFortAIPawn::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAIPawn, AttributeReplicationProxy);
	DOREPLIFETIME(AFortAIPawn, RepAnimMontageInfo);
	DOREPLIFETIME(AFortAIPawn, RepSharedAnimInfo);
	DOREPLIFETIME(AFortAIPawn, SimulatedProxyGameplayCues);
	DOREPLIFETIME(AFortAIPawn, bHasGoalActor);
	DOREPLIFETIME(AFortAIPawn, bFrozen);
	DOREPLIFETIME(AFortAIPawn, bIsCharging);
	DOREPLIFETIME(AFortAIPawn, bIsCowering);
	DOREPLIFETIME(AFortAIPawn, bEnableBlockingCollisionWithOtherAI);
	DOREPLIFETIME(AFortAIPawn, FastReplicationMinimalReplicationTags);
	DOREPLIFETIME(AFortAIPawn, FastReplicationMinimalGameplayCueProxy);
	DOREPLIFETIME(AFortAIPawn, AIDifficultyLevel);
	DOREPLIFETIME(AFortAIPawn, SpawnRift);
	DOREPLIFETIME(AFortAIPawn, DBNOInteractionDuration);
	DOREPLIFETIME(AFortAIPawn, DBNOInteractionType);
	DOREPLIFETIME(AFortAIPawn, LocomotionPlayRateScale);
	DOREPLIFETIME(AFortAIPawn, MinimapGoalByTagColorIndex);
	DOREPLIFETIME(AFortAIPawn, bIsSleeping);
	DOREPLIFETIME(AFortAIPawn, bShouldStartSleeping);
	DOREPLIFETIME(AFortAIPawn, bCanLookAtGoal);
	DOREPLIFETIME(AFortAIPawn, bCanBeBaseForOtherPawns);
	DOREPLIFETIME(AFortAIPawn, bCanInteract);
	DOREPLIFETIME(AFortAIPawn, BeingControlledBy);
	DOREPLIFETIME(AFortAIPawn, MovementUrgency);
	DOREPLIFETIME(AFortAIPawn, AIType);
	DOREPLIFETIME(AFortAIPawn, Team);
	DOREPLIFETIME(AFortAIPawn, UpgradeUIData);
	DOREPLIFETIME(AFortAIPawn, PlayerManager);
	DOREPLIFETIME(AFortAIPawn, DefenderItemInstanceId);
	DOREPLIFETIME(AFortAIPawn, DefenderSquadId);
	DOREPLIFETIME(AFortAIPawn, DefenderPlacedTime);
	DOREPLIFETIME(AFortAIPawn, CurrentAIRotationRate);
	DOREPLIFETIME(AFortAIPawn, Inventory);
	DOREPLIFETIME(AFortAIPawn, AppearanceOverrideEntryIndex);
	DOREPLIFETIME(AFortAIPawn, MinimapViewableDistance);
	DOREPLIFETIME(AFortAIPawn, SpawnModifierDefinitions);
	DOREPLIFETIME(AFortAIPawn, CurrentAimTarget);
	DOREPLIFETIME(AFortAIPawn, CurrentAimLocation);
	DOREPLIFETIME(AFortAIPawn, TetheredFollower);
	DOREPLIFETIME(AFortAIPawn, bIsTetheredBoosting);
	DOREPLIFETIME(AFortAIPawn, CustomizationsToLoad);
	DOREPLIFETIME(AFortAIPawn, bCanUnloadCustomization);
}
