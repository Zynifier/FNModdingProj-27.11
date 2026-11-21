// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FortAimAssist2D.generated.h"

class AActor;
class AFortPlayerController;
class AFortPlayerPawn;
class UFortPlayerInput;
class UShapeComponent;

USTRUCT()
struct FFortAimAssist2D_InputParams
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortAimAssist2D_OwnerInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortPlayerController> FortPC;

	UPROPERTY()
	TObjectPtr<UFortPlayerInput> FortPI;

	UPROPERTY()
	TObjectPtr<AFortPlayerPawn> FortPawn;

};

USTRUCT()
struct FFortAimAssist2D_Target
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AActor> Actor;

};

USTRUCT()
struct FFortAimAssist2D
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FFortAimAssist2D_InputParams InputParams;

	UPROPERTY()
	FFortAimAssist2D_OwnerInfo OwnerInfo;

	UPROPERTY()
	TArray<FFortAimAssist2D_Target> TargetCache0;

	UPROPERTY()
	TArray<FFortAimAssist2D_Target> TargetCache1;

};

USTRUCT()
struct FFortAimAssist2D_History
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortAimAssist2D_HistorySample
{
	GENERATED_BODY()

};

UCLASS()
class UFortAimAssist2D_TargetManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AimAssist", meta=(DefaultToSelf="TargetActor"))
	static void RegisterAimAssistTarget(AActor* TargetActor, UShapeComponent* TargetShapeComponent);

	UFUNCTION(BlueprintCallable, Category="AimAssist", meta=(DefaultToSelf="TargetActor"))
	static void UnregisterAimAssistTarget(AActor* TargetActor);

protected:
	UFUNCTION()
	void OnTargetEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UPROPERTY(Export)
	TMap<TObjectPtr<AActor>, TWeakObjectPtr<UShapeComponent>> TargetMap;

};

