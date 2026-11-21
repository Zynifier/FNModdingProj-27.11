// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpatialEnterExitContext.generated.h"

class AActor;
class APlayerState;

USTRUCT(BlueprintType)
struct FPlayerEnterSpatialActorContext
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="PlayerEnterSpatialActorContext")
	TObjectPtr<AActor> SpatialGameplayInterfaceActor;

	UPROPERTY(BlueprintReadOnly, Category="PlayerEnterSpatialActorContext")
	TObjectPtr<APlayerState> EnteringPlayerState;

};

USTRUCT(BlueprintType)
struct FPlayerEnterSpatialActorContextLegacyMinigame
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="PlayerEnterSpatialActorContextLegacyMinigame")
	TObjectPtr<AActor> SpatialGameplayInterfaceActor;

	UPROPERTY(BlueprintReadOnly, Category="PlayerEnterSpatialActorContextLegacyMinigame")
	TObjectPtr<APlayerState> EnteringPlayerState;

};

USTRUCT(BlueprintType)
struct FPlayerEnterSpatialActorContextWithPawn
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="PlayerEnterSpatialActorContextWithPawn")
	TObjectPtr<AActor> SpatialGameplayInterfaceActor;

	UPROPERTY(BlueprintReadOnly, Category="PlayerEnterSpatialActorContextWithPawn")
	TObjectPtr<APlayerState> EnteringPlayerState;

};

USTRUCT(BlueprintType)
struct FPlayerExitSpatialActorContext
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="PlayerExitSpatialActorContext")
	TObjectPtr<AActor> SpatialGameplayInterfaceActor;

	UPROPERTY(BlueprintReadOnly, Category="PlayerExitSpatialActorContext")
	TObjectPtr<APlayerState> ExitingPlayerState;

};

USTRUCT(BlueprintType)
struct FPlayerExitSpatialActorContextLegacyMinigame
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="PlayerExitSpatialActorContextLegacyMinigame")
	TObjectPtr<AActor> SpatialGameplayInterfaceActor;

	UPROPERTY(BlueprintReadOnly, Category="PlayerExitSpatialActorContextLegacyMinigame")
	TObjectPtr<APlayerState> ExitingPlayerState;

};

USTRUCT(BlueprintType)
struct FPlayerExitSpatialActorContextWithPawn
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="PlayerExitSpatialActorContextWithPawn")
	TObjectPtr<AActor> SpatialGameplayInterfaceActor;

	UPROPERTY(BlueprintReadOnly, Category="PlayerExitSpatialActorContextWithPawn")
	TObjectPtr<APlayerState> ExitingPlayerState;

};

