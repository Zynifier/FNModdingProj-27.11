// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "Creative/FortCreativeItemTemplate.h"
#include "FortItemVariantHandle.h"
#include "FortPickupInstigatorInterface.h"
#include "FortPropertyOverrideReplication.h"
#include "Items/FortItemEntry.h"
#include "FortPickupInstigatorRegistryComponent.generated.h"

class AActor;
class AFortPawn;
class AFortPickup;
class APlayerController;
class IFortPickupEventHandler;
class UFortCreativeItemTemplate;
class UFortWorldItemDefinition;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPickupInstigatorDataUpdated, int32, TrackedIndex);

USTRUCT(BlueprintType)
struct FPickupInstigator : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="PickupInstigator")
	int32 TrackedIndex;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="PickupInstigator")
	FPickupInstigatorData InstigatorData;

};

USTRUCT()
struct FPickupInstigatorArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, Transient, Category="PickupInstigatorArray")
	TArray<FPickupInstigator> Items;

	UPROPERTY(Transient, NotReplicated)
	int32 NextTrackedIndex;

};

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Minigame"), meta=(BlueprintSpawnableComponent))
class UFortPickupInstigatorRegistryComponent : public UActorComponent, public IFortPropertyOverrideReplProvider
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="PickupInstigator")
	int32 AddPickupInstigator(UObject* PickupInstigator, int32 ItemIndex = 0, bool bItemTemplate = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="PickupInstigator")
	void ClearPickupInstigators();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="PickupInstigator")
	static void DestroyDroppedPickups(AActor* ActorContext, int32 TrackedIndex);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="PickupInstigator")
	static void DestroySpawnedPickups(AActor* ActorContext, int32 TrackedIndex);

	UFUNCTION(BlueprintPure, Category="PickupInstigator")
	static void GetDroppedPickups(AActor* ActorContext, int32 TrackedIndex, TArray<AFortPickup*>& DroppedPickups);

	UFUNCTION(BlueprintPure)
	bool GetInstigator(int32 TrackedIndex, FPickupInstigator& PickupInstigator) const;

	UFUNCTION(BlueprintPure)
	bool GetInstigatorData(int32 TrackedIndex, FPickupInstigatorData& InstigatorData) const;

	UFUNCTION(BlueprintPure)
	bool GetPickupEventHandler(int32 TrackedIndex, TScriptInterface<IFortPickupEventHandler>& EventHandler) const;

	UFUNCTION(BlueprintPure, Category="PickupInstigator")
	static void GetSpawnedPickups(AActor* ActorContext, int32 TrackedIndex, TArray<AFortPickup*>& SpawnedPickups);

	UFUNCTION(BlueprintPure, Category="Item Templates")
	bool GetTemplateData(int32 TrackedIndex, FCreativeItemTemplateData& TemplateData) const;

	UFUNCTION(BlueprintPure, Category="Item Templates")
	bool GetTemplateObjects(TArray<UFortCreativeItemTemplate*>& TemplateObjs, const FItemVariantHandle& VariantHandle, bool bOnlyEnabled = true) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="PickupInstigator")
	void NotifyItemCaptured(int32 TrackedIndex, APlayerController* PlayerController, const FFortItemEntry& ItemEntry);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="PickupInstigator")
	void NotifyItemRemoved(int32 TrackedIndex, APlayerController* PlayerController, const FFortItemEntry& ItemEntry);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="PickupInstigator")
	void NotifyPickupCaptured(int32 TrackedIndex, AFortPickup* Pickup);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="PickupInstigator")
	void NotifyPickupDropped(int32 TrackedIndex, AFortPickup* Pickup);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="PickupInstigator")
	void NotifyPickupSpawned(int32 TrackedIndex, AFortPickup* Pickup);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="PickupInstigator")
	void RemoveAllItemsForPickupInstigator(UObject* PickupInstigator);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="PickupInstigator")
	void RemovePickupInstigator(UObject* PickupInstigator, int32 ItemIndex = 0);

	UPROPERTY(BlueprintAssignable, Category="PickupInstigator")
	FPickupInstigatorDataUpdated OnPickupInstigatorDataChanged;

	UPROPERTY(BlueprintAssignable, Category="PickupInstigator")
	FPickupInstigatorDataUpdated OnPickupInstigatorDataRemoved;

	UPROPERTY(BlueprintAssignable, Category="Item Templates")
	FPickupInstigatorDataUpdated OnItemTemplateDataChanged;

	UPROPERTY(BlueprintAssignable, Category="Item Templates")
	FPickupInstigatorDataUpdated OnItemTemplateDataRemoved;

protected:
	UFUNCTION()
	void HandlePickupClaimed(AFortPickup* Pickup, AFortPawn* InteractingPawn, const UFortWorldItemDefinition* ItemDefinition, FVector PickupLocation);

	UFUNCTION()
	void HandlePickupDestroyed(AFortPickup* Pickup);

	UFUNCTION()
	void OnRep_ItemTemplateRegistry();

	UFUNCTION()
	void PostReplicateRepOverrides();

	UFUNCTION()
	void ResolvePendingRepOverrides();

	UPROPERTY(VisibleInstanceOnly, Transient, Replicated, Category="FortPickupInstigatorRegistryComponent")
	FPickupInstigatorArray InstigatorRegistry;

	UPROPERTY(VisibleInstanceOnly, Transient, ReplicatedUsing=OnRep_ItemTemplateRegistry, Category="FortPickupInstigatorRegistryComponent")
	FCreativeItemTemplateDataArray ItemTemplateRegistry;

};

