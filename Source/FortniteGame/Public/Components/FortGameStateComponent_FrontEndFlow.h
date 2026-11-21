// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "FrontEnd/FrontEndTypes.h"
#include "FortGameStateComponent_FrontEndFlow.generated.h"

class UFortFrontendPendingAsyncLevel;
class UFortGameStateComponent_FrontEndFlow;
class ULevelStreaming;
class ULevelStreamingDynamic;

USTRUCT()
struct FDynaimcLevelStreamingLocations
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FTransform LoadLocation;

	UPROPERTY(Transient)
	FName StreamingLevelPackageName;

};

USTRUCT()
struct FDynamicStreamingLevelData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FName LevelPackageName;

	UPROPERTY(Transient)
	EFrontEndCamera CameraOverride;

	UPROPERTY(Transient)
	FName CameraName;

};

USTRUCT()
struct FFortFrontendCompositeLevel
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FName StreamingLevelPackageName;

	UPROPERTY(Transient)
	TArray<TObjectPtr<ULevelStreaming>> StreamingLevels;

};

UCLASS(MinimalAPI)
class UFortFrontendPendingAsyncLevel : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleLevelLoadedAsync();

	UPROPERTY(Transient)
	TObjectPtr<ULevelStreamingDynamic> SubgameStreamingLevel;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGameStateComponent_FrontEndFlow> FrontEndFlow;

	UPROPERTY(Transient)
	FName PackageName;

	UPROPERTY(Transient)
	EFrontEndCamera CameraOverride;

	UPROPERTY(Transient)
	FName CameraName;

};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_FrontEndFlow : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UFortGameStateComponent_FrontEndFlow(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(Transient)
	TArray<FFortFrontendCompositeLevel> CurrentCompositeLevels;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortFrontendPendingAsyncLevel>> AsyncStreamingLevels;

};

