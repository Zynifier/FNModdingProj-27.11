// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "CurieInteractParams.h"
#include "CurieMinimalTypes.h"
#include "FortCurieBlueprintFunctionLibrary.generated.h"

class AActor;
class UFortAsyncAction_OnCurieActivated;
class UFortCurieManager;
class UObject;
class UStaticMeshComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCurieActivated_BP);

UCLASS()
class UFortAsyncAction_OnCurieActivated : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Curie", meta=(BlueprintInternalUseOnly="true", WorldContext="ContextObj"))
	static UFortAsyncAction_OnCurieActivated* OnCurieActivated(UObject* ContextObj);

	UPROPERTY(BlueprintAssignable)
	FOnCurieActivated_BP OnCurieActive;

private:
	UPROPERTY()
	TWeakObjectPtr<UObject> ContextObject;

};

UCLASS()
class UFortCurieBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie")
	static void AddActorToCurieIgnoreTransformChanges(AActor* Actor);

	UFUNCTION(BlueprintCallable, Category="Curie")
	static void ChangeCurieContainerOwnership(AActor* SourceActor, AActor* TargetActor);

	UFUNCTION(BlueprintCallable, Category="Curie|Prototype")
	static void CurieProtoMeshExtraction(TArray<FVector>& LocalVertLocs, UStaticMeshComponent* MeshComponent, int32 LOD, int32 VertDivisor = 16);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie")
	static void DisableElementAttachmentOnActor(AActor* TargetActor, FGameplayTag ElementTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie")
	static void DisableElementDecayOnActor(AActor* TargetActor, FGameplayTag ElementTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie")
	static void DisableElementInteractionOnActor(AActor* TargetActor, FGameplayTag ElementTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie")
	static void DisableStateAttachmentOnActor(AActor* TargetActor, FGameplayTag StateTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie")
	static void EnableElementAttachmentOnActor(AActor* TargetActor, FGameplayTag ElementTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie")
	static void EnableElementDecayOnActor(AActor* TargetActor, FGameplayTag ElementTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie")
	static void EnableElementInteractionOnActor(AActor* TargetActor, FGameplayTag ElementTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie")
	static void EnableStateAttachmentOnActor(AActor* TargetActor, FGameplayTag StateTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie", meta=(AutoCreateRefTerm="HitResult", DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static FCurieInteractHandle ExecuteBeginFireInteract(UObject* WorldContextObject, AActor* Instigator, AActor* EffectCauser, AActor* Target, float Magnitude, const FHitResult& HitResult, int32 PropagationFuel = -1, float LandscapeIgnitionRadius = 0.000000f);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie", meta=(AutoCreateRefTerm="HitResult", DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static FCurieInteractHandle ExecuteBeginWaterInteract(UObject* WorldContextObject, AActor* Instigator, AActor* EffectCauser, AActor* Target, float Magnitude, const FHitResult& HitResult, float LandscapeExtinguishRadius = 0.000000f);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool ExecuteEndFireInteract(UObject* WorldContextObject, AActor* Target, FCurieInteractHandle InteractHandle);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool ExecuteEndWaterInteract(UObject* WorldContextObject, AActor* Target, FCurieInteractHandle InteractHandle);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie", meta=(AutoCreateRefTerm="HitResult", DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void ExecuteFireApplication(UObject* WorldContextObject, AActor* Instigator, AActor* EffectCauser, AActor* Target, float Magnitude, const FHitResult& HitResult, int32 PropagationFuel = -1, float LandscapeIgnitionRadius = 0.000000f);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie", meta=(AutoCreateRefTerm="HitResult", DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void ExecuteIceApplication(UObject* WorldContextObject, AActor* Instigator, AActor* EffectCauser, AActor* Target, float Magnitude, const FHitResult& HitResult, int32 PropagationDepthLimit = -1);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie", meta=(AutoCreateRefTerm="HitResult", DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void ExecuteWaterApplication(UObject* WorldContextObject, AActor* Instigator, AActor* EffectCauser, AActor* Target, float Magnitude, const FHitResult& HitResult, float LandscapeExtinguishRadius = 0.000000f);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void ExtinguishGrassInBounds(UObject* WorldContextObject, FBox IgnitionBounds);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Curie")
	static FGameplayTagContainer GetAttachedCurieElements(AActor* Actor);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Curie")
	static FGameplayTagContainer GetAttachedCurieStates(AActor* Actor);

	UFUNCTION(BlueprintPure, Category="Curie", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static UFortCurieManager* GetCurieManager(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void GetInstigatorInfoForAttachedElement(UObject* WorldContextObject, const FCurieContainerHandle& CurieContainerHandle, FGameplayTag ElementTag, AActor*& Instigator, AActor*& EffectCauser);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie")
	static void GetInstigatorInfoFromInteractParams(const FCurieInteractParamsHandle& InteractParamsHandle, AActor*& Instigator, AActor*& EffectCauser);

	UFUNCTION(BlueprintCallable, Category="Curie")
	static AActor* GetLastElectricityPropagationParent(AActor* TargetActor);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Curie")
	static bool HasCurieElementAttached(AActor* Actor, FGameplayTag ElementIdentifier);

	UFUNCTION(BlueprintPure, Category="Curie")
	static bool HasCurieStateAttached(AActor* Actor, FGameplayTag StateIdentifier);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void IgniteGrassInBounds(UObject* WorldContextObject, AActor* Instigator, AActor* EffectCauser, FBox IgnitionBounds, int32 PropagationFuel = -1);

	UFUNCTION(BlueprintPure, Category="Curie", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool IsCurieActive(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Curie")
	static bool IsCurieActiveForActor(AActor* Actor);

	UFUNCTION(BlueprintPure, Category="Curie")
	static bool IsCurieEnabled();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Curie")
	static void RemoveActorFromCurieIgnoreTransformChanges(AActor* Actor);

};

