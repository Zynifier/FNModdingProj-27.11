// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FrontendLobbyData.generated.h"

class AActor;
class UMaterialInstance;
class UNiagaraSystem;
class UTexture;

UENUM(BlueprintType)
enum class EFrontendLobbyLocationOrigin : uint8
{
	Pedestal = 0,
	VaultWorld = 1,
	Player = 2,
};

USTRUCT(BlueprintType)
struct FLobbyPositionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="DynamicBackgroundDirector", meta=(DisplayName="Location"))
	FTransform Location;

	UPROPERTY(EditAnywhere, Category="DynamicBackgroundDirector", meta=(DisplayName="Origin"))
	EFrontendLobbyLocationOrigin LocationOrigin;

};

USTRUCT(BlueprintType)
struct FFrontendLobbyActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="DynamicBackgroundDirector", meta=(DisplayName="Actor"))
	TSubclassOf<AActor> ActorClass;

	UPROPERTY(EditAnywhere, Category="DynamicBackgroundDirector", meta=(DisplayName="Lobby Positioning"))
	FLobbyPositionData LobbyPosition;

};

USTRUCT(BlueprintType)
struct FFrontendLobbyFXData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="DynamicBackgroundDirector", meta=(DisplayName="Location"))
	FTransform Location;

	UPROPERTY(BlueprintReadWrite, Category="DynamicBackgroundDirector", meta=(DisplayName="Niagara FX"))
	TSoftObjectPtr<UNiagaraSystem> NiagaraFX;

};

USTRUCT(BlueprintType)
struct FFrontendLobbyData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicBackgroundDirector", meta=(DisplayName="Background Texture"))
	TSoftObjectPtr<UTexture> Texture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicBackgroundDirector", meta=(DisplayName="Background Material"))
	TSoftObjectPtr<UMaterialInstance> Material;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicBackgroundDirector", meta=(DisplayName="Background Pre Blur Material"))
	TSoftObjectPtr<UMaterialInstance> PreBlurMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicBackgroundDirector", meta=(DisplayName="Spawn FX List"))
	TArray<FFrontendLobbyFXData> SpawnFXList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicBackgroundDirector", meta=(DisplayName="Spawn Actor List"))
	TArray<FFrontendLobbyActor> SpawnActorList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicBackgroundDirector", meta=(DisplayName="Fade Grid"))
	float FadeGrid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicBackgroundDirector", meta=(DisplayName="Fade Floor To Black"))
	float FadeFloorToBlack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicBackgroundDirector", meta=(DisplayName="Has Ranked Widget"))
	bool bHasRankedWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicBackgroundDirector", meta=(DisplayName="Has Level Widget"))
	bool bHasLevelWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DynamicBackgroundDirector", meta=(DisplayName="Has Survivor Tier Widget"))
	bool bHasSurvivorTierWidget;

};

