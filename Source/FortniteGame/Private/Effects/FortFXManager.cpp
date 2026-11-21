// Copyright Epic Games, Inc. All Rights Reserved.

#include "Effects/FortFXManager.h"

void AFortFXManager::AddLightAnimationIntensity(UObject* WorldContextObject, ULightComponent* LightComp, float StartValue, float EndValue, UCurveFloat* LerpCurve, bool bOneMinusLerpValue, float Duration, bool bPlayReverse)
{
}

void AFortFXManager::AddMIDAnimationColor(UObject* WorldContextObject, UMaterialInstanceDynamic* MID, FName ParamName, const FLinearColor& StartValue, const FLinearColor& EndValue, UCurveFloat* LerpCurve, bool bOneMinusLerpValue, float Duration, bool bPlayReverse)
{
}

void AFortFXManager::AddMIDAnimationColorCurve(UObject* WorldContextObject, UMaterialInstanceDynamic* MID, FName ParamName, UCurveLinearColor* ColorCurve, float Duration, bool bPlayReverse)
{
}

void AFortFXManager::AddMIDAnimationFloat(UObject* WorldContextObject, UMaterialInstanceDynamic* MID, FName ParamName, float StartValue, float EndValue, UCurveFloat* LerpCurve, bool bOneMinusLerpValue, float Duration, bool bPlayReverse)
{
}

void AFortFXManager::AddParticleAnimationFloat(UObject* WorldContextObject, UParticleSystemComponent* ParticleSystemComp, FName ParamName, float StartValue, float EndValue, UCurveFloat* LerpCurve, bool bOneMinusLerpValue, float Duration, bool bPlayReverse)
{
}

void AFortFXManager::AddSplineMeshScaleAnimation(UObject* WorldContextObject, USplineMeshComponent* SplineMesh, float StartScaleStart, float StartScaleEnd, float EndScaleStart, float EndScaleEnd, UCurveFloat* LerpCurve, bool bOneMinusLerpValue, float Duration, bool bPlayReverse)
{
}

void AFortFXManager::AddSplineMeshSnapAnimation(UObject* WorldContextObject, const TArray<USplineMeshComponent*>& SplineMeshes, USplineComponent* TargetSpline, UCurveFloat* GrowthCurve, float Duration, bool bPlayGrowthReverse)
{
}

UMaterialInstanceDynamic* AFortFXManager::GetPickupRarityMID(AFortPickupEffect* PickupObject, UPrimitiveComponent* Component, int32 ElementIndex, int32 Rarity, bool& bNeedsToBeInitialized)
{
	return nullptr;
}

UMaterialInstanceDynamic* AFortFXManager::GetPickupStretchMIDFromPool(AFortPickupEffect* PickupObject, UMaterialInterface* SourceMaterial, UPrimitiveComponent* Component, int32 ElementIndex, bool& bNeedsToBeInitialized)
{
	return nullptr;
}

void AFortFXManager::OnPendingWeaponFXEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason)
{
}

void AFortFXManager::RemoveLightAnimations(UObject* WorldContextObject, ULightComponent* LightComp)
{
}

void AFortFXManager::RemoveMIDAnimations(UObject* WorldContextObject, UMaterialInstanceDynamic* MID)
{
}

void AFortFXManager::RemoveParticleAnimations(UObject* WorldContextObject, UParticleSystemComponent* ParticleSystemComp)
{
}

void AFortFXManager::RemoveSplineMeshAnimations(UObject* WorldContextObject, USplineMeshComponent* SplineMesh)
{
}

void AFortFXManager::ReturnFXActorToPool(UObject* WorldContextObject, AActor* FXActor)
{
}

void AFortFXManager::ReturnPickupStretchMIDToPool(AFortPickupEffect* PickupObject, UPrimitiveComponent* Component, int32 ElementIndex)
{
}

AActor* AFortFXManager::SpawnPooledFXActor(UObject* WorldContextObject, TSubclassOf<AActor> FXActorClass, const FTransform& SpawnTransform)
{
	return nullptr;
}
