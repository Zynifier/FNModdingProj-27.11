// Copyright Epic Games, Inc. All Rights Reserved.

#include "Customization/CustomCosmeticModifierBase.h"

AFortPlayerPawn* ACustomCosmeticModifierBase::GetAssociatedPlayerPawn() const
{
	return nullptr;
}

FFortAthenaLoadout ACustomCosmeticModifierBase::GetLoadout()
{
	return FFortAthenaLoadout();
}

void ACustomCosmeticModifierBase::HandleMovementModeChanged(const ACharacter* Character, const EMovementMode PrevMovementMode, const uint8 PreviousCustomMode)
{
}

void ACustomCosmeticModifierBase::HandlePawnJumped()
{
}

void ACustomCosmeticModifierBase::HandlePawnLanded(const FHitResult& Hit)
{
}

void ACustomCosmeticModifierBase::HandleSetFirstPersonCameraOrPawnTargetingChanged(bool bChanged)
{
}

bool ACustomCosmeticModifierBase::IsInFrontEnd() const
{
	return false;
}

void ACustomCosmeticModifierBase::NativeEnteredVehicle()
{
}

void ACustomCosmeticModifierBase::NativeExitedVehicle()
{
}

void ACustomCosmeticModifierBase::NativeOnHitPawn(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
}

void ACustomCosmeticModifierBase::NativePawnCustomizationFinished(AFortPlayerPawn* PlayerPawn)
{
}

void ACustomCosmeticModifierBase::NativeWeaponFired(AFortWeapon* FiringWeapon)
{
}

void ACustomCosmeticModifierBase::OnExternalDependencyActorDestroyed(AActor* OtherActor)
{
}

void ACustomCosmeticModifierBase::OnNativeCurieAttached(UObject* CurieOwner, FCurieContainerHandle ContainerHandle, const FGameplayTag& Tag)
{
}

void ACustomCosmeticModifierBase::OnNativeCurieDetached(UObject* CurieOwner, FCurieContainerHandle ContainerHandle, const FGameplayTag& Tag)
{
}

void ACustomCosmeticModifierBase::OnPlayerWeaponChanged(AFortWeapon* NewWeapon, AFortWeapon* OldWeapon)
{
}

void ACustomCosmeticModifierBase::OnPostResIn_Implementation()
{
}

void ACustomCosmeticModifierBase::SetCosmeticActiveVariant(TSoftObjectPtr<UAthenaCosmeticItemDefinition> SoftCosmetic, const FGameplayTag& ChannelTag, const FGameplayTag& VariantTag)
{
}

UParticleSystemComponent* ACustomCosmeticModifierBase::SpawnEmitterAtLocationPartModifier(ECosmeticModifierOutExec& OutExec, UParticleSystem* EmitterTemplate, FVector Location, FRotator Rotation, FVector Scale, bool bAutoDestroy, EPSCPoolMethod PoolingMethod, bool bAutoActivateSystem, bool bMatchPawnCustomDepth, bool bDebounce, float DebounceTime)
{
	return nullptr;
}

UParticleSystemComponent* ACustomCosmeticModifierBase::SpawnEmitterAttachedPartModifier(ECosmeticModifierOutExec& OutExec, UParticleSystem* EmitterTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, FVector Scale, EAttachLocation::Type LocationType, bool bAutoDestroy, EPSCPoolMethod PoolingMethod, bool bAutoActivate, bool bMatchPawnCustomDepth, bool bDebounce, float DebounceTime)
{
	return nullptr;
}

UNiagaraComponent* ACustomCosmeticModifierBase::SpawnSystemAtLocationPartModifier(ECosmeticModifierOutExec& OutExec, UNiagaraSystem* SystemTemplate, FVector Location, FRotator Rotation, FVector Scale, bool bAutoDestroy, bool bAutoActivate, bool bOwnedByModifier, ENCPoolMethod PoolingMethod, bool bPreCullCheck, bool bMatchPawnCustomDepth, bool bDebounce, float DebounceTime)
{
	return nullptr;
}

UNiagaraComponent* ACustomCosmeticModifierBase::SpawnSystemAttachedPartModifier(ECosmeticModifierOutExec& OutExec, UNiagaraSystem* SystemTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, EAttachLocation::Type LocationType, bool bAutoDestroy, bool bAutoActivate, bool bOwnedByModifier, ENCPoolMethod PoolingMethod, bool bPreCullCheck, bool bMatchPawnCustomDepth, bool bDebounce, float DebounceTime)
{
	return nullptr;
}
