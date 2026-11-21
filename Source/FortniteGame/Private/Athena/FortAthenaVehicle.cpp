// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortAthenaVehicle.h"
#include "Net/UnrealNetwork.h"
#include "UObject/Class.h"

bool FIgnoredPawn::operator==(const FIgnoredPawn& Other) const
{
	return StaticStruct()->CompareScriptStruct(this, &Other, 0);
}

uint32 GetTypeHash(const FIgnoredPawn& Value)
{
	return 0;
}

bool AFortAthenaVehicle::AddObjectToIgnoreForShocks(AActor* Actor)
{
	return false;
}

void AFortAthenaVehicle::AddReasonWhyCantContainPlayers(const FText& TextToAdd)
{
}

bool AFortAthenaVehicle::AllowInteractionBetweenFortVolume() const
{
	return false;
}

bool AFortAthenaVehicle::AnyWheelsOnGround() const
{
	return false;
}

UMaterialInstanceDynamic* AFortAthenaVehicle::ApplyMaterialAndUseWrapIfPossible(UMaterialInterface* MaterialToUse, int32 SlotIndex, bool bAlwaysCreateMID)
{
	return nullptr;
}

bool AFortAthenaVehicle::BlocksBuilding() const
{
	return false;
}

bool AFortAthenaVehicle::BP_CanInteract_Implementation(AController* InController)
{
	return false;
}

bool AFortAthenaVehicle::BP_IsSeatEnabled_Implementation(const int32 SeatIdx) const
{
	return false;
}

void AFortAthenaVehicle::BreakDamageablePart(const FName& ShapeName)
{
}

void AFortAthenaVehicle::BreakSpawnedSleepLock()
{
}

void AFortAthenaVehicle::BroadcastResetWaterIdleTimeEmpty_Implementation()
{
}

bool AFortAthenaVehicle::CanAntigravityOnIncline() const
{
	return false;
}

bool AFortAthenaVehicle::CanContainPlayers() const
{
	return false;
}

bool AFortAthenaVehicle::CanCorrectOrientation(AFortPawn* FP) const
{
	return false;
}

bool AFortAthenaVehicle::CanDriveOnIncline() const
{
	return false;
}

bool AFortAthenaVehicle::CanForcePawnToSeat(AFortPlayerPawn* PawnToSeat, const int32 SeatIndex) const
{
	return false;
}

bool AFortAthenaVehicle::CanShootFromSeat(const int32 SeatIndex) const
{
	return false;
}

bool AFortAthenaVehicle::CanTeleport() const
{
	return false;
}

void AFortAthenaVehicle::ClientBroadcastAbilityImpactAtLocation_Implementation(UObject* WorldContextObject, USoundBase* InSound, UObject* InInstigator, const FVector& Velocity, const float Radius, const FName Tag, const bool bSubtractLocalNoise)
{
}

bool AFortAthenaVehicle::ClientIsDriver() const
{
	return false;
}

void AFortAthenaVehicle::ClientRefreshVehicleClientSettings_Implementation()
{
}

void AFortAthenaVehicle::ClientTeleportVehicleToLoc_Implementation(const FVector& TeleportLocation)
{
}

bool AFortAthenaVehicle::ContainsPlayers() const
{
	return false;
}

void AFortAthenaVehicle::DebugDrawImpactBucket_Implementation(FVector Location, FVector ImpactVector, FColor Color)
{
}

void AFortAthenaVehicle::DemagnetizeFromSkyTube()
{
}

void AFortAthenaVehicle::DestroyAllDamageableParts()
{
}

void AFortAthenaVehicle::DestroyVehicle()
{
}

void AFortAthenaVehicle::DisableTrickCredit(float Duration)
{
}

void AFortAthenaVehicle::EjectAllPlayers()
{
}

bool AFortAthenaVehicle::EjectPlayerPawn(const AFortPlayerPawn* InPlayerPawn)
{
	return false;
}

bool AFortAthenaVehicle::EjectSeat(const int32 SeatIndex)
{
	return false;
}

void AFortAthenaVehicle::EnableVehicleStencil(AActor* PotentialVehicle, const bool bEnable, bool bHighlighted, int32 StencilValueOverride)
{
}

int32 AFortAthenaVehicle::FindSeatIndex(const AFortPlayerPawn* PlayerPawn) const
{
	return int32();
}

bool AFortAthenaVehicle::ForceEnterSeat(AFortPlayerPawn* Pawn, const EVehicleSeats Seat, const bool bIgnoreDBNOCheck)
{
	return false;
}

void AFortAthenaVehicle::ForceSeatPawns(TArray<AFortPlayerPawn*> PawnsToSeat)
{
}

bool AFortAthenaVehicle::ForceSeatSinglePawn(AFortPlayerPawn* PawnToSeat, int32 SeatIndex)
{
	return false;
}

void AFortAthenaVehicle::GamepadUseOrExitPressedFromSeat(const int32 FromSeatIndex)
{
}

void AFortAthenaVehicle::GamepadUseOrExitReleasedFromSeat(const int32 FromSeatIndex)
{
}

void AFortAthenaVehicle::GameplayCue_Damage(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters)
{
}

float AFortAthenaVehicle::GetAccelerationAlpha() const
{
	return float();
}

TArray<AFortPlayerPawn*> AFortAthenaVehicle::GetAllNonDriverPassengers() const
{
	return TArray<AFortPlayerPawn*>();
}

float AFortAthenaVehicle::GetBrakingDelta() const
{
	return float();
}

FVector AFortAthenaVehicle::GetCrouchingFiringOffsetForSeat(const int32 SeatIdx) const
{
	return FVector();
}

float AFortAthenaVehicle::GetCurrentBrakeForce(float ForwardSpeedKmh) const
{
	return float();
}

float AFortAthenaVehicle::GetCurrentForwardVelocity() const
{
	return float();
}

float AFortAthenaVehicle::GetCurrentFOV() const
{
	return float();
}

int32 AFortAthenaVehicle::GetCurrentGear() const
{
	return int32();
}

const FVehicleRuntimeModifiers& AFortAthenaVehicle::GetCurrentRuntimeProperties()
{
	static FVehicleRuntimeModifiers Dummy;
	return Dummy;
}

float AFortAthenaVehicle::GetDesiredForwardSpeedKmh() const
{
	return float();
}

float AFortAthenaVehicle::GetDesiredForwardVelocity() const
{
	return float();
}

float AFortAthenaVehicle::GetDesiredForwardVelocityDelta() const
{
	return float();
}

FString AFortAthenaVehicle::GetDisplayName() const
{
	return FString();
}

AFortPlayerPawn* AFortAthenaVehicle::GetDriver() const
{
	return nullptr;
}

float AFortAthenaVehicle::GetExplosionDelay() const
{
	return float();
}

float AFortAthenaVehicle::GetHealth() const
{
	return float();
}

FVector AFortAthenaVehicle::GetIndicatorRelativeOffset() const
{
	return FVector();
}

float AFortAthenaVehicle::GetMaxHealth() const
{
	return float();
}

float AFortAthenaVehicle::GetMaxZeroHealthTime() const
{
	return float();
}

int32 AFortAthenaVehicle::GetMinigameClassID() const
{
	return int32();
}

uint8 AFortAthenaVehicle::GetMinigameTeamID() const
{
	return uint8();
}

float AFortAthenaVehicle::GetNormalizedAudioRPM() const
{
	return float();
}

AFortPlayerPawn* AFortAthenaVehicle::GetPawnAtSeat(const int32 SeatIdx) const
{
	return nullptr;
}

float AFortAthenaVehicle::GetPontoonRadius(const int32 PontoonIndex) const
{
	return float();
}

FVector AFortAthenaVehicle::GetPreviousLinearAcceleration() const
{
	return FVector();
}

FVector AFortAthenaVehicle::GetPreviousLinearVelocity() const
{
	return FVector();
}

float AFortAthenaVehicle::GetSeatSwitchCooldown(const int32 SeatIndex) const
{
	return float();
}

float AFortAthenaVehicle::GetSelfDestructCleanupDelay() const
{
	return float();
}

float AFortAthenaVehicle::GetSelfDestructDelay() const
{
	return float();
}

bool AFortAthenaVehicle::GetShootingCone(const int32 SeatIdx, FTransform& OutConeTM, FAthenaVehicleShootingCone& OutCone) const
{
	return false;
}

int32 AFortAthenaVehicle::GetSignificanceLOD() const
{
	return int32();
}

UFortSoundLibraryComponent* AFortAthenaVehicle::GetSoundLibraryComponent(FGameplayTag InComponentTag) const
{
	return nullptr;
}

float AFortAthenaVehicle::GetSpringLengthRatio(int32 SpringIdx) const
{
	return float();
}

FVector AFortAthenaVehicle::GetStandingFiringOffsetForSeat(const int32 SeatIdx) const
{
	return FVector();
}

float AFortAthenaVehicle::GetSteeringAngle() const
{
	return float();
}

bool AFortAthenaVehicle::GetTireState(int32 TireIndex) const
{
	return false;
}

float AFortAthenaVehicle::GetTotalSpeedKmh() const
{
	return float();
}

FVector AFortAthenaVehicle::GetVehicleVelocity() const
{
	return FVector();
}

float AFortAthenaVehicle::GetWaterLevel() const
{
	return float();
}

void AFortAthenaVehicle::HandleFuelChanged(float NewFuelPercent, float OldFuelPercent)
{
}

void AFortAthenaVehicle::HandleLowFuel()
{
}

void AFortAthenaVehicle::HandleOutOfFuel()
{
}

bool AFortAthenaVehicle::HasConstraints() const
{
	return false;
}

bool AFortAthenaVehicle::HasDriver() const
{
	return false;
}

bool AFortAthenaVehicle::HasEverContainedPlayers() const
{
	return false;
}

bool AFortAthenaVehicle::HasExploded() const
{
	return false;
}

bool AFortAthenaVehicle::HasTraction() const
{
	return false;
}

bool AFortAthenaVehicle::IsAirControlling() const
{
	return false;
}

bool AFortAthenaVehicle::IsAsleep() const
{
	return false;
}

bool AFortAthenaVehicle::IsBraking() const
{
	return false;
}

bool AFortAthenaVehicle::IsCameraControlledRotation() const
{
	return false;
}

bool AFortAthenaVehicle::IsCorrectingOrientation() const
{
	return false;
}

bool AFortAthenaVehicle::IsCriticalHealth() const
{
	return false;
}

bool AFortAthenaVehicle::IsDriverMinigameTeamRestricted(const AFortPlayerPawn* PlayerPawn) const
{
	return false;
}

bool AFortAthenaVehicle::IsDriverSplitScreen() const
{
	return false;
}

bool AFortAthenaVehicle::IsEnforcingMinigameClassRestriction() const
{
	return false;
}

bool AFortAthenaVehicle::IsEnforcingTeamRestriction() const
{
	return false;
}

bool AFortAthenaVehicle::IsHonking() const
{
	return false;
}

bool AFortAthenaVehicle::IsInAir() const
{
	return false;
}

bool AFortAthenaVehicle::IsInReverseGear() const
{
	return false;
}

bool AFortAthenaVehicle::IsInSkyTube() const
{
	return false;
}

bool AFortAthenaVehicle::IsInWater() const
{
	return false;
}

bool AFortAthenaVehicle::IsInWaterBody() const
{
	return false;
}

bool AFortAthenaVehicle::IsJumping() const
{
	return false;
}

bool AFortAthenaVehicle::IsMagnetizedForSkyTubes() const
{
	return false;
}

bool AFortAthenaVehicle::IsOnFire() const
{
	return false;
}

bool AFortAthenaVehicle::IsOutOfRechargeableFuel() const
{
	return false;
}

bool AFortAthenaVehicle::IsOverlappingWaterBody() const
{
	return false;
}

bool AFortAthenaVehicle::IsPendingDeath() const
{
	return false;
}

bool AFortAthenaVehicle::IsRechargeableFuelBelowThreshold() const
{
	return false;
}

bool AFortAthenaVehicle::IsScrapingSidesOrTop() const
{
	return false;
}

bool AFortAthenaVehicle::IsSlowEnoughToInteract() const
{
	return false;
}

bool AFortAthenaVehicle::IsSprinting() const
{
	return false;
}

bool AFortAthenaVehicle::IsSquadRestricted(const AFortPlayerPawnAthena* InteractingPawn) const
{
	return false;
}

void AFortAthenaVehicle::ManageSpeedDamageMutlipliers()
{
}

float AFortAthenaVehicle::ModifyIncomingDamage(float Damage, const FGameplayTagContainer& InTags, const FGameplayEffectContextHandle& EffectContext, AController* EventInstigator, AActor* DamageCauser)
{
	return float();
}

void AFortAthenaVehicle::MulticastVehicleInputStateUnreliable_Implementation(FFortAthenaVehicleInputStateUnreliable InputState, AFortPlayerPawn* Pawn)
{
}

void AFortAthenaVehicle::OnDisabledChanged_Implementation(bool bDisabled)
{
}

void AFortAthenaVehicle::OnEnterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void AFortAthenaVehicle::OnExitOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AFortAthenaVehicle::OnPawnExitVehicle_Implementation(AFortPlayerPawn* PlayerPawn, FName ExitSocketName)
{
}

void AFortAthenaVehicle::OnPoppedTire(const int32 TireIndex, const bool bFakeTire)
{
}

void AFortAthenaVehicle::OnPrimitiveComponentSleep(UPrimitiveComponent* WakingComponent, FName BoneName)
{
}

void AFortAthenaVehicle::OnPrimitiveComponentWake(UPrimitiveComponent* WakingComponent, FName BoneName)
{
}

void AFortAthenaVehicle::OnRep_AbilitySystemComponent()
{
}

void AFortAthenaVehicle::OnRep_ActiveGameplayEffectGrantedTagsToForceRemove()
{
}

void AFortAthenaVehicle::OnRep_CorrectTargetOrientation()
{
}

void AFortAthenaVehicle::OnRep_DamageableParts(const TArray<FVehicleDamageablePart>& PrevDamageableParts)
{
}

void AFortAthenaVehicle::OnRep_Exploded()
{
}

void AFortAthenaVehicle::OnRep_ForceKinematicOnClientCount()
{
}

void AFortAthenaVehicle::OnRep_HealthSet()
{
}

void AFortAthenaVehicle::OnRep_IgnoredBuildingActors()
{
}

void AFortAthenaVehicle::OnRep_NetPrediction_AP()
{
}

void AFortAthenaVehicle::OnRep_NetPrediction_SP()
{
}

void AFortAthenaVehicle::OnRep_OnFire()
{
}

void AFortAthenaVehicle::OnRep_OverrideWrap()
{
}

void AFortAthenaVehicle::OnRep_PendingDeath()
{
}

void AFortAthenaVehicle::OnRep_SpawnedSleepLockActive()
{
}

void AFortAthenaVehicle::OnRep_SurfaceTypeVehicleOn(EPhysicalSurface PreviousSurfaceOn)
{
}

void AFortAthenaVehicle::OnRep_Tires(const TArray<ETireStates>& PrevTireStates)
{
}

void AFortAthenaVehicle::OnRep_ToggleableParts(const TArray<FVehicleToggleablePart>& PrevToggleableParts)
{
}

void AFortAthenaVehicle::OnRep_VehicleAttributes()
{
}

void AFortAthenaVehicle::OnRepairedTire(const int32 TireIndex, const bool bFakeTire)
{
}

void AFortAthenaVehicle::OnWaterTooDeep_Implementation()
{
}

void AFortAthenaVehicle::OverrideCurrentWrap(const UAthenaItemWrapDefinition* LoadedWrap)
{
}

void AFortAthenaVehicle::OverridePontoonRadiusOnServer(int32 PontoonIndex, float NewRadius)
{
}

void AFortAthenaVehicle::PawnHitByVehicle_Implementation(AFortPawn* Pawn, const FVector& ImpactPoint, const FVector& ImpactNormal, const FVector LaunchVector)
{
}

bool AFortAthenaVehicle::PlayerIsTryingToReverse() const
{
	return false;
}

bool AFortAthenaVehicle::RearLateralFrictionHasReachedMax() const
{
	return false;
}

void AFortAthenaVehicle::RefreshVehicleClientSettings()
{
}

void AFortAthenaVehicle::ReleaseVehicleControlledExternalyInternal()
{
}

void AFortAthenaVehicle::RemoveIgnoredPawnForDamage(const AFortPawn* IgnoredPawn)
{
}

bool AFortAthenaVehicle::RemoveObjectToIgnoreForShocks(AActor* Actor)
{
	return false;
}

bool AFortAthenaVehicle::RemoveReasonWhyCantContainPlayers(const FText& TextToRemove)
{
	return false;
}

void AFortAthenaVehicle::RepairAllDamageableParts(const float NewHealthPercent)
{
}

void AFortAthenaVehicle::RepairDamageablePart(const FName& ShapeName, const float NewHealthPercent)
{
}

void AFortAthenaVehicle::RequestReliablePhysicsUpdate_Implementation()
{
}

void AFortAthenaVehicle::ResetHasContact()
{
}

void AFortAthenaVehicle::ResetTrick()
{
}

bool AFortAthenaVehicle::SeatIsTurret(const int32 SeatIndex) const
{
	return false;
}

bool AFortAthenaVehicle::ServerOnAttemptInteract(const FInteractionType& InteractType)
{
	return false;
}

void AFortAthenaVehicle::ServerReceiveInputCmd_Implementation(int32 ClientFrameNumber, const TArray<uint8>& Data)
{
}

void AFortAthenaVehicle::ServerSetDestructionInfo(const float InSelfDestructTime, const float InMaxTimeZeroHealth, const float InMaxTimeSelfDestructCleanup, const float InMaxTimeExplosion)
{
}

void AFortAthenaVehicle::ServerSetIgnoreAllFallingDamage_Implementation(bool InIgnoreAllFallingDamage)
{
}

void AFortAthenaVehicle::ServerSetIgnoreNextFallingDamage_Implementation(bool InIgnoreNextFallingDamage)
{
}

void AFortAthenaVehicle::ServerSetMoveStickAcceleratesVehicles_Implementation(const bool bNewValue)
{
}

void AFortAthenaVehicle::ServerStartFire_Implementation(uint8 FireModeNum)
{
}

void AFortAthenaVehicle::ServerUsingRiftPortal_Implementation(AActor* RiftPortal)
{
}

void AFortAthenaVehicle::SetActorBase(AActor* InActorBase, const int32 SeatIndex)
{
}

void AFortAthenaVehicle::SetAllowInteractionBetweenFortVolumes(bool bInteractBetweenVolumes)
{
}

void AFortAthenaVehicle::SetCurrentFocusedSocketLocation(const int32 SeatIndex)
{
}

void AFortAthenaVehicle::SetDyingPhysics()
{
}

void AFortAthenaVehicle::SetEnforceMinigameClassRestriction(const bool bNewEnforceClassRestriction)
{
}

void AFortAthenaVehicle::SetEnforceTeamRestriction(const bool bNewEnforceTeamRestriction)
{
}

void AFortAthenaVehicle::SetForceInfiniteFuel(const bool bNewForceInfiniteFuel)
{
}

void AFortAthenaVehicle::SetHealthPercent(float Percent)
{
}

void AFortAthenaVehicle::SetIgnoreAllFallingDamage(bool InIgnoreAllFallingDamage)
{
}

void AFortAthenaVehicle::SetIgnoreNextFallingDamage(bool bInIgnoreNextFallingDamage)
{
}

void AFortAthenaVehicle::SetImpulseResponseMultiplier(const float Multiplier)
{
}

void AFortAthenaVehicle::SetImpulseResponseZBias(const float ZBias)
{
}

void AFortAthenaVehicle::SetMinigameClassID(const int32 NewClassID)
{
}

void AFortAthenaVehicle::SetMinigameTeamID(const uint8 NewTeamID)
{
}

void AFortAthenaVehicle::SetNormalizedAudioRPM(const float NewValue)
{
}

void AFortAthenaVehicle::SetOnFire(const bool bNewValue)
{
}

void AFortAthenaVehicle::SetPropDestructionParams(TArray<TSubclassOf<ABuildingActor>> InBuildingPropClassesVehicleCanDestroy, TArray<TSubclassOf<ABuildingActor>> InBuildingPropClassesVehicleCannotDestroyWhenBoosting, TArray<UBuildingEditModeMetadata*> InWallsVehicleCanDestroy, TArray<UBuildingEditModeMetadata*> InWallsVehicleCannotDestroyWhenBoosting)
{
}

void AFortAthenaVehicle::SetShootingCone(const int32 SeatIdx, FAthenaVehicleShootingCone InCone)
{
}

void AFortAthenaVehicle::SetShouldDealDamage(const bool bNewValue)
{
}

void AFortAthenaVehicle::SetShouldSleepAtSpawn(const bool bNewValue)
{
}

void AFortAthenaVehicle::SetSpringEnabled(const int32 SpringIndex, const bool bEnabled)
{
}

void AFortAthenaVehicle::SetStaticPhysics(const bool bStatic)
{
}

void AFortAthenaVehicle::SetSupportCosmeticWrap(const bool bNewSupportCosmeticWrap)
{
}

void AFortAthenaVehicle::SetUnoccupiedAutoDestroy(float UnoccupiedTime)
{
}

void AFortAthenaVehicle::SetUseGravity(const bool bInUseGravity)
{
}

bool AFortAthenaVehicle::SetVehicleStencilHighlighted(AActor* PotentialVehicle, bool bHighlighted, int32 StencilValueOverride)
{
	return false;
}

void AFortAthenaVehicle::SetWaterDestructionDelay(const float NewWaterDestructionDelay)
{
}

void AFortAthenaVehicle::UpdateClientWithVehicleTestInput_Implementation(FVector LinearVelocity, FVector AngularVelocity)
{
}

void AFortAthenaVehicle::UseOrExitPressedFromSeat(const int32 FromSeatIndex)
{
}

void AFortAthenaVehicle::UseOrExitReleasedFromSeat(const int32 FromSeatIndex)
{
}

bool AFortAthenaVehicle::VehicleIsInSkyTube() const
{
	return false;
}

void AFortAthenaVehicle::WakeUp()
{
}

void AFortAthenaVehicle::WakeUpOnGroundDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

bool AFortAthenaVehicle::WheelsOnGround() const
{
	return false;
}

void AFortAthenaVehicle::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaVehicle, NetPredictionProxy_AP);
	DOREPLIFETIME(AFortAthenaVehicle, NetPredictionProxy_SP);
	DOREPLIFETIME(AFortAthenaVehicle, SoftOverrideItemWrap);
	DOREPLIFETIME(AFortAthenaVehicle, SquadID);
	DOREPLIFETIME(AFortAthenaVehicle, TeamID);
	DOREPLIFETIME(AFortAthenaVehicle, bPlayInstantDeathEffects);
	DOREPLIFETIME(AFortAthenaVehicle, bHasDriver);
	DOREPLIFETIME(AFortAthenaVehicle, bHasPassengers);
	DOREPLIFETIME(AFortAthenaVehicle, bServerIsInUndergroundVolume);
	DOREPLIFETIME(AFortAthenaVehicle, bEnforceTeamRestrictionForMiniGame);
	DOREPLIFETIME(AFortAthenaVehicle, bEnforceMinigameClassRestriction);
	DOREPLIFETIME(AFortAthenaVehicle, bEnforceTeamRestriction);
	DOREPLIFETIME(AFortAthenaVehicle, bMoveStickAcceleratesVehicles);
	DOREPLIFETIME(AFortAthenaVehicle, MinigameClassID);
	DOREPLIFETIME(AFortAthenaVehicle, AppliedVehicleModTags);
	DOREPLIFETIME(AFortAthenaVehicle, EmptyDriverInputState);
	DOREPLIFETIME(AFortAthenaVehicle, SurfaceTypeVehicleOn);
	DOREPLIFETIME(AFortAthenaVehicle, RuntimeModifiedProperties);
	DOREPLIFETIME(AFortAthenaVehicle, VehicleAttributes);
	DOREPLIFETIME(AFortAthenaVehicle, IgnoredBuildingActors);
	DOREPLIFETIME(AFortAthenaVehicle, DamageableParts);
	DOREPLIFETIME(AFortAthenaVehicle, ToggledParts);
	DOREPLIFETIME(AFortAthenaVehicle, CorrectTargetOrientation);
	DOREPLIFETIME(AFortAthenaVehicle, AbilitySystemComponent);
	DOREPLIFETIME(AFortAthenaVehicle, HealthSet);
	DOREPLIFETIME(AFortAthenaVehicle, bShouldSleepAtSpawn);
	DOREPLIFETIME(AFortAthenaVehicle, bSpawnedSleepLockActive);
	DOREPLIFETIME(AFortAthenaVehicle, ForceKinematicOnClientCount);
	DOREPLIFETIME(AFortAthenaVehicle, bExploded);
	DOREPLIFETIME(AFortAthenaVehicle, bPendingDeath);
	DOREPLIFETIME(AFortAthenaVehicle, bOnFire);
	DOREPLIFETIME(AFortAthenaVehicle, TireStates);
	DOREPLIFETIME(AFortAthenaVehicle, ActiveGameplayEffectGrantedTagsToForceRemove);
}

UAbilitySystemComponent* AFortAthenaVehicle::GetAbilitySystemComponent() const
{
	return nullptr;
}

void AFortAthenaVehicle::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
}
