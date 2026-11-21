// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Building/BuildingActor.h"
#include "Building/TaggingVolumes/FortGameplayTagVolumeInterface.h"
#include "FortGameplayTagBuildingActor.generated.h"

class UBillboardComponent;
class UBoxComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Collision", "Culling", "Team", "Rendering", "Replication", "Gameplay", "Navigation", "Tags", "Input", "BuildingBounds", "Game|Damage"), SparseClassDataType=BuildingActorClassData)
class AFortGameplayTagBuildingActor : public ABuildingActor, public IFortGameplayTagVolumeInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TagsToApply")
	FGameplayTagContainer TagsToApplyOnSave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Size", meta=(ClampMax="100", ClampMin="1"))
	int32 XGridCells;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Size", meta=(ClampMax="100", ClampMin="1"))
	int32 YGridCells;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Size", meta=(ClampMax="100", ClampMin="1"))
	int32 ZGridCells;

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> BoxComponent;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBillboardComponent> SpriteComponent;
#endif

};

