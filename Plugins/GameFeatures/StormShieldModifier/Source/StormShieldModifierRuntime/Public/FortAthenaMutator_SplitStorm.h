// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/GameStateComponents/FortGameStateComponent_BattleRoyaleGamePhaseLogic.h"
#include "Athena/Modifiers/FortAthenaMutator_GameModeBase.h"
#include "FortAthenaMutator_SplitStorm.generated.h"

class AActor;
enum class ESplitStormProxyPhase : uint8;

UENUM(BlueprintType)
enum class ESplitStormProxyPhase : uint8
{
	None = 0,
	MovingToHold = 1,
	MovingToEnd = 2,
};

USTRUCT(BlueprintType)
struct FSplitStormProxyCircle
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="SplitStormProxyCircle")
	FVector Center;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SplitStormProxyCircle")
	float Radius;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_SplitStorm : public AFortAthenaMutator_GameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Split Storm")
	TSubclassOf<AActor> SafeZoneProxyClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Split Storm")
	FScalableFloat ProxyUpdateFrequency;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Split Storm")
	FScalableFloat SplitParallelTravelDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Split Storm")
	FScalableFloat JoinParallelTravelDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Split Storm")
	FScalableFloat SplitPerpendicularTravelDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Split Storm")
	FScalableFloat JoinAngleFromParallelDegrees;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Split Storm")
	FScalableFloat PhaseToSplitStorm;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Split Storm")
	FLinearColor ProxyMapCircleColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Split Storm")
	float ProxyMapCircleLineThickness;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Split Storm")
	int32 ProxyMapCircleLineSegments;

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Safe Zone Proxy")
	void SetProxyCenter(const FVector NewCenter);

	UFUNCTION(BlueprintNativeEvent, Category="Safe Zone Proxy")
	void SetProxyRadius(const float NewRadius);

	UFUNCTION(BlueprintCallable, Category="Safe Zone Proxy")
	void SetSafeZoneProxyPhase(ESplitStormProxyPhase NewPhase);

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortAthenaMutator_SplitStorm")
	AActor* SafeZoneProxy;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortAthenaMutator_SplitStorm")
	ESplitStormProxyPhase CurrentProxyPhase;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_SplitStorm")
	float MoveToHoldWaitDuration;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_SplitStorm")
	float MoveToHoldDuration;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_SplitStorm")
	float MoveToEndWaitDuration;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_SplitStorm")
	float MoveToEndDuration;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_SplitStorm")
	float MoveStartTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_SplitStorm")
	FSplitStormProxyCircle ProxyStartCircle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_SplitStorm")
	FSplitStormProxyCircle ProxyEndCircle;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortAthenaMutator_SplitStorm")
	FSplitStormProxyCircle ProxyHoldCircle;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_CurrentProxyCircle, Category="FortAthenaMutator_SplitStorm")
	FSplitStormProxyCircle CurrentProxyCircle;

private:
	UFUNCTION()
	void OnRep_CurrentProxyCircle();

	UFUNCTION()
	void OnSafeZoneIndicatorSpawned(const FFortSafeZoneIndicatorUpdatedEvent& Event);

	UFUNCTION()
	void OnSafeZonePhaseChanged();

	UFUNCTION()
	void StartProxyUpdateTimer();

	UFUNCTION()
	void UpdateProxyCenterAndRadius();

};

