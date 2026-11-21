// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "Items/FortItemEntry.h"
#include "Weapons/Data/FortWeaponModData.h"
#include "FortWeaponModFunctionLibrary.generated.h"

class AFortPickup;
class AFortPlayerController;
class AFortPlayerStateAthena;
class AFortWeapon;
class UFortWeaponItemDefinition;
class UFortWeaponModItemDefinition;
class UFortWeaponModSetData;
class UObject;
class UStaticMesh;
class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FFortModDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortModDisplayData")
	FGameplayTag ModSlotTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortModDisplayData")
	TObjectPtr<UStaticMesh> ModMesh;

};

USTRUCT(BlueprintType)
struct FFortRemoveWeaponModResult
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortRemoveWeaponModResult")
	TObjectPtr<UFortWeaponModItemDefinition> ModDefinition;

};

UCLASS(MinimalAPI)
class UFortWeaponModFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	static void ApplyModSetToPickup(const UFortWeaponModSetData* ModSet, AFortPickup* WeaponPickup);

	UFUNCTION(BlueprintCallable)
	static bool ApplyWeaponModToPickup(AFortPickup* Pickup, UFortWeaponModItemDefinition* WeaponModItem);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	static void AssignPlayerNameToItemEntry(AFortPlayerStateAthena* PlayerState, UPARAM(ref) FFortItemEntry& ItemEntry);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	static void AssignPlayerNameToWeapon(AFortPlayerStateAthena* PlayerState, AFortWeapon* Weapon);

	UFUNCTION(BlueprintPure, meta=(DisplayName="Weapon Has Unoccupied Slot For Mod"))
	static bool CanApplyModToWeapon(const UFortWeaponModItemDefinition* WeaponModItem, AFortWeapon* Weapon);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	static UStaticMeshComponent* FindPreviewModMeshComponent(UFortWeaponModItemDefinition* WeaponModItem, AFortWeapon* PreviewWeapon);

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf="WorldContext", HidePin="WorldContext"))
	static TArray<FFortModDisplayData> GetModDisplayData(const UObject* WorldContext, const UFortWeaponItemDefinition* WeaponItemDefinition, const UFortWeaponModSetData* WeaponModSetData);

	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
	static FWeaponModStaticMeshData GetModStaticMeshDataForWeapon(const UObject* WorldContextObject, UFortWeaponModItemDefinition* WMID, UFortWeaponItemDefinition* WID);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, meta=(DefaultToSelf="WorldContext", HidePin="WorldContext"))
	static const UFortWeaponModSetData* GetRandomWeaponModSetData(const UObject* WorldContext, const UFortWeaponItemDefinition* WeaponItemDefinition);

	UFUNCTION(BlueprintCallable)
	static TArray<UFortWeaponModItemDefinition*> GetWeaponModsFromPickup(const AFortPickup* Pickup);

	UFUNCTION(BlueprintPure, Category="Weapon Tag Query")
	static bool ModAllowedOnWeapon(const UFortWeaponModItemDefinition* ModDefinition, const AFortWeapon* WeaponActor);

	UFUNCTION(BlueprintPure, Category="Weapon Tag Query")
	static bool ModAllowedOnWeaponDefinition(const UFortWeaponModItemDefinition* ModDefinition, const UFortWeaponItemDefinition* WeaponDefintion);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(WorldContext="WorldContextObject"))
	static AFortWeapon* SpawnWeaponModPreviewActor(const UObject* WorldContextObject, UFortWeaponItemDefinition* WeaponItemDef, FTransform Transform);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	static UStaticMeshComponent* TryAddPreviewWeaponMod(UFortWeaponModItemDefinition* WeaponModItem, AFortWeapon* PreviewWeapon);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	static bool TryAddWeaponMod(UFortWeaponModItemDefinition* WeaponModItem, AFortWeapon* Weapon);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	static TArray<FFortRemoveWeaponModResult> TryRemoveAllWeaponModsFromWeapon(AFortWeapon* Weapon);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	static bool TryRemovePreviewWeaponMod(UFortWeaponModItemDefinition* WeaponModItem, AFortWeapon* PreviewWeapon);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	static bool TryRemoveWeaponMod(UFortWeaponModItemDefinition* WeaponModItem, AFortWeapon* Weapon);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	static int32 TrySplitModsFromWeaponPickup(AFortPlayerController* PlayerController, AFortPickup* Pickup);

};

