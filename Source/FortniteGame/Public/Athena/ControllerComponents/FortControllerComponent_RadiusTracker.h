// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_RadiusTracker.generated.h"

class AActor;
class UFortControllerComponent_RadiusTracker;
class UFortMiniMapRadiusTrackerIndicator;
class UMaterialInstanceDynamic;
class UMaterialInterface;

USTRUCT()
struct FRadiusTrackingDisplayInfo : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(NotReplicated)
	TObjectPtr<AActor> TrackedActor;

	UPROPERTY()
	FVector2D TrackedCenter;

	UPROPERTY()
	float TrackedRadius;

	UPROPERTY()
	FLinearColor CircleColor;

	UPROPERTY()
	float MaxDistance;

	UPROPERTY()
	TObjectPtr<UMaterialInterface> CircleMaterial;

	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> MiniMapMID;

	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> FullMapMID;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_RadiusTracker> RadiusTrackerComponent;

};

USTRUCT()
struct FRadiusTrackingDisplayInfoArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FRadiusTrackingDisplayInfo> Items;

};

UCLASS(Config=Game, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_RadiusTracker : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void OnRep_TrackingDisplayInfos();

	UFUNCTION()
	virtual void UpdateTrackingDisplayIndicators();

private:
	UPROPERTY(Transient, ReplicatedUsing=OnRep_TrackingDisplayInfos)
	FRadiusTrackingDisplayInfoArray TrackingDisplayInfos;

	UPROPERTY(Transient)
	TObjectPtr<UFortMiniMapRadiusTrackerIndicator> RadiusTrackerIndicator;

};

