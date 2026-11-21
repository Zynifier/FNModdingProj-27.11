// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/FortWeapon.h"
#include "FortWeap_BuildingToolBase.generated.h"

class AFortAthenaAIBotController;
class AFortPlayerController;
class UStaticMeshComponent;

UCLASS(Abstract, MinimalAPI, HideCategories=("Projectile", "Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortWeap_BuildingToolBase : public AFortWeapon
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	UStaticMeshComponent* GetPencilMeshComponent() const;

	UPROPERTY(EditAnywhere, Category="Mesh")
	FName BlueprintPaperSocket;

	UPROPERTY(EditAnywhere, Category="Mesh")
	FName BlueprintPencilSocket;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> InstigatorController;

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaAIBotController> InstigatorBotController;

private:
	UPROPERTY(VisibleAnywhere, Export, Category="Mesh", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UStaticMeshComponent> PencilMeshComponent;

};

