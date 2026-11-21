// Copyright Epic Games, Inc. All Rights Reserved.

#include "Pawns/FortPlayerPawn.h"
#include "Net/UnrealNetwork.h"

void AFortPlayerPawn::AddAbilityAITarget(AFortAIPawn* InTarget)
{
}

void AFortPlayerPawn::AddAttachment(USkeletalMesh* Attachment, TSubclassOf<UAnimInstance> InAnimBP)
{
}

void AFortPlayerPawn::AddIgnoredActor(AActor* InActorToIgnore, const float InIgnoreDuration)
{
}

void AFortPlayerPawn::AddStasisMode(const EFortPawnStasisMode InStasisMode, AActor* BoundStasisInstigator, const FGameplayTag& InStasisGameplayTag, const FGameplayTagContainer& AllowedActionTags)
{
}

void AFortPlayerPawn::AITargetDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void AFortPlayerPawn::AllowPickupInteractionWhileSkydiving(const bool bAllow)
{
}

void AFortPlayerPawn::ApplyCosmeticLoadout()
{
}

FGuid AFortPlayerPawn::ApplyMaterialOverride(const TSoftObjectPtr<UMaterialInterface>& Material, const FFortPawnMaterialOverrideCopiedParameters& MaterialParamsToCopy, float Priority, bool bHideParticleSystems, bool bApplyToWeapon)
{
	return FGuid();
}

FGuid AFortPlayerPawn::ApplyMaterialOverrideLocal(const TSoftObjectPtr<UMaterialInterface>& Material, const FFortPawnMaterialOverrideCopiedParameters& MaterialParamsToCopy, float Priority, bool bHideParticleSystems, bool bApplyToWeapon)
{
	return FGuid();
}

void AFortPlayerPawn::ApplyWrapToSaveTheWorldHoverboard()
{
}

bool AFortPlayerPawn::AreFXHidden() const
{
	return false;
}

bool AFortPlayerPawn::AreFXHiddenForPartComponent(const USkeletalMeshComponent* PartMeshComponent) const
{
	return false;
}

void AFortPlayerPawn::AttemptInstantInteractSearch()
{
}

void AFortPlayerPawn::AuthUpdateLockedFloatSliderVariant_Implementation(const UAthenaCosmeticItemDefinition* ItemVariantIsUsedFor, const FGameplayTag& ChannelTag)
{
}

void AFortPlayerPawn::BeginHovering()
{
}

void AFortPlayerPawn::BeginSkydiving(bool bFromBus)
{
}

void AFortPlayerPawn::BeginZiplining(AFortAthenaZipline* Zipline, USceneComponent* SocketComponent, UPrimitiveComponent* InteractComponent)
{
}

void AFortPlayerPawn::BlindTestPredictiveInput()
{
}

FGuid AFortPlayerPawn::BP_ApplyMaterialOverrideLocalWithFlags(const TSoftObjectPtr<UMaterialInterface>& Material, const FFortPawnMaterialOverrideCopiedParameters& MaterialParamsToCopy, float Priority, int32 Flags)
{
	return FGuid();
}

FGuid AFortPlayerPawn::BP_ApplyMaterialOverrideWithFlags(const TSoftObjectPtr<UMaterialInterface>& Material, const FFortPawnMaterialOverrideCopiedParameters& MaterialParamsToCopy, float Priority, int32 Flags)
{
	return FGuid();
}

void AFortPlayerPawn::BP_CloseParachuteAndFall()
{
}

void AFortPlayerPawn::BP_ForceLockParachuteOpen(bool bLocked)
{
}

void AFortPlayerPawn::BP_ForceOpenParachute()
{
}

AFortAthenaVehicle* AFortPlayerPawn::BP_GetVehicle() const
{
	return nullptr;
}

void AFortPlayerPawn::BP_OpenParachute()
{
}

void AFortPlayerPawn::BroadcastClearWeaponOverrideAnimSet_Implementation()
{
}

void AFortPlayerPawn::BroadcastSetWeaponOverrideAnimSet_Implementation(UFortWeaponAnimSet* WeaponOverrideAnimSet)
{
}

bool AFortPlayerPawn::BufferCrouchCommand()
{
	return false;
}

void AFortPlayerPawn::CancelJumpAbility()
{
}

bool AFortPlayerPawn::CanInterrogateFromDBNO(AController* EventInstigator)
{
	return false;
}

bool AFortPlayerPawn::CanPredictJumpApex()
{
	return false;
}

bool AFortPlayerPawn::CanShootFromVehicle() const
{
	return false;
}

bool AFortPlayerPawn::CanUseInventoryAsDriver() const
{
	return false;
}

void AFortPlayerPawn::CheckForUnburrowTeleport()
{
}

void AFortPlayerPawn::ClearExistingCosmeticPetInstance()
{
}

void AFortPlayerPawn::ClearScalarMaterialParameterOverrideLocal(FName ParamName)
{
}

void AFortPlayerPawn::ClearWeaponOverrideAnimSet()
{
}

void AFortPlayerPawn::ClientAcknowledgeVehicleInputState_Implementation(float Timestamp)
{
}

void AFortPlayerPawn::ClientExecuteGameplayCueOnSpecificPlayer_Implementation(const FGameplayTag GameplayCueTag)
{
}

void AFortPlayerPawn::ClientForceZiplineState_Implementation(const FZiplinePawnState& InZiplineState)
{
}

void AFortPlayerPawn::ClientNotifyAbilityFailed_Implementation(const UGameplayAbility* FailedAbility, const FGameplayTagContainer& FailedReason)
{
}

void AFortPlayerPawn::ClientNotifyUnableToPerformAction_Implementation(bool bPlayMontage, const FGameplayTagContainer& FailedReason)
{
}

void AFortPlayerPawn::ClientResetAbilitySystemComponent_Implementation()
{
}

void AFortPlayerPawn::ClientUnequipCurrentWeaponById_Implementation(FGuid WeaponItemGuid, bool bSetWeaponAttachment)
{
}

void AFortPlayerPawn::ConstructItemSwapClonedFromLoadout(const FFortAthenaLoadout& Loadout, const UAthenaCosmeticItemDefinition* Item, FFortSwapItemAndVariantData& SwapData)
{
}

void AFortPlayerPawn::DebugDestroyVehicle()
{
}

void AFortPlayerPawn::DestroyBalloonRope()
{
}

void AFortPlayerPawn::DisableCosmeticSwap(const FGuid& SwapId)
{
}

void AFortPlayerPawn::DisableFaceRotation(float DurationInSeconds, bool bSetStasis)
{
}

bool AFortPlayerPawn::DontCrossArms() const
{
	return false;
}

bool AFortPlayerPawn::DontHandsOnHips() const
{
	return false;
}

void AFortPlayerPawn::DriverToPassengerAnimationStopped()
{
}

void AFortPlayerPawn::EndedInteractSearch()
{
}

void AFortPlayerPawn::EndFloating()
{
}

void AFortPlayerPawn::EndGhostModeExit()
{
}

void AFortPlayerPawn::EndHovering()
{
}

void AFortPlayerPawn::EndSkydiving()
{
}

void AFortPlayerPawn::EndZiplining(bool bFromJump, bool bReachedEnd)
{
}

void AFortPlayerPawn::ForceDetachFromRemoteControlledPawn()
{
}

void AFortPlayerPawn::ForceOpenParachuteAndOverrideGlider(const UAthenaGliderItemDefinition* InGliderOverride, bool bResetGliderOverrideOnLanding, bool bForceIntoGliderRedeploy)
{
}

FGameplayTagContainer AFortPlayerPawn::GatherMetaTags(const UAthenaCosmeticItemDefinition* CosmeticItem) const
{
	return FGameplayTagContainer();
}

UFXSystemComponent* AFortPlayerPawn::GetActivePlayerFootSplashInWaterLeftComponent() const
{
	return nullptr;
}

UFXSystemComponent* AFortPlayerPawn::GetActivePlayerFootSplashInWaterRightComponent() const
{
	return nullptr;
}

UFXSystemComponent* AFortPlayerPawn::GetActivePlayerHandSplashInWaterComponent() const
{
	return nullptr;
}

UFXSystemComponent* AFortPlayerPawn::GetActivePlayerInWaterComponent() const
{
	return nullptr;
}

UFXSystemComponent* AFortPlayerPawn::GetActivePlayerJumpSplashInWaterComponent() const
{
	return nullptr;
}

UFXSystemComponent* AFortPlayerPawn::GetActivePlayerSwimmingComponent() const
{
	return nullptr;
}

UFXSystemComponent* AFortPlayerPawn::GetActivePlayerWaterBoostComponent() const
{
	return nullptr;
}

AFortAthenaZiplineBase* AFortPlayerPawn::GetActiveZipline() const
{
	return nullptr;
}

UFortPlayerAnimationInterface* AFortPlayerPawn::GetAnimationInterface() const
{
	return nullptr;
}

float AFortPlayerPawn::GetBaseAimPitchQuantized() const
{
	return float();
}

float AFortPlayerPawn::GetBuildCostModifier() const
{
	return float();
}

float AFortPlayerPawn::GetBuildSpeedModifier() const
{
	return float();
}

int32 AFortPlayerPawn::GetCachedFootstepIndex() const
{
	return int32();
}

FVector AFortPlayerPawn::GetCachedStepSurfaceNormal() const
{
	return FVector();
}

EFortCustomBodyType::Type AFortPlayerPawn::GetCharacterBodyType() const
{
	return EFortCustomBodyType::Type();
}

AFortPlayerCharm* AFortPlayerPawn::GetCharacterCharmActorForCharmType(EFortCustomCharmType::Type CharmType) const
{
	return nullptr;
}

EFortCustomGender::Type AFortPlayerPawn::GetCharacterGender() const
{
	return EFortCustomGender::Type();
}

int32 AFortPlayerPawn::GetClientObservedStatValue(const FName& StatName, int32 DefaultValue) const
{
	return int32();
}

TArray<UActorComponent*> AFortPlayerPawn::GetComponentsByClassForPartType(TSubclassOf<UActorComponent> ComponentClass, EFortCustomPartType::Type PartType) const
{
	return TArray<UActorComponent*>();
}

TArray<UActorComponent*> AFortPlayerPawn::GetComponentsByClassOnAllPartModifiers(TSubclassOf<UActorComponent> ComponentClass) const
{
	return TArray<UActorComponent*>();
}

TSoftObjectPtr<UFXSystemAsset> AFortPlayerPawn::GetContrailParticleSystemSoftRef()
{
	return TSoftObjectPtr<UFXSystemAsset>();
}

AFortPlayerPawn* AFortPlayerPawn::GetControllingPawn() const
{
	return nullptr;
}

UCosmeticDataComponent* AFortPlayerPawn::GetCosmeticDataComponent() const
{
	return nullptr;
}

UFortCosmeticLoadoutComponent* AFortPlayerPawn::GetCosmeticLoadoutComponent() const
{
	return nullptr;
}

AFortPlayerPawn* AFortPlayerPawn::GetDBNOHoistee() const
{
	return nullptr;
}

AFortPlayerPawn* AFortPlayerPawn::GetDBNOHoister() const
{
	return nullptr;
}

EFortPawnDisplayContext AFortPlayerPawn::GetDisplayContext() const
{
	return EFortPawnDisplayContext();
}

int32 AFortPlayerPawn::GetExtraLives() const
{
	return int32();
}

UAnimMontage* AFortPlayerPawn::GetFrontendAnimMontageIdleOverride() const
{
	return nullptr;
}

void AFortPlayerPawn::GetGender(bool& IsMale, bool& IsFemale) const
{
}

FText AFortPlayerPawn::GetGliderDisplayName() const
{
	return FText();
}

AActor* AFortPlayerPawn::GetHomeActor() const
{
	return nullptr;
}

bool AFortPlayerPawn::GetIsHoldingObject() const
{
	return false;
}

void AFortPlayerPawn::GetLastWaterSurfaceInfo(FVector& OutWaterSurfacePosition, FVector& OutWaterSurfaceNormal)
{
}

AFortWeapon* AFortPlayerPawn::GetLastWeaponEquippedOnServer() const
{
	return nullptr;
}

float AFortPlayerPawn::GetMaxStamina() const
{
	return float();
}

ACustomCharacterPartModifier* AFortPlayerPawn::GetModifierForPartType(EFortCustomPartType::Type PartType) const
{
	return nullptr;
}

int32 AFortPlayerPawn::GetNumActiveBalloons() const
{
	return int32();
}

const FFortAthenaLoadout& AFortPlayerPawn::GetPawnCosmeticLoadout(const bool bGetBaseLoadout, const bool bWarn) const
{
	static FFortAthenaLoadout Dummy;
	return Dummy;
}

bool AFortPlayerPawn::GetPendingSkydiveLaunch() const
{
	return false;
}

ABuildingGameplayActorPlayerPropAttachment* AFortPlayerPawn::GetPossessedProp() const
{
	return nullptr;
}

const FVector AFortPlayerPawn::GetPreviousPosition()
{
	return FVector();
}

const FVector AFortPlayerPawn::GetPreviousVelocity()
{
	return FVector();
}

FRotator AFortPlayerPawn::GetRemoteViewRotation() const
{
	return FRotator();
}

int32 AFortPlayerPawn::GetSignificanceLOD() const
{
	return int32();
}

float AFortPlayerPawn::GetSimulatedAttributeValue(const FGameplayAttribute& Attribute, const float DefaultValue) const
{
	return float();
}

USkeletalMeshComponent* AFortPlayerPawn::GetSkeletalMeshForCharmType(EFortCustomCharmType::Type CharmType) const
{
	return nullptr;
}

USkeletalMeshComponent* AFortPlayerPawn::GetSkeletalMeshForPartType(EFortCustomPartType::Type PartType) const
{
	return nullptr;
}

float AFortPlayerPawn::GetStamina() const
{
	return float();
}

EFortPawnStasisMode AFortPlayerPawn::GetStasisMode() const
{
	return EFortPawnStasisMode();
}

const TArray<EFortPawnStasisMode>& AFortPlayerPawn::GetStasisModes() const
{
	static TArray<EFortPawnStasisMode> Dummy;
	return Dummy;
}

APawn* AFortPlayerPawn::GetTetherPawn() const
{
	return nullptr;
}

USkeletalMesh* AFortPlayerPawn::GetTetherRopeRodMesh() const
{
	return nullptr;
}

FHitResult AFortPlayerPawn::GetThrownItemTrajectoryHitResult() const
{
	return FHitResult();
}

UFortControllerComponent_TransientQuests* AFortPlayerPawn::GetTransientQuestsComponent() const
{
	return nullptr;
}

bool AFortPlayerPawn::GetUseViewRotationForCameraOrigin() const
{
	return false;
}

AActor* AFortPlayerPawn::GetVehicleActor() const
{
	return nullptr;
}

bool AFortPlayerPawn::GetVehicleOverrideExit()
{
	return false;
}

int32 AFortPlayerPawn::GetVehicleSeatIndex() const
{
	return int32();
}

TScriptInterface<IFortVehicleInterface> AFortPlayerPawn::GetVehicleUInterface() const
{
	return TScriptInterface<IFortVehicleInterface>();
}

float AFortPlayerPawn::GetZiplineSpeedFactor() const
{
	return float();
}

float AFortPlayerPawn::GetZiplineSpeedFactorTarget() const
{
	return float();
}

void AFortPlayerPawn::HACK_ApplyCosmetics(const FString& ApplyCosmetics)
{
}

bool AFortPlayerPawn::HasControlledRCPawn() const
{
	return false;
}

bool AFortPlayerPawn::HasPendingVariantAssets() const
{
	return false;
}

bool AFortPlayerPawn::HasRecentlyExitedZiplineFromJumping() const
{
	return false;
}

bool AFortPlayerPawn::HasRespawnedInAir() const
{
	return false;
}

bool AFortPlayerPawn::HasStartedFloating() const
{
	return false;
}

void AFortPlayerPawn::InvokeWaterHandSplash(const FVector& SplashPosition)
{
}

void AFortPlayerPawn::InvokeWaterHandSplashAttached(USceneComponent* AttachParent, FName AttachSocketName)
{
}

void AFortPlayerPawn::InvokeWaterJumpSplash(const FVector& SplashPosition, float SplashScale)
{
}

bool AFortPlayerPawn::IsActivelySkydiving(const bool bCheckMovementMode) const
{
	return false;
}

bool AFortPlayerPawn::IsActivelySkydivingUpInVortex() const
{
	return false;
}

bool AFortPlayerPawn::IsActivelyStrafingInAir(const bool bCheckMovementMode) const
{
	return false;
}

bool AFortPlayerPawn::IsCharacterCustomizationLoadingCompleted() const
{
	return false;
}

bool AFortPlayerPawn::IsComponentCharacterPartMesh(const USkeletalMeshComponent* SkeletalMeshComponent) const
{
	return false;
}

bool AFortPlayerPawn::IsCoreCharacterCustomizationLoadingCompleted() const
{
	return false;
}

bool AFortPlayerPawn::IsCrouchInputBuffered() const
{
	return false;
}

bool AFortPlayerPawn::IsDrivingInteractBlockingVehicle() const
{
	return false;
}

bool AFortPlayerPawn::IsDrivingVehicle() const
{
	return false;
}

bool AFortPlayerPawn::IsEmoteBlockedByMovement() const
{
	return false;
}

bool AFortPlayerPawn::IsImprovedDBNOEnabled() const
{
	return false;
}

bool AFortPlayerPawn::IsInCharacterCustomization() const
{
	return false;
}

bool AFortPlayerPawn::IsInFloatingMovement() const
{
	return false;
}

bool AFortPlayerPawn::IsInFrontEndHologram() const
{
	return false;
}

bool AFortPlayerPawn::IsInInteractBlockingVehicle() const
{
	return false;
}

bool AFortPlayerPawn::IsInSlipperyMovement() const
{
	return false;
}

bool AFortPlayerPawn::IsInStasis() const
{
	return false;
}

bool AFortPlayerPawn::IsInStasisMode(const EFortPawnStasisMode InStasisMode) const
{
	return false;
}

bool AFortPlayerPawn::IsInVehicle() const
{
	return false;
}

bool AFortPlayerPawn::IsItemAndVariantSwapActiveById(const FGuid& SwapID) const
{
	return false;
}

bool AFortPlayerPawn::IsMaterialOverrideApplied(const FGuid& MaterialOverrideId, bool& bOutIsCurrentOverride)
{
	return false;
}

bool AFortPlayerPawn::IsNiagaraProceduralWaterSim() const
{
	return false;
}

bool AFortPlayerPawn::IsNiagaraSimpleWaterSim() const
{
	return false;
}

bool AFortPlayerPawn::IsOperatingTurret() const
{
	return false;
}

bool AFortPlayerPawn::IsParachuteForcedOpen() const
{
	return false;
}

bool AFortPlayerPawn::IsParachuteLockedOpen() const
{
	return false;
}

bool AFortPlayerPawn::IsParachuteOpen() const
{
	return false;
}

bool AFortPlayerPawn::IsParachuteOpenAndVisible() const
{
	return false;
}

bool AFortPlayerPawn::IsPartVisibleAccordingToCount(EFortCustomPartType::Type PartType) const
{
	return false;
}

bool AFortPlayerPawn::IsPassengerInVehicle() const
{
	return false;
}

bool AFortPlayerPawn::IsPassivelySkydiving() const
{
	return false;
}

bool AFortPlayerPawn::IsPickupInteractionWhileSkydivingAllowed() const
{
	return false;
}

bool AFortPlayerPawn::IsRidingOnActor() const
{
	return false;
}

bool AFortPlayerPawn::IsSkydiving() const
{
	return false;
}

bool AFortPlayerPawn::IsSkydivingFromBus() const
{
	return false;
}

bool AFortPlayerPawn::IsSkydivingFromLaunchPad() const
{
	return false;
}

bool AFortPlayerPawn::IsSprinting() const
{
	return false;
}

bool AFortPlayerPawn::IsTethered() const
{
	return false;
}

bool AFortPlayerPawn::IsUsingPersonalVehicle() const
{
	return false;
}

bool AFortPlayerPawn::IsUsingUmbrella() const
{
	return false;
}

bool AFortPlayerPawn::IsWaitingForEmoteInteraction() const
{
	return false;
}

bool AFortPlayerPawn::IsWaterSprintBoosting() const
{
	return false;
}

bool AFortPlayerPawn::IsZiplining() const
{
	return false;
}

void AFortPlayerPawn::ListCharacterParts(const FString& GenderAndOrPartString) const
{
}

bool AFortPlayerPawn::LocalIsTryingToGetPickup()
{
	return false;
}

void AFortPlayerPawn::LocalThrowCarriedPlayer()
{
}

void AFortPlayerPawn::ManualReviveFromDBNO(TSubclassOf<UGameplayEffect> ReviveGameplayEffectsOverride)
{
}

void AFortPlayerPawn::MarkSafe(TSubclassOf<UGameplayEffect> GEtoApply)
{
}

void AFortPlayerPawn::MulticastClearWeaponOverrideAnimSet_Implementation()
{
}

void AFortPlayerPawn::MulticastSetWeaponOverrideAnimSet_Implementation(UFortWeaponAnimSet* WeaponOverrideAnimSet)
{
}

void AFortPlayerPawn::MulticastUpdateVehicleInputStateReliable_Implementation(FFortAthenaVehicleInputStateReliable ReliableInput)
{
}

void AFortPlayerPawn::OnBeginParachuteMovement_Implementation()
{
}

void AFortPlayerPawn::OnBoundHidingInstigatorDestroyed(AActor* DestroyedActor)
{
}

void AFortPlayerPawn::OnBoundStasisInstigatorDestroyed(AActor* DestroyedActor)
{
}

void AFortPlayerPawn::OnCapsuleBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void AFortPlayerPawn::OnEndParachuteMovement_Implementation()
{
}

void AFortPlayerPawn::OnPhysicsVolumeChanged(APhysicsVolume* NewVolume)
{
}

void AFortPlayerPawn::OnPostPhysicsRotation(UCharacterMovementComponent* CharMoveComp, float DeltaSeconds)
{
}

void AFortPlayerPawn::OnRemoveZiplineFromIgnoreWhenMovingTimerExpired()
{
}

void AFortPlayerPawn::OnRep_AccelerationPack()
{
}

void AFortPlayerPawn::OnRep_AccelerationZPack()
{
}

void AFortPlayerPawn::OnRep_AnimBPOverride()
{
}

void AFortPlayerPawn::OnRep_AnimLayersOverride()
{
}

void AFortPlayerPawn::OnRep_AppliedSwaps()
{
}

void AFortPlayerPawn::OnRep_AttachmentMesh()
{
}

void AFortPlayerPawn::OnRep_BaseCosmeticLoadout()
{
}

void AFortPlayerPawn::OnRep_bDisabledTetheringSupport()
{
}

void AFortPlayerPawn::OnRep_bHasStartedFloating()
{
}

void AFortPlayerPawn::OnRep_CharPartAnimMontageInfo()
{
}

void AFortPlayerPawn::OnRep_ControlledRCPawn()
{
}

void AFortPlayerPawn::OnRep_CustomMeshHeightAdjustTarget()
{
}

void AFortPlayerPawn::OnRep_DBNOHoistee()
{
}

void AFortPlayerPawn::OnRep_DBNOHoisterData(const FFortDBNOCarryHoisterData& PreviousDBNOHoisterData)
{
}

void AFortPlayerPawn::OnRep_FacialTypeOverride()
{
}

void AFortPlayerPawn::OnRep_FootstepBankOverride()
{
}

void AFortPlayerPawn::OnRep_GliderOverride(const TArray<UAthenaGliderItemDefinition*>& OldSet)
{
}

void AFortPlayerPawn::OnRep_GroupEmoteLookTarget()
{
}

void AFortPlayerPawn::OnRep_GroupEmoteSyncValue()
{
}

void AFortPlayerPawn::OnRep_IsEmoteLeader()
{
}

void AFortPlayerPawn::OnRep_IsInAnyStorm()
{
}

void AFortPlayerPawn::OnRep_IsInsideSafeZone()
{
}

void AFortPlayerPawn::OnRep_IsInWaterVolume()
{
}

void AFortPlayerPawn::OnRep_IsParachuteForcedOpen()
{
}

void AFortPlayerPawn::OnRep_IsParachuteOpen(bool bPreviousState)
{
}

void AFortPlayerPawn::OnRep_IsSkydiving(bool bPreviousState)
{
}

void AFortPlayerPawn::OnRep_IsSkydivingFromBus()
{
}

void AFortPlayerPawn::OnRep_IsTacticalSprinting()
{
}

void AFortPlayerPawn::OnRep_IsTargeting()
{
}

void AFortPlayerPawn::OnRep_LockGroupEmoteLeaderRotation()
{
}

void AFortPlayerPawn::OnRep_MaterialOverrides()
{
}

void AFortPlayerPawn::OnRep_NetMovementPrioritized(bool bOldNetMovementPrioritized)
{
}

void AFortPlayerPawn::OnRep_NPCRetargetingInfo()
{
}

void AFortPlayerPawn::OnRep_ParachuteLockedOpen()
{
}

void AFortPlayerPawn::OnRep_PossessedProp(ABuildingGameplayActorPlayerPropAttachment* OldProp)
{
}

void AFortPlayerPawn::OnRep_RepAnimMontageStartSection()
{
}

void AFortPlayerPawn::OnRep_ReplicatedAnimMontage()
{
}

void AFortPlayerPawn::OnRep_ReplicatedInGliderRedeploy()
{
}

void AFortPlayerPawn::OnRep_ReplicatedIsInSlipperyMovement()
{
}

void AFortPlayerPawn::OnRep_ShallowWaterVolumeData(const FPlayerPawnShallowWaterVolumeData& PreviousShallowWaterVolumeData)
{
}

void AFortPlayerPawn::OnRep_StartedInteractSearch()
{
}

void AFortPlayerPawn::OnRep_StasisModes()
{
}

void AFortPlayerPawn::OnRep_StoredControlRotation()
{
}

void AFortPlayerPawn::OnRep_UpdateContextTracker()
{
}

void AFortPlayerPawn::OnRep_VehicleInputStateReliableForReplay()
{
}

void AFortPlayerPawn::OnRep_WaitingForEmoteInteraction()
{
}

void AFortPlayerPawn::OnRep_ZiplineState(const FZiplinePawnState& PreviousValue)
{
}

void AFortPlayerPawn::OnTacticalSprintEnded()
{
}

void AFortPlayerPawn::OnTacticalSprintStarted()
{
}

void AFortPlayerPawn::OnWeaponEquippedNative(AFortWeapon* NewWeapon, AFortWeapon* OldWeapon)
{
}

void AFortPlayerPawn::OverrideScalarMaterialParameterLocal(FName ParamName, float Value)
{
}

void AFortPlayerPawn::PassengerToDriverAnimationStopped()
{
}

void AFortPlayerPawn::PassengerToPassengerAnimationStopped()
{
}

void AFortPlayerPawn::PerformSupplementalKillVolumeSweep()
{
}

void AFortPlayerPawn::PlayGroupEmote(const UFortMontageItemDefinitionBase* EmoteAsset)
{
}

void AFortPlayerPawn::PopAnimBPOverride(int32 Priority, TSubclassOf<UAnimInstance> InAnimBPOverride)
{
}

void AFortPlayerPawn::PopAnimLayersOverride(int32 Priority, const TArray<TSubclassOf<UAnimInstance>>& InAnimLayersOverride)
{
}

void AFortPlayerPawn::PopFootstepBankOverride(int32 Priority, UFortFootstepAudioBank* InFootstepBankOverride)
{
}

void AFortPlayerPawn::PopGliderOverride(const UAthenaGliderItemDefinition* InGliderToRemove)
{
}

void AFortPlayerPawn::PopLocomotionAnimSetOverride(int32 Priority, UFortLocomotionAnimAsset* InLocomotionAnimAssetOverride)
{
}

void AFortPlayerPawn::PopWeaponAnimSetOverride(int32 Priority, UFortWeaponAnimSet* InWeaponAnimSetOverride)
{
}

void AFortPlayerPawn::PostResIn()
{
}

void AFortPlayerPawn::PushAnimBPOverride(int32 Priority, TSubclassOf<UAnimInstance> InAnimBPOverride)
{
}

void AFortPlayerPawn::PushAnimLayersOverride(int32 Priority, const TArray<TSubclassOf<UAnimInstance>>& InAnimLayersOverride)
{
}

void AFortPlayerPawn::PushFootstepBankOverride(int32 Priority, UFortFootstepAudioBank* InFootstepBankOverride)
{
}

void AFortPlayerPawn::PushGliderOverride(const UAthenaGliderItemDefinition* InGliderOverride)
{
}

void AFortPlayerPawn::PushLocomotionAnimSetOverride(int32 Priority, UFortLocomotionAnimAsset* InLocomotionAnimAssetOverride)
{
}

void AFortPlayerPawn::PushWeaponAnimSetOverride(int32 Priority, UFortWeaponAnimSet* InWeaponAnimSetOverride)
{
}

void AFortPlayerPawn::RandomizeCharacter(const FString& GenderString)
{
}

void AFortPlayerPawn::RemoveAbilityAITarget(AFortAIPawn* InTarget)
{
}

void AFortPlayerPawn::RemoveAllDefaultStasisApplications()
{
}

void AFortPlayerPawn::RemoveAttachment()
{
}

void AFortPlayerPawn::RemoveExpiredIgnoredActorsAndCheckForNextTimer()
{
}

bool AFortPlayerPawn::RemoveMaterialOverride(const FGuid& MaterialOverrideId)
{
	return false;
}

bool AFortPlayerPawn::RemoveMaterialOverrideLocal(const FGuid& MaterialOverrideId)
{
	return false;
}

void AFortPlayerPawn::RemoveStasisMode(const FGameplayTag& InStasisGameplayTag, const bool bRemoveAllOfThisTag)
{
}

void AFortPlayerPawn::ResetClothAndDynamics()
{
}

void AFortPlayerPawn::ResetClothAndDynamicsMatching(const FGameplayTagContainer& MatchingTags)
{
}

void AFortPlayerPawn::ResetGameplayAttributes(const bool bIgnoreStatClamp)
{
}

void AFortPlayerPawn::RestoreDBNOCollisionAfterDrop()
{
}

void AFortPlayerPawn::ReviveFromDBNO(AController* EventInstigator)
{
}

void AFortPlayerPawn::SeatChangeAnimationStopped(AFortPlayerController* VehiclePlayerController)
{
}

void AFortPlayerPawn::ServerAddStasisMode_Implementation(const EFortPawnStasisMode InStasisMode, AActor* BoundStasisInstigator, const FGameplayTag& InStasisGameplayTag, const FGameplayTagContainer& AllowedActionTags)
{
}

void AFortPlayerPawn::ServerChooseGender_Implementation(EFortCustomGender::Type Gender)
{
}
bool AFortPlayerPawn::ServerChooseGender_Validate(EFortCustomGender::Type Gender)
{
	return true;
}

void AFortPlayerPawn::ServerChoosePart_Implementation(EFortCustomPartType::Type Part, UCustomCharacterPart* ChosenCharacterPart)
{
}
bool AFortPlayerPawn::ServerChoosePart_Validate(EFortCustomPartType::Type Part, UCustomCharacterPart* ChosenCharacterPart)
{
	return true;
}

void AFortPlayerPawn::ServerCycleAccessoryColorSwatch_Implementation(EFortCustomPartType::Type Part, bool bNext)
{
}
bool AFortPlayerPawn::ServerCycleAccessoryColorSwatch_Validate(EFortCustomPartType::Type Part, bool bNext)
{
	return true;
}

void AFortPlayerPawn::ServerCycleColorSwatch_Implementation(EColorSwatchType SwatchType, bool bNext)
{
}
bool AFortPlayerPawn::ServerCycleColorSwatch_Validate(EColorSwatchType SwatchType, bool bNext)
{
	return true;
}

void AFortPlayerPawn::ServerCyclePart_Implementation(EFortCustomPartType::Type Part, bool bNextPart)
{
}

void AFortPlayerPawn::ServerDropCarriedPlayer_Implementation()
{
}

void AFortPlayerPawn::ServerEmoteSecondaryFirePressed_Implementation()
{
}

void AFortPlayerPawn::ServerEnterStasis_Implementation(EFortPawnStasisMode InStasisMode)
{
}

void AFortPlayerPawn::ServerEquipLastWeaponOrGadget_Implementation(bool bForce)
{
}

void AFortPlayerPawn::ServerHandlePickup(AFortPickup* Pickup, float InFlyTime, const FVector InStartDirection, bool bPlayPickupSound)
{
}

void AFortPlayerPawn::ServerHandlePickupInfo_Implementation(AFortPickup* Pickup, FFortPickupRequestInfo Params)
{
}
bool AFortPlayerPawn::ServerHandlePickupInfo_Validate(AFortPickup* Pickup, FFortPickupRequestInfo Params)
{
	return true;
}

void AFortPlayerPawn::ServerHoistDBNOPlayer_Implementation(AFortPlayerPawn* InDBNOHoistee)
{
}

void AFortPlayerPawn::ServerInterrogateDBNOPlayer_Implementation(AFortPlayerPawn* InDBNOHoistee)
{
}

AFortAthenaVehicle* AFortPlayerPawn::ServerOnExitVehicle(ETryExitVehicleBehavior ExitForceBehavior, const bool bDestroyVehicleWhenForced)
{
	return nullptr;
}

void AFortPlayerPawn::ServerPlayUnableToPerformActionMontage_Implementation()
{
}

void AFortPlayerPawn::ServerResetAbilitySystemComponent_Implementation()
{
}

void AFortPlayerPawn::ServerRespawnFromDBNO_Implementation()
{
}

void AFortPlayerPawn::ServerReviveFromDBNO_Implementation(AController* EventInstigator)
{
}

void AFortPlayerPawn::ServerRootMotionInterruptNotifyStopMontage_Implementation(UAnimMontage* MontageToStop)
{
}

void AFortPlayerPawn::ServerSendAimbotDetectionStatus_Implementation(const TArray<uint8>& Payload)
{
}
bool AFortPlayerPawn::ServerSendAimbotDetectionStatus_Validate(const TArray<uint8>& Payload)
{
	return true;
}

void AFortPlayerPawn::ServerSendZiplineState_Implementation(const FZiplinePawnState& InZiplineState)
{
}
bool AFortPlayerPawn::ServerSendZiplineState_Validate(const FZiplinePawnState& InZiplineState)
{
	return true;
}

void AFortPlayerPawn::ServerSetAimbotDetection_Implementation(bool bEnableDetection)
{
}
bool AFortPlayerPawn::ServerSetAimbotDetection_Validate(bool bEnableDetection)
{
	return true;
}

void AFortPlayerPawn::ServerSetAttachment_Implementation(FRepFortMeshAttachment Attachment)
{
}

void AFortPlayerPawn::ServerStartGliderSwap_Implementation()
{
}

void AFortPlayerPawn::ServerStopGliderSwap_Implementation()
{
}

void AFortPlayerPawn::ServerThrowCarriedPlayer_Implementation()
{
}

void AFortPlayerPawn::ServerToggleBodyType_Implementation()
{
}

void AFortPlayerPawn::ServerToggleGender_Implementation()
{
}

void AFortPlayerPawn::ServerUnmarkRespawned_Implementation()
{
}

void AFortPlayerPawn::ServerUpdateVehicleInputStateReliable_Implementation(FFortAthenaVehicleInputStateReliable ReliableInput)
{
}

void AFortPlayerPawn::ServerUpdateVehicleInputStateUnreliable_Implementation(FFortAthenaVehicleInputStateUnreliable ReliableInput, float Timestamp)
{
}

void AFortPlayerPawn::ServerVehicleEjectForZiplining_Implementation()
{
}

void AFortPlayerPawn::SetActorHiddenInGameWithGameplayEffect(bool bNewHidden, const TSubclassOf<UGameplayEffect>& HidePawnGameplayEffectClass, bool bRemoveAllOfThisTag)
{
}

void AFortPlayerPawn::SetActorHiddenInGameWithTag(const bool bNewHidden, const FGameplayTag HidePawnGameplayTag, AActor* BoundHidingInstigator, const bool bRemoveAllOfThisTag)
{
}

bool AFortPlayerPawn::SetAssembledMeshSchemasCosmetic(TArray<UAssembledMeshSchema*> AssembledMeshSchemas)
{
	return false;
}

void AFortPlayerPawn::SetBalloonRope(ABuildingGameplayActor* InBalloonRope)
{
}

void AFortPlayerPawn::SetCanSlide(bool bCanSlide)
{
}

bool AFortPlayerPawn::SetCharacterPartVisibility(EFortCustomPartType::Type InPartType, bool bNewVisibility, bool bPropagateToChildren)
{
	return false;
}

void AFortPlayerPawn::SetChuteAction(EChuteActions::Type InChuteAction)
{
}

void AFortPlayerPawn::SetClientObservedStatsFromAnotherPawn(AFortPlayerPawn* OtherPawn)
{
}

void AFortPlayerPawn::SetCrouch(const bool bNewValue, const bool bAttemptToSlide)
{
}

void AFortPlayerPawn::SetCustomMeshHeightAdjustTarget(int32 HeightAdjust, int32 LerpSpeed)
{
}

void AFortPlayerPawn::SetEquippedArmoredInterface(TScriptInterface<IFortArmoredInterface> InInterface)
{
}

void AFortPlayerPawn::SetFacialTypeOverride(EFortFacialAnimTypes NewType)
{
}

void AFortPlayerPawn::SetForceMoveRelativeToCameraRotation(bool bNewValue)
{
}

void AFortPlayerPawn::SetFortPlayerPawnLightingChannels(bool bChannel0, bool bChannel1, bool bChannel2)
{
}

void AFortPlayerPawn::SetHomeActor(AActor* NewActor)
{
}

void AFortPlayerPawn::SetInSlipperyMovement(bool bIsSlippery)
{
}

void AFortPlayerPawn::SetIsInFrontEndHologram(bool bInFrontEndHologram)
{
}

void AFortPlayerPawn::SetIsParachuteForcedOpen(bool bNewIsParachuteForcedOpen)
{
}

void AFortPlayerPawn::SetIsWaitingForEmoteInteraction(bool bWaitingForEmoteInteraction)
{
}

void AFortPlayerPawn::SetNumActiveBalloons(int32 NewBalloonCount)
{
}

void AFortPlayerPawn::SetPendingSkydiveLaunch(bool bPending)
{
}

void AFortPlayerPawn::SetPendingTetherLaunch(float Amount)
{
}

void AFortPlayerPawn::SetPetType(const UAthenaPetItemDefinition* PetToCreate)
{
}

void AFortPlayerPawn::SetPossessedProp(ABuildingGameplayActorPlayerPropAttachment* InPossessedProp)
{
}

void AFortPlayerPawn::SetPreviousPosition(FVector OldPosition)
{
}

void AFortPlayerPawn::SetPreviousVelocity(FVector OldVelocity)
{
}

void AFortPlayerPawn::SetScalarParamOnOverriddenMaterials(const FName ParamName, float Value)
{
}

void AFortPlayerPawn::SetStasisMode(EFortPawnStasisMode InStasisMode)
{
}

void AFortPlayerPawn::SetTetherPawn(APawn* InTetherPawn)
{
}

void AFortPlayerPawn::SetTetherRopeRodMesh(USkeletalMesh* InMesh)
{
}

void AFortPlayerPawn::SetTextureParamOnOverriddenMaterials(const FName ParamName, UTexture* Value)
{
}

void AFortPlayerPawn::SetThrownItemTrajectoryHitResult(const FHitResult& InHitResult)
{
}

void AFortPlayerPawn::SetTransformationMontage(UAnimMontage* CurrentMontage, UAnimMontage* FutureMontage, float StartTime)
{
}

void AFortPlayerPawn::SetVectorParamOnOverriddenMaterials(const FName ParamName, const FLinearColor& Value)
{
}

void AFortPlayerPawn::SetVehicleOverrideExit(const bool bIgnoreLaunch)
{
}

void AFortPlayerPawn::SetWeaponOverrideAnimSet(UFortWeaponAnimSet* WeaponOverrideAnimSet)
{
}

bool AFortPlayerPawn::ShouldAllowShadowStanceMaterialsForPartType(EFortCustomPartType::Type PartType) const
{
	return false;
}

bool AFortPlayerPawn::ShouldDriverHaveReticle() const
{
	return false;
}

bool AFortPlayerPawn::ShouldPlayDeathAnimation()
{
	return false;
}

void AFortPlayerPawn::ShowTestingPredictiveInput()
{
}

void AFortPlayerPawn::SpawnNiagaraWaterComponents(const bool bRegister)
{
}

void AFortPlayerPawn::StartedInteractSearch()
{
}

void AFortPlayerPawn::StartFloating()
{
}

void AFortPlayerPawn::StartGhostModeExit(const float InGhostModeExitDuration)
{
}

bool AFortPlayerPawn::StartPlayerDistanceTraveledTimer()
{
	return false;
}

void AFortPlayerPawn::StopCarryingPlayer(bool bFromAbilityCancel)
{
}

void AFortPlayerPawn::StopFacialAnimationStream()
{
}

void AFortPlayerPawn::StopItemInteractionAbility(const EItemInteractionStatus ItemInteractionStatus, const FGameplayTag OverrideItemInteractAbilityTag)
{
}

bool AFortPlayerPawn::SupportsTetheredMovement()
{
	return false;
}

void AFortPlayerPawn::SwapPawnCosmeticItemAndVariant(const FGuid& SwapId, const TArray<FFortSwapItemAndVariantData>& SwapData, bool bAllowActiveHotswap, EFortAppliedSwapItemAndVariantState ForcedSwapState)
{
}

void AFortPlayerPawn::SwitchToNextPart(const FString& PartName)
{
}

void AFortPlayerPawn::SwitchToPreviousPart(const FString& PartName)
{
}

void AFortPlayerPawn::TemporarilyIgnoreClientMovementErrorChecksAndCorrection(const float Duration)
{
}

void AFortPlayerPawn::ToggleBodyType()
{
}

void AFortPlayerPawn::ToggleCrouch(const bool bAttemptToSlide)
{
}

void AFortPlayerPawn::ToggleGender()
{
}

void AFortPlayerPawn::UnableToPerformAction(bool bPlayMontage, const FGameplayTagContainer& FailedReason)
{
}

void AFortPlayerPawn::UnequipCurrentWeaponById(FGuid WeaponItemGuid, bool bSetWeaponAttachment)
{
}

void AFortPlayerPawn::UpdateAimbotDetectionStatus()
{
}

void AFortPlayerPawn::UpdateGameStateModifiedGravity(float GravityMultiplier)
{
}

void AFortPlayerPawn::UpdatePlayerDistanceTraveled()
{
}

void AFortPlayerPawn::UpdatePreviousPositionAndVelocity(float DeltaSeconds, FVector OldLocation, FVector OldVelocity)
{
}

void AFortPlayerPawn::VerifySkydivingMatchesServer()
{
}

bool AFortPlayerPawn::WantsToGoFromVehicleToZipline() const
{
	return false;
}

void AFortPlayerPawn::WhenCosmeticMeshApplied(FOnCosmeticMeshAppliedBP Delegate, FDelegateHandleController& DelegateHandleController_Out)
{
}

void AFortPlayerPawn::WhenCosmeticMeshAppliedWithAnyStruct(FOnCosmeticMeshAppliedBPWithAnyStruct Delegate, FDelegateHandleController& DelegateHandleController_Out, const FInstancedStruct& AnyStruct)
{
}

void AFortPlayerPawn::WhenCosmeticPartApplied(FOnCosmeticPartAppliedBP Delegate, bool SkipNullMesh, FDelegateHandleController& DelegateHandleController_Out)
{
}

void AFortPlayerPawn::WhenCosmeticPartAppliedWithAnyStruct(FOnCosmeticPartAppliedBPWithAnyStruct Delegate, bool SkipNullMesh, FDelegateHandleController& DelegateHandleController_Out, const FInstancedStruct& AnyStruct)
{
}

void AFortPlayerPawn::WhenCosmeticsApplied(FOnCosmeticsAppliedBP Delegate, FDelegateHandleController& DelegateHandleController_Out)
{
}

void AFortPlayerPawn::WhenCosmeticsAppliedWithAnyStruct(FOnCosmeticsAppliedBPWithAnyStruct Delegate, FDelegateHandleController& DelegateHandleController_Out, const FInstancedStruct& AnyStruct)
{
}

void AFortPlayerPawn::WhenCosmeticSpecificPartApplied(FOnCosmeticPartAppliedBP Delegate, bool SkipNullMesh, EFortCustomPartType::Type PartType, FDelegateHandleController& DelegateHandleController_Out)
{
}

void AFortPlayerPawn::WhenCosmeticSpecificPartAppliedWithAnyStruct(FOnCosmeticPartAppliedBPWithAnyStruct Delegate, bool SkipNullMesh, EFortCustomPartType::Type PartType, FDelegateHandleController& DelegateHandleController_Out, const FInstancedStruct& AnyStruct)
{
}

void AFortPlayerPawn::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPlayerPawn, VehicleInputStateReliable);
	DOREPLIFETIME(AFortPlayerPawn, bIsNearSafeZoneEdge);
	DOREPLIFETIME(AFortPlayerPawn, bIsTacticalSprinting);
	DOREPLIFETIME(AFortPlayerPawn, bIsWaterJump);
	DOREPLIFETIME(AFortPlayerPawn, bIsWaterSprintBoost);
	DOREPLIFETIME(AFortPlayerPawn, bIsWaterSprintBoostPending);
	DOREPLIFETIME(AFortPlayerPawn, bIsTargeting);
	DOREPLIFETIME(AFortPlayerPawn, bIsTargetingConsumableThrow);
	DOREPLIFETIME(AFortPlayerPawn, bIsSwappingCharacterParts);
	DOREPLIFETIME(AFortPlayerPawn, StasisMode);
	DOREPLIFETIME(AFortPlayerPawn, StasisModes);
	DOREPLIFETIME(AFortPlayerPawn, BuildingState);
	DOREPLIFETIME(AFortPlayerPawn, AccelerationZPack);
	DOREPLIFETIME(AFortPlayerPawn, bIsInWaterVolume);
	DOREPLIFETIME(AFortPlayerPawn, ShallowWaterVolumeData);
	DOREPLIFETIME(AFortPlayerPawn, CachedTeamControllingRC);
	DOREPLIFETIME(AFortPlayerPawn, BalloonActiveCount);
	DOREPLIFETIME(AFortPlayerPawn, bIsSkydiving);
	DOREPLIFETIME(AFortPlayerPawn, bIsParachuteOpen);
	DOREPLIFETIME(AFortPlayerPawn, bIsParachuteForcedOpen);
	DOREPLIFETIME(AFortPlayerPawn, bIsSkydivingFromBus);
	DOREPLIFETIME(AFortPlayerPawn, bIsSkydivingFromLaunchPad);
	DOREPLIFETIME(AFortPlayerPawn, bReplicatedIsInSlipperyMovement);
	DOREPLIFETIME(AFortPlayerPawn, bIsProxySimulationTimedOut);
	DOREPLIFETIME(AFortPlayerPawn, bInGliderRedeploy);
	DOREPLIFETIME(AFortPlayerPawn, bStartedInteractSearch);
	DOREPLIFETIME(AFortPlayerPawn, bIsUsingJetpack);
	DOREPLIFETIME(AFortPlayerPawn, bIsPlayingEmote);
	DOREPLIFETIME(AFortPlayerPawn, bIsRespawning);
	DOREPLIFETIME(AFortPlayerPawn, bIsRespawningInAir);
	DOREPLIFETIME(AFortPlayerPawn, bCanShowDefaultSkin);
	DOREPLIFETIME(AFortPlayerPawn, bDisabledTetheringSupport);
	DOREPLIFETIME(AFortPlayerPawn, bIsWaitingForEmoteInteraction);
	DOREPLIFETIME(AFortPlayerPawn, bIsEmoteLeader);
	DOREPLIFETIME(AFortPlayerPawn, bShouldSyncAnimationWithEmoteLeader);
	DOREPLIFETIME(AFortPlayerPawn, bShouldJitterAnimationSyncWithEmoteLeader);
	DOREPLIFETIME(AFortPlayerPawn, bDoubleFileEmoteSecondLine);
	DOREPLIFETIME(AFortPlayerPawn, bLockGroupEmoteLeaderRotation);
	DOREPLIFETIME(AFortPlayerPawn, EmoteBandLeaderIndex);
	DOREPLIFETIME(AFortPlayerPawn, GroupEmoteLookTarget);
	DOREPLIFETIME(AFortPlayerPawn, GroupEmoteTailTarget);
	DOREPLIFETIME(AFortPlayerPawn, GroupEmoteAnimOffset);
	DOREPLIFETIME(AFortPlayerPawn, GroupEmoteLeaderRotationYawOffset);
	DOREPLIFETIME(AFortPlayerPawn, GroupEmoteSyncValue);
	DOREPLIFETIME(AFortPlayerPawn, ReplicatedCustomMeshHeightAdjustTarget);
	DOREPLIFETIME(AFortPlayerPawn, bIsInAnyStorm);
	DOREPLIFETIME(AFortPlayerPawn, bIsInsideSafeZone);
	DOREPLIFETIME(AFortPlayerPawn, StasisAbilityHandles);
	DOREPLIFETIME(AFortPlayerPawn, bHasStartedFloating);
	DOREPLIFETIME(AFortPlayerPawn, ZiplineState);
	DOREPLIFETIME(AFortPlayerPawn, bCanPredictJumpApex);
	DOREPLIFETIME(AFortPlayerPawn, InteractingPCRep);
	DOREPLIFETIME(AFortPlayerPawn, PossessedProp);
	DOREPLIFETIME(AFortPlayerPawn, BaseCosmeticLoadout);
	DOREPLIFETIME(AFortPlayerPawn, AppliedSwaps);
	DOREPLIFETIME(AFortPlayerPawn, ServerLoadoutChangeSync);
	DOREPLIFETIME(AFortPlayerPawn, MaterialOverrides);
	DOREPLIFETIME(AFortPlayerPawn, RepCharPartAnimMontageInfo);
	DOREPLIFETIME(AFortPlayerPawn, ClientObservedStats);
	DOREPLIFETIME(AFortPlayerPawn, NPCRetargetingInfo);
	DOREPLIFETIME(AFortPlayerPawn, AnimBPOverride);
	DOREPLIFETIME(AFortPlayerPawn, FootstepBankOverride);
	DOREPLIFETIME(AFortPlayerPawn, WeaponAnimSetOverride);
	DOREPLIFETIME(AFortPlayerPawn, LocomotionAnimAssetOverride);
	DOREPLIFETIME(AFortPlayerPawn, AnimLayersOverride);
	DOREPLIFETIME(AFortPlayerPawn, DBNOHoisterData);
	DOREPLIFETIME(AFortPlayerPawn, DBNOHoistee);
	DOREPLIFETIME(AFortPlayerPawn, PlayerStatus);
	DOREPLIFETIME(AFortPlayerPawn, AccelerationPack);
	DOREPLIFETIME(AFortPlayerPawn, RepAnimMontageInfo);
	DOREPLIFETIME(AFortPlayerPawn, RepAnimMontageStartSection);
	DOREPLIFETIME(AFortPlayerPawn, bNetMovementPrioritized);
	DOREPLIFETIME(AFortPlayerPawn, LandingMontagePair);
	DOREPLIFETIME(AFortPlayerPawn, bParachuteLockedOpen);
	DOREPLIFETIME(AFortPlayerPawn, AttachmentMesh);
	DOREPLIFETIME(AFortPlayerPawn, PetState);
	DOREPLIFETIME(AFortPlayerPawn, GliderOverrideStack);
	DOREPLIFETIME(AFortPlayerPawn, RemoteViewData32);
	DOREPLIFETIME(AFortPlayerPawn, ControlledRCPawn);
	DOREPLIFETIME(AFortPlayerPawn, StoredControlRotation);
	DOREPLIFETIME(AFortPlayerPawn, FacialTypeOverride);
}

void UFortItemAndVariantSwapHelpers::PushCosmeticOverrideOntoPawn(AFortPlayerPawn* Pawn, UAthenaCosmeticItemDefinition* Cosmetic)
{
}
