// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingSMActor.h"
#include "Net/UnrealNetwork.h"

void ABuildingSMActor::AddToGrid(const bool bFromDynamicBuilder)
{
}

void ABuildingSMActor::AttachBuildingActorToMe(ABuildingActor* ActorToAttach, bool bForceAttachment)
{
}

bool ABuildingSMActor::BlueprintCanAttemptGenerateResources_Implementation(const FGameplayTagContainer& InTags, AController* InstigatorController) const
{
	return false;
}

void ABuildingSMActor::BlueprintOnStructurallyStable_Implementation()
{
}

void ABuildingSMActor::BlueprintOnStructurallyUnstable_Implementation()
{
}

bool ABuildingSMActor::CanBeDamaged(const AController* DamageInstigator, const AActor* DamageCauser) const
{
	return false;
}

void ABuildingSMActor::CancelAutoBuild()
{
}

void ABuildingSMActor::CancelRepair()
{
}

bool ABuildingSMActor::CanDoBuildingAnimations() const
{
	return false;
}

void ABuildingSMActor::ClearRequestedBuildingAnimation()
{
}

void ABuildingSMActor::ClearResourcesEarnedOverrideDelegate()
{
}

void ABuildingSMActor::CollectBuildingTextureDataAssetReferences(FFortExposedAssetReferenceCollector& Collector) const
{
}

void ABuildingSMActor::DetachBuildingActorFromMe(ABuildingActor* ActorToAttach, bool bBeingDestroyed, AController* Killer)
{
}

void ABuildingSMActor::EditorOnlyRemoveInstanceMaterialRTVParameter(FName ParamName)
{
}

void ABuildingSMActor::EditorOnlyRemoveInstanceMaterialScalarParameter(FName ParamName)
{
}

void ABuildingSMActor::EditorOnlyRemoveInstanceMaterialTextureParameter(FName ParamName)
{
}

void ABuildingSMActor::EditorOnlyRemoveInstanceMaterialVectorParameter(FName ParamName)
{
}

void ABuildingSMActor::EditorOnlySetInstanceMaterialRTVParameter(FName ParamName, URuntimeVirtualTexture* Value)
{
}

void ABuildingSMActor::EditorOnlySetInstanceMaterialScalarParameter(FName ParamName, float Value)
{
}

void ABuildingSMActor::EditorOnlySetInstanceMaterialTextureParameter(FName ParamName, UTexture* Value)
{
}

void ABuildingSMActor::EditorOnlySetInstanceMaterialVectorParameter(FName ParamName, FLinearColor Value)
{
}

int32 ABuildingSMActor::FindDestructionLootTier() const
{
	return int32();
}

void ABuildingSMActor::ForceIntoStructuralGridDuringRuntime_Implementation()
{
}

void ABuildingSMActor::ForceVisualState(EBuildingAnim VisualState)
{
}

void ABuildingSMActor::GameplayCue_Abilities_Activation_Generic_BannerWallBuff1(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters)
{
}

void ABuildingSMActor::GameplayCue_Abilities_Activation_Generic_BannerWallBuff2(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters)
{
}

TArray<ABuildingActor*> ABuildingSMActor::GetAttachedBuildingActors() const
{
	return TArray<ABuildingActor*>();
}

TArray<ABuildingSMActor*> ABuildingSMActor::GetAttachedBuildingSMActors() const
{
	return TArray<ABuildingSMActor*>();
}

UStaticMeshComponent* ABuildingSMActor::GetBuildingMeshComponent() const
{
	return nullptr;
}

void ABuildingSMActor::GetBuildingTextureData(TArray<UBuildingTextureData*>& OutTextureDataArray) const
{
}

UFXSystemAsset* ABuildingSMActor::GetDeathParticles() const
{
	return nullptr;
}

const FName& ABuildingSMActor::GetDestructionLootTierGroup() const
{
	static FName Dummy;
	return Dummy;
}

UNaniteDisplacedMesh* ABuildingSMActor::GetDisplacedMesh()
{
	return nullptr;
}

FBuildingDuplicationData ABuildingSMActor::GetDuplicationData()
{
	return FBuildingDuplicationData();
}

bool ABuildingSMActor::GetIntenseWindMaterialsForPreview(TArray<UMaterialInterface*>& Materials)
{
	return false;
}

FGameplayTagQuery ABuildingSMActor::GetInvalidTrapTagQuery_Implementation() const
{
	return FGameplayTagQuery();
}

int32 ABuildingSMActor::GetLogicalBuildingIndex() const
{
	return int32();
}

const int32 ABuildingSMActor::GetMaximumLegalReplicatedHealthValue()
{
	return int32();
}

UMaterialInstanceDynamic* ABuildingSMActor::GetOrCreateMIDOnDefaultMesh(int32 ElementIndex)
{
	return nullptr;
}

ABuildingSMActor* ABuildingSMActor::GetParentActorToAttachTo() const
{
	return nullptr;
}

EBuildingReplacementType ABuildingSMActor::GetReplacementDestructionReason()
{
	return EBuildingReplacementType();
}

float ABuildingSMActor::GetWeakSpotEnabledTimeout_Implementation(AFortPlayerController* Controller) const
{
	return float();
}

UCurveLinearColor* ABuildingSMActor::GetWindPannerSpeedCurveForPreview() const
{
	return nullptr;
}

UCurveLinearColor* ABuildingSMActor::GetWindSpeedCurveForPreview() const
{
	return nullptr;
}

bool ABuildingSMActor::HasDestructionLoot() const
{
	return false;
}

bool ABuildingSMActor::IsStructurallySupported() const
{
	return false;
}

bool ABuildingSMActor::IsSupportedByWorld() const
{
	return false;
}

bool ABuildingSMActor::IsUnderConstruction() const
{
	return false;
}

void ABuildingSMActor::MarkConnectedBuildingsForStructuralIntegrityCheck()
{
}

float ABuildingSMActor::ModifyIncomingDamageForBuildingActorAttachedToMe_Implementation(const ABuildingSMActor* AttachedBuildingSMActor, float Damage, const FGameplayTagContainer& InTags, const FGameplayEffectContextHandle& EffectContext, AController* EventInstigator, AActor* DamageCauser) const
{
	return float();
}

void ABuildingSMActor::MulticastPlayFullHealthEffects_Implementation()
{
}

void ABuildingSMActor::NetMulticast_InvokeGameplayCueAdded_Implementation(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayEffectContextHandle EffectContext)
{
}

void ABuildingSMActor::NetMulticast_InvokeGameplayCueAdded_WithParams_Implementation(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayCueParameters Parameters)
{
}

void ABuildingSMActor::NetMulticast_InvokeGameplayCueAddedAndWhileActive_FromSpec_Implementation(const FGameplayEffectSpecForRPC& Spec, FPredictionKey PredictionKey)
{
}

void ABuildingSMActor::NetMulticast_InvokeGameplayCueAddedAndWhileActive_WithParams_Implementation(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayCueParameters GameplayCueParameters)
{
}

void ABuildingSMActor::NetMulticast_InvokeGameplayCueExecuted_Implementation(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayEffectContextHandle EffectContext)
{
}

void ABuildingSMActor::NetMulticast_InvokeGameplayCueExecuted_FromSpec_Implementation(const FGameplayEffectSpecForRPC Spec, FPredictionKey PredictionKey)
{
}

void ABuildingSMActor::NetMulticast_InvokeGameplayCueExecuted_WithParams_Implementation(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayCueParameters GameplayCueParameters)
{
}

void ABuildingSMActor::NetMulticast_InvokeGameplayCuesAddedAndWhileActive_WithParams_Implementation(const FGameplayTagContainer GameplayCueTags, FPredictionKey PredictionKey, FGameplayCueParameters GameplayCueParameters)
{
}

void ABuildingSMActor::NetMulticast_InvokeGameplayCuesExecuted_Implementation(const FGameplayTagContainer GameplayCueTags, FPredictionKey PredictionKey, FGameplayEffectContextHandle EffectContext)
{
}

void ABuildingSMActor::NetMulticast_InvokeGameplayCuesExecuted_WithParams_Implementation(const FGameplayTagContainer GameplayCueTags, FPredictionKey PredictionKey, FGameplayCueParameters GameplayCueParameters)
{
}

void ABuildingSMActor::OnDynamicShrinkAndDestroyEffectFinished()
{
}

void ABuildingSMActor::OnLODOverrideEffectFinished()
{
}

void ABuildingSMActor::OnPhysicsStateChanged(UPrimitiveComponent* PrimitiveComponent, EComponentPhysicsStateChange StateChange)
{
}

void ABuildingSMActor::OnRep_BuildingAnimation()
{
}

void ABuildingSMActor::OnRep_bUnderConstruction()
{
}

void ABuildingSMActor::OnRep_bUnderRepair()
{
}

void ABuildingSMActor::OnRep_EditingPlayer()
{
}

void ABuildingSMActor::OnRep_HiddenDueToTrapPlacement()
{
}

void ABuildingSMActor::OnRep_MetaData()
{
}

void ABuildingSMActor::OnRep_Mirrored()
{
}

void ABuildingSMActor::OnRep_NoCameraCollision()
{
}

void ABuildingSMActor::OnRep_NoCollision()
{
}

void ABuildingSMActor::OnRep_ProxyGameplayCueDamage()
{
}

void ABuildingSMActor::OnRep_RelevantBASE()
{
}

void ABuildingSMActor::OnRep_ReplicatedDrawScale3D()
{
}

void ABuildingSMActor::OnRep_ReplicationProxy()
{
}

void ABuildingSMActor::OnRep_ResourceType(EFortResourceType::Type OldType)
{
}

void ABuildingSMActor::PlayBreakEffects()
{
}

void ABuildingSMActor::PlayConstructionBounce()
{
}

void ABuildingSMActor::PlayDestructionEffects()
{
}

void ABuildingSMActor::PlayFullHealthEffects()
{
}

void ABuildingSMActor::PostForceMove()
{
}

void ABuildingSMActor::PreForceMove(AController* EventInstigator)
{
}

TArray<UTexture2D*> ABuildingSMActor::ReadTextureData()
{
	return TArray<UTexture2D*>();
}

void ABuildingSMActor::RepairBuilding(AFortPlayerController* RepairingController, int32 ResourcesSpent)
{
}

void ABuildingSMActor::SetBuildingTextureData(const int32 Index, UBuildingTextureData* NewBuildingTextureData)
{
}

void ABuildingSMActor::SetDeathParticles(UParticleSystem* InPS)
{
}

bool ABuildingSMActor::SetDisplacedMesh(UNaniteDisplacedMesh* NaniteDisplacedMesh)
{
	return false;
}

void ABuildingSMActor::SetMirrored(bool bIsMirrored)
{
}

void ABuildingSMActor::SetNoCameraCollision(bool bValue)
{
}

void ABuildingSMActor::SetNoPhysicsCollision(bool bValue)
{
}

void ABuildingSMActor::SetParentActorToAttachTo(ABuildingSMActor* InParentActorToAttachTo)
{
}

void ABuildingSMActor::SetResourcesEarnedOverrideDelegate(FOnResourcesEarnedOverrideSignature InOnResourcesEarnedOverrideDelegate)
{
}

void ABuildingSMActor::SetResourceType(EFortResourceType::Type NewResourceType)
{
}

void ABuildingSMActor::SetTextureData(const TArray<UTexture2D*>& InTextures)
{
}

bool ABuildingSMActor::ShouldUsePhysicalMaterialForFootstep_Implementation() const
{
	return false;
}

void ABuildingSMActor::StartBounceAnimation(const float StartTime, const float Radius, const FVector& Normal, const FVector& Center, EFortBounceType::Type InBounceType, const bool bLocalInstigator)
{
}

void ABuildingSMActor::StartFullHealthAnimation()
{
}

void ABuildingSMActor::TransferBuildingData(ABuildingSMActor* SourceDataActor)
{
}

void ABuildingSMActor::TransferFromDuplicationData(FBuildingDuplicationData SourceData)
{
}

void ABuildingSMActor::UpdateComponentCollisionModes()
{
}

void ABuildingSMActor::UpdateDynamicShrinkAndDestroyEffect(float CurveValue)
{
}

void ABuildingSMActor::UpdateLODOverrideEffect(float CurveValue)
{
}

void ABuildingSMActor::UpdateRepairMaterialAnim(float CurveValue)
{
}

bool ABuildingSMActor::WillRegisterWithStructuralGrid() const
{
	return false;
}

void ABuildingSMActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingSMActor, TextureData);
	DOREPLIFETIME(ABuildingSMActor, StaticMesh);
	DOREPLIFETIME(ABuildingSMActor, bNoPhysicsCollision);
	DOREPLIFETIME(ABuildingSMActor, bNoCameraCollision);
	DOREPLIFETIME(ABuildingSMActor, ResourceType);
	DOREPLIFETIME(ABuildingSMActor, AltMeshIdx);
	DOREPLIFETIME(ABuildingSMActor, bMirrored);
	DOREPLIFETIME(ABuildingSMActor, bNoCollision);
	DOREPLIFETIME(ABuildingSMActor, bSupportsRepairing);
	DOREPLIFETIME(ABuildingSMActor, bHiddenDueToTrapPlacement);
	DOREPLIFETIME(ABuildingSMActor, bAttachmentPlacementBlockedFront);
	DOREPLIFETIME(ABuildingSMActor, bAttachmentPlacementBlockedBack);
	DOREPLIFETIME(ABuildingSMActor, bUnderConstruction);
	DOREPLIFETIME(ABuildingSMActor, bUnderRepair);
	DOREPLIFETIME(ABuildingSMActor, bIsInitiallyBuilding);
	DOREPLIFETIME(ABuildingSMActor, BuildingAnimation);
	DOREPLIFETIME(ABuildingSMActor, ReplicatedDrawScale3D);
	DOREPLIFETIME(ABuildingSMActor, MinimalReplicationProxy);
	DOREPLIFETIME(ABuildingSMActor, BuildingReplacementType);
	DOREPLIFETIME(ABuildingSMActor, EditingPlayer);
	DOREPLIFETIME(ABuildingSMActor, BuildingAttachmentSlot);
	DOREPLIFETIME(ABuildingSMActor, DamagerOwner);
	DOREPLIFETIME(ABuildingSMActor, RelevantBASE);
	DOREPLIFETIME(ABuildingSMActor, ProxyGameplayCueDamage);
}

void ABuildingSMActor::ForceReplication()
{
}
