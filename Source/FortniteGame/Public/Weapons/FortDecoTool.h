// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "Math/MathFwd.h"
#include "Building/BuildingTypes.h"
#include "Weapons/FortWeapon.h"
#include "FortDecoTool.generated.h"

class AActor;
class ABuildingSMActor;
class AFortDecoHelper;
class UFortItemDefinition;
class UParticleSystem;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortDecoTool : public AFortWeapon
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void OnUnEquip();

	UFUNCTION(BlueprintCallable)
	virtual void SetDecoObjectPreview(const UFortItemDefinition* InItemDefinition, bool bUpdatePreviewPosition = true);

	UFUNCTION(BlueprintCallable)
	void SetHelper(AFortDecoHelper* InHelper);

	UFUNCTION(BlueprintCallable)
	bool TryToPlace();

protected:
	UFUNCTION(Client, Reliable)
	void ClientDestroyDecoPreview();

	UFUNCTION()
	void OnRep_CarriedActor(AActor* OldCarriedActor);

	UFUNCTION()
	void OnRep_ItemDefinition();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCreateBuildingAndSpawnDeco(FVector_NetQuantize10 BuildingLocation, FRotator BuildingRotation, FVector_NetQuantize10 Location, FRotator Rotation, EBuildingAttachmentType InBuildingAttachmentType, bool bSpawnDecoOnExtraPiece, FVector BuildingExtraPieceLocation);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSpawnDeco(FVector Location, FRotator Rotation, ABuildingSMActor* AttachedActor, EBuildingAttachmentType InBuildingAttachmentType);

	UPROPERTY()
	bool bButtonDown;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ItemDefinition)
	TObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(Transient)
	TObjectPtr<AFortDecoHelper> DecoHelper;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CarriedActor)
	TObjectPtr<AActor> CarriedActor;

	UPROPERTY(Transient)
	bool bPlaceCarriedActor;

	UPROPERTY()
	TSoftObjectPtr<UParticleSystem> SpawnEffect;

	UPROPERTY(EditDefaultsOnly, Category="FortDecoTool")
	bool bPreventExecutionOnOwningPlayerFalling;

	UPROPERTY(Transient)
	bool bIsEquipped;

private:
	UFUNCTION()
	void OnCarriedActorDestroyed(AActor* DestroyedActor);

};

