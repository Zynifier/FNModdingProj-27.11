// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/FortGameplayAbility.h"

void UFortGameplayAbility::AddDynamicGameplayEffectContainer(FGameplayTag& ApplicationTag, FFortGameplayEffectContainer& Container)
{
}

void UFortGameplayAbility::AllowAIMovement(UGameplayAbility* OwningAbility)
{
}

FVector UFortGameplayAbility::ApplyAccuracyToTargetLocation(const FVector& SourceLocation, const FVector& TargetLocation, float inDesiredThrowAngle) const
{
	return FVector();
}

const TArray<FActiveGameplayEffectHandle> UFortGameplayAbility::ApplyGameplayEffectContainer(FGameplayAbilityTargetDataHandle TargetData, FGameplayTag ApplicationTag, int32 GameplayEffectLevel)
{
	return TArray<FActiveGameplayEffectHandle>();
}

const TArray<FActiveGameplayEffectHandle> UFortGameplayAbility::ApplyGameplayEffectContainerWithCSVStats(FGameplayAbilityTargetDataHandle TargetData, FGameplayTag ApplicationTag, int32 GameplayEffectLevel, const FString& StatName)
{
	return TArray<FActiveGameplayEffectHandle>();
}

bool UFortGameplayAbility::ApplySourcePropertyOverrides(TArray<FName>& OverriddenPropertyNames)
{
	return false;
}

FGameplayTagContainer UFortGameplayAbility::BP_GetCooldownTags() const
{
	return FGameplayTagContainer();
}

FFortGameplayEffectContainer UFortGameplayAbility::BP_GetGameplayEffectContainer(FGameplayTag ApplicationTag)
{
	return FFortGameplayEffectContainer();
}

void UFortGameplayAbility::BP_GetGameplayEffectContainers(FGameplayTag ApplicationTag, TArray<FFortGameplayEffectContainer>& OutContainers)
{
}

void UFortGameplayAbility::CalculateProjectileTrajectorySpline(TArray<FVector>& OutSplinePoints, TArray<FVector>& OutSplineTangents, float& OutSimulatedTotalTime, const AActor* Instigator, FVector InitialLocation, FVector InitialVelocity, float MaxSpeed, float Gravity, float Friction, float Bounciness, float TimeStep, float TraceExtent, ECollisionChannel TraceChannel, const TArray<AActor*>& ExtraActorsToIgnore, int32 MaxBounces, int32 MaxSteps, float MaxDistanceBetweenSplinePoints, float InitialDistance, const float LinearDamping, bool bReturnPhysicalMaterial)
{
}

void UFortGameplayAbility::CalculateProjectileTrajectorySplineProfile(TArray<FVector>& OutSplinePoints, TArray<FVector>& OutSplineTangents, float& OutSimulatedTotalTime, const AActor* Instigator, FVector InitialLocation, FVector InitialVelocity, float MaxSpeed, float Gravity, float Friction, float Bounciness, float TimeStep, float TraceExtent, FName CollisionProfile, const TArray<AActor*>& ExtraActorsToIgnore, int32 MaxBounces, int32 MaxSteps, float MaxDistanceBetweenSplinePoints, float InitialDistance, const float LinearDamping, bool bReturnPhysicalMaterial)
{
}

void UFortGameplayAbility::CalculateProjectileTrajectorySplineWithHit(FHitResult& OutHitResult, TArray<FVector>& OutSplinePoints, TArray<FVector>& OutSplineTangents, float& OutSimulatedTotalTime, const AActor* Instigator, FVector InitialLocation, FVector InitialVelocity, float MaxSpeed, float Gravity, float Friction, float Bounciness, float TimeStep, float TraceExtent, ECollisionChannel TraceChannel, const TArray<AActor*>& ExtraActorsToIgnore, int32 MaxBounces, int32 MaxSteps, float MaxDistanceBetweenSplinePoints, float InitialDistance, const float LinearDamping, bool bReturnPhysicalMaterial)
{
}

void UFortGameplayAbility::CalculateProjectileTrajectorySplineWithHitProfile(FHitResult& OutHitResult, TArray<FVector>& OutSplinePoints, TArray<FVector>& OutSplineTangents, float& OutSimulatedTotalTime, const AActor* Instigator, FVector InitialLocation, FVector InitialVelocity, float MaxSpeed, float Gravity, float Friction, float Bounciness, float TimeStep, float TraceExtent, FName CollisionProfile, const TArray<AActor*>& ExtraActorsToIgnore, int32 MaxBounces, int32 MaxSteps, float MaxDistanceBetweenSplinePoints, float InitialDistance, const float LinearDamping, bool bReturnPhysicalMaterial)
{
}

void UFortGameplayAbility::ClearAIFocalPoint(bool bUseAttackingPriority)
{
}

void UFortGameplayAbility::ClearTrackedActors(bool bDestroyActors)
{
}

void UFortGameplayAbility::ClearTrackedGroupedActors(FGameplayTag GroupTag, bool bDestroyActors)
{
}

bool UFortGameplayAbility::DoesTargetHaveProhibitedTagsForAI(const AActor* Target) const
{
	return false;
}

bool UFortGameplayAbility::DoesTargetHaveTags(const AActor* Target, const FGameplayTagContainer& Tags) const
{
	return false;
}

void UFortGameplayAbility::EquipAbilityWeapon(UFortWeaponItemDefinition* WeaponDefinition, int32 ItemLevel)
{
}

void UFortGameplayAbility::EquipVehicleWeapon(UFortWeaponItemDefinition* WeaponDefinition, const int32 SeatIndex, const int32 ItemLevel)
{
}

void UFortGameplayAbility::ForceCameraLookDown(APlayerController* PC)
{
}

FGameplayTagContainer UFortGameplayAbility::GetAbilityTags() const
{
	return FGameplayTagContainer();
}

float UFortGameplayAbility::GetAbilityTargetingLevel_Implementation() const
{
	return float();
}

UFortAbilitySystemComponent* UFortGameplayAbility::GetActivatingAbilityComponent() const
{
	return nullptr;
}

AFortPawn* UFortGameplayAbility::GetActivatingPawn() const
{
	return nullptr;
}

AActor* UFortGameplayAbility::GetAIAbilityTarget() const
{
	return nullptr;
}

FVector UFortGameplayAbility::GetAimLocationNearestPawn(AFortPawn* Instigator)
{
	return FVector();
}

AFortPlayerPawn* UFortGameplayAbility::GetAvatarAsFortPlayerPawn() const
{
	return nullptr;
}

void UFortGameplayAbility::GetAvatarAsValidFortPlayerPawn(EFortGetPlayerPawnExecutions& OutExec, AFortPlayerPawn*& OutFortPlayerPawn)
{
}

float UFortGameplayAbility::GetChargePercent() const
{
	return float();
}

EFortAbilityChargeState UFortGameplayAbility::GetChargeState() const
{
	return EFortAbilityChargeState();
}

float UFortGameplayAbility::GetChargeTime() const
{
	return float();
}

void UFortGameplayAbility::GetCurrentAbilitySourceLevel(float& OutSourceLevel) const
{
}

UFortWorldItemDefinition* UFortGameplayAbility::GetCurrentSourceItemDefinition() const
{
	return nullptr;
}

AFortWeapon* UFortGameplayAbility::GetCurrentSourceWeapon() const
{
	return nullptr;
}

UFortTooltipDisplayStatsList* UFortGameplayAbility::GetDisplayStats() const
{
	return nullptr;
}

FVector UFortGameplayAbility::GetFireLocation() const
{
	return FVector();
}

FRotator UFortGameplayAbility::GetFireRotation(bool bApplyLeading, bool bApplyInaccuracy, bool bApplyClampedMaxYawAngleToFire) const
{
	return FRotator();
}

int32 UFortGameplayAbility::GetMaxNumTrackedActors() const
{
	return int32();
}

int32 UFortGameplayAbility::GetOwningPlayerTeamPerkProgressiveActivationLevel() const
{
	return int32();
}

void UFortGameplayAbility::GetProjectileInitialValues(float& outProjectileSpeed, FRotator& outSpawnDirection, float& outProjectileGravity, AActor*& HomingTarget, bool bApplyInaccuracy, bool bApplyClampedMaxYawAngleToFire, bool bApplyLeading, float DesiredFlightTime) const
{
}

void UFortGameplayAbility::GetProjectileInitialValuesAndTargetLocation(AActor* AbilityTarget, FVector& outTargetLocation, float& outProjectileSpeed, FRotator& outSpawnDirection, float& outProjectileGravity, AActor*& HomingTarget, bool bApplyInaccuracy, bool bApplyClampedMaxYawAngleToFire, bool bApplyLeading, float DesiredFlightTime) const
{
}

TSubclassOf<UFortTooltip> UFortGameplayAbility::GetTooltip(bool bSummaryTooltip) const
{
	return TSubclassOf<UFortTooltip>();
}

TArray<AActor*> UFortGameplayAbility::GetTrackedActors() const
{
	return TArray<AActor*>();
}

TArray<AActor*> UFortGameplayAbility::GetTrackedGroupedActors(FGameplayTag GroupTag) const
{
	return TArray<AActor*>();
}

bool UFortGameplayAbility::IsChargeUpAbility() const
{
	return false;
}

bool UFortGameplayAbility::IsTargetOutsideOfMaxYawRotation() const
{
	return false;
}

void UFortGameplayAbility::K2_AbilityCompleted()
{
}

void UFortGameplayAbility::K2_OverrideFailedReason_Implementation(const FGameplayTagContainer& FailedReason, FGameplayTagContainer& OverridenFailedReason)
{
}

FFortGameplayEffectContainerSpec UFortGameplayAbility::MakeGameplayEffectContainerSpec(FGameplayTag ApplicationTag, int32 GameplayEffectLevel) const
{
	return FFortGameplayEffectContainerSpec();
}

void UFortGameplayAbility::MakeGameplayEffectContainerSpecs(FGameplayTag ApplicationTag, int32 GameplayEffectLevel, TArray<FFortGameplayEffectContainerSpec>& OutSpecContainers)
{
}

void UFortGameplayAbility::OnGenericNotifyFromAnimation_Implementation(FGameplayTag NotifyTag)
{
}

void UFortGameplayAbility::OnWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon)
{
}

void UFortGameplayAbility::PopCameraMode()
{
}

void UFortGameplayAbility::PushCameraMode(TSubclassOf<UFortCameraMode> CameraModeClass)
{
}

void UFortGameplayAbility::QueryGameplayEffectContainerTargetExecutionModifiers(FGameplayAbilityTargetDataHandle TargetData, const UFortAbilitySystemComponent* SrcAbilitySystem, FGameplayTag ApplicationTag, int32 GameplayEffectLevel, const UObject* SourceObject, const TArray<FGameplayEffectExecutionScopedModifierInfo>& InScopedMods, TArray<FActiveGameplayEffectHandle> InIgnoreHandles, TArray<FGameplayModifierEvaluatedData>& OutOutputModifiers, bool bTooltipRequest) const
{
}

void UFortGameplayAbility::SetAIFocalPoint(AActor* FocusTarget, FVector FocalPoint, bool bUseAttackingPriority)
{
}

bool UFortGameplayAbility::SetupPreviewImageOverride_Implementation()
{
	return false;
}

bool UFortGameplayAbility::ShouldPlayFailedMontage_Implementation(const FGameplayTagContainer& FailedReason) const
{
	return false;
}

void UFortGameplayAbility::TrackActor(AActor* ActorToTrack)
{
}

void UFortGameplayAbility::TrackGroupedActor(AActor* ActorToTrack, FGameplayTag GroupTag)
{
}
