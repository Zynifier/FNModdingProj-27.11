// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "GameplayTagContainer.h"
#include "CurieHandlersContainers.h"
#include "CurieMinimalTypes.h"
#include "CurieManager.generated.h"

class AActor;
class UCurieComponent;
class UCurieElementAllocationHandler;
class UCurieManagerComponent;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FCurieElementAttachedInternalSignature, UObject*, Owner, FCurieContainerHandle, ContainerHandle, const FGameplayTag&, ElementIdentifier);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FCurieElementAttachedSignature, UObject*, Owner, FCurieContainerHandle, ContainerHandle, const FGameplayTag&, ElementIdentifier);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FCurieElementBeginInteractInternalSignature, UObject*, Owner, FCurieContainerHandle, ContainerHandle, const FGameplayTag&, ElementIdentifier);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FCurieElementBeginInteractSignature, UObject*, Owner, FCurieContainerHandle, ContainerHandle, const FGameplayTag&, ElementIdentifier);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FCurieElementDetachedInternalSignature, UObject*, Owner, FCurieContainerHandle, ContainerHandle, const FGameplayTag&, ElementIdentifier);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FCurieElementDetachedSignature, UObject*, Owner, FCurieContainerHandle, ContainerHandle, const FGameplayTag&, ElementIdentifier);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FCurieElementEndInteractInternalSignature, UObject*, Owner, FCurieContainerHandle, ContainerHandle, const FGameplayTag&, ElementIdentifier);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FCurieElementEndInteractSignature, UObject*, Owner, FCurieContainerHandle, ContainerHandle, const FGameplayTag&, ElementIdentifier);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FCurieElementInteractInternalSignature, UObject*, Owner, FCurieContainerHandle, ContainerHandle, const FGameplayTag&, ElementIdentifier);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FCurieElementInteractSignature, UObject*, Owner, FCurieContainerHandle, ContainerHandle, const FGameplayTag&, ElementIdentifier);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FCurieStateAttachedInternalSignature, UObject*, Owner, FCurieContainerHandle, ContainerHandle, const FGameplayTag&, StateIdentifier);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FCurieStateAttachedSignature, UObject*, Owner, FCurieContainerHandle, ContainerHandle, const FGameplayTag&, StateIdentifier);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FCurieStateDetachedInternalSignature, UObject*, Owner, FCurieContainerHandle, ContainerHandle, const FGameplayTag&, StateIdentifier);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FCurieStateDetachedSignature, UObject*, Owner, FCurieContainerHandle, ContainerHandle, const FGameplayTag&, StateIdentifier);

USTRUCT()
struct FCurieElementPairKey
{
	GENERATED_BODY()


	CURIE_API bool operator==(const FCurieElementPairKey& Other) const;
	friend CURIE_API uint32 GetTypeHash(const FCurieElementPairKey& Value);
};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class CURIE_API UCurieManager : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UCurieManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, Category="Curie")
	void BindDelegateForCurieElementAttached(UObject* CurieOwner, const FCurieElementAttachedSignature& Delegate);

	UFUNCTION(BlueprintCallable, Category="Curie")
	void BindDelegateForCurieElementBeginInteract(UObject* CurieOwner, const FCurieElementBeginInteractSignature& Delegate);

	UFUNCTION(BlueprintCallable, Category="Curie")
	void BindDelegateForCurieElementDetached(UObject* CurieOwner, const FCurieElementDetachedSignature& Delegate);

	UFUNCTION(BlueprintCallable, Category="Curie")
	void BindDelegateForCurieElementEndInteract(UObject* CurieOwner, const FCurieElementEndInteractSignature& Delegate);

	UFUNCTION(BlueprintCallable, Category="Curie")
	void BindDelegateForCurieElementInteract(UObject* CurieOwner, const FCurieElementInteractSignature& Delegate);

	UFUNCTION(BlueprintCallable, Category="Curie")
	void BindDelegateForCurieStateAttached(UObject* CurieOwner, const FCurieStateAttachedSignature& Delegate);

	UFUNCTION(BlueprintCallable, Category="Curie")
	void BindDelegateForCurieStateDetached(UObject* CurieOwner, const FCurieStateDetachedSignature& Delegate);

	UFUNCTION(BlueprintCallable, Category="Curie")
	void UnbindDelegateForCurieElementAttached(UObject* CurieOwner, const FCurieElementAttachedSignature& Delegate);

	UFUNCTION(BlueprintCallable, Category="Curie")
	void UnbindDelegateForCurieElementBeginInteract(UObject* CurieOwner, const FCurieElementBeginInteractSignature& Delegate);

	UFUNCTION(BlueprintCallable, Category="Curie")
	void UnbindDelegateForCurieElementDetached(UObject* CurieOwner, const FCurieElementDetachedSignature& Delegate);

	UFUNCTION(BlueprintCallable, Category="Curie")
	void UnbindDelegateForCurieElementEndInteract(UObject* CurieOwner, const FCurieElementEndInteractSignature& Delegate);

	UFUNCTION(BlueprintCallable, Category="Curie")
	void UnbindDelegateForCurieElementInteract(UObject* CurieOwner, const FCurieElementInteractSignature& Delegate);

	UFUNCTION(BlueprintCallable, Category="Curie")
	void UnbindDelegateForCurieStateAttached(UObject* CurieOwner, const FCurieStateAttachedSignature& Delegate);

	UFUNCTION(BlueprintCallable, Category="Curie")
	void UnbindDelegateForCurieStateDetached(UObject* CurieOwner, const FCurieStateDetachedSignature& Delegate);

private:
	UFUNCTION()
	void HandleContainerOwnerDestroyed(AActor* OwnerActor);

	UPROPERTY(EditDefaultsOnly, Category="CurieManager")
	TSubclassOf<UCurieComponent> CurieComponentClass;

	UPROPERTY(EditDefaultsOnly, Category="CurieManager")
	FName CurieManagerRegistryName;

	UPROPERTY(EditDefaultsOnly, Category="CurieManager")
	FName MaterialDataRegistryName;

	UPROPERTY(EditDefaultsOnly, Category="CurieManager")
	FName ElementDataRegistryName;

	UPROPERTY(EditDefaultsOnly, Category="CurieManager")
	FName EntityStateDataRegistryName;

	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<UCurieElementAllocationHandler>> ElementAllocationHandlers;

	UPROPERTY(Transient)
	TMap<FGameplayTag, FCurieElementAttachHandlersContainer> ElementAttachmentHandlers;

	UPROPERTY(Transient)
	TMap<FGameplayTag, FCurieElementAttachConditionHandlersContainer> ElementAttachmentConditionHandlers;

	UPROPERTY(Transient)
	TMap<FCurieElementPairKey, FCurieElementInteractWithElementHandlersContainer> ElementInteractWithElementHandlers;

	UPROPERTY(Transient)
	TMap<FGameplayTag, FCurieElementInteractWithMaterialHandlersContainer> ElementInteractWithMaterialHandlers;

	UPROPERTY(Transient)
	TMap<FGameplayTag, FCurieElementInteractWithContainerHandlersContainer> ElementInteractWithContainerHandlers;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UCurieManagerComponent>> CurieManagerComponents;

};

