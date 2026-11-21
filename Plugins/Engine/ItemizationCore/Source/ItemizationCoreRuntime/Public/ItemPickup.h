// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "ItemPickup.generated.h"

class AItemPickup;
class UCapsuleComponent;
class UItemDefinitionBase;
class UObject;

/*
 * Structure of this class needs to be reworked to deal with being an engine plugin.
 * Consider reimplementing interfaces on a subclass on the game module.
 */
UCLASS(BlueprintType, Blueprintable)
class ITEMIZATIONCORERUNTIME_API AItemPickup : public AActor
{
	GENERATED_BODY()

private:
	// The collision capsule used to detect players collecting this pickup

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Collision", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UCapsuleComponent> TouchCapsule;

	// The type of item that is contained in this pickup.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item", meta=(AllowPrivateAccess="true"))
	TSoftObjectPtr<UItemDefinitionBase> ItemDefinition;

};

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemizationPickupFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Itemization")
	static AItemPickup* SpawnItemPickupInWorld(UObject* WorldContextObject, TSubclassOf<AItemPickup> ItemPickupClass, UItemDefinitionBase* ItemDefinition, const FVector& InPosition);

};

