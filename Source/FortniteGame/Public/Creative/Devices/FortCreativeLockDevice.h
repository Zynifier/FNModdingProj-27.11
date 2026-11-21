// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingProp.h"
#include "FortCreativeLockDevice.generated.h"

class AFortPlayerController;
class APawn;

UENUM(BlueprintType)
enum class EFortLockDeviceVisibilityDuringGames : uint8
{
	No = 0,
	Yes = 1,
	HologramOnly = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLocalPawnInventoryChanged);

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class AFortCreativeLockDevice : public ABuildingProp
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void HandleLocalPawnEnterToPreviewArea(APawn* Pawn);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void HandleLocalPawnExitPreviewArea();

	UPROPERTY(BlueprintAssignable)
	FLocalPawnInventoryChanged OnLocalPawnInventoryChanged;

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCreativeLockDevice")
	TObjectPtr<AFortPlayerController> CachedLocalController;

};

