// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "Math/MathFwd.h"
#include "Building/BuildingTypes.h"
#include "Weapons/FortTrapTool.h"
#include "FortDecoTool_ContextTrap.generated.h"

class ABuildingSMActor;
class UFortContextTrapItemDefinition;

UCLASS(HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortDecoTool_ContextTrap : public AFortTrapTool
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void ServerCreateBuildingAndSpawnDeco_Implementation(FVector_NetQuantize10 BuildingLocation, FRotator BuildingRotation, FVector_NetQuantize10 Location, FRotator Rotation, EBuildingAttachmentType InBuildingAttachmentType, bool bSpawnDecoOnExtraPiece, FVector BuildingExtraPieceLocation);

	UFUNCTION()
	virtual void ServerSpawnDeco_Implementation(FVector Location, FRotator Rotation, ABuildingSMActor* AttachedActor, EBuildingAttachmentType InBuildingAttachmentType);

	UFUNCTION(BlueprintCallable)
	void SetContextTrapItemDefinition(const UFortContextTrapItemDefinition* InContextTrapItemDefinition);

protected:
	UPROPERTY(Transient, Replicated)
	TObjectPtr<UFortContextTrapItemDefinition> ContextTrapItemDefinition;

};

