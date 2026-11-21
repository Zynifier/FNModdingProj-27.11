// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingGameplayActor.h"
#include "Capture/FortCarriedObjectHolderInterface.h"
#include "BuildingFlagSpawn.generated.h"

class AFortCarriedObject;

UCLASS(HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingFlagSpawn : public ABuildingGameplayActor, public IFortCarriedObjectHolderInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="CarriedObject")
	bool IsSpawnedObjectAwayFromBase() const;

	UFUNCTION(BlueprintNativeEvent, Category="SpawnedObject")
	void OnCarriedObjectAttachedEvent();

	UFUNCTION(BlueprintNativeEvent, Category="SpawnedObject")
	void OnCarriedObjectDetachedEvent();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CarriedObject")
	void SpawnCarriedObject();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CarriedObject")
	float SpawnDelay;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HUD")
	FVector HUDIndicatorRelativeOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Team")
	uint8 bPickupOnTouch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CarriedObject")
	TSubclassOf<AFortCarriedObject> CarriedObjectClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CarriedObject", meta=(MakeEditWidget))
	FVector RelativeTranslation;

	UPROPERTY(Transient)
	TObjectPtr<AFortCarriedObject> SpawnedObject;

};

