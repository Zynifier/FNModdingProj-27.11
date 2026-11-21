// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "Engine/EngineTypes.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "FortGameStateComponent_RadiusTracker.generated.h"

class AActor;
class AController;
class AFortPlayerController;
class AFortPlayerPawn;
class AFortPlayerStateAthena;
class UFortGameStateComponent_RadiusTracker;
class UMaterialInterface;
class UObject;
class UPrimitiveComponent;
enum class ERadiusTrackingGroupingType : uint8;

UENUM(BlueprintType)
enum class ERadiusTrackingGroupingType : uint8
{
	// All players will use the same tracking info for this target. This is a good way to make sure all players receive the same tracking info.

	Global = 0,
	// All players on the same team will use this tracking info. Players on other teams will NOT have access to this data and will have to have their own tracking info

	Team = 1,
	// All players on the same squad will use this tracking info. Players on other squads will NOT have access to this data and will have to have their own tracking info

	Squad = 2,
};

USTRUCT(BlueprintType)
struct FRadiusTrackingGroupKey
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType, meta=(HasNativeBreak="/Script/FortniteGame.FortGameStateComponent_RadiusTracker.BreakRadiusTrackingInitializer", HasNativeMake="/Script/FortniteGame.FortGameStateComponent_RadiusTracker.MakeRadiusTrackingInitializer"))
struct FRadiusTrackingInitializer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RadiusTrackingInitializer")
	float MaxCenterOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RadiusTrackingInitializer")
	float MinimumRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RadiusTrackingInitializer")
	float MaximumRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RadiusTrackingInitializer")
	float MaximumDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RadiusTrackingInitializer")
	TObjectPtr<UMaterialInterface> CircleDrawingMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RadiusTrackingInitializer")
	float TimeBetweenUpdatesInSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RadiusTrackingInitializer")
	float RadiusAmountToShrinkEachUpdate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RadiusTrackingInitializer")
	FLinearColor CircleColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RadiusTrackingInitializer")
	ERadiusTrackingGroupingType GroupingType;

};

USTRUCT()
struct FRadiusTrackingInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FRadiusTrackingInitializer RadiusTrackingStaticValues;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_RadiusTracker : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UFortGameStateComponent_RadiusTracker(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Fortnite", meta=(AdvancedDisplay="1", DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	FRadiusTrackingGroupKey AddActorTrackingInfo(const FRadiusTrackingInitializer& RadiusTrackingInitializer);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Radius Tracker")
	void AddOwnerSquadMemberIndexFromTracking(AActor* TrackedActor, const AFortPlayerController* PlayerTrackingActor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Radius Tracker")
	static void AddToInitializerOwnerSquadMemberIndex(FRadiusTrackingInitializer& RadiusTrackerInitializer, AFortPlayerStateAthena* PlayerToAdd);

	UFUNCTION(BlueprintCallable, Category="Radius Tracker", meta=(NativeBreakFunc))
	static void BreakRadiusTrackingInitializer(const FRadiusTrackingInitializer& RadiusTrackingInitializer, float& MaxCenterOffset, float& MinimumRadius, float& MaximumRadius, float& TimeBetweenUpdatesInSeconds, float& RadiusAmountToShrinkEachUpdate, FLinearColor& CircleColor, UMaterialInterface*& CircleDrawingMaterial, AActor*& ActorTarget, TArray<AFortPlayerController*>& TargetTrackers, ERadiusTrackingGroupingType& GroupingType);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Radius Tracker", meta=(AdvancedDisplay="1", DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static UFortGameStateComponent_RadiusTracker* GetGameStateRadiusTrackerComponent(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="Radius Tracker", meta=(NativeMakeFunc))
	static FRadiusTrackingInitializer MakeRadiusTrackingInitializer(float MaxCenterOffset, float MinimumRadius, float MaximumRadius, float TimeBetweenUpdatesInSeconds, float RadiusAmountToShrinkEachUpdate, FLinearColor CircleColor, UMaterialInterface* CircleDrawingMaterial, AActor* ActorTarget, TArray<AFortPlayerController*> TargetTrackers, ERadiusTrackingGroupingType GroupingType = ERadiusTrackingGroupingType::Team, float MaximumDistance = 0.000000f);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Radius Tracker")
	static bool RemoveFromInitializerOwnerSquadMemberIndex(FRadiusTrackingInitializer& RadiusTrackerInitializer, AFortPlayerStateAthena* PlayerToRemove);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Radius Tracker")
	bool RemoveOwnerSquadMemberIndexFromTracking(AActor* TrackedActor, const AFortPlayerController* PlayerTrackingActor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Radius Tracker")
	void RemoveTrackingForActor(AActor* TrackedActor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Radius Tracker")
	void RemoveTrackingForActorAndTrackingKey(AActor* TrackedActor, FRadiusTrackingGroupKey TrackingKey);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Radius Tracker")
	void RemoveTrackingForActorFromPlayer(AActor* TrackedActor, AFortPlayerController* PlayerTrackingActor, ERadiusTrackingGroupingType GroupingType = ERadiusTrackingGroupingType::Team);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Radius Tracker")
	void RemoveTrackingForActorFromTrackingGroup(AActor* TrackedActor, const AFortPlayerController* PlayerTrackingActor, ERadiusTrackingGroupingType GroupingType = ERadiusTrackingGroupingType::Team);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Radius Tracker")
	void SetRadiusTrackingViewersFromPlayerPawns(FRadiusTrackingInitializer& RadiusTrackingInitializer, const FRadiusTrackingInitializer& RadiusTrackingInitializerInput, const TArray<AFortPlayerPawn*>& ViewerPawns);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Radius Tracker")
	bool UpdateRadiusTrackingSizes(AActor* ActorTarget, float MaxCenterOffset = 35000.000000f, float MinimumRadius = 1000.000000f, float MaximumRadius = 50000.000000f, float MaximumDistance = 0.000000f);

private:
	UFUNCTION()
	void OnTrackedActorDestroyed(AActor* DestroyedActor);

	UFUNCTION()
	void OnTrackedActorDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnTrackedActorEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UPROPERTY()
	TArray<TObjectPtr<AActor>> UpdateQueue;

};

