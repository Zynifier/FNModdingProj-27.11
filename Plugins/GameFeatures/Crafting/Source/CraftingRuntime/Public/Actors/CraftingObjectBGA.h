// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Building/BuildingGameplayActor.h"
#include "Items/FortInventoryOwnerInterface.h"
#include "CraftingObjectBGA.generated.h"

class AActor;
class AFortInventory;
class UPrimitiveComponent;
class USphereComponent;
class UStaticMeshComponent;
class UUserWidget;
class UWidgetComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class CRAFTINGRUNTIME_API ACraftingObjectBGA : public ABuildingGameplayActor, public IFortInventoryOwnerInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(Replicated)
	TObjectPtr<AFortInventory> Inventory;

	UPROPERTY(VisibleAnywhere, Export, Category="Crafting | UI", meta=(EditInline="true"))
	TObjectPtr<USphereComponent> SphereComponent_InteractionRange;

	UPROPERTY(EditAnywhere, Category="Crafting | UI")
	TSoftClassPtr<UUserWidget> MenuWidget;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Crafting | UI", meta=(EditInline="true"))
	TObjectPtr<UWidgetComponent> WidgetComponent_PotContents;

	UPROPERTY(EditDefaultsOnly, Category="Crafting | UI")
	bool bShowCraftingUI;

	UPROPERTY(EditDefaultsOnly, Category="Crafting | UI")
	bool bSendEventMessageOnLocalInteract;

	UPROPERTY(VisibleAnywhere, Export, Category="Visual", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> CraftingObjectMesh;

private:
	UFUNCTION()
	void HandleInteractionRangeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void HandleInteractionRangeEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};

