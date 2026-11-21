// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingActor.h"
#include "Net/UnrealNetwork.h"

void ABuildingActor::AddEditorOnlyInstanceGameplayTags(const FGameplayTagContainer& NewTags)
{
}

void ABuildingActor::AddUniqueTransientOverride(FName InObjectName, FName InPropertyName, bool bInMarkTransient)
{
}

ABuildingActor* ABuildingActor::BeginDeferredBuildingActorSpawnFromClass(const UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, const FTransform& SpawnTransform, AActor* OptionalOwner, bool bTransient)
{
	return nullptr;
}

void ABuildingActor::BlueprintDie(FGameplayTag DeathReason, AController* Killer, AActor* DamageCauser)
{
}

bool ABuildingActor::BlueprintGetAllHighlightableComponents_Implementation(TArray<UPrimitiveComponent*>& OutHighlightableComponents) const
{
	return false;
}

bool ABuildingActor::BlueprintGetInteractionTime_Implementation(const AFortPawn* InteractingPawn, float& OutInteractionTime, const EInteractionBeingAttempted InteractionBeingAttempted) const
{
	return false;
}

void ABuildingActor::BP_SetTemporarilyTicking(const bool bEnabled)
{
}

bool ABuildingActor::CanClientSimulate() const
{
	return false;
}

bool ABuildingActor::CanDestroyBuildingActor(ABuildingActor* BuildingActor, AController* DamageInstigator, AActor* DamageCauser)
{
	return false;
}

void ABuildingActor::ClearPlayedDying()
{
}

bool ABuildingActor::DoesMutatorBlockIncomingDamage() const
{
	return false;
}

void ABuildingActor::ForceBuildingHealth(float NewHealth)
{
}

void ABuildingActor::ForceChangeOwnerInstigator(AFortPlayerController* NewInstigator)
{
}

void ABuildingActor::GameplayCue_Damage(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters)
{
}

void ABuildingActor::GameplayCue_Healing(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters)
{
}

void ABuildingActor::GameplayCue_InstantDeath(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters)
{
}

UFortBuildingActorSet* ABuildingActor::GetBuildingAttributeSet() const
{
	return nullptr;
}

UFortBuildingActorSet* ABuildingActor::GetBuildingAttributeSet_DontCreate() const
{
	return nullptr;
}

FVector ABuildingActor::GetCentroid() const
{
	return FVector();
}

UPrimitiveComponent* ABuildingActor::GetCurieCollisionComponentOverride_Implementation() const
{
	return nullptr;
}

int32 ABuildingActor::GetCurrentBuildingLevel() const
{
	return int32();
}

FString ABuildingActor::GetCustomState() const
{
	return FString();
}

FText ABuildingActor::GetDescription() const
{
	return FText();
}

void ABuildingActor::GetEditorTestTags(FGameplayTagContainer& TagContainer) const
{
}

const FGameplayTagContainer& ABuildingActor::GetGameplayTags() const
{
	static FGameplayTagContainer Dummy;
	return Dummy;
}

float ABuildingActor::GetHealth() const
{
	return float();
}

float ABuildingActor::GetHealthPercent() const
{
	return float();
}

FName ABuildingActor::GetLootTierGroupOverride()
{
	return FName();
}

float ABuildingActor::GetMaxHealth() const
{
	return float();
}

float ABuildingActor::GetMaxShield() const
{
	return float();
}

float ABuildingActor::GetMissingHealth() const
{
	return float();
}

UClass* ABuildingActor::GetNavigationLinksClass() const
{
	return nullptr;
}

FGameplayTag ABuildingActor::GetOverrideItemInteractAbilityTag_Implementation() const
{
	return FGameplayTag();
}

AController* ABuildingActor::GetOwningController() const
{
	return nullptr;
}

AFortPlayerState* ABuildingActor::GetOwningPlayerState() const
{
	return nullptr;
}

UFortPhysicsObjectComponent* ABuildingActor::GetPhysicsObjectComponent(ABuildingActor* Building)
{
	return nullptr;
}

float ABuildingActor::GetShield() const
{
	return float();
}

float ABuildingActor::GetShieldOrHealthPercent()
{
	return float();
}

float ABuildingActor::GetShieldPercent() const
{
	return float();
}

void ABuildingActor::HandleDestroyed()
{
}

bool ABuildingActor::HasHealthLeft() const
{
	return false;
}

void ABuildingActor::InitializeKismetSpawnedBuildingActor(ABuildingActor* BuildingOwner, AFortPlayerController* SpawningController, bool bUsePlayerBuildAnimations, ABuildingActor* ReplacedBuilding)
{
}

bool ABuildingActor::IsAcceptablePositionForPlacement_Implementation(const FVector& InLocation, const FRotator& InRotation, AFortDecoTool* DecoTool, bool bIsCDO, FText& OutFailureReason) const
{
	return false;
}

bool ABuildingActor::IsDamaged() const
{
	return false;
}

bool ABuildingActor::IsLockedFromGameEditing() const
{
	return false;
}

bool ABuildingActor::IsPlayerBuilt() const
{
	return false;
}

bool ABuildingActor::IsPreviewBuildingActor() const
{
	return false;
}

ABuildingActor* ABuildingActor::K2_SpawnBuildingActor(const UObject* WorldContextObject, TSubclassOf<ABuildingActor> Class, const FTransform& Transform, AActor* OptionalOwner, AActor* OptionalInstigator, const bool bDeferConstruction, const bool bTransient)
{
	return nullptr;
}

void ABuildingActor::MigrateLegacyUserOptions_Implementation()
{
}

bool ABuildingActor::ObstructsTrapTargetingGivenTags_Implementation(const FGameplayTagContainer& TrapDefTags) const
{
	return false;
}

void ABuildingActor::OnBuildingActorInitialized_Implementation(EFortBuildingInitializationReason::Type InitializationReason, EFortBuildingPersistentState::Type BuildingPersistentState)
{
}

void ABuildingActor::OnDayPhaseChanged_Implementation(EFortDayPhase CurrentDayPhase, EFortDayPhase PreviousDayPhase, bool bAtCreation)
{
}

void ABuildingActor::OnRep_AbilitySystemComponent()
{
}

void ABuildingActor::OnRep_bCollisionBlockedByPawns()
{
}

void ABuildingActor::OnRep_bDestroyed()
{
}

void ABuildingActor::OnRep_BuildingAttributeSet()
{
}

void ABuildingActor::OnRep_CurrentBuildingLevel()
{
}

void ABuildingActor::OnRep_CustomState()
{
}

void ABuildingActor::OnRep_InitialOverlappingVehicles()
{
}

void ABuildingActor::OnRep_InstantDeath()
{
}

void ABuildingActor::OnRep_Team()
{
}

void ABuildingActor::PlacedByPlacementTool_Implementation()
{
}

void ABuildingActor::RefreshRemovedFoliageAroundBounds(bool bUseNonCollidingBounds)
{
}

void ABuildingActor::RemoveAbilitySystemComponentAfterAutoBuildIfFullHealth()
{
}

void ABuildingActor::RemoveEditorOnlyInstanceGameplayTags(const FGameplayTagContainer& TagsToRemove)
{
}

void ABuildingActor::ReplaceNavAreaClass(const TSubclassOf<UNavArea>& ReplacementAreaClass)
{
}

void ABuildingActor::Resave()
{
}

void ABuildingActor::SetAlwaysExportNavRelevantComponent(const bool bInAlwaysExportNavRelevantComponent)
{
}

void ABuildingActor::SetBRDrawDistances(float NewBRMinDrawDistance, float NewBRMaxDrawDistance)
{
}

void ABuildingActor::SetCanBeSavedToCreativeVolume(bool bCanBeSaved)
{
}

void ABuildingActor::SetCanExportNavigationObstacle(bool InCanExportNavigationObstacle)
{
}

void ABuildingActor::SetCustomState(const FString& NewState)
{
}

void ABuildingActor::SetHealth(float NewHealth)
{
}

void ABuildingActor::SetHealth_DontCreateASC(float NewHealth)
{
}

void ABuildingActor::SetHealthBarIndicatorDifficultyRating(int32 InDisplayLevel)
{
}

void ABuildingActor::SetIsNavigationRelevant(const bool bInIsNavigationRelevant)
{
}

bool ABuildingActor::SetMaxHealth_DontCreateASC(float NewMaxHealth)
{
	return false;
}

void ABuildingActor::SetNavigationIndestructible(const bool bNavIndestructible)
{
}

void ABuildingActor::SetNavigationModifier(bool bEnableModifier)
{
}

void ABuildingActor::SetNavigationObstacleOverride(const ENavigationObstacleOverride NavOverride)
{
}

void ABuildingActor::SetQuestHighlight(bool Enabled)
{
}

void ABuildingActor::SetSuppressHealthBar(bool bNewValue)
{
}

void ABuildingActor::SetTeam(uint8 InTeam)
{
}

void ABuildingActor::SetUsesDayPhaseChange(bool bUseDayPhase)
{
}

bool ABuildingActor::ShouldDie_Implementation(float Damage, AController* EventInstigator, AActor* DamageCauser)
{
	return false;
}

bool ABuildingActor::ShouldDisplayDamageNumbers_Implementation() const
{
	return false;
}

bool ABuildingActor::ShouldDisplayFirstInteractPrompt_Implementation(const AFortPawn* InteractingPawn, const TInteractionType InteractionType) const
{
	return false;
}

bool ABuildingActor::ShouldDisplayMobileInteractPrompt() const
{
	return false;
}

bool ABuildingActor::ShouldDisplaySecondInteractPrompt_Implementation(const AFortPawn* InteractingPawn, const TInteractionType InteractionType) const
{
	return false;
}

void ABuildingActor::SilentDie(const bool bPropagateSilentDeath)
{
}

void ABuildingActor::SnapDmgVisualsToCurrentHealth()
{
}

void ABuildingActor::UpdateCullDistance(const bool bIgnoreLODParent)
{
}

void ABuildingActor::UpdatePropertyForLiveEdit(const FString& PropertyName)
{
}

bool ABuildingActor::UseDefaultHealthBar_Implementation() const
{
	return false;
}

void ABuildingActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingActor, OwnerPersistentID);
	DOREPLIFETIME(ABuildingActor, InitialOverlappingVehicles);
	DOREPLIFETIME(ABuildingActor, CurrentBuildingLevel);
	DOREPLIFETIME(ABuildingActor, ReplicatedBuildingAttributeSet);
	DOREPLIFETIME(ABuildingActor, ReplicatedAbilitySystemComponent);
	DOREPLIFETIME(ABuildingActor, HealthBarIndicatorDifficultyRating);
	DOREPLIFETIME(ABuildingActor, ForceMetadataRelevant);
	DOREPLIFETIME(ABuildingActor, bIsInvulnerable);
	DOREPLIFETIME(ABuildingActor, bPreviewBuildingActor);
	DOREPLIFETIME(ABuildingActor, bLockedFromGameEditing);
	DOREPLIFETIME(ABuildingActor, bDestroyed);
	DOREPLIFETIME(ABuildingActor, bPlayerPlaced);
	DOREPLIFETIME(ABuildingActor, bInstantDeath);
	DOREPLIFETIME(ABuildingActor, bDoNotBlockBuildings);
	DOREPLIFETIME(ABuildingActor, bForceBlockBuildings);
	DOREPLIFETIME(ABuildingActor, bDestroyOnPlayerBuildingPlacement);
	DOREPLIFETIME(ABuildingActor, bUseCentroidForBlockBuildingsCheck);
	DOREPLIFETIME(ABuildingActor, bCollisionBlockedByPawns);
	DOREPLIFETIME(ABuildingActor, TeamIndex);
	DOREPLIFETIME(ABuildingActor, DeviceTrackingGUID);
	DOREPLIFETIME(ABuildingActor, DeviceNameIndex);
	DOREPLIFETIME(ABuildingActor, AssociatedMissionParam);
	DOREPLIFETIME(ABuildingActor, OriginatingPlacementActor);
	DOREPLIFETIME(ABuildingActor, CustomState);
	DOREPLIFETIME(ABuildingActor, BaselineScale);
}

void ABuildingActor::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
}

UAbilitySystemComponent* ABuildingActor::GetAbilitySystemComponent() const
{
	return nullptr;
}
