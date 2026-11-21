// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingGameplayActor.h"

bool ABuildingGameplayActor::AcceptsEmoteSprays_Implementation() const
{
	return false;
}

void ABuildingGameplayActor::DisableAbilityDeliveryInfo(FGameplayTag BucketTag)
{
}

void ABuildingGameplayActor::EnableAbilityDeliveryInfo(FGameplayTag BucketTag)
{
}

FTransform ABuildingGameplayActor::GetTargetingSourceTransform_Implementation(EFortAbilityTargetingSource Source) const
{
	return FTransform();
}

void ABuildingGameplayActor::HandleCleanupMoveIgnoreActor(AActor* EndPlayActor, EEndPlayReason::Type EndPlayReason)
{
}

void ABuildingGameplayActor::K2_AddGameplayCue(FGameplayTag GameplayCueTag, FGameplayEffectContextHandle Context)
{
}

void ABuildingGameplayActor::K2_AddGameplayCueWithParams(FGameplayTag GameplayCueTag, const FGameplayCueParameters& GameplayCueParameters)
{
}

void ABuildingGameplayActor::K2_ExecuteGameplayCue(FGameplayTag GameplayCueTag, FGameplayEffectContextHandle Context)
{
}

void ABuildingGameplayActor::K2_ExecuteGameplayCueWithParams(FGameplayTag GameplayCueTag, const FGameplayCueParameters& GameplayCueParameters)
{
}

void ABuildingGameplayActor::K2_RemoveGameplayCue(FGameplayTag GameplayCueTag)
{
}

void ABuildingGameplayActor::OnRegisteredTouchComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void ABuildingGameplayActor::OnRegisteredTouchComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void ABuildingGameplayActor::OverrideMarkerDisplayInfo(const FMarkedActorDisplayInfo& NewDisplayInfo)
{
}

void ABuildingGameplayActor::SetAbilitySourceLevel(int32 NewAbilitySourceLevel)
{
}

void ABuildingGameplayActor::SetIgnoreInstigatorCollision(bool bShouldIgnore)
{
}

void ABuildingGameplayActor::SetInitialVelocity(const FVector& InitialVelocity)
{
}

void ABuildingGameplayActor::SetTouchComponentForAbilityDeliveryInfo(UPrimitiveComponent* PrimitiveComponent)
{
}
