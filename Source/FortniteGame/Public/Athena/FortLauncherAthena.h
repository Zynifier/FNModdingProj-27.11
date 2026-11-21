// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Building/BuildingTrapFloor.h"
#include "FortLauncherAthena.generated.h"

class AActor;
class AFortPawn;
class AFortPlayerPawnAthena;
class APawn;
class UPrimitiveComponent;
class USoundBase;

USTRUCT()
struct FServerLaunchInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float LaunchServerTime;

	UPROPERTY()
	TWeakObjectPtr<APawn> LaunchedPawn;

};

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingTrapActorClassData)
class AFortLauncherAthena : public ABuildingTrapFloor
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_ReplayLaunchInfo();

	UFUNCTION()
	void OnRep_ServerLaunchInfo();

	UFUNCTION()
	void OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void ReTriggerForPawn(AFortPlayerPawnAthena* AthenaPawn);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void TriggerLaunchEffects(AFortPawn* Pawn);

	UPROPERTY(EditAnywhere, Category="LaunchPad")
	FScalableFloat LaunchStrength;

	UPROPERTY(EditAnywhere, Category="LaunchPad")
	FScalableFloat LaunchStrengthVehicle;

	UPROPERTY(EditAnywhere, Category="LaunchPad")
	TObjectPtr<USoundBase> OnLaunchSound3P;

	UPROPERTY(EditAnywhere, Category="LaunchPad")
	TObjectPtr<USoundBase> OnLaunchSound1P;

	UPROPERTY(EditAnywhere, Category="LaunchPad")
	bool bAllowMultipleTriggers;

	UPROPERTY(EditAnywhere, Category="LaunchPad")
	bool bLaunchPlayersFromVehicles;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplayLaunchInfo)
	FServerLaunchInfo ReplayLaunchInfo;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerLaunchInfo)
	FServerLaunchInfo ServerLaunchInfo;

};

