// Copyright Epic Games, Inc. All Rights Reserved.

#include "Curie/FortCurieBlueprintFunctionLibrary.h"

UFortAsyncAction_OnCurieActivated* UFortAsyncAction_OnCurieActivated::OnCurieActivated(UObject* ContextObj)
{
	return nullptr;
}

void UFortCurieBlueprintFunctionLibrary::AddActorToCurieIgnoreTransformChanges(AActor* Actor)
{
}

void UFortCurieBlueprintFunctionLibrary::ChangeCurieContainerOwnership(AActor* SourceActor, AActor* TargetActor)
{
}

void UFortCurieBlueprintFunctionLibrary::CurieProtoMeshExtraction(TArray<FVector>& LocalVertLocs, UStaticMeshComponent* MeshComponent, int32 LOD, int32 VertDivisor)
{
}

void UFortCurieBlueprintFunctionLibrary::DisableElementAttachmentOnActor(AActor* TargetActor, FGameplayTag ElementTag)
{
}

void UFortCurieBlueprintFunctionLibrary::DisableElementDecayOnActor(AActor* TargetActor, FGameplayTag ElementTag)
{
}

void UFortCurieBlueprintFunctionLibrary::DisableElementInteractionOnActor(AActor* TargetActor, FGameplayTag ElementTag)
{
}

void UFortCurieBlueprintFunctionLibrary::DisableStateAttachmentOnActor(AActor* TargetActor, FGameplayTag StateTag)
{
}

void UFortCurieBlueprintFunctionLibrary::EnableElementAttachmentOnActor(AActor* TargetActor, FGameplayTag ElementTag)
{
}

void UFortCurieBlueprintFunctionLibrary::EnableElementDecayOnActor(AActor* TargetActor, FGameplayTag ElementTag)
{
}

void UFortCurieBlueprintFunctionLibrary::EnableElementInteractionOnActor(AActor* TargetActor, FGameplayTag ElementTag)
{
}

void UFortCurieBlueprintFunctionLibrary::EnableStateAttachmentOnActor(AActor* TargetActor, FGameplayTag StateTag)
{
}

FCurieInteractHandle UFortCurieBlueprintFunctionLibrary::ExecuteBeginFireInteract(UObject* WorldContextObject, AActor* Instigator, AActor* EffectCauser, AActor* Target, float Magnitude, const FHitResult& HitResult, int32 PropagationFuel, float LandscapeIgnitionRadius)
{
	return FCurieInteractHandle();
}

FCurieInteractHandle UFortCurieBlueprintFunctionLibrary::ExecuteBeginWaterInteract(UObject* WorldContextObject, AActor* Instigator, AActor* EffectCauser, AActor* Target, float Magnitude, const FHitResult& HitResult, float LandscapeExtinguishRadius)
{
	return FCurieInteractHandle();
}

bool UFortCurieBlueprintFunctionLibrary::ExecuteEndFireInteract(UObject* WorldContextObject, AActor* Target, FCurieInteractHandle InteractHandle)
{
	return false;
}

bool UFortCurieBlueprintFunctionLibrary::ExecuteEndWaterInteract(UObject* WorldContextObject, AActor* Target, FCurieInteractHandle InteractHandle)
{
	return false;
}

void UFortCurieBlueprintFunctionLibrary::ExecuteFireApplication(UObject* WorldContextObject, AActor* Instigator, AActor* EffectCauser, AActor* Target, float Magnitude, const FHitResult& HitResult, int32 PropagationFuel, float LandscapeIgnitionRadius)
{
}

void UFortCurieBlueprintFunctionLibrary::ExecuteIceApplication(UObject* WorldContextObject, AActor* Instigator, AActor* EffectCauser, AActor* Target, float Magnitude, const FHitResult& HitResult, int32 PropagationDepthLimit)
{
}

void UFortCurieBlueprintFunctionLibrary::ExecuteWaterApplication(UObject* WorldContextObject, AActor* Instigator, AActor* EffectCauser, AActor* Target, float Magnitude, const FHitResult& HitResult, float LandscapeExtinguishRadius)
{
}

void UFortCurieBlueprintFunctionLibrary::ExtinguishGrassInBounds(UObject* WorldContextObject, FBox IgnitionBounds)
{
}

FGameplayTagContainer UFortCurieBlueprintFunctionLibrary::GetAttachedCurieElements(AActor* Actor)
{
	return FGameplayTagContainer();
}

FGameplayTagContainer UFortCurieBlueprintFunctionLibrary::GetAttachedCurieStates(AActor* Actor)
{
	return FGameplayTagContainer();
}

UFortCurieManager* UFortCurieBlueprintFunctionLibrary::GetCurieManager(UObject* WorldContextObject)
{
	return nullptr;
}

void UFortCurieBlueprintFunctionLibrary::GetInstigatorInfoForAttachedElement(UObject* WorldContextObject, const FCurieContainerHandle& CurieContainerHandle, FGameplayTag ElementTag, AActor*& Instigator, AActor*& EffectCauser)
{
}

void UFortCurieBlueprintFunctionLibrary::GetInstigatorInfoFromInteractParams(const FCurieInteractParamsHandle& InteractParamsHandle, AActor*& Instigator, AActor*& EffectCauser)
{
}

AActor* UFortCurieBlueprintFunctionLibrary::GetLastElectricityPropagationParent(AActor* TargetActor)
{
	return nullptr;
}

bool UFortCurieBlueprintFunctionLibrary::HasCurieElementAttached(AActor* Actor, FGameplayTag ElementIdentifier)
{
	return false;
}

bool UFortCurieBlueprintFunctionLibrary::HasCurieStateAttached(AActor* Actor, FGameplayTag StateIdentifier)
{
	return false;
}

void UFortCurieBlueprintFunctionLibrary::IgniteGrassInBounds(UObject* WorldContextObject, AActor* Instigator, AActor* EffectCauser, FBox IgnitionBounds, int32 PropagationFuel)
{
}

bool UFortCurieBlueprintFunctionLibrary::IsCurieActive(UObject* WorldContextObject)
{
	return false;
}

bool UFortCurieBlueprintFunctionLibrary::IsCurieActiveForActor(AActor* Actor)
{
	return false;
}

bool UFortCurieBlueprintFunctionLibrary::IsCurieEnabled()
{
	return false;
}

void UFortCurieBlueprintFunctionLibrary::RemoveActorFromCurieIgnoreTransformChanges(AActor* Actor)
{
}
