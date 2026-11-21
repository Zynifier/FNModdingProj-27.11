// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortVehicleInterface.h"

void IFortVehicleInterface::AddVehicleActionNamesAndLabels(AFortPlayerPawn* FortPlayerPawn, TArray<FName>& SeatActionNames, TArray<FText>& SeatActionLabels)
{
}

bool IFortVehicleInterface::AllowsDamageFromOtherVehicle() const
{
	return false;
}

UMaterialInstanceDynamic* IFortVehicleInterface::ApplyMaterialAndUseWrapIfPossible(UMaterialInterface* MaterialToUse, int32 SlotIndex, bool bAlwaysCreateMID)
{
	return nullptr;
}

void IFortVehicleInterface::ApplyTireMod(const FGameplayTag& NewTireModTag, const AFortPlayerController* EventInstigator)
{
}

void IFortVehicleInterface::ApplyVehicleMod(const FGameplayTag& ModTag, const AFortPlayerController* EventInstigator)
{
}

bool IFortVehicleInterface::AreAnyTiresPopped() const
{
	return false;
}

bool IFortVehicleInterface::BlocksBuilding() const
{
	return false;
}

TArray<AFortPlayerPawn*> IFortVehicleInterface::BP_GetAllPassengers() const
{
	return TArray<AFortPlayerPawn*>();
}

void IFortVehicleInterface::CallGunOverheat(UFortVehicleSeatWeaponComponent* WeaponComponent)
{
}

void IFortVehicleInterface::CallWeaponFired(UFortVehicleSeatWeaponComponent* WeaponComponent, float Overheat)
{
}

bool IFortVehicleInterface::CanApplyMod(const FGameplayTag& InTag) const
{
	return false;
}

bool IFortVehicleInterface::CanContainPlayers() const
{
	return false;
}

bool IFortVehicleInterface::CanShootFromSeat(const int32 SeatIndex) const
{
	return false;
}

bool IFortVehicleInterface::CanTeleport() const
{
	return false;
}

void IFortVehicleInterface::ChangeSeat()
{
}

void IFortVehicleInterface::ChangeSeatFromIndex(const int32 FromSeatIndex)
{
}

bool IFortVehicleInterface::ClientIsDriver() const
{
	return false;
}

bool IFortVehicleInterface::ContainsPlayers() const
{
	return false;
}

void IFortVehicleInterface::DestroyVehicle()
{
}

void IFortVehicleInterface::DisableTrickCredit(float Duration)
{
}

bool IFortVehicleInterface::DoAltimeterTrace(FHitResult& HitResult, const FName TraceFromSocketName) const
{
	return false;
}

bool IFortVehicleInterface::DoesVehicleDamageFriendlyVehicles() const
{
	return false;
}

bool IFortVehicleInterface::DoesVehicleDamageOtherVehicles() const
{
	return false;
}

bool IFortVehicleInterface::DoesVehicleDamageOwnVehicle() const
{
	return false;
}

void IFortVehicleInterface::EjectAllPlayers()
{
}

bool IFortVehicleInterface::EjectPlayerPawn(const AFortPlayerPawn* InPlayerPawn)
{
	return false;
}

bool IFortVehicleInterface::EjectSeat(const int32 SeatIndex)
{
	return false;
}

void IFortVehicleInterface::ExitActivatedFromSeat(const int32 FromSeatIndex)
{
}

void IFortVehicleInterface::ExitPressedFromSeat(const int32 FromSeatIndex)
{
}

void IFortVehicleInterface::ExitReleasedFromSeat(const int32 FromSeatIndex)
{
}

int32 IFortVehicleInterface::FindSeatIndex(const AFortPlayerPawn* PlayerPawn) const
{
	return int32();
}

void IFortVehicleInterface::ForceDestroyVehicle(const bool bInPlayInstantDeathEffects)
{
}

bool IFortVehicleInterface::GasPedalIsDown() const
{
	return false;
}

void IFortVehicleInterface::GatherAndAssignAssembledMeshParts()
{
}

TArray<AFortPlayerPawn*> IFortVehicleInterface::GetAllNonDriverPassengers() const
{
	return TArray<AFortPlayerPawn*>();
}

AActor* IFortVehicleInterface::GetChildActorByClass(TSubclassOf<AActor> ActorClass) const
{
	return nullptr;
}

FVector IFortVehicleInterface::GetCrouchingFiringOffsetForSeat(const int32 SeatIndex) const
{
	return FVector();
}

FString IFortVehicleInterface::GetDisplayName() const
{
	return FString();
}

AFortPlayerPawn* IFortVehicleInterface::GetDriver() const
{
	return nullptr;
}

FTransform IFortVehicleInterface::GetExitSocketTransform(const int32 SeatIndex, const int32 SocketIndex) const
{
	return FTransform();
}

bool IFortVehicleInterface::GetForcedToAlwaysSpawn() const
{
	return false;
}

float IFortVehicleInterface::GetForwardSpeedKmh() const
{
	return float();
}

float IFortVehicleInterface::GetForwardSpeedPercent() const
{
	return float();
}

float IFortVehicleInterface::GetFuel() const
{
	return float();
}

float IFortVehicleInterface::GetFuelCapacity() const
{
	return float();
}

FGameplayTagContainer IFortVehicleInterface::GetGameplayTags() const
{
	return FGameplayTagContainer();
}

float IFortVehicleInterface::GetHealth() const
{
	return float();
}

float IFortVehicleInterface::GetHUDTopSpeed() const
{
	return float();
}

FVector IFortVehicleInterface::GetIndicatorRelativeOffset() const
{
	return FVector();
}

float IFortVehicleInterface::GetMaxHealth() const
{
	return float();
}

int32 IFortVehicleInterface::GetNumTires() const
{
	return int32();
}

FVector IFortVehicleInterface::GetOwnerLocation() const
{
	return FVector();
}

AFortPlayerPawn* IFortVehicleInterface::GetPawnAtSeat(const int32 SeatIndex) const
{
	return nullptr;
}

FString IFortVehicleInterface::GetPlayerFacingName() const
{
	return FString();
}

float IFortVehicleInterface::GetPreviousForwardSpeedKmh() const
{
	return float();
}

float IFortVehicleInterface::GetSeatSwitchCooldown(const int32 SeatIndex) const
{
	return float();
}

UFortVehicleSeatWeaponComponent* IFortVehicleInterface::GetSeatWeaponComponent(const int32 SeatIndex) const
{
	return nullptr;
}

bool IFortVehicleInterface::GetShootingCone(const int32 SeatIndex, FTransform& OutConeTM, FAthenaVehicleShootingCone& OutCone) const
{
	return false;
}

USkeletalMeshComponent* IFortVehicleInterface::GetSkeletalMeshComponent() const
{
	return nullptr;
}

FVector IFortVehicleInterface::GetStandingFiringOffsetForSeat(const int32 SeatIndex) const
{
	return FVector();
}

float IFortVehicleInterface::GetThrottle() const
{
	return float();
}

UAbilitySystemComponent* IFortVehicleInterface::GetVehicleAbilitySystemComponent() const
{
	return nullptr;
}

AActor* IFortVehicleInterface::GetVehicleActorPtr()
{
	return nullptr;
}

AActor* IFortVehicleInterface::GetVehicleActorPtrConst() const
{
	return nullptr;
}

FName IFortVehicleInterface::GetVehicleChangeSeatActionName(AFortPlayerPawn* FortPlayerPawn) const
{
	return FName();
}

const UFortVehicleConfigs* IFortVehicleInterface::GetVehicleConfigs() const
{
	return nullptr;
}

AFortPlayerControllerZone* IFortVehicleInterface::GetVehicleController(AFortPlayerPawn* PlayerPawn) const
{
	return nullptr;
}

FName IFortVehicleInterface::GetVehicleExitActionName(AFortPlayerPawn* FortPlayerPawn) const
{
	return FName();
}

FVector IFortVehicleInterface::GetVehicleForwardVector() const
{
	return FVector();
}

UFortVehicleFuelComponent* IFortVehicleInterface::GetVehicleFuelComponent() const
{
	return nullptr;
}

float IFortVehicleInterface::GetVehicleFuelPercent() const
{
	return float();
}

AFortPlayerStateZone* IFortVehicleInterface::GetVehiclePlayerState(const AFortPlayerPawn* PlayerPawn) const
{
	return nullptr;
}

UFortVehiclePontoonsComponent* IFortVehicleInterface::GetVehiclePontoonsComponent() const
{
	return nullptr;
}

TSubclassOf<UFortGameplayAbility> IFortVehicleInterface::GetVehiclePrimaryFireAbility() const
{
	return TSubclassOf<UFortGameplayAbility>();
}

FName IFortVehicleInterface::GetVehiclePrimaryFireActionName() const
{
	return FName();
}

FVector IFortVehicleInterface::GetVehicleRightVector() const
{
	return FVector();
}

FRotator IFortVehicleInterface::GetVehicleRotation() const
{
	return FRotator();
}

FText IFortVehicleInterface::GetVehicleSeatChoiceDisplayText(const int32 SeatIndex) const
{
	return FText();
}

UFortVehicleSeatComponent* IFortVehicleInterface::GetVehicleSeatComponentPtr()
{
	return nullptr;
}

FName IFortVehicleInterface::GetVehicleSecondaryFireActionName() const
{
	return FName();
}

const FGameplayTagContainer& IFortVehicleInterface::GetVehicleTags() const
{
	static FGameplayTagContainer Dummy;
	return Dummy;
}

FVector IFortVehicleInterface::GetVehicleVelocity() const
{
	return FVector();
}

float IFortVehicleInterface::GetWaterDepth() const
{
	return float();
}

void IFortVehicleInterface::GetWheelFXSockets(TArray<FVehicleWheelFXSocketInfo>& OutSockets) const
{
}

bool IFortVehicleInterface::HasDriver() const
{
	return false;
}

bool IFortVehicleInterface::HasEverContainedPlayers() const
{
	return false;
}

const bool IFortVehicleInterface::HasInfiniteFuel() const
{
	return bool();
}

bool IFortVehicleInterface::HasPermissionToAlterBuildings() const
{
	return false;
}

bool IFortVehicleInterface::HasSeatCollision(const int32 SeatIndex)
{
	return false;
}

bool IFortVehicleInterface::HasTireMod() const
{
	return false;
}

bool IFortVehicleInterface::HasVehicleModApplied(const FGameplayTag& ModTag) const
{
	return false;
}

void IFortVehicleInterface::ImpulseVehicle(const FVector& LinearVelocity, const FVector& AngularVelocity, const bool bRotateLinearVelocity, const bool bRotateAngularVelocity, const bool bAddToCurrent, const FName BoneName)
{
}

bool IFortVehicleInterface::IsAsleep() const
{
	return false;
}

bool IFortVehicleInterface::IsBoosting() const
{
	return false;
}

bool IFortVehicleInterface::IsDestructible() const
{
	return false;
}

bool IFortVehicleInterface::IsDisabled() const
{
	return false;
}

bool IFortVehicleInterface::IsDriverMinigameClassRestricted(const AFortPlayerPawn* PlayerPawn) const
{
	return false;
}

bool IFortVehicleInterface::IsIdling() const
{
	return false;
}

bool IFortVehicleInterface::IsInoperable() const
{
	return false;
}

bool IFortVehicleInterface::IsInWater() const
{
	return false;
}

bool IFortVehicleInterface::IsOffroad() const
{
	return false;
}

bool IFortVehicleInterface::IsOnDirt() const
{
	return false;
}

bool IFortVehicleInterface::IsOnGrass() const
{
	return false;
}

bool IFortVehicleInterface::IsOnIce() const
{
	return false;
}

bool IFortVehicleInterface::IsOnMud() const
{
	return false;
}

bool IFortVehicleInterface::IsOnRoad() const
{
	return false;
}

bool IFortVehicleInterface::IsOnSnow() const
{
	return false;
}

bool IFortVehicleInterface::IsPawnInSeatRequiringTargetingForShooting(const AFortPlayerPawn* PawnToCheck)
{
	return false;
}

bool IFortVehicleInterface::IsTeamRestricted(const AFortPlayerPawnAthena* InteractingPawn) const
{
	return false;
}

bool IFortVehicleInterface::IsTouchingGround() const
{
	return false;
}

bool IFortVehicleInterface::IsVehicleAcceleratingWithSpeedThreshold(const float MinSpeed, const float MaxSpeed) const
{
	return false;
}

bool IFortVehicleInterface::IsVehicleFuelEmpty() const
{
	return false;
}

bool IFortVehicleInterface::IsVehicleFuelLow() const
{
	return false;
}

void IFortVehicleInterface::MakeInoperable()
{
}

void IFortVehicleInterface::NotifyAudioComponentVehicleTriggered(UAudioComponent* AudioComponent, int32 Priority)
{
}

void IFortVehicleInterface::OverrideCurrentWrap(const UAthenaItemWrapDefinition* LoadedWrap)
{
}

bool IFortVehicleInterface::PlayerIsTryingToMoveForward() const
{
	return false;
}

void IFortVehicleInterface::RemoveAppliedTireMod()
{
}

void IFortVehicleInterface::RemoveVehicleMod(const FGameplayTag& ModTag)
{
}

void IFortVehicleInterface::ResetTrick()
{
}

bool IFortVehicleInterface::SeatIsTurret(const int32 SeatIndex) const
{
	return false;
}

void IFortVehicleInterface::SetActorBase(AActor* InActorBase, const int32 SeatIndex)
{
}

void IFortVehicleInterface::SetAttachedWheelDataMaterialInstance(const int32 TireIndex, UMaterialInstanceDynamic* NewValue)
{
}

void IFortVehicleInterface::SetCurrentFocusedSocketLocation(const int32 SeatIndex)
{
}

void IFortVehicleInterface::SetDestroyOnLastExit(bool bSetTo)
{
}

void IFortVehicleInterface::SetForcedToAlwaysSpawn(const bool bSetTo)
{
}

void IFortVehicleInterface::SetFuel(const float NewFuel)
{
}

void IFortVehicleInterface::SetHealthPercent(float Percent)
{
}

void IFortVehicleInterface::SetIgnoreAllFallingDamage(bool InIgnoreAllFallingDamage)
{
}

void IFortVehicleInterface::SetIgnoreNextFallingDamage(bool bInIgnoreNextFallingDamage)
{
}

void IFortVehicleInterface::SetShootingCone(const int32 SeatIndex, FAthenaVehicleShootingCone InCone)
{
}

void IFortVehicleInterface::SetVehicleFx(const FGameplayTag FxTag, const UFXSystemAsset* FxSystem)
{
}

void IFortVehicleInterface::SetVehicleFxMaterial(const FGameplayTag FxTag, const UMaterialInterface* FxMaterial)
{
}

bool IFortVehicleInterface::ShowVehicleHealthBarOnPlayerHUD() const
{
	return false;
}

void IFortVehicleInterface::TryConstructWithModServer(const FGameplayTagContainer& ForceMods)
{
}

bool IFortVehicleInterface::UsesVehicleFuelSystem() const
{
	return false;
}

void IFortVehicleInterface::VehicleGameplayCue_Damage(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters)
{
}

bool IFortVehicleInterface::VehicleIsInAir() const
{
	return false;
}

bool IFortVehicleInterface::VehicleIsInSkyTube() const
{
	return false;
}

void IFortVehicleInterface::WakeUp()
{
}
