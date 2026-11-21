// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortSnapOnSurfaceComponent.generated.h"

class AActor;
class UFortSnapOnSurfaceComponent;
class UNavigationQueryFilter;

UENUM()
enum class EFortSnapOnSurfaceBehavior : int32
{
	None = 0,
	Landscape = 1,
	Navmesh = 2,
	Trace = 3,
	AttachTo = 4,
	SphereTrace = 5,
};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortSnapOnSurfaceComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnCurrentPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UFUNCTION(Category="SnapBehavior", meta=(CallInEditor="true"))
	void Snap();

	UFUNCTION()
	void Snap_AttachTo_Internal(UFortSnapOnSurfaceComponent* AttachToComponent, const FTransform& OldTransform, const FTransform& NewTransform);

	UPROPERTY(EditAnywhere, Category="SnapBehavior")
	EFortSnapOnSurfaceBehavior Behavior;

	UPROPERTY(EditAnywhere, Category="SnapBehavior", meta=(EditCondition="Behavior == EFortSnapOnSurfaceBehavior::Navmesh || Behavior == EFortSnapOnSurfaceBehavior::Trace || Behavior == EFortSnapOnSurfaceBehavior::SphereTrace", EditConditionHides))
	FVector MaxMovement;

	UPROPERTY(EditAnywhere, Category="SnapBehavior")
	FVector WorldOffset;

	UPROPERTY(EditAnywhere, Category="SnapBehavior")
	FVector LocalOffset;

	UPROPERTY(EditAnywhere, Category="SnapBehavior", meta=(EditCondition="Behavior == EFortSnapOnSurfaceBehavior::Navmesh", EditConditionHides))
	TSubclassOf<UNavigationQueryFilter> NavigationFilterClass;

	UPROPERTY(EditAnywhere, Category="SnapBehavior", meta=(EditCondition="(Behavior == EFortSnapOnSurfaceBehavior::Trace || Behavior == EFortSnapOnSurfaceBehavior::SphereTrace)", EditConditionHides))
	TEnumAsByte<ECollisionChannel> TraceChannel;

	UPROPERTY(EditAnywhere, Category="SnapBehavior", meta=(EditCondition="(Behavior == EFortSnapOnSurfaceBehavior::Trace || Behavior == EFortSnapOnSurfaceBehavior::SphereTrace)", EditConditionHides))
	TArray<TSoftObjectPtr<AActor>> IgnoredTraceActors;

	UPROPERTY(EditAnywhere, Category="SnapBehavior", meta=(EditCondition="Behavior == EFortSnapOnSurfaceBehavior::AttachTo", EditConditionHides))
	TSoftObjectPtr<AActor> AttachToActor;

	UPROPERTY(EditAnywhere, Category="SnapBehavior", meta=(EditCondition="(Behavior == EFortSnapOnSurfaceBehavior::Trace || Behavior == EFortSnapOnSurfaceBehavior::SphereTrace)", EditConditionHides))
	bool bOrientToNormal;

	UPROPERTY(EditAnywhere, Category="SnapBehavior", meta=(EditCondition="Behavior == EFortSnapOnSurfaceBehavior::Navmesh", EditConditionHides))
	bool bRemoveCellHeightOffset;

	UPROPERTY(EditAnywhere, Category="SnapBehavior", meta=(EditCondition="Behavior == EFortSnapOnSurfaceBehavior::Landscape", EditConditionHides))
	bool bOnlySnapIfBelowLandscape;

	UPROPERTY(EditAnywhere, Category="SnapBehavior")
	bool bRandomizeYaw;

	UPROPERTY(EditAnywhere, Category="SnapBehavior", meta=(EditCondition="Behavior == EFortSnapOnSurfaceBehavior::SphereTrace", EditConditionHides))
	float SphereRadius;

	UPROPERTY(EditAnywhere, Category="SnapBehavior", meta=(EditCondition="Behavior == EFortSnapOnSurfaceBehavior::SphereTrace", EditConditionHides))
	bool bUseImpactPoint;

};

