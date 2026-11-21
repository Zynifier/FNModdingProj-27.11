// Copyright Epic Games, Inc. All Rights Reserved.

#include "Pawns/FortPawn.h"
#include "Net/UnrealNetwork.h"

UActorComponent* AFortPawn::AddDynamicComponentByClass(TSubclassOf<UActorComponent> ComponentClass)
{
	return nullptr;
}

void AFortPawn::AddEmoteAudioComponent(FName SoundID, UAudioComponent* AudioComponent, float FadeOutTime, bool bPersistsOverMontages)
{
}

void AFortPawn::AddNonReplicatedTagToPawn(const FGameplayTag& Tag)
{
}

void AFortPawn::AddProjectileIgnoreActor(AActor* ActorToIgnore)
{
}

void AFortPawn::AddWeaponTraceIgnoreActor(AActor* ActorToIgnore)
{
}

void AFortPawn::AlignRotationToHitDirection(const FVector& HitDirection)
{
}

int32 AFortPawn::AnimMontage_LocalJumpToRandomSection()
{
	return int32();
}

bool AFortPawn::AnimMontage_LocalJumpToSectionName(FName SectionName)
{
	return false;
}

void AFortPawn::AnimMontage_LocalSetNextSectionName(UAnimMontage* AnimMontage, FName SectionName, FName NextSectionName)
{
}

void AFortPawn::ApplyKnockback(float KnockbackMagnitude, float KnockbackZAngle, FVector ImpulseDir)
{
}

bool AFortPawn::AreEmoteAudioComponentsAllowed() const
{
	return false;
}

void AFortPawn::AttachAssetToSocket(const FAssetAttachment& InAttachment)
{
}

void AFortPawn::BroadcastLinkAnimLayer_Implementation(TSubclassOf<UAnimInstance> AnimLayer)
{
}

void AFortPawn::BroadcastUnlinkAnimLayer_Implementation(TSubclassOf<UAnimInstance> AnimLayer)
{
}

bool AFortPawn::CanSpawnSoundVisuals(EFortSoundIndicatorTypes IndicatorType) const
{
	return false;
}

void AFortPawn::ClearEmoteAudioComponents(UFortItemDefinition* EmoteItemDef)
{
}

void AFortPawn::ClientInternalEquipWeapon_Implementation(AFortWeapon* Weapon)
{
}

bool AFortPawn::DestroyDynamicComponent(UActorComponent* Component)
{
	return false;
}

void AFortPawn::DetachAssetFromSocket(FName SocketName)
{
}

void AFortPawn::DoFatalDamage(UAbilitySystemComponent* KillerAbilitySystemComponent)
{
}

void AFortPawn::EmoteStarted(UFortItemDefinition* MontageItemDef)
{
}

void AFortPawn::EmoteStopped(UFortItemDefinition* MontageItemDef)
{
}

void AFortPawn::EnterSkyTube(AFortSkyTube* SkyTube, bool& bOutIsFirstTube)
{
}

bool AFortPawn::EquipBestWeapon()
{
	return false;
}

AFortWeapon* AFortPawn::EquipWeaponDefinition(const UFortWeaponItemDefinition* WeaponData, FGuid ItemEntryGuid, FGuid TrackerGuid, bool bDisableEquipAnimation)
{
	return nullptr;
}

void AFortPawn::ExitSkyTube(AFortSkyTube* SkyTube, bool& bOutIsLastTube)
{
}

void AFortPawn::ForceKill(FGameplayTag DeathReason, AController* KillerController, AActor* KillerActor)
{
}

void AFortPawn::GameplayCue(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters)
{
}

void AFortPawn::GameplayCue_Damage(EGameplayCueEvent::Type EventType, const FGameplayCueParameters& Parameters)
{
}

void AFortPawn::GameplayCue_InstantDeath(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters)
{
}

TArray<UAudioComponent*> AFortPawn::GetAllEmoteAudioComponents() const
{
	return TArray<UAudioComponent*>();
}

USkeletalMeshComponent* AFortPawn::GetAssetSkeletalMeshComponentAttachment(FName SocketName)
{
	return nullptr;
}

UAudioParameterComponent* AFortPawn::GetAudioParameterComponent() const
{
	return nullptr;
}

EFortControlRecoveryBehavior AFortPawn::GetControlRecoveryBehavior() const
{
	return EFortControlRecoveryBehavior();
}

float AFortPawn::GetControlResistance() const
{
	return float();
}

float AFortPawn::GetCurrentMontageSectionTimeLeft()
{
	return float();
}

float AFortPawn::GetCurrentOvershield() const
{
	return float();
}

FText AFortPawn::GetCurrentSentenceSpeechText() const
{
	return FText();
}

AFortSkyTube* AFortPawn::GetCurrentSkyTube() const
{
	return nullptr;
}

AFortWaterBodyActor* AFortPawn::GetCurrentWaterBody() const
{
	return nullptr;
}

AFortWeapon* AFortPawn::GetCurrentWeapon() const
{
	return nullptr;
}

const TArray<AFortWeapon*>& AFortPawn::GetCurrentWeaponList() const
{
	static TArray<AFortWeapon*> Dummy;
	return Dummy;
}

EFortDamageZone::Type AFortPawn::GetDamageZone(const FHitResult& InHitResult) const
{
	return EFortDamageZone::Type();
}

FVector AFortPawn::GetDefaultTargetingOrigin() const
{
	return FVector();
}

FRotator AFortPawn::GetDefaultTargetingRotation() const
{
	return FRotator();
}

UAudioComponent* AFortPawn::GetEmoteAudioComponent(FName SoundId) const
{
	return nullptr;
}

UFortEmoteComponent* AFortPawn::GetEmoteComponent() const
{
	return nullptr;
}

USkeletalMeshComponent* AFortPawn::GetEmotePropAttachMesh()
{
	return nullptr;
}

UFortAIEncounterInfo* AFortPawn::GetEncounterInfo() const
{
	return nullptr;
}

UAudioComponent* AFortPawn::GetFirstValidEmoteAudioComponent() const
{
	return nullptr;
}

UFortFootstepComponent* AFortPawn::GetFootstepComponent() const
{
	return nullptr;
}

EFortFootstepSurfaceType::Type AFortPawn::GetFootstepSurfaceType() const
{
	return EFortFootstepSurfaceType::Type();
}

float AFortPawn::GetHealth() const
{
	return float();
}

float AFortPawn::GetHealthPercent() const
{
	return float();
}

FName AFortPawn::GetIgnoreFallDamageComponentTag() const
{
	return FName();
}

bool AFortPawn::GetIsSlopeSliding() const
{
	return false;
}

bool AFortPawn::GetIsSwingAttached() const
{
	return false;
}

bool AFortPawn::GetIsSwinging() const
{
	return false;
}

float AFortPawn::GetKnockbackMultiplier() const
{
	return float();
}

float AFortPawn::GetKnockbackThreshold() const
{
	return float();
}

float AFortPawn::GetLocalSpin() const
{
	return float();
}

float AFortPawn::GetMaxControlResistance() const
{
	return float();
}

float AFortPawn::GetMaxDistanceWithoutFallDamage() const
{
	return float();
}

float AFortPawn::GetMaxHealth() const
{
	return float();
}

float AFortPawn::GetMaxOvershield() const
{
	return float();
}

float AFortPawn::GetMaxShield() const
{
	return float();
}

float AFortPawn::GetMaxSignalInStorm() const
{
	return float();
}

int32 AFortPawn::GetMeleeComboCounter() const
{
	return int32();
}

float AFortPawn::GetMeleeReticleStrikeAngle(bool bPrimaryInput) const
{
	return float();
}

FVector AFortPawn::GetMovementPredictionPosition(float PredictionDeltaTime) const
{
	return FVector();
}

AActor* AFortPawn::GetMyMovementBaseActor()
{
	return nullptr;
}

float AFortPawn::GetOvershield() const
{
	return float();
}

float AFortPawn::GetOvershieldPercent() const
{
	return float();
}

UMaterialInstanceDynamic* AFortPawn::GetPawnMID(int32 ElementIndex)
{
	return nullptr;
}

FVector AFortPawn::GetPendingLaunchVelocity() const
{
	return FVector();
}

TArray<AActor*> AFortPawn::GetProjectileIgnoredActors() const
{
	return TArray<AActor*>();
}

float AFortPawn::GetShield() const
{
	return float();
}

float AFortPawn::GetShieldOrHealthPercent()
{
	return float();
}

float AFortPawn::GetShieldPercent() const
{
	return float();
}

float AFortPawn::GetSignalInStorm() const
{
	return float();
}

void AFortPawn::GetSimplifiedSavedPositions(TArray<FSavedPosition>& OutPositions, bool bStopAtTeleport) const
{
}

void AFortPawn::GetSlopeSlidingAngles(float& LocalPitch, float& LocalRoll) const
{
}

FVector AFortPawn::GetSlopeSlidingNormal() const
{
	return FVector();
}

UFortSoundLibraryComponent* AFortPawn::GetSoundLibraryComponent(FGameplayTag InComponentTag) const
{
	return nullptr;
}

void AFortPawn::GetSphericalHitDirection(const FVector& HitDirection, float& Azimuth, float& Elevation) const
{
}

UFortSurfaceTrackingComponent* AFortPawn::GetSurfaceTrackingComponent() const
{
	return nullptr;
}

FVector AFortPawn::GetSwingAttachLocation() const
{
	return FVector();
}

float AFortPawn::GetSwingingDistanceToGround()
{
	return float();
}

FTransform AFortPawn::GetTargetingTransform(EFortAbilityTargetingSource Source, UFortGameplayAbility* SourceAbility) const
{
	return FTransform();
}

uint8 AFortPawn::GetTeam() const
{
	return uint8();
}

float AFortPawn::GetWaterImmersionDepth() const
{
	return float();
}

void AFortPawn::HandleIsDying()
{
}

void AFortPawn::HandleIsHiddenForDeath()
{
}

bool AFortPawn::HasCurrentMontage() const
{
	return false;
}

void AFortPawn::HideBodyOnDeath(bool bDeathAnimationPlayed)
{
}

void AFortPawn::InitializeDeathHitSocket(FVector WorldLocation, FVector WorldNormal)
{
}

bool AFortPawn::IsActionInputIgnored() const
{
	return false;
}

bool AFortPawn::IsAllowChainStun() const
{
	return false;
}

bool AFortPawn::IsDBNO() const
{
	return false;
}

bool AFortPawn::IsDead() const
{
	return false;
}

bool AFortPawn::IsForciblyWadingInWater() const
{
	return false;
}

bool AFortPawn::IsFrontalHit(const FVector& HitDirection) const
{
	return false;
}

bool AFortPawn::IsInGoop() const
{
	return false;
}

bool AFortPawn::IsInsideHidingProp(const bool bIncludeTransition) const
{
	return false;
}

bool AFortPawn::IsInSkyTube() const
{
	return false;
}

bool AFortPawn::IsInVortex() const
{
	return false;
}

bool AFortPawn::IsSlidingEnabled() const
{
	return false;
}

bool AFortPawn::IsSpinning() const
{
	return false;
}

bool AFortPawn::IsStaggered() const
{
	return false;
}

bool AFortPawn::IsSurfaceSwimming() const
{
	return false;
}

bool AFortPawn::IsTurnTransitionActiveAndControllingRotation() const
{
	return false;
}

bool AFortPawn::IsWeaponHiddenByHolstering() const
{
	return false;
}

bool AFortPawn::IsWeaponHolstered() const
{
	return false;
}

TArray<ABuildingActor*> AFortPawn::K2_GetOverlappingBuildings() const
{
	return TArray<ABuildingActor*>();
}

void AFortPawn::KillDisconnectedPawn()
{
}

void AFortPawn::LaunchCharacterJump(FVector LaunchVelocity, bool bXYOverride, bool bZOverride, bool bIgnoreFallDamage, bool bPlayFeedbackEvent)
{
}

void AFortPawn::LinkAnimLayer(TSubclassOf<UAnimInstance> AnimLayer)
{
}

void AFortPawn::LogChugSplashEvent()
{
}

void AFortPawn::MaxHealthStateChanged(bool bIsMaxHealth)
{
}

void AFortPawn::MovingEmoteStopped()
{
}

void AFortPawn::MulticastLinkAnimLayer_Implementation(TSubclassOf<UAnimInstance> AnimLayer)
{
}

void AFortPawn::MulticastSetWeaponVisibility_Implementation(AFortWeapon* Weapon, bool bIsVisible)
{
}

void AFortPawn::MulticastUnlinkAnimLayer_Implementation(TSubclassOf<UAnimInstance> AnimLayer)
{
}

void AFortPawn::NetMulticast_Athena_BatchedDamageCues_Implementation(FAthenaBatchedDamageGameplayCues_Shared SharedData, FAthenaBatchedDamageGameplayCues_NonShared NonSharedData)
{
}

void AFortPawn::NetMulticast_InvokeGameplayCueAdded_Implementation(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayEffectContextHandle EffectContext)
{
}

void AFortPawn::NetMulticast_InvokeGameplayCueAdded_WithParams_Implementation(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayCueParameters Parameters)
{
}

void AFortPawn::NetMulticast_InvokeGameplayCueAddedAndWhileActive_FromSpec_Implementation(const FGameplayEffectSpecForRPC& Spec, FPredictionKey PredictionKey)
{
}

void AFortPawn::NetMulticast_InvokeGameplayCueAddedAndWhileActive_WithParams_Implementation(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayCueParameters GameplayCueParameters)
{
}

void AFortPawn::NetMulticast_InvokeGameplayCueExecuted_Implementation(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayEffectContextHandle EffectContext)
{
}

void AFortPawn::NetMulticast_InvokeGameplayCueExecuted_FromSpec_Implementation(const FGameplayEffectSpecForRPC Spec, FPredictionKey PredictionKey)
{
}

void AFortPawn::NetMulticast_InvokeGameplayCueExecuted_WithParams_Implementation(const FGameplayTag GameplayCueTag, FPredictionKey PredictionKey, FGameplayCueParameters GameplayCueParameters)
{
}

void AFortPawn::NetMulticast_InvokeGameplayCuesAddedAndWhileActive_WithParams_Implementation(const FGameplayTagContainer GameplayCueTags, FPredictionKey PredictionKey, FGameplayCueParameters GameplayCueParameters)
{
}

void AFortPawn::NetMulticast_InvokeGameplayCuesExecuted_Implementation(const FGameplayTagContainer GameplayCueTags, FPredictionKey PredictionKey, FGameplayEffectContextHandle EffectContext)
{
}

void AFortPawn::NetMulticast_InvokeGameplayCuesExecuted_WithParams_Implementation(const FGameplayTagContainer GameplayCueTags, FPredictionKey PredictionKey, FGameplayCueParameters GameplayCueParameters)
{
}

void AFortPawn::OnAllMontageInstancesEnded()
{
}

void AFortPawn::OnDeathPlayEffects_Implementation(float Damage, const FGameplayTagContainer& DamageTags, FVector Momentum, const FHitResult& HitInfo, AFortPawn* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext)
{
}

bool AFortPawn::OnlySpinWhenFalling() const
{
	return false;
}

void AFortPawn::OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted)
{
}

void AFortPawn::OnMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
}

void AFortPawn::OnMontageStarted(UAnimMontage* Montage)
{
}

void AFortPawn::OnOverlappingBuildingDestroyed(AActor* DestroyedActor)
{
}

void AFortPawn::OnOverlappingBuildingDied(TWeakObjectPtr<ABuildingActor> Building)
{
}

void AFortPawn::OnRep_bIsInvulnerable()
{
}

void AFortPawn::OnRep_bWeaponHolstered()
{
}

void AFortPawn::OnRep_ClientAILODSettings()
{
}

void AFortPawn::OnRep_CurrentWeapon(AFortWeapon* OldWeapon)
{
}

void AFortPawn::OnRep_DamageZoneActiveBitMask()
{
}

void AFortPawn::OnRep_EmoteWalkSpeed()
{
}

void AFortPawn::OnRep_IsDBNO()
{
}

void AFortPawn::OnRep_IsJumping()
{
}

void AFortPawn::OnRep_IsKnockedBack()
{
}

void AFortPawn::OnRep_IsSkating()
{
}

void AFortPawn::OnRep_IsSliding()
{
}

void AFortPawn::OnRep_IsSlopeSliding()
{
}

void AFortPawn::OnRep_IsSwinging()
{
}

void AFortPawn::OnRep_IsSynchedAction()
{
}

void AFortPawn::OnRep_JumpFlashCount()
{
}

void AFortPawn::OnRep_LandingFlashCount()
{
}

void AFortPawn::OnRep_LastReplicatedEmoteExecuted(const UFortItemDefinition* PreviousValue)
{
}

void AFortPawn::OnRep_MovementModeExtension()
{
}

void AFortPawn::OnRep_MovingEmote()
{
}

void AFortPawn::OnRep_MovingEmoteFollowingOnly()
{
}

void AFortPawn::OnRep_PawnUniqueID()
{
}

void AFortPawn::OnRep_PushMomentum()
{
}

void AFortPawn::OnRep_ReplicatedIsInGoop()
{
}

void AFortPawn::OnRep_ReplicatedIsInVortex()
{
}

void AFortPawn::OnRep_ReplicatedSkyTube()
{
}

void AFortPawn::OnRep_ReplicatedWaterBody()
{
}

void AFortPawn::OnRep_Sentence()
{
}

void AFortPawn::OnRep_StormShieldComponent()
{
}

void AFortPawn::OnRep_SynchedActionWarpPointInfo()
{
}

void AFortPawn::OnRep_TeleportCounter()
{
}

void AFortPawn::OnRep_VocalChords()
{
}

void AFortPawn::OnRep_WeaponActivated()
{
}

void AFortPawn::PawnStartFire(uint8 FireModeNum)
{
}

void AFortPawn::PawnStartSecondaryFire(uint8 FireModeNum)
{
}

void AFortPawn::PawnStopFire(uint8 FireModeNum)
{
}

void AFortPawn::PawnStopSecondaryFire(uint8 FireModeNum)
{
}

bool AFortPawn::PickUpActor(AActor* PickupTarget, const UFortDecoItemDefinition* PlacementDecoItemDefinition)
{
	return false;
}

void AFortPawn::PlayFootStepSound(int32 FootDown)
{
}

float AFortPawn::PlayLocalAnimMontage(UAnimMontage* NewAnimMontage, float InPlayRate, FName StartSectionName, bool bNoBlend)
{
	return float();
}

void AFortPawn::PlaySound_Implementation(USoundBase* Sound, float VolumeMultiplier, float PitchMultiplier)
{
}

void AFortPawn::PlaySwimmingSound(EFortSwimmingAudioType::Type SoundType)
{
}

void AFortPawn::PooledCascadeCameraLensEffectCompleted(UParticleSystemComponent* FinishedComponent)
{
}

void AFortPawn::PooledNiagaraCameraLensEffectCompleted(UNiagaraComponent* FinishedComponent)
{
}

void AFortPawn::PrototypeCharacterMovement(EMovementMode MovementMode, FVector LaunchVelocity)
{
}

void AFortPawn::RegisterAdditionalGameplayModifiers(const TArray<UFortGameplayModifierItemDefinition*>& ModifierDefinitions)
{
}

void AFortPawn::RemoveCallout(const FGameplayTag& CalloutTagToRemove)
{
}

void AFortPawn::RemoveNonReplicatedTagToPawn(const FGameplayTag& Tag)
{
}

void AFortPawn::RemoveProjectileIgnoreActor(AActor* ActorToRemove)
{
}

void AFortPawn::RemoveWeaponTraceIgnoreActor(AActor* ActorToRemove)
{
}

void AFortPawn::ResetFallingHeight()
{
}

void AFortPawn::ServerInternalEquipWeapon_Implementation(AFortWeapon* Weapon)
{
}
bool AFortPawn::ServerInternalEquipWeapon_Validate(AFortWeapon* Weapon)
{
	return true;
}

void AFortPawn::ServerTeleportNearLocation_Implementation(FVector ActorLocation)
{
}
bool AFortPawn::ServerTeleportNearLocation_Validate(FVector ActorLocation)
{
	return true;
}

void AFortPawn::SetAimAssistTargetOverride(const USceneComponent* InOverride)
{
}

void AFortPawn::SetAllowEmoteAudioComponents(const bool InAllowEmoteAudioComponents)
{
}

void AFortPawn::SetCallout(const FGameplayTag& CalloutTagToSet, float Duration)
{
}

bool AFortPawn::SetCommonWaterFXParams(UFXSystemComponent* FXComponent, const bool bUpdateWaveData, const bool bUpdatePlaneData, const bool bUpdateSurfaceData)
{
	return false;
}

void AFortPawn::SetControlRecoveryBehavior(EFortControlRecoveryBehavior NewBehavior)
{
}

void AFortPawn::SetCurrentOvershield(float NewShieldValue)
{
}

void AFortPawn::SetFallingHeight(float FromHeight)
{
}

void AFortPawn::SetFNameBasedOnHitDirection(const FVector& HitDirection, FName& NameResult, FName NameFront, FName NameBack, FName NameLeft, FName NameRight)
{
}

void AFortPawn::SetGravityJumpMultipliers(float NewGravityVal, float NewVehicleGravityVal, float NewJumpZ, float NewJumpHorizontalAcceleration, float NewJumpHorizontalVelocity)
{
}

void AFortPawn::SetGravityMultiplier(float NewGravityVal)
{
}

void AFortPawn::SetHealth(float NewHealthVal)
{
}

void AFortPawn::SetHolsterWeaponBP(const TScriptInterface<IFortHolsterWeaponSourceInterface> HolsterSource, const bool bHolster, const bool bPlayEquipAnim, const FName HolsterId)
{
}

void AFortPawn::SetInVortex(bool bNewValue, float UpwardLaunchVelocity, float GravityFloorAltitude, float GravityFloorWidth, float GravityFloorGravityScalar, float GravityFloorTerminalVelocity, const bool bCanDeployGlider)
{
}

void AFortPawn::SetInVortexVolume(const bool bIsInVortexVolume, const float UpwardLaunchVelocity, const FTransform VolumeTransform, const float VolumeThickness, const float GravityScalar, const float VolumeEdgeTerminalVelocity, const bool bCanDeployGlider)
{
}

void AFortPawn::SetInVortexWithSpin(bool bNewValue, float UpwardLaunchVelocity, float GravityFloorAltitude, float GravityFloorWidth, float GravityFloorGravityScalar, float GravityFloorTerminalVelocity, FVector SpinCenter, float SpinRadius, float SpinVelocity)
{
}

void AFortPawn::SetIsInGoop(const bool bNewValue)
{
}

void AFortPawn::SetIsKnockedBack(bool bKnockback)
{
}

void AFortPawn::SetIsSkating(const bool bNewIsSkating)
{
}

void AFortPawn::SetMaxHealth(float NewHealthVal)
{
}

void AFortPawn::SetMaxOvershield(float NewValue)
{
}

void AFortPawn::SetMaxShield(float NewValue)
{
}

void AFortPawn::SetMaxSignalInStorm(float NewValue)
{
}

void AFortPawn::SetMovementSpeedMultiplier(float NewMovementSpeedVal)
{
}

void AFortPawn::SetPawnAndControlRotation(FRotator NewRotation)
{
}

void AFortPawn::SetPawnVisibility(const bool bNewHidden, const bool bPropagateToWeapon)
{
}

void AFortPawn::SetPawnVisibilityControllerOnly(const bool bNewHidden, const bool bPropagateToWeapon)
{
}

void AFortPawn::SetShield(float NewShieldValue)
{
}

void AFortPawn::SetSignalInStorm(float NewSignalInStormValue)
{
}

void AFortPawn::SetSpawnSpot(AActor* InSpawnSpot)
{
}

void AFortPawn::SetTurnTransitionActiveAndControllingRotation(bool bInControl)
{
}

bool AFortPawn::ShouldDie_Implementation(float Damage, AController* EventInstigator, AActor* DamageCauser)
{
	return false;
}

AEmitterCameraLensEffectBase* AFortPawn::SpawnCameraLensEffect(TSubclassOf<AEmitterCameraLensEffectBase> LensEffectEmitterClass)
{
	return nullptr;
}

AFortEmitterCameraLensEffectDirectional* AFortPawn::SpawnCameraLensEffectDirectional(TSubclassOf<AFortEmitterCameraLensEffectDirectional> LensEffectEmitterClass, AActor* DamageDealer, const FHitResult& HitInfo, bool bDeferSpawn)
{
	return nullptr;
}

TScriptInterface<ICameraLensEffectInterface> AFortPawn::SpawnGenericCameraLensEffect(TSubclassOf<AActor> LensEffectEmitterClass)
{
	return TScriptInterface<ICameraLensEffectInterface>();
}

TScriptInterface<ICameraLensEffectInterface> AFortPawn::SpawnGenericCameraLensEffectDirectional(TSubclassOf<AActor> LensEffectEmitterClass, AActor* DamageDealer, const FHitResult& HitInfo, bool bDeferSpawn)
{
	return TScriptInterface<ICameraLensEffectInterface>();
}

AFortEmitterCameraLensEffectDirectional* AFortPawn::SpawnPooledCameraLensEffectDirectional(TSubclassOf<AFortEmitterCameraLensEffectDirectional> LensEffectEmitterClass, AActor* DamageDealer, const FHitResult& HitInfo, bool bShouldActivate)
{
	return nullptr;
}

TScriptInterface<ICameraLensEffectInterface> AFortPawn::SpawnPooledGenericCameraLensEffectDirectional(TSubclassOf<AActor> LensEffectEmitterClass, AActor* DamageDealer, const FHitResult& HitInfo, bool bShouldActivate)
{
	return TScriptInterface<ICameraLensEffectInterface>();
}

AFortSoundCameraLensEffect* AFortPawn::SpawnSoundLensEffectDirectional(AActor* TrackedActor, FVector HitInfo, const float MaxAudibleDistance, const float EvaluatedStrength, EFortSoundIndicatorTypes IndicatorType, const AActor* InstigatingActor, FLinearColor Tint, UTexture* OverrideIcon)
{
	return nullptr;
}

void AFortPawn::StartPushMomentum(FVector NewPushMomentum, float Duration)
{
}

void AFortPawn::StartSpinning(float Value, bool bFallingOnly, bool bAdjustForInputYawScale)
{
}

void AFortPawn::StopBatchedLoopingWeaponActivation()
{
}

void AFortPawn::StopPushMomentum()
{
}

void AFortPawn::StopSpinning()
{
}

float AFortPawn::TimeFromJumpApex() const
{
	return float();
}

void AFortPawn::TriggerAnimInputEvent(const UFortAnimInputEvent* AnimInputEvent)
{
}

void AFortPawn::TriggerFeedbackEvent(FName EventName, AFortPawn* InstigatorPawn, AFortPawn* Recipient, float OverriddenDelay)
{
}

void AFortPawn::UnlinkAnimLayer(TSubclassOf<UAnimInstance> AnimLayer)
{
}

bool AFortPawn::WasDBNOOnDeath() const
{
	return false;
}

bool AFortPawn::WillFallFromHeightCauseDamage(float FallDistance) const
{
	return false;
}

void AFortPawn::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPawn, bIgnoreNextFallingDamage);
	DOREPLIFETIME(AFortPawn, bIsDying);
	DOREPLIFETIME(AFortPawn, bIsHiddenForDeath);
	DOREPLIFETIME(AFortPawn, bIsKnockedback);
	DOREPLIFETIME(AFortPawn, bIsStaggered);
	DOREPLIFETIME(AFortPawn, bMovingEmote);
	DOREPLIFETIME(AFortPawn, bMovingEmoteForwardOnly);
	DOREPLIFETIME(AFortPawn, bMovingEmoteFollowingOnly);
	DOREPLIFETIME(AFortPawn, bMovingEmoteSkipLandingFX);
	DOREPLIFETIME(AFortPawn, bIsInvulnerable);
	DOREPLIFETIME(AFortPawn, bSpotted);
	DOREPLIFETIME(AFortPawn, bWeaponActivated);
	DOREPLIFETIME(AFortPawn, bReplicatedIsInGoop);
	DOREPLIFETIME(AFortPawn, bIsSliding);
	DOREPLIFETIME(AFortPawn, bIsSkating);
	DOREPLIFETIME(AFortPawn, bIsSwinging);
	DOREPLIFETIME(AFortPawn, bIsSynchedAction);
	DOREPLIFETIME(AFortPawn, bSwingingAttached);
	DOREPLIFETIME(AFortPawn, SwingAttachLocation);
	DOREPLIFETIME(AFortPawn, ReplicatedSynchedActionWarpPointInfo);
	DOREPLIFETIME(AFortPawn, bWeaponHolstered);
	DOREPLIFETIME(AFortPawn, bIsDBNO);
	DOREPLIFETIME(AFortPawn, bWasDBNOOnDeath);
	DOREPLIFETIME(AFortPawn, bShouldUseCharacterMovementIdleFastPath);
	DOREPLIFETIME(AFortPawn, CurrentMovementStyle);
	DOREPLIFETIME(AFortPawn, TeleportCounter);
	DOREPLIFETIME(AFortPawn, bIsSlopeSliding);
	DOREPLIFETIME(AFortPawn, PackedReplicatedSlopeAngles);
	DOREPLIFETIME(AFortPawn, StormShieldComponent);
	DOREPLIFETIME(AFortPawn, bIsJumping);
	DOREPLIFETIME(AFortPawn, PawnUniqueID);
	DOREPLIFETIME(AFortPawn, CurrentWeapon);
	DOREPLIFETIME(AFortPawn, SpawnImmunityTime);
	DOREPLIFETIME(AFortPawn, ReplicatedWaterBody);
	DOREPLIFETIME(AFortPawn, bIsStunned);
	DOREPLIFETIME(AFortPawn, WindVolumes);
	DOREPLIFETIME(AFortPawn, VortexParams);
	DOREPLIFETIME(AFortPawn, bReplicatedIsInVortex);
	DOREPLIFETIME(AFortPawn, ReplicatedSkyTube);
	DOREPLIFETIME(AFortPawn, PushMomentum);
	DOREPLIFETIME(AFortPawn, LocalSpin);
	DOREPLIFETIME(AFortPawn, bTurnTransitionActiveAndControllingRotation);
	DOREPLIFETIME(AFortPawn, DefaultHitNotifyAudioBank);
	DOREPLIFETIME(AFortPawn, DamageZoneActiveBitMask);
	DOREPLIFETIME(AFortPawn, JumpFlashCountPacked);
	DOREPLIFETIME(AFortPawn, LandingFlashCountPacked);
	DOREPLIFETIME(AFortPawn, LastReplicatedEmoteExecuted);
	DOREPLIFETIME(AFortPawn, EmoteWalkSpeed);
	DOREPLIFETIME(AFortPawn, AdditionalModifierDefinitions);
	DOREPLIFETIME(AFortPawn, VocalChords);
	DOREPLIFETIME(AFortPawn, bIsDisconnectedPawn);
	DOREPLIFETIME(AFortPawn, DisplayName);
	DOREPLIFETIME(AFortPawn, CurrentCalloutTag);
	DOREPLIFETIME(AFortPawn, CurrentSentence);
	DOREPLIFETIME(AFortPawn, ClientAILODSettings);
	DOREPLIFETIME(AFortPawn, FallbackTag);
	DOREPLIFETIME(AFortPawn, DebugType);
	DOREPLIFETIME(AFortPawn, OverlappingBuildings);
	DOREPLIFETIME(AFortPawn, RepActiveMovementModeExtension);
}

void AFortPawn::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
}

UAbilitySystemComponent* AFortPawn::GetAbilitySystemComponent() const
{
	return nullptr;
}

void AFortPawn::ForceReplication()
{
}
