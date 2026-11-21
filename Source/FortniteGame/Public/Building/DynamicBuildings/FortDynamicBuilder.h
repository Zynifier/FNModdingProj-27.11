// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingActor.h"
#include "FortDynamicBuilder.generated.h"

class ABuildingActor;
class AFortDynamicBuilder;
class UBillboardComponent;
class UFortBuildingInstructions;
class UObject;

UENUM()
namespace FDynamicBuildOrder
{
	enum Type
	{
		X = 0,
		Y = 1,
		Z = 2,
		None = 3,
	};
}

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBPDynamicBuilderFinishedSpawning, const TArray<ABuildingActor*>&, Buildings);

UCLASS(BlueprintType, HideCategories=("Input", "Replication", "Rendering", "Gameplay", "Navigation", "Culling", "Team", "Game|Damage"), SparseClassDataType=BuildingActorClassData)
class AFortDynamicBuilder : public ABuildingActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Fort Dynamic Builder|Statics", meta=(WorldContext="WorldContextObject", CPP_Default_BuildLocationOffset))
	static AFortDynamicBuilder* CreateBuilder(UObject* WorldContextObject, const FTransform& Transform, const UFortBuildingInstructions* BuildingInstructions, FVector BuildLocationOffset);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	TObjectPtr<UFortBuildingInstructions> BuildingInstructions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	bool bSelectiveDestruction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	bool bDestroyOverlapping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	bool bDestroyMatchingPiece;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	bool bNoCollisionFail;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	bool bIgnoreMissionActors;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	bool bShrinkAndDestroyEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	bool bDebugDrawBounds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	bool bUsePlayerBuildAnimations;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	float BuildingConstructionTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	TEnumAsByte<FDynamicBuildOrder::Type> BuildOrder;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Instructions")
	bool bReverseBuild;

	UPROPERTY(Transient)
	int32 OverrideOwnerPersistentId;

	UPROPERTY(BlueprintAssignable)
	FBPDynamicBuilderFinishedSpawning BPDynamicBuilderFinishedSpawning;

private:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Fort Dynamic Builder")
	void RemoveExistingActors();

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBillboardComponent> SpriteComponent;
#endif

	UPROPERTY(Transient)
	int32 CurrentIndex;

	UPROPERTY(Transient)
	TArray<TObjectPtr<ABuildingActor>> AllBuiltActors;

};

