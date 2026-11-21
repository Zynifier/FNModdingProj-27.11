// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Misc/Guid.h"
#include "Items/FortItemEntry.h"
#include "FortItemEntryComponent.generated.h"

class IFortInventoryOwnerInterface;

UCLASS(BlueprintType, Blueprintable, HideCategories=("ComponentReplication", "Activation", "Cooking", "AssetUserData", "Collision", "Sockets", "Tags"), meta=(BlueprintSpawnableComponent))
class UFortItemEntryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	bool AddItemToInventoryOwner(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, bool bUseItemPickupAnalyticEvent = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Empty();

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	int32 GetClipSize() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	int32 GetLoadedAmmo() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	const FFortItemEntry& GetOwnedItem() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool HasItem() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetOwnedItem(const FFortItemEntry& Item);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	bool TakeItemFromInventoryOwner(const FGuid& ItemGuid, const int32 Count, TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, const bool bTreatAsPickup = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	int32 TrySetLoadedAmmo(int32 NewAmmoAmount);

private:
	UPROPERTY()
	FFortItemEntry OwnedItemEntry;

};

