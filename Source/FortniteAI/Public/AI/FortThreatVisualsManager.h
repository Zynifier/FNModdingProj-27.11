// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "AI/ThreatVisuals/ThreatCloud.h"
#include "Environment/FortWindImpulse.h"
#include "FortInitializationInterface.h"
#include "FortThreatVisualsManager.generated.h"

class AActor;
class AFortThreatVisualsManager;
class AThreatCloud;
class UFortAIEncounterInfo;

USTRUCT()
struct FStormWind : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FVector Location;

	UPROPERTY(Transient)
	FVector Direction;

	UPROPERTY(Transient)
	float Radius;

	UPROPERTY(Transient)
	float Magnitude;

	UPROPERTY(Transient)
	TObjectPtr<AFortThreatVisualsManager> ThreatVisualsManager;

	UPROPERTY(Transient, NotReplicated)
	TArray<TObjectPtr<UFortAIEncounterInfo>> Encounters;

	UPROPERTY(Transient, NotReplicated)
	FFortWindImpulseHandle WindHandle;

};

USTRUCT()
struct FStormWindArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FStormWind> StormWinds;

};

USTRUCT()
struct FThreatGridIndex
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	int32 X;

	UPROPERTY(Transient)
	int32 Y;

};

USTRUCT(BlueprintType)
struct FThreatLocationInfo : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="ThreatLocationInfo")
	FVector CloudLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ThreatLocationInfo")
	FBox ThreatVolume;

	UPROPERTY(Transient)
	TObjectPtr<AFortThreatVisualsManager> ThreatVisualsManager;

	UPROPERTY(BlueprintReadOnly, Transient, NotReplicated, Category="ThreatLocationInfo")
	TWeakObjectPtr<AThreatCloud> CloudActor;

	UPROPERTY(Transient)
	bool bThreatActivated;

	UPROPERTY(Transient)
	EFortThreatDeactivationType DeactivationType;

};

USTRUCT()
struct FThreatLocationArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FThreatLocationInfo> Locations;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class AFortThreatVisualsManager : public AActor, public IFortInitializationInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(NetMulticast, Reliable)
	void BeginThreatVisualsPrecursor(AActor* SourceActor, FVector ThreatLocation);

	UFUNCTION(BlueprintPure, Category="ThreatVisuals")
	bool GetCloudsAreHidden() const;

	UFUNCTION(BlueprintPure, Category="ThreatVisuals")
	AThreatCloud* GetThreatCloud(const FThreatLocationInfo& ThreatLocInfo) const;

	UFUNCTION(BlueprintPure, Category="ThreatVisuals")
	const TArray<FThreatLocationInfo> GetThreatClouds() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="ThreatVisuals")
	void OnBeginThreatVisualsPrecursor(AActor* SourceActor, const FVector& EndLocation);

	UFUNCTION(BlueprintImplementableEvent, Category="ThreatVisuals")
	void OnThreatCloudsChanged(const TArray<FThreatLocationInfo>& ThreatLocationInfo);

	UFUNCTION(BlueprintCallable, Category="ThreatVisuals")
	void ResetMinimumCloudAltitude();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="ThreatVisuals")
	void SetCloudsAreHidden(bool bHide);

	UFUNCTION(BlueprintCallable, Category="ThreatVisuals")
	void SetMinimumCloudAltitude(float NewMinimumAltitude);

	UFUNCTION(BlueprintPure, Category="ThreatVisuals")
	bool StormsExist() const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnWorldReady();

private:
	UFUNCTION()
	void OnRep_GoalActorLocations();

	UFUNCTION()
	void OnRep_HideClouds();

	UFUNCTION()
	void OnRep_StormWinds();

	UFUNCTION()
	void OnRep_ThreatLocations();

	UPROPERTY(EditAnywhere, Category="ThreatCloud")
	TSubclassOf<AThreatCloud> CloudBlueprint;

	UPROPERTY(EditAnywhere, Category="ThreatCloud")
	float CloudRadius;

	UPROPERTY(EditAnywhere, Category="ThreatCloud")
	float ThreatBoxVolumeTopPadding;

	UPROPERTY(EditAnywhere, Category="ThreatCloud")
	float ThreatBoxVolumeBottomPadding;

	UPROPERTY(EditDefaultsOnly, Category="ThreatCloud")
	bool bUseLocalPlayersOnlyForCloudMinimumHeight;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_HideClouds)
	bool bHideClouds;

	UPROPERTY(EditDefaultsOnly, Category="ThreatCloud")
	float CloudMinimumHeightAbovePlayers;

	UPROPERTY(EditDefaultsOnly, Category="ThreatCloud")
	float CloudMinimumHeightAboveGround;

	UPROPERTY(EditDefaultsOnly, Category="ThreatCloud")
	float CloudMinimumAltitude;

	UPROPERTY(EditDefaultsOnly, Category="ThreatCloud", meta=(ClampMax="1000000.0", ClampMin="0.1", UIMax="1000000.0", UIMin="0.1"))
	float CloudMaxVerticalDelta;

	UPROPERTY(EditDefaultsOnly, Category="ThreatCloud", meta=(ClampMax="10000.0", ClampMin="1", UIMax="10000.0", UIMin="1"))
	float CloudMinSpeed;

	UPROPERTY(EditDefaultsOnly, Category="ThreatCloud", meta=(ClampMax="10000000.0", ClampMin="1", UIMax="10000000.0", UIMin="1"))
	float CloudMaxSpeed;

	UPROPERTY(EditDefaultsOnly, Category="StormWind")
	float StormWindCloudRadius;

	UPROPERTY(EditDefaultsOnly, Category="StormWind")
	float StormWindGoalRadius;

	UPROPERTY(EditDefaultsOnly, Category="StormWind")
	float StormWindFalloffRadius;

	UPROPERTY(EditDefaultsOnly, Category="StormWind")
	float StormWindInactiveMagnitude;

	UPROPERTY(EditDefaultsOnly, Category="StormWind")
	float StormWindActiveMagnitude;

	UPROPERTY(EditDefaultsOnly, Category="StormWind")
	float StormWindDesiredDeltaBlendTime;

	UPROPERTY(EditDefaultsOnly, Category="StormWind")
	float StormWindDirectionAdditionalAngle;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ThreatLocations)
	FThreatLocationArray ThreatLocations;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_StormWinds)
	FStormWindArray StormWindArray;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_GoalActorLocations)
	TArray<FVector> GoalActorLocations;

};

